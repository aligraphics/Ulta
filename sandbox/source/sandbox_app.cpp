#include "ulta.hpp"
#include "ulta/core/entry_point.hpp"

class sandbox : public ulta::application
{
public:
    sandbox(const ulta::application_info& app_info)
        : ulta::application(app_info)
    {
    }
};

ulta::application* ulta::create_application()
{
    ulta::application_info app_info;
    app_info.name = "Sandbox App";

    return new sandbox(app_info);
}
