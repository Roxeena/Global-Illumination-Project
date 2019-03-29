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


//TODO! get Normal for sphere
const Vector Sphere::getNormal(const Vector pos) const
{
	return Vector();
}


//TODO! get intersection with sphere
bool Sphere::intersects(const Vector rayOrgin, const Vector rayDir, Vector &intersectionPoint1, Vector &intersectionPoint2) const
{
	Vector l = center - rayOrgin;
	float lR = l * rayDir;
	if (lR >= EPSILON)
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
			//std::cout << "Spere intersected! .. twice!" << std::endl;
			return true;
		}
		//If zero then only one intersection
		else
		{
			//std::cout << "Spere intersected!" << std::endl;
			intersectionPoint1 = rayOrgin + rayDir * lR;
			return true;
		}
	}

	return false;
}


ColorDbl Sphere::getColor() const {
	return color;
}


double Sphere::getArea() const
{
	return 4.0*M_PI*radius*radius;
}


void Sphere::setColor(const ColorDbl newColor) { color = newColor; }


Vector Sphere::getCenter() const { return center; }
float Sphere::getRadius() const { return radius; }

