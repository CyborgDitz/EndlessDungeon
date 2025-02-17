
#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H
#include "playerData.h"

class PlayerController {
public:

    PlayerController();
    void Update();

    void Draw();

    player& GetPlayer() { return player; }

private:
    player player;
    float speed;
};

#endif //PLAYER_CONTROLLER_H
