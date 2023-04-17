#include "ultapch.hpp"
#include "ulta/platform/glfw/glfw_window.hpp"

#include "ulta/events/application_event.hpp"
#include "ulta/events/mouse_event.hpp"
#include "ulta/events/key_event.hpp"

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

        m_window = glfwCreateWindow(m_data.width, m_data.height, m_data.title.data(), nullptr, nullptr);

        glfwSetWindowUserPointer(m_window, &m_data);

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
		{
			window_data& data = *(window_data*)glfwGetWindowUserPointer(window);
			window_close_event event;
			data.event_callback(event);
		});

        glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
        {
            window_data& data = *(window_data*)glfwGetWindowUserPointer(window);
            data.width = width;
            data.height = height;

            window_resize_event event(width, height);
            data.event_callback(event);
        });

        glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            window_data& data = *(window_data*)glfwGetWindowUserPointer(window);
            
            switch(action)
            {
                case GLFW_PRESS:
                {
                    key_pressed_event event((key_code)key, 0);
                    data.event_callback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    key_released_event event((key_code)key);
                    data.event_callback(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    key_pressed_event event((key_code)key, 1);
                    data.event_callback(event);
                    break;
                }
            }
        });

        glfwSetCharCallback(m_window, [](GLFWwindow* window, unsigned int keycode)
        {
            window_data& data = *(window_data*)glfwGetWindowUserPointer(window);
            key_typed_event event((key_code)keycode);
            data.event_callback(event);
        });

        glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xpos, double ypos)
        {
            window_data& data = *(window_data*)glfwGetWindowUserPointer(window);
            mouse_moved_event event(xpos, ypos);
            data.event_callback(event);
        });

        glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xoffset, double yoffset)
        {
            window_data& data = *(window_data*)glfwGetWindowUserPointer(window);
            mouse_scrolled_event event(xoffset, yoffset);
            data.event_callback(event);
        });

        glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
        {
            window_data& data = *(window_data*)glfwGetWindowUserPointer(window);
            
            if(action == GLFW_PRESS)
            {
                mouse_button_pressed_event event((mouse_code)button);
                data.event_callback(event);
            } else if(action == GLFW_RELEASE)
            {
                mouse_button_released_event event((mouse_code)button);
                data.event_callback(event);
            }
        });
    }

    void glfw_window::shutdown()
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }
}