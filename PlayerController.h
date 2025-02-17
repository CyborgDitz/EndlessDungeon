#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <vector>
#include "common.h"
#include "playerData.h"

extern GameConfig gameConfig;

void applyTileEffects(std::vector<std::vector<CellType>>& grid, Player& player, std::vector<TileEffect> effects);
void checkTileEffect(std::vector<std::vector<CellType>>& grid, Player& player);
void movePlayer(std::vector<std::vector<CellType>>& grid, Player& player, int directionY, int directionX);

#endif // PLAYER_CONTROLLER_H
