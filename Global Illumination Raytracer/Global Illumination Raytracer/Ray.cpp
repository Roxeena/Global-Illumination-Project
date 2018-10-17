#include "Ray.h"

Ray::Ray(Vertex *inStart, Vertex *inEnd, const ColorDbl inColor)
	: start(inStart), end(inEnd), endTriangle(nullptr), rayColor(inColor), intersectionPoint(Vertex())
{

}

void Ray::setRay(Vertex *inStart, Vertex *inEnd, const ColorDbl inColor)
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
	return *start;
}
Vertex Ray::getEnd() const
{
	return *end;
}


Ray::~Ray()
{
}
