#pragma once
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
	KMG::VertextArrayBuffer m_VAB;
	GLuint v, b;
};