/**
 * @file AbstractGameUnit.h
 * @author user p4553d
 * @section DESCRIPTION
 * Game unit of the world, renderable, with HP and team membership
 */

#ifndef _ABSTRACTGAMEUNIT_H
#define _ABSTRACTGAMEUNIT_H


#include "IRenderable.h"
#include "Team.h"

class LOP;

class AbstractGameUnit : public IRenderable {
public:
    AbstractGameUnit();

    float getHealtPoints();
    bool isDead();
    int getUnitId();
    void setTeam(TeamID t);
    TeamID getTeam();

    virtual void takeDamage(float );
    virtual float causeDamage();
    virtual void doSomething(LOP*);
    virtual void teleportTo(float x, float y);

protected:
    float m_healthPoints;
    float m_damage;
    TeamID m_team;
    int m_unitId;
    bool m_dead;

    static int s_uidSeed;
};
#endif
