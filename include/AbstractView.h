/**
 * @file AbstractView.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _ABSTRACTVIEW_H
#define _ABSTRACTVIEW_H

#include "IRenderable.h"

#include <list>
using namespace std;


class AbstractView : public IRenderable {
public:
    virtual void registerRenderable(IRenderable * r);
    virtual void removeRenderable(IRenderable * r);
    virtual void render();

protected:
    list<IRenderable *> m_renderable;

};
#endif
