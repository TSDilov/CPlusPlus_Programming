#pragma once

#include <iostream>
#include <conio.h>
#include <windows.h>

class Game {
    public:
        Game();
        ~Game();
        void Run();
    
    private:
        bool gameOver;
        const int width;
        const int height;
        int x, y, fruitX, fruitY, score;
        int* tailX;
        int* tailY;
        int nTail;
        enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
        eDirection dir;

        void Setup();
        void Draw();
        void Input();
        void Algorithm();
};