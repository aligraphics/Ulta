#pragma once

#include "ulta.hpp"

class editor_layer : public ulta::layer
{
public:
    editor_layer() = default;
    virtual ~editor_layer() = default;

    virtual void on_imgui_render() override;

    virtual void on_attach() override;
    virtual void on_detach() override;
    virtual void on_update() override;
    virtual void on_event(ulta::event& e) override;
};