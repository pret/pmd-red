#include "global.h"
#include "dungeon_action.h"
#include "dungeon_entity.h"

void SetAction(struct DungeonActionContainer *actionPointer, u16 action)
{
    actionPointer->action = action;
    actionPointer->actionUseIndex = 0;
    actionPointer->unkC = 0;
}
