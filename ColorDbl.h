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

ColorDbl::ColorDbl()
	: r(0.0), g(0.0), b(0.0)
{
}

ColorDbl::ColorDbl(const double red, const double green, const double blue)
	: r(red), g(green), b(blue)
{
}

void ColorDbl::setColorDbl(const double red, const double green, const double blue)
{
	r = red;
	g = green;
	b = blue;
}

ColorDbl::~ColorDbl()
{
}