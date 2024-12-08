#include "Snake.h"

Snake::Snake(int initialSize) {
    direction = 0; //движение вниз
    body.resize(initialSize);
    prevDirection = Vector2i(0, 1); 

    for (int i = 0; i < initialSize; ++i) {
        body[i].setRadius(8);
        body[i].setFillColor(Color::White);
        body[i].setPosition(10 * 16, 10 * 16 + i * 16); 
    }
}

void Snake::move() {
    // Сохранение предыдущие позиции сегментов
    for (int i = body.size() - 1; i > 0; --i) {
        body[i].setPosition(body[i - 1].getPosition());
    }

    // Изменение положение головы в зависимости от направления
    if (direction == 0) body[0].move(0, 16);   // down
    if (direction == 1) body[0].move(-16, 0);  // left
    if (direction == 2) body[0].move(16, 0);   // right
    if (direction == 3) body[0].move(0, -16);  // up
}

void Snake::grow() {
    CircleShape newSegment(8);
    newSegment.setFillColor(Color::White);
    body.push_back(newSegment); // Добавить новый сегмент в конец змейки
}

void Snake::setDirection(int dir) {
    // Проверяем, не является ли новое направление противоположным
    if ((dir == 0 && direction == 3) || (dir == 1 && direction == 2) ||
        (dir == 2 && direction == 1) || (dir == 3 && direction == 0)) {
        return; // Остановка выполнения, если змея движется в противоположном направлении.
    }
    direction = dir;
}

std::vector<CircleShape>& Snake::getBody() {
    return body;
}



int Snake::getLength() {
    return body.size(); // возвращение длины змеи
}
