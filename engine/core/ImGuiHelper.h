#pragma once

#include <imgui.h>
#include <GLFW/glfw3.h>

#include "../utils/Singleton.h"

namespace Carovan
{
    // Demo code
    class ImGuiHelper : public Singleton<ImGuiHelper>
    {
    private:
        GLFWwindow* m_Window;
        const ImVec4 m_ClearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
        float m_DemoSliderValue = 0.0f;
        bool m_ShowFramerate = true;
        int m_DemoCounter = 0;

    public:
        void InitImGui(GLFWwindow* window);
        void RenderImGui() const;
        void DemoWindow();
        void SceneHierarchy();
        void NewFrame() const;

    private:
        void ApplyStyle();
    };
};
