#include "global.h"
#include "targeting.h"

#include "dungeon_util.h"

void TargetTileInFront(Entity *pokemon)
{
    EntityInfo *pokemonInfo = pokemon->axObj.info;
    pokemonInfo->targetPos.x = pokemon->pos.x + gAdjacentTileOffsets[pokemonInfo->action.direction].x;
    pokemonInfo->targetPos.y = pokemon->pos.y + gAdjacentTileOffsets[pokemonInfo->action.direction].y;
}
