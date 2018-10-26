#include "Box.h"



Box::Box(const Vector position, float size, const ColorDbl boxColor)
{
	triangles.reserve(NUM_TRIANGLES_BOX);
	vertices.reserve(NUM_VERTICES_BOX);

	//Create the vertices
	//Bot
	vertices.push_back(position);
	vertices.push_back(Vector(position.getX() + size, position.getY(), position.getZ()));
	vertices.push_back(Vector(position.getX(), position.getY(), position.getZ() + size));
	vertices.push_back(Vector(position.getX() + size, position.getY(), position.getZ() + size));

	//Top
	vertices.push_back(Vector(position.getX(), position.getY() + size, position.getZ()));
	vertices.push_back(Vector(position.getX() + size, position.getY() + size, position.getZ()));
	vertices.push_back(Vector(position.getX(), position.getY() + size, position.getZ() + size));
	vertices.push_back(Vector(position.getX() + size, position.getY() + size, position.getZ() + size));

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


//TODO!
const Vector Box::getNormal(const Vector pos)
{
	return Vector();
}


//TODO!
bool Box::intersects(const Vector rayOrgin, const Vector rayDir, Vector &intersectionPoint1, Vector &intersectionPoint2) const 
{
	int count = 0;
	Vector boxIntersection1 = Vector();
	Vector boxIntersection2 = Vector();

	//Loop through all the box triangles and calculate the intersection on them
	for (int i = 0; i < triangles.size(); ++i)
	{
		//One triangle has intersected!
		if ( triangles[i].intersects(rayOrgin, rayDir, intersectionPoint1, intersectionPoint2) == true);
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
	if (count == 1)
		intersectionPoint1 = boxIntersection1;
	else if (count == 2)
	{
		intersectionPoint1 = boxIntersection1;
		intersectionPoint2 = boxIntersection2;
	}
	else
		std::cout << "ehm... Something is weired here... cannot intersect box more than 2 times!" << std::endl;
	
	return false;
}