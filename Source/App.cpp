
#include "Source/ImguiBE.h"
#include "Source/Texture.h"
#include "Source/Window.h"

#include "Source/States/Login.h"

int main()
{
    Window::Get()->Create("BankingApp", 1000, 800);

    auto logoTexture = Texture("Resource/Textures/Logo.png");

    auto imGui = Imgui();

    auto loginState = Login();

    while (!glfwWindowShouldClose(Window::Get()->GetNativeWindow()))
    {
        Window::Get()->Events();

        glClearColor(0.33, 0.33, 0.33, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        imGui.NewFrame();

        imGui.Begin(" ", ImVec2(0, -35), ImVec2(1000, 800));

        if (imGui.RenderImageButton(" ", logoTexture.GetHandle(), ImVec2(100, 100)))
        {
            loginState.IsActive = false;
        }
        imGui.RenderText("GRC Online Banking", true);
        imGui.RenderText("Help & Support");

        if (!loginState.IsActive)
        {
            if (imGui.RenderButton("Login"))
            {
                loginState.IsActive = true;
            }
            
            imGui.RenderText("Sign Up");
            imGui.RenderButton("Personal");
            imGui.RenderButton("Business", true);
            imGui.RenderButton("Student", true);

        }

        if (loginState.IsActive)
        {
            loginState.Update(imGui);
        }

        imGui.End();

        imGui.EndFrame();

        Window::Get()->Swap();
    }

    Window::Get()->Free();

}