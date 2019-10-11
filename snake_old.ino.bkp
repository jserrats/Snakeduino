#include <LedControl.h>
#define SIZE 8
#define MAX_LENGTH SIZE*SIZE

enum buttons {RIGHT, UP, DOWN, LEFT, EXTRA};
buttons clickedButton;


const byte analogInPin = A0;

unsigned long previousMillis = 0;
unsigned long currentMillis;

LedControl screen = LedControl(12, 11, 10, 1);
 
void setup() {
  randomSeed(analogRead(1));
  Serial.begin(9600);
  screen.shutdown(0, false);
  screen.setIntensity(0, 1);
}

void loop() {
  screen.clearDisplay(0);
  byte snake_size = 5;
  byte snake[MAX_LENGTH][2] = {{3, 3}, {4, 3}, {5, 3}, {6, 3}, {7, 3}};
  byte first = 0;
  byte last = snake_size - 1;
  boolean first_move = true;


  for (int i = 0; i < snake_size; i++) {
    screen.setLed(0, snake[i][0], snake[i][1], true);
  }

  byte dotx, doty;
  print_dot(snake, first, snake_size, dotx, doty);

  boolean gameover = false;
  while (!gameover) {
    clickedButton = readButton(first_move);
    currentMillis = millis();

    if (currentMillis - previousMillis >= 300) {
      previousMillis = currentMillis;

      screen.setLed(0, snake[last][0], snake[last][1], false);

      switch (clickedButton) {
        case UP:
          snake[last][0] = (snake[first][0] + SIZE - 1) % SIZE;
          snake[last][1] = snake[first][1];
          break;
        case LEFT:
          snake[last][1] = (snake[first][1] + SIZE - 1) % SIZE;
          snake[last][0] = snake[first][0];
          break;
        case RIGHT:
          snake[last][1] = (snake[first][1] + 1) % SIZE;
          snake[last][0] = snake[first][0];
          break;
        case DOWN:
          snake[last][0] = (snake[first][0] + 1) % SIZE;
          snake[last][1] = snake[first][1];
          break;
        case EXTRA:
          break;
      }

      first = (first + snake_size - 1 ) % snake_size;
      last = (last + snake_size - 1) % snake_size;

      for (byte i = (first + 1) % snake_size; i != first; i = (i + 1) % snake_size) {
        if ((snake[first][0] == snake[i][0]) && (snake[first][1] == snake[i][1])) {
          gameover = true;
          screen.shutdown(0, true);
          delay(100);
          screen.shutdown(0, false);
          break;
        }
      }

      if ((snake[first][0] == dotx) && (snake[first][1] == doty)) {
        Serial.println("dot");
        print_dot(snake, first, snake_size, dotx, doty);
      }

      screen.setLed(0, snake[first][0], snake[first][1], true);
    }
  }
}

void print_dot(byte snake[][2], byte first, byte snake_size, byte &x, byte &y) {
  boolean flag = true;
  while (flag) {
    flag = false;
    x = random(8);
    y = random(8);

    for (byte i = 0; i < snake_size; i++) {
      if ((snake[i][0] == x) && (snake[i][1] == y)) {
        flag = true;
        break;
      }
    }
  }
  screen.setLed(0, x, y, true);
}

enum buttons readButton(boolean &first_move) {
  if (first_move) {
    first_move = false;
    return UP;
  }
  byte sensorValue = analogRead(analogInPin);

  delay(50);
  if ( 100 < sensorValue && sensorValue < 200) {
    return DOWN;
  }
  else if ( 0 <= sensorValue && sensorValue < 10) {
    return RIGHT;
  }
  else if ( 65 <= sensorValue && sensorValue < 75) {
    return  UP;
  }
  else if ( 245 < sensorValue && sensorValue < 250) {
    return  LEFT;
  }
  else if (228 < sensorValue && sensorValue < 235) {
    return EXTRA;
  }
}