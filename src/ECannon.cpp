/**
 * @file ECannon.cpp
 * @author user p4553d
 */

#include "ECannon.h"
#include "EChassis.h"
#include "Playground.h"

ECannon::ECannon(float radius){

    m_radius = radius;

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

    m_body->CreateFixture(&fixtureDef);
}

void ECannon::attach(EChassis *c){

}

void ECannon::rotate(int direction) {
}

void ECannon::shoot() {
}

