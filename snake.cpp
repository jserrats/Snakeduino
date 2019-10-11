#include "snake.h"
#define X 0
#define Y 1


void Snake::print(LedControl  screen){
    for (int i = 0; i < size; i++) {
    screen.setLed(0, dots[i][X], dots[i][Y], true);
    }
}