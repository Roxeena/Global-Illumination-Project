#pragma once
#include "ColorDbl.h"
#include "Ray.h"
#include <vector>
class Pixel
{
public:
	//Constructors and destructor
	Pixel();
	Pixel(const ColorDbl pixelColor);
	~Pixel();

	//Methods
	Ray* getFirstRay();
	const Ray*const getFirstRay() const;
	const std::vector<Ray>& getRayList() const;
	void addRay(Ray &r);
	void setColor(const ColorDbl pixelColor);
	ColorDbl getColor() const;


private:
	std::vector<Ray> rays;
	ColorDbl color;
};

