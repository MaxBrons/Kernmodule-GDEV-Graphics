#include "ExampleLayer.h"

void ExampleLayer::OnEnable()
{
	KMG_LOG_WARN("OnEnable of Example Layer not yet implemented.");
}

void ExampleLayer::OnDisable()
{
	KMG_LOG_WARN("OnDisable of Example Layer not yet implemented.");
}

void ExampleLayer::OnUpdate(double deltaTime)
{
	static bool s_Triggered;
	if (s_Triggered)
		return;

	KMG_LOG_WARN("OnUpdate of Example Layer not yet implemented.");
	s_Triggered = true;
}

#define EVENT_COMPARE(e, type) if(e.GetEventType() == type)
void ExampleLayer::OnEvent(KMG::Event& e)
{
	auto type = e.GetEventType();

	if (type == KMG::EventType::KeyStateChanged)
	{
		auto& keyEvent = static_cast<KMG::KeyEvent&>(e);
		KMG_LOG_WARN(
			"Key event not yet implemented (key: " +
			std::to_string(keyEvent.Key) + ", action: " +
			std::to_string(keyEvent.Action) +
			")"
		);
	}

	if (type == KMG::EventType::MouseMoved)
	{
		static bool s_Printed = false;
		if (s_Printed)
			return;

		KMG_LOG_WARN("Mouse moved event not yet implemented.");
		s_Printed = true;
	}
}
