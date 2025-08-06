#include <glad/glad.h>

#include "Carovan.h"
#include "utils/Assertion.h"

// This code will be removed once Renderer / Scene / Entities / Events are completely implemented
namespace Carovan
{
    void EngineInit()
    {
        int success = glfwInit();
        CAROVAN_ASSERT(!success, "Failed to initialize GLFW3");

        // Window must be initialized before GLAD
        Window::Instance()->Init("Carovan");
        ImGuiHelper::Instance()->InitImGui(Window::Instance()->GetWindowHandle());

        success = gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
        CAROVAN_ASSERT(!success, "Failed to load GLAD");
    }

    void EngineDispose()
    {
        glfwTerminate();
    }

    bool ExitRequested()
    {
        return glfwWindowShouldClose(Window::Instance()->GetWindowHandle());
    }

    // Methods that start with TEST are purely placeholders
    // and don't represent how the code will look down the road.
    // Those methods are hideous... but useful for now.
    float* TESTGetTrianglesVertexes()
    {
        auto* vertexes = new float[8]{
            -0.5f, -0.5f,
             0.5f, -0.5f,
             0.5f,  0.5f,
            -0.5f,  0.5f,
        };
        return vertexes;
    }

    unsigned int* TESTGetTriangleIndices()
    {
        auto* indices = new unsigned int[6] {
            0, 1, 2,
            2, 3, 0
        };
        return indices;
    }

    std::tuple<VertexArray, IndexBuffer> TESTPrepareBuffers()
    {
        unsigned int* indices   = TESTGetTriangleIndices();
        float*        vertexes  = TESTGetTrianglesVertexes();

        VertexBuffer vertexBuffer(vertexes, 8*sizeof(float));
        VertexArray vertexArray;
        VertexBufferLayout layout;
        layout.Push<float>(2);
        vertexArray.AddBuffer(vertexBuffer, layout);
        IndexBuffer indexBuffer(indices, 6);

        vertexArray.Unbind();
        vertexBuffer.Unbind();
        indexBuffer.Unbind();
        delete indices;
        delete vertexes;

        return std::make_tuple(std::move(vertexArray), std::move(indexBuffer));
    }

    Shader TESTPrepareShaders()
    {
        // Test hardcoded paths for shaders
        const std::string FRAG_SHADER_PATH = "res/Fragment.glsl";
        const std::string VERT_SHADER_PATH = "res/Vertex.glsl";

        Shader shader(VERT_SHADER_PATH, FRAG_SHADER_PATH);
        shader.Bind();
        shader.SetUniform4f("u_Color", Vector<float>{ 1.0f, 0.8f, 0.4, 1.0f });
        //int location = shader.GetUniformLocation("u_Color");

        return shader;
    }
};