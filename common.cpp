#include "common.h"

Grid grid;
TileCounters tileCounters;
TileEffectsMap tileEffects = {
    {WALL,   {BLOCK_PLAYER}},
    {TRAP,   {DAMAGE_PLAYER, CLEAR_TILE}},
    {LOOT,   {HEAL_PLAYER,   CLEAR_TILE}},
    {ENEMY,  {DAMAGE_PLAYER, PUSH_PLAYER, CLEAR_TILE}},
    {STAIRS, {NEXT_LEVEL}},
};
