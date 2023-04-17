#pragma once

#include "ulta/events/event.hpp"

namespace ulta
{
    class window_close_event : public event
    {
    public:
        window_close_event() = default;

        EVENT_CLASS_TYPE(WINDOW_CLOSE)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)
    };

    class window_resize_event : public event
    {
    public:
        window_resize_event(u32 width, u32 height)
            : m_width(width), m_height(height)
        {
        }

        u32 get_width() const { return m_width; }
        u32 get_height() const { return m_height; }

        EVENT_CLASS_TYPE(WINDOW_RESIZE)
		EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)
    private:
        u32 m_width, m_height;
    };
}