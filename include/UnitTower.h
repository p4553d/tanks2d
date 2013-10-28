/**
 * @file UnitTower.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _UNITTOWER_H
#define _UNITTOWER_H


#include "Building.h"

class ECannon;
class EFort;

class UnitTower : public Building {
public:
    UnitTower (ECannon *cannon, EFort *fort);
    virtual ~UnitTower();

    void render();

    void teleportTo(float x, float y);
    float getFlatPosition();
protected:
    ECannon * m_cannon;

    EFort * m_fort;

};
#endif
