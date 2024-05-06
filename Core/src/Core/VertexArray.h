#pragma once
#include "Core.h"
#include "Buffer.h"

namespace KMG
{
	class VertexArray
	{
	public:
		VertexArray();
		virtual ~VertexArray() = default;

		void Bind();
		void Unbind();

		void AddVertexBuffer(const s_ptr<VertexBuffer>& vertexBuffer);
		void SetIndexBuffer(const s_ptr<IndexBuffer>& indexBuffer);

		static s_ptr<VertexArray> Create();
	private:
		uint32_t m_RendererID;
		std::vector<s_ptr<VertexBuffer>> m_VertexBuffers;
		s_ptr<IndexBuffer> m_IndexBuffer;
		uint32_t m_VertexBufferIndex = 0;
	};
}