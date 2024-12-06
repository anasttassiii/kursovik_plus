#include "Fruit.h"
#include <cstdlib>

Fruit::Fruit(int startX, int startY) {
    x = startX;
    y = startY;
}

void Fruit::respawn(int width, int height) {
    x = rand() % width;
    y = rand() % height;
}