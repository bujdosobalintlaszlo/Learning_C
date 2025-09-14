#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "map.h"

int **map;

void initializeMap(int mapSize) {
    map = malloc(mapSize * sizeof(int*));
    for (int i = 0; i < mapSize; i++) {
        map[i] = malloc(mapSize * sizeof(int));
        for (int j = 0; j < mapSize; j++) {
            if (i == 0 || i == mapSize - 1 || j == 0 || j == mapSize - 1) {
                map[i][j] = BORDER;
            } else {
                map[i][j] = EMPTY;
            }
        }
    }
}

void placeApple(int mapSize, int level) {
    for (int i = 0; i < level; i++) {
        int row = rand() % mapSize;
        int col = rand() % mapSize;
        if (map[row][col] == EMPTY) {
            map[row][col] = APPLE;
        }
    }
}

void clrscr() {
    system("cls"); // Windows clear
}

void printMap(int mapSize) {
    clrscr();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < mapSize; i++) {
        for (int j = 0; j < mapSize; j++) {
            switch (map[i][j]) {
                case EMPTY:
                    SetConsoleTextAttribute(hConsole, 14);
                    printf("   ");
                    break;
                case APPLE:
                    SetConsoleTextAttribute(hConsole, 12);
                    printf(" @ ");
                    break;
                case BORDER:
                    SetConsoleTextAttribute(hConsole, 15);
                    printf(" * ");
                    break;
                case SNAKE:
                    SetConsoleTextAttribute(hConsole, 10);
                    printf(" O ");
                    break;
            }
        }
        printf("\n");
    }

    SetConsoleTextAttribute(hConsole, 7);
}



