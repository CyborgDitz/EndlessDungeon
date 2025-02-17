#include "common.h"
#ifndef PLAYERDATA_H
#define PLAYERDATA_H
typedef struct Player{
    int x,y;
    int health {100};
    Player(int startX = 0, int startY = 0, int startHealth = 100)
       : x(startX), y(startY), health(startHealth) {}
} player;
#endif //PLAYERDATA_H
