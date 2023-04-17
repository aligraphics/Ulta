#include "ultapch.hpp"
#include "layer_stack.hpp"

namespace ulta
{
    layer_stack::~layer_stack()
    {
        for(layer* layer : m_layers)
        {
            layer->on_detach();
            delete layer;
        }
    }

    void layer_stack::push_layer(layer* layer)
    {
        m_layers.emplace(m_layers.begin() + m_insertindex, layer);
		m_insertindex++;
    }

    void layer_stack::push_overlay(layer* overlay)
    {
        m_layers.emplace_back(overlay);
    }

    void layer_stack::pop_layer(layer* layer)
    {
		auto it = std::find(m_layers.begin(), m_layers.begin() + m_insertindex, layer);
		if (it != m_layers.begin() + m_insertindex)
		{
			layer->on_detach();
			m_layers.erase(it);
			m_insertindex--;
		}
    }

    void layer_stack::pop_overlay(layer* overlay)
    {
        auto it = std::find(m_layers.begin() + m_insertindex, m_layers.end(), overlay);
		if (it != m_layers.end())
		{
			overlay->on_detach();
			m_layers.erase(it);
		}
    }
}