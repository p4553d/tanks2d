/**
 * @file EWheel.cpp
 * @author user p4553d
 */

#include "EWheel.h"
#include "Playground.h"

EWheel::EWheel(float radius, float speed) {
    m_radius = radius;
    m_speed = speed;

    Playground& pg = Playground::getInstance();

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    m_body = pg.createBody(&bodyDef);

    b2CircleShape circleShape;
    circleShape.m_radius = m_radius;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 1.0f;
    fixtureDef.restitution = 0.0f;

    m_body->CreateFixture(&fixtureDef);
}

void EWheel::setMotor (b2WheelJoint* m) {
    m_motor = m;
    m_motor->SetMotorSpeed(m_speed);
}

void EWheel::go() {
}

void EWheel::stop() {
}

void EWheel::backward() {
}

b2Body* EWheel::getBody() {
    return m_body;
}

float EWheel::getRadius() {
    return m_radius;
}

float EWheel::getSpeed() {
    return m_speed;
}

