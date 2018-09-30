#include "Vertex.h";
#include "Pixel.h";

class Camera
{
public:
	//Constructor and destructor
	Camera(const Vertex &position1, const Vertex &position2, const bool inPos1 = true, const int inWidth = 800, const int inHeight = 800);
	~Camera();

	//Methods
	void render() const;
	void switchPosition();
	void createImage();

private:
	Vertex pos1, pos2;
	bool isPos1;		//swith between the two different positions
	int width, height;	//width and height of viewport
	Pixel* pixels;		//pointer to array of all the pixels in the camera plane
};

