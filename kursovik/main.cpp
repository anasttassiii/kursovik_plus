#include "Game.h"
#include <iostream>
#include "snake.h"
#include <vector>
#include <windows.h>
#include <conio.h>
#include <sstream> // Для преобразования чисел в строки
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>


int main() {
    Game game; // создание игры
    game.run(); // запуск игры
    return 0;
}
