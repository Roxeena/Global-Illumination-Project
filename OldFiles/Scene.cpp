#include "Scene.h"
#include "Triangle.h"
#include "Ray.h"

//Create the scene
Scene::Scene()
{
	triangles = new Triangle[numTriangles];
	vertices = new Vertex[numVertices];

	//Create the vertices
	vertices[0].setVertex(-3.0, 0.0, 5.0);
	vertices[1].setVertex(0.0, 6.0, 5.0);
	vertices[2].setVertex(10.0, 6.0, 5.0);
	vertices[3].setVertex(13.0, 0.0, 5.0);
	vertices[4].setVertex(10.0, -6.0, 5.0);
	vertices[5].setVertex(0.0, -6.0, 5.0);
	vertices[6].setVertex(5.0, 0.0, 5.0);

	vertices[7].setVertex(-3.0, 0.0, -5.0);
	vertices[8].setVertex(0.0, 6.0, -5.0);
	vertices[9].setVertex(10.0, 6.0, -5.0);
	vertices[10].setVertex(13.0, 0.0, -5.0);
	vertices[11].setVertex(10.0, -6.0, -5.0);
	vertices[12].setVertex(0.0, -6.0, -5.0);
	vertices[13].setVertex(5.0, 0.0, -5.0);

	//create the hexegonal room in the scene
	//Roof
	triangles[0].setTriangle(vertices[0], vertices[1], vertices[6], Direction(0.0f, 0.0f, -1.0f), ColorDbl(1.0, 1.0, 1.0));
	triangles[1].setTriangle(vertices[1], vertices[2], vertices[6], Direction(0.0f, 0.0f, -1.0f), ColorDbl(1.0, 1.0, 1.0));
	triangles[2].setTriangle(vertices[2], vertices[3], vertices[6], Direction(0.0f, 0.0f, -1.0f), ColorDbl(1.0, 1.0, 1.0));
	triangles[3].setTriangle(vertices[3], vertices[4], vertices[6], Direction(0.0f, 0.0f, -1.0f), ColorDbl(1.0, 1.0, 1.0));
	triangles[4].setTriangle(vertices[4], vertices[5], vertices[6], Direction(0.0f, 0.0f, -1.0f), ColorDbl(1.0, 1.0, 1.0));
	triangles[5].setTriangle(vertices[5], vertices[0], vertices[6], Direction(0.0f, 0.0f, -1.0f), ColorDbl(1.0, 1.0, 1.0));

	//Bot
	triangles[6].setTriangle(vertices[7], vertices[13], vertices[8], Direction(0.0f, 0.0f, 1.0f), ColorDbl(1.0, 1.0, 1.0));
	triangles[7].setTriangle(vertices[8], vertices[13], vertices[9], Direction(0.0f, 0.0f, 1.0f), ColorDbl(1.0, 1.0, 1.0));
	triangles[8].setTriangle(vertices[9], vertices[13], vertices[10], Direction(0.0f, 0.0f, 1.0f), ColorDbl(1.0, 1.0, 1.0));
	triangles[9].setTriangle(vertices[10], vertices[13], vertices[11], Direction(0.0f, 0.0f, 1.0f), ColorDbl(1.0, 1.0, 1.0));
	triangles[10].setTriangle(vertices[11], vertices[13], vertices[12], Direction(0.0f, 0.0f, 1.0f), ColorDbl(1.0, 1.0, 1.0));
	triangles[11].setTriangle(vertices[12], vertices[13], vertices[7], Direction(0.0f, 0.0f, 1.0f), ColorDbl(1.0, 1.0, 1.0));

	//sides
	triangles[12].setTriangle(vertices[1], vertices[0], vertices[8], Direction(0.0f, 0.0f, -1.0f), ColorDbl(1.0, 0.0, 0.0));	//Red
	triangles[13].setTriangle(vertices[0], vertices[7], vertices[8], Direction(0.0f, 0.0f, -1.0f), ColorDbl(1.0, 0.6, 0.0));	//Orange

	triangles[14].setTriangle(vertices[2], vertices[1], vertices[9], Direction(0.0f, -1.0f, 0.0f), ColorDbl(1.0, 1.0, 0.0));	//Yellow
	triangles[15].setTriangle(vertices[1], vertices[8], vertices[9], Direction(0.0f, -1.0f, 0.0f), ColorDbl(0.0, 1.0, 0.0));	//Green

	triangles[16].setTriangle(vertices[3], vertices[2], vertices[10], Direction(0.0f, 0.0f, -1.0f), ColorDbl(0.0, 0.0, 1.0));	//Blue
	triangles[17].setTriangle(vertices[2], vertices[9], vertices[10], Direction(0.0f, 0.0f, -1.0f), ColorDbl(0.8, 0.0, 0.8));	//Violet

	triangles[18].setTriangle(vertices[4], vertices[3], vertices[11], Direction(0.0f, 0.0f, -1.0f), ColorDbl(1.0, 0.0, 0.0));	//Red
	triangles[19].setTriangle(vertices[3], vertices[10], vertices[11], Direction(0.0f, 0.0f, -1.0f), ColorDbl(1.0, 0.6, 0.0));	//Orange

	triangles[20].setTriangle(vertices[5], vertices[4], vertices[12], Direction(0.0f, 1.0f, 0.0f), ColorDbl(1.0, 1.0, 0.0));	//Yellow
	triangles[21].setTriangle(vertices[4], vertices[11], vertices[12], Direction(0.0f, 1.0f, 0.0f), ColorDbl(0.0, 1.0, 0.0));	//Green

	triangles[22].setTriangle(vertices[0], vertices[5], vertices[7], Direction(0.0f, 0.0f, -1.0f), ColorDbl(0.0, 0.0, 1.0));	//Blue
	triangles[23].setTriangle(vertices[5], vertices[12], vertices[7], Direction(0.0f, 0.0f, -1.0f), ColorDbl(0.8, 0.0, 0.8));	//Violet

}


Scene::~Scene()
{
	delete[] triangles;
	delete[] vertices;
}


//Calculates the interection between the scene and Ray arg
void Scene::intersect(const Ray &arg) const
{
	for (int i = 0; i < numTriangles; ++i)
	{
		if (triangles[i].RayIntersectsTriangle(arg))
			std::cout << "Collision with triangle: " << i << std::endl;
	}
}