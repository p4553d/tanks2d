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

Playground::Playground() {
    LOG_INFO("Playground initialisation");

    b2Vec2 gravity;
    gravity.Set(0.0f, -9.81f);
    m_World = new b2World(gravity);

    assert(m_World != NULL);

    //TODO
    // contact listener
}

Playground::~Playground(){
    delete m_World;
    m_World = NULL;
}

void Playground::registerUnit(AbstractGameUnit * agu) {
    // Obsolete?
    if(agu != NULL){
        m_gameUnits.push_back(agu);
    }
    else{
        LOG_WARN("NULL-unit seen!");
    }
}

void Playground::step() {
    // clear world from garbage
    //TODO

    // make step
    m_World->Step(sm_timeStep, sm_velocityIterations, sm_positionIterations);

    // increment game time
    m_gametime++;
}

b2Body * Playground::createBody(const b2BodyDef * def) {
    return (m_World->CreateBody(def));
}

b2Joint * Playground::createJoint(const b2JointDef * def) {
    return (m_World->CreateJoint(def));
}

void Playground::destructBody(b2Body * b) {
    m_World->DestroyBody(b);
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
