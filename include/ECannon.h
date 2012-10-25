/**
 * @file ECannon.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _ECANNON_H
#define _ECANNON_H


#include "AbstractGameEntity.h"

class EChassis;

class ECannon : public AbstractGameEntity {



public:
    ECannon(float radius, float speed, float damage);

    void attach (EChassis *c);

    void rotate(int direction);
    void shoot();

protected:
    float m_radius;
    float m_speed;
    float m_damage;

    int m_nextShot;

};
#endif
