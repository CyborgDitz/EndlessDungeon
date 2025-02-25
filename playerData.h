
#ifndef PLAYERDATA_H
#define PLAYERDATA_H
#include "common.h"
typedef struct Player{
    int x,y;
    int health {100};
    explicit Player(int startX = 1, int startY = 1, int startHealth = 100)
       : x(startX), y(startY), health(startHealth) {}
} player;
#endif //PLAYERDATA_H
