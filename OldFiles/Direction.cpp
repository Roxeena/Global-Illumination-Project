#include "Direction.h"

Direction::Direction()
	: x(0.0), y(0.0), z(0.0)
{
}

Direction::Direction(const float inX, const float inY, const float inZ)
	: x(inX), y(inY), z(inZ)
{
}

void Direction::setDirection(const float inX, const float inY, const float inZ)
{
	x = inX;
	y = inY;
	z = inZ;
}

Direction::~Direction()
{
}