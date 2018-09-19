class ColorDbl
{
public:
	ColorDbl();
	ColorDbl(const double red, const double green, const double blue);
	~ColorDbl();

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

ColorDbl::~ColorDbl()
{
}