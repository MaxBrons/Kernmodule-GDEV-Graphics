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
