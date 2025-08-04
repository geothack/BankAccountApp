#include "Imgui.h"
#include "Window.h"
#include <imgui_impl_opengl3_loader.h>

Imgui::Imgui()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    //ImGui::StyleColorsDark();
    ImGui::StyleColorsLight();

    ImGuiStyle& style = ImGui::GetStyle();
    //style.ScaleAllSizes(main_scale);  
    //style.FontScaleDpi = main_scale;     

    ImGui_ImplGlfw_InitForOpenGL(Window::Get()->GetNativeWindow(), true);
    ImGui_ImplOpenGL3_Init("#version 460");

}

Imgui::~Imgui()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void Imgui::Render()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Once);
    ImGui::SetNextWindowSize(ImVec2(1000, 800), ImGuiCond_Once);
    static bool active = false;
    ImGui::Begin("GRC Online Banking",&active);

    if (ImGui::Button("Login"))                           
    {

    }

    ImGui::Text("Sign Up");

    if (ImGui::Button("Personal"))
    {

    }

    if (ImGui::Button("Student"))
    {

    }

    if (ImGui::Button("Business"))
    {

    }

    


    ImGui::End();

    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(Window::Get()->GetNativeWindow(), &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Imgui::RenderTexture(uint32_t handle, ImVec2 size)
{
}
