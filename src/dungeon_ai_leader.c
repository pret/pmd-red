#include "global.h"
#include "dungeon_ai_leader.h"

#include "constants/status.h"
#include "constants/targeting.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_visibility.h"
#include "pokemon_3.h"

extern struct DungeonEntity* GetLeaderEntity();

bool8 TargetLeader(struct DungeonEntity *pokemon)
{
    if (pokemon->entityData->isEnemy)
    {
        return FALSE;
    }
    return TacticsTargetLeader(pokemon->entityData->tactic);
}

struct DungeonEntity* GetLeaderEntityIfVisible(struct DungeonEntity *pokemon)
{
    if (!pokemon->entityData->isEnemy)
    {
        struct DungeonEntity *leader = GetLeaderEntity();
        if (leader &&
            leader->entityData->waitingStatus != WAITING_STATUS_DECOY &&
            CanTarget(pokemon, leader, FALSE, FALSE) == TARGET_CAPABILITY_CANNOT_ATTACK &&
            CanSee_2(pokemon, leader))
        {
            return leader;
        }
    }
    return NULL;
}
