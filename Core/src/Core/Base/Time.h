#pragma once
#include <GLFW/glfw3.h>

namespace KMG
{
	class Time
	{
	public:
		static void Init();
		static void OnUpdate();

		static double GetTime() { return glfwGetTime(); }
		static double GetDeltaTime() { return m_DeltaTime; }
	private:
		Time() = default;
		~Time() = default;
	private:
		static double m_PreviousFrameTime;
		static double m_DeltaTime;
	};
}
