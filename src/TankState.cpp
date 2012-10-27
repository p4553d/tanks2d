/**
 * @file TankState.cpp
 * @author user p4553d
 */


#include "TankState.h"
#include "UnitTank.h"

void BerzerkState::doSomething(LOP *lop, UnitTank *ut) {
    // movement
    ut->forward();
    // shooting
}

void GoState::doSomething(LOP *lop, UnitTank *ut) {
    // movement
    // when healt > 70% go, else search next tower
    ut->forward();

    // shooting
}

void StayState::doSomething(LOP *lop, UnitTank *ut) {
    //movement
    ut->stop();

    // shhoting
}

AbstractTankState* TankStateFactory::getBerzerkState() {
    static BerzerkState _instance;
    return &_instance;
}

AbstractTankState* TankStateFactory::getGoState() {
    static GoState _instance;
    return &_instance;
}

AbstractTankState* TankStateFactory::getStayState() {
    static StayState _instance;
    return &_instance;
}
