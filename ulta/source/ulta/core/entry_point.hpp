#pragma once

#include "ulta/core/application.hpp"

#include <iostream>

extern ulta::application* ulta::create_application();

int main()
{
    std::cout << "Hello from Sandbox App\n";
}