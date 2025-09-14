#include <stdio.h>
#include <stdlib.h>
#include "snake.h"

Snake* createSnake(int startX, int startY) {
    Snake* s = malloc(sizeof(Snake));
    s->xHead = startX;
    s->yHead = startY;
    s->length = 2; // head + tail
    s->direction = RIGHT;

    s->body = malloc(sizeof(int*) * 100); // max length
    for (int i = 0; i < s->length; i++) {
        s->body[i] = malloc(2 * sizeof(int));
    }

    // Head
    s->body[0][0] = startX;
    s->body[0][1] = startY;

    // Tail
    s->body[1][0] = startX - 1;
    s->body[1][1] = startY;

    return s;
}

void destroySnake(Snake* snake) {
    for (int i = 0; i < snake->length; i++) {
        free(snake->body[i]);
    }
    free(snake->body);
    free(snake);
}

void moveSnake(Snake* snake) {
    // shift body
    for (int i = snake->length - 1; i > 0; i--) {
        snake->body[i][0] = snake->body[i - 1][0];
        snake->body[i][1] = snake->body[i - 1][1];
    }

    // move head
    switch (snake->direction) {
        case UP:    snake->yHead--; break;
        case DOWN:  snake->yHead++; break;
        case LEFT:  snake->xHead--; break;
        case RIGHT: snake->xHead++; break;
    }

    snake->body[0][0] = snake->xHead;
    snake->body[0][1] = snake->yHead;
}

int checkCollision(Snake* snake, int mapSize) {
    if (snake->xHead <= 0 || snake->xHead >= mapSize - 1 ||
        snake->yHead <= 0 || snake->yHead >= mapSize - 1) {
        return 1; // hit wall
    }
    for (int i = 1; i < snake->length; i++) {
        if (snake->xHead == snake->body[i][0] &&
            snake->yHead == snake->body[i][1]) {
            return 1; // hit self
        }
    }
    return 0;
}

void growSnake(Snake* snake) {
    snake->length++;
    snake->body[snake->length - 1] = malloc(2 * sizeof(int));
    snake->body[snake->length - 1][0] = snake->body[snake->length - 2][0];
    snake->body[snake->length - 1][1] = snake->body[snake->length - 2][1];
}

void placeSnakeOnMap(Snake* snake) {
    for (int i = 0; i < snake->length; i++) {
        int x = snake->body[i][0];
        int y = snake->body[i][1];
        map[y][x] = SNAKE;
    }
}
