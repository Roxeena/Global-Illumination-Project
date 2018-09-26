#include "Vertex.h";
#include "ColorDbl.h";
#include "Direction.h";

class Triangle
{
public:
	//Constructor and destructor
	Triangle();
	Triangle(Vertex *inA, Vertex *inB, Vertex *inC, Direction &inNormal, const ColorDbl &color);
	~Triangle();

	//Method
	Vertex* rayIntersection(const Ray &arg);
	void setTriangle(Vertex *inA, Vertex *inB, Vertex *inC, const Direction &inNormal, const ColorDbl &color);

private:
	Vertex *pointA, *pointB, *pointC;	//The three points in the triangle
	ColorDbl trangleColor;			//color of the triangle
	Direction normal;				//normal of the triangle
	const float Epsilon = 0.0000001;
};

Triangle::Triangle()
	: pointA(nullptr), pointB(nullptr), pointC(nullptr), normal(Direction()), trangleColor(ColorDbl())
{
}

Triangle::Triangle(Vertex *inA, Vertex *inB, Vertex *inC, const Direction &inNormal, const ColorDbl &color)
	: pointA(inA), pointB(inB), pointC(inC), normal(inNormal), trangleColor(color)
{
}

void Triangle::setTriangle(Vertex *inA, Vertex *inB, Vertex *inC, const Direction &inNormal, const ColorDbl &color)
{
	pointA = inA;
	pointB = inB;
	pointC = inC;
	normal = inNormal;
	trangleColor = color;
}

Vertex* Triangle::rayIntersection(const Ray &arg)
{
	//ELIAS TO DO
	//https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm


	//ALSO implement a VECTOR CLASS	that is gonna make everything easier
}

Triangle::~Triangle()
{
}