#include "Vector3D.h"
#include "Vertex.h"
#define _USE_MATH_DEFINES;
#include <cmath>
#include <math.h>

 Vector3D::Vector3D()
	: X(0), Y(0), Z(0)
{}


 Vector3D::Vector3D(const float& x, const float& y, const float& z)
	: X(x), Y(y), Z(z)
{}


 Vector3D::Vector3D(const float coords[3])
	: X(coords[0]), Y(coords[1]), Z(coords[2])
{}


 Vector3D::Vector3D(const Vertex in)
	 : X(in.getX()), Y(in.getY()), Z(in.getZ())
{}


 const float& Vector3D::getX() const
{
	return X;
}


 void Vector3D::setX(const float& newX)
{
	X = newX;
}


 const float& Vector3D::getY() const
{
	return Y;
}


 void Vector3D::setY(const float& newY)
{
	Y = newY;
}


 const float& Vector3D::getZ() const
{
	return Z;
}


 void Vector3D::setZ(const float& newZ)
{
	Z = newZ;
}


 void Vector3D::getv(float buffer[3]) const
{
	buffer[0] = X;
	buffer[1] = Y;
	buffer[2] = Z;
}


 void Vector3D::setv(const float coords[3])
{
	X = coords[0];
	Y = coords[1];
	Z = coords[2];
}


 void Vector3D::get(float& x, float& y, float& z) const
{
	x = X;
	y = Y;
	z = Z;
}


 void Vector3D::set(const float& x, const float& y, const float& z)
{
	X = x;
	Y = y;
	Z = z;
}


 const float& Vector3D::operator[] (size_t index) const
{
	switch (index)
	{
	case 0:
		return X;
	case 1:
		return Y;
	case 2:
		return Z;
	}

	return float();
}


 float& Vector3D::operator[] (size_t index)
{
	switch (index)
	{
	case 0:
		return X;
	case 1:
		return Y;
	case 2:
		return Z;
	default:
		return X;
	}
}


 const float& Vector3D::operator() (size_t column) const
{
	switch (column)
	{
	case 1:
		return X;
	case 2:
		return Y;
	case 3:
		return Z;
	}

	return float();
}


 float& Vector3D::operator() (size_t column)
{
	switch (column)
	{
	case 1:
		return X;
	case 2:
		return Y;
	case 3:
		return Z;
	default:
		return X;
	}
}


 const Vector3D Vector3D::operator+ () const
{
	return *this;
}


 const Vector3D Vector3D::operator+ (const Vector3D& other) const
{
	return Vector3D(X + other.X, Y + other.Y, Z + other.Z);
}


 Vector3D& Vector3D::operator+= (const Vector3D& other)
{
	return *this = *this + other;
}


 const Vector3D Vector3D::operator- () const
{
	return Vector3D(-X, -Y, -Z);
}


 const Vector3D Vector3D::operator- (const Vector3D& other) const
{
	return Vector3D(X - other.X, Y - other.Y, Z - other.Z);
}


 Vector3D& Vector3D::operator-= (const Vector3D& other)
{
	return *this = *this - other;
}


 const Vector3D Vector3D::operator* (const float& scalar) const
{
	return Vector3D(X*scalar, Y*scalar, Z*scalar);
}


 Vector3D& Vector3D::operator*= (const float& scalar)
{
	return *this = *this * scalar;
}


 const Vector3D Vector3D::operator/ (const float& scalar) const
{
	return Vector3D(X / scalar, Y / scalar, Z / scalar);
}


 Vector3D& Vector3D::operator/= (const float& scalar)
{
	return *this = *this / scalar;
}


 const float Vector3D::operator* (const Vector3D& other) const
{
	return X * other.X + Y * other.Y + Z * other.Z;
}


 const Vector3D Vector3D::operator% (const Vector3D& other) const
{
	return Vector3D(Y*other.Z - Z * other.Y,
		Z*other.X - X * other.Z,
		X*other.Y - Y * other.X);
}


 Vector3D& Vector3D::operator%= (const Vector3D& other)
{
	return *this = *this % other;
}


 const float Vector3D::getSqrLen() const
{
	return X * X + Y * Y + Z * Z;
}


 const float Vector3D::getLen() const
{
	return std::sqrt(getSqrLen());
}


 const Vector3D Vector3D::getUnit() const
{
	if (getSqrLen() != 0)
		return *this / getLen();

	return *this;
}


 const Vector3D Vector3D::getInterpolation(const Vector3D& other, const float& ratio) const
{
	return *this + (other - *this)*ratio;
}


 const Vector3D Vector3D::getReflection(const Vector3D& surfaceNormal) const
{
	return *this - surfaceNormal * ((*this * surfaceNormal) * 2);
}