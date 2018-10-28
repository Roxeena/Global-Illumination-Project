#include "Triangle.h"


Triangle::Triangle()
	: color(ColorDbl()), normal(Vector()) 
{ 
	vertices[0] = &Vector();
	vertices[1] = &Vector();
	vertices[2] = &Vector();
}


Triangle::Triangle(Vector *A, Vector *B, Vector *C, const ColorDbl triangleColor)
	: color(triangleColor)
{
	vertices[0] = A;
	vertices[1] = B;
	vertices[2] = C;

	normal = (edge1() % edge2()).getUnit();
}


void Triangle::set(Vector *A, Vector *B, Vector *C, const ColorDbl triangleColor)
{
	color = triangleColor;

	vertices[0] = A;
	vertices[1] = B;
	vertices[2] = C;

	normal = (edge1() % edge2()).getUnit();
}


void Triangle::set(Vector *A, Vector *B, Vector *C, const Vector inNormal, const ColorDbl triangleColor)
{
	color = triangleColor;

	vertices[0] = A;
	vertices[1] = B;
	vertices[2] = C;

	normal = inNormal;
}

const Vector Triangle::getNormal(const Vector pos) { return normal; }


//TODO!
//Based on code from:
//https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm
bool Triangle::intersects(const Vector rayOrgin, const Vector rayDir, Vector &intersectionPoint1, Vector &intersectionPoint2) const
{
	//TODO: Adjust for our code
	const float EPSILON = 0.0000001f;
	Vector edge1, edge2, h, s, q;
	float a, f, u, v;
	//Eventuellt byta ut till funktionen av edge1() och 2. Har jag gjort i fel ordning?
	edge1 = *vertices[1] - *vertices[0];
	edge2 = *vertices[2] - *vertices[0];
	h = rayDir % edge2;
	a = edge1 * h;

	if (a > -EPSILON && a < EPSILON)
		return false;

	f = 1 / a;
	s = rayOrgin - *vertices[0];
	u = f * (s * h);

	if (u < 0.0 || u > 1.0)
		return false;

	q = s % edge1;
	v = rayDir * q * f;

	if (v < 0.0 || u + v > 1.0)
		return false;

	// At this stage we can compute t to find out where the intersection point is on the line.
	float t = edge2 * q * f;
	if (t > EPSILON) // ray intersection
	{
		intersectionPoint1 = rayOrgin + rayDir * t;
		//std::cout << "Triangle hit!" << std::endl;
		//std::cout << "Tri color: " << color.toString() << std::endl;
		return true;
	}
	else // This means that there is a line intersection but not a ray intersection.
		return false;
}


ColorDbl Triangle::getColor() const { return color; }

void Triangle::setColor(const ColorDbl newColor) {
	color = newColor;
}


Triangle::~Triangle()
{
}

Vector Triangle::edge1() const { return *(vertices[1]) - *(vertices[0]); }
Vector Triangle::edge2() const { return *(vertices[1]) - *(vertices[2]); }