/**
 * @file Controller.cpp
 * @author user p4553d
 */



#include "Controller.h"
#include "View.h"
#include "Log.h"

#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL/glut.h>	   // The GL Utility Toolkit (GLUT) Header

#define KEY_ESCAPE 27


Controller::Controller(){
    LOG_INFO("Controller initialisation");
}

Controller& Controller::getInstance(){
    static Controller _instance;
    return _instance;
}

void Controller::keyboard(unsigned char key, int posX, int posY) {

    View &v = View::getInstance();
    float zoom = v.get_zoom();

    switch ( key )
    {
    case KEY_ESCAPE:
        exit ( 0 );
        break;

        // Press 'y' to zoom out.
    case 'y':
        if(zoom < 60)
        {
            zoom = zoom * 1.2;
            v.set_zoom(zoom);
        }
        break;

        // Press 'x' to zoom in.
    case 'x':
        if(zoom>1.2)
        {
            zoom = zoom * 0.8;
            v.set_zoom(zoom);
        }
        break;

    default:
        break;
    }

}

 void Controller::keyboardSpecial(int key, int poX, int posY) {
     View &v = View::getInstance();
     float xView = v.get_xView();
     float yView = v.get_yView();

     float width = v.get_width();
     float height = v.get_height();

     float zoom = v.get_zoom();

     float viewStep = width/(5*zoom);

    switch (key)
    {
    case GLUT_KEY_LEFT:
        xView -= viewStep;
        v.set_xView(xView);
        v.resize(width, height);
        break;

        // Press right to pan right.
    case GLUT_KEY_RIGHT:
        xView += viewStep;
        v.set_xView(xView);
        v.resize(width, height);
        break;

        // Press down to pan down.
    case GLUT_KEY_DOWN:
        yView -= viewStep;
        v.set_yView(yView);
        v.resize(width, height);
        break;

        // Press up to pan up.
    case GLUT_KEY_UP:
        yView += viewStep;
        v.set_yView(yView);
        v.resize(width, height);
        break;
    }

}

