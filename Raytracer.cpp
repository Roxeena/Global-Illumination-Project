//Raytracer project in the "Global illumination and rendering course"

#include "MicroGlut.h"
// uses framework Cocoa
#include "GL_utilities.h"
#include "VectorUtils3.h"
#include "loadobj.h"
#include "LoadTGA.h"

mat4 projectionMatrix;
mat4 worldToViewMatrix, modelToWorldMatrix;

Model *m;
// Reference to shader program
GLuint program;

void init(void)
{
	// GL inits
	glClearColor(1.0, 1.0, 1.0, 0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_TRUE);

	// Load and compile shader
	/*program = loadShaders("psych.vert", "psych.frag");
	glUseProgram(program);*/

	projectionMatrix = frustum(-0.5, 0.5, -0.5, 0.5, 1.0, 30.0);
	worldToViewMatrix = lookAt(0, 1, 8, 0, 0, 0, 0, 1, 0);
	modelToWorldMatrix = IdentityMatrix();
	//	mx = Mult(worldToViewMatrix, modelToWorldMatrix);

	glUniformMatrix4fv(glGetUniformLocation(program, "camMatrix"), 1, GL_TRUE, worldToViewMatrix.m);
	glUniformMatrix4fv(glGetUniformLocation(program, "projMatrix"), 1, GL_TRUE, projectionMatrix.m);
}


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitContextVersion(3, 2);
	glutCreateWindow("Global illumination raytracer");
#ifdef WIN32
	glewInit();
#endif
	
	return 0;
}
