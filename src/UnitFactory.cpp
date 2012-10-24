/**
 * @file UnitFactory.cpp
 * @author user p4553d
 */

#include "UnitFactory.h"
#include "EntityFactory.h"
#include "View.h"

UnitTank* UnitFactory::createTank() {
    // create parts of tank
    b2Color r (1, 0.5, 0.5);
    b2Color y (1, 1, 0.2);

    EChassis *c = new EChassis (20, 10, 3);
    CompWheel *w = new CompWheel (4, 2.0f, 60.0f);
    ECannon *ec = new ECannon(6.0f);

    c->setColor(r);
    ec->setColor(y);

    View &v = View::getInstance();
    v.registerRenderable(c);
    v.registerRenderable(w);
    v.registerRenderable(ec);

    UnitTank *retTank = new UnitTank(ec, c, w);

    // bind parts on unit
    ec->setUserData(retTank);
    c->setUserData(retTank);
    w->setUserData(retTank);

    // set initial properties to the tank
    retTank->takeDamage(-10.0);

    return retTank;
}

UnitTower* UnitFactory::createTower() {
}

UnitBox* UnitFactory::createBox() {
}

UnitWell* UnitFactory::createWell() {
}

UnitGround* UnitFactory::createGround() {
}

