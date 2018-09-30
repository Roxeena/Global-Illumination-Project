class Vertex
{
public:
	Vertex();
	Vertex(const float inX, const float inY, const float inZ, const float inW = 1);
	~Vertex();

	//Methods
	void setVertex(const float inX, const float inY, const float inZ, const float inW = 1);

private:
	float x, y, z, w;
};
