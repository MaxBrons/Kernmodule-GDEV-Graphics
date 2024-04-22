#pragma once

namespace KMG
{
	class ApplicationLayer
	{
	public:
		ApplicationLayer() = default;
		virtual ~ApplicationLayer() = default;

		virtual void OnEnable() = 0;
		virtual void OnUpdate(double deltaTime) = 0;
		virtual void OnDisable() = 0;
	};
}