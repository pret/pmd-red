#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "text_3.h"
#include "code_800D090.h"
#include "music_util.h"
#include "input.h"
#include "items.h"
#include "kecleon_bros3.h"
#include "memory.h"
#include "menu_input.h"
#include "text_1.h"
#include "text_2.h"

static EWRAM_INIT MenuHeaderWindow *gUnknown_203B21C = {NULL};
static EWRAM_INIT u16 gUnknown_203B220 = {0};

#include "data/kecleon_bros3.h"

static void sub_801A430(void);

// arm9.bin::02025DDC
bool8 sub_801A20C(u32 r0)
{
    if (CountKecleonWareItems() == 0)
        return FALSE;

    gUnknown_203B21C = MemoryAlloc(sizeof(*gUnknown_203B21C), 8);
    gUnknown_203B21C->m.menuWinId = r0;
    gUnknown_203B21C->m.menuWindow = &gUnknown_203B21C->m.windows.id[gUnknown_203B21C->m.menuWinId];
    RestoreSavedWindows(&gUnknown_203B21C->m.windows);
    gUnknown_203B21C->m.windows.id[gUnknown_203B21C->m.menuWinId] = sUnknown_80DB914;
    gUnknown_203B21C->m.menuWindow->header = &gUnknown_203B21C->header;
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B21C->m.windows, TRUE, TRUE);
    CreateMenuOnWindow(&gUnknown_203B21C->m.input, CountKecleonWareItems(), 10, r0);
    gUnknown_203B21C->m.input.menuIndex = gUnknown_203B220;
    MenuUpdatePagesData(&gUnknown_203B21C->m.input);
    sub_801A430();
    sub_801A4A4();
    return TRUE;
}

u32 sub_801A2A8(bool8 r0)
{
    Item slot;
    BulkItem *item;

    if (!r0) {
        sub_8013660(&gUnknown_203B21C->m.input);
        return 0;
    }

    switch (GetKeyPress(&gUnknown_203B21C->m.input)) {
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
            if (MenuCursorUpdate(&gUnknown_203B21C->m.input, 1) != 0) {
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
    return GET_CURRENT_MENU_ENTRY(gUnknown_203B21C->m.input);
}

// arm9.bin::02025C64
void sub_801A398(bool8 r0)
{
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B21C->m.windows, FALSE, FALSE);
    gUnknown_203B21C->m.input.totalEntriesCount = CountKecleonWareItems();
    MenuUpdatePagesData(&gUnknown_203B21C->m.input);
    sub_801A430();
    sub_801A4A4();
    if (r0)
        AddMenuCursorSprite(&gUnknown_203B21C->m.input);
}

// arm9.bin::02025BD4
void sub_801A3DC(void)
{
    if (gUnknown_203B21C != NULL) {
        gUnknown_203B220 = gUnknown_203B21C->m.input.menuIndex;
        gUnknown_203B21C->m.windows.id[gUnknown_203B21C->m.menuWinId] = sUnknown_80DB8FC;
        ResetUnusedInputStruct();
        ShowWindows(&gUnknown_203B21C->m.windows, TRUE, TRUE);
        MemoryFree(gUnknown_203B21C);
        gUnknown_203B21C = NULL;
    }
}

static void sub_801A430(void)
{
    gUnknown_203B21C->header.count = gUnknown_203B21C->m.input.pagesCount;
    gUnknown_203B21C->header.currId = gUnknown_203B21C->m.input.currPage;
    gUnknown_203B21C->header.width = 10;
    gUnknown_203B21C->header.f3 = 0;

    UPDATE_MENU_WINDOW_HEIGHT(gUnknown_203B21C->m);
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

    CallPrepareTextbox_8008C54(gUnknown_203B21C->m.menuWinId);
    sub_80073B8(gUnknown_203B21C->m.menuWinId);
    PrintStringOnWindow(gUnknown_203B21C->m.input.currPage * 8 + 10, 0, sGoods, gUnknown_203B21C->m.menuWinId, 0);

    for (index = 0; index < gUnknown_203B21C->m.input.currPageEntries; index++) {
        temp_calc = (gUnknown_203B21C->m.input.currPage * gUnknown_203B21C->m.input.entriesPerPage) + index;
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
            y = GetMenuEntryYCoord(&gUnknown_203B21C->m.input, index);
            PrintStringOnWindow(8, y, buffer1, gUnknown_203B21C->m.menuWinId, 0);
        }
        else {
            sprintfStatic(buffer2, sFmtRed, buffer1);
            y = GetMenuEntryYCoord(&gUnknown_203B21C->m.input, index);
            PrintStringOnWindow(8, y, buffer2, gUnknown_203B21C->m.menuWinId, 0);
        }
    }

    sub_80073E0(gUnknown_203B21C->m.menuWinId);
}
