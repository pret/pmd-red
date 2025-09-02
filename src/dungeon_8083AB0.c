#include "global.h"
#include "globaldata.h"
#include "dungeon_8083AB0.h"
#include "dungeon_info.h"
#include "dungeon_util.h"
#include "text_util.h"
#include "dungeon_logic.h"
#include "dungeon_data.h"
#include "dungeon_strings.h"
#include "run_dungeon.h"

void sub_8083AB0(s16 dungeonExitReason_, Entity *target, Entity *entity)
{
  u8 *defPtr;
  u8 *attackPtr;
  u8 *spDefPtr;
  EntityInfo * entityInfo;
  EntityInfo * targetEntityInfo;
  u8 *spAttPtr;
  u8 buffer [0x14];
  UnkDungeonGlobal_unk1CE98_sub *temp;
  u8 *id;
  s32 dungeonExitReason = dungeonExitReason_;

  temp = &gDungeon->unk1CE98;
  targetEntityInfo = NULL;
  if ((EntityIsValid(target)) && (GetEntityType(target) == ENTITY_MONSTER)) {
    targetEntityInfo = GetEntInfo(target);
  }
  entityInfo = GetEntInfo(entity);
  if (targetEntityInfo != NULL) {
    sub_80709C8(buffer, targetEntityInfo);
    CopyStringtoBuffer(temp->buffer1, buffer);
  }
  else {
    CopyStringtoBuffer(temp->buffer1, gUnknown_80FE6F4); // Someone
  }
  sub_80709C8(buffer,entityInfo);
  CopyStringtoBuffer(temp->buffer2, buffer);
  temp->moveID = dungeonExitReason;
  temp->heldItem = entityInfo->heldItem;
  temp->exp = entityInfo->exp;
  temp->level = entityInfo->level;
  temp->maxHPStat = entityInfo->maxHPStat;
  temp->atk = entityInfo->atk[0];
  temp->spAtk = entityInfo->atk[1];
  temp->def = entityInfo->def[0];
  temp->spDef = entityInfo->def[1];
  temp->dungeonLocation = gDungeon->unk644.dungeonLocation;
  attackPtr = &temp->attBoost;
  *attackPtr = 0;
  spAttPtr = &temp->spAttBoost;
  *spAttPtr = 0;
  defPtr = &temp->defBoost;
  *defPtr = 0;
  spDefPtr = &temp->spDefBoost;
  *spDefPtr = 0;
  if ((entityInfo->heldItem.flags & ITEM_FLAG_EXISTS) && !(entityInfo->heldItem.flags & ITEM_FLAG_STICKY)) {
    id = &entityInfo->heldItem.id;
    if (*id == ITEM_POWER_BAND) {
      *attackPtr += gUnknown_810AC60;
    }
    if (*id == ITEM_MUNCH_BELT) {
      *attackPtr += gUnknown_810AC68;
    }
    if (*id == ITEM_SPECIAL_BAND) {
      *spAttPtr += gUnknown_810AC62;
    }
    if (*id == ITEM_MUNCH_BELT) {
      *spAttPtr += gUnknown_810AC68;
    }
    if (*id == ITEM_DEF_SCARF) {
      *defPtr += gUnknown_810AC64;
    }
    if (*id == ITEM_ZINC_BAND) {
      *spDefPtr += gUnknown_810AC66;
    }
  }
}

bool8 sub_8083C24(void)
{
    UnkDungeonGlobal_unk1CE98_sub *temp = &gDungeon->unk1CE98;

    if (temp->moveID < 0x226)
        return TRUE;

    return FALSE;
}

bool8 sub_8083C50(void)
{
    UnkDungeonGlobal_unk1CE98_sub *temp = &gDungeon->unk1CE98;

    if (temp->moveID == 0x227 || temp->moveID == 0x22A || temp->moveID == 0x228)
        return TRUE;

    return FALSE;
}

bool8 sub_8083C88(u8 param_1)
{
    UnkDungeonGlobal_unk1CE98_sub *temp = &gDungeon->unk1CE98;

    if ((!HasCheckpoint(gDungeon->unk644.dungeonLocation.id) && (gDungeon->unk644.unk18 != 0 || param_1 != 0))
        || temp->moveID != 0x227) {
        return TRUE;
    }

    return FALSE;
}
