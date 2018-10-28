#pragma once
#include "Vector.h"
#include "ColorDbl.h"

const double EPSILON = 0.0000001;

class Surface
{
public:
	//Destructor
	virtual ~Surface();

	//Pure virtual methods
	virtual const Vector getNormal(const Vector pos) = 0;
	virtual bool intersects(const Vector rayOrgin, const Vector rayDir, Vector &intersectionPoint1, Vector &intersectionPoint2) const = 0;
	virtual ColorDbl getColor() const = 0;
	virtual void setColor(const ColorDbl newColor) = 0;

	//Methods
	void setLight(const bool isLight);
	void setPerfect(const bool isRefractive);
	bool isLight() const;
	bool isPerfect() const;
	

private: 
	bool light = false;
	bool perfect = false;
};

