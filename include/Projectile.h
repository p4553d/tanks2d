/**
 * @file AbstractProjectile.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _PROJECTILE_H
#define _PROJECTILE_H


#include "AbstractGameUnit.h"

class Projectile : public AbstractGameUnit {
protected:
    float m_damagePoints;

    float m_splashRadius;

    float m_splashDamage;

    float m_weight;

};
#endif
