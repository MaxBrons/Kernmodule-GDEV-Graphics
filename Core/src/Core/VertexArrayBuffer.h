#pragma once
#include "Core.h"

namespace KMG
{
	class VertextArrayBuffer
	{
	public:
		VertextArrayBuffer() = default;
		VertextArrayBuffer(const void* data, GLsizeiptr dataSize, unsigned int size, GLenum type, GLsizei stride);
		virtual ~VertextArrayBuffer() = default;

		void Bind();
		void Unbind();

	private:
		GLuint m_VAO, m_VBO;
	};
}
