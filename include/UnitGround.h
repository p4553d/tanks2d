/**
 * @file UnitGround.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _UNITGROUND_H
#define _UNITGROUND_H


#include "AbstractGameUnit.h"
#include "AbstractGameEntity.h"

class UnitGround : public AbstractGameUnit, public AbstractGameEntity {
public:
    UnitGround();

    virtual ~UnitGround();

    void render();

};
#endif
