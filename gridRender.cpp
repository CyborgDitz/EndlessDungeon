#include "gridRender.h"

void drawGrid() {
    tileCounters = TileCounters();

    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            CellType cell = grid.cells[y][x];

            Color color = TILE_COLORS[cell];

            if (cell == STAIRS) {
                if (tileCounters.stairsCount == 0) {
                    color = DARKGREEN;
                } else if (tileCounters.stairsCount == 1) {
                    color = GREEN;
                } else {
                    continue;
                }
                tileCounters.stairsCount++;
            }

            switch (cell) {
                case WALL: tileCounters.wallCount++; break;
                case TRAP: tileCounters.trapCount++; break;
                case LOOT: tileCounters.lootCount++; break;
                case ENEMY: tileCounters.enemyCount++; break;
                case EMPTY: tileCounters.emptyCount++; break;
                default: break;
            }

            DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, color);
        }
    }
}
