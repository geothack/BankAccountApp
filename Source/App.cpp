
#include "Source/ImguiBE.h"
#include "Source/Texture.h"
#include "Source/Window.h"

#include "Source/States/BusinessAccount.h"
#include "Source/States/Login.h"
#include "Source/States/PersonalAccount.h"
#include "Source/States/StateCache.h"
#include "Source/States/StudentAccount.h"

int main()
{
    Window::Get()->Create("BankingApp", 1000, 800);

    auto logoTexture = Texture("Resource/Textures/Logo.png");

    GIMGUI->Create();


    auto loginState = Login{};
    auto businessAccount = BusinessAccount{};
    auto personalAccount = PersonalAccount{};
    auto studentAccount = StudentAccount{};

    auto stateCache = StateCache{};

    stateCache.Add(loginState);
    stateCache.Add(businessAccount);
    stateCache.Add(personalAccount);
    stateCache.Add(studentAccount);

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
            businessAccount.IsActive = false;
            personalAccount.IsActive = false;
            studentAccount.IsActive = false;
        }
        GIMGUI->RenderText("GRC Online Banking", true);
        GIMGUI->RenderText("Business");
        GIMGUI->RenderText("Savings",true);
        GIMGUI->RenderText("Investing",true);
        GIMGUI->RenderText("Help & Support",true);

        if (!loginState.IsActive && !businessAccount.IsActive && !personalAccount.IsActive && !studentAccount.IsActive)
        {
            if (GIMGUI->RenderButton("Login"))
            {
                loginState.IsActive = true;
            }
            
            GIMGUI->RenderText("Sign Up");
            if (GIMGUI->RenderButton("Personal"))
            {
                personalAccount.IsActive = true;
            }
            if (GIMGUI->RenderButton("Business", true))
            {
                businessAccount.IsActive = true;
            }
            if (GIMGUI->RenderButton("Student", true))
            {
                studentAccount.IsActive = true;
            }

        }

      
        stateCache.Update();
        

        GIMGUI->End();

        GIMGUI->EndFrame();

        Window::Get()->Swap();
    }

    GIMGUI->Free();
    Window::Get()->Free();

}