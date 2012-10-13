/**
 * @file AbstractView.cpp
 * @author user p4553d
 */



#include "AbstractView.h"
#include "IRenderable.h"

void AbstractView::registerRenderable(IRenderable* r) {
    m_renderable.push_back(r);
}

void AbstractView::removeRenderable(IRenderable* r) {
    m_renderable.remove(r);
}

void AbstractView::render() {
    list<IRenderable*>::iterator it_r;
    for(it_r=m_renderable.begin(); it_r!=m_renderable.end(); it_r++) {
        (*it_r)->render();
    }
}
