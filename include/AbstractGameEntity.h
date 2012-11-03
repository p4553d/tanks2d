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
    COL_BOUNDARY = 0x01,
    COL_BLUEUNIT = 0x02,
    COL_BLUEPROJECTIL = 0x04,
    COL_REDUNIT = 0x08,
    COL_REDPROJECTIL = 0x10
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
