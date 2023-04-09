#include "ultapch.hpp"
#include "ulta/platform/glfw/glfw_window.hpp"

#include "ulta/events/application_event.hpp"

namespace ulta
{
    glfw_window::glfw_window(const window_properties& window_properties)
    {
        init(window_properties);
    }

    glfw_window::~glfw_window()
    {

    }

    void glfw_window::on_update()
    {
        glfwPollEvents();
    }

    void glfw_window::set_vsync(bool vsync)
    {
        m_data.vsync = vsync;

        // if(m_data.vsync)
        // {
        //     // vulkan present mode
        //     // request swapchain recreation
        // }
    }

    void glfw_window::init(const window_properties& window_properties)
    {
        m_data.title = window_properties.m_title;
        m_data.width = window_properties.m_width;
        m_data.height = window_properties.m_height;

        int success = glfwInit();
        std::cout << "GLFW SUCCESS: success\n";

        m_window = glfwCreateWindow(m_data.width, m_data.height, m_data.title.data(), nullptr, m_window);

        glfwSetWindowUserPointer(m_window, &m_data);

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
		{
			window_data& data = *(window_data*)glfwGetWindowUserPointer(window);
			window_close_event event;
			data.event_callback(event);
		});
    }

    void glfw_window::shutdown()
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }
}