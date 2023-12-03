#include "texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.c"

Texture::Texture(GLint new_texture_mag_filter, GLint new_texture_min_filter, GLint new_texture_wrap_s, GLint new_texture_wrap_t)
{
    error_count_load_texture = 0;

    texture_min_filter = new_texture_min_filter;
    texture_mag_filter = new_texture_mag_filter;

    texture_wrap_s     = new_texture_wrap_s;
    texture_wrap_t     = new_texture_wrap_t;
}

void Texture::load_texture(const char* path, GLuint* id)
{
    glGenTextures(1, id);
    glBindTexture(GL_TEXTURE_2D, *id);

    float anisotropic = 1.0f;
    glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &anisotropic);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, anisotropic);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, texture_min_filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, texture_mag_filter);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, texture_wrap_s);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, texture_wrap_t);

    int width, height, channels;
    unsigned char* data = stbi_load(path, &width, &height, &channels, 0);

    if (data == nullptr) {
        error_count_load_texture++;
        std::cout << error_count_load_texture << "." << " stbi load texture error " << path << std::endl;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);
}
