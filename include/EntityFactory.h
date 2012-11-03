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

#include "Team.h"

class Config;

class EntityFactory {
public:
    static EFort* createEFort();
    static EChassis* createEChassis(int n, TeamID t);
    static EWell* createEWell();
    static CompWheel* createCompWheel(int n, TeamID t);
    static ECannon* createECannon(int n, TeamID t);

    static void init();

    static void setCollisionBits(b2FixtureDef &fd, TeamID t);

    static const int MAX_KEY_LENGTH=10;

private:
    static Config *fortConf;
    static Config *chassisConf;
    static Config *wellConf;
    static Config *wheelsConf;
    static Config *cannonConf;

};
#endif
