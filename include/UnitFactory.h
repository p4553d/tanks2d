/**
 * @file UnitFactory.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _UNITFACTORY_H
#define _UNITFACTORY_H


#include "UnitTank.h"
#include "UnitTower.h"
#include "Box.h"
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
