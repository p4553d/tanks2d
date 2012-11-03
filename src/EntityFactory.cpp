/**
 * @file EntityFactory.cpp
 * @author user p4553d
 */

#include "EntityFactory.h"
#include "Config.h"

Config *EntityFactory::fortConf;
Config *EntityFactory::chassisConf;
Config *EntityFactory::wellConf;
Config *EntityFactory::wheelsConf;
Config *EntityFactory::cannonConf;

void EntityFactory::init() {    //TODO !
    fortConf = new Config("/home/mutant/projects/tanks2d2/Fort");
    assert(fortConf !=NULL);

    chassisConf = new Config("/home/mutant/projects/tanks2d2/Chassis");
    assert(chassisConf !=NULL);

    wellConf = new Config("/home/mutant/projects/tanks2d2/Well");
    assert(wellConf !=NULL);

    wheelsConf = new Config("/home/mutant/projects/tanks2d2/Wheels");
    assert(wheelsConf !=NULL);

    cannonConf = new Config("/home/mutant/projects/tanks2d2/Cannon");
    assert(cannonConf !=NULL);
}

EFort* EntityFactory::createEFort() {
}

EChassis* EntityFactory::createEChassis(int n, TeamID t) {
    char key[MAX_KEY_LENGTH];

    snprintf(key, MAX_KEY_LENGTH, "%d/width", n);
    float width = chassisConf->getFloat(key);

    snprintf(key, MAX_KEY_LENGTH, "%d/height", n);
    float height = chassisConf->getFloat(key);

    snprintf(key, MAX_KEY_LENGTH, "%d/density", n);
    float density = chassisConf->getFloat(key);

    // TODO: plausibility check

    EChassis *ret = new EChassis (width, height, t, density);

    return ret;
}

EWell* EntityFactory::createEWell() {
}

CompWheel* EntityFactory::createCompWheel(int n, TeamID t) {
    char key[MAX_KEY_LENGTH];

    snprintf(key, MAX_KEY_LENGTH, "%d/radius", n);
    float radius = wheelsConf->getFloat(key);

    snprintf(key, MAX_KEY_LENGTH, "%d/number", n);
    int number = wheelsConf->getFloat(key);

    snprintf(key, MAX_KEY_LENGTH, "%d/speed", n);
    float speed = wheelsConf->getFloat(key);

    // TODO: plausibility check

    CompWheel *ret = new CompWheel(number, radius, speed, t);

    return ret;
}

ECannon* EntityFactory::createECannon(int n, TeamID t) {
    char key[MAX_KEY_LENGTH];

    snprintf(key, MAX_KEY_LENGTH, "%d/radius", n);
    float radius = cannonConf->getFloat(key);

    snprintf(key, MAX_KEY_LENGTH, "%d/damage", n);
    float damage = cannonConf->getFloat(key);

    snprintf(key, MAX_KEY_LENGTH, "%d/speed", n);
    float speed = cannonConf->getFloat(key);

    // TODO: plausibility check

    ECannon *ret = new ECannon(radius, speed, damage, t);

    return ret;
}

void EntityFactory::setCollisionBits(b2FixtureDef &fixtureDef, TeamID t) {
    if(t == TEAM_BLUE) {
        fixtureDef.filter.categoryBits = COL_BLUEUNIT;
        fixtureDef.filter.maskBits = COL_BOUNDARY | COL_REDPROJECTIL;
    }

    if(t == TEAM_RED) {
        fixtureDef.filter.categoryBits = COL_REDUNIT;
        fixtureDef.filter.maskBits = COL_BOUNDARY | COL_BLUEPROJECTIL;
    }
}
