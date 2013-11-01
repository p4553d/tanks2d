/**
 * @file ECannon.cpp
 * @author user p4553d
 */

#include "ECannon.h"
#include "EChassis.h"
#include "EFort.h"

#include "Playground.h"
#include "EntityFactory.h"

ECannon::ECannon(float radius, float speed, float damage, TeamID t) {

    m_radius = radius;
    m_speed = speed;
    m_damage = damage;
    m_cHeight = 0;

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

    // team membership for collision filtering
    EntityFactory::setCollisionBits(fixtureDef, t);

    m_body->CreateFixture(&fixtureDef);
}

void ECannon::attach(EChassis *c) {
    Playground &pg = Playground::getInstance();

    float width = c->getWidth();
    float height = c->getHeight();
    float radius = m_radius;

    m_cHeight = height;

    AbstractGameEntity::teleportTo(0,(height+radius/2));

//    b2DistanceJointDef djd;
//
//    djd.dampingRatio = 0.9f;
//    djd.frequencyHz = 10.0f;
//
//    djd.Initialize(c->getBody(), m_body, b2Vec2(-width/2, 0), b2Vec2(0, height+radius/2));
//    pg.createJoint(&djd);
//
//    djd.Initialize(c->getBody(), m_body, b2Vec2(width/2, 0), b2Vec2(0, height+radius/2));
//    pg.createJoint(&djd);

    b2RevoluteJointDef djd;
    djd.collideConnected = false;
    djd.Initialize(c->getBody(), m_body, b2Vec2(0, (height+radius/2)));
    pg.createJoint(&djd);

}

void ECannon::attach(EFort *e){
    Playground &pg = Playground::getInstance();

    float width = e->getWidth();
    float height = e->getHeight();
    float radius = m_radius;

    m_cHeight = height-2*radius;

    AbstractGameEntity::teleportTo(width, m_cHeight);

    b2RevoluteJointDef djd;
    djd.collideConnected = false;
    djd.Initialize(e->getBody(), m_body, b2Vec2(width, m_cHeight));
    pg.createJoint(&djd);


}

void ECannon::teleportTo(float x, float y) {
    m_body->SetTransform(b2Vec2(x,y+(m_radius/2)),0);
}

void ECannon::rotate(int direction) {
}

void ECannon::shoot() {
}

