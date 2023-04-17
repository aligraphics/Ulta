#pragma once

#include "ulta/core/base.hpp"
#include "ulta/core/layer/layer.hpp"

#include <vector>

namespace ulta
{
    class layer_stack
    {
    public:
        layer_stack() = default;
        ~layer_stack();

        void push_layer(layer* layer);
        void push_overlay(layer* overlay);
        void pop_layer(layer* layer);
        void pop_overlay(layer* overlay);
    public:
        std::vector<layer*>::iterator begin() { return m_layers.begin(); }
		std::vector<layer*>::iterator end() { return m_layers.end(); }
		std::vector<layer*>::reverse_iterator rbegin() { return m_layers.rbegin(); }
		std::vector<layer*>::reverse_iterator rend() { return m_layers.rend(); }

		std::vector<layer*>::const_iterator begin() const { return m_layers.begin(); }
		std::vector<layer*>::const_iterator end()	const { return m_layers.end(); }
		std::vector<layer*>::const_reverse_iterator rbegin() const { return m_layers.rbegin(); }
		std::vector<layer*>::const_reverse_iterator rend() const { return m_layers.rend(); }
    private:
        std::vector<layer*> m_layers;
        u32 m_insertindex;
    };
}