#ifndef SNAKE_H
#define SNAKE_H


#include <vector>
#include <SFML/Graphics.hpp>



class Snake {
private:
    

public:
    Snake(int initialSize);
    void move();
    void grow();
    void setDirection(int dir);
    int getLength();
};

#endif // SNAKE_H