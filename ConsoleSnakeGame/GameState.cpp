#include "GameState.h"
#include <cstdlib>

GameState::GameState(int w, int h) : width(w), height(h), x(0), y(0), fruitX(0), fruitY(0), nTail(0), score(0), tailX(nullptr), tailY(nullptr) {
    tailX = new int[100];
    tailY = new int[100];
}

GameState::~GameState() {
    delete[] tailX;
    tailX = nullptr;
    delete[] tailY;
    tailY = nullptr;
}

void GameState::Setup() {  
    gameOver = false;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    nTail = 0;
    score = 0;
}