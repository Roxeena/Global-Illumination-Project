#ifndef TNCG15_TRIANGLE_H
#define TNCG15_TRIANGLE_H

#include "Vertex.h"
#include "ColorDbl.h"
#include "Direction.h"
#include "Vector3D.h"
#include "Ray.h"
#include <cstddef>

class Triangle
{
public:
	//Constructor and destructor
	Triangle();
	Triangle(Vertex *inA, Vertex *inB, Vertex *inC, Direction &inNormal, const ColorDbl &color);
	~Triangle();

	//Method
	bool RayIntersectsTriangle(Ray arg) const;
	void setTriangle(Vertex *inA, Vertex *inB, Vertex *inC, const Direction &inNormal, const ColorDbl &color);
	Vertex* getVertexA() const;
	Vertex* getVertexB() const;
	Vertex* getVertexC() const;

protected:
	Vertex *vertexA, *vertexB, *vertexC;	//The three points in the triangle

	ColorDbl trangleColor;			//color of the triangle
	Direction normal;				//normal of the triangle
	const float Epsilon = 0.0000001;
};
#endif //TNCG15_TRIANGLE_H