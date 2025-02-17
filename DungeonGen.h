#ifndef GRID_H
#define GRID_H
#include "common.h"

struct grid {
    Vector2 dimensions;
    Vector2 tileSize;
    std::vector<tile> tiles;
    std::vector<CellType> cellContents;

    grid(Vector2 dimensions, Vector2 tileSize)
        : dimensions(dimensions), tileSize(tileSize)
    {
        int cols = static_cast<int>(dimensions.x);
        int rows = static_cast<int>(dimensions.y);

        // Create floor tiles.
        for (int j = 0; j < rows; ++j) {
            for (int i = 0; i < cols; ++i) {
                tile tile;
                tile.position = { i * tileSize.x, j * tileSize.y };
                tile.size = tileSize;
                tile.x = i;
                tile.y = j;
                tile.solid = false;
                tiles.push_back(tile);
            }
        }

        // Create wall tiles.
        for (int i = 0; i < cols; ++i) {
            tiles.push_back({ i, 0, true });
            tiles.push_back({ i, rows - 1, true });
        }
        for (int j = 1; j < rows - 1; ++j) {
            tiles.push_back({ 0, j, true });
            tiles.push_back({ cols - 1, j, true });
        }

        cellContents.resize(cols * rows, CELL_EMPTY);

        // Example update for cellContents (update as needed).
        for (const tile &t : tiles) {
            if (t.x < cols && t.y < rows) {
                int cellIndex = t.y * cols + t.x;
                cellContents[cellIndex] = t.solid ? CELL_ENEMY : CELL_TRAP;
            }
        }
    }
};

// Global instance (consider moving to a .cpp file)
static const grid myGrid(GRID_DIMENSIONS, TILE_SIZE);

// Renamed function to avoid conflict with Raylib's DrawGrid.
void DrawDungeonGrid(const grid &myGrid);

#endif // GRID_H
