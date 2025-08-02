#include "Window.h"

Window* Window::Get()
{
	if (!m_Window)
	{
		m_Window = new Window();
	}

	return m_Window;
}

void Window::Create(std::string_view title, const uint32_t width, const uint32_t height)
{
	auto success = glfwInit();

	if (success == 0)
	{
		throw std::runtime_error("Failed to initialize glfw");
	}

	m_NativeWindow = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);

	if (!m_NativeWindow)
	{
		throw std::runtime_error("Failed to create glfw window");
	}

	//glfwMakeContextCurrent(m_NativeWindow);

	//glfwSetWindowShouldClose(m_NativeWindow, false);

	glfwSwapInterval(1); // set vsync

	m_WindowSize.Width = width;
	m_WindowSize.Height = height;
}

void Window::Events() const
{
	glfwPollEvents();
}

void Window::Swap() const
{
	glfwSwapBuffers(m_NativeWindow);
}
