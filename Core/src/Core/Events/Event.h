#pragma once
#include "Core.h"

namespace KMG
{

#define DEFINE_EVENT_CLASS_TYPE_METHODS(type) virtual EventType GetEventType() const override { return EventType::##type; }\
											  static EventType GetStaticType() { return EventType::##type; }	

#define CREATE_EVENT_FN_REF(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

	enum EventType
	{
		None = 0,
		WindowResized,
		WindowClosed,
		KeyStateChanged,
		MouseMoved,
		MouseScrolled,
		MouseButtonPressed,
		MouseButtonReleased,
	};

	class Event
	{
	public:
		Event() = default;
		virtual ~Event() = default;

		virtual EventType GetEventType() const = 0;
	};

	class EventDispatcher
	{
	public:
		template<typename T, typename F>
		static constexpr bool Dispatch(Event& e, const F& func)
		{
			if (e.GetEventType() == T::GetStaticType())
				return func(static_cast<T&>(e));
			return false;
		}
	private:
		EventDispatcher() = default;
		virtual ~EventDispatcher() = default;
	};

	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(uint32_t width, uint32_t height)
			: Width(width), Height(height)
		{
		}
		virtual ~WindowResizeEvent() = default;

		DEFINE_EVENT_CLASS_TYPE_METHODS(WindowResized)
	public:
		uint32_t Width, Height;
	};

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;
		virtual ~WindowCloseEvent() = default;

		DEFINE_EVENT_CLASS_TYPE_METHODS(WindowClosed)
	};

	class KeyEvent : public Event
	{
	public:
		KeyEvent(int key, int action)
			:Key(key), Action(action)
		{
		}
		virtual ~KeyEvent() = default;

		DEFINE_EVENT_CLASS_TYPE_METHODS(KeyStateChanged)
	public:
		int Key, Action;
	};

	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(double xPos, double yPos)
			:XPos(xPos), YPos(yPos)
		{
		}
		virtual ~MouseMovedEvent() = default;

		DEFINE_EVENT_CLASS_TYPE_METHODS(MouseMoved)
	public:
		double XPos, YPos;
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: XOffset(xOffset), YOffset(yOffset)
		{
		}

		DEFINE_EVENT_CLASS_TYPE_METHODS(MouseScrolled)
	public:
		float XOffset, YOffset;
	};

	class MouseButtonPressedEvent : public Event
	{
	public:
		MouseButtonPressedEvent(int button)
			:Button(button)
		{
		}

		DEFINE_EVENT_CLASS_TYPE_METHODS(MouseButtonPressed)
	public:
		int Button;
	};

	class MouseButtonReleasedEvent : public Event
	{
	public:
		MouseButtonReleasedEvent(int button)
			:Button(button)
		{
		}

		DEFINE_EVENT_CLASS_TYPE_METHODS(MouseButtonReleased)
	public:
		int Button;
	};
}
