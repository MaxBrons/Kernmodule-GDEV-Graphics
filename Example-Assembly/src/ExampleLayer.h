#pragma once
#include "Core/Core.h"
#include "KMG.h"
#include "Base/model.h"

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
	bool OnWindowResized(KMG::WindowResizeEvent& e);
	bool OnKey(KMG::KeyEvent& e);
	bool OnMouseButtonPressed(KMG::MouseButtonPressedEvent& e);
	void SetupTerrain();
private:
	KMG::s_ptr<KMG::VertexArray> m_BoxVertexArray;
	KMG::s_ptr<KMG::VertexArray> m_TerrainVertexArray;
	KMG::Shader m_CrateShader, m_FlatColorShader, m_SkyboxShader;
	KMG::Shader m_TerrainShader;
	KMG::CameraController3D m_CameraController;
	uint32_t m_Width, m_Height;
	glm::vec3 m_TerrainSize;

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

	glm::vec3 m_LightDirection = glm::vec3(1.0f, 1.0f, 0.0f);
	glm::vec3 m_LightColour = glm::vec3(1.0f);
	bool m_RandomLightColour = false;
};