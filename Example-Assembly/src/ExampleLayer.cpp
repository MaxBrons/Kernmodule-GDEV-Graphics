#include "ExampleLayer.h"

#include <glfw/include/GLFW/glfw3.h> // Temp, for easy testing; TODO: Abstract out glfw code to Core.

//static GLuint VBO, VAO, EBO;
void ExampleLayer::OnEnable()
{
	//KMG_LOG_WARN("OnEnable of Example Layer not yet implemented.");
	m_VertexArray = KMG::VertexArray::Create();

	float vertices[] = {    
		-0.5f,  0.5f, 0.0f,	 0.0f, 1.0f, 0.0, 1.0f,
		-0.5f, -0.5f, 0.0f,	 0.0f, 1.0f, 0.0, 1.0f,
		 0.5f, -0.5f, 0.0f,	 0.0f, 1.0f, 0.0, 1.0f,
		 0.5f,  0.5f, 0.0f,	 0.0f, 1.0f, 0.0, 1.0f,
	};

	auto vertexBuffer = KMG::VertexBuffer::Create(vertices, sizeof(vertices));
	vertexBuffer->AddLayout(KMG::BufferLayout("aPosition", KMG::LayoutType::Float3, false));
	vertexBuffer->AddLayout(KMG::BufferLayout("aColor", KMG::LayoutType::Float4, false));
	m_VertexArray->AddVertexBuffer(vertexBuffer);

	uint32_t indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	m_VertexArray->Bind();
	auto indexBuffer = KMG::IndexBuffer::Create(indices, sizeof(indices));
	m_VertexArray->SetIndexBuffer(indexBuffer);

	m_Shader = KMG::Shader("assets/shaders/Vertex.glsl", "assets/shaders/Fragment.glsl");
}

void ExampleLayer::OnDisable()
{
	KMG_LOG_WARN("OnDisable of Example Layer not yet implemented.");
}

void ExampleLayer::OnUpdate(double deltaTime)
{
	m_Shader.Bind();
	//m_Shader.SetUniform4f("aColor", 1.0f, 0.0f, 0.0f, 1.0f);

	m_VertexArray->Bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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
