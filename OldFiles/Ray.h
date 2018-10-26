#pragma once
#include "Vertex.h"
#include "Triangle.h"

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
	void setTarget(Triangle *target, const Vertex collisionPoint);	//TODO: Compiler deos not recognise Triangle
	void setRayColor(const ColorDbl inColor);
	Vertex* getStart() const;
	Vertex* getEnd() const;

private:
	Vertex *start; 
	Vertex *end;	//start and end point of the ray
	Triangle *endTriangle;	//Triangle at the end of the ray	//TODO: Compiler deos not recognise Triangle
	Vertex intersectionPoint;	//point where the ray intersect with endTriangle
	ColorDbl rayColor;		//Color of the ray
};

