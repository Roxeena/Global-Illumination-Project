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


bool Sphere::intersects(const Vector rayOrgin, const Vector rayDir, Vector &intersectionPoint1, Vector &intersectionPoint2) const
{
	Vector l = center - rayDir;
	float tca = l * rayDir;

	//No hit!
	if (tca < 0)
		return false;

	float d2 = l * l - tca * tca;

	//No hit!
	if (d2 > radius * radius)
		return false;

	float thc = sqrt(radius * radius - d2);

	//Only one hit
	if (thc < EPSILON)
	{
		//std::cout << "Sphere intersected!" << std::endl;
		intersectionPoint1 = rayOrgin + rayDir * tca;
		return true;
	}
	//Two hits
	else
	{
		//std::cout << "Spere intersected! .. twice!" << std::endl;
		intersectionPoint1 = rayOrgin + rayDir * (tca - thc);
		intersectionPoint2 = rayOrgin + rayDir * (tca + thc);
		return true;
	}
	
	/*//Vector from rayorgin to center
	Vector l = center - rayOrgin;
	//Angle between l and rayDirection
	float theta = acos((l * rayDir)/(l.getLen() * rayDir.getLen()));
	float a = l.getLen() * tan(theta);
	
	//If a is samller than the redius the ray hit twise
	if (a < radius)
	{
		intersectionPoint1 = ;
		intersectionPoint2 = ;
		//std::cout << "Spere intersected! .. twice!" << std::endl;
		return true;
	}
	//If a is equal to redius then the ray hit only once on the edge
	else if (a == radius)
	{
		//std::cout << "Spere intersected!" << std::endl;
		intersectionPoint1 = ;
		return true;
	}
	//If a is bigger than radius then ray missed
	else
		return false;
	*/

}


ColorDbl Sphere::getColor() const {
	//std::cout << "Sphere Color: " << color.toString() << std::endl;
	return color;
}


double Sphere::getArea() const
{
	return 4.0*M_PI*radius*radius;
}


void Sphere::setColor(const ColorDbl newColor) { color = newColor; }


Vector Sphere::getCenter() const { return center; }
float Sphere::getRadius() const { return radius; }

