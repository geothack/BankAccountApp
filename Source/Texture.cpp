#include "Texture.h"

Texture::Texture(const std::filesystem::path& path, bool flip)
{
    stbi_set_flip_vertically_on_load(flip);

    auto pathString = path.string();
    unsigned char* data = stbi_load(pathString.c_str(), &m_Width, &m_Height, &m_Channels, 0);
    if (data)
    {
        uint32_t format;
        if (m_Channels == 1)
        {
            format = GL_RED;
        }
        else if (m_Channels == 3)
        {
            format = GL_RGB;
        }
        else if (m_Channels == 4)
        {
            format = GL_RGBA;
        }

        glBindTexture(GL_TEXTURE_2D, m_Handle);
        glTexImage2D(GL_TEXTURE_2D, 0, format, m_Width, m_Height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        throw std::runtime_error("Failed to load texture at " + pathString);
        stbi_image_free(data);
    }
}

void Texture::Attach() const
{
	glBindTexture(GL_TEXTURE_2D, m_Handle);
}
