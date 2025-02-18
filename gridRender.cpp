#include "gridRender.h"
#include "common.h"
#include "playerData.h"
void generateRandomGrid() {
    srand(static_cast<unsigned>(time(nullptr)));
for (int y = 0; y < GRID_SIZE; y++) {
    for (int x = 0; x < GRID_SIZE; x++) {
        int randomTile = rand() % 6;
        grid.cells[y][x] = static_cast<CellType>(randomTile);
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
                case TRAP:   color = RED;       break;
                case LOOT:   color = GOLD;      break;
                case ENEMY:  color = MAROON;    break;
                case STAIRS: color = GREEN;     break;
                case EMPTY:
                    default:     color = LIGHTGRAY; break;
            }
            DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, color);
           // DrawRectangleLines(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, BLACK);
        }
    }
}
