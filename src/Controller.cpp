/**
 * @file Controller.cpp
 * @author user p4553d
 */



#include "Controller.h"
#include "Log.h"

#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL/glut.h>	   // The GL Utility Toolkit (GLUT) Header


Controller::Controller(){
    LOG_INFO("Controller initialisation");
}

Controller& Controller::getInstance(){
    static Controller _instance;
    return _instance;
}

void Controller::keyboard(unsigned char key, int posX, int posY) {
    LOG_INFO("event");

}

 void Controller::keyboardSpecial(int key, int poX, int posY) {
     LOG_INFO("Event");
}

