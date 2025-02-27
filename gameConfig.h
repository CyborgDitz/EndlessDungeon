#ifndef GAMECONFIG_H
#define GAMECONFIG_H

struct GameConfig {
    int damageFromTrap = 5;
    int damageFromEnemy = 10;
    int healingFromLoot = 5;

    float moveCooldown = 0.1f;
    float moveTimer = 0.0f;
    float playerSpeed = 5.0f;

    bool showLevelMessage = false;
    float messageTimer = 2.0f;
};

#endif // GAMECONFIG_H
