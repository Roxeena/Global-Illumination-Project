#define VECTOR3D_H
#include <cstddef>


template<typename T>
class vector3d
{
private:
	T X;
	T Y;
	T Z;

public:
	//! Sets all members to zero
	vector3d();

	//! Explicitly converts from one type to another
	template<typename R>
	explicit vector3d(const vector3d<R>& other);

	vector3d(const T& x, const T& y, const T& z);

	vector3d(const T coords[3]);

	// Get-Set methods

	const T& getX() const;
	void setX(const T& newX);

	const T& getY() const;
	void setY(const T& newY);

	const T& getZ() const;
	void setZ(const T& newZ);

	void getv(T buffer[3]) const;
	void setv(const T coords[3]);

	void get(T& x, T& y, T& z) const;
	void set(const T& x, const T& y, const T& z);

	// Interface for indexing

	const T& operator[] (size_t index) const;
	T& operator[] (size_t index);

	//! Considering vectors as matrices with one row
	const T& operator() (size_t column) const;
	T& operator() (size_t column);

	// Standard operations

	//! This does absolutely nothing, but it should be included for consistency
	const vector3d operator+ () const;

	const vector3d operator+ (const vector3d& other) const;
	vector3d& operator+= (const vector3d& other);

	//! The same as multiplying *this by -1
	const vector3d operator- () const;

	const vector3d operator- (const vector3d& other) const;
	vector3d& operator-= (const vector3d& other);

	//! Multiplying *this by a scalar
	const vector3d operator* (const T& scalar) const;
	vector3d& operator*= (const T& scalar);

	//! Same as multiplication by 1/scalar, maybe more accurate but also slower
	const vector3d operator/ (const T& scalar) const;
	vector3d& operator/= (const T& scalar);

	//! Calculate the dot/inner/scalar product
	const T operator* (const vector3d& other) const;

	//! Calculate the cross/outer/vector product
	const vector3d operator% (const vector3d& other) const;
	vector3d& operator%= (const vector3d& other);

	// Auxiliary methods

	//! Returns the squared length of *this
	const T getSqrLen() const;
	//! Returns the length of *this
	const T getLen() const;

	//! Returns a vector with the same orientation, but with a length of 1
	const vector3d getUnit() const;

	//! Interpolates *this between another vector, by a ratio
	const vector3d getInterpolation(const vector3d& other, const T& ratio) const;

	//! Reflects *this according to a surface's normal
	const vector3d getReflection(const vector3d& surfaceNormal) const;

	//! Rotates *this about an origin, using Euler angles( X=pitch, Y=yaw, Z=roll)
	const vector3d getRotationEuler(const vector3d& angles,
		const vector3d& origin = vector3d(), bool degs = true) const;

	//! Rotates *this about an origin, using an arbitrary axis( axis should be a unit vector )
	const vector3d getRotationArbAxis(const vector3d& axis, const T& amount,
		const vector3d& origin = vector3d(), bool degs = true) const;
};
