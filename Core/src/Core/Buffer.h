#pragma once
#include "Core.h"

#include <string>

namespace KMG
{
	enum class LayoutType { None = 0, Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, Bool };

	static uint32_t GetLayoutElementCount(LayoutType type)
	{
		switch (type)
		{
			case LayoutType::Float:		return 1;
			case LayoutType::Float2:	return 2;
			case LayoutType::Float3:	return 3;
			case LayoutType::Float4:	return 4;
			case LayoutType::Mat3:		return 3;
			case LayoutType::Mat4:		return 4;
			case LayoutType::Int:		return 1;
			case LayoutType::Int2:		return 2;
			case LayoutType::Int3:		return 3;
			case LayoutType::Int4:		return 4;
			case LayoutType::Bool:		return 1;
		}
		return 0;
	}

	static uint32_t GetLayoutTypeSize(LayoutType type)
	{
		switch (type)
		{
			case LayoutType::Float:    return sizeof(float);
			case LayoutType::Float2:   return sizeof(float) * 2;
			case LayoutType::Float3:   return sizeof(float) * 3;
			case LayoutType::Float4:   return sizeof(float) * 4;
			case LayoutType::Mat3:     return sizeof(float) * 3 * 3;
			case LayoutType::Mat4:     return sizeof(float) * 4 * 4;
			case LayoutType::Int:      return sizeof(int);
			case LayoutType::Int2:     return sizeof(int) * 2;
			case LayoutType::Int3:     return sizeof(int) * 3;
			case LayoutType::Int4:     return sizeof(int) * 4;
			case LayoutType::Bool:     return sizeof(bool);
		}

		return 0;
	}

	static GLuint LayoutTypeToGLType(LayoutType type)
	{
		switch (type)
		{
			case LayoutType::Float:		return GL_FLOAT;
			case LayoutType::Float2:	return GL_FLOAT;
			case LayoutType::Float4:	return GL_FLOAT;
			case LayoutType::Float3:	return GL_FLOAT;
			case LayoutType::Mat3:		return GL_FLOAT;
			case LayoutType::Mat4:		return GL_FLOAT;
			case LayoutType::Int:		return GL_INT;
			case LayoutType::Int2:		return GL_INT;
			case LayoutType::Int3:		return GL_INT;
			case LayoutType::Int4:		return GL_INT;
			case LayoutType::Bool:		return GL_BOOL;
		}
		return GL_NONE;
	}

	// Vertex array -> Vertex Buffer -> Vertex Layout
	struct BufferLayout
	{
		std::string Name;
		LayoutType Type;
		uint32_t Size;
		uint32_t Offset;
		bool Normalized;

	public:
		BufferLayout() = default;
		BufferLayout(const std::string& name, LayoutType type, bool normalized)
			:Name(name), Type(type), Size(GetLayoutTypeSize(type)), Offset(0), Normalized(normalized)
		{
		}
	};

	class VertexBuffer
	{
	public:
		VertexBuffer(uint32_t size);
		VertexBuffer(const void* data, uint32_t size);
		virtual ~VertexBuffer() = default;

		void Bind();
		void Unbind();

		void SetData(const void* data);
		void AddLayout(const BufferLayout& layout);

		const std::vector<BufferLayout>& GetLayouts() const { return m_Layouts; }
		uint32_t GetStride() const { return m_Stride; }

		static s_ptr<VertexBuffer> Create(uint32_t size);
		static s_ptr<VertexBuffer> Create(const void* data, uint32_t size);
	private:
		void OnUpdate();
	private:
		uint32_t m_RendererID;
		std::vector<BufferLayout> m_Layouts;
		uint32_t m_Stride = 0;
		uint32_t m_Size = 0;
	};

	class IndexBuffer
	{
	public:
		IndexBuffer(const uint32_t* indices, uint32_t size);
		virtual ~IndexBuffer() = default;

		void Bind();
		void Unbind();

		uint32_t GetCount() const { return m_Count; }

		static s_ptr<IndexBuffer> Create(const uint32_t* indices, uint32_t size);
	private:
		uint32_t m_RendererID;
		uint32_t m_Count = 0;
	};
}