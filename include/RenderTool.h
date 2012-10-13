#ifndef RENDERTOOL_H
#define RENDERTOOL_H

#include <Box2D/Box2D.h>

#include <GL/glut.h>
#include <cstdio>
#include <cstdarg>
#include <cstring>

#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f


namespace RenderTool {

void DrawShape(b2Fixture*, const b2Transform&, const b2Color&);

void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);
void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);
void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);
void DrawTransform(const b2Transform& xf);
void DrawPoint(const b2Vec2& p, float32 size, const b2Color& color);
void DrawString(int x, int y, const char* string, ...);
};

#endif // RENDERTOOL_H
