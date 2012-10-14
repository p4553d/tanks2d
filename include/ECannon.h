/**
 * @file ECannon.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _ECANNON_H
#define _ECANNON_H


#include "AbstractGameEntity.h"

class ECannon : public AbstractGameEntity {



public:
    ECannon(float radius);

    void rotate(int direction);

    void shoot();

protected:
    float m_radius;
    int m_nextShot;

};
#endif
