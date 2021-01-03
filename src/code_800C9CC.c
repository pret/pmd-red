#include "global.h"
#include "input.h"

struct BGControlStruct
{
    u16 padding;
    u16 unk2;
    s16 hofs;
    s16 vofs;
};

extern u16 gRawKeyInput;
extern u8 gUnknown_202D6B8;
extern u8 gUnknown_202D6B9;
extern u16 gUnknown_202D7FA;
extern u8 gUnknown_202D7FE;

extern struct BGControlStruct gUnknown_202D698;
extern struct BGControlStruct gUnknown_202D6A0;
extern struct BGControlStruct gUnknown_202D6A8;
extern struct BGControlStruct gUnknown_202D6B0;

void ReadKeyInput(struct Inputs *r0)
{
    u16 keyInput = REG_KEYINPUT ^ KEYS_MASK;
    r0->held = 0;

    if((keyInput & DPAD_UP) != 0)
        r0->held = DPAD_UP;

    if((keyInput & DPAD_DOWN) != 0)
        r0->held |= DPAD_DOWN;

    if((keyInput & DPAD_LEFT) != 0)
        r0->held |= DPAD_LEFT;

    if((keyInput & DPAD_RIGHT) != 0)
        r0->held |= DPAD_RIGHT;

    if((keyInput & A_BUTTON) != 0)
        r0->held |= A_BUTTON;

    if((keyInput & B_BUTTON) != 0)
        r0->held |= B_BUTTON;

    if((keyInput & START_BUTTON) != 0)
        r0->held |= START_BUTTON;

    if((keyInput & SELECT_BUTTON) != 0)
        r0->held |= SELECT_BUTTON;

    if((keyInput & R_BUTTON) != 0)
        r0->held |= R_BUTTON;

    if((keyInput & L_BUTTON) != 0)
        r0->held |= L_BUTTON;

    gRawKeyInput = keyInput;
}

void sub_800CC44(s32 r0, s32 r1)
{
    u32 preload1;
    u8 preload2;
    u8 preload3;

    if(r0 < 0)
    {
        r0 = 0;
    }
    else
    {
        if(r0 > 0x10)
        {
            r0 = 0x10;
        }
    }
    if(r1 < 0)
    {
        r1 = 0;
    }
    else
    {
        if(r1 > 0x10)
        {
            r1 = 0x10;
        }
    }
    gUnknown_202D6B8 = r0;
    gUnknown_202D6B9 = r1;

    // Forcing the correct loads
    preload1 = gUnknown_202D7FA;
    preload2 = gUnknown_202D6B8;
    preload3 = gUnknown_202D6B9;

    gUnknown_202D7FA = (gUnknown_202D6B9 << 8) | gUnknown_202D6B8;

}

void SetBG0RegOffsets(s32 xoffset, s32 yoffset)
{
    gUnknown_202D698.hofs = xoffset;
    gUnknown_202D698.vofs = yoffset;
}

void SetBG1RegOffsets(s32 xoffset, s32 yoffset)
{
    gUnknown_202D6A0.hofs = xoffset;
    gUnknown_202D6A0.vofs = yoffset;
}

void SetBG2RegOffsets(s32 xoffset, s32 yoffset)
{
    gUnknown_202D6A8.hofs = xoffset;
    gUnknown_202D6A8.vofs = yoffset;
}

void SetBG3RegOffsets(s32 xoffset, s32 yoffset)
{
    gUnknown_202D6B0.hofs = xoffset;
    gUnknown_202D6B0.vofs = yoffset;
}

void SetBGRegOffsets(s32 reg, u32 xoffset, s32 yoffset)
{
    if(reg == 1)
    {
        goto _0800CCD4;
    }
    if(reg <= 1)
    {
        goto _0800CCCA;
    }
    if(reg == 2)
    {
        goto _0800CCDE;
    }
    if(reg == 3)
    {
        goto _0800CCE8;
    }

    _0800CCCA:
        SetBG0RegOffsets(xoffset, yoffset);
        return;
    _0800CCD4:
        SetBG1RegOffsets(xoffset, yoffset);
        return;
    _0800CCDE:
        SetBG2RegOffsets(xoffset, yoffset);
        return;
    _0800CCE8:
        SetBG3RegOffsets(xoffset, yoffset);
}

void SetBGRegXOffset(s32 reg, s32 offset)
{
    if(reg == 1)
    {
        goto _0800CD10;
    }
    if(reg <= 1)
    {
        goto _0800CD06;
    }
    if(reg == 2)
    {
        goto _0800CD18;
    }
    if(reg == 3)
    {
        goto _0800CD20;
    }

    _0800CD06:
        gUnknown_202D698.hofs = offset;
        return;
    _0800CD10:
        gUnknown_202D6A0.hofs = offset;
        return;
    _0800CD18:
        gUnknown_202D6A8.hofs = offset;
        return;
    _0800CD20:
        gUnknown_202D6B0.hofs = offset;
}

void SetBGRegYOffset(s32 reg, s32 offset)
{
    if(reg == 1)
    {
        goto _0800CD48;
    }
    if(reg <= 1)
    {
        goto _0800CD3E;
    }
    if(reg == 2)
    {
        goto _0800CD50;
    }
    if(reg == 3)
    {
        goto _0800CD58;
    }

    _0800CD3E:
        gUnknown_202D698.vofs = offset;
        return;
    _0800CD48:
        gUnknown_202D6A0.vofs = offset;
        return;
    _0800CD50:
        gUnknown_202D6A8.vofs = offset;
        return;
    _0800CD58:
        gUnknown_202D6B0.vofs = offset;
}

void sub_800CD64(s32 r0, u8 r1)
{
    gUnknown_202D7FE = r1;
    gUnknown_202D6A8.unk2 = (1 << 15) & (u16)((-r0|r0) >> 31);
}
