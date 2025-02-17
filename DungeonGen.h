#ifndef GRID_H
#define GRID_H
#include <ctime>

#include "common.h"

void generateDungeon(vector<vector<CellType>>& grid, Player& player) {
    srand(time(0));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int randTile = rand() % 12;
            if (randTile < 6) grid[i][j] = EMPTY;
            else if (randTile < 9) grid[i][j] = WALL;
            else if (randTile < 11) grid[i][j] = LOOT;
            else grid[i][j] = TRAP;
        }
    }
    player.x = 0;
    player.y = 0;
}


void drawGrid(const vector<vector<CellType>>& grid, const Player& player) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            Color color;
            switch (grid[i][j]) {
                case WALL: color = DARKGRAY; break;
                case LOOT: color = GOLD; break;
                case TRAP: color = RED; break;
                default: color = LIGHTGRAY; break;
            }
            DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, color);
            DrawRectangleLines(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, BLACK);
        }
    }
    DrawRectangle(player.y * TILE_SIZE, player.x * TILE_SIZE, TILE_SIZE, TILE_SIZE, BLUE);
}
#endif // GRID_H
