#include "window.h"

Window::Window(int width, int height, const char* title, int depth, int samples)
{
	glfwWindowHint(GLFW_DEPTH_BITS, depth);
	glfwWindowHint(GLFW_SAMPLES, samples);

	glfwInit();

	window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	glfwMakeContextCurrent(window);

	process();
}

void Window::swap_buffers()
{
	glfwSwapBuffers(window);
}

void Window::process()
{
	glfwGetWindowSize(window, &width, &height);
	glfwGetWindowPos(window, &x, &y);

	glViewport(0, 0, width, height);

	current_frame = glfwGetTime();
	delta = current_frame - last_frame;
	last_frame = current_frame;
}
