#include "corepch.h"
#include "Time.h"

namespace KMG
{
	double Time::m_DeltaTime = 0.0;
	double Time::m_PreviousFrameTime = 0.0;

	void Time::Init()
	{
		m_PreviousFrameTime = 0.0;
		m_DeltaTime = 0.0;

		OnUpdate();
	}

	void Time::OnUpdate()
	{
		double time = glfwGetTime();
		m_DeltaTime = time - m_PreviousFrameTime;
		m_PreviousFrameTime = time;
	}
}