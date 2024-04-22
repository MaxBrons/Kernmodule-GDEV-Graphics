#pragma once
#include "KMG.h"

class ExampleLayer : public KMG::ApplicationLayer
{
public:
	ExampleLayer() = default;
	virtual ~ExampleLayer() = default;

	void OnEnable() override;
	void OnUpdate(double deltaTime) override;
	void OnDisable() override;
};