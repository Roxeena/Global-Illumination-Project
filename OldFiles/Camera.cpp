#include "Camera.h"
#include "Vertex.h"
#include "Pixel.h"


Camera::Camera(const Vertex &position1, const Vertex &position2, const bool inPos1 = true, const int inWidth = 800, const int inHeight = 800)
	: pos1(position1), pos2(position2), isPos1(inPos1), width(inWidth), height(inHeight)
{
	pixels = new Pixel[width*height];
}


void Camera::render()
{
	if (isPos1)
	{
		//TO DO: Render scene into pixles from pos1
		for (int i = 0; i < (width*height); ++i)
		{
			//Create a ray through this pixel onto the scene
		}
	}
	else
	{
		//TO DO: Render scene into pixles from pos2
		for (int i = 0; i < (width*height); ++i)
		{
			//Create a ray through this pixel onto the scene
		}
	}
}	


void Camera::switchPosition()
{
	isPos1 = !isPos1;
}


void Camera::createImage() const
{
	//TO DO: Convert the 2D info in pixles (after rendering) to a image
}


Camera::~Camera()
{
	delete[] pixels;
}