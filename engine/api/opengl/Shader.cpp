#include <glad/glad.h>
#include <fstream>
#include <sstream>
#include <memory>

#include "Shader.h"
#include "Common.h"
#include "../../core/Logger.h"

namespace Carovan
{
    Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
        : m_RendererID(0)
    {
        const auto fragment = OpenShaderFile(fragmentPath);
        const auto vertex   = OpenShaderFile(vertexPath);
        this->m_RendererID = CreateShader(vertex, fragment);
    }

    Shader::~Shader()
    {
        GL_FUNCTION(glDeleteProgram(this->m_RendererID));
    }

    std::string Shader::OpenShaderFile(const std::string& filepath)
    {
        std::ifstream stream(filepath);

        std::string source;
        std::string line;
        while (getline(stream, line))
        {
            source += line + "\n";
        }

        return source;
    }

    inline bool Shader::ShaderCompilationSucceeded(const unsigned int shaderID)
    {
        int result;
        GL_FUNCTION(glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result));

        if (result == GL_FALSE)
        {
            int len;
            GL_FUNCTION(glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &len));

            const auto message = std::make_unique<char[]>(len);
            GL_FUNCTION(glGetShaderInfoLog(shaderID, len, &len, message.get()));
            LOG_ERROR("Could not compile shader: {}", message.get());
            GL_FUNCTION(glDeleteShader(shaderID));

            return false;
        }

        return true;
    }

    unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
    {
        GL_FUNCTION(const unsigned int program = glCreateProgram());
        const unsigned int vertShader = CompileShader(GL_VERTEX_SHADER, vertexShader);
        const unsigned int fragShader = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

        GL_FUNCTION(glAttachShader(program, vertShader));
        GL_FUNCTION(glAttachShader(program, fragShader));
        GL_FUNCTION(glLinkProgram(program));
        GL_FUNCTION(glValidateProgram(program));

        GL_FUNCTION(glDeleteShader(vertShader));
        GL_FUNCTION(glDeleteShader(fragShader));

        return program;
    }

    unsigned int Shader::CompileShader(const unsigned int type, const std::string& source)
    {
        CAROVAN_ASSERT(source.empty(), "Source to shader does not exist");

        GL_FUNCTION(const unsigned int shaderID = glCreateShader(type));
        const char* src = source.c_str();
        GL_FUNCTION(glShaderSource(shaderID, 1, &src, nullptr));
        GL_FUNCTION(glCompileShader(shaderID));

        const bool success = ShaderCompilationSucceeded(shaderID);
        CAROVAN_ASSERT(!success, "Shader compilation error");

        return shaderID;
    }

    void Shader::Bind() const
    {
        GL_FUNCTION(glUseProgram(this->m_RendererID));
    }

    void Shader::Unbind() const
    {
        GL_FUNCTION(glUseProgram(0));
    }

    void Shader::SetUniform4f(const std::string& name, const Vector<float>& vec)
    {
        const auto location = GetUniformLocation(name);
        GL_FUNCTION(glUniform4f(location, vec.x, vec.y, vec.z, vec.w));
    }

    int Shader::GetUniformLocation(const std::string& uniformName)
    {
        if (this->m_UniformLocationCache.contains(uniformName))
        {
            return this->m_UniformLocationCache[uniformName];
        }

        GL_FUNCTION(const int location = glGetUniformLocation(m_RendererID, uniformName.c_str()));
        if (location == -1)
        {
            LOG_WARN("Uniform {} doesn't exist", uniformName);
        }
        this->m_UniformLocationCache[uniformName] = location;

        return location;
    }
};