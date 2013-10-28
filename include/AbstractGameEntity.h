/**
 * @file AbstractGameEntity.h
 * @author user p4553d
 * @section DESCRIPTION
 * Renderable physical entity of game world model
 */

#ifndef _ABSTRACTGAMEENTITY_H
#define _ABSTRACTGAMEENTITY_H


#include "IPhysical.h"
#include "IRenderable.h"
#include "Team.h"

enum CollisionBits{
    COL_BOUNDARY = 1<<0,
    COL_BLUEUNIT = 1<<1,
    COL_BLUEPROJECTIL = 1<<2,
    COL_REDUNIT = 1<<3,
    COL_REDPROJECTIL = 1<<4,
    COL_BUILDING = 1<<5
};

class AbstractGameUnit;

class AbstractGameEntity : public IPhysical, public IRenderable {
public:
    virtual ~AbstractGameEntity();
    virtual void render();
    virtual void teleportTo(float32 x, float32 y);
    virtual b2Vec2 getPosition();

    void setColor(b2Color c);
    void setUserData(AbstractGameUnit * agu);
    AbstractGameUnit* getUserData();

protected:
    b2Color m_color;

};
#endif
