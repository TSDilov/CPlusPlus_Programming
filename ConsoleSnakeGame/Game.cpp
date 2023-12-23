#include "Game.h"

using namespace std;

Game::Game() : gameOver(false), width(20), height(10), tailX(nullptr), tailY(nullptr), nTail(0) {
    tailX = new int[100];
    tailY = new int[100];
    Setup();
}

void Game::Setup() {
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Game::Draw() {
    system("cls");
    cout << endl;
    cout << endl;

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#";

            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else {
                bool printTail = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";
                        printTail = true;
                    }
                }
                if (!printTail)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    cout << "Score:" << score << endl;
}

void Game::Input() {
    if (_kbhit()) {
        char keyPressed = _getch();
        switch (keyPressed) {
            case 'a':
                if (dir != RIGHT) 
                    dir = LEFT;
                break;
            case 'd':
                if (dir != LEFT)  
                    dir = RIGHT;
                break;
            case 'w':
                if (dir != DOWN)  
                    dir = UP;
                break;
            case 's':
                if (dir != UP)   
                    dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}

void Game::Algorithm() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
    }

    if (x >= width) x = 0;
    else if (x < 0) x = width - 1;

    if (y >= height) y = 0;
    else if (y < 0) y = height - 1;

    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

void Game::Run() {
    while (!gameOver) {
        Draw();
        Input();
        Algorithm();
        Sleep(100);
    }
}

Game::~Game() {
    delete[] tailX;
    tailX = nullptr;
    delete[] tailY;
    tailY = nullptr;
}