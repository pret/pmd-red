#include "global.h"
#include "dungeon_leader.h"

#include "dungeon_global_data.h"
#include "dungeon_util.h"

extern struct DungeonEntity *gLeaderPokemon;

struct DungeonEntity* GetLeaderEntity()
{
    struct DungeonEntity *leader = gLeaderPokemon;
    if (leader == NULL)
    {
        s32 i;
        for (i = 0; i < MAX_TEAM_MEMBERS; i++)
        {
            struct DungeonEntity *currentPokemon = gDungeonGlobalData->teamPokemon[i];
            if (EntityExists(currentPokemon) && currentPokemon->entityData->isLeader)
            {
                gLeaderPokemon = currentPokemon;
                return currentPokemon;
            }
        }
        return NULL;
    }
    return leader;
}
