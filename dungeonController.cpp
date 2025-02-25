#include "dungeonController.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>


void countTiles() {
    tileCounters = TileCounters(); // Reset tile counters

    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            switch (grid.cells[y][x]) {
                case WALL:
                    tileCounters.wallCount++;
                break;
                case TRAP:
                    tileCounters.trapCount++;
                break;
                case LOOT:
                    tileCounters.lootCount++;
                break;
                case ENEMY:
                    tileCounters.enemyCount++;
                break;
                case STAIRS:
                    tileCounters.stairsCount++;
                break;
                case EMPTY:
                    tileCounters.emptyCount++;
                break;
                default:
                    break;
            }
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
    countTiles();
}
void generateRandomGrid() {
    srand(static_cast<unsigned>(time(nullptr)));

    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            int randomTile = rand() % 6;
            grid.cells[y][x] = static_cast<CellType>(randomTile);
        }
    }

    countTiles(); // Call countTiles after generating the grid
}

void generateMazeDungeon(int playerX, int playerY) {
    bool validSpawn = false;

    while (!validSpawn) {
        srand(static_cast<unsigned>(time(nullptr)));

        for (int y = 0; y < GRID_SIZE; y++) {
            for (int x = 0; x < GRID_SIZE; x++) {
                grid.cells[y][x] = WALL;
            }
        }

        int startX = 1, startY = 1;
        grid.cells[startY][startX] = EMPTY;

        vector<pair<int,int>> cellList;
        cellList.push_back({startY, startX});

        while (!cellList.empty()) {
            int index = cellList.size() - 1;
            pair<int,int> current = cellList[index];
            int cy = current.first;
            int cx = current.second;

            vector<pair<int,int>> neighbors;

            if (cy - 2 > 0 && grid.cells[cy - 2][cx] == WALL)
                neighbors.push_back({cy - 2, cx});
            if (cy + 2 < GRID_SIZE - 1 && grid.cells[cy + 2][cx] == WALL)
                neighbors.push_back({cy + 2, cx});
            if (cx - 2 > 0 && grid.cells[cy][cx - 2] == WALL)
                neighbors.push_back({cy, cx - 2});
            if (cx + 2 < GRID_SIZE - 1 && grid.cells[cy][cx + 2] == WALL)
                neighbors.push_back({cy, cx + 2});

            if (!neighbors.empty()) {
                int randIndex = rand() % neighbors.size();
                pair<int,int> nextCell = neighbors[randIndex];
                int ny = nextCell.first;
                int nx = nextCell.second;

                int wallY = cy + (ny - cy) / 2;
                int wallX = cx + (nx - cx) / 2;
                grid.cells[wallY][wallX] = EMPTY;
                grid.cells[ny][nx] = EMPTY;

                cellList.push_back({ny, nx});
            } else {
                cellList.pop_back();
            }
        }

        // Ensure the player does not spawn on a wall
        if (grid.cells[playerY][playerX] == EMPTY) {
            validSpawn = true;
        }
    }
    fillEmptyCells();
}



