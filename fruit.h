#ifndef FRUIT_H
#define FRUIT_H

#include <LedControl.h>
#include "snake.h"
class Fruit{
    //private:
        //LedControl _screen;
    public:
        byte x;
        byte y;
        Fruit(Snake snake, LedControl screen);
};
#endif