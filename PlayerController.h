#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <vector>
#include "common.h"
#include "playerData.h"

extern GameConfig gameConfig;

void applyTileEffects(Player& player, const std::vector<TileEffect>& effects);
void checkTileEffect(Player& player);
void drawHealth(const Player& player);
void movePlayer(Player& player, int directionY, int directionX);
void drawHealth(const Player& player);
void updatePlayer(Player& player);
#endif // PLAYER_CONTROLLER_H
