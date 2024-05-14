#include "corepch.h"
#include "Camera3D.h"
#include "Base/Input.h"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

namespace KMG
{
	Camera3D::Camera3D(float fov, float aspectRatio, float nearClip, float farClip)
		:m_FOV(fov), m_AspectRatio(aspectRatio), m_NearClip(nearClip), m_FarClip(farClip)
	{
		RecalculateProjectionMatrix();
	}

	void Camera3D::OnUpdate()
	{
		RecalculateViewMatrix();
	}

	void Camera3D::RecalculateProjectionMatrix()
	{
		m_ProjectionMatrix = glm::perspective(glm::radians(m_FOV), m_AspectRatio, m_NearClip, m_FarClip);
	}

	void Camera3D::RecalculateViewMatrix()
	{
		m_Position = CalculatePosition();

		//m_ViewMatrix = glm::lookAt(m_Position, m_Position + GetForwardDirection(), GetUpDirection());
		m_ViewMatrix = glm::translate(glm::mat4(1.0f), m_Position) * glm::toMat4(GetOrientation());
		m_ViewMatrix = glm::inverse(m_ViewMatrix);
	}

	void Camera3D::Move(const glm::vec3 delta)
	{
		m_FocalPoint += GetRightDirection() * delta.x * m_ZoomLevel;
		m_FocalPoint += GetUpDirection() * delta.y * m_ZoomLevel;
		m_FocalPoint += GetForwardDirection() * delta.z * m_ZoomLevel;
	}

	void Camera3D::Rotate(const glm::vec3 delta)
	{
		m_Pitch = glm::clamp(m_Pitch + delta.y * (1.7778f), -85.0f, 85.0f);
		m_Yaw += delta.x;
		m_Roll += delta.z;

		if (m_Yaw > 180.0f)
			m_Yaw -= 360.0f;
		else if (m_Yaw < -180.0f)
			m_Yaw += 360.0f;
	}

	void Camera3D::Zoom(float delta)
	{
		m_ZoomLevel -= delta * 0.1f;

		if (m_ZoomLevel < 1.0f)
		{
			m_FocalPoint += GetForwardDirection();
			m_ZoomLevel = 1.0f;
		}
	}

	glm::quat Camera3D::GetOrientation() const
	{
		return glm::quat(glm::vec3(-glm::radians(m_Pitch), -glm::radians(m_Yaw), glm::radians(m_Roll)));
	}

	void Camera3D::SetFOV(float fov)
	{
		m_FOV = fov;
		RecalculateProjectionMatrix();
	}

	void Camera3D::SetAspectRatio(float aspectRatio)
	{
		m_AspectRatio = aspectRatio;
		RecalculateProjectionMatrix();
	}

	void Camera3D::SetNearClip(float nearClip)
	{
		m_NearClip = nearClip;
		RecalculateProjectionMatrix();
	}

	void Camera3D::SetFarClip(float farClip)
	{
		m_FarClip = farClip;
		RecalculateProjectionMatrix();
	}

	glm::vec3 Camera3D::GetUpDirection() const
	{
		return glm::rotate(GetOrientation(), glm::vec3(0.0f, 1.0f, 0.0f));
	}

	glm::vec3 Camera3D::GetRightDirection() const
	{
		return glm::rotate(GetOrientation(), glm::vec3(1.0f, 0.0f, 0.0f));
	}

	glm::vec3 Camera3D::GetForwardDirection() const
	{
		return glm::rotate(GetOrientation(), glm::vec3(0.0f, 0.0f, -1.0f));
	}

	glm::vec3 Camera3D::CalculatePosition() const
	{
		return m_FocalPoint - GetForwardDirection() * m_ZoomLevel;
	}

}