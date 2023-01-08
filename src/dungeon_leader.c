#include "global.h"
#include "dungeon_leader.h"

#include "dungeon_global_data.h"
#include "dungeon_util.h"

extern struct Entity *gLeaderPointer;

struct Entity* GetLeader()
{
    struct Entity *leader = gLeaderPointer;
    if (leader == NULL)
    {
        s32 i;
        for (i = 0; i < MAX_TEAM_MEMBERS; i++)
        {
            struct Entity *currentPokemon = gDungeon->teamPokemon[i];
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

struct EntityInfo* GetLeaderInfo(void)
{
    return GetLeader()->info;
}
