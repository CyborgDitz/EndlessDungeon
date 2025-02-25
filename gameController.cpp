//
// Created by sebba on 2025-02-25.
//

#include "gameController.h"
void fillEmptyCells() {
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            if (grid.cells[y][x] == EMPTY) {
                // Do something with the empty tile at (x, y)
                cout << "Empty tile found at: (" << x << ", " << y << ")\n";
            }
        }
    }
}
void dungeonSetup() {
    generateRandomGrid();
    generateMazeDungeon();
    fillEmptyCells();
}
