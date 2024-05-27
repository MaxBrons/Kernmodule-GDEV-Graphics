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
private:
	KMG::s_ptr<KMG::VertexArray> m_VertexArray;
	KMG::Shader m_Shader;
	KMG::CameraController3D m_CameraController;
	uint32_t m_Width, m_Height;
	KMG::s_ptr<KMG::Texture> m_MainTexture;
	glm::vec3 m_LightPosition = glm::vec3();
};