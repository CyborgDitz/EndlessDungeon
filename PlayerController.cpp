#include "PlayerController.h"
#include <cstdio>

PlayerController::PlayerController()
    : player({ 64, 64 }, { gridCellSize.x, gridCellSize.y }, 100),
      speed(200.0f)
{
}

PlayerController::~PlayerController() {
    // No dynamic memory to clean up in this simple example.
}


void PlayerController::Update() {

    if (IsKeyPressed(KEY_D)) player.Position.x += gridCellSize.x;
    if (IsKeyPressed(KEY_A)) player.Position.x -= gridCellSize.x;
    if (IsKeyPressed(KEY_S)) player.Position.y += gridCellSize.y;
    if (IsKeyPressed(KEY_W)) player.Position.y -= gridCellSize.y;
}


void PlayerController::Draw() {

    DrawRectangleV(player.Position, player.Size, BLUE);


    DrawRectangleLines(
        static_cast<int>(player.Position.x),
        static_cast<int>(player.Position.y),
        static_cast<int>(player.Size.x),
        static_cast<int>(player.Size.y),
        DARKBLUE
    );
    char healthText[32];
    std::sprintf(healthText, "HP: %d", player.health);
    Vector2 textPos = { player.Position.x, player.Position.y - 25 };
    DrawText(healthText, static_cast<int>(textPos.x), static_cast<int>(textPos.y), 20, BLACK);
}

