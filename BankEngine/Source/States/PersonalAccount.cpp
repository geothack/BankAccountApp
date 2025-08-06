#include "PersonalAccount.h"

PersonalAccount::PersonalAccount()
{
}

PersonalAccount::~PersonalAccount()
{
}

void PersonalAccount::Update()
{
    if (IsActive)
    {
        GIMGUI->RenderText("A personal account is easy to setup, and has zero fees.");
        GIMGUI->RenderTextBox("Name");
        GIMGUI->RenderTextBox("Email");
        GIMGUI->RenderTextBox("Address");
        if (GIMGUI->RenderButton("Create"))
        {

        }
        if (GIMGUI->RenderButton("Exit",true))
        {
            IsActive = false;
        }
    }
}
