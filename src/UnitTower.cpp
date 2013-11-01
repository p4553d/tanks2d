/**
 * @file UnitTower.cpp
 * @author user p4553d
 */


#include "UnitTower.h"
#include "ECannon.h"
#include "EFort.h"

UnitTower::UnitTower (ECannon *cannon, EFort *fort) {
    m_cannon = cannon;
    m_fort = fort;

    //Compose tower from parts

    cannon->attach(fort);
}

UnitTower::~UnitTower() {
    if(m_cannon) {
        delete m_cannon;
    }

    if(m_fort) {
        delete m_fort;
    }
}

void UnitTower::render(){
    if(m_cannon) {
        m_cannon->render();
    }

    if(m_fort) {
        m_fort->render();
    }
}

void UnitTower::teleportTo(float x, float y){
    if(m_cannon) {
        m_cannon->teleportTo(x,y);
    }

    if(m_fort) {
        m_fort->teleportTo(x,y);
    }
}

float UnitTower::getFlatPosition(){
    b2Vec2 v = m_fort->getPosition();

    return v.x;
}
