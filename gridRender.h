#ifndef GRID_H
#define GRID_H
#include <ctime>
#include "playerData.h"
#include "common.h"
void drawPlayer(const Player& player);
void drawGrid(const vector<vector<CellType>>& grid, const Player& player);

#endif // GRID_H
