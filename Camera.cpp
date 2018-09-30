#include "Camera.h"
#include "Vertex.h";
#include "Pixel.h";


Camera::Camera(const Vertex &position1, const Vertex &position2, const bool inPos1 = true, const int inWidth = 800, const int inHeight = 800)
	: pos1(position1), pos2(position2), isPos1(inPos1), width(inWidth), height(inHeight)
{
	pixels = new Pixel[width*height];
}

Camera::~Camera()
{
	delete[] pixels;
}