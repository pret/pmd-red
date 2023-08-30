#ifndef GUARD_BG_CONTROL_H
#define GUARD_BG_CONTROL_H

enum
{
    BG0,
    BG1,
    BG2,
    BG3,
    NUM_BGS
};

struct BGControlStruct
{
    u16 padding;
    u16 unk2;
    s16 hofs;
    s16 vofs;
};

extern struct BGControlStruct gBG0Control;
extern struct BGControlStruct gBG1Control;
extern struct BGControlStruct gBG2Control;
extern struct BGControlStruct gBG3Control;
extern u16 gBldAlpha;
extern u16 gBldCnt;
extern bool8 gUnknown_202D7FE;

void SetBG2RegOffsets(s32, s32);
void SetBG3RegOffsets(s32, s32);
void SetBGOBJEnableFlags(u32);
void SetBldAlphaReg(s32, s32);
void sub_800CD64(s32, bool8);

#endif // GUARD_BG_CONTROL_H