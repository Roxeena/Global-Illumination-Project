#include "Box.h"


Box::Box(const Vector pos, float size, const ColorDbl boxColor)
	: position(pos), color(boxColor)
{
	triangles.reserve(NUM_TRIANGLES_BOX);
	vertices.reserve(NUM_VERTICES_BOX);

	//Create the vertices
	//Bot
	vertices.push_back(pos);
	vertices.push_back(Vector(pos.getX() + size, pos.getY(), pos.getZ()));
	vertices.push_back(Vector(pos.getX(), pos.getY(), pos.getZ() + size));
	vertices.push_back(Vector(pos.getX() + size, pos.getY(), pos.getZ() + size));

	//Top
	vertices.push_back(Vector(pos.getX(), pos.getY() + size, pos.getZ()));
	vertices.push_back(Vector(pos.getX() + size, pos.getY() + size, pos.getZ()));
	vertices.push_back(Vector(pos.getX(), pos.getY() + size, pos.getZ() + size));
	vertices.push_back(Vector(pos.getX() + size, pos.getY() + size, pos.getZ() + size));

	//Create the Triangles
	//Sides
	triangles.push_back(Triangle(&vertices[1], &vertices[5], &vertices[0], boxColor));
	triangles.push_back(Triangle(&vertices[4], &vertices[0], &vertices[5], boxColor));

	triangles.push_back(Triangle(&vertices[0], &vertices[4], &vertices[2], boxColor));
	triangles.push_back(Triangle(&vertices[6], &vertices[2], &vertices[4], boxColor));

	triangles.push_back(Triangle(&vertices[2], &vertices[6], &vertices[3], boxColor));
	triangles.push_back(Triangle(&vertices[7], &vertices[3], &vertices[6], boxColor));

	triangles.push_back(Triangle(&vertices[3], &vertices[7], &vertices[1], boxColor));
	triangles.push_back(Triangle(&vertices[5], &vertices[1], &vertices[7], boxColor));

	//Bot
	triangles.push_back(Triangle(&vertices[0], &vertices[2], &vertices[1], boxColor));
	triangles.push_back(Triangle(&vertices[3], &vertices[1], &vertices[2], boxColor));

	//Top
	triangles.push_back(Triangle(&vertices[5], &vertices[7], &vertices[4], boxColor));
	triangles.push_back(Triangle(&vertices[6], &vertices[4], &vertices[7], boxColor));
}


Box::~Box()
{
	//Delete the triangles and vertices vectors
}

const std::vector<Triangle>& Box::getTriangles() const { return triangles; }


//TODO! get Normal in Box
const Vector Box::getNormal(const Vector pos) const
{
	return Vector();
}


//TODO! get Intersection in Box
bool Box::intersects(const Vector rayOrgin, const Vector rayDir, Vector &intersectionPoint1, Vector &intersectionPoint2) const
{
	int count = 0;
	Vector boxIntersection1 = Vector();
	Vector boxIntersection2 = Vector();

	//Loop through all the box triangles and calculate the intersection on them
	for (int i = 0; i < triangles.size(); ++i)
	{
		//One triangle has intersected!
		if (triangles[i].intersects(rayOrgin, rayDir, intersectionPoint1, intersectionPoint2) == true);
		{
			++count;
			//If one intersection so far
			if (count == 1)
				boxIntersection1 = intersectionPoint1;
			//If two intersections so far
			else if (count == 2)
				boxIntersection2 = intersectionPoint1;
			//Weired if more than 2 intersections!
			else
				std::cout << "ehm... Something is weired here... cannot intersect box more than 2 times!" << std::endl;
		}
	}

	//How many intersections?
	if (count == 1) {
		intersectionPoint1 = boxIntersection1;
		//std::cout << "Box intersected!" << std::endl;
		return true;
	}
	else if (count == 2) {
		//std::cout << "Box intersected! ...Twice!" << std::endl;
		intersectionPoint1 = boxIntersection1;
		intersectionPoint2 = boxIntersection2;
		return true;
	}
	else
		std::cout << "ehm... Something is weired here... cannot intersect box more than 2 times!" << std::endl;

	return false;
}


ColorDbl Box::getColor() const { return color; }

void Box::setColor(const ColorDbl newColor) {
	color = newColor;

	//Loop through all the box triangles and set the new color
	for (int i = 0; i < triangles.size(); ++i)
	{
		triangles[i].setColor(newColor);
	}
}


Vector Box::getCenter() const
{
	double newX = vertices[7].getX() - position.getX();
	double newY = vertices[7].getY() - position.getY();
	double newZ = vertices[7].getZ() - position.getZ();

	return Vector(newX, newY, newZ);
}


double Box::getArea() const
{
	double size = vertices[1].getX() - vertices[0].getX();
	return 6.0*size*size;
}