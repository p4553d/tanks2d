/**
 * @file UnitTank.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _UNITTANK_H
#define _UNITTANK_H


#include "Vehicle.h"
#include "TankState.h"

class ECannon;
class EChassis;
class CompWheel;
class LOP;

class UnitTank : public Vehicle {
public:
    UnitTank(ECannon*, EChassis*, CompWheel*);
    virtual ~UnitTank();

    void forward();
    void stop();
    void backward();
    void shoot();
    void doSomething(LOP*);

    void render();

    void rotateUp();
    void rotateDown();
    void setState(AbstractTankState *state);

    void teleportTo(float x, float y);

    float getFlatPosition();

private:
    ECannon * m_cannon;
    EChassis * m_chassis;
    CompWheel * m_wheel;

    AbstractTankState *m_mind;

};
#endif
