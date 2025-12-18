#include "global.h"
#include "globaldata.h"
#include "ground_weather.h"
#include "code_800558C.h"
#include "debug.h"
#include "event_flag.h"
#include "ground_bg.h"
#include "ground_map.h"
#include "memory.h"

typedef struct unkStruct_3001B74
{
    s16 unk0;
    u8 unk2;
    s32 unk4;
    s32 unk8;
    PixelPos unkC;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
} unkStruct_3001B74;

IWRAM_INIT unkStruct_3001B74 *gUnknown_3001B74 = {NULL};
IWRAM_INIT GroundBg *gUnknown_3001B78 = {NULL};

extern const s16 gUnknown_811E5F4[][2];

static const SubStruct_52C gUnknown_8117784 = {
    .unk0 = 13,
    .unk2 = 1,
    .unk4 = 0x380,
    .unk6 = 0x80,
    .unk8 = 0x80,
    .unkA = 0,
    .numLayers = 1,
    .unkE = 0xbc,
    .unk10 = 0x5e,
    .unk12 = 0,
    .unk14 = NULL,
};

void sub_80A5E8C(bool8 param_1)
{
    gUnknown_3001B74 = MemoryAlloc(sizeof(unkStruct_3001B74), MEMALLOC_GROUP_6);
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

void sub_80A5EDC(bool8 param_1)
{
    SetScriptVarValue(NULL, WEATHER_KIND, -1);
    gUnknown_3001B74->unk0  = -1;
    gUnknown_3001B74->unk2 = param_1;

    if (gUnknown_3001B78 != NULL) {
        GroundBg_FreeAll(gUnknown_3001B78);
        FREE_AND_SET_NULL(gUnknown_3001B78);
    }

    if (param_1) {
        gUnknown_3001B78 = MemoryAlloc(sizeof(GroundBg), MEMALLOC_GROUP_6);
        GroundBg_Init(gUnknown_3001B78, &gUnknown_8117784);
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
    Log(0, "GroundWeather Select %3d %3d", iVar2, gUnknown_3001B74->unk2);
    SetScriptVarValue(NULL, WEATHER_KIND, iVar2);
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
    gUnknown_3001B74->unkC.x = 0;
    gUnknown_3001B74->unkC.y = 0;
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
    if (gUnknown_3001B74->unk2 == 0)
        return;

    switch ((s16)(gUnknown_3001B74->unk0 + 1)) {
        case 10: {
            PixelPos pixPos;

            gUnknown_3001B74->unk4 += 2;
            gUnknown_3001B74->unk8 += 1;
            gUnknown_3001B74->unkC.x += gUnknown_3001B74->unk4 / 4;
            gUnknown_3001B74->unkC.y += gUnknown_3001B74->unk8 / 4;
            sub_80A4580(gUnknown_3001B78, 0, &gUnknown_3001B74->unkC);
            gUnknown_3001B74->unk4 &= 3;
            gUnknown_3001B74->unk8 &= 3;
            sub_80A56C0(&pixPos);
            pixPos.x -= gUnknown_3001B74->unkC.x;
            pixPos.y += gUnknown_3001B74->unkC.y;
            sub_80A4580(gUnknown_3001B78, 0, &pixPos);
            SetCameraPositionForLayer(gUnknown_3001B78, 0, &pixPos);
            break;
        }
        case 11:
        case 12:
        case 13:
        case 14: {
            PixelPos pixPos;

            sub_80A56C0(&pixPos);
            SetCameraPositionForLayer(gUnknown_3001B78,0,&pixPos);
            break;
        }
        case 15: {
            PixelPos pixPos;

            gUnknown_3001B74->unk4++;
            gUnknown_3001B74->unkC.x += gUnknown_3001B74->unk4 / 4;
            sub_80A4580(gUnknown_3001B78, 0, &gUnknown_3001B74->unkC);
            gUnknown_3001B74->unk4 &= 3;
            sub_80A56C0(&pixPos);
            pixPos.x -= gUnknown_3001B74->unkC.x;
            pixPos.y = 0;
            sub_80A4580(gUnknown_3001B78, 0, &pixPos);
            SetCameraPositionForLayer(gUnknown_3001B78, 0, &pixPos);
            break;
        }
        case 16: {
            PixelPos pixPos;

            gUnknown_3001B74->unk4 += 2;
            gUnknown_3001B74->unkC.x += gUnknown_3001B74->unk4 / 4;
            sub_80A4580(gUnknown_3001B78, 0, &gUnknown_3001B74->unkC);
            gUnknown_3001B74->unk4 &= 3;
            sub_80A56C0(&pixPos);
            pixPos.x -= gUnknown_3001B74->unkC.x;
            pixPos.y = 0;
            sub_80A4580(gUnknown_3001B78, 0, &pixPos);
            SetCameraPositionForLayer(gUnknown_3001B78, 0, &pixPos);
            break;
        }
        default: {
            PixelPos pixPos;
            const s16 *puVar1 = gUnknown_811E5F4[gUnknown_3001B74->unk0];
            if (puVar1[0] == 0) {
                sub_80A56C0(&pixPos);
                SetCameraPositionForLayer(gUnknown_3001B78,0,&pixPos);
                break;
            }
        }
        // NOTE: Fallthrough needed here.
        case 0: {
            static const PixelPos pixPos = {0, 0};

            SetCameraPositionForLayer(gUnknown_3001B78, 0, &pixPos);
            break;
        }
    }

    sub_80A4764(gUnknown_3001B78);
}

void sub_80A62D0(void)
{
    if (gUnknown_3001B74->unk2 != 0)
        sub_80A49E8(gUnknown_3001B78);
}
