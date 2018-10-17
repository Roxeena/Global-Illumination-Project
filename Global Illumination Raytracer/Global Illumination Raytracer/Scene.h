#pragma once

#include "Triangle.h"
#include "Vertex.h"
#include "Ray.h"

class Scene
{
public:
	//Constructor and destructor
	Scene();
	~Scene();

	//Methods
	//Calculate intersection point between the scene and the ray arg
	void intersect(const Ray &arg) const;	

private:
	Triangle * triangles;	//pointer to array of triangles in the scene
	Vertex *vertices;		//pointer to array of vertices in the scene
	const int numTriangles = 24;
	const int numVertices = 14;
};

