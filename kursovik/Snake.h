#ifndef SNAKE_H
#define SNAKE_H


#include <vector>
#include <SFML/Graphics.hpp>
using namespace sf;


class Snake {
private:
    std::vector<CircleShape> body; // Вектор для хранения сегментов змеи
    int direction;
    Vector2i prevDirection; // Для сохранения предыдущего направления


public:
    Snake(int initialSize);
    void move();
    void grow();
    void setDirection(int dir);
    std::vector<CircleShape>& getBody();
    bool checkCollisionBounds(int width, int height);
    void checkSelfCollision();

    int getLength();
};

#endif // SNAKE_H