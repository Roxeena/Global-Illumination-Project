#pragma once
class ColorDbl
{
public:
public:
	//Constructors and destructor
	ColorDbl();
	ColorDbl(const double red, const double green, const double blue);
	~ColorDbl();

	//Methods
	void setColorDbl(const double red, const double green, const double blue);

private:
	double r, g, b;
};

