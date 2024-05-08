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

	void Shader::SetFloat(const std::string& name, float value)
	{
		glUniform1f(glGetAttribLocation(m_ShaderID, name.c_str()), value);
	}

	void Shader::SetFloat2(const std::string& name, const glm::vec2& value)
	{
		glUniform2f(glGetAttribLocation(m_ShaderID, name.c_str()), value.x, value. y);
	}

	void Shader::SetFloat3(const std::string& name, const glm::vec3& value)
	{
		glUniform3f(glGetAttribLocation(m_ShaderID, name.c_str()), value.x, value.y, value.z);
	}

	void Shader::SetFloat4(const std::string& name, const glm::vec4& value)
	{
		glUniform4f(glGetUniformLocation(m_ShaderID, name.c_str()), value.x, value.y, value.z, value.w);
	}

	void Shader::SetMat3(const std::string& name, const glm::mat3& value)
	{
		glUniformMatrix3fv(glGetUniformLocation(m_ShaderID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
	}

	void Shader::SetMat4(const std::string& name, const glm::mat4& value)
	{
		glUniformMatrix4fv(glGetUniformLocation(m_ShaderID, name.c_str()),1, GL_FALSE, glm::value_ptr(value));
	}
}
