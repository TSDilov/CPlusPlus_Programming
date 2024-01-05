#include "StartMenu.h"
#include <iostream>

StartMenu::StartMenu() {}

int StartMenu::ShowMenu() {
    int choice;
    std::cout << "Welcome to Snake Game!" << std::endl;
    std::cout << "1. Start Game" << std::endl;
    std::cout << "2. Choose Field Size" << std::endl;
    std::cout << "3. Quit" << std::endl;

    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}

std::pair<int, int> StartMenu::GetWidthAndHeight() {
    int width;
    int height;
    std::cout << "Choose width for the field:" << std::endl;
    std::cin >> width;
    std::cout << "Choose height for the field:" << std::endl;
    std::cin >> height;
    return std::make_pair(width, height);
}