#include <iostream>
#include "Scene.h"
#include "Vector.h"
#include "ColorDbl.h"
#include "Camera.h"

int main()
{
	std::cout << "Hello Scene" << std::endl;

	//Create the scene
	Scene scene = Scene();

	//Add objects to scene
	scene.addTriangle(new Vector(1, -0.5, -0.5), new Vector(1, 0.5, -0.5), new Vector(1, 0, 0.5), ColorDbl(1.0f, 0.0f, 0.0f), false, false);
	//scene.addSphere(Vector(5.0f, 0.0f, 0.0f), 1.0f, ColorDbl(1.0f, 0.0f, 0.0f), false, false);
	//scene.addBox(Vector(1, -0.5, -0.5), 1, ColorDbl(1.0f, 0.0f, 1.0f), false, false);
	//scene.addSphere(Vector(-2.0f, 0.0f, 0.0f), 0.1f, ColorDbl(1.0f, 1.0f, 1.0f), false, false);
	//scene.addSphere(Vector(-2.0f, 0.0f, -1.0f), 0.1f, ColorDbl(1.0f, 1.0f, 1.0f), false, false);
	//Create light sources
	//scene.addSphere(Vector(-2.0f, 0.0f, 1.0f), 0.5f, ColorDbl(1.0f, 1.0f, 1.0f), true, false);

	//Corners
	/*scene.addSphere(Vector(1.0f, -1.0f, 1.0f), 1.0f, ColorDbl(0.0f, 0.0f, 1.0f), false, false);
	scene.addSphere(Vector(1.0f, 1.0f, 1.0f), 1.0f, ColorDbl(1.0f, 0.0f, 0.0f), false, false);
	scene.addSphere(Vector(1.0f, -1.0f, -1.0f), 1.0f, ColorDbl(1.0f, 0.0f, 1.0f), false, false);
	scene.addSphere(Vector(1.0f, 1.0f, -1.0f), 1.0f, ColorDbl(0.0f, 1.0f, 1.0f), false, false);*/
	
	

	//Create the camera
	Camera cam(true);

	//Shoot out rays into the scene to render it
	//Create an image and store localy on disc
	cam.createImage(scene);
	return 0;
}