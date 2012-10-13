/**
 * @file EWheel.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _EWHEEL_H
#define _EWHEEL_H


#include "AbstractGameEntity.h"

class EWheel : public AbstractGameEntity {
public:
    void go();

    void stop();

    void backward();

    EWheel(float radius, float speed);

    virtual ~EWheel();


protected:
    float m_radius;

    float m_speed;

    b2WheelJoint* m_motor;

};
#endif
