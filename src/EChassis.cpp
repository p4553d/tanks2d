/**
 * @file EChassis.cpp
 * @author user p4553d
 */


#include "EChassis.h"
#include "Playground.h"
#include "EntityFactory.h"

EChassis::EChassis(float width, float height, TeamID t, float density) {
    m_width = width;
    m_height = height;
    m_density = density;

    Playground& pg = Playground::getInstance();

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    m_body = pg.createBody(&bodyDef);

    b2FixtureDef fixtureDef;
    fixtureDef.density = m_density;
    fixtureDef.friction = 0.5f;

    // team membership for collision filtering
    EntityFactory::setCollisionBits(fixtureDef, t);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(m_width, m_height);

    fixtureDef.shape = &boxShape;

    m_body->CreateFixture(&fixtureDef);
}

float EChassis::getWidth() {
    return m_width;
}

float EChassis::getHeight() {
    return m_height;
}

b2Body* EChassis::getBody(){
    return m_body;
}
