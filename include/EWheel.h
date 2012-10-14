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
    EWheel(float radius, float speed);
    void setMotor (b2WheelJoint*);

    void go();
    void stop();
    void backward();

    b2Body* getBody();
    float getRadius();
    float getSpeed();

protected:
    float m_radius;
    float m_speed;
    b2WheelJoint* m_motor;
};
#endif
