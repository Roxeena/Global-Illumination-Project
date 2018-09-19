#include "Vertex.h";
#include "Triangle.h";
#include "ColorDbl.h";

class Ray
{
public:
	//Constructor and destructor
	Ray(const Vertex inStart, const Vertex inEnd);
	~Ray();

private:
	Vertex &start, &end;	//start end end point of the ray
	Triangle &endTriangle;	//Triangle at the end of the ray
	ColorDbl rayColor;		//Color of the ray
};

Ray::Ray()
{
}

Ray::~Ray()
{
}