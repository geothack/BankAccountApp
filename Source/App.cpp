#include <print>

#include "Imgui.h"
#include "Window.h"

int main()
{
    std::println("Hello World");

    Window::Get()->Create("BankingApp", 1000, 800);

    auto imGui = Imgui();

    while (!glfwWindowShouldClose(Window::Get()->GetNativeWindow()))
    {
        Window::Get()->Events();

        glClearColor(0.33,0.33,0.33,1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        imGui.Render();

        Window::Get()->Swap();
    }

}