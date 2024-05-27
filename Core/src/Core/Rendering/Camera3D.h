#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace KMG
{
	class Camera3D
	{
	public:
		Camera3D() = default;
		Camera3D(float fov, float aspectRatio, float nearClip, float farClip);
		virtual ~Camera3D() = default;

		void OnUpdate();
		void Move(const glm::vec3 delta);
		void Rotate(const glm::vec3 delta);

		const glm::vec3 GetPosition() const { return m_Position; }
		glm::quat GetOrientation() const;

		float GetPitch() const { return m_Pitch; }
		float GetYaw() const { return m_Yaw; }

		float GetZoomLevel() const { return m_ZoomLevel; }
		void Zoom(float delta);

		float GetFOV() const { return m_FOV; }
		void SetFOV(float fov);

		float GetAspectRatio() const { return m_AspectRatio; }
		void SetAspectRatio(float aspectRatio);

		float GetNearClip() const { return m_NearClip; };
		void SetNearClip(float nearClip);

		float GetFarClip()const { return m_FarClip; };
		void SetFarClip(float farClip);

		const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
		const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
		glm::mat4 GetViewProjectionMatrix() const { return m_ProjectionMatrix * m_ViewMatrix; }
	private:
		void RecalculateProjectionMatrix();
		void RecalculateViewMatrix();
		glm::vec3 GetUpDirection() const;
		glm::vec3 GetRightDirection() const;
		glm::vec3 GetForwardDirection() const;
	private:
		float m_FOV = 60.0f;
		float m_AspectRatio = 1.77778;
		float m_NearClip = 0.1f;
		float m_FarClip = 1000.0f;
		float m_ZoomLevel = 1.0f;

		glm::mat4 m_ProjectionMatrix = glm::mat4(0);
		glm::mat4 m_ViewMatrix = glm::mat4(0);
		glm::vec3 m_Position = glm::vec3(0);

		float m_Pitch = 0.0f;
		float m_Yaw = 0.0f;
		float m_Roll = 0.0f;
	};
}