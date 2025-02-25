#include "dungeonController.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>

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

void generateMazeDungeon() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(nullptr)));

    // Initialize every cell to WALL.
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            grid.cells[y][x] = WALL;
        }
    }

    // Start at (1,1) so that the border remains intact.
    int startX = 1, startY = 1;
    grid.cells[startY][startX] = EMPTY;

    // The growing tree algorithm uses a list of active cells.
    vector<pair<int,int>> cellList;
    cellList.push_back({startY, startX});

    while (!cellList.empty()) {
        // For a depth-first search behavior, select the most recently added cell.
        int index = cellList.size() - 1;
        pair<int,int> current = cellList[index];
        int cy = current.first;
        int cx = current.second;

        // Find all unvisited neighbors two cells away.
        vector<pair<int,int>> neighbors;

        // Up: check cell two steps up.
        if (cy - 2 > 0 && grid.cells[cy - 2][cx] == WALL)
            neighbors.push_back({cy - 2, cx});

        // Down: check cell two steps down.
        if (cy + 2 < GRID_SIZE - 1 && grid.cells[cy + 2][cx] == WALL)
            neighbors.push_back({cy + 2, cx});

        // Left: check cell two steps to the left.
        if (cx - 2 > 0 && grid.cells[cy][cx - 2] == WALL)
            neighbors.push_back({cy, cx - 2});

        // Right: check cell two steps to the right.
        if (cx + 2 < GRID_SIZE - 1 && grid.cells[cy][cx + 2] == WALL)
            neighbors.push_back({cy, cx + 2});

        if (!neighbors.empty()) {
            // Randomly select one of the unvisited neighbors.
            int randIndex = rand() % neighbors.size();
            pair<int,int> nextCell = neighbors[randIndex];
            int ny = nextCell.first;
            int nx = nextCell.second;

            // Remove the wall between current cell and the chosen neighbor.
            int wallY = cy + (ny - cy) / 2;
            int wallX = cx + (nx - cx) / 2;
            grid.cells[wallY][wallX] = EMPTY;
            grid.cells[ny][nx] = EMPTY;

            // Add the neighbor to the active cell list.
            cellList.push_back({ny, nx});
        } else {
            // No unvisited neighbors; remove this cell from the list.
            cellList.pop_back();
        }
    }
}

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

