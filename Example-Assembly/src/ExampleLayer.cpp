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
	float vertices[] = {
		// positions            //colors            // tex coords   // normals          //tangents      //bitangents
		0.5f, -0.5f, -0.5f,     1.0f, 1.0f, 1.0f,   1.f, 1.f,       0.f, -1.f, 0.f,     -1.f, 0.f, 0.f,  0.f, 0.f, 1.f,
		0.5f, -0.5f, 0.5f,      1.0f, 1.0f, 1.0f,   1.f, 0.f,       0.f, -1.f, 0.f,     -1.f, 0.f, 0.f,  0.f, 0.f, 1.f,

		-0.5f, -0.5f, 0.5f,     1.0f, 1.0f, 1.0f,   0.f, 0.f,       0.f, -1.f, 0.f,     -1.f, 0.f, 0.f,  0.f, 0.f, 1.f,
		-0.5f, -0.5f, -.5f,     1.0f, 1.0f, 1.0f,   0.f, 1.f,       0.f, -1.f, 0.f,     -1.f, 0.f, 0.f,  0.f, 0.f, 1.f,

		0.5f, 0.5f, -0.5f,      1.0f, 1.0f, 1.0f,   1.f, 1.f,       1.f, 0.f, 0.f,     0.f, -1.f, 0.f,  0.f, 0.f, 1.f,
		0.5f, 0.5f, 0.5f,       1.0f, 1.0f, 1.0f,   1.f, 0.f,       1.f, 0.f, 0.f,     0.f, -1.f, 0.f,  0.f, 0.f, 1.f,

		0.5f, 0.5f, 0.5f,       1.0f, 1.0f, 1.0f,   1.f, 0.f,       0.f, 0.f, 1.f,     1.f, 0.f, 0.f,  0.f, -1.f, 0.f,
		-0.5f, 0.5f, 0.5f,      1.0f, 1.0f, 1.0f,   0.f, 0.f,       0.f, 0.f, 1.f,     1.f, 0.f, 0.f,  0.f, -1.f, 0.f,

		-0.5f, 0.5f, 0.5f,      1.0f, 1.0f, 1.0f,   0.f, 0.f,      -1.f, 0.f, 0.f,     0.f, 1.f, 0.f,  0.f, 0.f, 1.f,
		-0.5f, 0.5f, -.5f,      1.0f, 1.0f, 1.0f,   0.f, 1.f,      -1.f, 0.f, 0.f,     0.f, 1.f, 0.f,  0.f, 0.f, 1.f,

		-0.5f, 0.5f, -.5f,      1.0f, 1.0f, 1.0f,   0.f, 1.f,      0.f, 0.f, -1.f,     1.f, 0.f, 0.f,  0.f, 1.f, 0.f,
		0.5f, 0.5f, -0.5f,      1.0f, 1.0f, 1.0f,   1.f, 1.f,      0.f, 0.f, -1.f,     1.f, 0.f, 0.f,  0.f, 1.f, 0.f,

		-0.5f, 0.5f, -.5f,      1.0f, 1.0f, 1.0f,   1.f, 1.f,       0.f, 1.f, 0.f,     1.f, 0.f, 0.f,  0.f, 0.f, 1.f,
		-0.5f, 0.5f, 0.5f,      1.0f, 1.0f, 1.0f,   1.f, 0.f,       0.f, 1.f, 0.f,     1.f, 0.f, 0.f,  0.f, 0.f, 1.f,

		0.5f, -0.5f, 0.5f,      1.0f, 1.0f, 1.0f,   1.f, 1.f,       0.f, 0.f, 1.f,     1.f, 0.f, 0.f,  0.f, -1.f, 0.f,
		-0.5f, -0.5f, 0.5f,     1.0f, 1.0f, 1.0f,   0.f, 1.f,       0.f, 0.f, 1.f,     1.f, 0.f, 0.f,  0.f, -1.f, 0.f,

		-0.5f, -0.5f, 0.5f,     1.0f, 1.0f, 1.0f,   1.f, 0.f,       -1.f, 0.f, 0.f,     0.f, 1.f, 0.f,  0.f, 0.f, 1.f,
		-0.5f, -0.5f, -.5f,     1.0f, 1.0f, 1.0f,   1.f, 1.f,       -1.f, 0.f, 0.f,     0.f, 1.f, 0.f,  0.f, 0.f, 1.f,

		-0.5f, -0.5f, -.5f,     1.0f, 1.0f, 1.0f,   0.f, 0.f,       0.f, 0.f, -1.f,     1.f, 0.f, 0.f,  0.f, 1.f, 0.f,
		0.5f, -0.5f, -0.5f,     1.0f, 1.0f, 1.0f,   1.f, 0.f,       0.f, 0.f, -1.f,     1.f, 0.f, 0.f,  0.f, 1.f, 0.f,

		0.5f, -0.5f, -0.5f,     1.0f, 1.0f, 1.0f,   0.f, 1.f,       1.f, 0.f, 0.f,     0.f, -1.f, 0.f,  0.f, 0.f, 1.f,
		0.5f, -0.5f, 0.5f,      1.0f, 1.0f, 1.0f,   0.f, 0.f,       1.f, 0.f, 0.f,     0.f, -1.f, 0.f,  0.f, 0.f, 1.f,

		0.5f, 0.5f, -0.5f,      1.0f, 1.0f, 1.0f,   0.f, 1.f,       0.f, 1.f, 0.f,     1.f, 0.f, 0.f,  0.f, 0.f, 1.f,
		0.5f, 0.5f, 0.5f,       1.0f, 1.0f, 1.0f,   0.f, 0.f,       0.f, 1.f, 0.f,     1.f, 0.f, 0.f,  0.f, 0.f, 1.f
	};

	auto vertexBuffer = KMG::VertexBuffer::Create(vertices, sizeof(vertices));
	vertexBuffer->AddLayout(KMG::BufferLayout("a_Position", KMG::LayoutType::Float3, false));
	vertexBuffer->AddLayout(KMG::BufferLayout("a_Color", KMG::LayoutType::Float3, false));
	vertexBuffer->AddLayout(KMG::BufferLayout("a_UV", KMG::LayoutType::Float2, false));
	vertexBuffer->AddLayout(KMG::BufferLayout("a_Normal", KMG::LayoutType::Float3, false));
	vertexBuffer->AddLayout(KMG::BufferLayout("a_Tangent", KMG::LayoutType::Float3, false));
	vertexBuffer->AddLayout(KMG::BufferLayout("a_Bitangent", KMG::LayoutType::Float3, false));
	
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

	auto indexBuffer = KMG::IndexBuffer::Create(indices, sizeof(indices));

	// Reuse this box for the light and crate.
	m_BoxVertexArray = KMG::VertexArray::Create();
	m_BoxVertexArray->AddVertexBuffer(vertexBuffer);
	m_BoxVertexArray->SetIndexBuffer(indexBuffer);

	// ----- Crate ----- //
	m_CrateShader = KMG::Shader("assets/shaders/Box-Vertex.glsl", "assets/shaders/Box-Fragment.glsl");
	m_MainTexture = KMG::Texture::Create("assets/textures/Box_Albedo.png");
	m_NormalTexture = KMG::Texture::Create("assets/textures/Box_Normal.png");

	// ----- Light ----- //
	m_FlatColorShader = KMG::Shader("assets/shaders/FlatColor-Vert.glsl", "assets/shaders/FlatColor-Frag.glsl");
	m_LightPosition = glm::vec3(-3.0f, 1.0f, 3);

	// ----- Skybox ------ //
	m_SkyboxShader = KMG::Shader("assets/shaders/Skybox-Vertex.glsl", "assets/shaders/Skybox-Fragment.glsl");

	// ----- Rendering ----- //
	m_CameraController.GetCamera().Move({ 0.0f, 1.0f, -2.0f });

	KMG::Cursor::SetCursorVisible(false);
	KMG::Renderer::Initialize();
}

void ExampleLayer::OnDisable()
{
	KMG_LOG_WARN("OnDisable of Example Layer not yet implemented.");
}

void ExampleLayer::OnUpdate(double dt)
{
	// Update camera movement.
	m_CameraController.OnUpdate(dt);

	// Clear the screen.
	KMG::Renderer::SetClearColor({ 0.0f, 0.0f, 0.0f, 1.0f });
	KMG::Renderer::Clear();

	// Calculate a random color or use the active static light color.
	float time = static_cast<float>(glfwGetTime());
	float sin = std::sinf(time) / 2 + 0.5f;
	float cos = std::cosf(time) / 2 + 0.5f;
	float tan = std::atan(time) / 2 + 0.5f;
	glm::vec3 lightColor = m_RandomLightColour ? glm::normalize(glm::vec3(sin, cos, tan)) : m_LightColour;

	// ----- Render Skybox ----- //
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);

	glm::mat4 skyboxTransform = glm::translate(glm::mat4(1.0f), m_CameraController.GetCamera().GetPosition());
	skyboxTransform = glm::scale(skyboxTransform, glm::vec3(10.0f, 10.0f, 10.0f));

	m_SkyboxShader.Bind();
	m_SkyboxShader.SetMat4("u_ViewProjection", m_CameraController.GetCamera().GetViewProjectionMatrix());
	m_SkyboxShader.SetMat4("u_Transform", skyboxTransform);
	m_SkyboxShader.SetFloat3("u_LightDirection", glm::normalize(m_LightPosition));
	m_SkyboxShader.SetFloat3("u_CameraPosition", m_CameraController.GetCamera().GetPosition());

	KMG::Renderer::DrawIndexed(m_BoxVertexArray, m_BoxVertexArray->GetIndexBuffer()->GetCount());

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	// ----- Render Crate (box) ----- //
	glm::mat4 crateTransform = glm::rotate(glm::mat4(1.0f), glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	m_CrateShader.Bind();
	m_MainTexture->Bind(0);
	m_NormalTexture->Bind(1);

	m_CrateShader.SetMat4("u_ViewProjection", m_CameraController.GetCamera().GetViewProjectionMatrix());
	m_CrateShader.SetMat4("u_Transform", crateTransform);
	m_CrateShader.SetFloat3("u_LightPosition", m_LightPosition);
	m_CrateShader.SetFloat3("u_CameraPosition", m_CameraController.GetCamera().GetPosition());
	m_CrateShader.SetFloat3("u_LightColor", lightColor);

	KMG::Renderer::DrawIndexed(m_BoxVertexArray, m_BoxVertexArray->GetIndexBuffer()->GetCount());

	// ----- Render Light (box) ----- //
	glm::mat4 lightTransform = glm::translate(glm::mat4(1.0f), m_LightPosition);
	lightTransform = glm::scale(lightTransform, glm::vec3(0.5f));

	m_FlatColorShader.Bind();
	m_FlatColorShader.SetMat4("u_ViewProjection", m_CameraController.GetCamera().GetViewProjectionMatrix());
	m_FlatColorShader.SetMat4("u_Transform", lightTransform);
	m_FlatColorShader.SetFloat3("u_Color", lightColor != glm::vec3() ? lightColor : glm::vec3(0.75f));

	KMG::Renderer::DrawIndexed(m_BoxVertexArray, m_BoxVertexArray->GetIndexBuffer()->GetCount());
}

void ExampleLayer::OnEvent(KMG::Event& e)
{
	KMG::EventDispatcher::Dispatch<KMG::WindowResizeEvent>(e, CREATE_EVENT_FN_REF(OnWindowResized));
	KMG::EventDispatcher::Dispatch<KMG::KeyEvent>(e, CREATE_EVENT_FN_REF(OnKey));
	KMG::EventDispatcher::Dispatch<KMG::MouseButtonPressedEvent>(e, CREATE_EVENT_FN_REF(OnMouseButtonPressed));

	m_CameraController.OnEvent(e);
}

bool ExampleLayer::OnWindowResized(KMG::WindowResizeEvent& e)
{
	m_Width = e.Width;
	m_Height = e.Height;

	glViewport(0, 0, m_Width, m_Height);

	return true;
}

bool ExampleLayer::OnKey(KMG::KeyEvent& e)
{
	if (e.Action == GLFW_RELEASE)
		return false;

	// Move the light around.
	switch (e.Key)
	{
		case KMG::Key::Left: m_LightPosition -= glm::vec3(1.0f, 0.0f, 0.0f); break;
		case KMG::Key::Right: m_LightPosition += glm::vec3(1.0f, 0.0f, 0.0f); break;
		case KMG::Key::Up: m_LightPosition += glm::vec3(0.0f, 0.0f, 1.0f); break;
		case KMG::Key::Down: m_LightPosition -= glm::vec3(0.0f, 0.0f, 1.0f); break;
	}

	// Switch between random light color.
	if (e.Key == KMG::Key::Num5)
		m_RandomLightColour = !m_RandomLightColour;

	// Set the light color to red, green or blue.
	if (!m_RandomLightColour)
	{
		switch (e.Key)
		{
			case KMG::Key::Num1: m_LightColour = { 1.0f, 0.0f, 0.0f }; break;
			case KMG::Key::Num2: m_LightColour = { 0.0f, 1.0f, 0.0f }; break;
			case KMG::Key::Num3: m_LightColour = { 0.0f, 0.0f, 1.0f }; break;
			case KMG::Key::Num4: m_LightColour = { 1.0f, 1.0f, 1.0f }; break;
		}
	}

	// Show the cursor again when pressing escape.
	if (e.Key == KMG::Key::Escape)
		KMG::Cursor::SetCursorVisible(true);

	return true;
}

bool ExampleLayer::OnMouseButtonPressed(KMG::MouseButtonPressedEvent& e)
{
	if (e.Button != KMG::Mouse::ButtonLeft)
		return false;

	// Hide the cursor again when focussing on the window again.
	if (KMG::Cursor::GetCursorVisible())
		KMG::Cursor::SetCursorVisible(false);

	return true;
}