#include "global.h"
#include "dungeon_ai_leader.h"
#include "constants/status.h"
#include "constants/targeting.h"
#include "dungeon_logic.h"
#include "dungeon_leader.h"
#include "dungeon_util.h"
#include "pokemon_3.h"

bool8 TargetLeader(Entity *pokemon)
{
    if (GetEntInfo(pokemon)->isNotTeamMember)
    {
        return FALSE;
    }
    return TacticsTargetLeader(GetEntInfo(pokemon)->tactic);
}

Entity* GetLeaderIfVisible(Entity *pokemon)
{
    if (!GetEntInfo(pokemon)->isNotTeamMember)
    {
        Entity *leader = GetLeader();
        if (leader &&
            GetEntInfo(leader)->curseClassStatus.status != STATUS_DECOY &&
            GetTreatmentBetweenMonsters(pokemon, leader, FALSE, FALSE) == TREATMENT_TREAT_AS_ALLY &&
            CanTargetEntity(pokemon, leader))
        {
            return leader;
        }
    }
    return NULL;
}

