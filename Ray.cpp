#include "Ray.h"
#include "Vertex.h";
#include "Triangle.h";
#include "ColorDbl.h";


Ray::Ray(Vertex *inStart, Vertex *inEnd, const ColorDbl inColor = ColorDbl())
	: start(inStart), end(inEnd), endTriangle(nullptr), rayColor(inColor)
{

}

void Ray::setRay(Vertex *inStart, Vertex *inEnd, const ColorDbl inColor = ColorDbl())
{
	start = inStart;
	end = inEnd;
	rayColor = inColor;
}

void Ray::setTarget(Triangle *target)
{
	endTriangle = target;
}

void Ray::setRayColor(const ColorDbl inColor)
{
	rayColor = inColor;
}

Ray::~Ray()
{
}