#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <vector>
#include "common.h"
#include "playerData.h"

extern GameConfig gameConfig;

void applyTileEffects(Player& player, const std::vector<TileEffect>& effects);
void checkTileEffect(Player& player);
void movePlayer(Player& player, int directionY, int directionX);
void updateHealth(const Player& player);
#endif // PLAYER_CONTROLLER_H
