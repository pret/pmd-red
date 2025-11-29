#include "global.h"
#include "globaldata.h"
#include "dungeon_exit.h"
#include "constants/dungeon_exit.h"
#include "dungeon_info.h"
#include "dungeon_util.h"
#include "text_util.h"
#include "dungeon_logic.h"
#include "dungeon_data.h"
#include "dungeon_strings.h"
#include "run_dungeon.h"
#include "items.h"

void SetUpDungeonExitData(s16 dungeonExitReason_, Entity *target, Entity *entity)
{
    EntityInfo * entityInfo;
    u8 buffer [0x14];
    s32 dungeonExitReason = dungeonExitReason_;
    DungeonExitSummary *exitSummary = &gDungeon->exitSummary;
    EntityInfo * targetEntityInfo = NULL;

    if (EntityIsValid(target) && GetEntityType(target) == ENTITY_MONSTER) {
        targetEntityInfo = GetEntInfo(target);
    }
    entityInfo = GetEntInfo(entity);
    if (targetEntityInfo != NULL) {
        CopyEntityNameForDungeonExitSummary(buffer, targetEntityInfo);
        CopyStringtoBuffer(exitSummary->buffer1, buffer);
    }
    else {
        CopyStringtoBuffer(exitSummary->buffer1, gText_Someone); // Someone
    }
    CopyEntityNameForDungeonExitSummary(buffer,entityInfo);
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
    exitSummary->attBoost = 0;
    exitSummary->spAttBoost = 0;
    exitSummary->defBoost = 0;
    exitSummary->spDefBoost = 0;
    if (ItemExists(&entityInfo->heldItem) && !(entityInfo->heldItem.flags & ITEM_FLAG_STICKY)) {
        if (entityInfo->heldItem.id == ITEM_POWER_BAND) {
            exitSummary->attBoost += gPowerBandBoost;
        }
        if (entityInfo->heldItem.id == ITEM_MUNCH_BELT) {
            exitSummary->attBoost += gMunchBeltBoost;
        }
        if (entityInfo->heldItem.id == ITEM_SPECIAL_BAND) {
            exitSummary->spAttBoost += gSpecialBandBoost;
        }
        if (entityInfo->heldItem.id == ITEM_MUNCH_BELT) {
            exitSummary->spAttBoost += gMunchBeltBoost;
        }
        if (entityInfo->heldItem.id == ITEM_DEF_SCARF) {
            exitSummary->defBoost += gDefScarfBoost;
        }
        if (entityInfo->heldItem.id == ITEM_ZINC_BAND) {
            exitSummary->spDefBoost += gZincBandBoost;
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

bool8 sub_8083C88(u8 dungeonMissionKind)
{
    DungeonExitSummary *exitSummary = &gDungeon->exitSummary;

    if ((!HasCheckpoint(gDungeon->unk644.dungeonLocation.id) && (gDungeon->unk644.canChangeLeader || dungeonMissionKind != DUNGEON_MISSION_UNK0))
        || exitSummary->exitReason != DUNGEON_EXIT_CLEARED_DUNGEON) {
        return TRUE;
    }

    return FALSE;
}
