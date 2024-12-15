#include "global.h"
#include "items.h"
#include "memory.h"
#include "game_options.h"
#include "event_flag.h"
#include "ground_main.h"
#include "code_80A26CC.h"

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

IWRAM_DATA struct unkStruct_3001B68 *gUnknown_3001B68 = {0};


struct unkStruct_20399E0
{
     u32 unk0;
     s32 unk4;
     u32 unk8;
};

extern struct unkStruct_20399E0 *gUnknown_20399E0;


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

void sub_809CB74(void) {
    MemoryFree(gUnknown_20399E0);
    gUnknown_20399E0 = NULL;
}


void sub_809CB8C(void) {
    ClearScriptVarArray(NULL, STATION_ITEM_TEMP);
    ClearScriptVarArray(NULL, DELIVER_ITEM_TEMP);
}

bool8 HasItemInInventory(u8 item)
{
    if(FindItemInInventory(item) >= 0)
        return TRUE;
    else
        return FALSE;
}
