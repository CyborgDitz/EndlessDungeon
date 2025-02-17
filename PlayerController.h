
#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H
#include <vector>

#include "playerData.h"

void movePlayer(vector<vector<CellType>>& grid, Player& player, int directionX, int directionY);

#endif //PLAYER_CONTROLLER_H
