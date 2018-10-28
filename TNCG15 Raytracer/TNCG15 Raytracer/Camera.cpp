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
	
}


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
	Ray ray(pos, (LOOKAT + diff), ColorDbl());
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


void Camera::createPixles()
{
	for (int h = 0; h < HEIGHT; ++h) {
		for (int w = 0; w < WIDTH; ++w) {
			Pixel p = Pixel();

			float diff = 1.0f / subPixels;
			for (int subX = 0; subX < subPixels; ++subX) {
				for (int subY = 0; subY < subPixels; ++subY) {
					double x = randMinMax(w + subX * diff, w + (subX + 1) * diff);
					double y = randMinMax(h + subY * diff, h + (subY + 1) * diff);
					Ray r = getRayFromPixelCoords(x, y);
					p.addRay(r);
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
			// pring progress (use one of the two lines)
			std::cout << "\r" << progress << "%";
			//            std::cout << std::setprecision(5) << progress << "%" << std::endl;

			// cast ray for this pixel
			ColorDbl clr = ColorDbl();
			std::vector<Ray> rays = pixel.getRayList();

			if (rays.empty())
				std::cout << "No Rays!" << std::endl;

			for (Ray r : rays) {
				for (int i = 0; i < spp; ++i) {
					clr += castRay(room, r);
				}
			}
			clr /= (double)(spp * subPixels * subPixels);
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
	//Get intersecting triangles and object in scene
	std::vector<Intersection> intersections;
	room.detectIntersections(ray, intersections);

	ColorDbl resultingColor = ColorDbl();

	//Check if there were any intersections
	if (intersections.size() > 0)
	{
		//std::cout << "Found intersections!" << std::endl;
		int closest = -1;
		bool hit1 = true;
		float distance1, distance2, bestDistance = 0.0f;

		//Find the closest intersection, direct hit.
		for (unsigned int i = 0; i < intersections.size(); ++i)
		{
			//Calculate distance
			distance1 = (intersections[i].intersectionpoint1 - ray.getStart()).getLen();
			if(intersections[i].twoIntersections)
				distance2 = (ray.getStart() - intersections[i].intersectionpoint2).getLen();

			//Compare the distance to the so far closest object
			if (bestDistance < EPSILON)
			{
				//If closer then excange to new object
				if (intersections[i].twoIntersections && distance2 < distance1) {
					bestDistance = distance2;
					closest = i;
					hit1 = false;
				}
				else {
					bestDistance = distance1;
					closest = i;
					hit1 = true;
				}
			}
			else
			{
				//If closer the excange to new object
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
				else
					continue;
			}
		}

		//We have found the closest object
		if (closest != -1) {
			//std::cout << "Found closest intersection!" << std::endl;
			//If it is a light source return light color
			if (intersections[closest].object->isLight()) {
				//std::cout << "Found Light Source!" << std::endl;
				return intersections[closest].object->getColor();
			}

			Vector point;
			if (hit1)
				point = intersections[closest].intersectionpoint1;
			else
				point = intersections[closest].intersectionpoint2;

			Vector normal = intersections[closest].object->getNormal(point);
			Vector flip = -(ray.getDir().getUnit());
			Vector outDir = flip.getReflection(normal);
			ColorDbl indirectIllumination = ColorDbl();
			ColorDbl directIllumination = ColorDbl();

			//Otherwise calculate outgoing color
			//Depending on the material
			if (intersections[closest].object->isPerfect()) {
				//resultingColor = intersections[closest].object->getColor();
				//TODO! Perfect reflector
				//Follow light around scene and return the color of the ray coming back
				//Metallic object
			}
			else if(depth < MAX_DEPTH) {
				//TODO! Lambertian reflector

				/*Indirect illumination*/
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

					Ray newRay(p, newDir, ray.getColor());
					depth++;
					indirectIllumination = castRay(room, newRay, depth) * cos * BRDF / pdf;
					indirectIllumination /= ((1 - absorption));
				}

				/*Direct illumination*/

				int shadowRays = 4;
				std::vector<Surface*> objects = room.getObjects();
				for (int i = 0; i < objects.size(); i++) {
					if (objects.at(i)->isLight()) {
						Surface *l = objects.at(i); // Pointer to current light
						ColorDbl tempColor(); // Total color per light
						float unobstructedRays = 0.0;

						for (int j = 0; j < shadowRays; j++) {
							bool shaded = false;
							Vector pDir = findLightDirection(p, l); // Vector towards light
							float dist = pDir.getLen();
							pDir = pDir.getUnit();

							// Shoot shadow ray(s) to random position on light (not random now though)
							for (auto &o : objects)
								Vector inSecPoint1(), inSecPoint2();
								if (o.intersects(p, pDir, inSecPoint1, inSecPoint2))
									if (inSecPoint1 < dist && !o->isLight())
										shaded = true;

							if (!shaded) {
								unobstructedRays++;
								float lightIntensity = 2.2 * 1.0 / 255.0;
								float BRDF = normal * pDir;
								// TODO: N(light) must be calculated properly
								// radianceTransfer = dot(N(object), shadowRay) * dot(N(light), -shadowRay)
								float radianceTransfer = (normal * pDir) * (-pDir * -pDir);
								float pdfk = 2.0 * M_PI * l->getRadius() * l->getRadius(); // pdf over sphere (lights are halved spheres)
								float pdfyk = 0.5; // Chance to pick one of the light sources

								// Direct illumination = light * BRDF * radiance transfer / pdfk * pdfyk
								tempColor += l->color * lightIntensity * BRDF * radianceTransfer / (pdfk * pdfyk) * s->color;
							}
						}
					}

					directIllumination += tempColor * (1.0f / (float)shadowRays);
				}
			}

			resultingColor = (indirectIllumination * 2.0 + directIllumination / M_PI);
			//std::cout << "Setting resulting Color to: " << intersections[closest].object->getColor().toString() << std::endl;
			//Bounce the ray
			/*Vector temp = -(ray.getDir().getUnit());
			Vector point;
			if(hit1)
				point = intersections[closest].intersectionpoint1;
			else
				point = intersections[closest].intersectionpoint2;

			Vector normal = intersections[closest].object->getNormal(point);

			Vector outDir = temp.getReflection(normal);
			Ray out = Ray(point, outDir, resultingColor);
			*/

			//TODO!
			//Do over with the new outgoing ray

			//Decide if we should terminate the ray or not
			//Russian roulette
		}
		else {
			std::cout << "Could not find the closest hit!" << std::endl;
		}
		
	}
	//If no intersections ther ray missed! should not be possible
	else {
		//std::cout << "Ray from: " << ray.getStart().toString() << " with direction: " << ray.getDir().toString() << " MISSED!" << std::endl;
	}

	//std::cout << "Resulting Color: " << resultingColor.toString() << std::endl;
	return resultingColor;
}

//TODO!
void Camera::writeToFile(const std::string filename, const double &max)
{
	std::cout << std::endl << std::endl << "Writing image... (Max: " << max << ")" << std::endl;

	FILE *fp = fopen(filename.c_str(), "w"); /* b - binary mode */
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