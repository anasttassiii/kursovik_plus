#ifndef SNAKE_H
#define SNAKE_H


#include <vector>



class Snake {
private:
    

public:
    Snake(int initialSize);
    void move();
    void grow();
    void setDirection(int dir);
    bool checkCollisionBounds(int width, int height);
    void checkSelfCollision();
    int getLength();
};

#endif // SNAKE_H