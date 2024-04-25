#include "corepch.h"
#include "VertexArrayBuffer.h"

namespace KMG
{
	VertextArrayBuffer::VertextArrayBuffer(const void* data, GLsizeiptr dataSize, unsigned int size, GLenum type, GLsizei stride)
	{
		// TODO: Seperate into vertex buffer, vertex array and index array classes
		glGenVertexArrays(1, &m_VAO);
		glBindVertexArray(m_VAO);

		glGenBuffers(1, &m_VBO);
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		glBufferData(GL_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);

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