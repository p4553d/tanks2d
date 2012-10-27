/**
 * @file LOP.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _LOP_H
#define _LOP_H

class Playground;

class LOP {
private:
    float nextEnemyTank;
    float nextEnemyBuilding;
    float nextFriendlyTank;
    float nextFriendlyTower;
    float lastHit;


public:

    LOP(float net, float neb, float nft, float nfw, float lh);

    const float get_nextEnemyTank() const;
    const float get_nextEnemyBuilding() const;
    const float get_nextFriendlyTank() const;
    const float get_nextFriendlyTower() const;
    const float get_lastHit() const;

};


#endif
