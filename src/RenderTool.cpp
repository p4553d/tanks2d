#include "RenderTool.h"
#include "View.h"

// As seen in Box2D example
// TODO: replace with some another graphical framework

namespace RenderTool
{

void setPixel(int32 x, int32 y, const b2Color &color)
{
	SDL_Surface *surface = View::getInstance().getScreen();
	
	SDL_PixelFormat *pf = surface->format;
	Uint32 pixel = SDL_MapRGB(pf, color.r , color.g, color.b);

	Uint8 *target_pixel = (Uint8 *)surface->pixels + y * surface->pitch + x * 4;
	*(Uint32 *)target_pixel = pixel;
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
		b2Vec2 vertices[b2_maxPolygonVertices];

		for (int32 i = 0; i < vertexCount; ++i) {
			vertices[i] = b2Mul(xf, poly->m_vertices[i]);
		}

		DrawSolidPolygon(vertices, vertexCount, color);
	}
	break;

	default:
		break;
	}
}


void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{

}

void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{

}

void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)
{
	double error = (double)-radius;
	double x = (double)radius -0.5;
	double y = (double)0.5;
	double cx = center.x - 0.5;
	double cy = center.y - 0.5;

	while (x >= y) {
		setPixel((int)(cx + x), (int)(cy + y), color);
		setPixel((int)(cx + y), (int)(cy + x), color);

		if (x != 0) {
			setPixel((int)(cx - x), (int)(cy + y), color);
			setPixel((int)(cx + y), (int)(cy - x), color);
		}

		if (y != 0) {
			setPixel((int)(cx + x), (int)(cy - y), color);
			setPixel((int)(cx - y), (int)(cy + x), color);
		}

		if (x != 0 && y != 0) {
			setPixel((int)(cx - x), (int)(cy - y), color);
			setPixel((int)(cx - y), (int)(cy - x), color);
		}

		error += y;
		++y;
		error += y;

		if (error >= 0) {
			--x;
			error -= x;
			error -= x;
		}
	}

}

void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color)
{
	DrawCircle(center, radius, color);
}

void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{

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
