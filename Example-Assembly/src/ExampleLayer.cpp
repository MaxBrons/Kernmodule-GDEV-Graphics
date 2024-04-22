#include "ExampleLayer.h"

void ExampleLayer::OnEnable()
{
	KMG_LOG_WARN("OnEnable of Example Layer not yet implemented.");
}

void ExampleLayer::OnUpdate(double deltaTime)
{
	static bool s_Triggered;
	if (s_Triggered)
		return;

	KMG_LOG_WARN("OnUpdate of Example Layer not yet implemented.");
	s_Triggered = true;
}

void ExampleLayer::OnDisable()
{
	KMG_LOG_WARN("OnDisable of Example Layer not yet implemented.");
}