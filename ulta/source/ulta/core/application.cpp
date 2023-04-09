#include "ultapch.hpp"
#include "ulta/core/application.hpp"

namespace ulta
{
    application* application::s_instance = nullptr;

    application::application(const application_info& app_info)
        : m_appinfo(app_info)
    {
        // TODO: logging system
        assert(!s_instance);
        s_instance = this;

        m_window = window::create(window_properties(app_info.name));
        m_window->set_event_callback(ULTA_BIND_EVENT_FN(application::on_event));
    }

    void application::on_event(event& e)
    {
        event_dispatcher dispatcher(e);
        dispatcher.dispatch<window_close_event>(ULTA_BIND_EVENT_FN(application::on_window_close));
    }

    void application::run()
    {
        while(m_running)
        {
            m_window->on_update();
        }
    }

    bool application::on_window_close(window_close_event& e)
    {
        m_running = false;
        return true;
    }
}