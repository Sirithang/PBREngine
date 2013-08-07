#include <gl/glew.h>
#include <gl/glfw.h>

#include "core/engine.h"
#include "data/mesh.h"


int main(int argc, char** argv)
{
	glfwInit();
	glfwOpenWindowHint(GLFW_VERSION_MAJOR, 3);
	glfwOpenWindowHint(GLFW_VERSION_MINOR, 3);
	glfwOpenWindow(800, 600, 8,8,8,8, 24, 16, GLFW_WINDOW);

	glewInit();

	sigurd::Engine engine;

	sigurd::data::Mesh m;
	sigurd::data::mesh::loadFromFile(m, "data/sphere.obj");

	bool running = true;
	while(running)
	{
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		engine.frameStep();
		glfwSwapBuffers();

		running = glfwGetWindowParam(GLFW_OPENED) && !glfwGetKey(GLFW_KEY_ESC);
	}

	return 0;
}