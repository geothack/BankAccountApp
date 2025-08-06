
#include "Source/ImguiBE.h"
#include "Source/Texture.h"
#include "Source/Window.h"

#include "Source/States/Login.h"
#include "Source/States/SetupAccount.h"
#include "Source/States/StateCache.h"


int main()
{
    Window::Get()->Create("BankingApp", 1000, 800);

    auto logoTexture = Texture("Resource/Textures/Logo.png");

    GIMGUI->Create();


    auto loginState = Login{};
    auto setupAccountState = SetupAccount{};

    auto stateCache = StateCache{};

    stateCache.Add(loginState);
    stateCache.Add(setupAccountState);

    while (!glfwWindowShouldClose(Window::Get()->GetNativeWindow()))
    {
        Window::Get()->Events();

        glClearColor(0.33, 0.33, 0.33, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        GIMGUI->NewFrame();

        GIMGUI->Begin(" ", ImVec2(0, -35), ImVec2(1000, 800));

        if (GIMGUI->RenderImageButton(" ", logoTexture.GetHandle(), ImVec2(100, 100)))
        {
            loginState.IsActive = false;
            setupAccountState.IsActive = false;
        }
        GIMGUI->RenderText("GRC Online Banking", true);
        GIMGUI->RenderText("Help & Support");

        if (!loginState.IsActive && !setupAccountState.IsActive)
        {
            if (GIMGUI->RenderButton("Login"))
            {
                loginState.IsActive = true;
            }
            
            GIMGUI->RenderText("Sign Up");
            if (GIMGUI->RenderButton("Personal"))
            {
                setupAccountState.IsActive = true;
            }
            GIMGUI->RenderButton("Business", true);
            GIMGUI->RenderButton("Student", true);

        }

      
        stateCache.Update();
        

        GIMGUI->End();

        GIMGUI->EndFrame();

        Window::Get()->Swap();
    }

    GIMGUI->Free();
    Window::Get()->Free();

}