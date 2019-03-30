#pragma once
#include "Surface.h"
#include "Vector.h"
#include "ColorDbl.h"

class Sphere :
	public Surface
{
public:
	//Constructors and destructor
	Sphere(const Vector inCenter, const float r, const ColorDbl sphereColor);
	virtual ~Sphere();

	//Inherited methods
	const Vector getNormal(const Vector pos) const override;
	bool intersects(const Vector rayOrgin, const Vector rayDir, Vector &intersectionPoint1, Vector &intersectionPoint2) const override;
	ColorDbl getColor() const override;
	void setColor(const ColorDbl newColor) override;
	Vector getCenter() const override;
	double getArea() const override;

	//Methods
	float getRadius() const;

private:
	Vector center;
	float radius;
	ColorDbl color;
};