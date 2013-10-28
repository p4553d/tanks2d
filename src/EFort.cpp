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
    bodyDef.type = b2_staticBody;
    m_body = pg.createBody(&bodyDef);

    b2FixtureDef fixtureDef;

    // team membership for collision filtering
    EntityFactory::setCollisionBits(fixtureDef, TEAM_NON_COMBAT);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(m_width, m_height);

    fixtureDef.shape = &boxShape;

    m_body->CreateFixture(&fixtureDef);
}
