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

