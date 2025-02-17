#include "PlayerController.h"
#include "common.h"
GameConfig gameConfig;
void applyTileEffects(vector<vector<CellType>>& grid, Player& player, vector<TileEffect> effects) {
    for (TileEffect effect : effects) {
        switch (effect) {
            case CLEAR_TILE:
                grid[player.x][player.y] = EMPTY;
            cout << "Tile cleared!\n";
            break;

            case DAMAGE_PLAYER:
                if (grid[player.x][player.y] == TRAP) {
                    player.health -= gameConfig.damageFromTrap;
                    cout << "Player stepped on a trap! Health -" << gameConfig.damageFromTrap << "\n";
                } else if (grid[player.x][player.y] == ENEMY) {
                    player.health -= gameConfig.damageFromEnemy;
                    cout << "Bonked an enemy! Health -" << gameConfig.damageFromEnemy << "\n";
                }
            break;

            case HEAL_PLAYER:
                player.health += gameConfig.healingFromLoot;
            cout << "Player found loot! Health +" << gameConfig.healingFromLoot << "\n";
            break;

            case PUSH_PLAYER:
                cout << "Player bumped into a wall and was pushed back!\n";
            //todo Push logic could be added here
            break;

            case NEXT_LEVEL:
                cout << "You found the stairs! Moving to the next level.\n";
            //todo  Level transition logic
            break;
        }
    }
}

void checkTileEffect(vector<vector<CellType>>& grid, Player& player) {
    CellType currentTile = grid[player.x][player.y];

    if (tileEffects.find(currentTile) != tileEffects.end()) {
        applyTileEffects(grid, player, tileEffects[currentTile]);
    }
}

void movePlayer(vector<vector<CellType>>& grid, Player& player, int directionY, int directionX) {
    int newX = player.x + directionX;
    int newY = player.y + directionY;


    cout << "Attempting to move player from (" << player.x << ", " << player.y << ") to (" << newX << ", " << newY << ")\n";

    if (newY >= 0 && newY < GRID_SIZE && newX >= 0 && newX < GRID_SIZE) {
        cout << "Checking grid at (" << newY << ", " << newX << ") - ";
        if (grid[newY][newX] != WALL) {
            cout << "Valid move.\n";
            player.x = newX;
            player.y = newY;
            checkTileEffect(grid, player);
        } else {
            cout << "Blocked by a wall!\n";
        }
    } else {
        cout << "Out of bounds! Can't move there.\n";
    }
}





