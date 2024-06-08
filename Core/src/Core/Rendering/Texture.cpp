#include "corepch.h"
#include "Texture.h"
#include "Base/Log.h"

#include <stb_image.h>

namespace KMG
{
	Texture::Texture(const std::string& path)
	{
		glGenTextures(1, &m_RendererID);
		glBindTexture(GL_TEXTURE_2D, m_RendererID);

		glTexParameteri(m_RendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(m_RendererID, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexParameteri(m_RendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(m_RendererID, GL_TEXTURE_WRAP_T, GL_REPEAT);

		stbi_set_flip_vertically_on_load(1);
		m_Data = stbi_load(path.c_str(), &m_Width, &m_Height, &m_Channels, 4);

		KMG_CORE_ASSERT(m_Data, "Failed to load texture at path: " + std::string(path));

		switch (m_Channels)
		{
			case 3:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_Data);
				break;
			case 4:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_Data);
				break;
			default:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_Data);
				m_Channels = 4;
				break;
		}

		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	Texture::~Texture()
	{
		if (m_Data)
			stbi_image_free(m_Data);

		glDeleteTextures(1, &m_RendererID);
	}

	void Texture::Bind(uint32_t slot)
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, m_RendererID);
	}

	s_ptr<Texture> Texture::Create(const std::string& path)
	{
		return MakeShared<Texture>(path);
	}
}
