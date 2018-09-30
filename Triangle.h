#include "Vertex.h";
#include "ColorDbl.h";
#include "Direction.h";
#include "Vector3D.h";

#include <cstddef>

class Triangle
{
public:
	//Constructor and destructor
	Triangle();
	Triangle(Vertex *inA, Vertex *inB, Vertex *inC, Direction &inNormal, const ColorDbl &color);
	~Triangle();

	//Method
	bool RayIntersectsTriangle(Vector3D rayOrigin, Vector3D rayVector, Triangle* inTriangle, Vector3D& outIntersectionPoint);
	void setTriangle(Vertex *inA, Vertex *inB, Vertex *inC, const Direction &inNormal, const ColorDbl &color);
	Vertex* getVertexA();
	Vertex* getVertexB();
	Vertex* getVertexC();

private:
	Vertex *pointA, *pointB, *pointC;	//The three points in the triangle
	/*
	Kanske kalla det vertex1 eller vertexA?
	
	*/
	ColorDbl trangleColor;			//color of the triangle
	Direction normal;				//normal of the triangle
	const float Epsilon = 0.0000001;
};
