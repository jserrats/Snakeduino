#include "snake.h"
#define X 0
#define Y 1

void Snake::print(LedControl screen)
{
    for (int i = 0; i < size; i++)
    {
        screen.setLed(0, dots[i][X], dots[i][Y], true);
        //Serial.println("Printing X: " +dots[i][X] + " Y: "+ dots[i][Y]);
    }
}

void Snake::move(LedControl screen)
{
    switch (current)
    {
    case UP:
        dots[last][X] = (dots[first][X] + SIZE - 1) % SIZE;
        dots[last][Y] = dots[first][Y];
        break;
    case LEFT:
        dots[last][Y] = (dots[first][Y] + SIZE - 1) % SIZE;
        dots[last][X] = dots[first][X];
        break;
    case RIGHT:
        dots[last][Y] = (dots[first][Y] + 1) % SIZE;
        dots[last][X] = dots[first][X];
        break;
    case DOWN:
        dots[last][X] = (dots[first][X] + 1) % SIZE;
        dots[last][Y] = dots[first][Y];
        break;
    }

    screen.setLed(0,dots[last][X], dots[last][Y],false);

    first = (first + size - 1) % size;
    last = (last + size - 1) % size;

    print(screen);
}

void Snake::updateDirection()
{
    byte sensorValue = analogRead(A0);

    delay(50);
    if (100 < sensorValue && sensorValue < 200)
    {
        current = DOWN;
    }
    else if (0 <= sensorValue && sensorValue < 10)
    {
        current = RIGHT;
    }
    else if (65 <= sensorValue && sensorValue < 75)
    {
        current = UP;
    }
    else if (245 < sensorValue && sensorValue < 250)
    {
        current = LEFT;
    }

    Serial.print(current);
}