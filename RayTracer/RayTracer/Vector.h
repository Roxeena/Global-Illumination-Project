#pragma once
#include "Vertex.h"
#include <cstddef>

class Vector
{
public:
public:
	/*Constructors and destructor*/
	Vector();
	Vector(const float& x, const float& y, const float& z);
	~Vector();

	/*Get-Set methods*/
	const float& getX() const;
	void setX(const float& newX);

	const float& getY() const;
	void setY(const float& newY);

	const float& getZ() const;
	void setZ(const float& newZ);

	void get(float& x, float& y, float& z) const;
	void set(const float& x, const float& y, const float& z);

	/*Standard operations*/
	const Vector operator+ (const Vector& other) const;
	Vector& operator+= (const Vector& other);

	//The same as multiplying *this by -1
	const Vector operator- () const;

	const Vector operator- (const Vector& other) const;
	Vector& operator-= (const Vector& other);

	//Multiplying *this by a scalar
	const Vector operator* (const float& scalar) const;
	Vector& operator*= (const float& scalar);

	//Same as multiplication by 1/scalar
	const Vector operator/ (const float& scalar) const;
	Vector& operator/= (const float& scalar);

	//Calculate the scalarproduct
	const float operator* (const Vector& other) const;

	//Calculate the crossproduct
	const Vector operator% (const Vector& other) const;
	Vector& operator%= (const Vector& other);

	/*Auxiliary methods*/
	//Returns the squared length of *this
	const float getSqrLen() const;
	//Returns the length of *this
	const float getLen() const;

	//Returns a vector with the same orientation, but normalized
	const Vector getUnit() const;
	//Normalizes *this
	void normalize();

	//Interpolates *this between another vector, by a ratio
	const Vector getInterpolation(const Vector& other, const float& ratio) const;

	//Reflects *this according to a surface's normal
	const Vector getReflection(const Vector& surfaceNormal) const;

private:
	float x;
	float y;
	float z;
};

