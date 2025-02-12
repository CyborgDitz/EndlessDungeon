#include "common.h"
#include "data.h"
#include "PlayerController.h"
#include "DungeonGen.h"

int main() {

    InitWindow(SCREEN_WIDTH, SCREEN_WIDTH, "C++ Raylib Grid Example");
    
    Vector2 dimensions = { 10, 8 };
    Vector2 tileSize = { 64, 64 };
    grid myGrid(dimensions, tileSize);
    PlayerController playerController;
    SetTargetFPS(60);  

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        playerController.Update();
        DrawGrid(myGrid);
        playerController.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
