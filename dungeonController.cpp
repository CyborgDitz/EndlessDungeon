#include "dungeonController.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>


void countTiles() {
    tileCounters = TileCounters(); // Reset tile counters

    for (auto & cell : grid.cells) {
        for (auto & x : cell) {
            switch (x) {
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
}void fillEmptyCells() {
    forEachCell([](int x, int y) {
        if (grid.cells[y][x] == EMPTY) {
            std::cout << "Empty tile found at: (" << x << ", " << y << ")\n";
        }
    });
    countTiles();
}

void generateRandomGrid() {
    srand(static_cast<unsigned>(time(nullptr)));
    forEachCell([](int x, int y) {
        int randomTile = rand() % 6;
        grid.cells[y][x] = static_cast<CellType>(randomTile);
    });
    countTiles();
}


void generateMazeDungeon(int playerX, int playerY) {
    bool validSpawn = true;

    while (validSpawn) {
        srand(static_cast<unsigned>(time(nullptr)));

        for (auto & cell : grid.cells) {
            for (auto & x : cell) {
                x = WALL;
            }
        }

        int startX = 1, startY = 1;
        grid.cells[startY][startX] = EMPTY;

        std::vector<std::pair<int,int>> cellList;
        cellList.emplace_back(startY, startX);

        while (!cellList.empty()) {
            if (grid.cells[playerY][playerX] == EMPTY) {
                validSpawn = false;
            }
            int index = cellList.size() - 1;
            std::pair<int,int> current = cellList[index];
            int cy = current.first;
            int cx = current.second;

            std::vector<std::pair<int,int>> neighbors;

            if (cy - 2 > 0 && grid.cells[cy - 2][cx] == WALL)
                neighbors.emplace_back(cy - 2, cx);
            if (cy + 2 < GRID_SIZE - 1 && grid.cells[cy + 2][cx] == WALL)
                neighbors.emplace_back(cy + 2, cx);
            if (cx - 2 > 0 && grid.cells[cy][cx - 2] == WALL)
                neighbors.emplace_back(cy, cx - 2);
            if (cx + 2 < GRID_SIZE - 1 && grid.cells[cy][cx + 2] == WALL)
                neighbors.emplace_back(cy, cx + 2);

            if (!neighbors.empty()) {
                int randIndex = rand() % neighbors.size();
                std::pair<int,int> nextCell = neighbors[randIndex];
                int ny = nextCell.first;
                int nx = nextCell.second;

                int wallY = cy + (ny - cy) / 2;
                int wallX = cx + (nx - cx) / 2;
                grid.cells[wallY][wallX] = EMPTY;
                grid.cells[ny][nx] = EMPTY;

                cellList.emplace_back(ny, nx);
            } else {
                cellList.pop_back();
            }
        }

    }
    fillEmptyCells();
}



