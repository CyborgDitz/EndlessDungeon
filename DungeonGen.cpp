
#include "DungeonGen.h"

void DrawGrid(const grid &myGrid) {
    for (const tile &t : myGrid.tiles) {
        DrawRectangleV(t.Position, t.Size, LIGHTGRAY);
    }
    for (const dungBlock &db : myGrid.blocks) {
        Vector2 position = { db.x * myGrid.tileSize.x, db.y * myGrid.tileSize.y };
        DrawRectangleV(position, myGrid.tileSize, RED);
    }
}