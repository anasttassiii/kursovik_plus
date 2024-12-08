#ifndef GAME_H
#define GAME_H


#include "Snake.h"
#include "Fruit.h"
#include <sstream>
#include <SFML/Graphics.hpp>


class Game {
private:
    const int N = 70; // Количество ячеек по горизонтали
    const int M = 40; // Количество ячеек по вертикали
    const int size = 16; // Размер одной ячейки
    Fruit fruit;
public:
    Game();
    void run();

private:
    void update();
    void updateScoreText();
    void draw();
    void drawGameOver();
    void restartGame();
};

#endif // GAME_H