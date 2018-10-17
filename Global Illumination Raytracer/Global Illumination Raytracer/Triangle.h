#pragma once
#include "Vertex.h"
#include "ColorDbl.h"
#include "Direction.h"
#include "Ray.h"

class Triangle
{
public:
	//Constructors and destructor
	Triangle();
	Triangle(Vertex *inA, Vertex *inB, Vertex *inC, Direction &inNormal, const ColorDbl &color);
	~Triangle();

	//Methods
	bool RayIntersectsTriangle(const Ray &arg) const;
	void setTriangle(Vertex *inA, Vertex *inB, Vertex *inC, const Direction &inNormal, const ColorDbl &color);
	Vertex* getVertexA() const;
	Vertex* getVertexB() const;
	Vertex* getVertexC() const;

private:
	Vertex * vertexA, *vertexB, *vertexC;	//The three points in the triangle

	ColorDbl trangleColor;			//color of the triangle
	Direction normal;				//normal of the triangle
	const float Epsilon = 0.0000000001f;
};

