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
    int nextEnemyTank;

    int nextEnemyBuilding;

    int nextFriendlyTank;

    int nextFriendlyTower;


public:
    inline const int get_nextEnemyTank() const;

    inline const int get_nextEnemyBuilding() const;

    inline const int get_nextFriendlyTank() const;

    inline const int get_nextFriendlyTower() const;

};
inline const int LOP::get_nextEnemyTank() const {
    return nextEnemyTank;
}

inline const int LOP::get_nextEnemyBuilding() const {
    return nextEnemyBuilding;
}

inline const int LOP::get_nextFriendlyTank() const {
    return nextFriendlyTank;
}

inline const int LOP::get_nextFriendlyTower() const {
    return nextFriendlyTower;
}

#endif
