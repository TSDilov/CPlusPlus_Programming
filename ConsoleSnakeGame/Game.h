#pragma once

#include "Game.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "DrawBoard.h"
#include "GameState.h"

class Game {
public:
    Game();
    Game(int width, int height);
    void Run();

private:
    GameState gameState;
    DrawBoard drawBoard;

    void Setup();
    void Input();
};