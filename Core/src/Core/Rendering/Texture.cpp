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
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_set_flip_vertically_on_load(1);
		stbi_uc* data = stbi_load(path.c_str(), &m_Width, &m_Height, &m_Channels, 4);
		
		KMG_CORE_ASSERT(data, "Failed to load texture at path: " + std::string(path));

		switch (m_Channels)
		{
			case 3:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
				break;
			case 4:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
				break;
		}

		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);
		glBindTexture(GL_TEXTURE_2D, 0);
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
