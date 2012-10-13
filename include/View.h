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
