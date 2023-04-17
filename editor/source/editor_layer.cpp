#include "editor_layer.hpp"

#include <imgui/imgui.h>

void editor_layer::on_attach()
{
    ImGui::CreateContext();
}

void editor_layer::on_detach()
{

}

void editor_layer::on_update()
{

}

void editor_layer::on_event(ulta::event& event)
{

}

void editor_layer::on_imgui_render()
{
    // ImGui::Begin("Stats");
    //     ImGui::Text("Renderer2D Stats:");
    //     ImGui::Text("Draw Calls: %d", 1);
    //     ImGui::Text("Quads: %d", 1);
    //     ImGui::Text("Vertices: %d", 1);
    //     ImGui::Text("Indices: %d", 1);
    // ImGui::End();
}
