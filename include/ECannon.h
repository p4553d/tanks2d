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
protected:
    float m_radius;


public:
    void rotate(int direction);

    void shoot();


private:
    int m_nextShot;

};
#endif
