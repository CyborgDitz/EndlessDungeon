#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <vector>
#include "common.h"
#include "Game.h"
#include "playerData.h"
#include "gameConfig.h"

extern GameConfig gameConfig;
void drawPlayer(const Player& player);
void drawLevelMessage();
void applyTileEffects(Player& player, const std::vector<TileEffect>& effects, Game& game);
void checkTileEffect(Player& player, Game& game);
void drawHealth(const Player& player);
void movePlayer(Player& player, int directionY, int directionX);
void updatePlayer(Player& player, Game& game);
#endif // PLAYER_CONTROLLER_H