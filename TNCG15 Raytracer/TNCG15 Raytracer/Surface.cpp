#include "Surface.h"

Surface::~Surface()
{
}


void Surface::setLight(const bool isLight) { light = isLight; }
void Surface::setPerfect(const bool isRefractive) { perfect = isRefractive; }
bool Surface::isLight() const { return light; }
bool Surface::isPerfect() const { return perfect; }