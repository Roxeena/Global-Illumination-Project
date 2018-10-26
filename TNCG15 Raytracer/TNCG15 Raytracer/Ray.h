#include "Vector.h"
#include "ColorDbl.h"
#pragma once

class Ray
{
public:
	//Constructors and destructor
	Ray();
	Ray(const Vector orgin, const Vector dir, const ColorDbl rayColor);
	~Ray();

	//Methods
	const Vector getStart() const;
	const Vector getDir() const;
	const ColorDbl getColor() const;

	void setRay(const Vector orgin, const Vector dir, const ColorDbl rayColor);
	void setStart(const Vector orgin);
	void setDir(const Vector dir);
	void setColor(const ColorDbl rayColor);

private:
	Vector start, direction;
	ColorDbl color;
};

