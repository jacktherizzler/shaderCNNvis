#pragma once

#include <string>
#include <OpenGL/gl3.h>

class Shader {
public:
    Shader();
    ~Shader();
    bool init(const char* vertexPath, const char* fragmentPath);
    void use();
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setMat4(const std::string &name, const float* value) const;
    GLuint getProgram() const { return programID; }

private:
    GLuint programID;
    void checkCompileErrors(GLuint shader, std::string type);
};