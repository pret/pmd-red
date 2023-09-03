#ifndef GUARD_CODE_80972F4_H
#define GUARD_CODE_80972F4_H

// size: 0x8
struct MissionText
{
    /* 0x0 */ u8 *text;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
};

const u8 *GetCurrentMissionText(s16);

const u8 *sub_80975DC(u32);

// These two are definitely bool8 but can't get them to match with it yet
//bool8 sub_8097384(s16);
//bool8 sub_80973F4(s16);

#endif // GUARD_CODE_80972F4_H