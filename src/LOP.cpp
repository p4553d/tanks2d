/**
 * @file LOP.cpp
 * @author user p4553d
 */



#include "LOP.h"
#include "Playground.h"

LOP::LOP(float net, float neb, float nft, float nfw, float lh){
}

const float LOP::get_nextEnemyTank() const {
    return nextEnemyTank;
}

const float LOP::get_nextEnemyBuilding() const {
    return nextEnemyBuilding;
}

const float LOP::get_nextFriendlyTank() const {
    return nextFriendlyTank;
}

const float LOP::get_nextFriendlyTower() const {
    return nextFriendlyTower;
}

const float LOP::get_lastHit() const {
    return lastHit;
}
