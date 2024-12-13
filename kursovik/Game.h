#ifndef GAME_H
#define GAME_H


#include "Snake.h"
#include "Fruit.h"
#include <sstream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Game {
private:
    const int N = 70; // ���������� ����� �� �����������
    const int M = 40; // ���������� ����� �� ���������
    const int size = 16; // ������ ����� ������
    RenderWindow window;
    Snake snake;
    Fruit fruit;
    Clock clock;
    float timer;
    float delay;
    int score; // ���������� ��� �������� �����������
    int totalGamesPlayed; // ����� ���-�� ��������� ���
    int totalScore; // ������������ ���� �� ��� ����
    Font font; // ����� ��� ����������� �����
    Text scoreText; // ����� ��� ����������� �����
    bool isGameOver; // ���� ��� �������� ��������� ����

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