#include "ulta.hpp"
#include "ulta/core/entry_point.hpp"

// #include "editor_layer.hpp"

class editor : public ulta::application
{
public:
    editor(const ulta::application_info& app_info)
        : ulta::application(app_info)
    {
        // push_layer(new editor_layer());
    }
};

ulta::application* ulta::create_application()
{
    ulta::application_info app_info;
    app_info.name = "Editor";

    std::cout << "Hello from editor\n";

    return new editor(app_info);
}