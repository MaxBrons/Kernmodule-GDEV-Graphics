#include "corepch.h"
#include "Shader.h"
#include "Base/Log.h"

namespace KMG
{
	Shader::Shader(const std::string& vertSource, const std::string& fragSource)
	{
		std::string&& vContent = Utils::FileReader::ReadFile(vertSource) + "\n";
		std::string&& fContent = Utils::FileReader::ReadFile(fragSource) + "\n";
		const char* vSource = vContent.c_str();
		const char* fSource = fContent.c_str();

		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vSource, nullptr);
		glCompileShader(vertexShader);

		GLint success;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		KMG_CORE_VALIDATE(success, "CORE::SHADER: Failed to compile vertex shader");

		LogError(vertexShader, success);

		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fSource, nullptr);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		KMG_CORE_VALIDATE(success, "CORE::SHADER: Failed to compile fragment shader");

		LogError(fragmentShader, success);

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

	void Shader::SetInt(const std::string& name, int value)
	{
		glUniform1i(glGetUniformLocation(m_ShaderID, name.c_str()), value);
	}

	void Shader::SetInt2(const std::string& name, const glm::i32vec2& value)
	{
		glUniform2iv(glGetUniformLocation(m_ShaderID, name.c_str()), 1, glm::value_ptr(value));
	}

	void Shader::SetInt3(const std::string& name, const glm::i32vec3& value)
	{
		glUniform3iv(glGetUniformLocation(m_ShaderID, name.c_str()), 1, glm::value_ptr(value));
	}

	void Shader::SetInt4(const std::string& name, const glm::i32vec4& value)
	{
		glUniform4iv(glGetUniformLocation(m_ShaderID, name.c_str()), 1, glm::value_ptr(value));
	}

	void Shader::SetFloat(const std::string& name, float value)
	{
		glUniform1f(glGetUniformLocation(m_ShaderID, name.c_str()), value);
	}

	void Shader::SetFloat2(const std::string& name, const glm::vec2& value)
	{
		glUniform2fv(glGetUniformLocation(m_ShaderID, name.c_str()), 1, glm::value_ptr(value));
	}

	void Shader::SetFloat3(const std::string& name, const glm::vec3& value)
	{
		glUniform3fv(glGetUniformLocation(m_ShaderID, name.c_str()), 1, glm::value_ptr(value));
	}

	void Shader::SetFloat4(const std::string& name, const glm::vec4& value)
	{
		glUniform4fv(glGetUniformLocation(m_ShaderID, name.c_str()), 1, glm::value_ptr(value));
	}

	void Shader::SetMat3(const std::string& name, const glm::mat3& value)
	{
		glUniformMatrix3fv(glGetUniformLocation(m_ShaderID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
	}

	void Shader::SetMat4(const std::string& name, const glm::mat4& value)
	{
		glUniformMatrix4fv(glGetUniformLocation(m_ShaderID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
	}

	s_ptr<Shader> Shader::Create(const std::string& vertSource, const std::string& fragSource)
	{
		return MakeShared<Shader>(vertSource, fragSource);
	}

	void Shader::LogError(GLuint id, GLuint success)
	{
		if (success)
			return;

		GLint maxLength = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(id, maxLength, &maxLength, errorLog.data());

		printf("%s", errorLog.data());
	}
}
