#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "ApplicationLayer.h"
#include "Window.h"

namespace KMG
{
	struct ApplicationSettings
	{
	public:
		std::string Title;
	};

	class Application
	{
	public:
		Application(const ApplicationSettings& settings);
		virtual ~Application() = default;

		void Run();
		void Shutdown();
		void OnEvent(Event& event);

		bool IsRunning() const { return m_Running; }
		Window& GetWindow() const { return *m_Window; }
		
		static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClosed(WindowCloseEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);
	protected:
		std::vector<ApplicationLayer*> m_Layers;
	private:
		u_ptr<Window> m_Window;
		bool m_Running = true;
		ApplicationSettings m_Settings;
	private:
		static Application* s_Instance;
	};
}