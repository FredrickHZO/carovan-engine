#pragma once

#include "../api/opengl/VertexArray.h"
#include "../api/opengl/IndexBuffer.h"
#include "../api/opengl/Shader.h"

namespace Carovan
{
    class Renderer {
    public:
        static void Draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const Shader& shader);
        static void DrawGui();
        static void Clear();
        static void End();
    };
};
