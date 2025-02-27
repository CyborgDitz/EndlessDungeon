#ifndef GAMECONFIG_H
#define GAMECONFIG_H

struct GameConfig {
    int   damageFromTrap     =  5;
    int   damageFromEnemy    = 10;
    int   healingFromLoot    =  5;
    int   keysToWin;

    float moveCooldown       =  0.1f;
    float moveTimer          =  0.0f;
    float playerSpeed        =  5.0f;

    bool  showLevelMessage   = false;
    float messageTimer       =  2.0f;

    int   minMin             =  3;
    int   maxTraps           =  6;
    int   maxLoot            =  5;
    int   maxEnemies         = 13;
    int   minTraps           = minMin;
    int   minLoot            = minMin;
    int   minEnemies         = minMin;

    int   pushDistance       =  -2;
    int   jumpDistance       =  2;
};

#endif // GAMECONFIG_H
