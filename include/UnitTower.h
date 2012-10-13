/**
 * @file UnitTower.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _UNITTOWER_H
#define _UNITTOWER_H


#include "AbstractGameUnit.h"

class ECannon;
class EFort;

class UnitTower : public AbstractGameUnit {
protected:
    ECannon * m_cannon;

    EFort * m_fort;

};
#endif
