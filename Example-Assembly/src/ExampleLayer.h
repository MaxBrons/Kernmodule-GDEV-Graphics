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
	bool OnWindowResized(KMG::WindowResizeEvent& e);
	bool OnKey(KMG::KeyEvent& e);
private:
	KMG::s_ptr<KMG::VertexArray> m_VertexArray;
	KMG::Shader m_BoxShader, m_FlatColorShader;
	KMG::CameraController3D m_CameraController;
	uint32_t m_Width, m_Height;

	KMG::s_ptr<KMG::Texture> m_MainTexture;
	KMG::s_ptr<KMG::Texture> m_NormalTexture;

	glm::vec3 m_LightPosition = {};
	glm::vec3 m_LightColour = {};
	bool m_RandomLightColour = false;
};