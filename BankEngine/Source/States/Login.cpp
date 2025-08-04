#include "Login.h"

Login::Login()
{
}

void Login::Update(Imgui& imGui)
{
    imGui.RenderTextBox("Username");
    imGui.RenderTextBox("Password");
    if (imGui.RenderButton("Exit"))
    {
        IsActive = false;
    }
}
