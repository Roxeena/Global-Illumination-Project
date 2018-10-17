#ifndef TNCG15_COLORDBL_H
#define TNCG15_COLORDBL_H

class ColorDbl
{
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

#endif TNCG15_COLORDBL_H //TNCG15_COLORDBL_H