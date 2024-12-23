#include "Snake.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Snake::Snake(int initialSize) {
    direction = 0; //�������� ����
    body.resize(initialSize);
    prevDirection = Vector2i(0, 1); 

    for (int i = 0; i < initialSize; ++i) {
        body[i].setRadius(8);
        body[i].setFillColor(Color::Green);
        body[i].setPosition(10 * 16, 10 * 16 + i * 16); 
    }
}

void Snake::move() {
    // ���������� ���������� ������� ���������
    for (int i = body.size() - 1; i > 0; --i) {
        body[i].setPosition(body[i - 1].getPosition());
    }

    // ��������� ��������� ������ � ����������� �� �����������
    if (direction == 0) body[0].move(0, 16);   // down
    if (direction == 1) body[0].move(-16, 0);  // left
    if (direction == 2) body[0].move(16, 0);   // right
    if (direction == 3) body[0].move(0, -16);  // up
}

void Snake::grow() {
    CircleShape newSegment(8);
    newSegment.setFillColor(Color::Green);
    body.push_back(newSegment); // �������� ����� ������� � ����� ������
}

void Snake::setDirection(int dir) {
    // ���������, �� �������� �� ����� ����������� ���������������
    if ((dir == 0 && direction == 3) || (dir == 1 && direction == 2) ||
        (dir == 2 && direction == 1) || (dir == 3 && direction == 0)) {
        return; // ��������� ����������, ���� ���� �������� � ��������������� �����������.
    }
    direction = dir;
}

std::vector<CircleShape>& Snake::getBody() {
    return body;
}

bool Snake::checkCollisionBounds(int width, int height) {
    // ��������, ������� �� ������ �� ������� ����
    Vector2f headPos = body[0].getPosition();
    return (headPos.x < 0 || headPos.x >= width || headPos.y < 0 || headPos.y >= height);
}

bool Snake::checkSelfCollision() {
    int flag = 0;
    if (body.size() != 4) {
        for (int i = 1; i < body.size(); ++i) {
            if (body[0].getPosition() == body[i].getPosition()) {
                // ���� ������ ������������ � �����
                flag = 1;
                break;
            }
        }
    }
    if (flag == 1) return true;
    else return false;
}


int Snake::getLength() {
    return body.size(); // ����������� ����� ����
}
