
#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H
#include "data.h"

struct player : public GameObject {
    int health;

    player(Vector2 position = { 0, 0 }, Vector2 s = { 64, 64 }, int hp = 100)
        : GameObject(position, s), health(hp)
    {}

    virtual void Draw() override {
        DrawRectangleV(position, size, BLUE);

        DrawRectangleLines(static_cast<int>(position.x),
                           static_cast<int>(position.y),
                           static_cast<int>(size.x),
                           static_cast<int>(size.y),
                           DARKBLUE);


        char healthText[32];
        std::sprintf(healthText, "HP: %d", health);
        Vector2 textPos = { position.x, position.y - 25 };
        DrawText(healthText,
                 static_cast<int>(textPos.x),
                 static_cast<int>(textPos.y),
                 20,
                 BLACK);
    }
};
class PlayerController {
public:

    PlayerController();
    ~PlayerController();

    void Update();

    void Draw();

    player& GetPlayer() { return player; }

private:
    player player;
    float speed;
};

#endif //PLAYER_CONTROLLER_H
