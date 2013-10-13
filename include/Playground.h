/**
 * @file Playground.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _PLAYGROUND_H
#define _PLAYGROUND_H

#include "Box2D/Box2D.h"

#include <pthread.h>
#include <list>
#include <map>

using namespace std;

class Vehicle;
class Building;
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

    static pthread_t pgTread;
    static pthread_mutex_t pg_mutex;

    void registerUnit(Vehicle *agu);
    void registerUnit(Building *agu);
    void registerTeam( ITeam *team);

    const int get_m_gametime() const;

    void step();

    b2Body * createBody(const b2BodyDef * def);
    b2Joint * createJoint(const b2JointDef * def);
    void destructBody(b2Body * b);

    static const float32 sm_timeStep = 1.0f / 60.0f;
    static const int32 sm_velocityIterations = 3;
    static const int32 sm_positionIterations = 2;

    const static float MIN_BOUND = -99999;
    const static float MAX_BOUND =  99999;

protected:
    Playground();

    b2World *m_World;

    Playground(const Playground & );
    Playground & operator =(const Playground & );

    int m_gametime;

    list<ITeam *> m_teams;
    list<Vehicle*> m_gameVehicles;
    list<Building*> m_gameBuildings;

    void generateOPs();


};

#endif
