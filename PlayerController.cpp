#include "PlayerController.h"
#include <cstdio>
#include "common.h"
PlayerController::PlayerController()
    : player({ 64, 64 }, { gridCellSize.x, gridCellSize.y }, 100),
      speed(200.0f)
{
}

PlayerController::~PlayerController() {
    // No dynamic memory to clean up in this simple example.
}


void PlayerController::Update() {

    if (IsKeyPressed(KEY_D)) player.position.x += gridCellSize.x;
    if (IsKeyPressed(KEY_A)) player.position.x -= gridCellSize.x;
    if (IsKeyPressed(KEY_S)) player.position.y += gridCellSize.y;
    if (IsKeyPressed(KEY_W)) player.position.y -= gridCellSize.y;
}


void PlayerController::Draw() {

    DrawRectangleV(player.position, player.size, BLUE);


    DrawRectangleLines(
        static_cast<int>(player.position.x),
        static_cast<int>(player.position.y),
        static_cast<int>(player.size.x),
        static_cast<int>(player.size.y),
        DARKBLUE
    );
    char healthText[32];
    std::sprintf(healthText, "HP: %d", player.health);
    Vector2 textPos = { player.position.x, player.position.y - 25 };
    DrawText(healthText, static_cast<int>(textPos.x), static_cast<int>(textPos.y), 20, BLACK);
}

