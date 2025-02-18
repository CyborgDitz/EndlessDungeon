#include "gridRender.h"
#include "playerData.h"
void generateRandomGrid(vector<vector<CellType>>& grid) {
    srand(time(0));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int randomTile = rand() % 6;
            grid[i][j] = static_cast<CellType>(randomTile);
        }
    }
}
void drawPlayer(const Player& player) {
    DrawRectangle(player.y * TILE_SIZE, player.x * TILE_SIZE, TILE_SIZE, TILE_SIZE, PINK);
}

void drawGrid(const vector<vector<CellType>>& grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            Color color;
            switch (grid[i][j]) {
                case WALL: color = DARKGRAY; break;
                case LOOT: color = GOLD; break;
                case TRAP: color = RED; break;
                case STAIRS: color = GREEN; break;
                case ENEMY: color = MAROON; break;
                default: color = LIGHTGRAY; break;
            }
            DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, color);
            DrawRectangleLines(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, BLACK);
        }
    }
}

