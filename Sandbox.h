#pragma once

#include "engine/Carovan.h"

class Sandbox
{
public:
    // This is not indicative of how the client application code will look like
    // down the road when the engine api is done
    void Run()
    {
        Carovan::EngineInit();
        const Carovan::Shader shader = Carovan::TESTPrepareShaders();
        auto [vertexArr, indexBuff] = Carovan::TESTPrepareBuffers();

        while (!Carovan::ExitRequested())
        {
            // Update application state
            Carovan::InputManager::ProcessInput();

            // Render pass
            Carovan::Renderer::Clear();
                Carovan::Renderer::Draw(vertexArr, indexBuff, shader);
                Carovan::Renderer::DrawGui();
            Carovan::Renderer::End();
        }
        Carovan::EngineDispose();
    }
};
