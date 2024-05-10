#include "corepch.h"
#include "Buffer.h"

namespace KMG
{
	VertexBuffer::VertexBuffer(uint32_t size)
		:m_Stride(0), m_Size(size)
	{
		glGenBuffers(1, &m_RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_STATIC_DRAW);
	}

	VertexBuffer::VertexBuffer(const void* data, uint32_t size)
		:m_Stride(0), m_Size(size)
	{
		glGenBuffers(1, &m_RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

		m_Size = size;
	}

	void VertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	}

	void VertexBuffer::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void VertexBuffer::SetData(const void* data)
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, m_Size, data, GL_STATIC_DRAW);
	}

	void VertexBuffer::AddLayout(const BufferLayout& layout)
	{
		m_Layouts.push_back(layout);
		OnUpdate();
	}

	s_ptr<VertexBuffer> VertexBuffer::Create(uint32_t size)
	{
		return MakeShared<VertexBuffer>(size);
	}

	s_ptr<VertexBuffer> VertexBuffer::Create(const void* data, const uint32_t size)
	{
		return MakeShared<VertexBuffer>(data, size);
	}


	void VertexBuffer::OnUpdate()
	{
		uint32_t offset = 0;
		m_Stride = 0;

		for (auto& layout : m_Layouts)
		{
			layout.Offset = offset;
			offset += layout.Size;
			m_Stride += layout.Size;
		}
	}

	IndexBuffer::IndexBuffer(const uint32_t* indices, uint32_t size)
	{
		glGenBuffers(1, &m_RendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);

		m_Count = size;
	}

	void IndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	}

	void IndexBuffer::Unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	s_ptr<IndexBuffer> IndexBuffer::Create(const uint32_t* indices, uint32_t size)
	{
		return MakeShared<IndexBuffer>(indices, size);
	}

}