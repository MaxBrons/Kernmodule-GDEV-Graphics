#include "ExampleLayer.h"

#include <glfw/include/GLFW/glfw3.h> // Temp, for easy testing; TODO: Abstract out glfw code to Core.

void ExampleLayer::OnEnable()
{
	//KMG_LOG_WARN("OnEnable of Example Layer not yet implemented.");

	float vertices[3 * 3] = {
		 0.0f,  0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
	};

	m_VAB = KMG::VertextArrayBuffer(&vertices, sizeof(vertices), 3, GL_FLOAT, 3 * sizeof(float));

	m_Shader = KMG::Shader("assets/shaders/Vertex.glsl", "assets/shaders/Fragment.glsl");
}

void ExampleLayer::OnDisable()
{
	KMG_LOG_WARN("OnDisable of Example Layer not yet implemented.");
}

void ExampleLayer::OnUpdate(double deltaTime)
{
	m_Shader.Bind();
	m_Shader.SetUniform3f("aPosition", .5f, .5f, 0.0f);
	m_Shader.SetUniform4f("aColor", 0.0f, 1.0f, 0.0f, 1.0f);

	m_VAB.Bind();
	glDrawArrays(GL_TRIANGLES, 0, 3);
	m_VAB.Unbind();

	//m_Shader.Unbind();
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
