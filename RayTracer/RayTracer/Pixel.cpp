#include "Pixel.h"

Pixel::Pixel()
	: pixelColor(ColorDbl())
{
	pixelRays = new Ray[numRays];
}


Pixel::Pixel(const double red, const double blue, const double green)
	: pixelColor(ColorDbl(red, green, blue))
{
	pixelRays = new Ray[numRays];
}


Pixel::Pixel(const ColorDbl color)
	: pixelColor(color)
{

}


Pixel::~Pixel()
{
	delete[] pixelRays;
}
