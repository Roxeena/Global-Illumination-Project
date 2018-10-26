#pragma once
#include "Direction.h"
#include "ColorDbl.h"
#include <iostream>	//For debug!!!!
#include "Triangle.h"
#include "Vertex.h"
#include "Ray.h"

class Scene
{
public:
	//Constructors and destructor
	Scene();
	~Scene();

	//Methods
	void intersect(Ray &arg) const;
private:
	Triangle *triangles;
	Vertex *vertices;
	const int numVertices = 14;
	const int numTriangles = 24;
};

