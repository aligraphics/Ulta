#pragma once

#include "ulta/core/window.hpp"
#include "ulta/events/application_event.hpp"
#include "ulta/core/layer/layer_stack.hpp"

int main();

namespace ulta
{
    struct application_info
    {
        std::string name;
    };

    class application
    {
    public:
        application(const application_info& app_info);
        virtual ~application() = default;

        void on_event(event& e);

        void push_layer(layer* layer);
        void push_overlay(layer* layer);

        static application& get() { return *s_instance; }
    private:
        void run();
        bool on_window_close(window_close_event& e);
    private:
        application_info    m_appinfo;
        scope<window>       m_window;
        layer_stack         m_layerstack;

        bool                m_running;
    private:
        static application* s_instance;
        friend int ::main();
    };

    application* create_application();
}
