/**
 * @file AbstractGameComposite.h
 * @author user p4553d
 * @section DESCRIPTION
 * Composition of one or more game entities
 */

#ifndef _ABSTRACTGAMECOMPOSITE_H
#define _ABSTRACTGAMECOMPOSITE_H

#include "AbstractGameEntity.h"
#include "Team.h"

#include <list>
using namespace std;

class AbstractGameUnit;

class AbstractGameComposite : public AbstractGameEntity {

public:
    AbstractGameComposite();
    virtual ~AbstractGameComposite();

public:
    virtual void render();
    void teleportTo(float32 x, float32 y);
    void setColor(b2Color c);
    void setUserData(AbstractGameUnit * agu);

    void addEntity(AbstractGameEntity* age);

private:
    list<AbstractGameEntity*> m_entities;

};
#endif
