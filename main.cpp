#include "GameController.h"
#include "PlayerController.h"
int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Dungeon Tile Generator");
    SetTargetFPS(60);

    vector<vector<CellType>> grid(GRID_SIZE, vector<CellType>(GRID_SIZE, EMPTY));
    generateRandomGrid(grid);
    Player player = {5, 5, 100};

    while (!WindowShouldClose()) {

        if (IsKeyPressed(KEY_W)) {
            movePlayer(grid, player, 0, -1);
            cout << "Move Up (decrease Y) " << endl;
        }
        if (IsKeyPressed(KEY_S)) {
            movePlayer(grid, player, 0, 1);
cout << "Move Down (increase Y) " << endl;
        }
        if (IsKeyPressed(KEY_A)) {
            movePlayer(grid, player, -1, 0);
            cout << "Move left (decrease x) " << endl;
        }
        if (IsKeyPressed(KEY_D)) {
            movePlayer(grid, player, 1, 0);
            cout << "Move right (increase x) " << endl;
        }


        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawGrid(grid, player);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
