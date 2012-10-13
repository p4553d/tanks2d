/**
 * @file UnitWell.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _UNITWELL_H
#define _UNITWELL_H


#include "AbstractGameUnit.h"

class EWell;

class UnitWell : public AbstractGameUnit {
private:
    EWell * m_eWell;

    int m_nextMoney;

};
#endif
