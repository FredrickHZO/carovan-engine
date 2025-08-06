#pragma once

#include <string>
#include <unordered_map>
#include "../../math/Vector.h"

namespace Carovan
{
    class Shader
    {
    private:
        std::unordered_map<std::string, int>  m_UniformLocationCache;
        unsigned int                          m_RendererID;

    public:
        Shader() = delete;
        Shader(const std::string& vertexPath, const std::string& fragmentPath);
        ~Shader();

        void Bind() const;
        void Unbind() const;
        void SetUniform4f(const std::string& name, const Vector4<float>& vec);
        int GetUniformLocation(const std::string& uniformName);

    private:
        static std::string OpenShaderFile(const std::string& filepath);
        static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
        static unsigned int CompileShader(unsigned int type, const std::string& source);
        static inline bool ShaderCompilationSucceeded(unsigned int shaderID);
    };
};
