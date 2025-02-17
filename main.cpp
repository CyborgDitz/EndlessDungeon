#include "common.h"
#include "playerData.h"
#include "PlayerController.h"
#include "DungeonGen.h"

int main() {

    InitWindow(SCREEN_WIDTH, SCREEN_WIDTH, "C++ Raylib Grid Example");
    

    PlayerController playerController;
    SetTargetFPS(60);  

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        playerController.Update();
        DrawDungeonGrid(myGrid);
        playerController.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
