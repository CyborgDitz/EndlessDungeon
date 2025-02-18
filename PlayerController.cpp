#include "PlayerController.h"
#include "common.h"

GameConfig gameConfig;

void applyTileEffects(Player& player, const std::vector<TileEffect>& effects)
{
    for (TileEffect effect : effects)
    {
        switch (effect)
        {
        case CLEAR_TILE:
            // Clear the tile the player is on
            grid.cells[player.y][player.x] = EMPTY;
            std::cout << "Tile cleared!\n";
            break;

        case DAMAGE_PLAYER:
            {
                CellType currentTile = grid.cells[player.y][player.x];
                if (currentTile == TRAP) {
                    player.health -= gameConfig.damageFromTrap;
                    std::cout << "Player stepped on a trap! Health -"
                              << gameConfig.damageFromTrap << "\n";
                } else if (currentTile == ENEMY) {
                    player.health -= gameConfig.damageFromEnemy;
                    std::cout << "Bonked an enemy! Health -"
                              << gameConfig.damageFromEnemy << "\n";
                }
            }
            break;

        case HEAL_PLAYER:
            player.health += gameConfig.healingFromLoot;
            std::cout << "Player found loot! Health +"
                      << gameConfig.healingFromLoot << "\n";
            break;

        case PUSH_PLAYER:
            std::cout << "Player bumped into a wall and was pushed back!\n";
            // TODO: Add push logic here
            break;

        case NEXT_LEVEL:
            std::cout << "You found the stairs! Moving to the next level.\n";
            // TODO: Level transition logic
            break;
        }
    }
}

void checkTileEffect(Player& player)
{
    CellType currentTile = grid.cells[player.y][player.x];

    auto it = tileEffects.find(currentTile);
    if (it != tileEffects.end()) {
        applyTileEffects(player, it->second);
    }
}
void playerInput(Player& player) {
    if (IsKeyPressed(KEY_W)) {
        movePlayer(player, 0, -1);
        std::cout << "Move Up (decrease Y)\n";
    }
    if (IsKeyPressed(KEY_S)) {
        movePlayer(player, 0, 1);
        std::cout << "Move Down (increase Y)\n";
    }
    if (IsKeyPressed(KEY_A)) {
        movePlayer(player, -1, 0);
        std::cout << "Move left (decrease X)\n";
    }
    if (IsKeyPressed(KEY_D)) {
        movePlayer(player, 1, 0);
        std::cout << "Move right (increase X)\n";
    }
}
void movePlayer(Player& player, int directionX, int directionY) {
    int newX = player.x + directionX;
    int newY = player.y + directionY;

    if (inBounds(newY, newX)) {
        if (grid.cells[newY][newX] != WALL) {
            std::cout << "Moving player to (" << newX << ", " << newY << ")\n";
            player.x = newX;
            player.y = newY;
            checkTileEffect(player);
        } else {
            std::cout << "Blocked by a wall!\n";
        }
    } else {
        std::cout << "Out of bounds!\n";
    }
}

void drawHealth(const Player& player) {
    char healthText[32];
    std::sprintf(healthText, "HP: %d", player.health);
    Vector2 textPos = { static_cast<float>(player.x), static_cast<float>(player.y - 25) };
    DrawText(healthText, static_cast<int>(textPos.x),
             static_cast<int>(textPos.y), 20, BLACK);
}


void updatePlayer(Player& player) {
    playerInput(player);
    drawHealth(player);
}
