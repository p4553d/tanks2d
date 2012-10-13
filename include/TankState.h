/**
 * @file TankState.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _TANKSTATE_H
#define _TANKSTATE_H


class AbstractTankState {
public:
    void doSomething();

};
class BerzerkState : public AbstractTankState {
public:
    void doSomething();

};
class GoState : public AbstractTankState {
public:
    void doSomething();

};
class StayState : public AbstractTankState {
public:
    void doSomething();

};
class TankStateFactory {
};
#endif
