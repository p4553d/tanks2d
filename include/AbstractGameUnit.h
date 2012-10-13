/**
 * @file AbstractGameUnit.h
 * @author user p4553d
 * @section DESCRIPTION
 * Game unit of the world, renderable, with HP and team membership
 */

#ifndef _ABSTRACTGAMEUNIT_H
#define _ABSTRACTGAMEUNIT_H


#include "IRenderable.h"

enum TeamID {
    RED,
    BLUE,
    GREY,
    NON_COMBAT

};

class AbstractGameUnit : public IRenderable {
public:
    AbstractGameUnit();

    void takeDamage(float );
    float getHealtPoints();
    bool isDead();
    float causeDamage();

protected:
    float m_healthPoints;
    float m_damage;
    TeamID m_team;
    bool m_dead;
};
#endif
