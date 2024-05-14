#include "corepch.h"
#include "Input.h"
#include "Application.h"

#include <GLFW/glfw3.h>

namespace KMG
{
    bool Input::GetKeyDown(KeyCode key)
    {
        auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        int state = glfwGetKey(window, static_cast<int32_t>(key));
        return state == GLFW_PRESS;
    }

    bool Input::GetMouseButtonDown(MouseCode button)
    {
        auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        int state = glfwGetMouseButton(window, static_cast<int32_t>(button));
        return state == GLFW_PRESS;
    }

    glm::vec2 Input::GetMousePosition()
    {
        auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        return { (float)xpos, (float)ypos };
    }
}
