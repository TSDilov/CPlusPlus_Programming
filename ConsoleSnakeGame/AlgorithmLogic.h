#pragma once

#include "GameState.h"

class AlgorithmLogic {
public:
    static void Move(GameState& gameState);
    static void GenerateRandomPosition(GameState& gameState, int& x, int& y);
};