#pragma once
#include <vector>
#include "Triangle.h"
#include "Vector.h"
#include "Surface.h"
#include "Ray.h"

const int NUM_TRIANGLES = 24;
const int NUM_VERTICES = 14;

struct Intersection
{
	Surface* object;
	Vector intersectionpoint1;
	Vector intersectionpoint2;

	bool twoIntersections;
};

class Scene
{
public:
	//Constructors and destructor
	Scene();
	~Scene();

	//Methods
	void addSphere(const Vector inCenter, const float r, const ColorDbl sphereColor, const bool isLightSource = false, const bool isPerfect = false);
	void addBox(const Vector position, float size, const ColorDbl boxColor, const bool isLightSource = false, const bool isPerfect = false);
	void addTriangle(Vector *A, Vector *B, Vector *C, const ColorDbl triangleColor, const bool isLightSource = false, const bool isPerfect = false);
	std::vector<Surface*>& getObjects(); 

	void detectIntersections(Ray &ray, std::vector<Intersection> &intersections);

private:
	std::vector<Surface*> objects;
	Triangle triangles[NUM_TRIANGLES];
	Vector vertices[NUM_VERTICES];

};

