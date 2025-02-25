#include "gridRender.h"
#include "common.h"
#include "dungeonController.h"
#include "PlayerController.h"
int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Dungeon Tile Generator");
    SetTargetFPS(60);
   // generateRandomGrid();
    generateMazeDungeon();

    Player player = {1, 1, 100};

    while (!WindowShouldClose()) {

        if (IsKeyDown(KEY_SPACE)) { generateMazeDungeon();}

        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawGrid();
        updatePlayer( player);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
