#include "common.h"

Grid grid;

TileEffectsMap tileEffects = {
    {TRAP,   {DAMAGE_PLAYER, CLEAR_TILE}},
    {LOOT,   {HEAL_PLAYER,   CLEAR_TILE}},
    {ENEMY,  {DAMAGE_PLAYER}},
    {STAIRS, {NEXT_LEVEL}},
    {WALL,   {PUSH_PLAYER}}
};
