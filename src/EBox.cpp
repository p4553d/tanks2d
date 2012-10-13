/**
 * @file EBox.cpp
 * @author user p4553d
 */

#include "EBox.h"
#include "Playground.h"

EBox::EBox(float width, float height, float density) {
    m_width = width;
    m_height = height;
    m_density = density;

    Playground& pg = Playground::getInstance();

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    m_body = pg.createBody(&bodyDef);

    b2FixtureDef fixtureDef;
    fixtureDef.density = 2.0f;
    fixtureDef.friction = 0.5f;

    b2PolygonShape boxShape;
    boxShape.SetAsBox(m_width, m_height);

    fixtureDef.shape = &boxShape;

    m_body->CreateFixture(&fixtureDef);
}
