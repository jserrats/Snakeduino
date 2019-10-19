#ifndef SNAKE_H
#define SNAKE_H

#include <LedControl.h>
#define SIZE 8
#define MAX_LENGTH SIZE *SIZE
struct node
{
    int x,y;
    node *next;
};

class Snake
{
private:
    enum directions
    {
        RIGHT,
        UP,
        DOWN,
        LEFT
    };
    directions current = UP;
    node *head, *tail;
    void insert_start(int x, int y);
    void insert_last(int x, int y);
    void delete_last();
    
public: 
    Snake();
    void print(LedControl screen);
    void move(LedControl screen);
    void updateDirection();
    void serialDebug();
    list()
    {
      head=NULL;
      tail=NULL;
    }
};

#endif