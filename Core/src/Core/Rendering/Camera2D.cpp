#include "corepch.h"
#include "Camera2D.h"

namespace KMG
{
	Camera2D::Camera2D(float left, float right, float top, float bottom)
		:m_ProjectionMatrix(glm::ortho(left, right, bottom, top, -1.0f, 1.0f)), m_ViewMatrix(1.0f)
	{
	}

	void Camera2D::UpdateProjectionMatrix(float left, float right, float top, float bottom)
	{
		m_ProjectionMatrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
	}

	void Camera2D::SetPosition(const glm::vec3& position)
	{
		m_Position = position;
		RecalculateViewMatrix();
	}

	void Camera2D::SetRotation(float rotation)
	{
		m_Rotation = rotation;
		RecalculateViewMatrix();
	}

	void Camera2D::RecalculateViewMatrix()
	{
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_Position) * glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation), glm::vec3(0, 0, 1));

		m_ViewMatrix = glm::inverse(transform);
	}
}
