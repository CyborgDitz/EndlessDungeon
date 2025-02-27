#include "gridRender.h"

void DrawTextWithBorder(const char* text, int posX, int posY, int fontSize, Color textColor, Color borderColor) {
    DrawText(text, posX - 1, posY, fontSize, borderColor);
    DrawText(text, posX + 1, posY, fontSize, borderColor);
    DrawText(text, posX, posY - 1, fontSize, borderColor);
    DrawText(text, posX, posY + 1, fontSize, borderColor);
    DrawText(text, posX, posY, fontSize, textColor);
}

void drawGrid() {
    tileCounters = TileCounters();

    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            CellType cell = grid.cells[y][x];

            Color color = TILE_COLORS[cell];

            if (cell == STAIRS) {
                if (tileCounters.stairsCount == 0) {
                    color = DARKGREEN;
                } else if (tileCounters.stairsCount == 1) {
                    color = GREEN;
                } else {
                    continue;
                }
                tileCounters.stairsCount++;
            }

            switch (cell) {
                case WALL: tileCounters.wallCount++; break;
                case TRAP: tileCounters.trapCount++; break;
                case LOOT: tileCounters.lootCount++; break;
                case ENEMY: tileCounters.enemyCount++; break;
                case EMPTY: tileCounters.emptyCount++; break;
                default: break;
            }

            DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, color);
        }
    }

    int textY = SCREEN_HEIGHT - 30;
    int textX = 10;
    int spacing = 150;
    int fontSize = 20;

    DrawTextWithBorder(TextFormat("Traps: %d", tileCounters.trapCount), textX + spacing, textY, fontSize, PURPLE, BLACK);
    DrawTextWithBorder(TextFormat("Loot: %d", tileCounters.lootCount), textX + 2 * spacing, textY, fontSize, GOLD, BLACK);
    DrawTextWithBorder(TextFormat("Enemies: %d", tileCounters.enemyCount), textX + 3 * spacing, textY, fontSize, RED, BLACK);
    DrawTextWithBorder(TextFormat("Empty: %d", tileCounters.emptyCount), textX + 6 * spacing, textY, fontSize, WHITE, BLACK);
}
