#include "PlayerController.h"
#include <cstdio>
#include "common.h"
#include "data.h"

PlayerController::PlayerController()
    : player({ 64, 64 }, { gridCellSize.x, gridCellSize.y }, 100),
      speed(200.0f)
{
}

PlayerController::~PlayerController() {}

CellType PlayerStandingOnCell(const Player* p, const Grid* g) {
    Vector2 tileSize = g->tileSize;
    int col = static_cast<int>(p->position.x / tileSize.x);
    int row = static_cast<int>(p->position.y / tileSize.y);
    CellKey key{ col, row };
    auto it = g->cellMap.find(key);
    return (it != g->cellMap.end()) ? it->second.type : CELL_EMPTY;
}

void PlayerController::Update() {
    Vector2 movement = { 0, 0 };
    if (IsKeyPressed(KEY_D)) movement.x += gridCellSize.x;
    if (IsKeyPressed(KEY_A)) movement.x -= gridCellSize.x;
    if (IsKeyPressed(KEY_S)) movement.y += gridCellSize.y;
    if (IsKeyPressed(KEY_W)) movement.y -= gridCellSize.y;
    if (movement.x != 0 || movement.y != 0) {
        Vector2 previousPosition = player.position;
        player.position.x += movement.x;
        player.position.y += movement.y;
        CellType cell = PlayerStandingOnCell(&player, &myGrid);
        if (cell == CELL_TRAP)
            player.health -= 10;
        else if (cell == CELL_ENEMY) {
            player.health -= 5;
            player.position = previousPosition;
        }
    }
}

void PlayerController::Draw() {
    DrawRectangleV(player.position, player.size, BLUE);
    DrawRectangleLines(static_cast<int>(player.position.x), static_cast<int>(player.position.y),
                       static_cast<int>(player.size.x), static_cast<int>(player.size.y), DARKBLUE);
    char healthText[32];
    std::sprintf(healthText, "HP: %d", player.health);
    Vector2 textPos = { player.position.x, player.position.y - 25 };
    DrawText(healthText, static_cast<int>(textPos.x), static_cast<int>(textPos.y), 20, BLACK);
}
