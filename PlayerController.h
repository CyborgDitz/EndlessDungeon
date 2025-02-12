
#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H
#include "data.h"


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
