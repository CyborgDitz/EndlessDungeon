#include "dungeonController.h"
#include <algorithm>
#include <vector>
#include <random>
#include <utility>

DesignatedTiles designatedTiles = { 5, 3, 7, 1 };

void countTiles() {
    tileCounters = TileCounters();

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
}
void fillEmptyCells()
    {
        {
        std::vector<std::pair<int,int>> emptyCells;

        forEachCell([&emptyCells](int x, int y)
            {
            if (grid.cells[y][x] == EMPTY) {
            emptyCells.emplace_back(y, x);
            }
        });

    std::random_device rd;
    std::mt19937 engine(rd());
    std::shuffle(emptyCells.begin(), emptyCells.end(), engine);

    auto assignTiles = [&](CellType tileType, int count) {
        for (int i = 0; i < count && !emptyCells.empty(); ++i) {
            auto pos = emptyCells.back();
            emptyCells.pop_back();
            grid.cells[pos.first][pos.second] = tileType;
        }
    };

    assignTiles(TRAP, designatedTiles.traps);
    assignTiles(LOOT, designatedTiles.loot);
    assignTiles(ENEMY, designatedTiles.enemies);
    assignTiles(STAIRS, designatedTiles.stairs);
}
    countTiles();
}


void generateRandomGrid() {
    // Create a random engine and a uniform distribution [0, 5].
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> distribution(0, 5);

    forEachCell([&engine, &distribution](int x, int y) {
        int randomTile = distribution(engine);
        grid.cells[y][x] = static_cast<CellType>(randomTile);
    });
    countTiles();
}

void generateMazeDungeon(int playerX, int playerY) {
    std::random_device rd;
    std::mt19937 engine(rd());
    bool validSpawn = true;

    while (validSpawn) {
        // Set all cells to WALL.
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
            // Use std::size_t for the index to avoid narrowing conversion.
            std::size_t index = cellList.size() - 1;
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
                // Use std::size_t for distribution index to match neighbors.size() type.
                std::uniform_int_distribution<std::size_t> dist(0, neighbors.size() - 1);
                std::size_t randIndex = dist(engine);
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
