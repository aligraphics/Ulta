#pragma once

namespace ulta
{
    enum mouse_code : u16
    {
        // From glfw3.h
        button_0                = 0,
        button_1                = 1,
        button_2                = 2,
        button_3                = 3,
        button_4                = 4,
        button_5                = 5,
        button_6                = 6,
        button_7                = 7,

        button_last             = button_7,
        button_left             = button_0,
        button_right            = button_1,
        button_middle           = button_2
    };
}