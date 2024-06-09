#pragma once
#include "Core.h"
#include "RenderCommands.h"
#include "Camera3D.h"
#include "Shader.h"

namespace KMG
{
	class Renderer
	{
	public:
		Renderer() = default;
		virtual ~Renderer() = default;

		static void Initialize();
		static void OnWindowResized(uint32_t width, uint32_t height);
		static void Begin(const Camera3D& camera);
		static void End();
		static void Submit(const s_ptr<Shader>& shader, const s_ptr<VertexArray>& vertexArray, const glm::mat4& transform);
	private:
		static glm::mat4 s_ViewProjectionMatrix;
	};
}