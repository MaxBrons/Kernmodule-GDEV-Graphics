#pragma once
#include "Core.h"
#include "VertexArray.h"

namespace KMG
{
	class RenderCommands
	{
	public:
		static void Initialize();
		static void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
		static void SetClearColor(const glm::vec4& color);
		static void Clear();
		static void DrawIndexed(const s_ptr<VertexArray>& vertexArray, uint32_t indexCount = 0);
	};
}