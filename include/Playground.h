/**
 * @file Playground.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _PLAYGROUND_H
#define _PLAYGROUND_H

#include "Box2D/Box2D.h"
#include <list>
using namespace std;

class AbstractGameUnit;
class Config;
class Log;
class Team;
class ITeam;

class Playground {
public:
    static inline Playground & getInstance() {     // singleton
        static Playground _instance;
        return _instance;
    };

    ~Playground();

    void registerEntity(AbstractGameUnit * agu);

    void step();

    // simulation step
    b2Body * createBody(const b2BodyDef * def);

    // create physical body
    b2Joint * createJoint(const b2JointDef * def);

    // create joint
    void destructBody(b2Body * b);


protected:
    // destruct body
    Playground();

    b2World * m_World;

    std::list<AbstractGameUnit*> m_gameUnits;


private:
    Playground(const Playground & );

    Playground & operator =(const Playground & );

    static const float32 sm_timeStep=  1.0f / 60.0f;

    static const int32 sm_velocityIterations=  3;

    static const int32 sm_positionIterations=  2;

    int m_gametime;


public:
    inline const int get_m_gametime() const;

    void registerTeam(const Team & team);


private:
    list<ITeam *> m_teams;

};
inline const int Playground::get_m_gametime() const {
    return m_gametime;
}

#endif
