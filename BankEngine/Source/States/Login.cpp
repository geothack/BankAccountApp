#include "Login.h"
#include "Source/ImguiBE.h"

Login::Login()
{
}

Login::~Login()
{
}

void Login::Update()
{
    GIMGUI->RenderTextBox("Username");
    GIMGUI->RenderTextBox("Password");
    if (GIMGUI->RenderButton("Exit"))
    {
        IsActive = false;
    }
}
