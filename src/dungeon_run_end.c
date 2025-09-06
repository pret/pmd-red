#include "global.h"
#include "globaldata.h"
#include "dungeon_misc.h"
#include "dungeon_run_end.h"
#include "constants/dungeon_exit.h"
#include "structs/str_dungeon.h"
#include "data_serializer.h"
#include "dungeon_info.h"
#include "items.h"
#include "moves.h"
#include "string_format.h"
#include "text_1.h"
#include "text_3.h"
#include "text_util.h"
#include "strings.h"

#define TEXT_BUFFER_LEN 200

static void WriteDeathText(s16 dungeonExitReason, u8 *buffer)
{
    u16 dungeonExitReason_u16;
    s32 dungeonExitReason_s32 = dungeonExitReason;
    Move move;

    if (dungeonExitReason_s32 < DUNGEON_EXIT_REASON_START) {
        // Needed this cast/variable to match
        dungeonExitReason_u16 = dungeonExitReason_s32;
        InitPokemonMoveOrNullObject(&move, dungeonExitReason_u16);
        BufferMoveName(gFormatBuffer_Items[0], &move, NULL);
        FormatString(gText_DeathToMove, buffer, buffer + TEXT_BUFFER_LEN, 0); // $m0's $i0
    } else {
        strncpy(buffer, gDungeonExitReasonTexts[dungeonExitReason - DUNGEON_EXIT_REASON_START].text, TEXT_BUFFER_LEN);
    }
}

static bool8 HasDefeatedByPrefix(s16 dungeonExitReason)
{
    if (dungeonExitReason < DUNGEON_EXIT_REASON_START)
    {
        // all moves are prefixed by "was defeated by..."
        return TRUE;
    }
    else
    {
        // some exit reason texts are to be put after "was defeated by..."
        return gDungeonExitReasonTexts[dungeonExitReason  - DUNGEON_EXIT_REASON_START].defeatedByPrefix;
    }
}

void PrintOnDungeonFinishedWindow(u32 windowId, const u8 *headerText, DungeonExitSummary *exitSummary)
{
    u8 buffer[TEXT_BUFFER_LEN];
    s32 x, y;
    Item *item;

    sub_80073B8(windowId);
    PrintFormattedStringOnWindow(16,0,headerText,windowId,0);
    PrintYellowDungeonNametoBuffer(gFormatBuffer_Monsters[0], &exitSummary->dungeonLocation);
    PrintFormattedStringOnWindow(4,16,gText_AlignPlaceX,windowId,0); // #+Place: $m0
    y = 26;
    StrncpyCustom(gFormatBuffer_Monsters[0], exitSummary->buffer1, POKEMON_NAME_LENGTH);
    StrncpyCustom(gFormatBuffer_Monsters[1], exitSummary->buffer2, POKEMON_NAME_LENGTH);
    if (HasDefeatedByPrefix(exitSummary->exitReason)) {
        // $m1 was defeated by
        FormatString(gText_Pokemon1WasDefeatedBy,buffer, buffer + sizeof(buffer),0);
    }
    else {
        // $m1
        FormatString(gText_Pokemon1,buffer, buffer + sizeof(buffer),0);
    }

    x = (176 - GetStringLineWidth(buffer)) / 2;
    PrintFormattedStringOnWindow(x,y,buffer,windowId,0);

    y += 10;
    WriteDeathText(exitSummary->exitReason, buffer);

    x = (176 - GetStringLineWidth(buffer)) / 2;
    PrintFormattedStringOnWindow(x,y,buffer,windowId,0);

    y += 16;
    gFormatArgs[0] = exitSummary->exp;
    gFormatArgs[1] = exitSummary->level;
    if (gFormatArgs[1] >= 100) {
        PrintFormattedStringOnWindow(4,y,gUnknown_81138C0,windowId,0);
    }
    else {
        PrintFormattedStringOnWindow(4,y,gUnknown_8113898,windowId,0);
    }
    y += 10;
    gFormatArgs[0] = exitSummary->maxHPStat;
    PrintFormattedStringOnWindow(4,y,gUnknown_81138D0,windowId,0);
    y += 10;
    gFormatArgs[0] = exitSummary->atk;
    gFormatArgs[1] = exitSummary->def;
    if (exitSummary->attBoost) {
        gFormatArgs[0] = gFormatArgs[0] + exitSummary->attBoost;
        PrintFormattedStringOnWindow(4,y,gUnknown_8113950,windowId,0);
    }
    else {
        PrintFormattedStringOnWindow(4,y,gUnknown_81138E4,windowId,0);
    }
    if (exitSummary->defBoost) {
        gFormatArgs[1] = gFormatArgs[1] + exitSummary->defBoost;
        PrintFormattedStringOnWindow(4,y,gUnknown_8113974,windowId,0);
    }
    else {
        PrintFormattedStringOnWindow(4,y,gUnknown_8113900,windowId,0);
    }
    y += 10;
    gFormatArgs[0] = exitSummary->spAtk;
    gFormatArgs[1] = exitSummary->spDef;
    if (exitSummary->spAttBoost) {
        gFormatArgs[0] = gFormatArgs[0] + exitSummary->spAttBoost;
        PrintFormattedStringOnWindow(4,y,gUnknown_8113990,windowId,0);
    }
    else {
        PrintFormattedStringOnWindow(4,y,gUnknown_8113918,windowId,0);
    }
    if (exitSummary->spDefBoost) {
        gFormatArgs[1] = gFormatArgs[1] + exitSummary->spDefBoost;
        PrintFormattedStringOnWindow(4,y,gUnknown_81139B4,windowId,0);
    }
    else {
        PrintFormattedStringOnWindow(4,y,gUnknown_8113934,windowId,0);
    }
    y += 16;
    item = &(exitSummary->heldItem);
    if ((exitSummary->heldItem.flags & ITEM_FLAG_EXISTS)) {
        sub_8090E14(gFormatBuffer_Items[0],item,0);
    }
    else {
        strcpy(gFormatBuffer_Items[0],gUnknown_81139B8);
    }
    PrintFormattedStringOnWindow(4,y,gText_ItemAlignedX,windowId,0);
    sub_80073E0(windowId);
}

s16 GetDungeonExitReasonFromMoveOrItemID(u16 moveID, u8 id)
{
    if(id != 0)
    {
        if(GetItemCategory(id) == CATEGORY_ORBS)
            return DUNGEON_EXIT_FAINTED_FROM_WONDER_ORB;
        else
            return DUNGEON_EXIT_FAINTED_FROM_ITEM;
    }
    else
    {
        return moveID;
    }
}
