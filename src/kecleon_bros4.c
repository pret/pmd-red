#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "constants/item.h"
#include "structs/menu.h"
#include "structs/struct_sub80095e4.h"
#include "code_800D090.h"
#include "code_80118A4.h"
#include "code_8099360.h"
#include "input.h"
#include "items.h"
#include "kecleon_bros4.h"
#include "memory.h"
#include "menu_input.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"

// size: R=0xF4 | B=0xF0
typedef struct unkStruct_203B224
{
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4[INVENTORY_SIZE];
    /* 0x54 */ struct_Sub80095E4_2 unk54;
} unkStruct_203B224;

static EWRAM_INIT unkStruct_203B224 *gUnknown_203B224 = {NULL};
static EWRAM_INIT u16 gUnknown_203B228 = {0};
static EWRAM_INIT u16 gUnknown_203B22A = {0};

#include "data/kecleon_bros4.h"

static void SortInventoryItems(void);

static void sub_801A998(void);
static s32 sub_801AE24(u32);

// arm9.bin::02026BE4
bool8 sub_801A5D8(u32 param_1, s32 param_2, DungeonPos *param_3, u32 param_4)
{
    if (GetNumberOfFilledInventorySlots() == 0)
        return FALSE;

    if (gUnknown_203B224 == NULL)
        gUnknown_203B224 = MemoryAlloc(sizeof(unkStruct_203B224), 8);

    gUnknown_203B224->unk0 = param_1;
    FillInventoryGaps();
    sub_801AE84();
    gUnknown_203B224->unk54.s0.winId = param_2;
    gUnknown_203B224->unk54.s0.unk38 = &gUnknown_203B224->unk54.s0.windows.id[param_2];
    RestoreSavedWindows(&gUnknown_203B224->unk54.s0.windows);
    gUnknown_203B224->unk54.s0.windows.id[gUnknown_203B224->unk54.s0.winId] = sUnknown_80DB95C;
    gUnknown_203B224->unk54.s0.unk38->header = &gUnknown_203B224->unk54.header;

    if (param_3 != NULL)
        gUnknown_203B224->unk54.s0.windows.id[gUnknown_203B224->unk54.s0.winId].pos = *param_3;

    sub_8012D08(gUnknown_203B224->unk54.s0.unk38, param_4);
    sub_8099690(1);
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B224->unk54.s0.windows, TRUE, TRUE);
    sub_8013818(&gUnknown_203B224->unk54.s0.input, GetNumberOfFilledInventorySlots(), param_4, param_2);
    gUnknown_203B224->unk54.s0.input.menuIndex = gUnknown_203B228;
    gUnknown_203B224->unk54.s0.input.unk1E = gUnknown_203B22A;
    sub_8013984(&gUnknown_203B224->unk54.s0.input);
    sub_801A998();
    sub_801A9E0();
    return TRUE;
}

// arm9.bin::02026954
u32 sub_801A6E8(bool8 param_1)
{
    s32 index;
    Item item;

    if (param_1 == FALSE) {
        sub_8013660(&gUnknown_203B224->unk54.s0.input);
        return 0;
    }

    switch (GetKeyPress(&gUnknown_203B224->unk54.s0.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            switch (gUnknown_203B224->unk0) {
                case 0:
                case 1:
                case 2:
                    if (gUnknown_203B224->unk4[sub_801A8AC()] != 0)
                        PlayMenuSoundEffect(2);
                    else
                        PlayMenuSoundEffect(0);
                    break;
                case 3:
                    if (sub_801AEA8() != 0 || sub_801ADA0(sub_801A8AC()))
                        PlayMenuSoundEffect(0);
                    else
                        PlayMenuSoundEffect(2);
                    break;
                case 4:
                    item = gTeamInventoryRef->teamItems[sub_801A8AC()];

                    if (CanSellItem(item.id) && GetStackSellPrice(&item) + gTeamInventoryRef->teamMoney <= MAX_TEAM_MONEY)
                        PlayMenuSoundEffect(0);
                    else
                        PlayMenuSoundEffect(2);
                    break;
                case 5:
                    PlayMenuSoundEffect(0);
                    break;
            }
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(4);
            return 4;
        case INPUT_L_BUTTON:
        case INPUT_R_BUTTON:
            if (gUnknown_203B224->unk0 != 3)
                goto _0801A87C;

            index = sub_801A8AC();
            if (gUnknown_203B224->unk4[index] != 0 || sub_801ADA0(index)) {
                PlayMenuSoundEffect(6);
                gUnknown_203B224->unk4[index] ^= 1;
                sub_80138B8(&gUnknown_203B224->unk54.s0.input, 0);
                sub_801A9E0();
                return 1;
            }

            PlayMenuSoundEffect(2);
            goto _0801A87C;
        case INPUT_SELECT_BUTTON:
            if (gUnknown_203B224->unk0 != 2) {
                PlayMenuSoundEffect(5);
                SortInventoryItems();
                sub_801A9E0();
            }
            // NOTE: fallthrough needed here
        default:
            _0801A87C:
            if (sub_80138B8(&gUnknown_203B224->unk54.s0.input, 1) != FALSE) {
                sub_801A998();
                sub_801A9E0();
                return 1;
            }
            else
                return 0;
            break;
    }
}

// arm9.bin::02026934
s32 sub_801A8AC(void)
{
    return (gUnknown_203B224->unk54.s0.input.unk1E * gUnknown_203B224->unk54.s0.input.unk1C) + gUnknown_203B224->unk54.s0.input.menuIndex;
}

// arm9.bin::020268C0
void sub_801A8D0(bool8 r0)
{
    sub_8099690(1);
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B224->unk54.s0.windows, FALSE, FALSE);
    FillInventoryGaps();
    gUnknown_203B224->unk54.s0.input.unk22 = GetNumberOfFilledInventorySlots();
    sub_8013984(&gUnknown_203B224->unk54.s0.input);
    sub_801A998();
    sub_801A9E0();
    if (r0)
        AddMenuCursorSprite(&gUnknown_203B224->unk54.s0.input);
}

// arm9.bin::02026818
void sub_801A928(void)
{
    if (gUnknown_203B224 != NULL) {
        gUnknown_203B228 = gUnknown_203B224->unk54.s0.input.menuIndex;
        gUnknown_203B22A = gUnknown_203B224->unk54.s0.input.unk1E;
        gUnknown_203B224->unk54.s0.windows.id[gUnknown_203B224->unk54.s0.winId] = sUnknown_80DB944;
        sub_8099690(0);
        ResetUnusedInputStruct();
        ShowWindows(&gUnknown_203B224->unk54.s0.windows, TRUE, TRUE);
        MemoryFree(gUnknown_203B224);
        gUnknown_203B224 = NULL;
    }
}

static void sub_801A998(void)
{
    gUnknown_203B224->unk54.header.count = gUnknown_203B224->unk54.s0.input.unk20;
    gUnknown_203B224->unk54.header.currId = gUnknown_203B224->unk54.s0.input.unk1E;
    gUnknown_203B224->unk54.header.width = 11;
    gUnknown_203B224->unk54.header.f3 = 0;
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B224->unk54.s0.windows, TRUE, TRUE);
}

// arm9.bin::020262DC
void sub_801A9E0(void)
{
    s32 teamItemIndex;
    s32 r7;
    s32 x;
    u8 buf1[80]; // sp4
    Item item; // spC8

    CallPrepareTextbox_8008C54(gUnknown_203B224->unk54.s0.winId);
    sub_80073B8(gUnknown_203B224->unk54.s0.winId);
    x = gUnknown_203B224->unk54.s0.input.unk1E * 8 + 10;

    if (gUnknown_203B224->unk54.s0.input.unk1E == 0)
        PrintStringOnWindow(x, 0, sTeamToolboxA, gUnknown_203B224->unk54.s0.winId, 0);
    else
        PrintStringOnWindow(x, 0, sTeamToolboxB, gUnknown_203B224->unk54.s0.winId, 0);

    for (r7 = 0; r7 < gUnknown_203B224->unk54.s0.input.unk1A; r7++) {
        teamItemIndex = (gUnknown_203B224->unk54.s0.input.unk1E * gUnknown_203B224->unk54.s0.input.unk1C) + r7;
        item = gTeamInventoryRef->teamItems[teamItemIndex];

        switch (gUnknown_203B224->unk0) {
            case 0: {
                sub_8090E14(buf1, &item, 0);
                PrintStringOnWindow(8, GetMenuEntryYCoord(&gUnknown_203B224->unk54.s0.input, r7), buf1, gUnknown_203B224->unk54.s0.winId, 0);
                break;
            }
            case 1:
            case 2: {
                struct unkStruct_8090F58 thing; // sp54

                thing.unk0 = 0;
                thing.unk4 = 0;
                thing.unk8 = 1;
                item.flags = 1;
                sub_8090E14(buf1, &item, &thing);

                PrintStringOnWindow(8, GetMenuEntryYCoord(&gUnknown_203B224->unk54.s0.input, r7), buf1, gUnknown_203B224->unk54.s0.winId, 0);
                break;
            }
            case 3: {
                struct unkStruct_8090F58 thing; // sp60

                thing.unk0 = 0;
                thing.unk4 = 0;
                thing.unk8 = 1;
                item.flags = 1;
                sub_8090E14(buf1, &item, &thing);

                if (gUnknown_203B224->unk4[teamItemIndex] != 0 || sub_801ADA0(teamItemIndex))
                    PrintStringOnWindow(8,GetMenuEntryYCoord(&gUnknown_203B224->unk54.s0.input,r7), buf1, gUnknown_203B224->unk54.s0.winId, 0);
                else {
                    strncpy(gFormatBuffer_Items[0], buf1, 80);
                    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&gUnknown_203B224->unk54.s0.input, r7), sFmtMoveItem0, gUnknown_203B224->unk54.s0.winId, 0);
                }
                break;
            }
            case 4: {
                struct unkStruct_8090F58 thing; // sp6C
                u8 buf2[80]; // sp78

                if (CanSellItem(item.id)) {
                    thing.unk0 = 3;
                    thing.unk4 = 0;
                    thing.unk6 = 88;
                    thing.unk8 = 1;
                    item.flags = 3;
                    sub_8090E14(buf1, &item, &thing);

                    if (GetStackSellPrice(&item) + gTeamInventoryRef->teamMoney > MAX_TEAM_MONEY) {
                        sprintfStatic(buf2, sFmtRed, buf1);
                        PrintStringOnWindow(8, GetMenuEntryYCoord(&gUnknown_203B224->unk54.s0.input, r7), buf2, gUnknown_203B224->unk54.s0.winId, 0);
                    }
                    else
                        PrintStringOnWindow(8, GetMenuEntryYCoord(&gUnknown_203B224->unk54.s0.input, r7), buf1, gUnknown_203B224->unk54.s0.winId, 0);
                }
                else {
                    sub_8090E14(buf1, &item, 0);
                    strncpy(gFormatBuffer_Items[0], buf1, 80);
                    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&gUnknown_203B224->unk54.s0.input, r7), sFmtMoveItem0, gUnknown_203B224->unk54.s0.winId, 0);
                }
                break;
            }
            case 5: {
                UNUSED struct unkStruct_8090F58 thingUnused; // sp6C
                struct unkStruct_8090F58 thing; // sp78

                thing.unk0 = 0;
                thing.unk4 = 0;
                thing.unk8 = 1;
                item.flags = 1;
                sub_8090E14(buf1, &item, &thing);

                if (IsGummiItem(item.id))
                    PrintStringOnWindow(8, GetMenuEntryYCoord(&gUnknown_203B224->unk54.s0.input, r7), buf1, gUnknown_203B224->unk54.s0.winId, 0);
                else {
                    strncpy(gFormatBuffer_Items[0], buf1, 80);
                    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&gUnknown_203B224->unk54.s0.input, r7), sFmtMoveItem0, gUnknown_203B224->unk54.s0.winId, 0);
                }
                break;
            }
        }

        if (sub_801AED0(teamItemIndex) & 1)
            sub_8007B7C(gUnknown_203B224->unk54.s0.winId, 8, GetMenuEntryYCoord(&gUnknown_203B224->unk54.s0.input, r7), (gUnknown_203B224->unk54.s0.unk38->width - 2) * 8, 10);
    }

    sub_80073E0(gUnknown_203B224->unk54.s0.winId);
}

// arm9.bin::02026234
void sub_801AD34(u32 param_1)
{
    CallPrepareTextbox_8008C54(param_1);
    sub_80073B8(param_1);
    PrintStringOnWindow(6, 0, sItems, param_1, 0);
    sub_8012BC4(18, 13, GetNumberOfFilledInventorySlots(), 2, 7, param_1);
    PrintStringOnWindow(22, 13, sSlash, param_1, 0);
    sub_8012BC4(43, 13, INVENTORY_SIZE, 2, 7, param_1);
    sub_80073E0(param_1);
}

bool8 sub_801ADA0(s32 param_1)
{
    u16 uVar2;
    u32 uVar2_32;

    u16 uVar3;
    u32 uVar3_32;
    s32 sum1;
    s32 sum2;
    Item item;

    item = gTeamInventoryRef->teamItems[param_1];
    if (!IsNotMoneyOrUsedTMItem(item.id))
        return FALSE;

    if (IsThrowableItem(item.id)) {
        uVar3_32 = sub_801AE24(item.id);
        sum1 = gTeamInventoryRef->teamStorage[item.id];
        uVar3 = uVar3_32;
        sum1 += uVar3;
        sum1 += (item.quantity);
        if (sum1 > 999)
            return FALSE;
    }
    else {
        uVar2_32 = sub_801AE24(item.id);
        sum2 = gTeamInventoryRef->teamStorage[item.id];
        uVar2 = uVar2_32;
        sum2 += uVar2;
        if (sum2 > 998)
            return FALSE;
    }
    return 1;
}

static s32 sub_801AE24(u32 itemID)
{
    Item item;
    u16 count;
    s32 invIndex;

    count = 0;
    for (invIndex = 0; invIndex < GetNumberOfFilledInventorySlots(); invIndex++) {
        if (gUnknown_203B224->unk4[invIndex] != 0) {
            item = gTeamInventoryRef->teamItems[invIndex];

            if (item.id == itemID) {
                if (IsThrowableItem(item.id))
                    count += item.quantity;
                else
                    count++;
            }
        }
    }
    return count;
}

void sub_801AE84(void)
{
    s32 index;

    for (index = 0; index < INVENTORY_SIZE; index++)
        gUnknown_203B224->unk4[index] = 0;
}

s32 sub_801AEA8(void)
{
    s32 index;
    s32 count;

    count = 0;
    for (index = 0; index < INVENTORY_SIZE; index++) {
        if (gUnknown_203B224->unk4[index] != 0)
            count++;
    }
    return count;
}

s32 sub_801AED0(s32 index)
{
    return gUnknown_203B224->unk4[index];
}

void sub_801AEE4(s32 index, s32 value)
{
    gUnknown_203B224->unk4[index] = value;
}

static void SortInventoryItems(void)
{
    Item *itemSlotR;
    u32 *itemIDR;
    u32 *base;
    s32 orderL;
    s32 orderR;
    u32 itemIDL;
    Item itemSlotL;
    s32 itemR;
    s32 itemL;

    for (itemL = 0; itemL < GetNumberOfFilledInventorySlots() - 1; itemL++) {
        for (itemR = itemL + 1; itemR < GetNumberOfFilledInventorySlots(); itemR++) {
            orderL = GetItemOrder(gTeamInventoryRef->teamItems[itemL].id);
            orderR = GetItemOrder(gTeamInventoryRef->teamItems[itemR].id);

            if (orderL > orderR
                         || (orderL == orderR && gTeamInventoryRef->teamItems[itemL].quantity < gTeamInventoryRef->teamItems[itemR].quantity)) {
                itemSlotL = gTeamInventoryRef->teamItems[itemL];
                itemSlotR = &gTeamInventoryRef->teamItems[itemR];
                gTeamInventoryRef->teamItems[itemL] = *itemSlotR;
                *itemSlotR = itemSlotL;

                base = gUnknown_203B224->unk4;
                itemIDL = gUnknown_203B224->unk4[itemL];
                itemIDR = &base[itemR];
                base[itemL] = *itemIDR;
                *itemIDR = itemIDL;
            }
        }
    }
}

UNUSED static unkStruct_203B224 *sub_801AF98(void)
{
    return gUnknown_203B224;
}
