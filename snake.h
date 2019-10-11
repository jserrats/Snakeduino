#ifndef SNAKE_H
#define SNAKE_H

#include <LedControl.h>
#define SIZE 8
#define MAX_LENGTH SIZE*SIZE

class Snake 
{
private:
    byte first = 0;
    byte last = size - 1;

public:
    byte dots[MAX_LENGTH][2] = {{3, 3}, {4, 3}, {5, 3}, {6, 3}, {7, 3}};
    byte size = 5;
    void print(LedControl screen);
};

#endif