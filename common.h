
#ifndef COMMON_H
#define COMMON_H

#include "raylib.h"
#include <vector>
#include "raymath.h"
#include <ctime>


const int GRID_SIZE = 8;
const int TILE_SIZE = 64;
const int SCREEN_WIDTH = GRID_SIZE * TILE_SIZE;
const int SCREEN_HEIGHT = GRID_SIZE * TILE_SIZE;
using namespace std;

enum CellType {
    WALL,
    ENEMY,
    LOOT,
    TRAP,
    STAIRS,
    EMPTY
};

typedef struct Tile {
    int x, y;
    bool solid;

    Tile(int x = 0, int y = 0, bool solid = false) : x(x), y(y), solid(solid) {}
} tile;

#endif //COMMON_H
