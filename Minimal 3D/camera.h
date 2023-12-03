#pragma once
#include <gl/glew.h>
#include <glfw/glfw3.h>
#include <gl/glu.h>

class Camera
{
	public:
		GLfloat fov, znear, zfar;
		Camera(GLfloat new_fov, GLfloat new_znear, GLfloat new_zfar);
		void process(int width, int height);
};
