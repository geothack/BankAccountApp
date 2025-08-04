#pragma once
#include <glad/glad.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <memory>

class Imgui
{
public:
	Imgui();
	~Imgui();

	void Render();

	void RenderTexture(uint32_t handle, ImVec2 size);

private:
	
};

