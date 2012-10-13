/**
 * @file AbstractGameEntity.cpp
 * @author user p4553d
 */


#include "AbstractGameEntity.h"
#include "AbstractGameUnit.h"
#include "Playground.h"

AbstractGameEntity::~AbstractGameEntity() {
    Playground &pg = Playground::getInstance();
    pg.destructBody(m_body);
}

void AbstractGameEntity::render() {
    // get physical body and transformation
    const b2Transform &xf = m_body->GetTransform();

    // get Fixture / shapes to the body
    for (b2Fixture* f = m_body->GetFixtureList(); f!=NULL; f = f->GetNext()) {
        // draw shapes
        RenderTool::DrawShape(f, xf, m_color);
    }
}

void AbstractGameEntity::setColor(b2Color c) {
    m_color = c;
}

void AbstractGameEntity::teleportTo(float32 x, float32 y) {
}

void AbstractGameEntity::setUserData(AbstractGameUnit * agu) {
    m_body->SetUserData(agu);
}

AbstractGameUnit * AbstractGameEntity::getUserData() {
    return (AbstractGameUnit*)m_body->GetUserData();
}

