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
    b2Color r (1,0.7,0.5);

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

    float width = c->getWidth();
    float height = c->getHeight();

    b2WheelJointDef jd;
    b2Vec2 axis(0.0f, 1.0f);

    for(int i=0; i<m_count; i++) {
        float radius = m_wheels[i]->getRadius();

        // positioning wheels right
        m_wheels[i]->teleportTo((2*(width+radius)*i/(m_count-1)-(width+radius)),-(height));

        // attach them
        jd.Initialize(c->getBody(), m_wheels[i]->getBody(), m_wheels[i]->getBody()->GetPosition(), axis);
        jd.frequencyHz = 8.0f;
        jd.dampingRatio = 2.7f;
        jd.maxMotorTorque = 2500.0f;
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
}

void CompWheel::go() {
}

void CompWheel::backward() {
}

