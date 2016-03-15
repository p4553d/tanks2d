/**
 * @file EGround.cpp
 * @author user p4553d
 */


#include "EGround.h"
#include "Playground.h"

EGround::EGround() {
    Playground &pg = Playground::getInstance();

    b2BodyDef bd;
    m_body = pg.createBody(&bd);

    b2EdgeShape shape;
    b2FixtureDef fd;
    fd.shape = &shape;
    fd.density = 0.0f;
    fd.friction = 0.6f;

    float32 x = 220.0f, y1 = 0, dx = 50, dy=200;
    for (int32 i = 1; i < 100; ++i)
    {
        //float32 y2 = 30*sin(i);
        float32 y2 = 0;
        shape.Set(b2Vec2(x, y1+dy), b2Vec2(x + dx, y2+dy));
        m_body->CreateFixture(&fd);
        y1 = y2;
        x += dx;
    }
}

