/**
 * @file ECannon.cpp
 * @author user p4553d
 */

#include "ECannon.h"
#include "EChassis.h"
#include "Playground.h"

ECannon::ECannon(float radius) {

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

void ECannon::attach(EChassis *c) {
    Playground &pg = Playground::getInstance();

    float width = c->getWidth();
    float height = c->getHeight();
    float radius = m_radius;

    teleportTo(0,(height+radius));

    b2DistanceJointDef djd;

    djd.dampingRatio = 0.9f;
    djd.frequencyHz = 10.0f;

    djd.Initialize(c->getBody(), m_body, b2Vec2(-width/2, height), b2Vec2(0, height+radius));
    pg.createJoint(&djd);

    djd.Initialize(c->getBody(), m_body, b2Vec2(width/2, height), b2Vec2(0, height+radius));
    pg.createJoint(&djd);

}

void ECannon::rotate(int direction) {
}

void ECannon::shoot() {
}

