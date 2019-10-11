#include <LedControl.h>
#include "snake.h"
#include "fruit.h"
void setup()
{
  Serial.begin(9600);
  Serial.println("Welcome to Snakeduino");

  unsigned long previousMillis = 0;
  unsigned long currentMillis;
  randomSeed(analogRead(1));
  LedControl screen = LedControl(12, 11, 10, 1);
  screen.shutdown(0, false);
  screen.setIntensity(0, 1);

  Snake snake = Snake();

  snake.print(screen);
  //Fruit fruit = Fruit(snake, screen);

  bool gameover = false;
  while (!gameover)
  {
    snake.updateDirection();
    currentMillis = millis();
    if (currentMillis - previousMillis >= 300)
    {
      previousMillis = currentMillis;
      snake.move(screen);
      Serial.println("bucle");

    }
  }

}

void loop()
{
  ;
}