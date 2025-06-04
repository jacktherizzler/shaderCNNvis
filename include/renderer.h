#pragma once

#include <vector>
#include <string>
#include <OpenGL/gl3.h>

#ifdef __cplusplus
extern "C" {
#endif
#include "stb/stb_image.h"
#ifdef __cplusplus
}
#endif
#include "shader.h"

class Renderer {
public:
    Renderer();
    ~Renderer();
    bool init(int width, int height);
    bool loadTexture(const char* path);
    void setKernel(const std::vector<float>& kernel, int size);
    void render();
    GLuint getOutputTexture() const { return outputTexture; }

private:
    GLuint VAO, VBO;
    GLuint inputTexture;
    GLuint outputTexture;
    GLuint framebuffer;
    Shader convShader;
    int textureWidth;
    int textureHeight;
    void setupQuad();
    bool setupFramebuffer();
};