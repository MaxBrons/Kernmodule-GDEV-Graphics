#include "corepch.h"
#include "WindowsWindow.h"
#include "Base/Log.h"

namespace KMG
{
	// External window creation method.
	u_ptr<Window> Window::Create(const WindowProperties& settings)
	{
		return KMG::MakeUnique<WindowsWindow>(settings);
	}

	static void GLFWErrorCallback(int error, const char* description)
	{
		KMG_LOG_ERROR("GLFW Error (" + std::to_string(error) + "):" + std::string(description));
	}

	WindowsWindow::WindowsWindow(const WindowProperties& settings)
	{
		Init(settings);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwSwapBuffers(m_NativeWindow);
		glfwPollEvents();
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Settings.VSync = enabled;
	}

	void WindowsWindow::Init(const WindowProperties& settings)
	{
		m_Settings.Title = settings.Title;
		m_Settings.Width = settings.Width;
		m_Settings.Height = settings.Height;

		int result = glfwInit();
		KMG_CORE_ASSERT(result, "Could not initialize GLFW.");

#ifdef KMG_DEBUG
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
#endif
		//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

		m_NativeWindow = glfwCreateWindow(settings.Width, settings.Height, settings.Title.c_str(), nullptr, nullptr);
		KMG_CORE_ASSERT(m_NativeWindow, "Could not create the GLFW window.");

		glfwMakeContextCurrent(m_NativeWindow);

		result = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		KMG_CORE_ASSERT(result, "Could not initialize GLAD.");

		glfwSetErrorCallback(GLFWErrorCallback);

		glfwSetWindowUserPointer(m_NativeWindow, &m_Settings);

		glfwSetWindowSizeCallback(m_NativeWindow, [](GLFWwindow* window, int width, int height) {
			WindowSettings& settings = *(WindowSettings*)glfwGetWindowUserPointer(window);
			settings.Width = width;
			settings.Height = height;

			WindowResizeEvent event(static_cast<uint32_t>(width), static_cast<uint32_t>(height));
			settings.OnEvent(event);
			});

		glfwSetWindowCloseCallback(m_NativeWindow, [](GLFWwindow* window) {
			WindowSettings& settings = *(WindowSettings*)glfwGetWindowUserPointer(window);

			WindowCloseEvent event;
			settings.OnEvent(event);
			});

		glfwSetKeyCallback(m_NativeWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowSettings& settings = *(WindowSettings*)glfwGetWindowUserPointer(window);

			KeyEvent event(key, action);
			settings.OnEvent(event);
			});

		glfwSetCursorPosCallback(m_NativeWindow, [](GLFWwindow* window, double xPos, double yPos) {
			WindowSettings& settings = *(WindowSettings*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event(xPos, yPos);
			settings.OnEvent(event);
			});

		glfwSetMouseButtonCallback(m_NativeWindow, [](GLFWwindow* window, int button, int action, int mods) {
			WindowSettings& settings = *(WindowSettings*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					settings.OnEvent(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					settings.OnEvent(event);
					break;
				}
			}
			});

		glfwSetScrollCallback(m_NativeWindow, [](GLFWwindow* window, double xOffset, double yOffset) {
			WindowSettings& settings = *(WindowSettings*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			settings.OnEvent(event);
			});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_NativeWindow);
		m_NativeWindow = nullptr;
	}
}