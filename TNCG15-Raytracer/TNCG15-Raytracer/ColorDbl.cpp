#include "ColorDbl.h"
#include <algorithm>

ColorDbl::ColorDbl()
	: R(MIN), G(MIN), B(MIN)
{ }


ColorDbl::ColorDbl(const double red, const double green, const double blue)
{
	// make sure r, g and b is within the range [MIN, MAX]
	R = red;
	G = green;
	B = blue;
}


double ColorDbl::getRed() const { return R; }
double ColorDbl::getGreen() const { return G; }
double ColorDbl::getBlue() const { return B; }

void ColorDbl::setColor(const double red, const double green, const double blue)
{
	// make sure r, g and b is within the range [MIN, MAX]
	R = std::max(std::min(red, MAX), MIN);
	G = std::max(std::min(green, MAX), MIN);
	B = std::max(std::min(blue, MAX), MIN);
}


std::string ColorDbl::toString() const {
	return "R: " + std::to_string(R) + " G: " + std::to_string(G) + " B: " + std::to_string(B);
}


ColorDbl& ColorDbl::operator=(const ColorDbl rhs)
{
	R = rhs.getRed();
	G = rhs.getGreen();
	B = rhs.getBlue();
	return *this;
}


const ColorDbl ColorDbl::operator+ (const ColorDbl &other) const
{
	// make sure r, g and b is within the range [MIN, MAX]
	double newRed = R + other.R;
	double newGreen = G + other.G;
	double newBlue = B + other.B;

	return ColorDbl(newRed, newGreen, newBlue);
}


ColorDbl& ColorDbl::operator+= (const ColorDbl& other)
{
	return *this = *this + other;
}


const ColorDbl ColorDbl::operator/ (const double &other) const
{
	return ColorDbl(R / other, G / other, B / other);
}


ColorDbl& ColorDbl::operator/= (const double other)
{
	return *this = *this / other;
}


const ColorDbl ColorDbl::operator* (const double &other) const
{
	return ColorDbl(R*other, G*other, B*other);
}


ColorDbl& ColorDbl::operator*= (const double other)
{
	return *this = *this * other;
}


ColorDbl::~ColorDbl()
{
}
