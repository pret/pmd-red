#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "text_3.h"
#include "code_800D090.h"
#include "music_util.h"
#include "input.h"
#include "items.h"
#include "kecleon_bros2.h"
#include "memory.h"
#include "menu_input.h"
#include "text_1.h"
#include "text_2.h"

static EWRAM_INIT MenuHeaderWindow *gUnknown_203B214 = {NULL};
static EWRAM_INIT u16 gUnknown_203B218 = {0};

#include "data/kecleon_bros2.h"

static void sub_801A064(void);

// arm9.bin::020258B0
bool8 sub_8019E40(u32 r0)
{
    if (CountKecleonShopItems() == 0)
        return FALSE;

    gUnknown_203B214 = MemoryAlloc(sizeof(*gUnknown_203B214), MEMALLOC_GROUP_8);
    gUnknown_203B214->m.menuWinId = r0;
    gUnknown_203B214->m.menuWindow = &gUnknown_203B214->m.windows.id[gUnknown_203B214->m.menuWinId];
    RestoreSavedWindows(&gUnknown_203B214->m.windows);
    gUnknown_203B214->m.windows.id[gUnknown_203B214->m.menuWinId] = sUnknown_80DB8CC;
    gUnknown_203B214->m.menuWindow->header = &gUnknown_203B214->header;
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B214->m.windows, TRUE, TRUE);
    CreateMenuOnWindow(&gUnknown_203B214->m.input, CountKecleonShopItems(), 10, r0);
    gUnknown_203B214->m.input.menuIndex = gUnknown_203B218;
    MenuUpdatePagesData(&gUnknown_203B214->m.input);
    sub_801A064();
    sub_801A0D8();
    return TRUE;
}

// arm9.bin::020257BC
u32 sub_8019EDC(bool8 r0)
{
    Item slot;
    BulkItem *item;

    if (!r0) {
        sub_8013660(&gUnknown_203B214->m.input);
        return 0;
    }

    switch (GetKeyPress(&gUnknown_203B214->m.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(MENU_SFX_BACK);
            return 2;
        case INPUT_A_BUTTON:
            item = GetKecleonShopItem(sub_8019FB0());
            slot.id = item->id;
            slot.quantity = item->quantity;

            if (GetActualBuyPrice(&slot) > gTeamInventoryRef->teamMoney)
                PlayMenuSoundEffect(MENU_SFX_FAIL);
            else
                PlayMenuSoundEffect(MENU_SFX_ACCEPT);
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(MENU_SFX_INFO);
            return 4;
        default:
            if (MenuCursorUpdate(&gUnknown_203B214->m.input, 1)) {
                sub_801A064();
                sub_801A0D8();
                return 1;
            }
            return 0;
    }
}

// arm9.bin::02025798
u8 sub_8019FB0(void)
{
    return GET_CURRENT_MENU_ENTRY(gUnknown_203B214->m.input);
}

// arm9.bin::02025738
void sub_8019FCC(bool8 r0)
{
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B214->m.windows, FALSE, FALSE);
    gUnknown_203B214->m.input.totalEntriesCount = CountKecleonShopItems();
    MenuUpdatePagesData(&gUnknown_203B214->m.input);
    sub_801A064();
    sub_801A0D8();
    if (r0)
        AddMenuCursorSprite(&gUnknown_203B214->m.input);
}

// arm9.bin::020256A8
void sub_801A010(void)
{
    if (gUnknown_203B214 != NULL) {
        gUnknown_203B218 = gUnknown_203B214->m.input.menuIndex;
        gUnknown_203B214->m.windows.id[gUnknown_203B214->m.menuWinId] = sUnknown_80DB8B4;
        ResetUnusedInputStruct();
        ShowWindows(&gUnknown_203B214->m.windows, TRUE, TRUE);
        MemoryFree(gUnknown_203B214);
        gUnknown_203B214 = NULL;
    }
}

static void sub_801A064(void)
{
    gUnknown_203B214->header.count = gUnknown_203B214->m.input.pagesCount;
    gUnknown_203B214->header.currId = gUnknown_203B214->m.input.currPage;
    gUnknown_203B214->header.width = 10;
    gUnknown_203B214->header.f3 = 0;

    UPDATE_MENU_WINDOW_HEIGHT(gUnknown_203B214->m);
}

// arm9.bin::02025480
void sub_801A0D8(void)
{
    BulkItem *heldItem;
    s32 buyPrice;
    s32 y;
    s32 index;
    u8 auStack204[80];
    struct unkStruct_8090F58 local_7c;
    u8 auStack112[80];
    Item item;
    u8 temp_calc;

    CallPrepareTextbox_8008C54(gUnknown_203B214->m.menuWinId);
    sub_80073B8(gUnknown_203B214->m.menuWinId);
    PrintStringOnWindow((gUnknown_203B214->m.input.currPage * 8) + 10, 0, sGoods, gUnknown_203B214->m.menuWinId, 0);

    for (index = 0; index < gUnknown_203B214->m.input.currPageEntries; index++) {
        temp_calc = (gUnknown_203B214->m.input.currPage * gUnknown_203B214->m.input.entriesPerPage) + index;
        heldItem = GetKecleonShopItem(temp_calc);
        item.id = heldItem->id;
        item.quantity = heldItem->quantity;
        item.flags = (ITEM_FLAG_EXISTS | ITEM_FLAG_IN_SHOP);
        local_7c.unk0 = 1;
        local_7c.unk4 = 0;
        local_7c.unk6 = 88;
        local_7c.unk8 = 1;
        sub_8090E14(auStack204, &item, &local_7c);
        buyPrice = GetActualBuyPrice(&item);

        if (buyPrice <= gTeamInventoryRef->teamMoney) {
            y = GetMenuEntryYCoord(&gUnknown_203B214->m.input, index);
            PrintStringOnWindow(8, y, auStack204, gUnknown_203B214->m.menuWinId, 0);
        }
        else {
            sprintfStatic(auStack112, sFmtRed, auStack204);
            y = GetMenuEntryYCoord(&gUnknown_203B214->m.input, index);
            PrintStringOnWindow(8, y, auStack112, gUnknown_203B214->m.menuWinId, 0);
        }
    }

    sub_80073E0(gUnknown_203B214->m.menuWinId);
}
