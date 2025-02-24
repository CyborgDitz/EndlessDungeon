#include "gridRender.h"
#include "common.h"
#include "dungeonController.h"
#include "PlayerController.h"
int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Dungeon Tile Generator");
    SetTargetFPS(60);
   generateRandomGrid();

    Player player = {0, 0, 100};

    while (!WindowShouldClose()) {



        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawGrid();
        updatePlayer( player);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
