#pragma once
#include <iostream>
#include <string>

const double MIN = 0.0;
const double MAX = 1.0;

class ColorDbl
{
public:
	//Constructors and destructor
	ColorDbl();
	ColorDbl(const double red, const double green, const double blue);
	~ColorDbl();

	//Methods
	double getRed() const;
	double getGreen() const;
	double getBlue() const;
	void setColor(const double red, const double green, const double blue);
	std::string toString() const;

	//Operators
	ColorDbl& operator=(const ColorDbl rhs);
	const ColorDbl operator+ (const ColorDbl &other) const;
	ColorDbl& operator+= (const ColorDbl& other);
	const ColorDbl operator/ (const double &other) const;
	ColorDbl& operator/= (const double other);
	const ColorDbl operator* (const double &other) const;
	ColorDbl& operator*= (const double other);

private:
	double R, G, B;
};