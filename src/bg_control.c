#include "global.h"
#include "bg_control.h"

EWRAM_DATA BGControlStruct gBG0Control = {0};
EWRAM_DATA BGControlStruct gBG1Control = {0};
EWRAM_DATA BGControlStruct gBG2Control = {0};
EWRAM_DATA BGControlStruct gBG3Control = {0};
static EWRAM_DATA u8 sBldAlpha_CoeffA = {0};
static EWRAM_DATA u8 sBldAlpha_CoeffB = {0};
EWRAM_DATA u16 gBldAlpha;
EWRAM_DATA u16 gBldCnt;
EWRAM_DATA bool8 gUnknown_202D7FE;

void SetBldAlphaReg(s32 lowAlpha, s32 highAlpha)
{
    if (lowAlpha < 0)
        lowAlpha = 0;
    else if (lowAlpha > 16)
        lowAlpha = 16;

    if (highAlpha < 0)
        highAlpha = 0;
    else if (highAlpha > 16)
        highAlpha = 16;

    sBldAlpha_CoeffA = lowAlpha;
    sBldAlpha_CoeffB = highAlpha;

    gBldAlpha = BLDALPHA_BLEND1(sBldAlpha_CoeffA, sBldAlpha_CoeffB);
}

static void SetBG0RegOffsets(s32 xoffset, s32 yoffset)
{
    gBG0Control.hofs = xoffset;
    gBG0Control.vofs = yoffset;
}

static void SetBG1RegOffsets(s32 xoffset, s32 yoffset)
{
    gBG1Control.hofs = xoffset;
    gBG1Control.vofs = yoffset;
}

void SetBG2RegOffsets(s32 xoffset, s32 yoffset)
{
    gBG2Control.hofs = xoffset;
    gBG2Control.vofs = yoffset;
}

void SetBG3RegOffsets(s32 xoffset, s32 yoffset)
{
    gBG3Control.hofs = xoffset;
    gBG3Control.vofs = yoffset;
}

UNUSED static void SetBGRegOffsets(s32 reg, u32 xoffset, s32 yoffset)
{
    switch (reg) {
        default:
        case 0: return SetBG0RegOffsets(xoffset, yoffset);
        case 1: return SetBG1RegOffsets(xoffset, yoffset);
        case 2: return SetBG2RegOffsets(xoffset, yoffset);
        case 3: return SetBG3RegOffsets(xoffset, yoffset);
    }
}

UNUSED static void SetBGRegXOffset(s32 reg, s32 offset)
{
    switch (reg) {
        default:
        case 0:
            gBG0Control.hofs = offset;
            break;
        case 1:
            gBG1Control.hofs = offset;
            break;
        case 2:
            gBG2Control.hofs = offset;
            break;
        case 3:
            gBG3Control.hofs = offset;
            break;
    }
}

UNUSED static void SetBGRegYOffset(s32 reg, s32 offset)
{
    switch (reg) {
        default:
        case 0:
            gBG0Control.vofs = offset;
            break;
        case 1:
            gBG1Control.vofs = offset;
            break;
        case 2:
            gBG2Control.vofs = offset;
            break;
        case 3:
            gBG3Control.vofs = offset;
            break;
    }
}

void sub_800CD64(s32 r0, bool8 r1)
{
    gUnknown_202D7FE = r1;
    gBG2Control.unk2 = r0 ? 0x8000 : 0;
}

void SetBGOBJEnableFlags(u32 mask)
{
    REG_DISPCNT = (REG_DISPCNT & 0xE0FF) | (~(mask << 8) & (DISPCNT_BG_ALL_ON | DISPCNT_OBJ_ON));
}
