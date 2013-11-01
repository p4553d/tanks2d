/**
 * @file AbstractView.cpp
 * @author user p4553d
 */

#include "Log.h"
#include "Config.h"

#include "Playground.h"
#include "View.h"
#include "Controller.h"

#include "EntityFactory.h"
#include "UnitFactory.h"
#include "Team.h"

#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL/glut.h>	   // The GL Utility Toolkit (GLUT) Header
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

LOG_DECLARE
Config *mainConf;

void* viewStarter(void* t) {
    int i=0;
    glutInit(&i, NULL);
    LOG_INFO("GLUT initialisied");

    View::getInstance();
    LOG_INFO("Going to start glutMainLoop");
    glutMainLoop();

    return NULL;    // never reach it
}

void physicStepHandler(sigval_t info) {
    Playground &pg = Playground::getInstance();
    pg.step();
}


void* playgroundStarter (void *t) {
    timer_t physic_timer;

    struct sigevent evp1;
    evp1.sigev_notify = SIGEV_THREAD;
    evp1.sigev_value.sival_ptr = &physic_timer;
    evp1.sigev_notify_function = physicStepHandler;
    evp1.sigev_notify_attributes = NULL;

    // Create timer thread for playground
    if (timer_create(CLOCK_REALTIME, &evp1, &physic_timer) != 0) {
        LOG_ERR("timer_create error");
        timer_delete(physic_timer);
        bzero(&physic_timer, sizeof(physic_timer));
    }

    struct itimerspec its;
    long long freq_nanosecs = Playground::sm_timeStep*1e9;
    its.it_value.tv_sec = freq_nanosecs / 1000000000;
    its.it_value.tv_nsec = freq_nanosecs % 1000000000;
    its.it_interval.tv_sec = its.it_value.tv_sec;
    its.it_interval.tv_nsec = its.it_value.tv_nsec;

    if (timer_settime(physic_timer, 0, &its, NULL) == -1) {
        LOG_ERR("timer_settime error");
    }

    return NULL;
}

int main(int argc, char** argv) {

    mainConf = new Config("/home/mutant/workbench/tanks2d2/./main.conf");  //TODO

    LOG_INIT(mainConf->getValue("main/Logfile").c_str());
    LOG_INFO("Start logging");

    pthread_create(&View::viewTread, NULL, viewStarter, NULL);
    LOG_INFO("View thread started");
    sleep(1);

    pthread_create (&Playground::pgTread, NULL, playgroundStarter, NULL);
    LOG_INFO("Playground thread started");
//    sleep(2);

    EntityFactory::init();
    LOG_INFO("Initalise Entity factory");

    UnitGround *ug = new UnitGround ();

    View &v = View::getInstance();
    Playground &pg = Playground::getInstance();

//    pg.registerUnit(ug);
    v.registerRenderable(ug);

//    UnitBox *b;
//    for(int i=0; i<100; i++) {
//        b = new UnitBox(5,5,0.5);
//        b->teleportTo(i*10-2000, i*100);
////        pg.registerUnit(b);
//        v.registerRenderable(b);
//    }

    UnitTank *tb = UnitFactory::createTank(TEAM_BLUE);

    pg.registerUnit(tb);
    v.registerRenderable(tb);

    tb->teleportTo(100, 10);

    tb->setState(TankStateFactory::getGoState());



//    UnitTank *tr = UnitFactory::createTank(TEAM_RED);
//
//    pg.registerUnit(tr);
//    v.registerRenderable(tr);
//
//    tr->teleportTo(-200, 10);

//    UnitTower *t = UnitFactory::createTower(TEAM_GREY);
//    pg.registerUnit(t);
//    v.registerRenderable(t);

    pthread_join (View::viewTread, NULL);

    return 0;
}
