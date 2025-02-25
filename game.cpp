#include "Game.h"

Game::Game() {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Dungeon Tile Generator");
    SetTargetFPS(60);


    player = {1, 1, 100};
    generateRandomGrid();
    generateMazeDungeon(player.x, player.y);
}

Game::~Game() {
    CloseWindow();
}

void Game::HandleInput() {

    if (IsKeyPressed(KEY_SPACE)) {
        generateMazeDungeon(player.x, player.y);
    }
    if (IsKeyPressed(KEY_F4)) {
        generateRandomGrid();
    }
}

void Game::PlayerUpdate() {
    updatePlayer(player);
    drawPlayer(player);
    drawHealth(player);
}

void Game::Render() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    drawGrid();
    drawPlayer(player);
    drawHealth(player);
    EndDrawing();
}

void Game::Run() {
    while (!WindowShouldClose()) {
        HandleInput();

        Render();

    }
}
