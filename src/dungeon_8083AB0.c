#include "global.h"
#include "globaldata.h"
#include "constants/dungeon_exit.h"
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
  DungeonExitSummary *exitSummary;
  u8 *id;
  s32 dungeonExitReason = dungeonExitReason_;

  exitSummary = &gDungeon->exitSummary;
  targetEntityInfo = NULL;
  if ((EntityIsValid(target)) && (GetEntityType(target) == ENTITY_MONSTER)) {
    targetEntityInfo = GetEntInfo(target);
  }
  entityInfo = GetEntInfo(entity);
  if (targetEntityInfo != NULL) {
    sub_80709C8(buffer, targetEntityInfo);
    CopyStringtoBuffer(exitSummary->buffer1, buffer);
  }
  else {
    CopyStringtoBuffer(exitSummary->buffer1, gUnknown_80FE6F4); // Someone
  }
  sub_80709C8(buffer,entityInfo);
  CopyStringtoBuffer(exitSummary->buffer2, buffer);
  exitSummary->exitReason = dungeonExitReason;
  exitSummary->heldItem = entityInfo->heldItem;
  exitSummary->exp = entityInfo->exp;
  exitSummary->level = entityInfo->level;
  exitSummary->maxHPStat = entityInfo->maxHPStat;
  exitSummary->atk = entityInfo->atk[0];
  exitSummary->spAtk = entityInfo->atk[1];
  exitSummary->def = entityInfo->def[0];
  exitSummary->spDef = entityInfo->def[1];
  exitSummary->dungeonLocation = gDungeon->unk644.dungeonLocation;
  attackPtr = &exitSummary->attBoost;
  *attackPtr = 0;
  spAttPtr = &exitSummary->spAttBoost;
  *spAttPtr = 0;
  defPtr = &exitSummary->defBoost;
  *defPtr = 0;
  spDefPtr = &exitSummary->spDefBoost;
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

bool8 IsUnsuccessfulDungeonExit(void)
{
    DungeonExitSummary *exitSummary = &gDungeon->exitSummary;

    if (exitSummary->exitReason < DUNGEON_EXIT_REASON_SUCCESS)
        return TRUE;

    return FALSE;
}

bool8 sub_8083C50(void)
{
    DungeonExitSummary *exitSummary = &gDungeon->exitSummary;

    if (exitSummary->exitReason == DUNGEON_EXIT_CLEARED_DUNGEON
     || exitSummary->exitReason == DUNGEON_EXIT_BEFRIENDED_MEW
     || exitSummary->exitReason == DUNGEON_EXIT_SUCCEEDED_IN_RESCUE_MISSION)
        return TRUE;

    return FALSE;
}

bool8 sub_8083C88(u8 param_1)
{
    DungeonExitSummary *exitSummary = &gDungeon->exitSummary;

    if ((!HasCheckpoint(gDungeon->unk644.dungeonLocation.id) && (gDungeon->unk644.unk18 != 0 || param_1 != 0))
        || exitSummary->exitReason != DUNGEON_EXIT_CLEARED_DUNGEON) {
        return TRUE;
    }

    return FALSE;
}
