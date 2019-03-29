#pragma once
#include <iostream>

class Vector
{
public:
	/*Constructors and destructor*/
	Vector();
	Vector(const double& x, const double& y, const double& z);
	~Vector();

	/*Get-Set methods*/
	const double& getX() const;
	void setX(const double& newX);

	const double& getY() const;
	void setY(const double& newY);

	const double& getZ() const;
	void setZ(const double& newZ);

	void get(double& x, double& y, double& z) const;
	void set(const double& x, const double& y, const double& z);

	/*Standard operations*/
	const Vector operator+ (const Vector& other) const;
	Vector& operator+= (const Vector& other);

	//The same as multiplying *this by -1
	const Vector operator- () const;

	const Vector operator- (const Vector& other) const;
	Vector& operator-= (const Vector& other);

	//Multiplying *this by a scalar
	const Vector operator* (const double& scalar) const;
	Vector& operator*= (const double& scalar);

	//Same as multiplication by 1/scalar
	const Vector operator/ (const double& scalar) const;
	Vector& operator/= (const double& scalar);

	//Calculate the scalarproduct
	const double operator* (const Vector& other) const;

	//Calculate the crossproduct
	const Vector operator% (const Vector& other) const;
	Vector& operator%= (const Vector& other);

	/*Auxiliary methods*/
	//Returns the squared length of *this
	const double getSqrLen() const;
	//Returns the length of *this
	const double getLen() const;

	//Returns a vector with the same orientation, but normalized
	const Vector getUnit() const;
	//Normalizes *this
	void normalize();

	//Interpolates *this between another vector, by a ratio
	const Vector getInterpolation(const Vector& other, const double& ratio) const;

	//Reflects *this according to a surface's normal
	const Vector getReflection(const Vector& surfaceNormal) const;

	/*To String*/
	std::string toString() const;

	/*Comparison operators*/
	bool operator==(const Vector &rhs) const;
	bool operator!=(const Vector &rhs) const;


private:
	double x;
	double y;
	double z;
};