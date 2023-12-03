#include "camera.h"

Camera::Camera(GLfloat new_fov, GLfloat new_znear, GLfloat new_zfar)
{
	fov = new_fov;
	znear = new_znear;
	zfar = new_zfar;
}

void Camera::process(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, GLfloat(width) / GLfloat(height), znear, zfar);
	glTranslatef(0.0f, 0.0f, -4.0f);
}
