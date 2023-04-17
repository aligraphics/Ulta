#pragma once

#include "ulta/events/event.hpp"
#include "ulta/core/key_code.hpp"

namespace ulta
{
    class key_event : public event
    {
    public:
        key_code get_key_code() const { return m_keycode; }

        EVENT_CLASS_CATEGORY(EVENT_CATEGORY_KEYBOARD | EVENT_CATEGORY_INPUT)
    protected:
        key_event(const key_code keycode)
            : m_keycode(keycode)
        {
        }
        key_code m_keycode;
    };

    class key_pressed_event : public key_event
    {
    public:
        key_pressed_event(key_code key, bool is_repeat = false)
            : key_event(key), m_isrepeat(is_repeat)
        {
        }

        bool is_repeat() const { return m_isrepeat; }

        std::string to_string() const override
		{
			std::stringstream ss;
			ss << "key_pressed_event: " << m_keycode << " (repeat = " << m_isrepeat << ")";
			return ss.str();
		}

        EVENT_CLASS_TYPE(KEY_PRESSED)
    private:
        bool m_isrepeat;
    };

    class key_released_event : public key_event
    {
    public:
        key_released_event(key_code key)
            : key_event(key)
        {
        }

        std::string to_string() const override
		{
			std::stringstream ss;
			ss << "key_released_event: " << m_keycode;
			return ss.str();
		}

        EVENT_CLASS_TYPE(KEY_RELEASED)
    };

    class key_typed_event : public key_event
    {
    public:
        key_typed_event(key_code key)
            : key_event(key)
        {
        }

        std::string to_string() const override
		{
			std::stringstream ss;
			ss << "key_typed_event: " << m_keycode;
			return ss.str();
		}

        EVENT_CLASS_TYPE(KEY_TYPED)
    };
}