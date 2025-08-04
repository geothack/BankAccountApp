#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string_view>
#include <stdexcept>

struct WindowSize // 8 bytes can be copied 
{
    uint32_t Width;
    uint32_t Height;
}; 

class Window
{
public:
	static Window* Get();

    Window() = default;

    Window(const Window&) = delete;
    Window& operator=(Window&&) = delete;
    Window& operator=(const Window&) = delete;
    Window(Window&&) = delete;

    void Create(std::string_view title, const uint32_t width, const uint32_t height);

    void Events() const;

    void Swap() const;

    void Free();

    GLFWwindow* GetNativeWindow() { return m_NativeWindow; }

public:
    WindowSize GetSize() { return m_WindowSize; }

private:
	inline static Window* m_Window = nullptr;

    WindowSize m_WindowSize{};

    GLFWwindow* m_NativeWindow{};
};

