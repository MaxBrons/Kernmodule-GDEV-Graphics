#include "corepch.h"
#include "Shader.h"

namespace KMG
{
	Shader::Shader(const std::string& vertSource, const std::string& fragSource)
	{
		std::string&& vContent = Utils::FileReader::ReadFile(vertSource);
		std::string&& fContent = Utils::FileReader::ReadFile(fragSource);
		vContent += "\n";
		fContent += "\n";
		const char* vSource = vContent.c_str();
		const char* fSource = fContent.c_str();

		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vSource, nullptr);
		glCompileShader(vertexShader);

		GLint success;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		KMG_CORE_VALIDATE(success, "CORE::SHADER: Failed to compile vertex shader");

		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fSource, nullptr);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		KMG_CORE_VALIDATE(success, "CORE::SHADER: Failed to compile fragment shader");

		m_ShaderID = glCreateProgram();
		glAttachShader(m_ShaderID, vertexShader);
		glAttachShader(m_ShaderID, fragmentShader);
		glLinkProgram(m_ShaderID);
		
		glGetProgramiv(m_ShaderID, GL_LINK_STATUS, &success);
		KMG_CORE_VALIDATE(success, "CORE::SHADER: Failed to link shader");

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void Shader::Bind()
	{
		glUseProgram(m_ShaderID);
	}

	void Shader::Unbind()
	{
		glUseProgram(0);
	}

	void Shader::SetUniform1f(const std::string& name, GLfloat x)
	{
		glUniform1f(glGetAttribLocation(m_ShaderID, name.c_str()), x);
	}

	void Shader::SetUniform2f(const std::string& name, GLfloat x, GLfloat y)
	{
		glUniform2f(glGetAttribLocation(m_ShaderID, name.c_str()), x, y);
	}

	void Shader::SetUniform3f(const std::string& name, GLfloat x, GLfloat y, GLfloat z)
	{
		glUniform3f(glGetAttribLocation(m_ShaderID, name.c_str()), x, y, z);
	}

	void Shader::SetUniform4f(const std::string& name, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
	{
		glUniform4f(glGetUniformLocation(m_ShaderID, name.c_str()), x, y, z, w);
	}
}
