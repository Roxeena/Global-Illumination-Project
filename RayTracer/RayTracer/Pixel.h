#pragma once
#include "ColorDbl.h"
#include "Ray.h"
class Pixel
{
public:
	//Constructors and destructor
	Pixel();
	Pixel(const double red, const double blue, const double green);
	Pixel(const ColorDbl color);
	~Pixel();

private:
	ColorDbl pixelColor;	//Color of the pixel
	Ray *pixelRays;			//The rays that flow through this pixel
	const unsigned int numRays = 1;	//How many rays that flow through this pixel
};

