#include "Game.h"
#include "PlayerController.h"

Game::Game() : player(1, 1, 100) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "EndlessDungeon");
    SetTargetFPS(60);

    generateRandomGrid();
    generateMazeDungeon(player.x, player.y);
}

Game::~Game() {
    CloseWindow();
}

void Game::RestartGame() {
    player.x = 1;
    player.y = 1;
    player.health = 100;

    generateRandomGrid();
    generateMazeDungeon(player.x, player.y);
}

void Game::HandleInput() {
    if (IsKeyPressed(KEY_SPACE)) {
        generateMazeDungeon(player.x, player.y);
    }
    if (IsKeyPressed(KEY_F4)) {
        generateRandomGrid();
    }

    if (IsKeyPressed(KEY_K)) {
        player.health = 0;
    }

    if (IsKeyPressed(KEY_L)) {
        player.health = 100;
    }
}

void Game::PlayerUpdate() {
    updatePlayer(player, *this);
}

void Game::Render() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    drawGrid();
    drawPlayer(player);
    drawHealth(player);
    drawLevelMessage();
    EndDrawing();
}

void Game::Run() {
    while (!WindowShouldClose()) {
        HandleInput();
        PlayerUpdate();
        Render();

        if (player.health <= 0) {
            RestartGame();
        }

    }
}
