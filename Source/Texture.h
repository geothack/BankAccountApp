#pragma once
#include <glad/glad.h>

#include <memory>
#include <stdexcept>
#include <filesystem>

#include "stb_image.h"


class Texture
{
public:
	Texture() = default;
	Texture(const std::filesystem::path& path, bool flip = false);

	void Attach() const;

	uint32_t GetHandle() const { return m_Handle; }

private:
	uint32_t m_Handle = 0;

	int m_Width;
	int m_Height;
	int m_Channels;
};

