#include "Vector.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include <string>

Vector::Vector()
	: x(0), y(0), z(0)
{ }


Vector::Vector(const float& X, const float& Y, const float& Z)
	: x(X), y(Y), z(Z)
{ }


Vector::~Vector()
{ }


const float& Vector::getX() const {
	return x;
}


void Vector::setX(const float& newX) {
	x = newX;
}


const float& Vector::getY() const  {
	return y;
}


void Vector::setY(const float& newY) {
	y = newY;
}


const float& Vector::getZ() const {
	return z;
}


void Vector::setZ(const float& newZ) {
	z = newZ;
}


void Vector::get(float& X, float& Y, float& Z) const
{
	X = x;
	Y = y;
	Z = z;
}


void Vector::set(const float& X, const float& Y, const float& Z)
{
	x = X;
	y = Y;
	z = Z;
}


const Vector Vector::operator+ (const Vector& other) const
{
	return Vector(x + other.x, y + other.y, z + other.z);
}


Vector& Vector::operator+= (const Vector& other)
{
	return *this = *this + other;
}


const Vector Vector::operator- () const
{
	return Vector(-x, -y, -z);
}


const Vector Vector::operator- (const Vector& other) const
{
	return Vector(x - other.x, y - other.y, z - other.z);
}


Vector& Vector::operator-= (const Vector& other)
{
	return *this = *this - other;
}


const Vector Vector::operator* (const float& scalar) const
{
	return Vector(x*scalar, y*scalar, z*scalar);
}


Vector& Vector::operator*= (const float& scalar)
{
	return *this = *this * scalar;
}


const Vector Vector::operator/ (const float& scalar) const
{
	return Vector(x / scalar, y / scalar, z / scalar);
}


Vector& Vector::operator/= (const float& scalar)
{
	return *this = *this / scalar;
}


const float Vector::operator* (const Vector& other) const
{
	return x * other.x + y * other.y + z * other.z;
}


const Vector Vector::operator% (const Vector& other) const
{
	return Vector(y*other.z - z * other.y,
		z*other.x - x * other.z,
		x*other.y - y * other.x);
}


Vector& Vector::operator%= (const Vector& other)
{
	return *this = *this % other;
}


const float Vector::getSqrLen() const
{
	return x * x + y * y + z * z;
}


const float Vector::getLen() const
{
	return std::sqrt(getSqrLen());
}


const Vector Vector::getUnit() const
{
	if (getSqrLen() != 0)
		return *this / getLen();

	return *this;
}


void Vector::normalize()
{
	*this = this->getUnit();
}


const Vector Vector::getInterpolation(const Vector& other, const float& ratio) const
{
	return *this + (other - *this)*ratio;
}


const Vector Vector::getReflection(const Vector& surfaceNormal) const
{
	return *this - surfaceNormal * ((*this * surfaceNormal) * 2);
}


std::string Vector::toString() const
{
	return ( "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")" );
}


bool Vector::operator==(const Vector &rhs) const
{
	return (x == rhs.getX() && y == rhs.getY() && z == rhs.getZ());
}


bool Vector::operator!=(const Vector &rhs) const
{
	return !(*this == rhs);
}