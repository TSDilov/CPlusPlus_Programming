#include "Game.h"
#include "AlgorithmLogic.h"
#include "InputController.h"

using namespace std;

Game::Game() : gameState(20, 10), drawBoard(gameState) {
    Setup();
}

void Game::Run() {
    while (!gameState.gameOver) {
        DrawBoard drawBoard(gameState);
        drawBoard.Draw();

        Input();
        AlgorithmLogic::Move(gameState);
        Sleep(100);
    }
}

void Game::Setup() {
    gameState.Setup();
}

void Game::Input() {
    InputController::HandleInput(gameState);
}
