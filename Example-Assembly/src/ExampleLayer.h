#pragma once
#include "Core/Core.h"
#include "KMG.h"

class ExampleLayer : public KMG::ApplicationLayer
{
public:
	ExampleLayer() = default;
	virtual ~ExampleLayer() = default;

	void OnEnable() override;
	void OnDisable() override;
	void OnUpdate(double deltaTime) override;
	void OnEvent(KMG::Event& e) override;
private:
	KMG::s_ptr<KMG::VertexArray> m_VertexArray;
	KMG::Shader m_Shader;
	uint32_t m_Width, m_Height;
};