#include "Ray.h"

Ray::Ray()
	: start(Vector()), direction(Vector()), color(ColorDbl())
{ }


Ray::Ray(const Vector orgin, const Vector dir, const ColorDbl rayColor)
	: start(orgin), direction(dir), color(rayColor)
{ }


Ray::~Ray()
{
}


const Vector Ray::getStart() const { return start; }
const Vector Ray::getDir() const { return direction; }
const ColorDbl Ray::getColor() const { return color; }

void Ray::setRay(const Vector orgin, const Vector dir, const ColorDbl rayColor)
{
	start = orgin;
	direction = dir;
	color = rayColor;
}


void Ray::setStart(const Vector orgin)
{
	start = orgin;
}


void Ray::setDir(const Vector dir)
{
	direction = dir;
}


void Ray::setColor(const ColorDbl rayColor)
{
	color = rayColor;
}