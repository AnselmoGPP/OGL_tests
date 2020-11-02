#include "shader.hpp"

void Shader::checkCompileErrors(unsigned int shaderID, std::string type)
{
    int success;
    char infoLog[1024];

    if(type != "PROGRAM")
    {
        glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(shaderID, 1024, nullptr, infoLog);
            std::cout << type << "_SHADER_COMPILATION_ERROR \n" << infoLog <<
                         "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shaderID, GL_LINK_STATUS, &success);
        if(!success)
        {
            glGetProgramInfoLog(shaderID, 1024, nullptr, infoLog);
            std::cout << type << "_LINKING_ERROR \n" << infoLog <<
                         "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
}

Shader::Shader(const char *vertexPath, const char *fragmentPath)
{
    // 1) Retrieve the shaders source code the paths

    std::ifstream vertexFile;
    std::ifstream fragmentFile;
    std::string vertexString;
    std::string fragmentString;

    // Ensure ifstream objects can throw exceptions:
    vertexFile.exceptions( std::ifstream::failbit | std::ifstream::badbit );
    fragmentFile.exceptions( std::ifstream::failbit | std::ifstream::badbit );

    try
    {
        vertexFile.open(vertexPath);
        fragmentFile.open(fragmentPath);

        std::stringstream vertexStream, fragmentStream;
        vertexStream << vertexFile.rdbuf();
        fragmentStream << fragmentFile.rdbuf();

        vertexFile.close();
        fragmentFile.close();

        vertexString = vertexStream.str();
        fragmentString = fragmentStream.str();
    }
    catch( std::ifstream::failure &e )
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }

    const char *vertexCode = vertexString.c_str();
    const char *fragmentCode = fragmentString.c_str();

    // 2) Compile the shaders and the program

    unsigned int vertexID, fragmentID;

    vertexID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexID, 1, &vertexCode, nullptr);
    glCompileShader(vertexID);
    checkCompileErrors(vertexID, "VERTEX");

    fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentID, 1, &fragmentCode, nullptr);
    glCompileShader(fragmentID);
    checkCompileErrors(fragmentID, "FRAGMENT");

    ID = glCreateProgram();
    glAttachShader(ID, vertexID);
    glAttachShader(ID, fragmentID);
    glLinkProgram(ID);
    checkCompileErrors(ID, "PROGRAM");

    glDeleteShader(vertexID);
    glDeleteShader(fragmentID);
}

void Shader::UseProgram()
{
    glUseProgram(ID);
}

void Shader::setBoolUniform(const std::string &name, bool value) const
{
    int uniformID = glGetUniformLocation(ID, name.c_str());
    glUniform1i(uniformID, (int)value);
}

void Shader::setIntUniform(const std::string &name, int value) const
{
    int uniformID = glGetUniformLocation(ID, name.c_str());
    glUniform1i(uniformID, value);
}

void Shader::setFloatUniform(const std::string &name, float value) const
{
    int uniformID = glGetUniformLocation(ID, name.c_str());
    glUniform1f(uniformID, value);
}
