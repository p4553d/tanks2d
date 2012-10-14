/**
 * @file AbstractView.cpp
 * @author user p4553d
 */

#include "Log.h"
#include "Playground.h"
#include "View.h"
#include "Controller.h"

#include "EntityFactory.h"
#include "UnitFactory.h"

#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL/glut.h>	   // The GL Utility Toolkit (GLUT) Header
#include <pthread.h>
#include <unistd.h>

LOG_DECLARE

void* viewStarter(void* t) {
    int i=0;
    glutInit(&i, NULL);
    LOG_INFO("GLUT initialisied");

    View::getInstance();
    LOG_INFO("Going to start glutMainLoop");
    glutMainLoop();
}

void* playgroundStarter (void *t) {
    Playground &pg = Playground::getInstance();
    while(1) {  //TODO Flag?
//        printf("+");
        pg.step();
    }
}

int main(int argc, char** argv) {

    LOG_INIT("/home/mutant/projects/tanks2d2/test.log");
    LOG_INFO("Start logging");

    pthread_create(&View::viewTread, NULL, viewStarter, NULL);
    LOG_INFO("View thread started");
    sleep(1);

    pthread_create (&Playground::pgTread, NULL, playgroundStarter, NULL);
    LOG_INFO("Playground thread started");
//    sleep(2);

    UnitGround *ug = new UnitGround ();
    UnitBox *b;


    View &v = View::getInstance();
    Playground &pg = Playground::getInstance();

//    pg.registerUnit(ug);
    v.registerRenderable(ug);

//    for(int i=0; i<100; i++) {
//        b = new UnitBox(50,50);
//        b->teleportTo(i*10-1000, i*100+1000);
////        pg.registerUnit(b);
//        v.registerRenderable(b);
//    }

    b2Color r (1,0.5,0.5);

    EChassis *c = new EChassis (20,10);
    CompWheel *w = new CompWheel (4, 2.0f, 10.0f);

    c->setColor(r);
    w->setColor(r);

    w->attach(c);

    c->teleportTo(0,1000);

    v.registerRenderable(c);
    v.registerRenderable(w);


    pthread_join (View::viewTread, NULL);

    return 0;
}
