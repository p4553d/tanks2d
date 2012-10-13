/**
 * @file AbstractProjectile.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _ABSTRACTPROJECTILE_H
#define _ABSTRACTPROJECTILE_H


#include "AbstractGameUnit.h"

class AbstractProjectile : public AbstractGameUnit {
protected:
    float m_damagePoints;

    float m_splashRadius;

    float m_splashDamage;

    float m_weight;

};
#endif
