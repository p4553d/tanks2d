/**
 * @file Playground.cpp
 * @author user p4553d
 */

#include "Config.h"
#include "Log.h"

#include "Playground.h"
#include "AbstractGameUnit.h"
#include "Building.h"
#include "Vehicle.h"
#include "ITeam.h"

#include "LOP.h"
#include "GOP.h"

pthread_t Playground::pgTread;
pthread_mutex_t Playground::pg_mutex;

// private function to compare game units
bool compareUnits(AbstractGameUnit *agu1, AbstractGameUnit *agu2) {
    return agu1->getFlatPosition() < agu2->getFlatPosition();
}

Playground::Playground() {
    LOG_INFO("Playground initialisation");

    b2Vec2 gravity;
    gravity.Set(0.0f, -9.81f);  //set my favorite gravity
    m_World = new b2World(gravity);

    assert(m_World != NULL);

    pthread_mutex_init (&pg_mutex, NULL);

    //TODO
    // contact listener
}

Playground::~Playground() {
    delete m_World;
    m_World = NULL;
}

void Playground::registerUnit(Vehicle * agu) {
    if(agu != NULL) {
        pthread_mutex_lock(&Playground::pg_mutex);
        m_gameVehicles.push_back(agu);
        pthread_mutex_unlock(&pg_mutex);
    } else {
        LOG_WARN("NULL-vehicle seen!");
    }
}

void Playground::registerUnit(Building * agu) {
    if(agu != NULL) {
        pthread_mutex_lock(&Playground::pg_mutex);
        m_gameBuildings.push_back(agu);
        m_gameBuildings.sort(compareUnits);
        pthread_mutex_unlock(&pg_mutex);
    } else {
        LOG_WARN("NULL-building seen!");
    }
}

void Playground::step() {
    // clear world from garbage
    //TODO

    // make simulation step
    pthread_mutex_lock(&Playground::pg_mutex);
    m_World->Step(sm_timeStep, sm_velocityIterations, sm_positionIterations);

    generateOPs();

    pthread_mutex_unlock(&pg_mutex);

    // activate teams with actual GOP

    // increment game time
    m_gametime++;
}

void Playground::generateOPs(){
    // track units and generate LOPs and GOP with sweep line
    // TODO: separate thread for game logic?
    //sort game units to prepare for sweep line
    m_gameVehicles.sort(compareUnits);

    // create GOP und LOP
    list<Vehicle*>::iterator it_vehicle = m_gameVehicles.begin();

    list<Vehicle*>::iterator it_Bvehicle = m_gameVehicles.begin();
    list<Vehicle*>::iterator it_Rvehicle = m_gameVehicles.begin();
    list<Building*>::iterator it_Bbuilding = m_gameBuildings.begin();
    list<Building*>::iterator it_Rbuilding = m_gameBuildings.begin();

    float lastBlueVeh = MIN_BOUND;
    float currentBlueVeh = MIN_BOUND;
    float lastBlueBuilding = MIN_BOUND;
    float currentBlueBuilding = MIN_BOUND;

    float lastRedVeh = MIN_BOUND;
    float currentRedVeh = MIN_BOUND;
    float lastRedBuilding = MIN_BOUND;
    float currentRedBuilding = MIN_BOUND;

    float nrv, nrb, nbv, nbb, lh;
    for(it_vehicle; it_vehicle!=m_gameVehicles.end(); it_vehicle++) {

        float currentVeh = (*it_vehicle)->getFlatPosition();

        // search apropriate buildings
        // TODO: move me to an function!?
        // FIXME: grey buildings are not tracked!
        bool done = false;
        while(it_Bbuilding != m_gameBuildings.end() && !done) {
            if((*it_Bbuilding)->getTeam() == TEAM_BLUE) {
                if((*it_Bbuilding)->getFlatPosition() > currentVeh) {
                    currentBlueBuilding = (*it_Bbuilding)->getFlatPosition();
                    done = true;
                } else {
                    lastBlueBuilding = (*it_Bbuilding)->getFlatPosition();
                    it_Bbuilding++;
                }
            } else {
                it_Bbuilding++;
            }
        }

        if(
           (currentBlueBuilding-currentVeh) > (currentVeh-lastBlueBuilding) ||
           currentBlueBuilding == MIN_BOUND
        ) {
            nbb = lastBlueBuilding;
        } else {
            nbb = currentBlueBuilding;
        }


        done = false;
        while(it_Rbuilding != m_gameBuildings.end() && !done) {
            if((*it_Rbuilding)->getTeam() == TEAM_RED) {
                if((*it_Rbuilding)->getFlatPosition() > currentVeh) {
                    currentRedBuilding = (*it_Rbuilding)->getFlatPosition();
                    done = true;
                } else {
                    lastBlueBuilding = (*it_Rbuilding)->getFlatPosition();
                    it_Rbuilding++;
                }
            } else {
                it_Rbuilding++;
            }
        }

        if(
            (currentRedBuilding-currentVeh) > (currentVeh-lastRedBuilding) ||
            currentRedBuilding == MIN_BOUND
        ) {
            nrb = lastRedBuilding;
        } else {
            nrb = currentRedBuilding;
        }

        // search for apropriate vehicles
        // FIXME: do not detect itself as neares firendly vehicle
        done = false;
        while(it_Bvehicle != m_gameVehicles.end() && !done) {
            if((*it_Bvehicle)->getTeam() == TEAM_BLUE) {
                if((*it_Bvehicle)->getFlatPosition() > currentVeh) {
                    currentBlueVeh = (*it_Bvehicle)->getFlatPosition();
                    done = true;
                } else {
                    lastBlueVeh = (*it_Bvehicle)->getFlatPosition(); // FIXME
                    it_Bvehicle++;
                }
            } else {
                it_Bvehicle++;
            }
        }

        if(
           (currentBlueVeh-currentVeh) > (currentVeh-lastBlueVeh) ||
            currentBlueVeh == MIN_BOUND
        ) {
            nbv = lastBlueVeh;
        } else {
            nbv = currentBlueVeh;
        }

        done = false;
        while(it_Rvehicle != m_gameVehicles.end() && !done) {
            if((*it_Rvehicle)->getTeam() == TEAM_RED) {
                if((*it_Rvehicle)->getFlatPosition() > currentVeh) {
                    currentRedVeh = (*it_Rvehicle)->getFlatPosition();
                    done = true;
                } else {
                    lastRedVeh = (*it_Rvehicle)->getFlatPosition();
                    it_Rvehicle++;
                }
            } else {
                it_Rvehicle++;
            }
        }

        if(
           (currentRedVeh-currentVeh) > (currentVeh-lastRedVeh) ||
            currentRedVeh == MIN_BOUND
        ){
            nrv = lastRedVeh;
        } else {
            nrv = currentRedVeh;
        }

        // get last hit, if any
        lh = MIN_BOUND; // TODO Hit detection

        // build params in dependency of team membership
        LOP *l = NULL;
        if((*it_vehicle)->getTeam() == TEAM_BLUE) {
            l = new LOP (nrv, nrb, nbv, nbb, lh);
        }

        if((*it_vehicle)->getTeam() == TEAM_RED) {
            l = new LOP (nbv, nbb, nrv, nrb, lh);
        }

        // activate units according they states
        (*it_vehicle)->doSomething(l);

        if(l) {
            delete l;
        }
    }
}

b2Body * Playground::createBody(const b2BodyDef * def) {
    pthread_mutex_lock(&Playground::pg_mutex);
    b2Body *ret = (m_World->CreateBody(def));
    pthread_mutex_unlock(&pg_mutex);
    return ret;
}

b2Joint * Playground::createJoint(const b2JointDef * def) {
    pthread_mutex_lock(&Playground::pg_mutex);
    b2Joint *ret = (m_World->CreateJoint(def));
    pthread_mutex_unlock(&pg_mutex);
    return ret;
}

void Playground::destructBody(b2Body * b) {
    if(b) {
        pthread_mutex_lock(&Playground::pg_mutex);
        m_World->DestroyBody(b);
        pthread_mutex_unlock(&pg_mutex);
    }
}

void Playground::registerTeam(ITeam *team) {
    m_teams.push_back(team);
}

const int Playground::get_m_gametime() const {
    return m_gametime;
}
