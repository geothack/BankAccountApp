#include "StudentAccount.h"

StudentAccount::StudentAccount()
{
}

StudentAccount::~StudentAccount()
{
}

void StudentAccount::Update()
{
    if (IsActive)
    {
        GIMGUI->RenderText("A student account comes with a $100 overdraft with a 0.0 APR.");
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
