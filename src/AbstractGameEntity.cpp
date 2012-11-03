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
    if(m_body) {
        // get physical body and transformation
        const b2Transform &xf = m_body->GetTransform();

        // get Fixture / shapes to the body
        for (b2Fixture* f = m_body->GetFixtureList(); f!=NULL; f = f->GetNext()) {
            // draw shapes
            RenderTool::DrawShape(f, xf, m_color);
        }
    }
}

void AbstractGameEntity::setColor(b2Color c) {
    m_color = c;
}

void AbstractGameEntity::teleportTo(float32 x, float32 y) {
    if(m_body) {
        pthread_mutex_lock(&Playground::pg_mutex);
        m_body->SetTransform(b2Vec2(x,y), 0);
        pthread_mutex_unlock(&Playground::pg_mutex);
    }
}

void AbstractGameEntity::setUserData(AbstractGameUnit * agu) {
    if(m_body) {
        m_body->SetUserData(agu);
    }
}

AbstractGameUnit * AbstractGameEntity::getUserData() {
    AbstractGameUnit *agu = NULL;
    if (m_body) {
        agu = (AbstractGameUnit*)m_body->GetUserData();
    }
    return agu;
}

b2Vec2 AbstractGameEntity::getPosition(){
    if(m_body){
        return m_body->GetPosition();
    }
    else{
        return b2Vec2_zero;
    }
}
