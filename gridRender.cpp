#include "gridRender.h"
#include "common.h"
#include "playerData.h"
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


void drawPlayer(const Player& player) {
        DrawRectangle(
            player.x * TILE_SIZE,
            player.y * TILE_SIZE,
            TILE_SIZE,
            TILE_SIZE,
            PINK
        );
    }
void drawGrid() {
    tileCounters = TileCounters();

    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            Color color = WHITE;
            switch (grid.cells[y][x]) {
                case WALL:
                    color = DARKGRAY;
                tileCounters.wallCount++;
                break;
                case TRAP:
                    color = RED;
                tileCounters.trapCount++;
                break;
                case LOOT:
                    color = GOLD;
                tileCounters.lootCount++;
                break;
                case ENEMY:
                    color = MAROON;
                tileCounters.enemyCount++;
                break;
                case STAIRS:
                     if (tileCounters.stairsCount == 0) {
                         color = DARKGREEN;
                         tileCounters.stairsCount++;
                     } else if (tileCounters.stairsCount == 1) {
                         color = GREEN;
                         tileCounters.stairsCount++;
                     } else {
                         continue;
                     }

                break;
                case EMPTY:
                    color = WHITE;
                tileCounters.emptyCount++;
                break;
                default:
                    break;
            }
            DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, color);
        }
    }
}

