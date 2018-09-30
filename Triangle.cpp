#include "Triangle.h"
#include "Vertex.h";
#include "ColorDbl.h";
#include "Direction.h";
#include "Vector3D.h";


Triangle::Triangle()
	: pointA(nullptr), pointB(nullptr), pointC(nullptr), normal(Direction()), trangleColor(ColorDbl())
{
}

Triangle(Vertex *inA, Vertex *inB, Vertex *inC, const Direction &inNormal, const ColorDbl &color)
	: pointA(inA), pointB(inB), pointC(inC), normal(inNormal), trangleColor(color)
{
}

void Triangle::setTriangle(Vertex *inA, Vertex *inB, Vertex *inC, const Direction &inNormal, const ColorDbl &color)
{
	pointA = inA;
	pointB = inB;
	pointC = inC;
	normal = inNormal;
	trangleColor = color;
}

Vertex* Triangle::getVertexA()
{
	return pointA;
}

Vertex* Triangle::getVertexB()
{
	return pointB;
}

Vertex* Triangle::getVertexC()
{
	return pointC;
}


//ELIAS TO DO
//https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm
bool RayIntersectsTriangle(Vector3D rayOrigin, Vector3D rayVector, Triangle* inTriangle, Vector3D& outIntersectionPoint)
{
	const float EPSILON = 0.0000001;
	//Trodde att vertex0 = pointA i Triangle
	Vector3D vertex0 = inTriangle->getVertexA();
	Vector3D vertex1 = inTriangle->getVertexB();
	Vector3D vertex2 = inTriangle->getVertexC();
	Vector3D edge1, edge2, h, s, q;
	float a, f, u, v;
	edge1 = vertex1 - vertex0;
	edge2 = vertex2 - vertex0;
	h = rayVector.crossProduct(edge2);
	a = edge1.dotProduct(h);
	if (a > -EPSILON && a < EPSILON)
		return false;
	f = 1 / a;
	s = rayOrigin - vertex0;
	u = f * (s.dotProduct(h));
	if (u < 0.0 || u > 1.0)
		return false;
	q = s.crossProduct(edge1);
	v = f * rayVector.dotProduct(q);
	if (v < 0.0 || u + v > 1.0)
		return false;
	// At this stage we can compute t to find out where the intersection point is on the line.
	float t = f * edge2.dotProduct(q);
	if (t > EPSILON) // ray intersection
	{
		outIntersectionPoint = rayOrigin + rayVector * t;
		return true;
	}
	else // This means that there is a line intersection but not a ray intersection.
		return false;
}

Triangle::~Triangle()
{
}