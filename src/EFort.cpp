/**
 * @file EFort.cpp
 * @author user p4553d
 */


#include "EFort.h"
#include "Playground.h"
#include "EntityFactory.h"

EFort::EFort(float width, float height) {
    m_width = width;
    m_height = height;

    Playground& pg = Playground::getInstance();

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;//b2_staticBody;
    m_body = pg.createBody(&bodyDef);

    b2FixtureDef fixtureDef;
    fixtureDef.density = 7.0f;
    fixtureDef.friction = 1.0f;

    // team membership for collision filtering
    EntityFactory::setCollisionBits(fixtureDef, TEAM_NON_COMBAT);

    b2PolygonShape trapeze;
    b2Vec2 vertices[4];
    vertices[0].Set(0.0f, 0.0f);
    vertices[1].Set(width*2, 0.0f);
    vertices[2].Set(width*1.5, height);
    vertices[3].Set(width*.5, height);

    trapeze.Set(vertices, 4);



    fixtureDef.shape = &trapeze;

    m_body->CreateFixture(&fixtureDef);
}

b2Body* EFort::getBody(){
    return m_body;
}

float EFort::getWidth() {
    return m_width;
}

float EFort::getHeight() {
    return m_height;
}
