#pragma once

#include "ulta/core/window.hpp"
#include "ulta/events/application_event.hpp"

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

        static application& get() { return *s_instance; }
    private:
        void run();
        bool on_window_close(window_close_event& e);
    private:
        application_info    m_appinfo;
        scope<window>       m_window;

        bool                m_running;
    private:
        static application* s_instance;
        friend int ::main();
    };

    application* create_application();
}
