#include "corepch.h"
#include "Application.h"
#include "Platform/Windows/WindowsWindow.h"
#include "Time.h"

namespace KMG
{
	Application* Application::s_Instance = nullptr;

	Application::Application(const ApplicationSettings& settings)
		:m_Settings(settings)
	{
		s_Instance = this;

		m_Window = Window::Create({ settings.Title });
		m_Window->SetEventCallback(KMG_BIND_EVENT(OnEvent));

		Time::Init();
	}

	void Application::Run()
	{
		for (auto& layer : m_Layers)
		{
			layer->OnEnable();
			
			WindowResizeEvent event(m_Window->GetWidth(), m_Window->GetHeight());
			layer->OnEvent(event);
		}

		while (m_Running)
		{
			Time::OnUpdate();

			for (auto& layer : m_Layers)
				layer->OnUpdate(Time::GetDeltaTime());

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


	void Application::OnEvent(Event& e)
	{
		for (auto* layer : m_Layers)
			layer->OnEvent(e);

		if(e.GetEventType() == EventType::WindowClosed)
		{
			m_Running = false;
			Shutdown();
		}
	}
}