#include "PlayerController.h"

#include "common.h"
#include "Game.h"
#include "gridRender.h"

GameConfig gameConfig;
Game* game;
void applyTileEffects(Player& player, const std::vector<TileEffect>& effects, Game& game) {
    for (TileEffect effect : effects) {
        switch (effect) {
            case CLEAR_TILE:
                grid.cells[player.y][player.x] = EMPTY;
                break;

            case DAMAGE_PLAYER: {
                CellType currentTile = grid.cells[player.y][player.x];
                if (currentTile == TRAP) {
                    player.health -= gameConfig.damageFromTrap;
                } else if (currentTile == ENEMY) {
                    player.health -= gameConfig.damageFromEnemy;
                }
                break;
            }

            case HEAL_PLAYER:
                player.health += gameConfig.healingFromLoot;
                break;

            case COLLECT_KEY:
                player.keys += 1;
                grid.cells[player.y][player.x] = EMPTY;
                break;

            case PUSH_PLAYER: {
                int pushDistance = gameConfig.pushDistance; // Using the value from the config
                int newX = player.x + (player.lastMoveX * pushDistance);
                int newY = player.y + (player.lastMoveY * pushDistance);
                if (inBounds(newY, newX) && grid.cells[newY][newX] != WALL) {
                    player.x = newX;
                    player.y = newY;
                }
                break;
            }

            case JUMP_PLAYER: {
                int jumpDistance = gameConfig.jumpDistance; // Using the value from the config
                int jumpX = player.x + (player.lastMoveX * jumpDistance);
                int jumpY = player.y + (player.lastMoveY * jumpDistance);
                if (inBounds(jumpY, jumpX) && grid.cells[jumpY][jumpX] != WALL) {
                    player.x = jumpX;
                    player.y = jumpY;
                }
                break;
            }

            case NEXT_LEVEL:
                if (player.keys == gameConfig.keysToWin) {
                    gameConfig.showLevelMessage = true;
                    gameConfig.messageTimer = 2.0f;
                    game.RestartGame();
                }
                break;

            default:
                break;
        }
    }
}


void checkTileEffect(Player& player, Game& game) {
    CellType currentTile = grid.cells[player.y][player.x];

    auto it = tileEffects.find(currentTile);
    if (it != tileEffects.end()) {
        applyTileEffects(player, it->second, game);
    }
}

void playerInput(Player& player) {
    if (IsKeyDown(KEY_W)) movePlayer(player, 0, -1);
    if (IsKeyDown(KEY_S)) movePlayer(player, 0, 1);
    if (IsKeyDown(KEY_A)) movePlayer(player, -1, 0);
    if (IsKeyDown(KEY_D)) movePlayer(player, 1, 0);
}

void movePlayer(Player& player, int directionX, int directionY) {
    gameConfig.moveTimer -= GetFrameTime();

    if (gameConfig.moveTimer <= 0.0f) {
        int newX = player.x + directionX;
        int newY = player.y + directionY;

        if (inBounds(newY, newX) && grid.cells[newY][newX] != WALL) {
            player.x = newX;
            player.y = newY;
            player.lastMoveX = directionX;
            player.lastMoveY = directionY;
        }

        gameConfig.moveTimer = gameConfig.moveCooldown;
    }
}

void drawLevelMessage() {
    if (gameConfig.showLevelMessage) {
        DrawText("You found the stairs!\n Moving to the next level.\n", 200, 400, 60, PINK);
    }
}

void drawHealth(const Player& player) {
    char healthText[32];
    sprintf(healthText, "HP: %d", player.health);

    int pixelX = player.x * TILE_SIZE;
    int pixelY = player.y * TILE_SIZE - 25;
    DrawText(healthText, pixelX, pixelY, 20, BLACK);
}

void drawKeys(const Player& player) {
    char keyText[32];
    sprintf(keyText, "Keys: %d", player.keys);

    int pixelX = player.x * TILE_SIZE;
    int pixelY = player.y * TILE_SIZE - 45;
    DrawText(keyText, pixelX, pixelY, 20, GOLD);
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

void updatePlayer(Player& player, Game& game) {
    playerInput(player);
    checkTileEffect(player, game);

    if (gameConfig.showLevelMessage) {
        gameConfig.messageTimer -= GetFrameTime();
        if (gameConfig.messageTimer <= 0) {
            gameConfig.showLevelMessage = false;
        }
    }
}
