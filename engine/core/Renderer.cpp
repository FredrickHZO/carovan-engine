#include <glad/glad.h>

#include "Renderer.h"
#include "../core/Window.h"
#include "../core/ImGuiHelper.h"
#include "../api/opengl/Common.h"

namespace Carovan
{
    void Renderer::Draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const Shader& shader)
    {
        vertexArray.Bind();
        indexBuffer.Bind();
        shader.Bind();
        GL_FUNCTION(glDrawElements(GL_TRIANGLES, indexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr));

    #ifdef _NDEBUG
        vertexArray.Unbind();
        indexBuffer.Unbind();
        shader.Unbind();
    #endif
    }

    void Renderer::DrawGui()
    {
        ImGuiHelper::Instance()->NewFrame();
        ImGuiHelper::Instance()->DemoWindow();
        ImGuiHelper::Instance()->SceneHierarchy();
        ImGuiHelper::Instance()->RenderImGui();
    }

    void Renderer::Clear()
    {
        GL_FUNCTION(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
        GL_FUNCTION(glClear(GL_COLOR_BUFFER_BIT));
    }

    void Renderer::End()
    {
        glfwPollEvents();
        glfwSwapBuffers(Window::Instance()->GetWindowHandle());
    }
};
