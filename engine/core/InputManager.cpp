#include "InputManager.h"
#include "../core/Window.h"

namespace Carovan
{
    void InputManager::ProcessInput()
    {
        CarovanWindow* window = Window::Instance()->GetWindowHandle();
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, true);
        }
    }
};
