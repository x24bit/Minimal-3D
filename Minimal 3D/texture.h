#pragma once
#include <iostream>

#include <gl/glew.h>
#include <glfw/glfw3.h>

class Texture
{
	public:
		int error_count_load_texture;
		GLint texture_mag_filter, texture_min_filter, texture_wrap_s, texture_wrap_t;

		Texture(GLint new_texture_mag_filter, GLint new_texture_min_filter, GLint new_texture_wrap_s, GLint new_texture_wrap_t);
		void load_texture(const char* name, GLuint* id);
};

