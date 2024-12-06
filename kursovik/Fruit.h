#ifndef FRUIT_H
#define FRUIT_H

class Fruit {
public:
    int x, y;

    Fruit(int startX, int startY);
    void respawn(int width, int height);
};

#endif // FRUIT_H
