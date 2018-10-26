#pragma once
#include "Vertex.h"
#include "Triangle.h"
#include "Direction.h"
class Ray
{
public:
	//Constructor and destructor
	//TODO: Default constructor
	Ray();
	Ray(Vertex *inStart, Vertex *inEnd, const ColorDbl inColor = ColorDbl());
	~Ray();

	//Methods
	void setRay(Vertex *inStart, Vertex *inEnd, const ColorDbl inColor = ColorDbl());
	void setTarget(const Vertex collisionPoint);	//TODO: Compiler deos not recognise Triangle
	void setRayColor(const ColorDbl inColor);
	Vertex* getStart() const;
	Vertex* getEnd() const;

private:
	Vertex *start;
	Direction rayDirection;
	Vertex intersectionPoint;	//point where the ray intersect with a triangle
	ColorDbl rayColor;		//Color of the ray
};

