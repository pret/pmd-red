#ifndef GUARD_CODE_80A26CC_H
#define GUARD_CODE_80A26CC_H

// size: 0x14
typedef struct DungeonInfo
{
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ s16 unk8;
    /* 0xA */ s16 unkA;
    /* 0xC */ u8 dungeonIndex;
    /* 0xD */ u8 unkD;
    /* 0xE */ s16 unkE;
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
} DungeonInfo;

void sub_80A2500(s32, s16 *);
void sub_80A252C(s32, s16 *);
void sub_80A2558(s32, s16 *);
void sub_80A2584(s16, s16);
void sub_80A2598(s16, s16);
u32 sub_80A25AC(u16);
const DungeonInfo *GetDungeonInfo_80A2608(s32 index);
const DungeonInfo *sub_80A2620(s16 index);
s16 sub_80A2654(s16 index);
s16 sub_80A2668(u32);
s16 sub_80A2688(u8);
s16 sub_80A26B8(s16);
s16 sub_80A26CC(s16);
u8 sub_80A270C(s16 index);
u8 sub_80A2728(s16 index);
u8 sub_80A2740(s32 index);
s16 sub_80A2750(s16);
bool8 sub_80A27CC(s16);
bool8 sub_80A2824(u8 index);
bool8 sub_80A28F0(u8 index);
s32 sub_80A29B0(u8 *);
const u8 *sub_80A2B18(s16);

#endif // GUARD_CODE_80A26CC_H
