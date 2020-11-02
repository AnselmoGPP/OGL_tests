#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
    void checkCompileErrors(unsigned int shaderID, std::string type);

public:
    unsigned int ID;

    Shader(const char *vertexPath, const char *fragmentPath);
    void UseProgram();

    void setBoolUniform(const std::string &name, bool value) const;
    void setIntUniform(const std::string &name, int value) const;
    void setFloatUniform(const std::string &name, float value) const;
};

#endif
