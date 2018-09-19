class Direction
{
public:
	Direction(const float inX, const float inY, const float inZ);
	~Direction();

private:
	float x, y, z;
};

Direction::Direction(const float inX, const, float inY, const float inZ)
	: x(inX), y(inY), z(inZ)
{
}

Direction::~Direction()
{
}