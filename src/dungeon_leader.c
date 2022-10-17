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
        s32 i = 0;
        do
        {
            struct DungeonEntity *currentPokemon = gDungeonGlobalData->teamPokemon[i];
            if (EntityExists(currentPokemon) && currentPokemon->entityData->isLeader)
            {
                gLeaderPokemon = currentPokemon;
                return currentPokemon;
            }
        } while (++i < MAX_TEAM_MEMBERS);
        return NULL;
    }
    return leader;
}
