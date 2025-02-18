#ifndef COMMON_H
#define COMMON_H

#include "raylib.h"
#include "raymath.h"
#include "gameConfig.h"
#include <vector>
#include <map>
#include <ctime>
#include <iostream>

// Constants
static const int GRID_SIZE = 8;
static const int TILE_SIZE = 64;
static const int SCREEN_WIDTH = GRID_SIZE * TILE_SIZE;
static const int SCREEN_HEIGHT = GRID_SIZE * TILE_SIZE;

using namespace std;

// Enums
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
    int x;
    int y;
    bool solid;

    Tile(int x = 0, int y = 0, bool solid = false)
        : x(x), y(y), solid(solid) {}
} Tile;

typedef struct Grid {
    CellType cells[GRID_SIZE][GRID_SIZE];

    Grid() {
        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                cells[i][j] = EMPTY;
            }
        }
    }
} Grid;


extern Grid grid;

typedef std::map<CellType, std::vector<TileEffect>> TileEffectsMap;

extern TileEffectsMap tileEffects;

#endif // COMMON_H
