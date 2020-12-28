#include "global.h"
#include "input.h"

struct unkStruct_809CC88
{
    u16 padding;
    u16 unk2;
    u16 unk4;
    u16 unk6;
};

extern u16 gRawKeyInput;
extern u8 gUnknown_202D6B8;
extern u8 gUnknown_202D6B9;
extern u16 gUnknown_202D7FA;

extern struct unkStruct_809CC88 gUnknown_202D698;
extern struct unkStruct_809CC88 gUnknown_202D6A0;
extern struct unkStruct_809CC88 gUnknown_202D6A8;
extern struct unkStruct_809CC88 gUnknown_202D6B0;

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

void sub_800CC88(u32 r0, u32 r1)
{
    gUnknown_202D698.unk4 = r0;
    gUnknown_202D698.unk6 = r1;
}

void sub_800CC94(u32 r0, u32 r1)
{
    gUnknown_202D6A0.unk4 = r0;
    gUnknown_202D6A0.unk6 = r1;
}

void sub_800CCA0(u32 r0, u32 r1)
{
    gUnknown_202D6A8.unk4 = r0;
    gUnknown_202D6A8.unk6 = r1;
}

void sub_800CCAC(u32 r0, u32 r1)
{
    gUnknown_202D6B0.unk4 = r0;
    gUnknown_202D6B0.unk6 = r1;
}

void sub_800CCB8(s32 r0, u32 r1, u32 r2)
{
    if(r0 == 1)
    {
        goto _0800CCD4;
    }
    if(r0 <= 1)
    {
        goto _0800CCCA;
    }
    if(r0 == 2)
    {
        goto _0800CCDE;
    }
    if(r0 == 3)
    {
        goto _0800CCE8;
    }
   
    _0800CCCA:
        sub_800CC88(r1, r2);
        return;
    _0800CCD4:
        sub_800CC94(r1, r2);
        return;
    _0800CCDE:
        sub_800CCA0(r1, r2);
        return;
    _0800CCE8:
        sub_800CCAC(r1, r2);
}

void sub_800CCF4(s32 r0, u32 r1)
{
    if(r0 == 1)
    {
        goto _0800CD10;
    }
    if(r0 <= 1)
    {
        goto _0800CD06;
    }
    if(r0 == 2)
    {
        goto _0800CD18;
    }
    if(r0 == 3)
    {
        goto _0800CD20;
    }

    _0800CD06:
        gUnknown_202D698.unk4 = r1;
        return;
    _0800CD10:
        gUnknown_202D6A0.unk4 = r1;
        return;
    _0800CD18:
        gUnknown_202D6A8.unk4 = r1;
        return;
    _0800CD20:
        gUnknown_202D6B0.unk4 = r1;
}

void sub_800CD2C(s32 r0, u32 r1)
{
    if(r0 == 1)
    {
        goto _0800CD48;
    }
    if(r0 <= 1)
    {
        goto _0800CD3E;
    }
    if(r0 == 2)
    {
        goto _0800CD50;
    }
    if(r0 == 3)
    {
        goto _0800CD58;
    }

    _0800CD3E:
        gUnknown_202D698.unk6 = r1;
        return;
    _0800CD48:
        gUnknown_202D6A0.unk6 = r1;
        return;
    _0800CD50:
        gUnknown_202D6A8.unk6 = r1;
        return;
    _0800CD58:
        gUnknown_202D6B0.unk6 = r1;
}
