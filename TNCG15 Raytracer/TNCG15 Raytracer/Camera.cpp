#include "Camera.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <list>

Camera::Camera(bool camPos1)
	:isPos1(camPos1)
{ }


Camera::~Camera()
{
}


Ray Camera::getRayFromPixelCoords(const double w, const double h)
{
	Vector pos = getPos();
	double aspectRatio = (double)HEIGHT / (double)WIDTH;
	double pw = w / WIDTH, ph = h / HEIGHT;
	double fovH = fov * aspectRatio;
	double radW = pw * fov - fov / 2, radH = ph * fovH - fovH / 2;
	double diffW = -sin(radW), diffH = -sin(radH);
	Vector diff(diffW, diffH, 0.0f);
	Ray ray(pos, LOOKAT, ColorDbl());
	return ray;
}


void Camera::createImage(Scene &room, std::string filename)
{
	std::cout << "Creating image " << WIDTH << " x " << HEIGHT << std::endl;
	std::cout << "Camera at position: " << getPos().toString() << std::endl;

	createPixles();
	double max = castRays(room);
	writeToFile(filename, max);
	std::cout << "DONE!" << std::endl;
}

//TODO!
void Camera::createPixles()
{
	
}



double Camera::castRays(Scene &room)
{
	double maximum = 0.0;
	std::cout << "Casting rays..." << std::endl;
	int count = 0, total = WIDTH * HEIGHT;
	for (auto &row : pixels) {
		for (Pixel &pixel : row) {
			// calculate progress
			float progress = 100.0f * (float)count / total;
			// pring progress (use one of the two lines)
			std::cout << "\r" << progress << "%";
			//            std::cout << std::setprecision(5) << progress << "%" << std::endl;

			// cast ray for this pixel
			ColorDbl clr = ColorDbl();
			std::vector<Ray> rays = pixel.getRayList();
			for (Ray r : rays) {
				for (int i = 0; i < spp; ++i) {
					clr += castRay(room, r);
				}
			}
			clr /= (double)(spp * subPixels * subPixels);
			pixel.setColor(clr);
			maximum = std::max(maximum, std::max(clr.getRed(), std::max(clr.getGreen(), clr.getBlue())));
			count += 1;
		}
	}
	return maximum;
}

//TODO!
ColorDbl Camera::castRay(Scene &room, Ray &ray, int depth)
{
	//Get intersecting triangles and object in scene
	std::vector<Intersection> intersections;
	room.detectIntersections(ray, intersections);

	ColorDbl resultingColor = ColorDbl();

	//Check if there were any intersections
	if (intersections.size() > 0)
	{
		Intersection closest;

		//Find the closest intersection, direct hit.
		for (int i = 0; i < intersections.size(); ++i)
		{
			
		}

		//We have found the closest object

		//If it is a light source return light color

		//Otherwise calculate the light contribution at this point
		//Depending on the material

		//Bounce the ray 

		//Do over with the new outgoing ray

		//Decide if we should terminate the ray or not
		//Russian roulette
		
	}
	//If no intersections ther ray missed! should not be possible
	else {
		std::cout << "Ray from: " << ray.getStart().toString() << " with direction: " << ray.getDir().toString() << " MISSED!" << std::endl;
	}
	
	return ColorDbl();
}

//TODO!
void Camera::writeToFile(const std::string filename, const double &max)
{
	
}



Vector Camera::getPos() const
{
	if (isPos1)
		return POS1;
	else
		return POS2;
}
