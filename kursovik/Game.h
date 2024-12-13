#ifndef GAME_H
#define GAME_H


#include "Snake.h"
#include "Fruit.h"
#include <sstream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Game {
private:
    const int N = 70; // Количество ячеек по горизонтали
    const int M = 40; // Количество ячеек по вертикали
    const int size = 16; // Размер одной ячейки
    RenderWindow window;
    Snake snake;
    Fruit fruit;
    Clock clock;
    float timer;
    float delay;
    int score; // Переменная для хранения результатов
    int totalGamesPlayed; // общее кол-во сыгранных игр
    int totalScore; // максимальный счет за все игры
    Font font; // Шрифт для отображения очков
    Text scoreText; // Текст для отображения счета
    bool isGameOver; // Флаг для проверки состояния игры

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