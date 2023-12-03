#include <iostream>

#include <gl/glew.h>
#include <glfw/glfw3.h>

#include "window.h"
#include "camera.h"
#include "texture.h"
#include "cube.h"

int main()
{
    Window  m3dWindow  (1400, 600, "Minimal 3D", 24, 8);
    Camera  m3dCamera  (110.f, 0.1f, 1024.f);
    Texture m3dTexture (GL_LINEAR, GL_LINEAR_MIPMAP_LINEAR, GL_REPEAT, GL_REPEAT);
    Cube    m3dCube    (1.f);

    glewInit();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    GLuint cube[6]{};

    m3dTexture.load_texture("resource/texture/cube/face.png",  &cube[0]);
    m3dTexture.load_texture("resource/texture/cube/back.png",  &cube[1]);

    m3dTexture.load_texture("resource/texture/cube/left.png",  &cube[2]);
    m3dTexture.load_texture("resource/texture/cube/right.png", &cube[3]);

    m3dTexture.load_texture("resource/texture/cube/down.png",  &cube[4]);
    m3dTexture.load_texture("resource/texture/cube/up.png",    &cube[5]);

    while (!glfwWindowShouldClose(m3dWindow.window))
    {
        m3dWindow.process();
        m3dCamera.process(m3dWindow.width, m3dWindow.height);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);

        m3dCube.draw(cube);
        glRotatef(GLfloat(m3dWindow.delta) * 128.f, 1.f, 0.f, 1.f);

        m3dWindow.swap_buffers();
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}