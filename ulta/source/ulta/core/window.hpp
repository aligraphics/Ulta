#pragma once

#include "ulta/core/base.hpp"
#include "ulta/events/event.hpp"

namespace ulta
{
    struct window_properties
    {
        std::string m_title;
        u32         m_width;
        u32         m_height;

        window_properties(const std::string& title = "ulta application", u32 width = 1600, u32 height = 900)
            : m_title(title), m_width(width), m_height(height)
        {
        }
    };

    class window
    {
    public:
        using event_callback_fn = std::function<void(event&)>;

        window();
        virtual ~window() = default;

        virtual void on_update() = 0;

        virtual u32 get_width() const = 0;
        virtual u32 get_height() const = 0;

        virtual void set_event_callback(const event_callback_fn& callback) = 0;
        virtual void set_vsync(bool vsync) = 0;
        virtual bool is_vsync_enabled() const = 0;

        virtual void* get_native_window() const = 0;

        // static scope<window> create(const window_properties& window_properties = window_properties());
    };
}