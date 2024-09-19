#include "global.h"
#include "memory.h"
#include "debug.h"
#include "ground_map.h"
#include "ground_map_2.h"

extern u16 gUnknown_2026E4E;

IWRAM_DATA unkStruct_3001B74 *gUnknown_3001B74 = {0};
IWRAM_DATA unkStruct_3001B70 *gUnknown_3001B78 = {0};

extern const u8 gUnknown_8117784[];
extern const s16 gUnknown_811E5F4[][2];
extern const u8 gGroundWeatherSelect[];
extern const s32 gUnknown_81177BC[];

extern void sub_80A3BB0(unkStruct_3001B70 *, u32);
extern void SetScriptVarValue(u8, u8, u32);
extern void sub_80A2D00(unkStruct_3001B70 *);
extern void sub_80A2B40(unkStruct_3001B70 *, const u8 *);
extern void sub_80A2FBC(unkStruct_3001B70 *, u32);
extern void sub_80A49E8(unkStruct_3001B70 *);
extern void sub_80A456C(unkStruct_3001B70 *, u32, const s32 *);
extern void sub_80A4580(unkStruct_3001B70 *, u32, s32 *);
extern void sub_80A56C0(s32 *);
extern void sub_80A4764(unkStruct_3001B70 *);

static void sub_80A62D0(void);

void sub_80A5E70(void)
{
    if (gGroundMapDungeon_3001B70 != NULL)
        sub_80A49E8(gGroundMapDungeon_3001B70);

    sub_80A62D0();
}

void sub_80A5E8C(u8 param_1)
{
    gUnknown_3001B74 = MemoryAlloc(sizeof(unkStruct_3001B74), 6);
    gUnknown_3001B74->unk0 = -1;
    gUnknown_3001B74->unk2 = 0;
    sub_80A5EDC(param_1);
}

void sub_80A5EBC(void)
{
    sub_80A5EDC(0);
    MemoryFree(gUnknown_3001B74);
    gUnknown_3001B74 = NULL;
}

void sub_80A5EDC(u8 param_1)
{
    SetScriptVarValue(0, 27, -1);
    gUnknown_3001B74->unk0  = -1;
    gUnknown_3001B74->unk2 = param_1;

    if (gUnknown_3001B78 != NULL) {
        sub_80A2D00(gUnknown_3001B78);
        MemoryFree(gUnknown_3001B78);
        gUnknown_3001B78 = NULL;
    }

    if (param_1) {
        gUnknown_3001B78 = MemoryAlloc(sizeof(unkStruct_3001B70), 6);
        sub_80A2B40(gUnknown_3001B78, gUnknown_8117784);
        sub_80A2FBC(gUnknown_3001B78, -1);
    }
}

void nullsub_121(void)
{}

void nullsub_122(void)
{}

void GroundWeather_Select(s16 param_1)
{
    s32 iVar2;
    s32 iVar3;
    const s16 *pVar1;

    iVar2 = param_1;
    iVar3 = iVar2;
    Log(0, gGroundWeatherSelect, iVar2, gUnknown_3001B74->unk2);
    SetScriptVarValue(0, 27, iVar2);
    gUnknown_3001B74->unk0 = iVar2;

    if (gUnknown_3001B74->unk2 == 0)
        return;

    if (iVar2 == -1) {
        sub_80A2FBC(gUnknown_3001B78, -1);
        return;
    }

    pVar1 = gUnknown_811E5F4[iVar3];
    sub_80A2FBC(gUnknown_3001B78, pVar1[1]);

    gUnknown_3001B74->unk4 = 0;
    gUnknown_3001B74->unk8 = 0;
    gUnknown_3001B74->unkC = 0;
    gUnknown_3001B74->unk10 = 0;
    gUnknown_3001B74->unk20 = 0;
    gUnknown_3001B74->unk1C = 0;
    gUnknown_3001B74->unk18 = 0;
    gUnknown_3001B74->unk14 = 0;

    switch (gUnknown_3001B74->unk0) {
        case 9:
            sub_80A3BB0(gUnknown_3001B78, 1);
            gUnknown_2026E4E = 0x40c;
            break;
        case 7:
            gUnknown_2026E4E = 0x808;
            break;
        case 14:
            sub_80A3BB0(gUnknown_3001B78, 1);
            gUnknown_2026E4E = 0x1010;
            break;
        case 15:
            sub_80A3BB0(gUnknown_3001B78, 1);
            gUnknown_2026E4E = 0x40c;
            break;
        case 0:
        case 3:
        case 4:
        case 5:
        case 8:
            gUnknown_2026E4E = 0x1010;
            break;
        default:
            if (pVar1[0] == 1)
                sub_80A3BB0(gUnknown_3001B78, 1);

            gUnknown_2026E4E = 0x1000;
            break;
    }
}

UNUSED static s16 sub_80A60C4(void)
{
    return gUnknown_3001B74->unk0;
}

void nullsub_123(void)
{}

void sub_80A60D8(void)
{
    s32 r0;
#ifndef NONMATCHING
    register s32 r1 asm("r1");
#else
    s32 r1;
#endif
    s32 r3;
    s32 r4;

    s32 local_00[2]; // sp 0x0
    s32 local_08[2]; // sp 0x8
    s32 local_10[2]; // sp 0x10
    s32 local_18[2]; // sp 0x18
    s32 local_20[2]; // sp 0x20
    const s16 *puVar1;

    if (gUnknown_3001B74->unk2 == 0)
        return;

    switch ((s16)(gUnknown_3001B74->unk0 + 1)) {
        case 10:
            r1 = gUnknown_3001B74->unk4;
            r0 = r1 + 2;
            gUnknown_3001B74->unk4 = r0;

            r4 = gUnknown_3001B74->unk8;
            r3 = r4 + 1;
            gUnknown_3001B74->unk8 = r3;

            if (r0 < 0)
                r0 = r1 + 5;

            gUnknown_3001B74->unkC += (r0 >> 2);
            r1 = r3;
            if (r1 < 0)
                r1 = r4 + 4;

            gUnknown_3001B74->unk10 += (r1 >> 2);
            sub_80A4580(gUnknown_3001B78, 0, &gUnknown_3001B74->unkC);
            gUnknown_3001B74->unk4 &= 3;
            gUnknown_3001B74->unk8 &= 3;
            sub_80A56C0(local_00);
            local_00[0] -= gUnknown_3001B74->unkC;
            local_00[1] += gUnknown_3001B74->unk10;
            sub_80A4580(gUnknown_3001B78, 0, local_00);
            sub_80A456C(gUnknown_3001B78, 0, local_00);
            break;
        case 11:
        case 12:
        case 13:
        case 14:
            sub_80A56C0(local_08);
            sub_80A456C(gUnknown_3001B78,0,local_08);
            break;
        case 15:
            r1 = gUnknown_3001B74->unk4 ;
            r0 = r1 + 1;
            gUnknown_3001B74->unk4  = r0;

            if (r0 < 0)
                r0 = r1 + 4;

            gUnknown_3001B74->unkC += (r0 >> 2);
            sub_80A4580(gUnknown_3001B78, 0, &gUnknown_3001B74->unkC);
            gUnknown_3001B74->unk4 &= 3;
            sub_80A56C0(local_10);
            local_10[0] -= gUnknown_3001B74->unkC;
            local_10[1] = 0;
            sub_80A4580(gUnknown_3001B78, 0, local_10);
            sub_80A456C(gUnknown_3001B78, 0, local_10);
            break;
        case 16:
            r1 = gUnknown_3001B74->unk4;
            r0 = r1 + 2;
            gUnknown_3001B74->unk4 = r0;
            if (r0 < 0)
                r0 = r1 + 5;

            gUnknown_3001B74->unkC += (r0 >> 2);
            sub_80A4580(gUnknown_3001B78, 0, &gUnknown_3001B74->unkC);
            gUnknown_3001B74->unk4 &= 3;
            sub_80A56C0(local_18);
            local_18[0] -= gUnknown_3001B74->unkC;
            local_18[1] = 0;
            sub_80A4580(gUnknown_3001B78, 0, local_18);
            sub_80A456C(gUnknown_3001B78, 0, local_18);
            break;
        default:
            puVar1 = gUnknown_811E5F4[gUnknown_3001B74->unk0];
            if (puVar1[0] == 0) {
                sub_80A56C0(local_20);
                sub_80A456C(gUnknown_3001B78,0,local_20);
                break;
            }
            // NOTE: Fallthrough needed here..
        case 0:
            sub_80A456C(gUnknown_3001B78, 0, gUnknown_81177BC);
            break;
    }

    sub_80A4764(gUnknown_3001B78);
}

static void sub_80A62D0(void)
{
    if (gUnknown_3001B74->unk2 != 0)
        sub_80A49E8(gUnknown_3001B78);
}