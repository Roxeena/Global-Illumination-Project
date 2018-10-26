#include "Pixel.h"
#include <iostream>


Pixel::Pixel()
	: color(ColorDbl())
{ }


Pixel::Pixel(const ColorDbl pixelColor)
	: color(pixelColor)
{ }


Pixel::~Pixel()
{
}


Ray* Pixel::getFirstRay()
{
	if(!rays.empty())
		return &rays.at(0);
	else
	{
		std::cout << "Rays is empty!" << std::endl;
		return nullptr;
	}
}


const Ray*const Pixel::getFirstRay() const
{
	if (!rays.empty())
		return &rays.at(0);
	else
	{
		std::cout << "Rays is empty!" << std::endl;
		return nullptr;
	}
}


const std::vector<Ray>& Pixel::getRayList() const { return rays; }


void Pixel::addRay(Ray &r) {
	rays.push_back(r);
}


void Pixel::setColor(const ColorDbl pixelColor)
{
	color = pixelColor;
}


ColorDbl Pixel::getColor() const { return color; }