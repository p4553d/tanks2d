/**
 * @file UnitGround.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _UNITGROUND_H
#define _UNITGROUND_H


#include "AbstractGameUnit.h"

class EGround;

class UnitGround : public AbstractGameUnit{
public:
    UnitGround();
    void render();
protected:
    EGround *m_eGround;
};
#endif
