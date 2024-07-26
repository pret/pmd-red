#include "global.h"
#include "globaldata.h"
#include "code_80118A4.h"
#include "code_801C8C4.h"
#include "input.h"
#include "items.h"
#include "memory.h"
#include "menu_input.h"
#include "text1.h"
#include "text2.h"

static EWRAM_DATA_2 struct unkStruct_203B244 *sUnknown_203B244 = {0};
static EWRAM_DATA_2 u32 sUnknown_203B248 = {0};
static EWRAM_DATA_2 u16 sUnknown_203B24C = {0};
static EWRAM_DATA_2 u16 sUnknown_203B24E = {0};

#include "data/code_801C8C4.h"

static void sub_801CC38(void);
static u32 sub_801CE58(void);

bool8 sub_801C8C4(s32 a0, s32 a1, UnkTextStruct2_sub *a2, u32 a3)
{
    if (sub_801CF14(a0))
        return FALSE;

    if (sUnknown_203B244 == NULL)
        sUnknown_203B244 = MemoryAlloc(sizeof(struct unkStruct_203B244), 8);

    sUnknown_203B244->unk0 = a0;
    sub_801CF94();
    sUnknown_203B244->unk4E8 = a1;
    sUnknown_203B244->unk4EC = &sUnknown_203B244->unk4F0[a1];
    sub_8006518(sUnknown_203B244->unk4F0);
    sUnknown_203B244->unk4F0[sUnknown_203B244->unk4E8] = sUnknown_80DBE54;
    sUnknown_203B244->unk4EC->unk14 = &sUnknown_203B244->unk550;

    if (a2 != NULL)
        sUnknown_203B244->unk4F0[sUnknown_203B244->unk4E8].unk8 = *a2;

    sub_8012D08(sUnknown_203B244->unk4EC, a3);
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B244->unk4F0, TRUE, TRUE);
    sub_8013818(&sUnknown_203B244->input, sub_801CE58(), a3, a1);

    if (sUnknown_203B248 == sUnknown_203B244->unk0) {
        sUnknown_203B244->input.menuIndex = sUnknown_203B24C;
        sUnknown_203B244->input.unk1E = sUnknown_203B24E;
        sub_8013984(&sUnknown_203B244->input);
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
        sub_8013660(&sUnknown_203B244->input);
        return 0;
    }

    switch (GetKeyPress(&sUnknown_203B244->input)) {
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
                sub_80138B8(&sUnknown_203B244->input,0);
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
            if (sub_80138B8(&sUnknown_203B244->input, 1)) {
                sub_801CC38();
                sub_801CCD8();
                return 1;
            }
            return 0;
    }
}

u8 sub_801CB24(void)
{
    return sUnknown_203B244->itemIDs[(sUnknown_203B244->input.unk1E * sUnknown_203B244->input.unk1C) + sUnknown_203B244->input.menuIndex];
}

void sub_801CB5C(bool8 a0)
{
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B244->unk4F0, FALSE, FALSE);
    sUnknown_203B244->input.unk22 = sub_801CE58();
    sub_8013984(&sUnknown_203B244->input);
    sub_801CC38();
    sub_801CCD8();

    if (a0)
        AddMenuCursorSprite(&sUnknown_203B244->input);
}

void sub_801CBB8(void)
{
    if (sUnknown_203B244 != NULL) {
        sUnknown_203B248 = sUnknown_203B244->unk0;
        sUnknown_203B24C = sUnknown_203B244->input.menuIndex;
        sUnknown_203B24E = sUnknown_203B244->input.unk1E;
        sUnknown_203B244->unk4F0[sUnknown_203B244->unk4E8] = sUnknown_80DBE3C;
        ResetUnusedInputStruct();
        sub_800641C(sUnknown_203B244->unk4F0, TRUE, TRUE);
        MemoryFree(sUnknown_203B244);
        sUnknown_203B244 = NULL;
    }
}

NAKED
static void sub_801CC38(void)
{
    asm_unified(
    "\tpush {r4,r5,lr}\n"
    "\tldr r4, _0801CCC4\n"
    "\tldr r0, [r4]\n"
    "\tmovs r1, 0xAA\n"
    "\tlsls r1, 3\n"
    "\tadds r0, r1\n"
    "\tmovs r2, 0\n"
    "\tmovs r1, 0x1\n"
    "\tstrb r1, [r0]\n"
    "\tldr r0, [r4]\n"
    "\tldr r1, _0801CCC8\n"
    "\tadds r0, r1\n"
    "\tstrb r2, [r0]\n"
    "\tldr r0, [r4]\n"
    "\tadds r1, 0x1\n"
    "\tadds r0, r1\n"
    "\tmovs r1, 0xC\n"
    "\tstrb r1, [r0]\n"
    "\tldr r0, [r4]\n"
    "\tldr r1, _0801CCCC\n"
    "\tadds r0, r1\n"
    "\tstrb r2, [r0]\n"
    "\tldr r0, [r4]\n"
    "\tldr r2, _0801CCD0\n"
    "\tadds r0, r2\n"
    "\tmovs r1, 0\n"
    "\tldrsh r0, [r0, r1]\n"
    "\tmovs r1, 0xC\n"
    "\tbl sub_80095E4\n"
    "\tadds r0, 0x2\n"
    "\tlsls r0, 16\n"
    "\tldr r3, [r4]\n"
    "\tmovs r2, 0x9D\n"
    "\tlsls r2, 3\n"
    "\tadds r5, r3, r2\n"
    "\tldr r2, [r5]\n"
    "\tlsls r1, r2, 1\n"
    "\tadds r1, r2\n"
    "\tlsls r1, 3\n"
    "\tadds r1, r3, r1\n"
    "\tldr r2, _0801CCD4\n"
    "\tadds r1, r2\n"
    "\tasrs r2, r0, 16\n"
    "\tlsrs r0, 16\n"
    "\tstrh r0, [r1]\n"
    "\tldr r1, [r5]\n"
    "\tlsls r0, r1, 1\n"
    "\tadds r0, r1\n"
    "\tlsls r0, 3\n"
    "\tadds r3, r0\n"
    "\tadds r2, 0x2\n"
    "\tmovs r0, 0xA0\n"
    "\tlsls r0, 3\n"
    "\tadds r3, r0\n"
    "\tstrh r2, [r3]\n"
    "\tbl ResetUnusedInputStruct\n"
    "\tldr r0, [r4]\n"
    "\tmovs r1, 0x9E\n"
    "\tlsls r1, 3\n"
    "\tadds r0, r1\n"
    "\tmovs r1, 0x1\n"
    "\tmovs r2, 0x1\n"
    "\tbl sub_800641C\n"
    "\tpop {r4,r5}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
"_0801CCC4: .4byte sUnknown_203B244\n"
"_0801CCC8: .4byte 0x00000551\n"
"_0801CCCC: .4byte 0x00000553\n"
"_0801CCD0: .4byte 0x000004ce\n"
"_0801CCD4: .4byte 0x000004fe");
}

void sub_801CCD8(void)
{
    u32 y;
    u32 y2;
    u32 itemID;
    s32 index;
    u8 buffer[80];

    sub_8008C54(sUnknown_203B244->unk4E8);
    sub_80073B8(sUnknown_203B244->unk4E8);
    PrintStringOnWindow(10, 0, sStorage, sUnknown_203B244->unk4E8, 0);
    sub_8012BC4(sUnknown_203B244->unk550.f2 * 8 + 4, 0, sUnknown_203B244->input.unk1E + 1, 2, 7, sUnknown_203B244->unk4E8);

    for(index = 0; index < sUnknown_203B244->input.unk1A; index++) {
        itemID = sUnknown_203B244->itemIDs[(sUnknown_203B244->input.unk1E * sUnknown_203B244->input.unk1C) + index];
        BufferItemName(buffer, itemID, NULL);
        y = sub_8013800(&sUnknown_203B244->input, index);
        PrintStringOnWindow(8, y, buffer, sUnknown_203B244->unk4E8, 0);
        y2 = sub_8013800(&sUnknown_203B244->input, index);
        sub_8012BC4((sUnknown_203B244->unk4EC->unkC * 8) - 2, y2, gTeamInventoryRef->teamStorage[itemID], 3, 5, sUnknown_203B244->unk4E8);

        if (sub_801CFE0(itemID) & 1)
            sub_8007B7C(sUnknown_203B244->unk4E8, 8, sub_8013800(&sUnknown_203B244->input, index), (sUnknown_203B244->unk4EC->unkC - 1) * '\b', 10); // TODO: Ghidra being crazy
    }

    sub_80073E0(sUnknown_203B244->unk4E8);
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
