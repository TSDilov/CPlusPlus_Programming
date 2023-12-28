#include "AlgorithmLogic.h"
#include <cstdlib>

void AlgorithmLogic::Move(GameState& gameState) {
    int prevX = gameState.tailX[0];
    int prevY = gameState.tailY[0];
    int prev2X, prev2Y;
    gameState.tailX[0] = gameState.x;
    gameState.tailY[0] = gameState.y;

    for (int i = 1; i < gameState.nTail; i++) {
        prev2X = gameState.tailX[i];
        prev2Y = gameState.tailY[i];
        gameState.tailX[i] = prevX;
        gameState.tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (gameState.dir) {
        case GameState::LEFT:
            gameState.x--;
            break;
        case GameState::RIGHT:
            gameState.x++;
            break;
        case GameState::UP:
            gameState.y--;
            break;
        case GameState::DOWN:
            gameState.y++;
            break;
    }

    if (gameState.x >= gameState.width) gameState.x = 0;
    else if (gameState.x < 0) gameState.x = gameState.width - 1;

    if (gameState.y >= gameState.height) gameState.y = 0;
    else if (gameState.y < 0) gameState.y = gameState.height - 1;

    for (int i = 0; i < gameState.nTail; i++) {
        if (gameState.tailX[i] == gameState.x && gameState.tailY[i] == gameState.y)
            gameState.gameOver = true;
    }

    if (gameState.x == gameState.fruitX && gameState.y == gameState.fruitY) {
        GenerateRandomPosition(gameState, gameState.fruitX, gameState.fruitY);
        gameState.score += 10;
        gameState.nTail++;
    }
}

void AlgorithmLogic::GenerateRandomPosition(GameState& gameState, int& x, int& y) {
    bool validPosition = false;

    while (!validPosition) {
        x = rand() % gameState.width;
        y = rand() % gameState.height;

        validPosition = true;
        for (int i = 0; i < gameState.nTail; i++) {
            if (gameState.tailX[i] == x && gameState.tailY[i] == y) {
                validPosition = false;
                break;
            }
        }
    }
}