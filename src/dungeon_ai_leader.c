#include "global.h"
#include "dungeon_ai_leader.h"
#include "pokemon_3.h"

bool8 TargetLeader(struct DungeonEntity *pokemon)
{
    if (pokemon->entityData->isEnemy)
    {
        return FALSE;
    }
    return TacticsTargetLeader(pokemon->entityData->tactic);
}
