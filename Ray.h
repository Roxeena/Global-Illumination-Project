#include "Vertex.h";
#include "Triangle.h";
#include "ColorDbl.h";

class Ray
{
public:
	//Constructor and destructor
	Ray(Vertex *inStart, Vertex *inEnd, const ColorDbl inColor = ColorDbl());
	~Ray();

	//Methods
	void setRay(Vertex *inStart, Vertex *inEnd, const ColorDbl inColor = ColorDbl());
	void setTarget(Triangle *target);
	void setRayColor(const ColorDbl inColor);

private:
	Vertex *start, *end;	//start end end point of the ray
	Triangle *endTriangle;	//Triangle at the end of the ray
	ColorDbl rayColor;		//Color of the ray
};


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