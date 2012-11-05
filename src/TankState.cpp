/**
 * @file TankState.cpp
 * @author user p4553d
 */


#include "TankState.h"
#include "UnitTank.h"

#include "LOP.h"

void BerzerkState::doSomething(LOP *lop, UnitTank *ut) {
    // movement
    ut->forward();
    // shooting
}

void GoState::doSomething(LOP *lop, UnitTank *ut) {
    // movement
    // when healt > 70% go, else search next tower
    if(lop) {
        float myPos = ut->getFlatPosition();
        float enemyPos = lop->get_nextEnemyTank();

        printf("%f -> %f \n", myPos, enemyPos);

        if(myPos > enemyPos+15) {
            ut->forward();
        } else {
            if(myPos < enemyPos-15) {
                ut->backward();
            } else {
                ut->stop();
            }
        }
    }

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
