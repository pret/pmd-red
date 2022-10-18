#include "global.h"
#include "dungeon_action.h"

#include "constants/dungeon_action.h"
#include "dungeon_entity.h"
#include "dungeon_global_data.h"
#include "dungeon_leader.h"
#include "pokemon.h"
#include "item.h"

extern u8 *gUnknown_80F91EC[];
extern u8 *gUnknown_80F7C50[];
extern u8 gUnknown_80F697C[];

struct ItemText
{
    u8 *desc;
    u8 *useText;
};
extern const struct ItemText gActions[];


extern u8 sub_8043D10(void);
extern bool8 sub_8044B28(void);

bool8 sub_8044B28(void)
{
    if (gDungeonGlobalData->unk4 == 0) {
        if (GetLeaderEntity() == NULL) {
            gDungeonGlobalData->unk654 = 1;
        }
        else if (gDungeonGlobalData->unk2 == 1) {
            gDungeonGlobalData->unk654 = 2;
        }
        else if (gDungeonGlobalData->unk2 != 2) {
            return FALSE;
        }
        else {
            gDungeonGlobalData->unk654 = 2;
        }
    }
    return TRUE;
}
 
bool8 sub_8044B84(void)
{
    if(gDungeonGlobalData->unk10 != 0)
    {
        return TRUE;
    }
    else {
        return sub_8044B28();
    }
}

u8 *sub_8044BA8(u16 param_1, u8 itemIndex)
{
  u32 uVar3;
  u32 uVar4;
  
  if ((param_1 == 0x26) && (sub_8043D10() == 2)) {
    return *gUnknown_80F91EC;
  }
  else {
    uVar3 = uVar4 = strcmp(gUnknown_80F7C50[param_1 << 1], gUnknown_80F697C);
    if (uVar3 != 0) {
      uVar4 = 1;
    }
    if ((u8)(uVar4) == 0) {
        return gActions[GetItemCategory(itemIndex)].useText;
    }
    else
    {
        return gUnknown_80F7C50[param_1 << 1];
    }
  }
}

void sub_8044C10(u8 param_1)
{
    struct DungeonEntityData * entityData = GetLeaderEntityData();

    entityData->action.action = DUNGEON_ACTION_NONE;

    if(param_1)
    {
        entityData->action.actionUseIndex = 0;
        entityData->action.unkC = 0;
        entityData->itemTargetPosition.x = -1;
        entityData->itemTargetPosition.y = -1;
    }
}

void sub_8044C50(u16 action)
{
    struct DungeonEntityData * entityData = GetLeaderEntityData();

    entityData->action.action = action;
    entityData->action.actionUseIndex = 0;
    entityData->action.unkC = 0;
    entityData->itemTargetPosition.x = -1;
    entityData->itemTargetPosition.y = -1;
}

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
