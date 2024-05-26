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

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int width, height, numChannels;
		uint8_t* data = stbi_load(path.c_str(), &width, &height, &numChannels, 0);

		KMG_CORE_ASSERT(data, "Failed to load texture at path: " + std::string(path));

		switch (numChannels)
		{
			case 3:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			case 4:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		}

		glGenerateMipmap(GL_TEXTURE_2D);
		stbi_image_free(data);

		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Texture::Bind()
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_RendererID);
	}

	void Texture::Unbind()
	{
		glActiveTexture(0);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	s_ptr<Texture> Texture::Create(const std::string& path)
	{
		return MakeShared<Texture>(path);
	}
}
