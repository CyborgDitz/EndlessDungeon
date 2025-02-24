#include "dungeonController.h"
void generateRandomGrid() {
    srand(static_cast<unsigned>(time(nullptr)));
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            int randomTile = rand() % 6;
            CellType tileType = static_cast<CellType>(randomTile);
            grid.cells[y][x] = tileType;
        }
    }
}
