#pragma once
#include "Core.h"

#include <string>

namespace KMG
{
	class Texture
	{
	public:
		Texture(const std::string& path, uint32_t channels = 0);
		virtual ~Texture();

		void Bind(uint32_t slot = 0);

		uint32_t GetWidth() const { return static_cast<uint32_t>(m_Width); }
		uint32_t GetHeight() const { return static_cast<uint32_t>(m_Height); }
		uint32_t GetChannelCount() const { return static_cast<uint32_t>(m_Channels); }
		uint8_t* GetData() const { return m_Data; }

		static s_ptr<Texture> Create(const std::string& path, uint32_t channels = 0);
	private:
		uint32_t m_RendererID;
		int m_Width, m_Height, m_Channels;
		uint8_t* m_Data;
	};
}
