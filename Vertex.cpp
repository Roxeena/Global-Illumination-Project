#include "Vertex.h";

Vertex::Vertex()
	: x(0.0), y(0.0), z(0.0), w(0.0)
{
}

Vertex::Vertex(const float inX, const float inY, const float inZ, const float inW = 1)
	: x(inX), y(inY), z(inZ), w(inW)
{
}

Vertex::Vertex(const Vector3D in)
	: x(in.getX()), y(in.getY()), z(in.getZ), w(1.0)
{
}

void  Vertex::setVertex(const float inX, const float inY, const float inZ, const float inW = 1)
{
	x = inX;
	y = inY;
	z = inZ;
	w = inW;
}

float Vertex::getX() const {return x;}
float Vertex::getY() const {return y;}
float Vertex::getZ() const {return z;}
float Vertex::getW() const {return w;}

Vertex::~Vertex()
{
}