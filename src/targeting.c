#include "global.h"
#include "targeting.h"

#include "dungeon_util.h"

void TargetTileInFront(struct Entity *pokemon)
{
    struct EntityInfo *pokemonInfo = pokemon->info;
    pokemonInfo->targetPos.x = pokemon->pos.x + gAdjacentTileOffsets[pokemonInfo->action.direction].x;
    pokemonInfo->targetPos.y = pokemon->pos.y + gAdjacentTileOffsets[pokemonInfo->action.direction].y;
}
