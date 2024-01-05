#pragma once

#include <utility>

class StartMenu {
public:
    StartMenu();
    int ShowMenu();
    std::pair<int, int> GetWidthAndHeight();
};