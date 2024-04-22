#pragma once

namespace KMG
{
	enum EventType
	{
		None = 0,
		WindowResized,
		WindowClosed,
		KeyStateChanged,
		MouseMoved
	};

	class Event
	{
	public:
		Event(const EventType eventType)
			:m_EventType(eventType)
		{
		}
		virtual ~Event() = default;

		EventType GetEventType() const { return m_EventType; }
	private:
		EventType m_EventType;
	};

	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(uint32_t width, uint32_t height)
			:Event(EventType::WindowResized)
		{
			Width = width;
			Height = height;
		}
		virtual ~WindowResizeEvent() = default;
	public:
		uint32_t Width, Height;
	};

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent()
			:Event(EventType::WindowClosed)
		{
		}
		virtual ~WindowCloseEvent() = default;
	};

	class KeyEvent : public Event
	{
	public:
		KeyEvent(int key, int action)
			:Event(EventType::KeyStateChanged)
		{
			Key = key;
			Action = action;
		}
		virtual ~KeyEvent() = default;
	public:
		int Key, Action;
	};

	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(double xPos, double yPos)
			:Event(EventType::MouseMoved)
		{
			XPos = xPos;
			YPos = yPos;
		}
		virtual ~MouseMovedEvent() = default;
	public:
		double XPos, YPos;
	};
}
