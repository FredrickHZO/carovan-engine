#pragma once

#include <GLFW/glfw3.h>

#include "utils/Singleton.h"

namespace Carovan
{
    using CarovanWindow = GLFWwindow;

    class Window : public Singleton<Window> {
    private:
        CarovanWindow* m_Window = nullptr;

    public:
        const char* Title;
        int         Width  = 1280;
        int         Height = 720;

    private:
        void SetWindowHint();

    public:
        void Init(int width, int height, const char* title);
        void Init(const char* title);

        [[nodiscard]]
        CarovanWindow* GetWindowHandle() const;
    };
};
