#pragma once
#include "Log.h"
#include "Utils.h"

#include <string>

namespace KMG
{
	class Shader
	{
	public:
		Shader() = default;
		Shader(const std::string& vertSource, const std::string& fragSource);
		virtual ~Shader() = default;

		void Bind();
		void Unbind();

		void SetUniform1f(const std::string& name, GLfloat x);
		void SetUniform2f(const std::string& name, GLfloat x, GLfloat y);
		void SetUniform3f(const std::string& name, GLfloat x, GLfloat y, GLfloat z);
		void SetUniform4f(const std::string& name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	private:
		GLuint m_ShaderID;
	};
}
