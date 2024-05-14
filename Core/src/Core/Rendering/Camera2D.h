#pragma once
#include "Core.h"

namespace KMG
{
	class Camera2D
	{
	public:
		Camera2D() = default;
		Camera2D(float left, float right, float top, float bottom);
		virtual ~Camera2D() = default;

		void UpdateProjectionMatrix(float left, float right, float top, float bottom);

		const glm::vec3& GetPosition() const { return m_Position; }
		void SetPosition(const glm::vec3& position);

		float GetRotation() const { return m_Rotation; }
		void SetRotation(float rotation);

		const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
		const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
		const glm::mat4& GetViewProjectionMatrix() const { return m_ProjectionMatrix * m_ViewMatrix; }
	private:
		void RecalculateViewMatrix();
	private:
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ProjectionMatrix;

		glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
		float m_Rotation = 0.0f;
	};
}