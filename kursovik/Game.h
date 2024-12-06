#ifndef GAME_H
#define GAME_H


#include "Snake.h"
#include "Fruit.h"
#include <sstream>



class Game {
private:
    const int N = 70; // Number of cells horizontally
    const int M = 40; // Number of cells vertically
    const int size = 16; // Size of one cell
    Fruit fruit;
public:
    Game();
    void run();

private:
    void handleInput();
    void update();
    void updateScoreText();
    void draw();
    void drawGameOver();
    void restartGame();
};

#endif // GAME_H