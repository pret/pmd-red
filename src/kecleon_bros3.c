#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "structs/struct_sub80095e4.h"
#include "code_800D090.h"
#include "music_util.h"
#include "input.h"
#include "items.h"
#include "kecleon_bros3.h"
#include "memory.h"
#include "menu_input.h"
#include "text_1.h"
#include "text_2.h"

static EWRAM_INIT struct_Sub80095E4_2 *gUnknown_203B21C = {NULL};
static EWRAM_INIT u16 gUnknown_203B220 = {0};

#include "data/kecleon_bros3.h"

static void sub_801A430(void);

// arm9.bin::02025DDC
bool8 sub_801A20C(u32 r0)
{
    if (CountKecleonWareItems() == 0)
        return FALSE;

    gUnknown_203B21C = MemoryAlloc(sizeof(*gUnknown_203B21C), 8);
    gUnknown_203B21C->s0.winId = r0;
    gUnknown_203B21C->s0.unk38 = &gUnknown_203B21C->s0.windows.id[gUnknown_203B21C->s0.winId];
    RestoreSavedWindows(&gUnknown_203B21C->s0.windows);
    gUnknown_203B21C->s0.windows.id[gUnknown_203B21C->s0.winId] = sUnknown_80DB914;
    gUnknown_203B21C->s0.unk38->header = &gUnknown_203B21C->header;
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B21C->s0.windows, TRUE, TRUE);
    CreateMenuOnWindow(&gUnknown_203B21C->s0.input, CountKecleonWareItems(), 10, r0);
    gUnknown_203B21C->s0.input.menuIndex = gUnknown_203B220;
    sub_8013984(&gUnknown_203B21C->s0.input);
    sub_801A430();
    sub_801A4A4();
    return TRUE;
}

u32 sub_801A2A8(bool8 r0)
{
    Item slot;
    BulkItem *item;

    if (!r0) {
        sub_8013660(&gUnknown_203B21C->s0.input);
        return 0;
    }

    switch (GetKeyPress(&gUnknown_203B21C->s0.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            item = GetKecleonWareItem(sub_801A37C());

            slot.id = item->id;
            slot.quantity = item->quantity;

            if (GetStackBuyPrice(&slot) > gTeamInventoryRef->teamMoney)
                PlayMenuSoundEffect(2);
            else
                PlayMenuSoundEffect(0);
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(4);
            return 4;
        default:
            if (sub_80138B8(&gUnknown_203B21C->s0.input, 1) != 0) {
                sub_801A430();
                sub_801A4A4();
                return 1;
            }
            return 0;
    }
}

// arm9.bin::02025CC4
u8 sub_801A37C(void)
{
    return (gUnknown_203B21C->s0.input.currPage * gUnknown_203B21C->s0.input.entriesPerPage) + gUnknown_203B21C->s0.input.menuIndex;
}

// arm9.bin::02025C64
void sub_801A398(bool8 r0)
{
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B21C->s0.windows, FALSE, FALSE);
    gUnknown_203B21C->s0.input.totalEntriesCount = CountKecleonWareItems();
    sub_8013984(&gUnknown_203B21C->s0.input);
    sub_801A430();
    sub_801A4A4();
    if (r0)
        AddMenuCursorSprite(&gUnknown_203B21C->s0.input);
}

// arm9.bin::02025BD4
void sub_801A3DC(void)
{
    if (gUnknown_203B21C != NULL) {
        gUnknown_203B220 = gUnknown_203B21C->s0.input.menuIndex;
        gUnknown_203B21C->s0.windows.id[gUnknown_203B21C->s0.winId] = sUnknown_80DB8FC;
        ResetUnusedInputStruct();
        ShowWindows(&gUnknown_203B21C->s0.windows, TRUE, TRUE);
        MemoryFree(gUnknown_203B21C);
        gUnknown_203B21C = NULL;
    }
}

static void sub_801A430(void)
{
    gUnknown_203B21C->header.count = gUnknown_203B21C->s0.input.unk20;
    gUnknown_203B21C->header.currId = gUnknown_203B21C->s0.input.currPage;
    gUnknown_203B21C->header.width = 10;
    gUnknown_203B21C->header.f3 = 0;

    SUB_80095E4_CALL(gUnknown_203B21C->s0);
}

// arm9.bin::020259AC
void sub_801A4A4(void)
{
    BulkItem *heldItem;
    s32 buyPrice;
    s32 y;
    s32 index;
    u8 buffer1[80];
    struct unkStruct_8090F58 local_7c;
    u8 buffer2[80];
    Item item;
    u8 temp_calc;

    CallPrepareTextbox_8008C54(gUnknown_203B21C->s0.winId);
    sub_80073B8(gUnknown_203B21C->s0.winId);
    PrintStringOnWindow(gUnknown_203B21C->s0.input.currPage * 8 + 10, 0, sGoods, gUnknown_203B21C->s0.winId, 0);

    for (index = 0; index < gUnknown_203B21C->s0.input.unk1A; index++) {
        temp_calc = (gUnknown_203B21C->s0.input.currPage * gUnknown_203B21C->s0.input.entriesPerPage) + index;
        heldItem = GetKecleonWareItem(temp_calc);
        item.id = heldItem->id;
        item.quantity = heldItem->quantity;
        item.flags = (ITEM_FLAG_EXISTS | ITEM_FLAG_IN_SHOP);
        local_7c.unk0 = 1;
        local_7c.unk4 = 0;
        local_7c.unk6 = 88;
        local_7c.unk8 = 1;
        sub_8090E14(buffer1, &item, &local_7c);
        buyPrice = GetStackBuyPrice(&item);

        if (buyPrice <= gTeamInventoryRef->teamMoney) {
            y = GetMenuEntryYCoord(&gUnknown_203B21C->s0.input, index);
            PrintStringOnWindow(8, y, buffer1, gUnknown_203B21C->s0.winId, 0);
        }
        else {
            sprintfStatic(buffer2, sFmtRed, buffer1);
            y = GetMenuEntryYCoord(&gUnknown_203B21C->s0.input, index);
            PrintStringOnWindow(8, y, buffer2, gUnknown_203B21C->s0.winId, 0);
        }
    }

    sub_80073E0(gUnknown_203B21C->s0.winId);
}
