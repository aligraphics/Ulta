#pragma once

#include "ulta/core/window.hpp"

namespace ulta
{
    class windows_window : public window
    {
    public:
        windows_window(const window_properties& window_properties);
        virtual ~windows_window();

        virtual void on_update() override;

        virtual u32 get_width() const override;
        virtual u32 get_height() const override;

        virtual void set_event_callback(const event_callback_fn& callback) override;
        virtual void set_vsync(bool vsync) override;
        virtual bool is_vsync_enabled() const override;

        virtual void* get_native_window() const override;
    private:
        virtual void init(const window_properties& window_properties);
        virtual void shutdown();
    private:
        // glfw
    };
}