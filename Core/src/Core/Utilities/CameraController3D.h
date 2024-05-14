#pragma once
#include "Core.h"
#include "Rendering/Camera3D.h"
#include "Events/Event.h"
#include "Base/Input.h"

namespace KMG
{
	class CameraController3D
	{
	public:
		CameraController3D() = default;
		CameraController3D(float fov, float aspectRatio, float nearClip, float farClip, float movementSpeed, float rotationSpeed);
		virtual ~CameraController3D() = default;

		void OnUpdate(double dt);
		void OnEvent(Event& e);

		Camera3D& GetCamera() { return m_Camera; }
	private:
		bool OnWindowResized(WindowResizeEvent& e);
		bool OnMouseScrolled(MouseScrolledEvent& e);
	private:
		Camera3D m_Camera;
		glm::vec2 m_PreviousMousePosition;
		float m_MovementSpeed = 1.0f;
		float m_RotationSpeed = 1.0f;
		float m_ZoomLevel = 1.0f;
	};
}
