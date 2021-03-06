#pragma once
#include "Surface.h"
#include "Vector"

const int THREE = 3;

class Triangle :
	public Surface
{
public:
	//Constructors and destructor
	Triangle();
	Triangle(Vector *A, Vector *B, Vector *C, const ColorDbl triangleColor);
	virtual ~Triangle();

	//Inherited methods
	const Vector getNormal(const Vector pos) const override;
	bool intersects(const Vector rayOrgin, const Vector rayDir, Vector &intersectionPoint1, Vector &intersectionPoint2) const override;
	ColorDbl getColor() const override;
	void setColor(const ColorDbl newColor) override;
	Vector getCenter() const override;
	double getArea() const override;

	//Methods
	void set(Vector *A, Vector *B, Vector *C, const ColorDbl triangleColor);
	void set(Vector *A, Vector *B, Vector *C, const Vector inNormal, const ColorDbl triangleColor);

private:
	ColorDbl color;
	Vector normal;
	Vector *vertices[THREE];

	Vector edge1() const;
	Vector edge2() const;
};