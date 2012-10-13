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

class AbstractGameUnit;

class AbstractGameEntity : public IPhysical, public IRenderable {
public:
    virtual ~AbstractGameEntity();
    virtual void render();
    void setColor(b2Color c);
    void teleportTo(float32 x, float32 y);
    void setUserData(AbstractGameUnit * agu);
    AbstractGameUnit* getUserData();

protected:
    b2Color m_color;

};
#endif
