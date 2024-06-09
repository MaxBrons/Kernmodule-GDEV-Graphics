#pragma once
#include "Core/Core.h"
#include "KMG.h"

class ExampleLayer : public KMG::ApplicationLayer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	void OnEnable() override;
	void OnDisable() override;
	void OnUpdate(double dt) override;
	void OnEvent(KMG::Event& e) override;
private:
	bool OnKey(KMG::KeyEvent& e);
	bool OnMouseButtonPressed(KMG::MouseButtonPressedEvent& e);
	void SetupTerrain();
	void SetupBackpack();
	void SetUniformWorldData(const KMG::s_ptr<KMG::Shader>& shader);
	void SetUniformFogColor(const KMG::s_ptr<KMG::Shader>& shader);
private:
	KMG::CameraController3D m_CameraController;

	KMG::s_ptr<KMG::VertexArray> m_CubeVertexArray;
	KMG::s_ptr<KMG::Shader> m_CrateShader;
	KMG::s_ptr<KMG::Shader> m_FlatColorShader;
	KMG::s_ptr<KMG::Shader> m_SkyboxShader;

	glm::vec3 m_TerrainSize;
	KMG::s_ptr<KMG::VertexArray> m_TerrainVertexArray;
	KMG::s_ptr<KMG::Shader> m_TerrainShader;
	KMG::s_ptr<KMG::Texture> m_CrateAlbedoTexture;
	KMG::s_ptr<KMG::Texture> m_CrateNormalTexture;
	KMG::s_ptr<KMG::Texture> m_TerrainHeightmapTexture;
	KMG::s_ptr<KMG::Texture> m_TerrainNormalTexture;
	KMG::s_ptr<KMG::Texture> m_TerrainDirtTexture;
	KMG::s_ptr<KMG::Texture> m_TerrainGrassTexture;
	KMG::s_ptr<KMG::Texture> m_TerrainRockTexture;
	KMG::s_ptr<KMG::Texture> m_TerrainSandTexture;
	KMG::s_ptr<KMG::Texture> m_TerrainSnowTexture;

	KMG::s_ptr<Model> m_BackpackModel;
	KMG::s_ptr<KMG::Shader> m_BackpackShader;

	glm::vec3 m_LightDirection = glm::vec3(1.0f, 1.0f, 0.0f);
	glm::vec3 m_LightColor = glm::vec3(1.0f);
	glm::vec3 m_FogColorTop = glm::vec3(68.0f / 255.0f, 118.0f / 255.0f, 189.0f / 255.0f);
	glm::vec3 m_FogColorBottom = glm::vec3(188.0f / 255.0f, 214.0f / 255.0f, 231.0f / 255.0f);

	float m_SunAngle = 0.0f, m_SunHeight = 0.0f;
};