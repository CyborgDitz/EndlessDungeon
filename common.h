#ifndef COMMON_H
#define COMMON_H

#include "raylib.h"
#include "raymath.h"
#include "gameConfig.h"
#include <vector>
#include <map>
#include <ctime>
#include <iostream>


static const int GRID_SIZE = 33;
static const int TILE_SIZE = 28;
static const int SCREEN_WIDTH = GRID_SIZE * TILE_SIZE;
static const int SCREEN_HEIGHT = GRID_SIZE * TILE_SIZE;

using namespace std;

enum CellType {
    WALL = 0,
    TRAP,
    LOOT,
    ENEMY,
    STAIRS,
    EMPTY
};

enum TileEffect {
    DAMAGE_PLAYER,
    HEAL_PLAYER,
    PUSH_PLAYER,
    BLOCK_PLAYER,
    NEXT_LEVEL,
    CLEAR_TILE
};

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

static bool inBounds(int y, int x) {
    return (y >= 0 && y < GRID_SIZE &&
            x >= 0 && x < GRID_SIZE);
}
struct TileCounters {
    int wallCount;
    int trapCount;
    int lootCount;
    int enemyCount;
    int stairsCount;
    int emptyCount;

    TileCounters()
        : wallCount(0), trapCount(0), lootCount(0), enemyCount(0), stairsCount(0), emptyCount(0) {}
};
extern Grid grid;
extern TileCounters tileCounters;

typedef map<CellType, vector<TileEffect>> TileEffectsMap;

extern TileEffectsMap tileEffects;

#endif // COMMON_H
