
#ifndef DUNGEONCONTROLLER_H
#define DUNGEONCONTROLLER_H

#include "common.h"

struct DesignatedTiles {
    int traps;
    int loot;
    int enemies;
    int stairs;
    int keys;
};


extern DesignatedTiles designatedTiles;

void generateRandomGrid();
void generateMazeDungeon(int playerX, int playerY);
void countTiles();
#endif //DUNGEONC7NTROLLER_H
