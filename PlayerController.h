#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <vector>
#include "common.h"
#include "playerData.h"
#include "gameConfig.h"

extern GameConfig gameConfig;
void drawPlayer(const Player& player);
void applyTileEffects(Player& player, const std::vector<TileEffect>& effects);
void checkTileEffect(Player& player);
void drawHealth(const Player& player);
void movePlayer(Player& player, int directionY, int directionX);
void updatePlayer(Player& player);
#endif // PLAYER_CONTROLLER_H
