#pragma once
#include <gl/glew.h>
#include <glfw/glfw3.h>

class Cube
{
	public:
		GLfloat size;

		Cube(GLfloat size);
		void draw(GLuint texture[]);
};

