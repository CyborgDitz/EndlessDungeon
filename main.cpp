#include "gridRender.h"
#include "dungeonController.h"
#include "playerController.h"
int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Dungeon Tile Generator");
    SetTargetFPS(60);
    Player player = {1, 1, 100};
    generateMazeDungeon(player.x, player.y);
    generateRandomGrid();

    while (!WindowShouldClose()) {

        if (IsKeyDown(KEY_SPACE)) {
            generateMazeDungeon(player.x, player.y);
        }
        if (IsKeyDown(KEY_F4)) { generateRandomGrid();}

        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawGrid();
        updatePlayer( player);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
