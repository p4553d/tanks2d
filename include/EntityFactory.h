/**
 * @file EntityFactory.h
 * @author user p4553d
 * @section DESCRIPTION
 * It is not realy factory - it is a builder for game entites with given properties
 */

#ifndef _ENTITYFACTORY_H
#define _ENTITYFACTORY_H


#include "EWheel.h"
#include "EFort.h"
#include "EChassis.h"
#include "EWell.h"
#include "CompWheel.h"
#include "ECannon.h"

class EntityFactory {
public:
    static EWheel createEWheel();

    static EFort createEFort();

    static EChassis createEChassis();

    static EWell createEWell();

    static CompWheel createCompWheel();

    static ECannon createECannon();

};
#endif
