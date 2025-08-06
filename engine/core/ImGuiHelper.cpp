#include "ImGuiHelper.h"

#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace Carovan
{
    void ImGuiHelper::InitImGui(GLFWwindow* window)
    {
        ImGui::CreateContext();
        ImGui_ImplOpenGL3_Init("#version 460");
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui::StyleColorsDark();
        ApplyStyle();
    }

    void ImGuiHelper::RenderImGui() const
    {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiHelper::SceneHierarchy()
    {
        const char* demoSceneName = "Default scene";

        ImGui::Begin("Hierarchy");
        ImGui::Text("%s", demoSceneName);
        ImGui::End();
    }

    void ImGuiHelper::DemoWindow()
    {
        ImGui::Begin("Carovan");
        ImGui::Text("Engine Debugger");
        ImGui::SliderFloat("float", &m_DemoSliderValue, 0.0f, 1.0f);
        ImGui::ColorEdit4("clear color", (float*)&m_ClearColor);
        if (ImGui::Button("Button"))
        {
            m_DemoCounter++;
        }
        ImGui::SameLine();
        ImGui::Text("counter = %d", m_DemoCounter);

        ImGui::NewLine();
        ImGui::Checkbox("Show framerate", &m_ShowFramerate);
        if (m_ShowFramerate)
        {
            ImGui::Text("Application average %.3f ms/frame (%1.f)",
                    1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        }
        ImGui::End();
    }

    void ImGuiHelper::NewFrame() const
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void ImGuiHelper::ApplyStyle()
    {
        ImGuiStyle& style = ImGui::GetStyle();
        style.Colors[ImGuiCol_WindowBg] = ImColor(39, 37, 44, 255);
    }
}
