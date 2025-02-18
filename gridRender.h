#ifndef GRID_H
#define GRID_H
#include <ctime>
#include "playerData.h"
#include "common.h"
void generateRandomGrid(vector<vector<CellType>>& grid);
void drawPlayer(const Player& player);
void drawGrid(const vector<vector<CellType>>& grid);

#endif // GRID_H
