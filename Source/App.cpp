#include <print>


#include "Window.h"

int main()
{
    std::println("Hello World");

    Window::Get()->Create("BankingApp", 1000, 800);

    while (!glfwWindowShouldClose(Window::Get()->GetNativeWindow()))
    {
        Window::Get()->Events();
        Window::Get()->Swap();
    }

}