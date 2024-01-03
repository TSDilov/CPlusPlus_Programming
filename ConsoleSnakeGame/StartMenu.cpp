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