#include <print>

#include "Imgui.h"
#include "Texture.h"
#include "Window.h"

int main()
{
    std::println("Hello World");

    Window::Get()->Create("BankingApp", 1000, 800);

    auto logoTexture = Texture("Resource/Textures/Logo.png");

    auto imGui = Imgui();

    while (!glfwWindowShouldClose(Window::Get()->GetNativeWindow()))
    {
        Window::Get()->Events();

        glClearColor(0.33,0.33,0.33,1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        imGui.NewFrame();

        imGui.Begin(" ", ImVec2(0, -20), ImVec2(1000, 800));
       
        imGui.RenderTexture(logoTexture.GetHandle(), ImVec2(100, 100));
        imGui.RenderText("GRC Online Banking",true);
        imGui.RenderText("Help & Support");

        imGui.RenderButton("Login");
        imGui.RenderText("Sign Up");
        imGui.RenderButton("Personal");
        imGui.RenderButton("Business");
        imGui.RenderButton("Student");

        imGui.End();

        imGui.EndFrame();

        Window::Get()->Swap();
    }

    Window::Get()->Free();

}