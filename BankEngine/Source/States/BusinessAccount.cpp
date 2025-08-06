#include "BusinessAccount.h"

BusinessAccount::BusinessAccount()
{
}

BusinessAccount::~BusinessAccount()
{
}

void BusinessAccount::Update()
{
    if (IsActive)
    {
        GIMGUI->RenderText("A business account has muliple benefits but comes with a charge of $20 per month if your balance is below $1000");
        GIMGUI->RenderTextBox("Name");
        GIMGUI->RenderTextBox("Email");
        GIMGUI->RenderTextBox("Address");

        if (GIMGUI->RenderButton("Create"))
        {

        }
        if (GIMGUI->RenderButton("Exit", true))
        {
            IsActive = false;
        }
    }
}
