#include "global.h"
#include "targeting.h"

#include "dungeon_util.h"

void TargetTileInFront(struct DungeonEntity *pokemon)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    pokemonData->targetPosition.x = pokemon->posWorld.x + gAdjacentTileOffsets[pokemonData->action.facingDir].x;
    pokemonData->targetPosition.y = pokemon->posWorld.y + gAdjacentTileOffsets[pokemonData->action.facingDir].y;
}
