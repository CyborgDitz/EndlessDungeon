#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "gridRender.h"
#include "dungeonController.h"
#include "playerController.h"
#include "gameConfig.h"
#include "common.h"

class Game {
public:
    Game();
    ~Game();
    void Run();
    void RestartGame();

private:
    Player player;
    void HandleInput();
    void PlayerUpdate();
    void Render();
};

#endif // GAME_H
