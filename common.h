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


typedef struct {
    int  x;
    int  y;
    bool visitedCell;
    bool visitedPath;
    bool foundPath;
    bool walls[4];
    bool solid;
    CellType type;
} Tile;

static Tile createTile(int x, int y, bool solid, CellType type) {
    Tile tile;
    tile.x = x;
    tile.y = y;
    tile.solid = solid;
    tile.visitedCell = false;
    tile.visitedPath = false;
    tile.foundPath = false;
    tile.walls[0] = true;
    tile.walls[1] = true;
    tile.walls[2] = true;
    tile.walls[3] = true;
    tile.type = type;
    return tile;
}


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
