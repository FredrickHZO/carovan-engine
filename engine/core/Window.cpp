#include "Window.h"

#include "../utils/Assertion.h"

namespace Carovan
{
    /**
     * Init window with default width and height.
     * Panics if window creation fails.
     * @param title Window title
     * @return Window handle
     */
    void Window::Init(const char* title)
    {
        SetWindowHint();

        GLFWwindow* window = glfwCreateWindow(this->Width, this->Height , title, nullptr, nullptr);
        CAROVAN_ASSERT(!window, "Window creation failed");
        glfwMakeContextCurrent(window);

        this->m_Window = window;
        this->Title = title;
    }

    /**
     * Init window with user specified width, height and title.
     * Panics if window creation fails.
     * @param width Window width
     * @param height Window heigth
     * @param title Window title
     * @return Window handle
     */
    void Window::Init(const int width, const int height, const char* title)
    {
        SetWindowHint();

        GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        CAROVAN_ASSERT(!window, "Window creation failed");
        glfwMakeContextCurrent(window);

        this->m_Window = window;
        this->Height = height;
        this->Width = width;
        this->Title = title;
    }

    CarovanWindow* Window::GetWindowHandle() const
    {
        return this->m_Window;
    }

    void Window::SetWindowHint()
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }
};
