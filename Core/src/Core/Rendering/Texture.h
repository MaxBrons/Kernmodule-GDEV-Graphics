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

		static s_ptr<Texture> Create(const std::string& path);
	private:
		GLuint m_RendererID;
	};
}
