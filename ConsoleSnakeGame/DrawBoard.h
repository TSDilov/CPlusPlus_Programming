#pragma once

#include "GameState.h"

class DrawBoard {
public:
    DrawBoard(const GameState& gameState);
    void Draw();

private:
    const GameState& gameState;
    void ClearScreen();
};