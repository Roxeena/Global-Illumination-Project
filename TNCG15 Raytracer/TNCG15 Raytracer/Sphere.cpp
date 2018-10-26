#include "Sphere.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

Sphere::Sphere(const Vector inCenter, const float r, const ColorDbl sphereColor)
	: center(inCenter), radius(r), color(sphereColor)
{ }


Sphere::~Sphere()
{
}


//TODO!
const Vector Sphere::getNormal(const Vector pos)
{
	return Vector();
}


//TODO!
bool Sphere::intersects(const Vector rayOrgin, const Vector rayDir, Vector &intersectionPoint1, Vector &intersectionPoint2) const 
{
	Vector l = center - rayOrgin;
	float lR = l * rayDir;
	if(lR >= EPSILON)
	{
		float underRoot = radius * radius + lR * lR + (l*l);

		//If negative, no intersection
		if (underRoot < 0)
			return false;
		//if positive, two intersections
		else if (underRoot > EPSILON)
		{
			intersectionPoint1 = rayOrgin + rayDir * (lR + std::sqrt(underRoot));
			intersectionPoint2 = rayOrgin + rayDir * (lR + std::sqrt(underRoot));
			return true;
		}
		//If zero then only one intersection
		else
		{
			intersectionPoint1 = rayOrgin + rayDir * lR;
			return true;
		}
	}

	return false;
}


Vector Sphere::getCenter() const { return center; }
float Sphere::getRadius() const { return radius; }

