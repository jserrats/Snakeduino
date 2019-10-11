#include <LedControl.h>
#include "snake.h"
#include "fruit.h"

void setup(){
  randomSeed(analogRead(1));
  LedControl screen = LedControl(12, 11, 10, 1);
  screen.shutdown(0, false);
  screen.setIntensity(0, 1);

  Snake snake = Snake();
  
  snake.print(screen); 
  Fruit fruit = Fruit(snake,screen);
  
}

void loop(){
  ;
}