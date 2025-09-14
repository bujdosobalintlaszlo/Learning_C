#ifndef SNAKE_H
#define SNAKE_H

#include "map.h"

typedef enum {
    LEFT,
    RIGHT,
    UP,
    DOWN
} Direction;

typedef struct {
    int xHead;
    int yHead;
    int length;
    Direction direction;
    int **body; // body[i][0] = x, body[i][1] = y
} Snake;

Snake* createSnake(int startX, int startY);
void destroySnake(Snake* snake);
void moveSnake(Snake* snake);
int checkCollision(Snake* snake, int mapSize);
void growSnake(Snake* snake);
void placeSnakeOnMap(Snake* snake);

#endif
