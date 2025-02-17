
#ifndef COMMON_H
#define COMMON_H
#define SCREEN_WIDTH  1080
#define SCREEN_HEIGHT 720

#include "raylib.h"
#include "raymath.h"
#include <stdint.h>
#include <vector>
enum CellType {
    CELL_EMPTY = 0,
    CELL_PLAYER,
    CELL_ENEMY,
    CELL_LOOT,
    CELL_TRAP,
    CELL_STAIRS
};

typedef struct {
    Vector2 position;
    Vector2 size;
    int x, y;
    bool solid;
} tile;

static constexpr Vector2 gridCellSize = { 64.0f, 64.0f };
static const Vector2 GRID_DIMENSIONS = { 10.0f, 8.0f };
static const Vector2 TILE_SIZE = { 64.0f, 64.0f };


#endif //COMMON_H
