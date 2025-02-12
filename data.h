
#ifndef DATA_H
#define DATA_H
#include "common.h"

enum CellType {
    CELL_EMPTY = 0,
    CELL_PLAYER,
    CELL_ENEMY,
    CELL_LOOT,
    CELL_TRAP
};

typedef struct {
    Vector2 position;
    Vector2 size;
} tile;

typedef struct {
    int x, y;
    bool solid;
} dungBlock;


struct grid {
    Vector2 dimensions;
    Vector2 tileSize;
    std::vector<tile> tiles;
    std::vector<dungBlock> blocks;
    std::vector<CellType> cellContents;

    grid(Vector2 dimensions, Vector2 tileSize)
        : dimensions(dimensions), tileSize(tileSize)
    {
        int cols = static_cast<int>(dimensions.x);
        int rows = static_cast<int>(dimensions.y);

        for (int j = 0; j < rows; ++j) {
            for (int i = 0; i < cols; ++i) {
                tile t;
                t.position = { i * tileSize.x, j * tileSize.y };
                t.size = tileSize;
                tiles.push_back(t);
            }
        }

        for (int i = 0; i < cols; ++i) {
            blocks.push_back({ i, 0, true });
            blocks.push_back({ i, rows - 1, true });
        }

        for (int j = 1; j < rows - 1; ++j) {
            blocks.push_back({ 0, j, true });
            blocks.push_back({ cols - 1, j, true });
        }

        cellContents.resize(cols * rows, CELL_EMPTY);
    }
};

struct player {
    Vector2 position;
    Vector2 size;
    int health;
   /** player(Vector2 pos = { 0, 0 }, Vector2 size = { 64, 64 }, int hp = 100)
        : Position(pos), Size(size), health(hp)
    {}**/
};

#endif //DATA_H
