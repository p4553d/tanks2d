/**
 * @file UnitFactory.cpp
 * @author user p4553d
 */

#include "UnitFactory.h"
#include "EntityFactory.h"
#include "View.h"

UnitTank* UnitFactory::createTank(TeamID t) {
    // create parts of tank

    // hold your color

    b2Color r;
    b2Color y;

    switch(t) {
    case TEAM_BLUE:
        r = b2Color (0.5, 0.5, 1);
        y = b2Color (0.4, 0.4, 1);
        break;

    case TEAM_RED:
        r = b2Color (1, 0.5, 0.5);
        y = b2Color (1, 0.4, 0.4);
        break;
    default:
        r = b2Color (0.7, 0.7, 0.7);
        y = b2Color (0.6, 0.6, 0.6);
        }

    EChassis *c = EntityFactory::createEChassis(1);
    CompWheel *w = EntityFactory::createCompWheel(2);
    ECannon *ec = EntityFactory::createECannon(1);

    c->setColor(r);
    ec->setColor(y);

//    View &v = View::getInstance();
//    v.registerRenderable(c);
//    v.registerRenderable(w);
//    v.registerRenderable(ec);

    UnitTank *retTank = new UnitTank(ec, c, w);

    // bind parts on unit
    ec->setUserData(retTank);
    c->setUserData(retTank);
    w->setUserData(retTank);

    // set initial properties to the tank TODO
    retTank->takeDamage(-10.0);

    retTank->setTeam(t);

    return retTank;
}

UnitTower* UnitFactory::createTower(TeamID t) {
}

UnitBox* UnitFactory::createBox(TeamID t) {
}

UnitWell* UnitFactory::createWell(TeamID t) {
}

UnitGround* UnitFactory::createGround(TeamID t) {
}

