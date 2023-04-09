#pragma once

#include "ulta/core/window.hpp"

#include "GLFW/glfw3.h"

namespace ulta
{
    class glfw_window : public window
    {
    public:
        glfw_window(const window_properties& window_properties);
        virtual ~glfw_window();

        virtual void on_update() override;

        virtual u32 get_width() const override { return m_data.width; }
        virtual u32 get_height() const override { return m_data.height; }

        virtual void set_event_callback(const event_callback_fn& callback) override { m_data.event_callback = callback; }
        virtual void set_vsync(bool vsync) override;
        virtual bool is_vsync_enabled() const override { return m_data.vsync; }

        virtual void* get_native_window() const override { return m_window; }
    private:
        virtual void init(const window_properties& window_properties);
        virtual void shutdown();
    private:
        GLFWwindow* m_window;

        struct window_data
        {
            std::string title;
            u32         width, height;
            bool        vsync;

            event_callback_fn event_callback;
        };

        window_data m_data;
    };
}