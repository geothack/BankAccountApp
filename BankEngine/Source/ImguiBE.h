#pragma once
#include <glad/glad.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <memory>
#include <string_view>

#define GIMGUI Imgui::Get()

class Imgui
{
public:
	static Imgui* Get();
	~Imgui();

	void Create();

	void NewFrame();

	void EndFrame();

	void Begin(std::string_view title, ImVec2 position, ImVec2 size);

	void End();

	void RenderTexture(uint32_t handle, ImVec2 size);

	bool RenderButton(std::string_view buttonText, bool sameLine = false);

	bool RenderImageButton(std::string_view buttonText, uint32_t handle, ImVec2 size);

	void RenderText(std::string_view text, bool sameLine = false);

	const char* RenderTextBox(std::string_view title);

	void SameLine() const;

	void Free(); 

private:
	inline static Imgui* m_ImGuiBE = nullptr;
};

