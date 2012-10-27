/**
 * @file AbstractGameUnit.cpp
 * @author user p4553d
 */



#include "AbstractGameUnit.h"

int AbstractGameUnit::s_uidSeed=1;

AbstractGameUnit::AbstractGameUnit () {
    m_dead = false;
    m_healthPoints = 0;
    m_unitId = s_uidSeed;   //TODO mutex
    s_uidSeed++;

    m_team = TEAM_NON_COMBAT;
}

void AbstractGameUnit::takeDamage(float damage) {
    m_healthPoints = m_healthPoints - damage;
    if(m_healthPoints < 0) {
        m_dead = true;
    }
}

float AbstractGameUnit::getHealtPoints() {
    return m_healthPoints;
}

bool AbstractGameUnit::isDead() {
    return m_dead;
}

float AbstractGameUnit::causeDamage() {
    return m_damage;
}

int AbstractGameUnit::getUnitId(){
    return m_unitId;
}

void AbstractGameUnit::doSomething(LOP *l){
    // I do nothing!
}

void AbstractGameUnit::setTeam(TeamID t){
    m_team = t;
}

TeamID AbstractGameUnit::getTeam(){
    return m_team;
}

void AbstractGameUnit::teleportTo(float x, float y){
    // I do nothing!
}
