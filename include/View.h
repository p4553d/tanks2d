/**
 * @file View.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _VIEW_H
#define _VIEW_H

#include "AbstractView.h"
#include "IRenderable.h"

#include <pthread.h>

class View : public AbstractView {
public:

    static View& getInstance();
    virtual ~View();

    const float get_zoom() const;
    void set_zoom(float value);
    const float get_xView() const;
    void set_xView(float value);
    const float get_yView() const;
    void set_yView(float value);

    const float get_width() const;
    void set_width(float value);
    const float get_height() const;
    void set_height(float value);

    void registerRenderable(IRenderable * r);
    void removeRenderable(IRenderable * r);

    pthread_mutex_t view_mutex;
    static pthread_t viewTread;

    static void renderView();
    static void resize(int, int);

    void render();

private:
    View();
    View(const View&);
    View & operator= (const View&);

    float m_zoom;
    float m_xView;
    float m_yView;

    float m_width;
    float m_height;
};

#endif
