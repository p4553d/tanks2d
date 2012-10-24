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
#include <signal.h>
#include <time.h>

LOG_DECLARE

timer_t physic_timer;

void* viewStarter(void* t) {
    int i=0;
    glutInit(&i, NULL);
    LOG_INFO("GLUT initialisied");

    View::getInstance();
    LOG_INFO("Going to start glutMainLoop");
    glutMainLoop();
}

void physicStepHandler(sigval_t info){
    Playground &pg = Playground::getInstance();
    pg.step();
}


void* playgroundStarter (void *t) {
    struct sigevent evp1;
    evp1.sigev_notify = SIGEV_THREAD;
    evp1.sigev_value.sival_ptr = &physic_timer;
    evp1.sigev_notify_function = physicStepHandler;
    evp1.sigev_notify_attributes = NULL;

    // Create timer thread for playground
    if (timer_create(CLOCK_REALTIME, &evp1, &physic_timer) != 0)
    {
        LOG_ERR("timer_create error");
        timer_delete(physic_timer);
        bzero(&physic_timer, sizeof(physic_timer));
    }

    struct itimerspec its;
    long long freq_nanosecs = 16666666;
    its.it_value.tv_sec = freq_nanosecs / 1000000000;
    its.it_value.tv_nsec = freq_nanosecs % 1000000000;
    its.it_interval.tv_sec = its.it_value.tv_sec;
    its.it_interval.tv_nsec = its.it_value.tv_nsec;

   if (timer_settime(physic_timer, 0, &its, NULL) == -1){
         LOG_ERR("timer_settime error");
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
//        b = new UnitBox(5,5,0.5);
//        b->teleportTo(i*10-2000, i*100);
////        pg.registerUnit(b);
//        v.registerRenderable(b);
//    }

  UnitTank *t = UnitFactory::createTank();


    pthread_join (View::viewTread, NULL);

    return 0;
}
