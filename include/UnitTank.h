/**
 * @file UnitTank.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _UNITTANK_H
#define _UNITTANK_H


#include "AbstractGameUnit.h"
#include "TankState.h"

class ECannon;
class EChassis;
class CompWheel;
class LOP;

class UnitTank : public AbstractGameUnit {
public:
    UnitTank(ECannon*, EChassis*, CompWheel*);
    virtual ~UnitTank();

    void forward();
    void stop();
    void backward();
    void shoot();
    void doSomething();

    // Draw entity
    virtual void render();

    void rotateUp();
    void rotateDown();
    void setState(const AbstractTankState & state);

private:
    ECannon * m_cannon;
    EChassis * m_chassis;
    CompWheel * m_wheel;
    AbstractTankState * m_mind;

};
#endif
