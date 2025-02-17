#ifndef DATA_H
#define DATA_H

#include "common.h"
#include "hashing.h"
#include <vector>
#include <string>
#include <unordered_map>

enum CellType {
    CELL_EMPTY = 0,
    CELL_PLAYER,
    CELL_ENEMY,
    CELL_LOOT,
    CELL_TRAP,
    CELL_WALL,
    NUM_CELL_TYPES
};

static const Color cellColors[NUM_CELL_TYPES] = {
    RAYWHITE,
    BLUE,
    RED,
    GOLD,
    DARKGRAY,
    BLACK
};

typedef struct Cell {
    CellType type;
    Color color;
    bool solid;
    std::vector<std::string> effects;
    int damage;
    int gridX, gridY;
    Vector2 position;
    Vector2 size;
} cell;

static const std::vector<Cell> cellPrototypes = {

    { CELL_EMPTY,   cellColors[CELL_EMPTY],   false,  {},                  0,      0,     0,     {0.0f, 0.0f},       {32.0f, 32.0f} },
    { CELL_PLAYER,  cellColors[CELL_PLAYER],  true,   {"can move"},        0,      1,     0,     {32.0f, 0.0f},      {32.0f, 32.0f} },
    { CELL_ENEMY,   cellColors[CELL_ENEMY],   true,   {"moves to player"}, 10,    2,     0,     {64.0f, 0.0f},      {32.0f, 32.0f} },
    { CELL_LOOT,    cellColors[CELL_LOOT],    false,  {"pickup"},          0,      3,     0,     {96.0f, 0.0f},      {32.0f, 32.0f} },
    { CELL_TRAP,    cellColors[CELL_TRAP],    false,  {"damages"},         20,     4,     0,     {128.0f, 0.0f},     {32.0f, 32.0f} },
    { CELL_WALL,    cellColors[CELL_WALL],    true,   {"pushes"},          20,     5,     0,     {160.0f, 0.0f},     {32.0f, 32.0f} }
};

typedef struct Grid {
    Vector2 dimensions;
    Vector2 tileSize;
    std::unordered_map<CellKey, Cell, CellKeyHasher> cellMap;

    Grid(Vector2 dimensions, Vector2 tileSize)
        : dimensions(dimensions), tileSize(tileSize)
    {
        initializeCells();
    }

private:
    void initializeCells() {
        int cols = static_cast<int>(dimensions.x);
        int rows = static_cast<int>(dimensions.y);
        for (int j = 0; j < rows; ++j) {
            for (int i = 0; i < cols; ++i) {
                Cell cell;
                cell.gridX = i;
                cell.gridY = j;
                cell.position = { i * tileSize.x, j * tileSize.y };
                cell.size = tileSize;
                cell.type = CELL_EMPTY;
                cell.color = cellColors[CELL_EMPTY];
                cell.damage = 0;
                cell.effects = {"none"};
                cell.solid = false;
                CellKey key{ i, j };
                cellMap.insert({ key, cell });
            }
        }
    }
}grid;

typedef struct Player {
    Vector2 position;
    Vector2 size;
    int health;
}player;

static const Grid myGrid(GRID_DIMENSIONS, TILE_SIZE);

#endif // DATA_H
