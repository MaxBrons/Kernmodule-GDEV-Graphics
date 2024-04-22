#include "corepch.h"
#include "Application.h"
#include "Platform/Windows/WindowsWindow.h"
#include "Log.h"

namespace KMG
{
	Application::Application(const ApplicationSettings& settings)
		:m_Settings(settings)
	{
		m_Window = Window::Create({ settings.Title });
		m_Window->SetEventCallback(KMG_BIND_EVENT(OnEvent));
	}

	void Application::Run()
	{
		for (auto& layer : m_Layers)
			layer->OnEnable();

		while (m_Running)
		{
			// TODO: Create Timer class to pass on high_res_clock delta time.
			for (auto& layer : m_Layers)
				layer->OnUpdate(0);

			m_Window->OnUpdate();
		}
	}

	void Application::Shutdown()
	{
		for (auto layer : m_Layers)
			layer->OnDisable();

		for (auto layer : m_Layers)
			delete layer;

		m_Layers.clear();

		glfwTerminate();
	}


#define EVENT_COMPARE(x) if(event.GetEventType() == x)
	void Application::OnEvent(Event& event)
	{
		auto type = event.GetEventType();

		EVENT_COMPARE(EventType::WindowClosed)
		{
			m_Running = false;
			Shutdown();
		}

		EVENT_COMPARE(EventType::KeyStateChanged)
		{
			auto& keyEvent = static_cast<KeyEvent&>(event);
			KMG_LOG_WARN(
				"Key event not yet implemented (key: " +
				std::to_string(keyEvent.Key) + ", action: " +
				std::to_string(keyEvent.Action) +
				")"
			);
		}

		EVENT_COMPARE(EventType::MouseMoved)
		{
			static bool s_Printed = false;
			if (s_Printed)
				return;

			KMG_LOG_WARN("Mouse moved event not yet implemented.");
			s_Printed = true;
		}
	}
}