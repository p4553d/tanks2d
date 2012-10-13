/**
 * @file View.cpp
 * @author user p4553d
 */



#include "View.h"

View::View() {
    m_zoom = 10.0f;
    m_xView = 0;
    m_yView = 0;
    m_width = 640;
    m_height = 480;

    const char* title="tanks2d2";

    //GLUT init
}

View::~View(){
    // intentional empty
}

View& View::getInstance() {
    static View _instance;
    return _instance;
}

void View::set_zoom(float value) {
    m_zoom = value;
}

void View::set_xView(float value) {
    m_xView = value;
}

void View::set_yView(float value) {
    m_yView = value;
}

const float View::get_zoom() const {
    return m_zoom;
}

const float View::get_xView() const {
    return m_xView;
}

const float View::get_yView() const {
    return m_yView;
}
