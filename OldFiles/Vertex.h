#pragma once
#include "Vector.h"

class Vertex
{
public:
	//Constructors and destructor
	Vertex();
	Vertex(const Vector in);	//TODO: Compiler does not recognise Vector
	Vertex(const float inX, const float inY, const float inZ, const float inW = 1);
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

