/**
 * @file IPhysical.h
 * @author user p4553d
 * @section DESCRIPTION
 * Some basic abstraction of physic bodies in game world
 */

#ifndef _IPHYSICAL_H
#define _IPHYSICAL_H

#include "Box2D/Box2D.h"

class IPhysical {
public:

protected:
    b2Body * m_body;

};
#endif
