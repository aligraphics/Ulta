#include "ultapch.hpp"
#include "ulta/core/application.hpp"

namespace ulta
{
    application* application::s_instance = nullptr;

    application::application(const application_info& app_info)
        : m_appinfo(app_info)
    {
        s_instance = this;
    }
}