#pragma once

#include "core/Window.h"
#include "core/ImGuiHelper.h"
#include "core/Renderer.h"
#include "core/InputManager.h"
#include "api/opengl/VertexBuffer.h"
#include "api/opengl/VertexArray.h"
#include "api/opengl/IndexBuffer.h"
#include "api/opengl/Shader.h"

// This code is (ugly and) for Test / Debug only and will be removed
// once Scene / Entities / Events are done and this file
// will only contain relevant include of engine api code
// for the client application to use (Managers, Scene, Entities, etc).
namespace Carovan
{
    void EngineInit();
    void EngineDispose();
    bool ExitRequested();

    float* TESTGetTrianglesVertexes();
    unsigned int* TESTGetTriangleIndices();
    std::tuple<VertexArray, IndexBuffer> TESTPrepareBuffers();
    Shader TESTPrepareShaders();
};