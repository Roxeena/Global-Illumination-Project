#include "Triangle.h"
#include "Vector.h"

Triangle::Triangle()
	: vertexA(nullptr), vertexB(nullptr), vertexC(nullptr), normal(Direction()), trangleColor(ColorDbl())
{
}


Triangle::Triangle(Vertex *inA, Vertex *inB, Vertex *inC, Direction &inNormal, const ColorDbl &color)
	: vertexA(inA), vertexB(inB), vertexC(inC), normal(inNormal), trangleColor(color)
{
}


void Triangle::setTriangle(Vertex *inA, Vertex *inB, Vertex *inC, const Direction &inNormal, const ColorDbl &color)
{
	vertexA = inA;
	vertexB = inB;
	vertexC = inC;
	normal = inNormal;
	trangleColor = color;
}


Vertex* Triangle::getVertexA() const {
	return vertexA;
}

Vertex* Triangle::getVertexB() const {
	return vertexB;
}

Vertex* Triangle::getVertexC() const {
	return vertexC;
}


//Based on code from:
//https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm
bool Intersects(Vertex* rayOrg, Direction rayDir)
{
	//TODO: Adjust for our code
	/*const float EPSILON = 0.0000001f;
	//Trodde att vertex0 = vertexA i Triangle
	Vector vertex0 = Vector(vertexA->getX(), vertexA->getY(), vertexA->getZ());
	Vector vertex1 = Vector(vertexB->getX(), vertexB->getY(), vertexB->getZ());
	Vector vertex2 = Vector(vertexC->getX(), vertexC->getY(), vertexC->getZ());
	Vector rayOrigin = Vector(rayOrg->getX(), rayOrg->getY(), rayOrg->getZ());
	Vector rayDirection = Vector(rayDir.getX(), rayDir.getY(), rayDir.getZ());;
	Vector edge1, edge2, h, s, q;
	float a, f, u, v;
	edge1 = vertex1 - vertex0;
	edge2 = vertex2 - vertex0;
	h = rayDirection % edge2;
	a = edge1 * h;

	if (a > -EPSILON && a < EPSILON)
		return false;

	f = 1 / a;
	s = rayOrigin - vertex0;
	u = f * (s * h);

	if (u < 0.0 || u > 1.0)
		return false;

	q = s % edge1;
	v = rayDirection * q * f;

	if (v < 0.0 || u + v > 1.0)
		return false;

	// At this stage we can compute t to find out where the intersection point is on the line.
	float t = edge2 * q * f;
	if (t > EPSILON) // ray intersection
	{
		Vertex outIntersectionPoint = Vertex(rayOrigin + rayDirection * t);
		arg.setTarget(this, outIntersectionPoint);
		return true;
	}
	else // This means that there is a line intersection but not a ray intersection.
		return false;*/
}


Triangle::~Triangle()
{
}
