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

#define MAX_KEY_LENGTH 10

class Config;

class EntityFactory {
public:
    static EFort* createEFort();
    static EChassis* createEChassis(int n);
    static EWell* createEWell();
    static CompWheel* createCompWheel(int n);
    static ECannon* createECannon(int n);

    static void init();

private:
    static Config *fortConf;
    static Config *chassisConf;
    static Config *wellConf;
    static Config *wheelsConf;
    static Config *cannonConf;

};
#endif
