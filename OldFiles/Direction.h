#pragma once
class Direction
{
public:
	//Constructors and destructor
	Direction();
	Direction(const float inX, const float inY, const float inZ);
	~Direction();
	//Methods
	void setDirection(const float inX, const float inY, const float inZ);

private:
	float x, y, z;
};

