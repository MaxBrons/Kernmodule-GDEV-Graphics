#pragma once
#include "Core.h"

#include <string>

namespace KMG
{
	class Texture
	{
	public:
		Texture(const std::string& path);
		virtual ~Texture() = default;

		void Bind(uint32_t slot = 0);

		static s_ptr<Texture> Create(const std::string& path);
	private:
		uint32_t m_RendererID;
	};
}
