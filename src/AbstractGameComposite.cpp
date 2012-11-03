/**
 * @file AbstractGameComposite.cpp
 * @author user p4553d
 */

#include "AbstractGameComposite.h"
#include "AbstractGameUnit.h"

AbstractGameComposite::AbstractGameComposite() {
}

AbstractGameComposite::~AbstractGameComposite() {
    m_entities.clear();
}

void AbstractGameComposite::render() {
    list<AbstractGameEntity*>::iterator it_entity;
    for(it_entity=m_entities.begin(); it_entity != m_entities.end(); it_entity++) {
        (*it_entity)->render();
    }
}

void AbstractGameComposite::teleportTo(float32 x, float32 y) {
    list<AbstractGameEntity*>::iterator it_entity;
    for(it_entity=m_entities.begin(); it_entity != m_entities.end(); it_entity++) {
        (*it_entity)->teleportTo(x,y);
    }
}

void AbstractGameComposite::setColor(b2Color c) {
    list<AbstractGameEntity*>::iterator it_entity;
    for(it_entity=m_entities.begin(); it_entity != m_entities.end(); it_entity++) {
        (*it_entity)->setColor(c);
    }
}

void AbstractGameComposite::setUserData(AbstractGameUnit * agu) {
    list<AbstractGameEntity*>::iterator it_entity;
    for(it_entity=m_entities.begin(); it_entity != m_entities.end(); it_entity++) {
        (*it_entity)->setUserData(agu);
    }
}

void AbstractGameComposite::addEntity(AbstractGameEntity* age) {
    m_entities.push_back(age);
}
