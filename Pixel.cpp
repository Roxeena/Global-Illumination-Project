#include "Pixel.h"
#include "ColorDbl.h";
#include "Ray.h";


Pixel::Pixel()
	: pixelColor(ColorDbl())
{
}

Pixel::Pixel(const double red, const double blue, const double green)
	: pixelColor(ColorDbl(red, green, blue))
{

}

Pixel::Pixel(const ColorDbl color)
	: pixelColor(color)
{

}

Pixel::~Pixel()
{
	delete[] pixelRays;
}