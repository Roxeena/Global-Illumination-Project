#ifndef TNCG15_RAY_H
#define TNCG15_RAY_H

#include "Vertex.h"
#include "Triangle.h"
#include "ColorDbl.h"

class Ray
{
public:
	//Constructor and destructor
	Ray(Vertex *inStart, Vertex *inEnd, const ColorDbl inColor = ColorDbl());
	~Ray();

	//Methods
	void setRay(Vertex *inStart, Vertex *inEnd, const ColorDbl inColor = ColorDbl());
	void setTarget(Triangle *target, Vertex collisionPoint);
	void setRayColor(const ColorDbl inColor);
	Vertex getStart() const;
	Vertex getEnd() const;

private:
	Vertex *start, *end;	//start and end point of the ray
	Triangle *endTriangle;	//Triangle at the end of the ray
	Vertex intersectionPoint;	//point where the ray intersect with endTriangle
	ColorDbl rayColor;		//Color of the ray
};

#endif //TNCG15_RAY_H