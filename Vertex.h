#include "Vector3D.h";

class Vertex
{
public:
	Vertex();
	Vertex(const float inX, const float inY, const float inZ, const float inW = 1);
	Vertex(const Vector3D in);
	~Vertex();

	//Methods
	void setVertex(const float inX, const float inY, const float inZ, const float inW = 1);
	float getX() const;
	float getY() const;
	float getZ() const;
	float getW() const;

private:
	float x, y, z, w;
};
