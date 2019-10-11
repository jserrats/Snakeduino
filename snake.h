#ifndef SNAKE_H
#define SNAKE_H

#include <LedControl.h>
#define SIZE 8
#define MAX_LENGTH SIZE*SIZE

class Snake 
{
private:
    enum directions {RIGHT, UP, DOWN, LEFT};
    byte first = 0;
    byte last = size - 1;
    directions current = UP;

public:
//    byte dots[MAX_LENGTH][2] = {{3, 3}, {4, 3}, {5, 3}, {6, 3}, {7, 3}};
    byte dots[MAX_LENGTH][2] = {{3, 3}};
    byte size = 1;
    void print(LedControl screen);
    void updateDirection();
    void move(LedControl screen);
};

#endif