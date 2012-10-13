/**
 * @file IRenderable.h
 * @author user p4553d
 * @section DESCRIPTION
 * Basic interface for all renderable pieces of world
 */

#ifndef _IRENDERABLE_H
#define _IRENDERABLE_H

#include "RenderTool.h"

class IRenderable {
public:
    // Draw entity
    virtual void render() = 0;

};
#endif
