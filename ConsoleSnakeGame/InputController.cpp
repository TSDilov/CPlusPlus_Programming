#include "InputController.h"
#include <conio.h>

void InputController::HandleInput(GameState& gameState) {
    if (_kbhit()) {
        char keyPressed = _getch();
        switch (keyPressed) {
            case 'a':
                if (gameState.dir != GameState::RIGHT) 
                    gameState.dir = GameState::LEFT;
                break;
            case 'd':
                if (gameState.dir != GameState::LEFT)  
                    gameState.dir = GameState::RIGHT;
                break;
            case 'w':
                if (gameState.dir != GameState::DOWN)  
                    gameState.dir = GameState::UP;
                break;
            case 's':
                if (gameState.dir != GameState::UP)   
                    gameState.dir = GameState::DOWN;
                break;
            case 'x':
                gameState.gameOver = true;
                break;
        }
    }
}