#pragma once

class GameState {
public:
    bool gameOver;
    int width;
    int height;
    int x;
    int y;
    int fruitX;
    int fruitY;
    int* tailX;
    int* tailY;
    int nTail;
    int score;
    enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    eDirection dir;

    GameState(int w, int h);
    ~GameState();
    void Setup();
};