#pragma once
#include <glfw/glfw3.h>

class Window
{
	private:
		double current_frame, last_frame;

	public:
		GLFWwindow* window;

		int width, height, x, y;
		double delta;

		Window(int width, int height, const char *title, int depth, int samples);
		void process();
		void swap_buffers();
};

