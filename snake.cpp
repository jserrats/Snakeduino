#include "snake.h"

Snake::Snake()
{
    insert_last(3, 3);
    serialDebug();
}

void Snake::print(LedControl screen)
{
    screen.clearDisplay(0);

    node *temp = new node;
    temp = head;
    while (temp != NULL)
    {
        screen.setLed(0, temp->x, temp->y, true);
        temp = temp->next;
    }
}

void Snake::serialDebug()
{
    Serial.print("head x: ");
    Serial.print(head->x);
    Serial.print(" head y: ");
    Serial.println(head->y);
    Serial.print("tail x: ");
    Serial.print(tail->x);
    Serial.print(" tail y: ");
    Serial.println(tail->y);
    Serial.println();
}
void Snake::move(LedControl screen)
{
    // UP
    insert_start((head->x + SIZE - 1) % SIZE, head->y);
    delete_last();
    print(screen);
    serialDebug();

}

/* add a new node at the tail*/
void Snake::insert_last(int x, int y)
{
    node *temp = new node;
    temp->x = x;
    temp->y = y;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void Snake::insert_start(int x, int y)
{
    node *temp = new node;
    temp->x = x;
    temp->y = y;
    temp->next = head;
    head = temp;
}

void Snake::delete_last()
{
    node *current = new node;
    node *previous = new node;
    current = head;
    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }
    tail = previous;
    previous->next = NULL;
    delete current;
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

    //Serial.print(current);
}