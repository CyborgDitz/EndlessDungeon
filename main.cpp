#include "gridRender.h"
#include "dungeonTree.h"
#include "PlayerController.h"
int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Dungeon Tile Generator");
    SetTargetFPS(60);
   //generateRandomGrid();
    generateRandomGridGrowingTree();
    Player player = {5, 5, 100};

    while (!WindowShouldClose()) {

        if (IsKeyPressed(KEY_W)) {
            movePlayer(player, 0, -1);
            cout << "Move Up (decrease Y) " << endl;
        }
        if (IsKeyPressed(KEY_S)) {
            movePlayer(player, 0, 1);
            cout << "Move Down (increase Y) " << endl;
        }
        if (IsKeyPressed(KEY_A)) {
            movePlayer(player, -1, 0);
            cout << "Move left (decrease x) " << endl;
        }
        if (IsKeyPressed(KEY_D)) {
            movePlayer(player, 1, 0);
            cout << "Move right (increase x) " << endl;
        }


        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawGrid();
        drawPlayer(player);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
