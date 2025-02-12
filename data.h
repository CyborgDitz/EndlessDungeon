#ifndef DATA_H
#define DATA_H

#include "common.h"
#include <vector>
#include <sstream>


typedef struct {
    Vector2 Position;
    Vector2 Size;
} tile;

typedef struct {
    int x, y;
    bool solid;
} dungBlock;

class GameObject {
public:
    Vector2 position;
    Vector2 size;

    GameObject(Vector2 pos, Vector2 s)
        : position(pos), size(s)
    {}

    virtual ~GameObject() {}

    virtual void Update() {}

    virtual void Draw() {

        DrawRectangleV(position, size, WHITE);
    }
};



struct grid {
    Vector2 dimensions;
    Vector2 tileSize;
    std::vector<tile> tiles;
    std::vector<dungBlock> blocks;

    std::vector<GameObject*> objects;

    grid(Vector2 dimensions, Vector2 tileSize)
        : dimensions(dimensions), tileSize(tileSize)
    {
        int cols = static_cast<int>(dimensions.x);
        int rows = static_cast<int>(dimensions.y);

        for (int j = 0; j < rows; ++j) {
            for (int i = 0; i < cols; ++i) {
                tile t;
                t.Position = { i * tileSize.x, j * tileSize.y };
                t.Size = tileSize;
                tiles.push_back(t);
            }
        }

        for (int i = 0; i < cols; ++i) {
            blocks.push_back({ i, 0, true });
            blocks.push_back({ i, rows - 1, true });
        }

        for (int j = 1; j < rows - 1; ++j) {
            blocks.push_back({ 0, j, true });
            blocks.push_back({ cols - 1, j, true });
        }
    }

    ~grid() {
        for (GameObject* objects : objects) {
            delete objects;
        }
    }
};

#endif // DATA_H
