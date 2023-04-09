#include "ultapch.hpp"
#include "ulta/core/window.hpp"

#include "ulta/platform/glfw/glfw_window.hpp"

namespace ulta
{
    scope<window> window::create(const window_properties& window_properties)
    {
        return create_scope<glfw_window>(window_properties);
    }
}