#include "PlayerController.h"
#include "common.h"
#include "Game.h"
#include "gridRender.h"

GameConfig gameConfig;
Game* game;
void applyTileEffects(Player& player, const std::vector<TileEffect>& effects, Game& game)
{
    for (TileEffect effect : effects)
    {
        switch (effect)
        {
        case CLEAR_TILE:
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
            if (player.health > 0)
            {
                game.RestartGame();
                std::cout << "The player wins\n";
            }
            break;
            default:

                break;
        }
    }
}

void checkTileEffect(Player& player, Game& game)
{
    CellType currentTile = grid.cells[player.y][player.x];

    auto it = tileEffects.find(currentTile);
    if (it != tileEffects.end()) {
        applyTileEffects(player, it->second, game);
    }
}

void playerInput(Player& player) {
    if (IsKeyDown(KEY_W)) {
        movePlayer(player, 0, -1);
    }
    if (IsKeyDown(KEY_S)) {
        movePlayer(player, 0, 1);
    }
    if (IsKeyDown(KEY_A)) {
        movePlayer(player, -1, 0);
    }
    if (IsKeyDown(KEY_D)) {
        movePlayer(player, 1, 0);
    }
}
void movePlayer(Player& player, int directionX, int directionY) {
    int newX = player.x + directionX;
    int newY = player.y + directionY;

    if (inBounds(newY, newX)) {
        if (grid.cells[newY][newX] != WALL) {
            player.x = newX;
            player.y = newY;
        }
    }
}

void drawHealth(const Player& player) {
    char healthText[32];
   sprintf(healthText, "HP: %d", player.health);

    int pixelX = player.x * TILE_SIZE;
    int pixelY = player.y * TILE_SIZE - 25;
    DrawText(healthText, pixelX, pixelY, 20, BLACK);
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


void updatePlayer(Player& player,Game& game) {
    playerInput(player);
    checkTileEffect(player,game);
}
