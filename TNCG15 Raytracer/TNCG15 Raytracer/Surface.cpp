#include "Surface.h"

Surface::~Surface()
{
}


void Surface::setLight(const bool isLight) { light = isLight; }
void Surface::setPerfect(const bool isRefractive) { perfect = isRefractive; }
bool Surface::isLight() const { return light; }
bool Surface::isPerfect() const { return perfect; }
ColorDbl Surface::getEmmision() const 
{ 
	if(light)
		return ColorDbl(1.0, 1.0, 1.0)*L0; 

	std::cout << "Not a light source, no Emision!" << std::endl;
	return ColorDbl();
}


double Surface::getL0() const 
{ 
	if(light)
		return L0;

	std::cout << "Not a light source! No L0!" << std::endl;
	return 0.0;
}


void Surface::setL0(const double newL0) 
{ 
	if(light)
		L0 = newL0; 
	else {
		std::cout << "Not a light source! Cannot have L0!" << std::endl;
		L0 = 0.0;
	}
}