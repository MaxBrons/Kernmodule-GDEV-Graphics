#pragma once
#include "Utilities/Utils.h"

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

		void SetInt(const std::string& name, int value);
		void SetInt2(const std::string& name, const glm::i32vec2& value);
		void SetInt3(const std::string& name, const glm::i32vec3& value);
		void SetInt4(const std::string& name, const glm::i32vec4& value);
		void SetFloat(const std::string& name, float value);
		void SetFloat2(const std::string& name, const glm::vec2& value);
		void SetFloat3(const std::string& name, const glm::vec3& value);
		void SetFloat4(const std::string& name, const glm::vec4& value);
		void SetMat3(const std::string& name, const glm::mat3& value);
		void SetMat4(const std::string& name, const glm::mat4& value);
	private:
		GLuint m_ShaderID;
	};
}
