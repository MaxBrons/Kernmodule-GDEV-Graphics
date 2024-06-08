#include "corepch.h"
#include "CameraController3D.h"

#include <GLFW/glfw3.h>

namespace KMG
{
	CameraController3D::CameraController3D(float fov, float aspectRatio, float nearClip, float farClip, float movementSpeed, float rotationSpeed)
		:m_Camera(fov, aspectRatio, nearClip, farClip), m_MovementSpeed(movementSpeed), m_RotationSpeed(rotationSpeed)
	{
		m_PreviousMousePosition = Input::GetMousePosition();
	}

	void CameraController3D::OnUpdate(double dt)
	{
		int x = Input::GetKeyDown(Key::A) ? -1 : Input::GetKeyDown(Key::D) ? 1 : 0;
		int y = Input::GetKeyDown(Key::C) ? -1 : Input::GetKeyDown(Key::Space) ? 1 : 0;
		int z = Input::GetKeyDown(Key::S) ? -1 : Input::GetKeyDown(Key::W) ? 1 : 0;

		glm::vec3 delta = m_MovementSpeed * glm::vec3(x, y, z) * static_cast<float>(dt);

		glm::vec2 mousePos = Input::GetMousePosition();
		glm::vec2 mouseDelta = mousePos - m_PreviousMousePosition;
		m_PreviousMousePosition = mousePos;

		m_Camera.Move(delta);
		m_Camera.Rotate(glm::vec3(mouseDelta.x, mouseDelta.y, 0.0f) * m_RotationSpeed * static_cast<float>(dt));
		m_Camera.OnUpdate();
	}

	void CameraController3D::OnEvent(Event& e)
	{
		EventDispatcher::Dispatch<WindowResizeEvent>(e, CREATE_EVENT_FN_REF(OnWindowResized));
		EventDispatcher::Dispatch<MouseScrolledEvent>(e, CREATE_EVENT_FN_REF(OnMouseScrolled));
	}

	bool CameraController3D::OnWindowResized(WindowResizeEvent& e)
	{
		m_Camera.SetAspectRatio(e.Width / (float)e.Height);
		return false;
	}

	bool CameraController3D::OnMouseScrolled(MouseScrolledEvent& e)
	{
		m_Camera.Zoom(e.YOffset);
		return false;
	}
}
