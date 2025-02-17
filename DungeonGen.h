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
                tile t;
                t.position = { i * tileSize.x, j * tileSize.y };
                t.size = tileSize;
                t.x = i;          // Set grid x-coordinate
                t.y = j;          // Set grid y-coordinate
                t.solid = false;  // Assume floor tiles are non-solid
                tiles.push_back(t);
            }
        }

        // Create boundary (wall) tiles.
        // For simplicity, these tiles are added to the same vector.
        // In a more complex system, you might want to separate floor tiles from walls.
        for (int i = 0; i < cols; ++i) {
            // Top wall tile.
            {
                tile t;
                t.x = i;
                t.y = 0;
                t.position = { i * tileSize.x, 0 };
                t.size = tileSize;
                t.solid = true;
                tiles.push_back(t);
            }
            // Bottom wall tile.
            {
                tile t;
                t.x = i;
                t.y = rows - 1;
                t.position = { i * tileSize.x, (rows - 1) * tileSize.y };
                t.size = tileSize;
                t.solid = true;
                tiles.push_back(t);
            }
        }
        for (int j = 1; j < rows - 1; ++j) {
            // Left wall tile.
            {
                tile t;
                t.x = 0;
                t.y = j;
                t.position = { 0, j * tileSize.y };
                t.size = tileSize;
                t.solid = true;
                tiles.push_back(t);
            }
            // Right wall tile.
            {
                tile t;
                t.x = cols - 1;
                t.y = j;
                t.position = { (cols - 1) * tileSize.x, j * tileSize.y };
                t.size = tileSize;
                t.solid = true;
                tiles.push_back(t);
            }
        }

        // Resize cellContents for the grid (one per cell in the original grid dimensions).
        cellContents.resize(cols * rows, CELL_EMPTY);

        // Update cell contents based on tile position.
        // NOTE: If multiple tiles share the same (x, y) coordinates (as with walls added above),
        // this loop may update the same cell more than once.
        for (const tile &t : tiles) {
            // Make sure t.x and t.y are within bounds before using them as indices.
            if (t.x < cols && t.y < rows) {
                int cellIndex = t.y * cols + t.x;

                if (t.x % 2 == 0)
                    cellContents[cellIndex] = CELL_ENEMY;
                else
                    cellContents[cellIndex] = CELL_TRAP;
            }
        }
    }
};


static const grid myGrid(GRID_DIMENSIONS, TILE_SIZE);

void DrawGrid(const grid &myGrid);

#endif // GRID_H
