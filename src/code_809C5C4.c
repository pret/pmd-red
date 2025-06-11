#include "global.h"
#include "items.h"
#include "memory.h"
#include "game_options.h"
#include "event_flag.h"
#include "ground_main.h"
#include "code_80A26CC.h"
#include "code_800D090.h"
#include "code_80118A4.h"
#include "string_format.h"
#include "input.h"
#include "ground_lives.h"

struct unkStruct_3001B68
{
     u32 unk0;
     u32 unk4;
     u16 unk8;
     u16 unkA;
     u8  unkC;
     u8  unkD;
     u8  unkE;
     u32 unk10;
     s16 unk14;
     s16 unk16;
     u8  unk18;
     u8  unk19;
     u32 unk1C;
     u8  unk20;
};

IWRAM_INIT struct unkStruct_3001B68 *gUnknown_3001B68 = {NULL};


struct unkStruct_20399E0
{
     u32 unk0;
     s32 unk4;
     u32 unk8;
};

EWRAM_DATA struct unkStruct_20399E0 *gUnknown_20399E0 = {0};


void sub_809C63C();
u8 sub_809C740(void);
void nullsub_107();
void nullsub_108();
void nullsub_109();
void nullsub_110();
void nullsub_111();
void nullsub_112();
void nullsub_113();
void nullsub_114();
void nullsub_115();
void nullsub_116();

extern const char gUnknown_8116390[];
extern const char gUnknown_811636C[];
extern const char gUnknown_811633C[];

EWRAM_INIT const char *gUnknown_203B4A0[3] = {gUnknown_8116390, gUnknown_811636C, gUnknown_811633C};

void sub_809C5C4(void)
{
    gUnknown_3001B68 = MemoryAlloc(sizeof(struct unkStruct_3001B68), 6);
    gUnknown_3001B68->unk0 = 0;
    gUnknown_3001B68->unk4 = 0;
    gUnknown_3001B68->unk8 = 0;
    gUnknown_3001B68->unkA = 0;
    gUnknown_3001B68->unkD = 0;
    gUnknown_3001B68->unkE = 0;
    gUnknown_3001B68->unk10 = 0;
    gUnknown_3001B68->unk14 = 0xffff;
    gUnknown_3001B68->unk16 = 0x23;
    gUnknown_3001B68->unk18 = 0;
    gUnknown_3001B68->unk19 = 0x3f;
    gUnknown_3001B68->unk1C = 0;
    gUnknown_3001B68->unk20 = 0;
    nullsub_107();
    sub_809C63C();
}

void sub_809C618(void)
{
    sub_809C63C();
    nullsub_107();
    nullsub_108();
    MemoryFree(gUnknown_3001B68);
    gUnknown_3001B68 = NULL;
}

void sub_809C63C(void)
{
    nullsub_108();
    gUnknown_3001B68->unk1C = 0;
    gUnknown_3001B68->unk20 = 0;
}

void sub_809C658(void)
{
    switch(gUnknown_3001B68->unkA) {
        case 3:
            nullsub_111();
            nullsub_112();
            nullsub_113();
            break;
        case 4:
            nullsub_114();
            nullsub_115();
            nullsub_116();
            break;
        case 2:
            nullsub_109();
            nullsub_110();
            break;
        case 5:
            nullsub_107();
            nullsub_108();
            break;
        case 0:
        case 1:
            nullsub_107();
            nullsub_108();
            break;
    }
}

void sub_809C6CC(u16 param_1)
{
    if(gUnknown_3001B68->unk8 != param_1)
    {
        gUnknown_3001B68->unk8 = param_1;
        gUnknown_3001B68->unkE = 0;
    }
}

void sub_809C6EC(void)
{
    if (sub_8098F88() == 0) {
        if (gGameOptionsRef->unkC == 0) {
            sub_809C6CC(4);
        }
        else {
            sub_809C6CC(3);
        }
    }
    else {
        sub_809C6CC(5);
    }
}

u16 sub_809C724(void)
{
    return gUnknown_3001B68->unk8;
}

u8 sub_809C730(void)
{
   return sub_809C740();
}

u8 sub_809C740(void)
{
  if(gUnknown_3001B68->unk0 == 0)
        return 1;
  else
        return 0;
}

// Called in a number of places, like when the player changes the team leader in sub_80278B4().
void nullsub_104(void)
{ }

void sub_809C760(void)
{
    gUnknown_3001B68->unkE = 1;
}

void sub_809C770(s16 param_1, s16 param_2)
{
    u8 uVar2;
    u8 uVar3;
    s32 iVar5;
    u32 uVar6;

    s32 param_1_s32;
    s32 param_2_s32;

    param_1_s32 = param_1;
    param_2_s32 = param_2;

    if (gUnknown_3001B68->unkE != 0) {
        gUnknown_3001B68->unkE = 0;
        return;
    }
    if (gUnknown_3001B68->unk8 == 0) {
        sub_809C6EC();
    }
    uVar2 = gUnknown_3001B68->unk18;
    uVar3 = gUnknown_3001B68->unk19;
    switch(param_2_s32) {
        case 9:
            uVar2 = sub_8002658(param_1_s32);
            if (uVar2 == 0) {
                return;
            }
            uVar6 = 1;
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 10:
        case 0xb:
            uVar6 = 1;
            uVar2 = 0;
            break;
        case 0x23:
            switch((s16)(param_1_s32)) {
                case 0xA4:
                case 0xA5:
                case 0xA8:
                case 0xA9:
                case 0xAA:
                case 0xAE:
                case 0xAF:
                case 0xB0:
                case 0xB1:
                    uVar6 = 0;
                    break;
                default:
                    return;
            }
            break;
        case 0x24:
        case 0x25:
        case 0x26:
            uVar6 = 0;
            break;
        default:
            switch((s16)(param_2_s32 - 0xc)) {
                case 1:
                    iVar5 = 0;
                    break;
                case 6:
                case 7:
                    iVar5 = 7;
                    break;
                case 8:
                case 9:
                    iVar5 = 9;
                    break;
                case 10:
                    iVar5 = 10;
                    break;
                case 0xc:
                case 0xd:
                    iVar5 = 0xb;
                    break;
                case 0xe:
                case 0xf:
                    iVar5 = 0xd;
                    break;
                case 0x10:
                case 0x11:
                    iVar5 = 0xf;
                    break;
                case 0x12:
                case 0x13:
                    iVar5 = 0x11;
                    break;
                case 0x14:
                case 0x15:
                    iVar5 = 0x13;
                    break;
                case 0x16:
                    iVar5 = 0x20;
                    break;
                case 0:
                default:
                    iVar5 = (s16)GetScriptVarValue(NULL,DUNGEON_ENTER);
                    break;

            }
            if (iVar5 == -1) {
                return;
            }
            uVar3 = sub_80A2740(iVar5);
            uVar6 = 2;
            break;
    }
    if (gUnknown_3001B68->unk10 != uVar6) {
        gUnknown_3001B68->unk0 = 2;
        gUnknown_3001B68->unkC = 1;
        gUnknown_3001B68->unk20 = 1;
    }
    else
    {
        if (uVar6 == 1) {
            if ((uVar2 != gUnknown_3001B68->unk18) ||
                (gUnknown_3001B68->unk14 != param_1_s32)) {
                gUnknown_3001B68->unkC = 1;
                gUnknown_3001B68->unk20 = 1;
            }
            else {
                if ((uVar2 == 0) && (gUnknown_3001B68->unk16 != param_2_s32)) {
                    gUnknown_3001B68->unkC = 1;
                }
            }
        }
        else if ((uVar6 == 2) &&
            ((uVar3 != gUnknown_3001B68->unk19 || (gUnknown_3001B68->unk16 != param_2_s32))))
        {
            gUnknown_3001B68->unkC = 1;
            gUnknown_3001B68->unk20 = 1;
        }
    }
    if (gUnknown_3001B68->unkC != 0) {
        gUnknown_3001B68->unk10 = uVar6;
        gUnknown_3001B68->unk14 = param_1_s32;
        gUnknown_3001B68->unk16 = param_2_s32;
        gUnknown_3001B68->unk18 = uVar2;
        gUnknown_3001B68->unk19 = uVar3;
        if (gUnknown_3001B68->unk8 != 4) {
            gUnknown_3001B68->unkC = 0;
            gUnknown_3001B68->unk20 = 0;
        }
    }
}

void nullsub_105(void) {}

void sub_809CA20(void)
{
    u16 *puVar1;

    if (gUnknown_3001B68->unk0 != 0) {
        gUnknown_3001B68->unk0 = 0;
        gUnknown_3001B68->unk4 = 0x1f;
        gUnknown_3001B68->unkC = 1;
    }
    if (gUnknown_3001B68->unkC != 0) {
        puVar1 = &gUnknown_3001B68->unk8;
        gUnknown_3001B68->unkA = *puVar1;
        if ((*puVar1 == 4) && (gUnknown_3001B68->unk10 == 0)) {
            gUnknown_3001B68->unkA = 2;
            gUnknown_3001B68->unk1C = 0;
            gUnknown_3001B68->unk20 = 0;
        }
        switch(gUnknown_3001B68->unkA) {
            case 3:
                nullsub_111();
                nullsub_113();
                nullsub_112();
                gUnknown_3001B68->unkD = 1;
                break;
            case 4:
                nullsub_114();
                nullsub_115();
                nullsub_116();
                break;
            case 2:
                nullsub_109();
                nullsub_110();
                break;
            case 5:
                nullsub_107();
                nullsub_108();
                break;
            case 0:
            case 1:
                nullsub_107();
                nullsub_108();
                break;
        }
        gUnknown_3001B68->unkC = 0;

    }
    else {
        switch(gUnknown_3001B68->unkA) {
            case 3:
                nullsub_113();
                break;
            case 4:
                nullsub_116();
            case 0:
            case 1:
            case 2:
            case 5:
                break;
        }
    }
}


void nullsub_106(void) {}
void nullsub_107(void) {}
void nullsub_108(void) {}
void nullsub_109(void) {}
void nullsub_110(void) {}
void nullsub_111(void) {}
void nullsub_112(void) {}
void nullsub_113(void) {}
void nullsub_114(void) {}
void nullsub_115(void) {}
void nullsub_116(void) {}

void sub_809CB50(void)
{
    gUnknown_20399E0 = MemoryAlloc(sizeof(struct unkStruct_20399E0), 6);
    gUnknown_20399E0->unk4 = -1;
    gUnknown_20399E0->unk8 = 0;
}

void sub_809CB74(void)
{
    MemoryFree(gUnknown_20399E0);
    gUnknown_20399E0 = NULL;
}


void sub_809CB8C(void)
{
    ClearScriptVarArray(NULL, STATION_ITEM_TEMP);
    ClearScriptVarArray(NULL, DELIVER_ITEM_TEMP);
}

bool8 HasItemInInventory(u8 item)
{
    if (FindItemInInventory(item) >= 0)
        return TRUE;
    else
        return FALSE;
}

extern bool8 ScriptPrintText(s32 a0, s32 a1_, const char *text);
extern bool8 sub_809124C(u8 id, u8 param_3);
extern u8 IsTextboxOpen_809A750(void);
extern u8 sub_809CFE8(u32);
extern bool8 sub_809B260(s32 *a0);
extern void GroundMap_ExecuteEvent(s32, s32);
extern void GroundScriptLockJumpZero(s32 index);

extern const u8 gUnknown_81163E4[];

struct ItemWithQuantity
{
    u8 id;
    s16 quantity;
};

static bool8 sub_809CBBC(const struct ItemWithQuantity *itemToAdd, const u8 *maxMoneyStr, const u8 *noItemSpaceStr, const u8 *itemGivenStr)
{
    char buffer[80];

    if (itemToAdd->id == ITEM_POKE) {
        int newMoneyAmount;
        sprintfStatic(buffer,gUnknown_81163E4,itemToAdd->quantity,gItemParametersData[ITEM_POKE].name);
        newMoneyAmount = gTeamInventoryRef->teamMoney + itemToAdd->quantity;
        if (newMoneyAmount > MAX_TEAM_MONEY) {
            if (maxMoneyStr != 0) {
                ScriptPrintText(0, -1, maxMoneyStr);
            }
            return FALSE;
        }

        gTeamInventoryRef->teamMoney = newMoneyAmount;
    }
    else {
        Item item = {0};
        item.quantity = itemToAdd->quantity;
        item.id = itemToAdd->id;

        sub_8090E14(buffer,&item,0);
        if (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE) {
            if (noItemSpaceStr != 0) {
                ScriptPrintText(0, -1, noItemSpaceStr);
            }
            return FALSE;
        }

        sub_809124C(item.id,0);
        FillInventoryGaps();
    }

    if (itemGivenStr != 0) {
        strcpy(gFormatBuffer_Items[0], buffer);
        ScriptPrintText(0, -1, itemGivenStr);
        PlaySoundWithVolume(0xcb,0x100);
    }

    return TRUE;
}

extern const struct ItemWithQuantity gUnknown_81163BC[];

s32 sub_809CC90(s32 tableId)
{
    const struct ItemWithQuantity *item = &gUnknown_81163BC[tableId];
    if (item->id == ITEM_POKE) {
        if (gTeamInventoryRef->teamMoney + item->quantity > MAX_TEAM_MONEY)
            return 2;
    }
    else {
        if (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)
            return 2;
    }
    return 1;
}

extern const u8 gUnknown_81163F0[];
extern const u8 gUnknown_811642C[];

s32 sub_809CCDC(u32 tableId, s32 a1)
{
    s32 strId;
    const struct ItemWithQuantity *item = &gUnknown_81163BC[tableId];
    gUnknown_20399E0->unk4 = -1;
    gUnknown_20399E0->unk8 = 0;

    if (a1 > 99) {
        strId = 2;
    }
    else if (a1 > 1) {
        strId = 1;
    }
    else {
        strId = 0;
    }

    if (sub_809CBBC(item, gUnknown_81163F0, gUnknown_811642C, gUnknown_203B4A0[strId])) {
        gUnknown_20399E0->unk4 = tableId;
        gUnknown_20399E0->unk8 = a1;
        return 1;
    }
    else {
        return 2;
    }
}

s32 sub_809CD48(void)
{
    if (IsTextboxOpen_809A750()) {
        return 0;
    }
    return 3;
}

void nullsub_117(void) {}
void nullsub_118(void) {}

void sub_809CD68(struct Struct3001B84_sub120 *dst)
{
    dst->unk0 = 0;
    dst->unk4 = 0;
    dst->unk10 = -1;
    dst->unk14 = 0;
    dst->unk8 = 0;
    dst->unk18 = 0;
}

void sub_809CD7C(struct Struct3001B84_sub120 *dst)
{
    dst->unk0 = 0;
    dst->unk10 = -1;
    dst->unk14 = 0;
    dst->unk8 = 0;
}

void sub_809CD8C(struct Struct3001B84_sub120 *dst, s32 a1)
{
    if (a1 == 5) {
        sub_809CD68(dst);
        dst->unk0 = a1;
    }
    else if (dst->unk4 != a1) {
        dst->unk4 = a1;
        dst->unk10 = -1;
        dst->unk14 = 0;
    }
}

s32 sub_809CDB8(struct Struct3001B84_sub120 *dst)
{
    s32 ret = dst->unk4;
    if (ret == 0) {
        ret = dst->unk0;
    }
    return ret;
}

u32 sub_809CDC8(struct Struct3001B84_sub120 *strPtr, u32 *r6, s8 *r7, s32 *param_4, u32 param_5, u32 param_6)
{
    u32 sp_4;
    s32 sp;
    s32 r8;

    param_4[0] = -1;

    switch (strPtr->unk0) {
        case 1:
            if (param_6 & 0x2000) {
                sub_809CD68(strPtr);
                strPtr->unk0 = 2;
            }
            break;
        case 2:
            if (!(param_6 & 0x2000)) {
                sub_809CD68(strPtr);
                strPtr->unk0 = 1;
            }
            break;
    }

    r8 = strPtr->unk4;
    if (r8 == 0)
        r8 = strPtr->unk0;

    switch (r8) {
        case 1:
        {
            u16 held = gRealInputs.held;
            u16 pressed = gRealInputs.pressed;
            if (held & DPAD_ANY) {
                if (held & B_BUTTON) {
                    strPtr->unk10 = 0;
                }
                else {
                    strPtr->unk10 = -1;
                }
            }
            else if (pressed & B_BUTTON) {
                 strPtr->unk10 = 0x14;
            }
            else if (strPtr->unk10 > 1) {
                 strPtr->unk10--;
                 if (!(held & B_BUTTON)) {
                     *r6 = 0x13;
                     *r7 = -1;
                     return 5;
                 }
            }
            else {
                strPtr->unk10 = -1;
            }

            if (pressed & A_BUTTON) {
                *r6 = 10;
            }
            else if (strPtr->unk10 == 0) {
                *r6 = 8;
            }
            else {
                *r6 = 7;
            }

            *r7 = sub_809CFE8(held);
            return strPtr->unk0;
        }
        case 5:
            if (sub_809B260(&sp)) {
                if (gGameOptionsRef->unkC == 0)
                    sub_809C6CC(4);
                else
                    sub_809C6CC(3);

                nullsub_104();
                sub_809CD7C(strPtr);
                strPtr->unk0 = 1;

                switch (sp) {
                    case 3:
                        strPtr->unk0 = 4;
                        *r6 = 1;
                        *r7 = -1;
                        return 4;
                    case 2:
                        strPtr->unk0 = 4;
                        sub_8098D80(0x1E);
                        *r6 = 1;
                        *r7 = -1;
                        return strPtr->unk0;
                    case 1:
                        strPtr->unk0 = 4;
                        *r6 = 1;
                        *r7 = -1;
                        return 4;
                    case 4:
                        strPtr->unk0 = 4;
                        GroundMap_ExecuteEvent(0x45, 0);
                        *r6 = 1;
                        *r7 = -1;
                        return strPtr->unk0;
                }
                GroundScriptLockJumpZero(2);
            }
            break;
        case 6:
        case 7:
             if (sub_809B260(&sp_4)) {
                sub_809CD7C(strPtr);
                strPtr->unk0 = 1;
                return strPtr->unk0;
             }
             break;
        case 2:
            {
                if (strPtr->unk8 >= 1) {
                    strPtr->unk8--;
                    *r6 = 9;
                    *r7 = strPtr->unkC;
                }
                else {
                    s32 v;
                    u16 held = gRealInputs.held;
                    *r6 = 9;
                    if (held & 0x40) {
                        *r7 = 4;
                    }
                    else if (held & 0x80) {
                        *r7 = 0;
                    }
                    else {
                        *r7 = -1;
                    }

                    // TODO: Fix me, this should be a simple -1 comparision, but agbcc doesn't want to cooperate...
                    v = strPtr->unkC = *r7;
                    if (CMP_S8_NOT_MINUS1(v)) {
                        strPtr->unk8 = 0x20;
                    }
                }
            }
            return r8;
    }

    *r6 = 0;
    *r7 = -1;
    return r8;
}
