#pragma once

#include "ulta/events/event.hpp"

namespace ulta
{
    class layer
    {
    public:
        virtual ~layer() = default;

        virtual void on_imgui_render() {};

        virtual void on_attach() = 0;
        virtual void on_detach() = 0;
        virtual void on_update() = 0;
        virtual void on_event(event& e) = 0;
    };
}