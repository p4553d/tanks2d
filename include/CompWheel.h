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
    CompWheel(int count);

    virtual ~CompWheel();

    void attach(EChassis * c);


protected:
    int m_count;

    EWheel * m_wheels;


public:
    void stop();

    void go();

    void backward();

};
#endif
