#include "cube.h"

Cube::Cube(GLfloat new_size)
{
    size = new_size;
}

void Cube::draw(GLuint texture[])
{
    // face
    glBindTexture(GL_TEXTURE_2D, texture[0]); glBegin(GL_QUADS); {
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(0, 0); glVertex3f(-size, -size, -size);
        glTexCoord2f(1, 0); glVertex3f( size, -size, -size);
        glTexCoord2f(1, 1); glVertex3f( size,  size, -size);
        glTexCoord2f(0, 1); glVertex3f(-size,  size, -size);
    } glEnd();

    // back
    glBindTexture(GL_TEXTURE_2D, texture[1]); glBegin(GL_QUADS); {
        glNormal3f(0.0f, 0.0f, -1.0f);
        glTexCoord2f(0, 0); glVertex3f(-size, -size,  size);
        glTexCoord2f(1, 0); glVertex3f( size, -size,  size);
        glTexCoord2f(1, 1); glVertex3f( size,  size,  size);
        glTexCoord2f(0, 1); glVertex3f(-size,  size,  size);
    } glEnd();

    // left
    glBindTexture(GL_TEXTURE_2D, texture[2]); glBegin(GL_QUADS); {
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTexCoord2f(0, 0); glVertex3f(-size, -size,  size);
        glTexCoord2f(1, 0); glVertex3f(-size, -size, -size);
        glTexCoord2f(1, 1); glVertex3f(-size,  size, -size);
        glTexCoord2f(0, 1); glVertex3f(-size,  size,  size);
    } glEnd();

    // right
    glBindTexture(GL_TEXTURE_2D, texture[3]); glBegin(GL_QUADS); {
        glNormal3f(1.0f, 0.0f, 0.0f);
        glTexCoord2f(0, 0); glVertex3f( size, -size, -size);
        glTexCoord2f(1, 0); glVertex3f( size, -size,  size);
        glTexCoord2f(1, 1); glVertex3f( size,  size,  size);
        glTexCoord2f(0, 1); glVertex3f( size,  size, -size);
    } glEnd();

    // down
    glBindTexture(GL_TEXTURE_2D, texture[4]); glBegin(GL_QUADS); {
        glNormal3f(0.0f, -1.0f, 0.0f);
        glTexCoord2f(0, 0); glVertex3f(-size, -size,  size);
        glTexCoord2f(1, 0); glVertex3f( size, -size,  size);
        glTexCoord2f(1, 1); glVertex3f( size, -size, -size);
        glTexCoord2f(0, 1); glVertex3f(-size, -size, -size);
    } glEnd();

    // up
    glBindTexture(GL_TEXTURE_2D, texture[5]); glBegin(GL_QUADS); {
        glNormal3f(0.0f, 1.0f, 0.0f);
        glTexCoord2f(0, 0); glVertex3f(-size,  size, -size);
        glTexCoord2f(1, 0); glVertex3f( size,  size, -size);
        glTexCoord2f(1, 1); glVertex3f( size,  size,  size);
        glTexCoord2f(0, 1); glVertex3f(-size,  size,  size);
    } glEnd();
}

