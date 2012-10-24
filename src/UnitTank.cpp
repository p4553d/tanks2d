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
}

void UnitTank::stop() {
}

void UnitTank::backward() {
}

void UnitTank::shoot() {
}

void UnitTank::doSomething() {
}

void UnitTank::rotateUp() {
}

void UnitTank::rotateDown() {
}

void UnitTank::setState(const AbstractTankState & state) {
}

void UnitTank::render() {
}
