#include "corepch.h"
#include "VertexArrayBuffer.h"

namespace KMG
{
	VertextArrayBuffer::VertextArrayBuffer(const void* data, GLsizeiptr dataSize, unsigned int start, unsigned int size, GLenum type, GLsizei stride)
	{
		glGenVertexArrays(1, &m_VAO);
		glBindVertexArray(m_VAO);

		glGenBuffers(1, &m_VBO);
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		glBufferData(GL_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW);

		glVertexAttribPointer(start, size, type, GL_FALSE, stride, nullptr);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	void VertextArrayBuffer::Bind()
	{
		glBindVertexArray(m_VAO);
	}

	void VertextArrayBuffer::Unbind()
	{
		glBindVertexArray(0);
	}
}