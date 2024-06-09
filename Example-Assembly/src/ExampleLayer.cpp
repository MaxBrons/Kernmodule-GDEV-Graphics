#include "ExampleLayer.h"
#include "Core/Base/Input.h"
#include "Base/Time.h"

ExampleLayer::ExampleLayer()
	:m_Width(1280), m_Height(720), m_CameraController(60.0f, 1280.0f / 720.0f, 0.1f, 1000.0f, 5.0f, 15.0f)
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
	m_CrateAlbedoTexture = KMG::Texture::Create("assets/textures/Box_Albedo.png");
	m_CrateNormalTexture = KMG::Texture::Create("assets/textures/Box_Normal.png");

	// ----- Light ----- //
	m_FlatColorShader = KMG::Shader("assets/shaders/FlatColor-Vert.glsl", "assets/shaders/FlatColor-Frag.glsl");
	m_LightDirection = glm::vec3(-3.0f, 1.0f, 3);

	// ----- Skybox ------ //
	m_SkyboxShader = KMG::Shader("assets/shaders/Skybox-Vertex.glsl", "assets/shaders/Skybox-Fragment.glsl");

	// ----- Rendering ----- //
	m_CameraController.GetCamera().Move({ 0.0f, 1.0f, -2.0f });

	SetupTerrain();

	KMG::Cursor::SetCursorVisible(false);
	KMG::Renderer::Initialize();
}

void ExampleLayer::SetupTerrain()
{
	m_TerrainSize = glm::vec3(5.0f, 500.0f, 5.0f);
	m_TerrainHeightmapTexture = KMG::Texture::Create("assets/textures/Terrain_Heightmap.png", 4);
	m_TerrainNormalTexture = KMG::Texture::Create("assets/textures/Terrain_Normal.png", 4);
	m_TerrainDirtTexture = KMG::Texture::Create("assets/textures/Terrain_Dirt.jpg", 4);
	m_TerrainGrassTexture = KMG::Texture::Create("assets/textures/Terrain_Grass.png", 4);
	m_TerrainRockTexture = KMG::Texture::Create("assets/textures/Terrain_Rock.jpg", 4);
	m_TerrainSandTexture = KMG::Texture::Create("assets/textures/Terrain_Sand.jpg", 4);
	m_TerrainSnowTexture = KMG::Texture::Create("assets/textures/Terrain_Snow.jpg", 4);

	m_BackpackModel = KMG::MakeShared<Model>("assets/models/backpack/backpack.obj");

	uint32_t width = m_TerrainHeightmapTexture->GetWidth();
	uint32_t height = m_TerrainHeightmapTexture->GetHeight();

	int stride = 8;
	float* vertices = new float[(width * height) * stride];
	uint32_t* indices = new uint32_t[(width - 1) * (height - 1) * 6];

	{
		int index = 0;
		for (uint32_t i = 0; i < (width * height); i++)
		{
			// TODO: calculate x/z values
			uint32_t x = i % width;
			uint32_t z = i / width;

			float texHeight = (float)m_TerrainHeightmapTexture->GetData()[i * m_TerrainHeightmapTexture->GetChannelCount()];

			// TODO: set position
			vertices[index++] = x * m_TerrainSize.x;
			vertices[index++] = texHeight / 255.0f * m_TerrainSize.y;
			vertices[index++] = z * m_TerrainSize.z;
			// TODO: set normal
			vertices[index++] = 0;
			vertices[index++] = 1;
			vertices[index++] = 0;
			// TODO: set uv
			vertices[index++] = x / (float)width;
			vertices[index++] = z / (float)height;
		}
	}

	// OPTIONAL TODO: Calculate normal
	// TODO: Set normal

	{
		uint32_t index = 0;
		for (uint32_t i = 0; i < (width - 1) * (height - 1); i++)
		{
			uint32_t x = i % (width - 1);
			uint32_t z = i / (width - 1);

			uint32_t vertex = z * width + x;
			indices[index++] = vertex;
			indices[index++] = vertex + width;
			indices[index++] = vertex + width + 1;
			indices[index++] = vertex;
			indices[index++] = vertex + width + 1;
			indices[index++] = vertex + 1;
		}
	}

	m_TerrainVertexArray = KMG::VertexArray::Create();

	auto vertexBuffer = KMG::VertexBuffer::Create(vertices, (width * height) * stride * (uint32_t)sizeof(uint32_t));
	vertexBuffer->AddLayout(KMG::BufferLayout("a_Position", KMG::LayoutType::Float3, false));
	vertexBuffer->AddLayout(KMG::BufferLayout("a_Normal", KMG::LayoutType::Float3, false));
	vertexBuffer->AddLayout(KMG::BufferLayout("a_UV", KMG::LayoutType::Float2, false));

	auto indexBuffer = KMG::IndexBuffer::Create(indices, (width - 1) * (height - 1) * 6 * (uint32_t)sizeof(uint32_t));

	m_TerrainVertexArray->AddVertexBuffer(vertexBuffer);
	m_TerrainVertexArray->SetIndexBuffer(indexBuffer);

	m_TerrainShader = KMG::Shader("assets/shaders/Terrain-Vertex.glsl", "assets/shaders/Terrain-Fragment.glsl");

	delete[] vertices;
	delete[] indices;
}

void ExampleLayer::OnDisable()
{
	KMG_LOG_WARN("OnDisable of Example Layer not yet implemented.");
}

static float angle = 0, h = 0.5f;
void ExampleLayer::OnUpdate(double dt)
{
	// Update camera movement.
	m_CameraController.OnUpdate(dt);

	// Clear the screen.
	KMG::Renderer::SetClearColor({ 0.0f, 0.0f, 0.0f, 1.0f });
	KMG::Renderer::Clear();

	// Calculate a random color or use the active static light color.
	float time = (float)KMG::Time::GetTime();
	float sin = std::sinf(time) / 2 + 0.5f;
	float cos = std::cosf(time) / 2 + 0.5f;
	float tan = std::atan(time) / 2 + 0.5f;
	glm::vec3 lightColor = m_RandomLightColour ? glm::normalize(glm::vec3(sin, cos, tan)) : m_LightColour;

	// Auto rotate the light around world center point.
	m_LightDirection = glm::normalize(glm::vec3(glm::sin(angle), h, glm::cos(angle)));

	// ----- Render Skybox (box) ----- //
	glDisable(GL_DEPTH);
	glDisable(GL_CULL_FACE);

	glm::mat4 skyboxTransform = glm::translate(glm::mat4(1.0f), m_CameraController.GetCamera().GetPosition());
	skyboxTransform = glm::scale(skyboxTransform, glm::vec3(1000.0f, 1000.0f, 1000.0f));

	m_SkyboxShader.Bind();
	m_SkyboxShader.SetMat4("u_ViewProjection", m_CameraController.GetCamera().GetViewProjectionMatrix());
	m_SkyboxShader.SetMat4("u_Transform", skyboxTransform);
	m_SkyboxShader.SetFloat3("u_LightDirection", m_LightDirection);
	m_SkyboxShader.SetFloat3("u_CameraPosition", m_CameraController.GetCamera().GetPosition());

	KMG::Renderer::DrawIndexed(m_BoxVertexArray, m_BoxVertexArray->GetIndexBuffer()->GetCount());
	glEnable(GL_DEPTH);
	glEnable(GL_CULL_FACE);

	// ----- Render Crate (box) ----- //
	glm::mat4 crateTransform = glm::rotate(glm::mat4(1.0f), glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	m_CrateShader.Bind();
	m_CrateAlbedoTexture->Bind();
	m_CrateNormalTexture->Bind(1);

	m_CrateShader.SetMat4("u_ViewProjection", m_CameraController.GetCamera().GetViewProjectionMatrix());
	m_CrateShader.SetMat4("u_Transform", crateTransform);
	m_CrateShader.SetFloat3("u_LightDirection", m_LightDirection);
	m_CrateShader.SetFloat3("u_CameraPosition", m_CameraController.GetCamera().GetPosition());
	m_CrateShader.SetFloat3("u_LightColor", lightColor);

	KMG::Renderer::DrawIndexed(m_BoxVertexArray, m_BoxVertexArray->GetIndexBuffer()->GetCount());

	// ----- Render Light (box) ----- //
	glm::mat4 lightTransform = glm::translate(glm::mat4(1.0f), m_LightDirection * 2.0f);
	lightTransform = glm::scale(lightTransform, glm::vec3(0.5f));

	m_FlatColorShader.Bind();
	m_FlatColorShader.SetMat4("u_ViewProjection", m_CameraController.GetCamera().GetViewProjectionMatrix());
	m_FlatColorShader.SetMat4("u_Transform", lightTransform);
	m_FlatColorShader.SetFloat3("u_Color", lightColor != glm::vec3() ? lightColor : glm::vec3(0.75f));

	KMG::Renderer::DrawIndexed(m_BoxVertexArray, m_BoxVertexArray->GetIndexBuffer()->GetCount());

	// ----- Render Plane ----- //
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH);
	glEnable(GL_DEPTH_TEST);
	glCullFace(GL_BACK);

	glm::mat4 terrainTransform = glm::translate(glm::mat4(1), glm::vec3(0, 0, 0));
	terrainTransform = glm::scale(terrainTransform, glm::vec3(0.01f));

	m_TerrainShader.Bind();
	m_TerrainHeightmapTexture->Bind();
	m_TerrainNormalTexture->Bind(1);
	m_TerrainDirtTexture->Bind(2);
	m_TerrainGrassTexture->Bind(3);
	m_TerrainRockTexture->Bind(4);
	m_TerrainSandTexture->Bind(5);
	m_TerrainSnowTexture->Bind(6);

	m_TerrainShader.SetMat4("u_ViewProjection", m_CameraController.GetCamera().GetViewProjectionMatrix());
	m_TerrainShader.SetMat4("u_Transform", terrainTransform);
	m_TerrainShader.SetFloat3("u_LightDirection", m_LightDirection);
	m_TerrainShader.SetFloat3("u_CameraPosition", m_CameraController.GetCamera().GetPosition());
	m_TerrainShader.SetFloat("u_TerrainHeight", m_TerrainSize.y);
	m_TerrainShader.SetFloat("u_TextureSmoothing", 30.0f);

	KMG::Renderer::DrawIndexed(m_TerrainVertexArray, m_TerrainVertexArray->GetIndexBuffer()->GetCount());
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
	if (e.Action == KMG::Key::Released)
		return false;

	float dt = (float)KMG::Time::GetDeltaTime();
	switch (e.Key)
	{
		case KMG::Key::Right: angle += dt * 10.0f; break;
		case KMG::Key::Up: h += dt * 100.0f; break;
		case KMG::Key::Down: h -= dt * 100.0f; break;
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