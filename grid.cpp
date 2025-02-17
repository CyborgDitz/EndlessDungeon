
#include "DungeonGen.h"

void DrawGrid(const grid &myGrid) {
    for (size_t i = 0; i < myGrid.tiles.size(); ++i) {
        const tile &t = myGrid.tiles[i];
        Color fillColor = LIGHTGRAY;
        switch (myGrid.cellContents[i]) {
            case CELL_PLAYER: fillColor = BLUE;    break;
            case CELL_ENEMY:  fillColor = RED;     break;
            case CELL_LOOT:   fillColor = GOLD;    break;
            case CELL_TRAP:   fillColor = DARKGRAY; break;
            default:          fillColor = LIGHTGRAY; break;
        }
        DrawRectangleV(t.position, t.size, fillColor);
    }

    int cols = static_cast<int>(myGrid.dimensions.x);

    for (const tile &db : myGrid.tiles) {
        if (db.solid) {

            int cellIndex = db.y * cols + db.x;


            Color blockColor = (myGrid.cellContents[cellIndex] == CELL_ENEMY) ? RED : DARKGRAY;

            Vector2 pos = { db.x * myGrid.tileSize.x, db.y * myGrid.tileSize.y };
            DrawRectangleV(pos, myGrid.tileSize, blockColor);
        }
    }
}
