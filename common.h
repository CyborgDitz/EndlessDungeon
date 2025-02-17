
#ifndef COMMON_H
#define COMMON_H
#include "raylib.h"
#include "raymath.h"
#include "gameConfig.h"
#include <vector>
#include <map>
#include <ctime>
#include <iostream>


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

enum TileEffect {
    CLEAR_TILE,
    DAMAGE_PLAYER,
    HEAL_PLAYER,
    PUSH_PLAYER,
    NEXT_LEVEL
};

typedef struct Tile {
    int x, y;
    bool solid;

    Tile(int x = 0, int y = 0, bool solid = false) : x(x), y(y), solid(solid) {}
} tile;
extern std::map<CellType, std::vector<TileEffect>> tileEffects;
#endif //COMMON_H
