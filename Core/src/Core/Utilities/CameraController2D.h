#pragma once
#include "Core.h"
#include "Rendering/Camera2D.h"
#include "Events/Event.h"
#include "Base/Input.h"

namespace KMG
{
	class CameraController2D
	{
	public:
		CameraController2D() = default;
		CameraController2D(float aspectRatio, float movementSpeed, float rotationSpeed);
		virtual ~CameraController2D() = default;

		void OnUpdate(double dt);
		void OnEvent(Event& e);

		void SetAspectRatio(uint32_t width, uint32_t height);
		Camera2D& GetCamera() { return m_Camera; }

		float GetZoomLevel() const { return m_ZoomLevel; }
		void Zoom(float zoomLevel);
	private:
		bool OnWindowResized(WindowResizeEvent& e);
		bool OnMouseScrolled(MouseScrolledEvent& e);
	private:
		Camera2D m_Camera;
		float m_AspectRatio;
		float m_ZoomLevel = 1.0f;
		glm::vec3 m_CameraPosition = glm::vec3(0.0f);
		float m_CameraRotation = 0.0f;
		float m_MovementSpeed = 1.0f;
		float m_RotationSpeed = 1.0f;
	};
}
