#include "Pixel.h"

Pixel::Pixel()
	: pixelColor(ColorDbl())
{
	pixelRays = new Ray[numRays];
}


Pixel::Pixel(const double red, const double blue, const double green)
	: pixelColor(ColorDbl(red, green, blue))
{
	pixelRays = new Ray[numRays];
}


Pixel::Pixel(const ColorDbl color)
	: pixelColor(color)
{
Ray::Ray(Vertex *inStart, Vertex *inEnd, const ColorDbl inColor = ColorDbl())
	: start(inStart), end(inEnd), endTriangle(nullptr), rayColor(inColor), intersectionPoint(Vertex())
{

}

void Ray::setRay(Vertex *inStart, Vertex *inEnd, const ColorDbl inColor = ColorDbl())
{
	start = inStart;
	end = inEnd;
	rayColor = inColor;
}

void Ray::setTarget(Triangle *target, Vertex collisionPoint)
{
	endTriangle = target;
	intersectionPoint = collisionPoint;
}

void Ray::setRayColor(const ColorDbl inColor)
{
	rayColor = inColor;
}


Vertex Ray::getStart() const
{
	return *start:
}
Vertex Ray::getEnd() const
{
	return *end;
}	pixelRays = new Ray[numRays];
}


Pixel::~Pixel()
{
	delete[] pixelRays;
}
