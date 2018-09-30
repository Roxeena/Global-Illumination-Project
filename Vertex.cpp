#include "Vertex.h"

Vertex::Vertex(const float inX, const float inY, const float inZ, const float inW = 1)
	: x(0.0), y(0.0), z(0.0), w(0.0)
{
}

Vertex::Vertex(const float inX, const float inY, const float inZ, const float inW = 1)
	: x(inX), y(inY), z(inZ), w(inW)
{
}

void  Vertex::setVertex(const float inX, const float inY, const float inZ, const float inW = 1)
{
	x = inX;
	y = inY;
	z = inZ;
	w = inW;
}


Vertex::~Vertex()
{
}