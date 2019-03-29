#define _CRT_SECURE_NO_DEPRECATE
#include "Camera.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <stdlib.h>
#include <ctime>
#include <vector>


Camera::Camera(bool camPos1)
	:isPos1(camPos1)
{
	cameraPlane.reserve(4);
	cameraPlane.push_back(Vector(0, -1, 1));
	cameraPlane.push_back(Vector(0, 1, 1));
	cameraPlane.push_back(Vector(0, -1, -1));
	cameraPlane.push_back(Vector(0, 1, -1));
}


Camera::~Camera()
{
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


//TODO: Change this to be more like our code and like the slides say
//DONE??
void Camera::createPixles()
{
	for (int h = 0; h < HEIGHT; ++h) {
		for (int w = 0; w < WIDTH; ++w) {
			Pixel p = Pixel();

			//Find the middle of the pixel
			float pixelSize = camPlaneSize / WIDTH;
			p.setSize(pixelSize);
			Vector mid = cameraPlane[0] + Vector(0, pixelSize / 2.0f * (w + 1), pixelSize / 2.0f * (h+ 1));
			float min = -1 + pixelSize / 2.0f;
			//Find the middle of the subpixels
			//Create a ray for every subpixel and add to the list of rays for this pixel
			
			//TODO: Add subpixles and random rays
			for (int subX = 0; subX < subPixels; ++subX) {
				for (int subY = 0; subY < subPixels; ++subY) {
					//Vector rayEnd = mid;
					Vector rayEnd = Vector(0, w * pixelSize + min, h*pixelSize + min);
					Vector rayStart = getPos();
					Vector rayDir = rayEnd - rayStart;

					//Create a new ray
					Ray newRay = Ray(rayStart, rayDir, ColorDbl());
					p.addRay(newRay);
				}
			}

			pixels[h][w] = p;
		}
	}
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
			std::cout << "\r" << progress << "%";

			// cast ray for this pixel
			ColorDbl clr = ColorDbl();
			std::vector<Ray> rays = pixel.getRayList();

			if (rays.empty()) {
				std::cout << "No Rays for this pixel!" << std::endl;
				continue;
			}

			//For every ray (subpixel) in the pixel
			for (Ray r : rays) {
				clr += castRay(room, r);
			}
			clr /= (double)(rays.size());
			//std::cout << "pixel Color: " << clr.toString() << std::endl;
			pixel.setColor(clr);
			maximum = std::max(maximum, std::max(clr.getRed(), std::max(clr.getGreen(), clr.getBlue())));
			count += 1;
		}
	}
	return maximum;
}


ColorDbl Camera::castRay(Scene &room, Ray &ray, int depth)
{
	//std::cout << "shooting ray: " << ray.getStart().toString() << " -> " << ray.getDir().toString() << std::endl;
	//Get intersecting triangles and objects in scene
	std::vector<Intersection> intersections;
	room.detectIntersections(ray, intersections);

	ColorDbl resultingColor = ColorDbl();

	//Check if there were any intersections
	if (!intersections.empty())
	{
		//std::cout << "Found intersections!" << std::endl;
		bool hit1 = true;
		double distance1, distance2;

		//Find the closest intersection, direct hit.
		int closest = findClosestIntersection(intersections, ray, distance1, distance2, hit1);

		//Have we found the closest object
		if (closest != -1) {
			//std::cout << "Found closest intersection!" << std::endl;

			//If it is a light source return light color
			if (intersections[closest].object->isLight()) {
				//std::cout << "Found Light Source!" << std::endl;
				return intersections[closest].object->getColor();
			}

			//Find the intersection point and which one it is
			Vector point;
			point = hit1 ? intersections[closest].intersectionpoint1 : intersections[closest].intersectionpoint2;

			//Calculate the reflected ray from the surface
			Vector normal = intersections[closest].object->getNormal(point);
			Vector flip = -(ray.getDir().getUnit());
			Vector outDir = flip.getReflection(normal);
			ColorDbl indirectIllumination = ColorDbl();
			ColorDbl directIllumination = ColorDbl();

			//DEBUG
			resultingColor = intersections[closest].object->getColor();

			//Calculate outgoing color depending on the material
			//PERFECT
			if (intersections[closest].object->isPerfect()) {
				//TODO! Perfect reflector
				//Follow light around scene and return the color of the ray coming back
				//Metallic object
			}
			//LAMBERTIAN
			else if (depth < MAX_DEPTH) {

				//Calculate indirect ilumination

				//Calculate the direct illumination
				//directIllumination = calculateDirect(room, intersections[closest].object, point, ray);

				//Calculate total color
				//resultingColor = (indirectIllumination * 2.0 + directIllumination / M_PI);
				//std::cout << "Setting resulting Color to: " << intersections[closest].object->getColor().toString() << std::endl;

			}
			//If too many bounces, perform russian roulette to decide if ray continues or not
			else {
				//Decide if we should terminate the ray or not
				//Russian roulette
			}
		}
		else {
			std::cout << "Could not find the closest hit!" << std::endl;
		}

	}
	//If no intersections the ray missed! should not be possible
	else {
		std::cout << "Ray from: " << ray.getStart().toString() << " with direction: " << ray.getDir().toString() << " MISSED!" << std::endl;
	}

	//std::cout << "Resulting Color: " << resultingColor.toString() << std::endl;
	return resultingColor;
}


void Camera::writeToFile(const std::string filename, const double &max)
{
	std::cout << std::endl << std::endl << "Writing image... (Max value: " << max << ")" << std::endl;

	//Create and open a file
	FILE *fp = fopen(filename.c_str(), "w");

	//Print all the colors in respective pixel
	(void)fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
	for (auto &row : pixels) {
		for (Pixel &pixel : row) {
			ColorDbl clr = pixel.getColor();
			(void)fprintf(fp, "%d %d %d ",
				(int)(255 * (clr.getRed() / max)),
				(int)(255 * (clr.getGreen() / max)),
				(int)(255 * (clr.getBlue() / max)));
		}
	}

	//When done close the file
	(void)fclose(fp);
	std::cout << std::endl << "Wrote image to `" + filename + "`." << std::endl;
}


Vector Camera::getPos() const
{
	if (isPos1)
		return POS1;
	else
		return POS2;
}


double Camera::randMinMax(const double min, const double max) const {
	srand(time(0));
	return min + rand() * (max - min);
}



//Light Calculations
ColorDbl Camera::calculatePerfect(const Surface* object, const Vector intersecP, const Ray inRay) const
{
	return ColorDbl();
}


ColorDbl Camera::calculateDirect(Scene &room, const Surface* object, const Vector intersecP, const Ray inRay) const
{
	//Direct illumination
	ColorDbl directIllumination = ColorDbl();
	double sum = 0.0;
	int numLights = 0;
	std::vector<Surface*> objects = room.getObjects();
	for (int i = 0; i < objects.size(); i++) {
		if (objects.at(i)->isLight()) {
			numLights++;
			Surface *l = objects.at(i); // Pointer to current light
			ColorDbl tempColor(); // Total color per light

			for (int j = 0; j < NUM_SHADOW_RAYS; j++) {
				bool shaded = false;
				Vector pDir = getRanomPoint(intersecP, l); // Vector towards light, not random currently
				double dist = pDir.getLen();
				Vector ranodmPAtLight = intersecP + pDir;
				pDir = pDir.getUnit();
				Ray toLight = Ray(intersecP, pDir, ColorDbl());

				//Shoot shadow ray to this random point on light 
				for (auto &o : objects) {
					//Get intersecting triangles and objects between the intersecP and the ligth
					std::vector<Intersection> intersections;
					room.detectIntersections(toLight, intersections);

					//Were there any intersections?
					if (!intersections.empty()) {
						//Find closest intersection
						bool hit1 = true;
						double distance1, distance2;
						int closest = findClosestIntersection(intersections, inRay, distance1, distance2, hit1);
						Vector closestIntersectionP = hit1 ? intersections[closest].intersectionpoint1 : intersections[closest].intersectionpoint2;

						//Calculate the distance to the closest intersection point from the intersection point on the object
						double bestDistance = (closestIntersectionP - intersecP).getLen();

						//Compare with the distance to the light source, if shorter then shaded
						if (bestDistance < dist && !o->isLight())
							shaded = true;
					}

				}

				//Calculate the direct illumination of not shaded
				if (!shaded) {

					//Calculate the geometric  term
					Vector normal = object->getNormal(intersecP);
					double alpha = std::max(0.0, toLight.getDir() * normal);
					double beta = std::max(0.0, -toLight.getDir() * l->getNormal(ranodmPAtLight.getUnit()));
					double geometric = alpha * beta / toLight.getDir().getLen();

					//Sum up the geometric term for all the shadow rays
					sum += geometric;
				}
			}
			directIllumination += (l->getEmmision()*l->getArea())*sum / NUM_SHADOW_RAYS;
		}
	}
	directIllumination /= (double)numLights;
	return directIllumination;
}


ColorDbl Camera::calculateIndirect(const int depth, const Surface* object, const Vector intersecP, const Ray inRay) const
{
	//TODO! Lambertian reflector

	/*//Indirect illumination
	float absorbtion = 0.5f;

	// Russian roulette
	float r1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float r2 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float absorption = 0.5;

	// Ray is scattered
	if (static_cast <float> (rand()) / static_cast <float> (RAND_MAX) > absorption) {

		// New random direction over hemisphere
		float inclination = 2.0 * M_PI * r1;
		float azimuth = acos(2.0 * r2 - 1.0);
		float u = cos(azimuth);

		float x = sqrt(1 - u * u) * cos(inclination);
		float y = sqrt(1 - u * u) * sin(inclination);
		float z = u;

		// New direction. If it points the wrong way, change direction
		Vector newDir(x, y, z);
		if (normal * newDir < 0) newDir = -newDir;

		// pdf  - over hemisphere
		// cos  - relationship between normal and the direction reflected light will come from
		// BRDF - Lambertian or Oren-Nayar
		float pdf = 1.0 / 2.0 * M_PI;
		float cos = normal * newDir;
		float BRDF = normal * newDir;

		Ray newRay(p, newDir, inRay.getColor());
		depth++;
		indirectIllumination = castRay(room, newRay, depth) * cos * BRDF / pdf;
		indirectIllumination /= ((1 - absorption));
	}
	*/
	return ColorDbl();
}


//TODO! random point on light source
Vector Camera::getRanomPoint(const Vector point, const Surface *light) const
{
	return light->getCenter() - point;
}


//Find the closest intersection point in the vecotr with intersections, return the index to where the closest intersection is in the vector
//Return also the distances and bool to say if first or seciond hit was closest
int Camera::findClosestIntersection(const std::vector<Intersection> &intersections, const Ray ray, double &distance1, double &distance2, bool &hit1) const
{
	int closest = -1;
	double bestDistance = 0.0;
	for (unsigned int i = 0; i < intersections.size(); ++i)
	{
		//Calculate distance
		distance1 = (intersections[i].intersectionpoint1 - ray.getStart()).getLen();
		if (intersections[i].twoIntersections)
			distance2 = (intersections[i].intersectionpoint2 - ray.getStart()).getLen();

		//Compare the distance
		if (bestDistance < EPSILON)
		{
			//If closer then excange to new object
			bool is2Best = intersections[i].twoIntersections && distance2 < distance1;
			bestDistance = is2Best ? distance2 : distance1;
			closest = i;
			hit1 = is2Best ? false : true;
		}
		//Compare the distance to the so far closest object
		else
		{
			//If closer then excange to new object
			if (intersections[i].twoIntersections && distance2 < bestDistance) {
				bestDistance = distance2;
				closest = i;
				hit1 = false;
			}
			else if (distance1 < bestDistance) {
				bestDistance = distance1;
				closest = i;
				hit1 = true;
			}
			//If not then continue 
			else continue;
		}
	}
	return closest;
}