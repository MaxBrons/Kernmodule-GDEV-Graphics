#include "corepch.h"
#include "CameraController2D.h"

#include <GLFW/glfw3.h>

namespace KMG
{
	CameraController2D::CameraController2D(float aspectRatio, float movementSpeed, float rotationSpeed)
		:m_AspectRatio(aspectRatio), m_Camera(-aspectRatio * m_ZoomLevel, aspectRatio* m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel), m_MovementSpeed(movementSpeed), m_RotationSpeed(rotationSpeed)
	{
	}

	void CameraController2D::OnUpdate(double dt)
	{
		float radians = glm::radians(m_CameraRotation);
		float sin = std::sin(radians) * m_MovementSpeed * static_cast<float>(dt);
		float cos = std::cos(radians) * m_MovementSpeed * static_cast<float>(dt);

		if (Input::GetKeyDown(Key::A))
		{
			m_CameraPosition.x -= cos;
			m_CameraPosition.y -= sin;
		}

		if (Input::GetKeyDown(Key::D))
		{
			m_CameraPosition.x += cos;
			m_CameraPosition.y += sin;
		}

		if (Input::GetKeyDown(Key::S))
		{
			m_CameraPosition.x += -sin;
			m_CameraPosition.y += cos;
		}

		if (Input::GetKeyDown(Key::W))
		{
			m_CameraPosition.x -= -sin;
			m_CameraPosition.y -= cos;
		}

		if (Input::GetKeyDown(Key::Q))
			m_CameraRotation += m_RotationSpeed * static_cast<float>(dt);
		if (Input::GetKeyDown(Key::E))
			m_CameraRotation -= m_RotationSpeed * static_cast<float>(dt);

		if (m_CameraRotation > 180.0f)
			m_CameraRotation -= 360.0f;
		else if (m_CameraRotation <= -180.0f)
			m_CameraRotation += 360.0f;

		m_Camera.SetRotation(m_CameraRotation);
		m_Camera.SetPosition(m_CameraPosition);
	}

	void CameraController2D::OnEvent(Event& e)
	{
		EventDispatcher::Dispatch<WindowResizeEvent>(e, CREATE_EVENT_FN_REF(OnWindowResized));
		EventDispatcher::Dispatch<MouseScrolledEvent>(e, CREATE_EVENT_FN_REF(OnMouseScrolled));
	}

	void CameraController2D::SetAspectRatio(uint32_t width, uint32_t height)
	{
		m_AspectRatio = width / (float)height;
		m_Camera.UpdateProjectionMatrix(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
	}

	void CameraController2D::Zoom(float zoomLevel)
	{
		m_ZoomLevel = std::max<float>(zoomLevel, 0.25f);
		m_Camera.UpdateProjectionMatrix(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
	}

	bool CameraController2D::OnWindowResized(WindowResizeEvent& e)
	{
		SetAspectRatio(e.Width, e.Height);
		m_Camera.UpdateProjectionMatrix(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}

	bool CameraController2D::OnMouseScrolled(MouseScrolledEvent& e)
	{
		Zoom(m_ZoomLevel - (e.YOffset * 0.25f));
		return false;
	}
}
