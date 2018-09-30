#include "Triangle.h";
#include "Ray.h";

class Scene
{
public:
	//Constructor and destructor.,
	Scene();
	~Scene();

	//Methods
	Vertex& intersect(const Ray &arg);	//Calculates the interection between the scene and Ray arg

private:
	Triangle *triangles;	//pointer to array of all the triangles in the scene
	Vertex *vertices; 
	const unsigned int numTriangles = 24;	//number of triangles in the scene
	const unsigned int numVertices = 14;	//number of vertices in the scene
};

