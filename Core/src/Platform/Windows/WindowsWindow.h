#pragma once
#include "Core/Core.h"
#include "Core/Window.h"

#include <GLFW/glfw3.h>

namespace KMG
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperties& settings);
		virtual ~WindowsWindow() = default;

		void OnUpdate() override;

		uint32_t GetWidth() const override { return m_Settings.Width; };
		uint32_t GetHeight() const override { return m_Settings.Height; };

		bool GetVSync() const override { return m_Settings.VSync; };
		void SetVSync(bool enabled) override;

		void SetEventCallback(const EventCallbackFunction& callback) override { m_Settings.OnEvent = callback; }

		virtual void* GetNativeWindow() const override { return m_NativeWindow; }

		void Init(const WindowProperties& settings);
		void Shutdown();
	private:
		struct WindowSettings
		{
		public:
			std::string Title = "New Window";
			uint32_t Width = 960;
			uint32_t Height = 720;
			bool VSync = false;

			EventCallbackFunction OnEvent;
		};
	private:
		GLFWwindow* m_NativeWindow = nullptr;
		WindowSettings m_Settings;
	};
}