#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "map.h"
#include "snake.h"

int main() {
    srand(time(NULL));
    int mapSize = 20;

    initializeMap(mapSize);
    placeApple(mapSize, 3);

    Snake* snake = createSnake(mapSize / 2, mapSize / 2);

    while (1) {
        // reset map each frame
        initializeMap(mapSize);
        placeApple(mapSize, 3);

        moveSnake(snake);

        if (checkCollision(snake, mapSize)) {
            printf("Game Over!\n");
            break;
        }

        placeSnakeOnMap(snake);
        printMap(mapSize);

        Sleep(300); // ms delay
    }

    destroySnake(snake);
    return 0;
}
