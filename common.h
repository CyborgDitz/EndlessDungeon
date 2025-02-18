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

// Tile struct
typedef struct Tile {
    int x;
    int y;
    bool solid;

    Tile(int x = 0, int y = 0, bool solid = false)
        : x(x), y(y), solid(solid) {}
} Tile;

// Grid struct
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

// Declare a global Grid instance (defined in common.cpp)
extern Grid gGrid;

// Use typedef instead of 'using' for the map
typedef std::map<CellType, std::vector<TileEffect>> TileEffectsMap;

// Declare a global TileEffectsMap instance (defined in common.cpp)
extern TileEffectsMap gTileEffects;

#endif // COMMON_H
