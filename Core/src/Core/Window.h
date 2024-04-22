#pragma once
#include "Event.h"

#include <string>

namespace KMG
{

	class Window
	{
	public:
		struct WindowProperties
		{
		public:
			std::string Title = "New Window";
			uint32_t Width = 960;
			uint32_t Height = 720;
			bool VSync = false;
		};
	public:
		Window() = default;
		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual bool GetVSync() const = 0;
		virtual void SetVSync(bool enabled) = 0;

		using EventCallbackFunction = std::function<void(Event&)>;
		virtual void SetEventCallback(const EventCallbackFunction& callback) = 0;

		virtual void* GetNativeWindow() const = 0;
	public:
		static u_ptr<Window> Create(const WindowProperties& settings);
	};
}
