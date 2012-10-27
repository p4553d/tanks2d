/**
 * @file Playground.cpp
 * @author user p4553d
 */


#include "Playground.h"
#include "AbstractGameUnit.h"
#include "Config.h"
#include "Log.h"
#include "ITeam.h"


pthread_t Playground::pgTread;
pthread_mutex_t Playground::pg_mutex;

Playground::Playground() {
    LOG_INFO("Playground initialisation");

    b2Vec2 gravity;
    gravity.Set(0.0f, -9.81f);
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

void Playground::registerUnit(AbstractGameUnit * agu) {
    if(agu != NULL) {
        pthread_mutex_lock(&Playground::pg_mutex);
        m_gameUnits.push_back(agu);
        pthread_mutex_unlock(&pg_mutex);
    } else {
        LOG_WARN("NULL-unit seen!");
    }
}

void Playground::step() {
    // clear world from garbage
    //TODO

    // make step
    pthread_mutex_lock(&Playground::pg_mutex);
    m_World->Step(sm_timeStep, sm_velocityIterations, sm_positionIterations);

    //create GOP und LOP
    list<AbstractGameUnit*>::iterator it_agu;
    for(it_agu=m_gameUnits.begin(); it_agu!=m_gameUnits.end(); it_agu++) {
        // Track units with sweep line
        LOP *l = NULL;

        // activate units according they states
        (*it_agu)->doSomething(l);
    }



    pthread_mutex_unlock(&pg_mutex);

    // activate teams with actual GOP

    // increment game time
    m_gametime++;
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

Playground::Playground(const Playground & ) {
}

Playground & Playground::operator =(const Playground & ) {
}

void Playground::registerTeam(ITeam *team) {
    m_teams.push_back(team);
}

const int Playground::get_m_gametime() const {
    return m_gametime;
}
