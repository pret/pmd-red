#include "global.h"
#include "globaldata.h"
#include "music_util.h"
#include "code_801C8C4.h"
#include "input.h"
#include "items.h"
#include "memory.h"
#include "menu_input.h"
#include "text_1.h"
#include "text_2.h"
#include "text_3.h"

EWRAM_INIT static struct unkStruct_203B244 *sUnknown_203B244 = { NULL };
EWRAM_INIT static u32 sUnknown_203B248 = {0};
EWRAM_INIT static u16 sUnknown_203B24C = {0};
EWRAM_INIT static u16 sUnknown_203B24E = {0};

#include "data/code_801C8C4.h"

static void sub_801CC38(void);
static u32 sub_801CE58(void);

bool8 sub_801C8C4(s32 a0, s32 a1, DungeonPos *a2, u32 a3)
{
    if (sub_801CF14(a0))
        return FALSE;

    if (sUnknown_203B244 == NULL)
        sUnknown_203B244 = MemoryAlloc(sizeof(struct unkStruct_203B244), 8);

    sUnknown_203B244->unk0 = a0;
    sub_801CF94();
    sUnknown_203B244->unk4B4.m.menuWinId = a1;
    sUnknown_203B244->unk4B4.m.menuWindow = &sUnknown_203B244->unk4B4.m.windows.id[a1];
    RestoreSavedWindows(&sUnknown_203B244->unk4B4.m.windows);
    sUnknown_203B244->unk4B4.m.windows.id[sUnknown_203B244->unk4B4.m.menuWinId] = sUnknown_80DBE54;
    sUnknown_203B244->unk4B4.m.menuWindow->header = &sUnknown_203B244->unk4B4.header;

    if (a2 != NULL)
        sUnknown_203B244->unk4B4.m.windows.id[sUnknown_203B244->unk4B4.m.menuWinId].pos = *a2;

    sub_8012D08(sUnknown_203B244->unk4B4.m.menuWindow, a3);
    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B244->unk4B4.m.windows, TRUE, TRUE);
    CreateMenuOnWindow(&sUnknown_203B244->unk4B4.m.input, sub_801CE58(), a3, a1);

    if (sUnknown_203B248 == sUnknown_203B244->unk0) {
        sUnknown_203B244->unk4B4.m.input.menuIndex = sUnknown_203B24C;
        sUnknown_203B244->unk4B4.m.input.currPage = sUnknown_203B24E;
        MenuUpdatePagesData(&sUnknown_203B244->unk4B4.m.input);
    }

    sub_801CC38();
    sub_801CCD8();
    return TRUE;
}

u32 sub_801CA08(bool8 a0)
{
    u32 index;
    u32 temp;
    u32 flag;

    if (a0 == FALSE) {
        sub_8013660(&sUnknown_203B244->unk4B4.m.input);
        return 0;
    }

    switch (GetKeyPress(&sUnknown_203B244->unk4B4.m.input)) {
        case 2:
            PlayMenuSoundEffect(1);
            return 2;
        case 1:
            PlayMenuSoundEffect(0);
            return 3;
        case 5:
        case 6:
            if (sUnknown_203B244->unk0 != 1)
                goto _0801CAF2;

            index = sub_801CB24();
            temp = sub_801CFE0(index);
            flag = FALSE;
            if (temp != 0 || (flag = (INVENTORY_SIZE > GetNumberOfFilledInventorySlots() + sub_801CFB8())) || flag) {
                PlayMenuSoundEffect(6);
                sUnknown_203B244->unkF4[index] = sUnknown_203B244->unkF4[index] ^ 1;
                MenuCursorUpdate(&sUnknown_203B244->unk4B4.m.input,0);
                sub_801CCD8();
                return 1;
            }

            PlayMenuSoundEffect(2);
            goto _0801CAF2;
        case 4:
            PlayMenuSoundEffect(4);
            return 4;
        default:
    _0801CAF2:
            if (MenuCursorUpdate(&sUnknown_203B244->unk4B4.m.input, 1)) {
                sub_801CC38();
                sub_801CCD8();
                return 1;
            }
            return 0;
    }
}

u8 sub_801CB24(void)
{
    return sUnknown_203B244->itemIDs[GET_CURRENT_MENU_ENTRY(sUnknown_203B244->unk4B4.m.input)];
}

void sub_801CB5C(bool8 a0)
{
    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B244->unk4B4.m.windows, FALSE, FALSE);
    sUnknown_203B244->unk4B4.m.input.totalEntriesCount = sub_801CE58();
    MenuUpdatePagesData(&sUnknown_203B244->unk4B4.m.input);
    sub_801CC38();
    sub_801CCD8();

    if (a0)
        AddMenuCursorSprite(&sUnknown_203B244->unk4B4.m.input);
}

void sub_801CBB8(void)
{
    if (sUnknown_203B244 != NULL) {
        sUnknown_203B248 = sUnknown_203B244->unk0;
        sUnknown_203B24C = sUnknown_203B244->unk4B4.m.input.menuIndex;
        sUnknown_203B24E = sUnknown_203B244->unk4B4.m.input.currPage;
        sUnknown_203B244->unk4B4.m.windows.id[sUnknown_203B244->unk4B4.m.menuWinId] = sUnknown_80DBE3C;
        ResetUnusedInputStruct();
        ShowWindows(&sUnknown_203B244->unk4B4.m.windows, TRUE, TRUE);
        MemoryFree(sUnknown_203B244);
        sUnknown_203B244 = NULL;
    }
}

static void sub_801CC38(void)
{
    sUnknown_203B244->unk4B4.header.count = 1;
    sUnknown_203B244->unk4B4.header.currId = 0;
    sUnknown_203B244->unk4B4.header.width = 12;
    sUnknown_203B244->unk4B4.header.f3 = 0;

    UPDATE_MENU_WINDOW_HEIGHT(sUnknown_203B244->unk4B4.m);
}

void sub_801CCD8(void)
{
    u32 y;
    u32 y2;
    u32 itemID;
    s32 index;
    u8 buffer[80];

    CallPrepareTextbox_8008C54(sUnknown_203B244->unk4B4.m.menuWinId);
    sub_80073B8(sUnknown_203B244->unk4B4.m.menuWinId);
    PrintStringOnWindow(10, 0, sStorage, sUnknown_203B244->unk4B4.m.menuWinId, 0);
    PrintNumOnWindow(sUnknown_203B244->unk4B4.header.width * 8 + 4, 0, sUnknown_203B244->unk4B4.m.input.currPage + 1, 2, 7, sUnknown_203B244->unk4B4.m.menuWinId);

    for(index = 0; index < sUnknown_203B244->unk4B4.m.input.currPageEntries; index++) {
        itemID = sUnknown_203B244->itemIDs[(sUnknown_203B244->unk4B4.m.input.currPage * sUnknown_203B244->unk4B4.m.input.entriesPerPage) + index];
        BufferItemName(buffer, itemID, NULL);
        y = GetMenuEntryYCoord(&sUnknown_203B244->unk4B4.m.input, index);
        PrintStringOnWindow(8, y, buffer, sUnknown_203B244->unk4B4.m.menuWinId, 0);
        y2 = GetMenuEntryYCoord(&sUnknown_203B244->unk4B4.m.input, index);
        PrintNumOnWindow((sUnknown_203B244->unk4B4.m.menuWindow->width * 8) - 2, y2, gTeamInventoryRef->teamStorage[itemID], 3, 5, sUnknown_203B244->unk4B4.m.menuWinId);

        if (sub_801CFE0(itemID) & 1)
            sub_8007B7C(sUnknown_203B244->unk4B4.m.menuWinId, 8, GetMenuEntryYCoord(&sUnknown_203B244->unk4B4.m.input, index), (sUnknown_203B244->unk4B4.m.menuWindow->width - 1) * 8, 10);
    }

    sub_80073E0(sUnknown_203B244->unk4B4.m.menuWinId);
}

static u32 sub_801CE58(void)
{
    u8 uVar1;
    s32 orderL;
    s32 orderR;
    s32 itemCount;
    s32 itemR;
    s32 itemIndex; // re-used variable to match

    itemCount = 0;
    for (itemIndex = 1; itemIndex < NUMBER_OF_ITEM_IDS; itemIndex++) {
        if (sUnknown_203B244->unk0 == 2 || (gTeamInventoryRef->teamStorage[itemIndex] != 0 && IsNotMoneyOrUsedTMItem(itemIndex))) {
            sUnknown_203B244->itemIDs[itemCount] = itemIndex;
            itemCount++;
        }
    }

    for (itemIndex = 0; itemIndex < itemCount - 1; itemIndex++) {
        for (itemR = itemIndex + 1; itemR < itemCount; itemR++) {
            orderL = GetItemOrder(sUnknown_203B244->itemIDs[itemIndex]);
            orderR = GetItemOrder(sUnknown_203B244->itemIDs[itemR]);

            if (orderL > orderR) {
                uVar1 = sUnknown_203B244->itemIDs[itemIndex];
                sUnknown_203B244->itemIDs[itemIndex] =  sUnknown_203B244->itemIDs[itemR];
                sUnknown_203B244->itemIDs[itemR] = uVar1;
            }
        }
    }

    return itemCount;
}

bool8 sub_801CF14(s32 a0)
{
    s32 itemID;

    if (a0 == 2)
        return FALSE;

    for (itemID = ITEM_STICK; itemID < NUMBER_OF_ITEM_IDS; itemID++) {
        if (gTeamInventoryRef->teamStorage[itemID] != 0 && IsNotMoneyOrUsedTMItem(itemID))
            return FALSE;
    }

    return TRUE;
}

bool8 sub_801CF50(s32 a0)
{
    s32 itemID;

    if (a0 == 2)
        return FALSE;

    for (itemID = ITEM_STICK; itemID < NUMBER_OF_ITEM_IDS; itemID++) {
        if (IsNotMoneyOrUsedTMItem(itemID) && gTeamInventoryRef->teamStorage[itemID] < 999)
            return FALSE;
    }

    return TRUE;
}

void sub_801CF94(void)
{
    s32 itemID;

    for (itemID = ITEM_NOTHING; itemID < NUMBER_OF_ITEM_IDS; itemID++)
        sUnknown_203B244->unkF4[itemID] = 0;
}

s32 sub_801CFB8(void)
{
    s32 itemID;
    s32 counter;

    counter = 0;
    for (itemID = ITEM_NOTHING; itemID < NUMBER_OF_ITEM_IDS; itemID++) {
        if (sUnknown_203B244->unkF4[itemID] != 0)
            counter++;
    }

    return counter;
}

u32 sub_801CFE0(u8 index)
{
    return sUnknown_203B244->unkF4[index];
}

UNUSED static void sub_801CFF4(u8 index, u32 value)
{
    sUnknown_203B244->unkF4[index] = value;
}

struct unkStruct_203B244 *sub_801D008(void)
{
    return sUnknown_203B244;
}
