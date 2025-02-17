#include "data.h"

void DrawGrid(const grid &myGrid) {
    int cols = static_cast<int>(myGrid.dimensions.x);
    int rows = static_cast<int>(myGrid.dimensions.y);
    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < cols; i++) {
            CellKey key { i, j };
            auto it = myGrid.cellMap.find(key);
            if (it != myGrid.cellMap.end()) {
                Color fillColor = it->second.color;
                if (i == 0 || j == 0 || i == cols - 1 || j == rows - 1)
                    fillColor = cellColors[CELL_WALL];
                DrawRectangleV(it->second.position, it->second.size, fillColor);
            }
        }
    }
}
