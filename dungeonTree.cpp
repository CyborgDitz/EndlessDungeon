#include <vector>
#include <cstdlib> // rand, srand
#include <ctime>
#include <utility> // std::pair
#include "common.h"
#include "playerData.h"

static int countEmptyNeighbors(int y, int x) {
    static const std::pair<int, int> dirs[4] = {{0,1},{0,-1},{1,0},{-1,0}};
    int emptyCount = 0;
    for (auto& d : dirs) {
        int ny = y + d.first;
        int nx = x + d.second;
        if (inBounds(ny, nx) && grid.cells[ny][nx] == EMPTY) {
            emptyCount++;
        }
    }
    return emptyCount;
}

void generateRandomGridGrowingTree() {
    // Seed random
    srand(static_cast<unsigned>(time(nullptr)));

    // 1) Fill entire grid with EMPTY
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            grid.cells[y][x] = EMPTY;
        }
    }

    // 2) Pick a random start cell and make it EMPTY
    int startY = rand() % GRID_SIZE;
    int startX = rand() % GRID_SIZE;
    grid.cells[startY][startX] = EMPTY;

    // 3) Keep a list of "active" cells to grow from
    std::vector<std::pair<int, int>> active;
    active.push_back({startY, startX});

    static const std::pair<int, int> dirs[4] = {{-1,0},{1,0},{0,-1},{0,1}};


    while (!active.empty()) {

        int idx = rand() % active.size();
        int cy = active[idx].first;
        int cx = active[idx].second;

        std::vector<std::pair<int,int>> candidates;
        for (auto& d : dirs) {
            int ny = cy + d.first;
            int nx = cx + d.second;
            if (inBounds(ny, nx) && grid.cells[ny][nx] == WALL) {

                if (countEmptyNeighbors(ny, nx) <= 1) {
                    candidates.push_back({ny, nx});
                }
            }
        }


        if (!candidates.empty()) {
            auto& nextCell = candidates[rand() % candidates.size()];
            int ny = nextCell.first;
            int nx = nextCell.second;
            grid.cells[ny][nx] = EMPTY;
            // Add the newly-carved cell to 'active'
            active.push_back({ny, nx});
        }
        else {

            active.erase(active.begin() + idx);
        }
    }

    // Optionally place TRAP, LOOT, ENEMY, STAIRS, etc., in some EMPTY cells.
}
