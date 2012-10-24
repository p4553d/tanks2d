/**
 * @file AbstractGameUnit.cpp
 * @author user p4553d
 */



#include "AbstractGameUnit.h"

AbstractGameUnit::AbstractGameUnit () {
    m_dead = false;
    m_healthPoints = 0;
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

