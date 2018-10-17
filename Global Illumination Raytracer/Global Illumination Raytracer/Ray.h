#pragma once
#include "Vertex.h"
#include "Triangle.h"
class Ray
{
public:
	//Constructor and destructor
	//TODO: Default constructor
	Ray(Vertex *inStart, Vertex *inEnd, const ColorDbl inColor = ColorDbl());
	~Ray();

	//Methods
	void setRay(Vertex *inStart, Vertex *inEnd, const ColorDbl inColor = ColorDbl());
	void setTarget(Triangle *target, Vertex collisionPoint);
	void setRayColor(const ColorDbl inColor);
	Vertex getStart() const;
	Vertex getEnd() const;

private:
	Vertex *start; 
	Vertex *end;	//start and end point of the ray
	Triangle *endTriangle;	//Triangle at the end of the ray
	Vertex intersectionPoint;	//point where the ray intersect with endTriangle
	ColorDbl rayColor;		//Color of the ray
};

