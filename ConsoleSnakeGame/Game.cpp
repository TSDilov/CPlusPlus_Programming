#include "Game.h"

using namespace std;

Game::Game() : gameOver(false), gameState(20, 10), drawBoard(gameState) {
    Setup();
}

void Game::Run() {
    while (!gameOver) {
        DrawBoard drawBoard(gameState);
        drawBoard.Draw();

        Input();
        Algorithm();
        Sleep(100);
    }
}

void Game::Setup() {
    gameOver = false;
    gameState.Setup();
}

void Game::Input() {
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
                gameOver = true;
                break;
        }
    }
}

void Game::Algorithm() {
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
            gameOver = true;
    }

    if (gameState.x == gameState.fruitX && gameState.y == gameState.fruitY) {
        gameState.score += 10;
        gameState.fruitX = rand() % gameState.width;
        gameState.fruitY = rand() % gameState.height;
        gameState.nTail++;
    }
}
