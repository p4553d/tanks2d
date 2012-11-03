/**
 * @file UnitTank.cpp
 * @author user p4553d
 */


#include "UnitTank.h"
#include "ECannon.h"
#include "EChassis.h"
#include "CompWheel.h"
#include "LOP.h"

UnitTank::UnitTank(ECannon* cannon, EChassis* chassis, CompWheel* wheels) {
    m_cannon = cannon;
    m_chassis = chassis;
    m_wheel = wheels;

    // construct the tank
    assert(m_chassis != NULL);

    if(m_cannon != NULL) {
        m_cannon->attach(m_chassis);
    }

    if(m_wheel != NULL) {
        m_wheel->attach(m_chassis);
    }

    m_mind = TankStateFactory::getStayState();
}

UnitTank::~UnitTank() {
    if(m_cannon) {
        delete m_cannon;
    }

    if(m_chassis) {
        delete m_chassis;
    }

    if(m_wheel) {
        delete m_wheel;
    }
}

void UnitTank::forward() {
    if (m_wheel) {
        m_wheel->forward();
    }
}

void UnitTank::stop() {
    if (m_wheel) {
        m_wheel->stop();
    }
}

void UnitTank::backward() {
    if (m_wheel) {
        m_wheel->backward();
    }
}

void UnitTank::shoot() {
    if (m_cannon) {
        m_cannon->shoot();
    }
}

void UnitTank::doSomething(LOP *l) {
    if(m_mind) {
        m_mind->doSomething(l, this);
    }
}

void UnitTank::rotateUp() {
    if(m_cannon) {
        m_cannon->rotate(1);
    }
}

void UnitTank::rotateDown() {
    if (m_cannon) {
        m_cannon->rotate(-1);
    }
}

void UnitTank::setState(AbstractTankState *state) {
    m_mind = state;
}

void UnitTank::render() {
    // draw parts of tank itself
    if(m_cannon) {
        m_cannon->render();
    }

    if(m_chassis) {
        m_chassis->render();
    }

    if(m_wheel) {
        m_wheel->render();
    }

    //render additional information
}

void UnitTank::teleportTo(float x, float y){
    if(m_cannon) {
        m_cannon->teleportTo(x, y);
    }

    if(m_chassis) {
        m_chassis->teleportTo(x, y);
    }

    if(m_wheel) {
        m_wheel->teleportTo(x, y);
    }
}

float UnitTank::getFlatPosition(){
    b2Vec2 v = m_chassis->getPosition();

    return v.x;
}
