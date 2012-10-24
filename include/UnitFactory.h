/**
 * @file UnitFactory.h
 * @author user p4553d
 * @section DESCRIPTION
 * It is not realy factory - it is a builder for complex game units with given properties
 */

#ifndef _UNITFACTORY_H
#define _UNITFACTORY_H


#include "UnitTank.h"
#include "UnitTower.h"
#include "UnitBox.h"
#include "UnitWell.h"
#include "UnitGround.h"

class EntityFactory;

class UnitFactory {
public:
    static UnitTank* createTank();

    static UnitTower* createTower();

    static UnitBox* createBox();

    static UnitWell* createWell();

    static UnitGround* createGround();

};
#endif
