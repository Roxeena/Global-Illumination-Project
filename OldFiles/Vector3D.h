#ifndef TNCG15_VECTOR3D_H
#define TNCG15_VECTOR3D_H

#include <cstddef>

class Vector3D
{
private:
	float X;
	float Y;
	float Z;

public:
	//Constructors and destructors
	//! Sets all members to zero
	Vector3D();

	Vector3D(const float& x, const float& y, const float& z);

	Vector3D(const float coords[3]);

	Vector3D(const Vertex in);

	// Get-Set methods
	const float& getX() const;
	void setX(const float& newX);

	const float& getY() const;
	void setY(const float& newY);

	const float& getZ() const;
	void setZ(const float& newZ);

	void getv(float buffer[3]) const;
	void setv(const float coords[3]);

	void get(float& x, float& y, float& z) const;
	void set(const float& x, const float& y, const float& z);

	// Interface for indexing
	const float& operator[] (size_t index) const;
	float& operator[] (size_t index);

	//! Considering vectors as matrices with one row
	const float& operator() (size_t column) const;
	float& operator() (size_t column);

	// Standard operations
	//! This does absolutely nothing, but it should be included for consistency
	const Vector3D operator+ () const;

	const Vector3D operator+ (const Vector3D& other) const;
	Vector3D& operator+= (const Vector3D& other);

	//! The same as multiplying *this by -1
	const Vector3D operator- () const;

	const Vector3D operator- (const Vector3D& other) const;
	Vector3D& operator-= (const Vector3D& other);

	//! Multiplying *this by a scalar
	const Vector3D operator* (const float& scalar) const;
	Vector3D& operator*= (const float& scalar);

	//! Same as multiplication by 1/scalar, maybe more accurate but also slower
	const Vector3D operator/ (const float& scalar) const;
	Vector3D& operator/= (const float& scalar);

	//! Calculate the dot/inner/scalar product
	const float operator* (const Vector3D& other) const;

	//! Calculate the cross/outer/vector product
	const Vector3D operator% (const Vector3D& other) const;
	Vector3D& operator%= (const Vector3D& other);

	// Auxiliary methods
	//! Returns the squared length of *this
	const float getSqrLen() const;
	//! Returns the length of *this
	const float getLen() const;

	//! Returns a vector with the same orientation, but with a length of 1
	const Vector3D getUnit() const;

	//! Interpolates *this between another vector, by a ratio
	const Vector3D getInterpolation(const Vector3D& other, const float& ratio) const;

	//! Reflects *this according to a surface's normal
	const Vector3D getReflection(const Vector3D& surfaceNormal) const;
};
#endif //TNCG15_VECTOR3D_H