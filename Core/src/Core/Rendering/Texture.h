#pragma once
#include "Core.h"

#include <string>

namespace KMG {
	class Texture {
	public:
		Texture(const std::string& path);
		virtual ~Texture() = default;

		void Bind();
		void Unbind();
	private:
		GLuint m_RendererID;
	};
}
