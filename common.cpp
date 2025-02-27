#include "common.h"

Grid grid;
TileCounters tileCounters;
TileEffectsMap tileEffects = {
    {WALL,   {BLOCK_PLAYER}},
    {TRAP,   {DAMAGE_PLAYER,  CLEAR_TILE, JUMP_PLAYER}},
    {LOOT,   {HEAL_PLAYER, CLEAR_TILE}},
    {KEY,    {COLLECT_KEY, CLEAR_TILE}},
    {ENEMY,  {DAMAGE_PLAYER, CLEAR_TILE, PUSH_PLAYER}},
    {STAIRS, {NEXT_LEVEL}},
    {EMPTY,  {}}
};


bool win = false;