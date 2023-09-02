#include "global.h"
#include "dungeon_leader.h"

#include "dungeon_global_data.h"
#include "dungeon_util.h"

extern Entity *gLeaderPointer;

Entity* GetLeader()
{
    Entity *leader = gLeaderPointer;
    if (leader == NULL)
    {
        s32 i;
        for (i = 0; i < MAX_TEAM_MEMBERS; i++)
        {
            Entity *currentPokemon = gDungeon->teamPokemon[i];
            if (EntityExists(currentPokemon) && currentPokemon->info->isTeamLeader)
            {
                gLeaderPointer = currentPokemon;
                return currentPokemon;
            }
        }
        return NULL;
    }
    return leader;
}

EntityInfo* GetLeaderInfo(void)
{
    return GetLeader()->info;
}
