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

	m_VAB = KMG::VertextArrayBuffer(&vertices, sizeof(vertices), 0, 3, GL_FLOAT, 3 * sizeof(float));

	/*GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, 0x00, nullptr);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, 0x00, nullptr);
	glCompileShader(fragmentShader);

	GLint success;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	KMG_CORE_VALIDATE(success, "CORE::SHADER: Failed to compile vertex shader");*/
}

void ExampleLayer::OnDisable()
{
	KMG_LOG_WARN("OnDisable of Example Layer not yet implemented.");
}

void ExampleLayer::OnUpdate(double deltaTime)
{
	m_VAB.Bind();
	glDrawArrays(GL_TRIANGLES, 0, 3);
	m_VAB.Unbind();
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
