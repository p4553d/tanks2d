/**
 * @file View.cpp
 * @author user p4553d
 */



#include "View.h"
#include "Log.h"
#include "Controller.h"

#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL/glut.h>	   // The GL Utility Toolkit (GLUT) Header

pthread_t View::viewTread;

View::View() {

    LOG_INFO("View initialisation");

    m_zoom = 1.0f;
    m_xView = 0;
    m_yView = 0;
    m_width = 640;
    m_height = 480;

    const char* title="tanks2d2";

    // GLUT init
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );  // Display Mode
    glutInitWindowSize(m_width, m_height);					// set window size
    glutCreateWindow(title);								// create Window

    glutDisplayFunc(View::renderView);						// register Display Function
    glutIdleFunc( View::renderView);						// register Idle Function

    glutKeyboardFunc( Controller::keyboard );   			// register Keyboard Handler
    glutSpecialFunc( Controller::keyboardSpecial);

    glutReshapeFunc(resize);

    // init OpenGL 2D
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(-m_width/2, m_width/2, -m_height/2, m_height/2);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    pthread_mutex_init (&view_mutex, NULL);
}

View::~View() {
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

void View::renderView() {
    View &v = View::getInstance();
    v.render();
}

void View::render() {
    pthread_mutex_lock(&view_mutex);
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    AbstractView::render();
    glutSwapBuffers();
    pthread_mutex_unlock(&view_mutex);
}

void View::registerRenderable(IRenderable * r) {
    pthread_mutex_lock(&view_mutex);
    AbstractView::registerRenderable(r);
    pthread_mutex_unlock(&view_mutex);
}

void View::removeRenderable(IRenderable * r) {
    pthread_mutex_lock(&view_mutex);
    AbstractView::removeRenderable(r);
    pthread_mutex_unlock(&view_mutex);
}

void View::resize(int w, int h) {
    View &v = View::getInstance();

    float zoom = v.get_zoom();
    float xView = v.get_xView();
    float yView = v.get_yView();

    float nRange = 2*w/zoom;

    glViewport(0, 0, w, h);         // reset viewport
    glMatrixMode(GL_PROJECTION);    // add perspective to scene
    glLoadIdentity();

    if (w <= h) {
        glOrtho (xView-nRange, xView+nRange, yView-nRange*h/w, yView+nRange*h/w, -1, 1);
    } else {
        glOrtho (xView-nRange*w/h, xView+nRange*w/h, yView-nRange, yView+nRange, -1, 1);
    }

    glMatrixMode(GL_MODELVIEW);
}
