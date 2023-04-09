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
}