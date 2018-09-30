#include "Triangle.h";
#include "Vertex.h";
#include "ColorDbl.h";
#include "Direction.h";
#include "Vector3D.h";


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

Vertex* Triangle::getVertexA() const
{
	return vertexA;
}

Vertex* Triangle::getVertexB() const
{
	return vertexB;
}

Vertex* Triangle::getVertexC() const
{
	return vertexC;
}


//Based on code from:
//https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm
bool Triangle::RayIntersectsTriangle(Ray arg) const
{
	const float EPSILON = 0.0000001;
	//Trodde att vertex0 = vertexA i Triangle
	Vector3D vertex0 = Vector3D(vertrexA);
	Vector3D vertex1 = Vector3D(vertrexB);
	Vector3D vertex2 = Vector3D(vertrexC);
	Vector3D rayOrigin = Vector3D(arg.getStart());
	Vector3D rayEnd = Vector3D(arg.getEnd());
	Vector3D rayVector = rayEnd - rayOrgin;
	Vector3D edge1, edge2, h, s, q;
	float a, f, u, v;
	edge1 = vertex1 - vertex0;
	edge2 = vertex2 - vertex0;
	h = rayVector % edge2;
	a = edge1 * h;

	if (a > -EPSILON && a < EPSILON)
		return false;

	f = 1 / a;
	s = rayOrigin - vertex0;
	u = f * (s * h);

	if (u < 0.0 || u > 1.0)
		return false;

	q = s % edge1;
	v = f * rayVector * q;

	if (v < 0.0 || u + v > 1.0)
		return false;

	// At this stage we can compute t to find out where the intersection point is on the line.
	float t = f * edge2 * q;
	if (t > EPSILON) // ray intersection
	{
		outIntersectionPoint = rayOrigin + rayVector * t;
		arg.setTarget(this, outIntersectionPoint);
		return true;
	}
	else // This means that there is a line intersection but not a ray intersection.
		return false;
}

Triangle::~Triangle()
{
}