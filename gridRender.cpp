#include "gridRender.h"
#include "common.h"
#include "playerData.h"
void generateRandomGrid() {
    srand(static_cast<unsigned>(time(nullptr)));
for (int y = 0; y < GRID_SIZE; y++) {
    for (int x = 0; x < GRID_SIZE; x++) {
        int randTile = rand() % 6; // pick a random CellType 0..5
        grid.cells[y][x] = static_cast<CellType>(randTile);
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
        for (int y = 0; y < GRID_SIZE; y++) {
            for (int x = 0; x < GRID_SIZE; x++) {
                Color color;
                switch (grid.cells[y][x]) {
                    case WALL:   color = DARKGRAY;  break;
                    case LOOT:   color = GOLD;      break;
                    case TRAP:   color = RED;       break;
                    case STAIRS: color = GREEN;     break;
                    case ENEMY:  color = MAROON;    break;
                    default:     color = LIGHTGRAY; break;
                }

                DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, color);
                DrawRectangleLines(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, BLACK);
            }
        }
    }