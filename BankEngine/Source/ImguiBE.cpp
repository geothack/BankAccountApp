#include "ImguiBE.h"
#include "Window.h"
#include <imgui_impl_opengl3_loader.h>

Imgui* Imgui::Get()
{
    if (!m_ImGuiBE)
    {
        m_ImGuiBE = new Imgui();
    }

    return m_ImGuiBE;
}

Imgui::~Imgui()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void Imgui::Create()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    io.Fonts->AddFontFromFileTTF("Resource/Fonts/LEMONMILK-Regular.otf", 25);

    ImGuiStyle& style = ImGui::GetStyle();
    //style.ScaleAllSizes(main_scale);  
    //style.FontScaleDpi = main_scale;     

    ImGui_ImplGlfw_InitForOpenGL(Window::Get()->GetNativeWindow(), true);
    ImGui_ImplOpenGL3_Init("#version 460");
}

void Imgui::NewFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void Imgui::EndFrame()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Imgui::Begin(std::string_view title, ImVec2 position, ImVec2 size)
{
    ImGui::SetNextWindowPos(ImVec2(position), ImGuiCond_Once);
    ImGui::SetNextWindowSize(ImVec2(size), ImGuiCond_Once);
    ImGui::Begin(title.data(),nullptr,ImGuiWindowFlags_NoBackground);
}

void Imgui::End()
{
    ImGui::End();
}

void Imgui::RenderTexture(uint32_t handle, ImVec2 size)
{
    ImGui::Image((ImTextureID)handle, size);
}

bool Imgui::RenderButton(std::string_view buttonText, bool sameLine)
{
    if (sameLine)
    {
        SameLine();
    }
    if (ImGui::Button(buttonText.data()))
    {
        return true;
    }
    return false;
}

bool Imgui::RenderImageButton(std::string_view buttonText, uint32_t handle, ImVec2 size)
{
    if (ImGui::ImageButton(buttonText.data(),handle,size))
    {
        return true;
    }
    return false;
}

void Imgui::RenderText(std::string_view text, bool sameLine)
{
    if (sameLine)
    {
        SameLine();
    }
    ImGui::Text(text.data());
}

const char* Imgui::RenderTextBox(std::string_view title)
{
    static char buffer[128] = "";
    ImGui::InputText(title.data(), buffer, IM_ARRAYSIZE(buffer));
    return buffer;
}

void Imgui::SameLine() const
{
    ImGui::SameLine();
}

void Imgui::Free() 
{
    delete m_ImGuiBE;
}
