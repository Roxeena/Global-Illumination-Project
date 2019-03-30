#include "Scene.h"
#include "Sphere.h"
#include "Box.h"
#include "Triangle.h"
#include <vector>

Scene::Scene()
{
	//Create the vertices
	//Top
	vertices[0].set(-3.0, 0.0, 5.0);
	vertices[1].set(0.0, 6.0, 5.0);
	vertices[2].set(10.0, 6.0, 5.0);
	vertices[3].set(13.0, 0.0, 5.0);
	vertices[4].set(10.0, -6.0, 5.0);
	vertices[5].set(0.0, -6.0, 5.0);
	vertices[6].set(5.0, 0.0, 5.0);

	//Bot
	vertices[7].set(-3.0, 0.0, -5.0);
	vertices[8].set(0.0, 6.0, -5.0);
	vertices[9].set(10.0, 6.0, -5.0);
	vertices[10].set(13.0, 0.0, -5.0);
	vertices[11].set(10.0, -6.0, -5.0);
	vertices[12].set(0.0, -6.0, -5.0);
	vertices[13].set(5.0, 0.0, -5.0);

	//create the hexegonal room in the scene
	//Roof
	triangles[0].set(&vertices[0], &vertices[1], &vertices[6], ColorDbl(1.0, 1.0, 1.0));
	triangles[1].set(&vertices[1], &vertices[2], &vertices[6], ColorDbl(1.0, 1.0, 1.0));
	triangles[2].set(&vertices[2], &vertices[3], &vertices[6], ColorDbl(1.0, 1.0, 1.0));
	triangles[3].set(&vertices[3], &vertices[4], &vertices[6], ColorDbl(1.0, 1.0, 1.0));
	triangles[4].set(&vertices[4], &vertices[5], &vertices[6], ColorDbl(1.0, 1.0, 1.0));
	triangles[5].set(&vertices[5], &vertices[0], &vertices[6], ColorDbl(1.0, 1.0, 1.0));

	//Bot
	triangles[6].set(&vertices[7], &vertices[13], &vertices[8], ColorDbl(1.0, 1.0, 1.0));
	triangles[7].set(&vertices[8], &vertices[13], &vertices[9], ColorDbl(1.0, 1.0, 1.0));
	triangles[8].set(&vertices[9], &vertices[13], &vertices[10], ColorDbl(1.0, 1.0, 1.0));
	triangles[9].set(&vertices[10], &vertices[13], &vertices[11], ColorDbl(1.0, 1.0, 1.0));
	triangles[10].set(&vertices[11], &vertices[13], &vertices[12], ColorDbl(1.0, 1.0, 1.0));
	triangles[11].set(&vertices[12], &vertices[13], &vertices[7], ColorDbl(1.0, 1.0, 1.0));

	//sides
	triangles[12].set(&vertices[1], &vertices[0], &vertices[7], ColorDbl(1.0, 0.0, 0.0));	//Red
	triangles[13].set(&vertices[7], &vertices[8], &vertices[1], ColorDbl(1.0, 0.0, 0.0));	//

	triangles[14].set(&vertices[2], &vertices[1], &vertices[8], ColorDbl(1.0, 0.6, 0.0));	//Orange
	triangles[15].set(&vertices[8], &vertices[9], &vertices[2], ColorDbl(1.0, 0.6, 0.0));	//

	triangles[16].set(&vertices[3], &vertices[2], &vertices[9], ColorDbl(1.0, 1.0, 0.0));	//Yellow
	triangles[17].set(&vertices[9], &vertices[10], &vertices[3], ColorDbl(1.0, 1.0, 0.0));	//

	triangles[18].set(&vertices[4], &vertices[3], &vertices[10], ColorDbl(0.0, 1.0, 0.0));	//Green
	triangles[19].set(&vertices[10], &vertices[11], &vertices[4], ColorDbl(0.0, 1.0, 0.0));	//

	triangles[20].set(&vertices[5], &vertices[4], &vertices[11], ColorDbl(0.0, 0.0, 1.0));	//Blue
	triangles[21].set(&vertices[11], &vertices[12], &vertices[5], ColorDbl(0.0, 0.0, 1.0));	//

	triangles[22].set(&vertices[0], &vertices[5], &vertices[12], ColorDbl(0.8, 0.0, 0.8));	//Violet
	triangles[23].set(&vertices[12], &vertices[7], &vertices[0], ColorDbl(0.8, 0.0, 0.8));	//
	

	//DEBUG: BOX scene
	//Create the vertices
	/*Vector pos = Vector(-5, -5, -5);
	float size = 10;
	//Create the box room in the scene
	//Roof
	vertices[0].set(pos.getX(), pos.getY(), pos.getZ());
	vertices[1].set(pos.getX() + size, pos.getY(), pos.getZ());
	vertices[2].set(pos.getX(), pos.getY(), pos.getZ() + size);
	vertices[3].set(pos.getX() + size, pos.getY(), pos.getZ() + size);

	//Bot
	vertices[4].set(pos.getX(), pos.getY() + size, pos.getZ());
	vertices[5].set(pos.getX() + size, pos.getY() + size, pos.getZ());
	vertices[6].set(pos.getX(), pos.getY() + size, pos.getZ() + size);
	vertices[7].set(pos.getX() + size, pos.getY() + size, pos.getZ() + size);

	//sides
	triangles[0].set(&vertices[1], &vertices[5], &vertices[0], ColorDbl(1.0, 0.0, 0.0));	//Red
	triangles[1].set(&vertices[4], &vertices[0], &vertices[5], ColorDbl(1.0, 0.0, 0.0));	//

	triangles[2].set(&vertices[0], &vertices[4], &vertices[2], ColorDbl(1.0, 0.6, 0.0));	//Orange
	triangles[3].set(&vertices[6], &vertices[2], &vertices[4], ColorDbl(1.0, 0.6, 0.0));	//

	triangles[4].set(&vertices[2], &vertices[6], &vertices[3], ColorDbl(1.0, 1.0, 0.0));	//Yellow
	triangles[5].set(&vertices[7], &vertices[3], &vertices[6], ColorDbl(1.0, 1.0, 0.0));	//

	triangles[6].set(&vertices[3], &vertices[7], &vertices[1], ColorDbl(0.0, 1.0, 0.0));	//Green
	triangles[7].set(&vertices[5], &vertices[1], &vertices[7], ColorDbl(0.0, 0.0, 1.0));	//

	//Bot
	triangles[8].set(&vertices[0], &vertices[2], &vertices[1], ColorDbl(0.0, 0.0, 1.0));	//Blue
	triangles[9].set(&vertices[3], &vertices[1], &vertices[2], ColorDbl(0.0, 0.0, 1.0));	//

	//Top
	triangles[10].set(&vertices[5], &vertices[7], &vertices[4], ColorDbl(0.8, 0.0, 0.8));	//Violet
	triangles[11].set(&vertices[6], &vertices[4], &vertices[7], ColorDbl(0.8, 0.0, 0.8));	//
	*/
}


void Scene::addSphere(const Vector inCenter, const float r, const ColorDbl sphereColor, const bool isLightSource, const bool isPerfect)
{
	objects.push_back(new Sphere(inCenter, r, sphereColor));
	objects.back()->setLight(isLightSource);
	objects.back()->setPerfect(isPerfect);
}


void Scene::addBox(const Vector position, float size, const ColorDbl boxColor, const bool isLightSource, const bool isPerfect)
{
	objects.push_back(new Box(position, size, boxColor));
	objects.back()->setLight(isLightSource);
	objects.back()->setPerfect(isPerfect);
}



void Scene::addTriangle(Vector *A, Vector *B, Vector *C, const ColorDbl triangleColor, const bool isLightSource, const bool isPerfect)
{
	objects.push_back(new Triangle(A, B, C, triangleColor));
	objects.back()->setLight(isLightSource);
	objects.back()->setPerfect(isPerfect);
}



Scene::~Scene()
{
	//Go through the vector of objects and free memory there
}


std::vector<Surface*>& Scene::getObjects()
{
	return objects;
}


void Scene::detectIntersections(Ray &ray, std::vector<Intersection> &intersections)
{
	Vector intersectionPoint1 = Vector(), intersectionPoint2 = Vector();

	//Loop through all the objects in the scene
	for (int i = 0; i < objects.size(); ++i)
	{
		//object has intersected! 
		bool wasIntersected = objects[i]->intersects(ray.getStart(), ray.getDir(), intersectionPoint1, intersectionPoint2);
		if (wasIntersected == true)
		{
			//std::cout << "Object intersected!" << std::endl;
			//Create a new intersection object
			Intersection inSec;
			inSec.intersectionpoint1 = intersectionPoint1;
			inSec.object = objects[i];

			//Did the ray intersect with the object twise?
			if (intersectionPoint2 != Vector())
			{
				inSec.intersectionpoint2 = intersectionPoint2;
				inSec.twoIntersections = true;
			}
			else
				inSec.twoIntersections = false;

			//Add this object to the list
			intersections.push_back(inSec);

			//Reset for next iteration
			intersectionPoint1 = Vector(), intersectionPoint2 = Vector();
		}
	}

	//Loop through all the triangles and calculate the intersection on them
	for (int i = 0; i < NUM_TRIANGLES; ++i)
	{
		//Triangle has intersected! Add it to the list
		bool wasIntersected = triangles[i].intersects(ray.getStart(), ray.getDir(), intersectionPoint1, intersectionPoint2);
		if (wasIntersected == true)
		{
			//std::cout << "Scene intersected!" << std::endl;
			//Create a new intersection object
			Intersection inSec;
			inSec.intersectionpoint1 = intersectionPoint1;
			inSec.object = &(triangles[i]);
			//std::cout << "Original color: " << triangles[i].getColor().toString() << std::endl;
			//std::cout << "Stored inSec color: " << inSec.object->getColor().toString() << std::endl;

			//Add this object to the list
			intersections.push_back(inSec);
		}
	}
	//std::cout << "num Intersections: " << intersections.size() << std::endl;
}