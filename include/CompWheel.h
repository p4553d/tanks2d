/**
 * @file CompWheel.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _COMPWHEEL_H
#define _COMPWHEEL_H

#include "AbstractGameComposite.h"

class EChassis;
class EWheel;

class CompWheel : public AbstractGameComposite {
public:
    CompWheel(int count, float radius, float speed, TeamID t);
    virtual ~CompWheel();

    void render();

    void attach(EChassis * c);

    void stop();
    void forward();
    void backward();

    void teleportTo (float32 x, float32 y);


protected:
    int m_count;
    float m_cHeight;
    float m_cWidth;
    EWheel ** m_wheels;

    const static float s_dumping = 2.7f;
    const static float s_freq = 8.0f;
    const static float s_torque = 4500.0f;

};
#endif
