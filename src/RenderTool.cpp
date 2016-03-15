#include "RenderTool.h"
#include "View.h"

#include "SDL2_gfxPrimitives.h"

// As seen in Box2D example
// TODO: replace with some another graphical framework

namespace RenderTool
{

Uint32 transformColor(const b2Color& color)
{
	Uint32 res = 0;
	res |= ((int)(255*color.r)<<24);
	res |= ((int)(255*color.g)<<16);
	res |= ((int)(255*color.b)<<8);
	res |= 0xff;
	return res;
}


void DrawShape(b2Fixture* fixture, const b2Transform& xf, const b2Color& color)
{
	switch (fixture->GetType()) {
	case b2Shape::e_circle: {
		b2CircleShape* circle = (b2CircleShape*)fixture->GetShape();

		b2Vec2 center = b2Mul(xf, circle->m_p);
		float32 radius = circle->m_radius;
		b2Vec2 axis = b2Mul(xf.q, b2Vec2(1.0f, 0.0f));

		DrawSolidCircle(center, radius, axis, color);
	}
	break;

	case b2Shape::e_edge: {
		b2EdgeShape* edge = (b2EdgeShape*)fixture->GetShape();
		b2Vec2 v1 = b2Mul(xf, edge->m_vertex1);
		b2Vec2 v2 = b2Mul(xf, edge->m_vertex2);
		DrawSegment(v1, v2, color);
	}
	break;

	case b2Shape::e_chain: {
		b2ChainShape* chain = (b2ChainShape*)fixture->GetShape();
		int32 count = chain->m_count;
		const b2Vec2* vertices = chain->m_vertices;

		b2Vec2 v1 = b2Mul(xf, vertices[0]);
		for (int32 i = 1; i < count; ++i) {
			b2Vec2 v2 = b2Mul(xf, vertices[i]);
			DrawSegment(v1, v2, color);
			DrawCircle(v1, 0.05f, color);
			v1 = v2;
		}
	}
	break;

	case b2Shape::e_polygon: {
		b2PolygonShape* poly = (b2PolygonShape*)fixture->GetShape();
		int32 vertexCount = poly->m_vertexCount;
		b2Assert(vertexCount <= b2_maxPolygonVertices);
		//b2Vec2 vertices[b2_maxPolygonVertices];

		short *vx = new short[vertexCount];
		short *vy = new short[vertexCount];
		//TODO: Error handling

		for (int32 i = 0; i < vertexCount; ++i) {
			b2Vec2 v = b2Mul(xf, poly->m_vertices[i]);
			vx[i] = v.x;
			vy[i] = v.y;
		}

		DrawSolidPolygon(vx, vy, vertexCount, color);

		delete[]vx;
		delete[]vy;
	}
	break;

	default:
		break;
	}
}

/*
void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{

}
*/

void DrawSolidPolygon( short* x, short * y, int32 vertexCount, const b2Color& color)
{
	View &v = View::getInstance();
	SDL_Renderer *r = v.getRenderer();
	polygonColor(r, x, y, vertexCount, transformColor(color));
}

void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)
{
	View &v = View::getInstance();
	SDL_Renderer *r = v.getRenderer();
	filledCircleColor(r, center.x, center.y, radius, transformColor(color));

}

void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color)
{
	View &v = View::getInstance();
	SDL_Renderer *r = v.getRenderer();
	filledCircleColor(r, center.x, center.y, radius, transformColor(color));
}

void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{
	View &v = View::getInstance();
	SDL_Renderer *r = v.getRenderer();
	lineColor(r, p1.x, p1.y, p2.x, p2.y, transformColor(color));

}

void DrawTransform(const b2Transform& xf)
{

}

void DrawPoint(const b2Vec2& p, float32 size, const b2Color& color)
{

}

void DrawString(int x, int y, const char *string, ...)
{

}

};
