#include "fruit.h"
#include <LedControl.h>

Fruit::Fruit(Snake snake, LedControl _screen){
  //_screen = screen;
  boolean flag = true;
  while (flag) {
    flag = false;
    x = random(8);
    y = random(8);

        /*for (byte i = 0; i < snake.size; i++) {
            if ((snake.dots[i][0] == x) && (snake.dots[i][1] == y)) {
                flag = true;
                break;
            }
        }*/
    }
   _screen.setLed(0,x,y,true); 
}