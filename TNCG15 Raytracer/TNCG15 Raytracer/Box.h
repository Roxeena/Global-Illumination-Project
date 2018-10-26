#pragma once
#include "Surface.h"
#include "Vector.h"
#include "Triangle.h"
#include "ColorDbl.h"
#include <vector>

const int NUM_VERTICES_BOX = 8;
const int NUM_TRIANGLES_BOX = 12;

class Box :
	public Surface
{
public:
	//Constructors and destructor
	Box(const Vector position, float size, const ColorDbl boxColor);
	virtual ~Box();

	//Inherited  methods 
	const Vector getNormal(const Vector pos);
	bool intersects(const Vector rayOrgin, const Vector rayDir, Vector &intersectionPoint1, Vector &intersectionPoint2) const ;


	//Methods
	const std::vector<Triangle>& getTriangles() const;

private:
	std::vector<Triangle> triangles;
	std::vector<Vector> vertices;
};

