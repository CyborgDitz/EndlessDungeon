#include "common.h"

#ifndef DUNGEONCONTROLLER_H
#define DUNGEONCONTROLLER_H

struct DesignatedTiles {
    int traps;
    int loot;
    int enemies;
    int stairs;
};

extern DesignatedTiles designatedTiles;

void generateRandomGrid();
void generateMazeDungeon(int playerX, int playerY);
void countTiles();
#endif //DUNGEONCONTROLLER_H
