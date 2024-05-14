#include "ExampleLayer.h"
#include "Core/Base/Input.h"

#include <glfw/include/GLFW/glfw3.h> // Temp, for easy testing; TODO: Abstract out glfw code to Core.

ExampleLayer::ExampleLayer()
	:m_Width(1280), m_Height(720), m_CameraController(60.0f, m_Width / (float)m_Height, 0.1f, 1000.0f, 1.0f, 5.0f)
{
}

//static GLuint VBO, VAO, EBO;
void ExampleLayer::OnEnable()
{
	//KMG_LOG_WARN("OnEnable of Example Layer not yet implemented.");
	m_VertexArray = KMG::VertexArray::Create();

	float vertices[] = {
		// positions            //colors            // tex coords   // normals
		0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,   1.f, 0.f,       0.f, -1.f, 0.f,
		0.5f, -0.5f, 0.5f,   1.0f, 1.0f, 1.0f,   1.f, 1.f,       0.f, -1.f, 0.f,
		-0.5f, -0.5f, 0.5f,  1.0f, 1.0f, 1.0f,   0.f, 1.f,       0.f, -1.f, 0.f,
		-0.5f, -0.5f, -.5f,  1.0f, 1.0f, 1.0f,   0.f, 0.f,       0.f, -1.f, 0.f,

		0.5f, 0.5f, -0.5f,   1.0f, 1.0f, 1.0f,   2.f, 0.f,       1.f, 0.f, 0.f,
		0.5f, 0.5f, 0.5f,    1.0f, 1.0f, 1.0f,   2.f, 1.f,       1.f, 0.f, 0.f,

		0.5f, 0.5f, 0.5f,    1.0f, 1.0f, 1.0f,   1.f, 2.f,       0.f, 0.f, 1.f,
		-0.5f, 0.5f, 0.5f,   1.0f, 1.0f, 1.0f,   0.f, 2.f,       0.f, 0.f, 1.f,

		-0.5f, 0.5f, 0.5f,   1.0f, 1.0f, 1.0f,   -1.f, 1.f,      -1.f, 0.f, 0.f,
		-0.5f, 0.5f, -.5f,   1.0f, 1.0f, 1.0f,   -1.f, 0.f,      -1.f, 0.f, 0.f,

		-0.5f, 0.5f, -.5f,   1.0f, 1.0f, 1.0f,   0.f, -1.f,      0.f, 0.f, -1.f,
		0.5f, 0.5f, -0.5f,   1.0f, 1.0f, 1.0f,   1.f, -1.f,      0.f, 0.f, -1.f,

		-0.5f, 0.5f, -.5f,   1.0f, 1.0f, 1.0f,   3.f, 0.f,       0.f, 1.f, 0.f,
		-0.5f, 0.5f, 0.5f,   1.0f, 1.0f, 1.0f,   3.f, 1.f,       0.f, 1.f, 0.f,

		0.5f, -0.5f, 0.5f,   1.0f, 1.0f, 1.0f,   1.f, 1.f,       0.f, 0.f, 1.f,
		-0.5f, -0.5f, 0.5f,  1.0f, 1.0f, 1.0f,   0.f, 1.f,       0.f, 0.f, 1.f,

		-0.5f, -0.5f, 0.5f,  1.0f, 1.0f, 1.0f,   0.f, 1.f,       -1.f, 0.f, 0.f,
		-0.5f, -0.5f, -.5f,  1.0f, 1.0f, 1.0f,   0.f, 0.f,       -1.f, 0.f, 0.f,

		-0.5f, -0.5f, -.5f,  1.0f, 1.0f, 1.0f,   0.f, 0.f,       0.f, 0.f, -1.f,
		0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,   1.f, 0.f,       0.f, 0.f, -1.f,

		0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,   1.f, 0.f,       1.f, 0.f, 0.f,
		0.5f, -0.5f, 0.5f,   1.0f, 1.0f, 1.0f,   1.f, 1.f,       1.f, 0.f, 0.f,

		0.5f, 0.5f, -0.5f,   1.0f, 1.0f, 1.0f,   2.f, 0.f,       0.f, 1.f, 0.f,
		0.5f, 0.5f, 0.5f,    1.0f, 1.0f, 1.0f,   2.f, 1.f,       0.f, 1.f, 0.f
	};

	auto vertexBuffer = KMG::VertexBuffer::Create(vertices, sizeof(vertices));
	vertexBuffer->AddLayout(KMG::BufferLayout("aPosition", KMG::LayoutType::Float3, false));
	vertexBuffer->AddLayout(KMG::BufferLayout("acolor", KMG::LayoutType::Float3, false));
	vertexBuffer->AddLayout(KMG::BufferLayout("aTexCoords", KMG::LayoutType::Float2, false));
	vertexBuffer->AddLayout(KMG::BufferLayout("aNormals", KMG::LayoutType::Float3, false));
	m_VertexArray->AddVertexBuffer(vertexBuffer);

	uint32_t indices[] = {
		// DOWN
		0, 1, 2,   // first triangle
		0, 2, 3,    // second triangle
		// BACK
		14, 6, 7,   // first triangle
		14, 7, 15,    // second triangle
		// RIGHT
		20, 4, 5,   // first triangle
		20, 5, 21,    // second triangle
		// LEFT
		16, 8, 9,   // first triangle
		16, 9, 17,    // second triangle
		// FRONT
		18, 10, 11,   // first triangle
		18, 11, 19,    // second triangle
		// UP
		22, 12, 13,   // first triangle
		22, 13, 23,    // second triangle
	};

	m_VertexArray->Bind();
	auto indexBuffer = KMG::IndexBuffer::Create(indices, sizeof(indices));
	m_VertexArray->SetIndexBuffer(indexBuffer);

	m_Shader = KMG::Shader("assets/shaders/Vertex.glsl", "assets/shaders/Fragment.glsl");

	glEnable(GL_DEPTH | GL_CULL_FACE);
	glCullFace(GL_BACK);
}

void ExampleLayer::OnDisable()
{
	KMG_LOG_WARN("OnDisable of Example Layer not yet implemented.");
}

void ExampleLayer::OnUpdate(double dt)
{
	m_CameraController.OnUpdate(dt);

	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::mat4 cubeTransform = glm::rotate(glm::mat4(1.0f), glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	m_Shader.Bind();
	m_Shader.SetMat4("u_ViewProjection", m_CameraController.GetCamera().GetViewProjectionMatrix());
	m_Shader.SetMat4("u_Transform", cubeTransform);
	m_Shader.SetFloat4("u_Color", glm::vec4(1.0f));

	m_VertexArray->Bind();
	glDrawElements(GL_TRIANGLES, m_VertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, 0);
}

void ExampleLayer::OnEvent(KMG::Event& e)
{
	KMG::EventDispatcher::Dispatch<KMG::WindowResizeEvent>(e, CREATE_EVENT_FN_REF(OnWindowResized));

	m_CameraController.OnEvent(e);
}

bool ExampleLayer::OnWindowResized(KMG::WindowResizeEvent& e)
{
	m_Width = e.Width;
	m_Height = e.Height;

	glViewport(0, 0, m_Width, m_Height);

	return true;
}
