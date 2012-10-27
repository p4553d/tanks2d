/**
 * @file TankState.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _TANKSTATE_H
#define _TANKSTATE_H

class UnitTank;
class LOP;

class AbstractTankState {
public:
    virtual void doSomething(LOP *lop, UnitTank *ut)=0;

};
class BerzerkState : public AbstractTankState {
public:
    void doSomething(LOP *lop, UnitTank *ut);

};
class GoState : public AbstractTankState {
public:
    void doSomething(LOP *lop, UnitTank *ut);

};
class StayState : public AbstractTankState {
public:
    void doSomething(LOP *lop, UnitTank *ut);

};

class TankStateFactory {
public:
    static AbstractTankState* getBerzerkState();
    static AbstractTankState* getGoState();
    static AbstractTankState* getStayState();
};
#endif
