#ifndef COMMON_H
#define COMMON_H

#include "raylib.h"
#include "raymath.h"

#include <vector>
#include <map>
#include <ctime>
#include <iostream>


static const int GRID_SIZE = 15;
static const int SCREEN_WIDTH = 1200;
static const int SCREEN_HEIGHT = 1200;

static const int TILE_SIZE = std::min(SCREEN_WIDTH, SCREEN_HEIGHT) / GRID_SIZE;

static const Color TILE_COLORS[] = {
    DARKGRAY,
    DARKPURPLE,
    GOLD,
    SKYBLUE,
    RED,
    GREEN,
    WHITE
};


enum CellType {
    WALL,
    TRAP,
    LOOT,
    KEY,
    ENEMY,
    STAIRS,
    EMPTY
};

enum TileEffect {
    DAMAGE_PLAYER,
    HEAL_PLAYER,
    PUSH_PLAYER,
    JUMP_PLAYER,
    BLOCK_PLAYER,
    COLLECT_KEY,
    NEXT_LEVEL,
    CLEAR_TILE
};

typedef struct Grid {
    CellType cells[GRID_SIZE][GRID_SIZE]{};

    Grid() {
        for (auto & cell : cells) {
            for (auto & j : cell) {
                j = EMPTY;
            }
        }
    }
} Grid;

struct TileCounters {
    int wallCount;
    int trapCount;
    int lootCount;
    int keyCount;
    int enemyCount;
    int stairsCount;
    int emptyCount;

    TileCounters()
     : wallCount(0), trapCount(0), lootCount(0), keyCount(0),
        enemyCount(0), stairsCount(0), emptyCount(0) {}
};

static bool inBounds(int y, int x) {
    return (y >= 0 && y < GRID_SIZE && x >= 0 && x < GRID_SIZE);
}

template<typename Func>
void forEachCell(Func func) {
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            func(x, y);
        }
    }
}

extern Grid grid;
extern TileCounters tileCounters;
extern bool win;
typedef std::map<CellType, std::vector<TileEffect>> TileEffectsMap;
extern TileEffectsMap tileEffects;

#endif // COMMON_H
