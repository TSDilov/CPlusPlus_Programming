#include "DrawBoard.h"
#include <iostream>
#include <windows.h>

DrawBoard::DrawBoard(const GameState& gameState) : gameState(gameState) {}

void DrawBoard::ClearScreen() {
    system("cls");
    std::cout << std::endl;
    std::cout << std::endl;
}

void DrawBoard::Draw() {
    ClearScreen();
    
    for (int i = 0; i < gameState.width + 2; i++)
        std::cout << "#";
    std::cout << std::endl;

    // Draw the game board
    for (int i = 0; i < gameState.height; i++) {
        for (int j = 0; j < gameState.width; j++) {
            if (j == 0)
                std::cout << "#";

            if (i == gameState.y && j == gameState.x)
                std::cout << "O";
            else if (i == gameState.fruitY && j == gameState.fruitX)
                std::cout << "F";
            else {
                bool printTail = false;
                for (int k = 0; k < gameState.nTail; k++) {
                    if (gameState.tailX[k] == j && gameState.tailY[k] == i) {
                        std::cout << "o";
                        printTail = true;
                    }
                }

                if (!printTail)
                    std::cout << " ";
            }

            if (j == gameState.width - 1)
                std::cout << "#";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < gameState.width + 2; i++)
        std::cout << "#";
    std::cout << std::endl;

    std::cout << "Score: " << gameState.score << std::endl;
}