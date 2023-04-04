#pragma once

#include <string>

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

        static application& get() { return *s_instance; }
    private:
        void run();
    private:
        application_info m_appinfo;
    private:
        static application* s_instance;
        friend int ::main();
    };

    application* create_application();
}
