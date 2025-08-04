#include "SetupAccount.h"

SetupAccount::SetupAccount()
{
}

SetupAccount::~SetupAccount()
{
}

void SetupAccount::Update()
{
    GIMGUI->RenderText("A personal account is easy to setup, and has zero fees.");
    GIMGUI->RenderTextBox("Name");
    GIMGUI->RenderTextBox("Email");
    GIMGUI->RenderTextBox("Address");
    if (GIMGUI->RenderButton("Exit"))
    {
        IsActive = false;
    }
}
