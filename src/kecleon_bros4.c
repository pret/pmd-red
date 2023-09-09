#include "global.h"
#include "code_800D090.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "code_8098BDC.h"
#include "constants/input.h"
#include "items.h"
#include "kecleon_bros4.h"
#include "memory.h"
#include "menu_input.h"
#include "text1.h"
#include "text2.h"

extern u8 gUnknown_202DE58[];

static EWRAM_DATA_2 unkStruct_203B224 *gUnknown_203B224 = {0};
static EWRAM_DATA_2 u16 gUnknown_203B228 = {0};
static EWRAM_DATA_2 u16 gUnknown_203B22A = {0};

#include "data/kecleon_bros4.h"

static void SortInventoryItems(void);

static void sub_801A998(void);
static s32 sub_801AE24(u32);

bool8 sub_801A5D8(u32 param_1, s32 param_2, UnkTextStruct2_sub *param_3, u32 param_4)
{
    if (GetNumberOfFilledInventorySlots() == 0)
        return FALSE;

    if (gUnknown_203B224 == NULL)
        gUnknown_203B224 = MemoryAlloc(sizeof(unkStruct_203B224), 8);

    gUnknown_203B224->unk0 = param_1;
    FillInventoryGaps();
    sub_801AE84();
    gUnknown_203B224->unk88 = param_2;
    gUnknown_203B224->unk8C = &gUnknown_203B224->unk90[param_2];
    sub_8006518(gUnknown_203B224->unk90);
    gUnknown_203B224->unk90[gUnknown_203B224->unk88] = sUnknown_80DB95C;
    gUnknown_203B224->unk8C->unk14 = gUnknown_203B224->unkF0;

    if (param_3 != NULL)
        gUnknown_203B224->unk90[gUnknown_203B224->unk88].unk8 = *param_3;

    sub_8012D08(gUnknown_203B224->unk8C, param_4);
    sub_8099690(1);
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B224->unk90, TRUE, TRUE);
    sub_8013818(&gUnknown_203B224->input, GetNumberOfFilledInventorySlots(), param_4, param_2);
    gUnknown_203B224->input.menuIndex = gUnknown_203B228;
    gUnknown_203B224->input.unk1E = gUnknown_203B22A;
    sub_8013984(&gUnknown_203B224->input);
    sub_801A998();
    sub_801A9E0();
    return TRUE;
}

u32 sub_801A6E8(bool8 param_1)
{
    s32 index;
    Item item;

    if (param_1 == FALSE) {
        sub_8013660(&gUnknown_203B224->input);
        return 0;
    }

    switch (GetKeyPress(&gUnknown_203B224->input)) {
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
                sub_80138B8(&gUnknown_203B224->input, 0);
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
            if (sub_80138B8(&gUnknown_203B224->input, 1) != FALSE) {
                sub_801A998();
                sub_801A9E0();
                return 1;
            }
            else
                return 0;
            break;
    }
}

s32 sub_801A8AC(void)
{
    return (gUnknown_203B224->input.unk1E * gUnknown_203B224->input.unk1C) + gUnknown_203B224->input.menuIndex;
}

void sub_801A8D0(bool8 r0)
{
    sub_8099690(1);
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B224->unk90, FALSE, FALSE);
    FillInventoryGaps();
    gUnknown_203B224->input.unk22 = GetNumberOfFilledInventorySlots();
    sub_8013984(&gUnknown_203B224->input);
    sub_801A998();
    sub_801A9E0();
    if (r0)
        AddMenuCursorSprite(&gUnknown_203B224->input);
}

void sub_801A928(void)
{
    if (gUnknown_203B224 != NULL) {
        gUnknown_203B228 = gUnknown_203B224->input.menuIndex;
        gUnknown_203B22A = gUnknown_203B224->input.unk1E;
        gUnknown_203B224->unk90[gUnknown_203B224->unk88] = sUnknown_80DB944;
        sub_8099690(0);
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B224->unk90, TRUE, TRUE);
        MemoryFree(gUnknown_203B224);
        gUnknown_203B224 = NULL;
    }
}

static void sub_801A998(void)
{
    gUnknown_203B224->unkF0[0] = gUnknown_203B224->input.unk20;
    gUnknown_203B224->unkF0[1] = gUnknown_203B224->input.unk1E;
    gUnknown_203B224->unkF0[2] = 11;
    gUnknown_203B224->unkF0[3] = 0;
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B224->unk90, TRUE, TRUE);
}

void sub_801A9E0(void)
{
    s32 teamItemIndex;
    s32 r7;
    s32 x;
    u8 buf1[80]; // sp4
    Item item; // spC8

    sub_8008C54(gUnknown_203B224->unk88);
    sub_80073B8(gUnknown_203B224->unk88);
    x = gUnknown_203B224->input.unk1E * 8 + 10;

    if (gUnknown_203B224->input.unk1E == 0)
        xxx_call_draw_string(x, 0, sTeamToolboxA, gUnknown_203B224->unk88, 0);
    else
        xxx_call_draw_string(x, 0, sTeamToolboxB, gUnknown_203B224->unk88, 0);

    for (r7 = 0; r7 < gUnknown_203B224->input.unk1A; r7++) {
        teamItemIndex = (gUnknown_203B224->input.unk1E * gUnknown_203B224->input.unk1C) + r7;
        item = gTeamInventoryRef->teamItems[teamItemIndex];

        switch (gUnknown_203B224->unk0) {
            case 0: {
                sub_8090E14(buf1, &item, 0);
                xxx_call_draw_string(8, sub_8013800(&gUnknown_203B224->input, r7), buf1, gUnknown_203B224->unk88, 0);
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

                xxx_call_draw_string(8, sub_8013800(&gUnknown_203B224->input, r7), buf1, gUnknown_203B224->unk88, 0);
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
                    xxx_call_draw_string(8,sub_8013800(&gUnknown_203B224->input,r7), buf1, gUnknown_203B224->unk88, 0);
                else {
                    strncpy(gUnknown_202DE58, buf1, 80);
                    xxx_format_and_draw(8, sub_8013800(&gUnknown_203B224->input, r7), sFmtMoveItem0, gUnknown_203B224->unk88, 0);
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
                        xxx_call_draw_string(8, sub_8013800(&gUnknown_203B224->input, r7), buf2, gUnknown_203B224->unk88, 0);
                    }
                    else
                        xxx_call_draw_string(8, sub_8013800(&gUnknown_203B224->input, r7), buf1, gUnknown_203B224->unk88, 0);
                }
                else {
                    sub_8090E14(buf1, &item, 0);
                    strncpy(gUnknown_202DE58, buf1, 80);
                    xxx_format_and_draw(8, sub_8013800(&gUnknown_203B224->input, r7), sFmtMoveItem0, gUnknown_203B224->unk88, 0);
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
                    xxx_call_draw_string(8, sub_8013800(&gUnknown_203B224->input, r7), buf1, gUnknown_203B224->unk88, 0);
                else {
                    strncpy(gUnknown_202DE58, buf1, 80);
                    xxx_format_and_draw(8, sub_8013800(&gUnknown_203B224->input, r7), sFmtMoveItem0, gUnknown_203B224->unk88, 0);
                }
                break;
            }
        }

        if (sub_801AED0(teamItemIndex) & 1)
            sub_8007B7C(gUnknown_203B224->unk88, 8, sub_8013800(&gUnknown_203B224->input, r7), (gUnknown_203B224->unk8C->unkC - 2) * 8, 10);
    }

    sub_80073E0(gUnknown_203B224->unk88);
}

void sub_801AD34(u32 param_1)
{ 
    sub_8008C54(param_1);
    sub_80073B8(param_1);
    xxx_call_draw_string(6, 0, sItems, param_1, 0);
    sub_8012BC4(18, 13, GetNumberOfFilledInventorySlots(), 2, 7, param_1);
    xxx_call_draw_string(22, 13, sSlash, param_1, 0);
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