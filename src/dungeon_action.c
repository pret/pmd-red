#include "global.h"
#include "dungeon_action.h"

#include "constants/dungeon_action.h"
#include "dungeon_entity.h"
#include "pokemon.h"

void ResetAction(struct DungeonActionContainer *actionPointer)
{
    actionPointer->action = DUNGEON_ACTION_NONE;
    actionPointer->actionUseIndex = 0;
    actionPointer->unkC = 0;
}

void SetAction(struct DungeonActionContainer *actionPointer, u16 action)
{
    actionPointer->action = action;
    actionPointer->actionUseIndex = 0;
    actionPointer->unkC = 0;
}

void SetWalkAction(struct DungeonActionContainer *actionPointer, s16 species)
{
    if (GetIsMoving(species))
    {
        actionPointer->action = DUNGEON_ACTION_WALK;
    }
    else
    {
        actionPointer->action = DUNGEON_ACTION_WAIT;
    }
    actionPointer->actionUseIndex = 0;
    actionPointer->unkC = 0;
}
