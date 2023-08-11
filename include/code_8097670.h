#ifndef GUARD_CODE_8097670_H
#define GUARD_CODE_8097670_H

#include "dungeon_global_data.h"

// size: 0xC4
struct unkStruct_203B494
{
    u32 unk0; // 32 bit bitfield, I think
    /* 0x4 */ s32 numAdventures;
    s32 unk8;
    s32 unkC;
    /* 0x10 */ struct DungeonLocation dungeonLocation;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    u32 unk1C[14];
    u32 unk54[14];
    u32 unk8C[13];
    s32 unkC0;
};

void sub_80976F8(u8);

#endif // GUARD_CODE_8097670_H