#ifndef MAP_H
#define MAP_H

#define EMPTY 0
#define APPLE 1
#define BORDER 2
#define SNAKE 3

extern int **map;

void initializeMap(int mapSize);
void placeApple(int mapSize, int level);
void printMap(int mapSize);
void clrscr();

#endif
