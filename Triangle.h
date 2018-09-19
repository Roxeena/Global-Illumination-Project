#include "Vertex.h";
#include "ColorDbl.h";
#include "Direction.h";

class Triangle
{
public:
	//Constructor and destructor
	Triangle();
	Triangle(const Vertex inA, const Vertex inB, const Vertex inC, const Direction inNormal, const ColorDbl color);
	~Triangle();

	//Method
	Vertex& rayIntersect(const Triangle &triangle);
	void setTriangle(const Vertex inA, const Vertex inB, const Vertex inC, const Direction inNormal, const ColorDbl color);

private:
	Vertex pointA, pointB, pointC;	//The three points in the triangle
	ColorDbl trangleColor;			//color of the triangle
	Direction normal;				//normal of the triangle
};

Triangle::Triangle()
	: pointA(Vertex()), pointB(Vertex()), pointC(Vertex()), normal(Direction(0.0, 0.0, 0.0)), trangleColor(ColorDbl())
{
}

Triangle::Triangle(const Vertex inA, const Vertex inB, const Vertex inC, const Direction inNormal, const ColorDbl color)
	: pointA(inA), pointB(inB), pointC(inC), normal(inNormal), trangleColor(color)
{
}

void Triangle::setTriangle(const Vertex inA, const Vertex inB, const Vertex inC, const Direction inNormal, const ColorDbl color)
{
	pointA = inA;
	pointB = inB;
	pointC = inC;
	normal = inNormal;
	trangleColor = color;
}

Triangle::~Triangle()
{
}