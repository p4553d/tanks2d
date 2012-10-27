/**
 * @file CompWheel.cpp
 * @author user p4553d
 */



#include "CompWheel.h"
#include "EChassis.h"
#include "EWheel.h"
#include "Playground.h"

CompWheel::CompWheel(int count, float radius, float speed) {
    m_count = count;
    m_wheels = new EWheel* [m_count];
    b2Color r (0.5,0.5,0.5);

    for(int i=0; i<m_count; i++) {
        m_wheels[i] = new EWheel (radius, speed);
        m_wheels[i]->setColor(r);
    }

}

CompWheel::~CompWheel() {
    for(int i=0; i<m_count; i++) {
        delete m_wheels[i];
    }
    delete[] m_wheels;
}

void CompWheel::attach(EChassis * c) {

    Playground &pg = Playground::getInstance();

    m_cWidth = c->getWidth();
    m_cHeight = c->getHeight();

    b2WheelJointDef jd;
    b2Vec2 axis(0.0f, 1.0f);

    for(int i=0; i<m_count; i++) {
//        float radius = m_wheels[i]->getRadius();

        // positioning wheels right
        // FIXME: variable postition of chassis
        m_wheels[i]->teleportTo(((2*m_cWidth)*i/(m_count-1)-(m_cWidth)),-(m_cHeight+1));

        // attach them
        jd.Initialize(c->getBody(), m_wheels[i]->getBody(), m_wheels[i]->getBody()->GetPosition(), axis);
        jd.frequencyHz = CompWheel::s_freq;
        jd.dampingRatio = CompWheel::s_dumping;
        jd.maxMotorTorque = CompWheel::s_torque;
        jd.enableMotor = true;

        m_wheels[i]->setMotor((b2WheelJoint*) pg.createJoint(&jd));
    }

}

void  CompWheel::render(){
    for(int i=0; i<m_count; i++) {
        m_wheels[i]->render();
    }
}

void CompWheel::stop() {
    for (int i=0; i<m_count; i++)
    {
    	m_wheels[i]->stop();
    }
}

void CompWheel::forward() {
    for (int i=0; i<m_count; i++)
    {
    	m_wheels[i]->forward();
    }
}

void CompWheel::backward() {
    for (int i=0; i<m_count; i++)
    {
    	m_wheels[i]->backward();
    }
}

void CompWheel::teleportTo(float32 x, float32 y){
    for (int i=0; i<m_count; i++)
    {
    	m_wheels[i]->teleportTo(x+((2*m_cWidth)*i/(m_count-1)-(m_cWidth)),y-(m_cHeight+1));
    }
}
