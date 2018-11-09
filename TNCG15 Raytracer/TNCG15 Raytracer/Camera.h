#pragma once
#define _USE_MATH_DEFINES	//M_PI
#include <math.h>			//M_PI
#include <array>
#include "Vector.h"
#include "Scene.h"
#include "ColorDbl.h"
#include "Ray.h"
#include "Pixel.h"

const int WIDTH = 200;
const int HEIGHT = 200;
const int MAX_DEPTH = 5;

class Camera
{
public:
	//Constructors and destructor
	Camera(bool camPos1 = true);
	~Camera();

	//Methods
	void setFov(const float inFov);
	void setRPP(const int numRaysPP);

	void createImage(Scene &room, std::string filename = "rayTracedImage.ppm");

private:
	//field of view in radians
	float fov = ((float)M_PI )/ 1.5f;

	//Camera positions
	const Vector POS1 = Vector(-1.0f, 0.0f, 0.0f);
	const Vector POS2 = Vector(-1.0f, 0.0f, 0.0f);
	const Vector LOOKAT = Vector(1.0f, 0.0f, 0.0f);
	bool isPos1;

	//Array of array with pixles
	std::array<std::array<Pixel, WIDTH>, HEIGHT> pixels;
	Ray getRayFromPixelCoords(const double w, const double h);

	//Number of samples per pixle
	int spp = 1;

	//Divide eacxh pixle into a number of sub-pixles
	int subPixels = 2;

	//Methods
	void createPixles();
	double castRays(Scene &room);
	ColorDbl castRay(Scene &room, Ray &ray, int depth = 0);
	void writeToFile(const std::string filename, const double &max);
	Vector getPos() const;
	double randMinMax(const double min, const double max) const;
};

