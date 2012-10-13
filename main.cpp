/**
 * @file AbstractView.cpp
 * @author user p4553d
 */

#include "Log.h"
#include "Playground.h"
#include "View.h"
#include "Controller.h"

#include "UnitGround.h"
#include "UnitBox.h"

#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL/glut.h>	   // The GL Utility Toolkit (GLUT) Header
#include <pthread.h>
#include <unistd.h>

LOG_DECLARE

void* viewStarter(void* t) {
    int i=0;
    glutInit(&i, NULL);
    LOG_INFO("GLUT initialisied");

    View &v = View::getInstance();
    LOG_INFO("Going to start glutMainLoop");
    glutMainLoop();
}

void* playgroundStarter (void *t) {
    Playground &pg = Playground::getInstance();
    while(1) {  //TODO Flag?
        pg.step();
    }
}

int main(int argc, char** argv) {

    LOG_INIT("/home/mutant/projects/tanks2d2/test.log");
    LOG_INFO("Start logging");

    pthread_create(&View::viewTread, NULL, viewStarter, NULL);
    LOG_INFO("View thread started");
    sleep(2);

    pthread_create (&Playground::pgTread, NULL, playgroundStarter, NULL);
    LOG_INFO("Playground thread started");

    UnitGround *ug = new UnitGround ();
    UnitBox *b = new UnitBox(50,50);


    View &v = View::getInstance();
    Playground &pg = Playground::getInstance();
//
//    pg.registerUnit(ug);
//    v.registerRenderable(ug);

    pg.registerUnit(b);
    v.registerRenderable(b);

    pthread_join (View::viewTread, NULL);

    return 0;
}
