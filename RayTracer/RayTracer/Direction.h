#pragma once
class Direction
{
public:
public:
	//Constructors and destructor
	Direction();
	Direction(const float inX, const float inY, const float inZ);
	~Direction();
	//Methods
	void setDirection(const float inX, const float inY, const float inZ);
	const float& getX() const;
	void setX(const float& newX);

	const float& getY() const;
	void setY(const float& newY);

	const float& getZ() const;
	void setZ(const float& newZ);

private:
	float x, y, z;
};

