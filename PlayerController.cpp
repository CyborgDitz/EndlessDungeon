#include "PlayerController.h"
#include "common.h"



void SteppedOn(vector<vector<CellType>>& grid, Player& player) {
    CellType currentTile = grid[player.x][player.y];
    if (currentTile == TRAP) {
        player.health -= 10;
        grid[player.x][player.y] = EMPTY; // Deactivate trap after stepping on it
    } else if (currentTile == LOOT) {
        player.health += 5;
        grid[player.x][player.y] = EMPTY; // Collect treasure
    }
}

void movePlayer(vector<vector<char>>& grid, Player& player, int directionX, int directionY) {
    int newX = player.x + directionX;
    int newY = player.y + directionY;
    if (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE && grid[newX][newY] != WALL) {
        player.x = newX;
        player.y = newY;
    }

}

