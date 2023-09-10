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
    /* 0x10 */ DungeonLocation dungeonLocation;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    u32 unk1C[14];
    u32 unk54[14];
    u32 unk8C[13];
    s32 unkC0;
};

extern struct unkStruct_203B494 *gUnknown_203B494;

const u8 *GetAdventureLogLine(u8 index);
DungeonLocation *GetDungeonLocationInfo(void);
s32 GetNumAdventures(void);
void ResetNumAdventures(void);

void sub_8097670(void);
struct unkStruct_203B494 *sub_8097680(void);
void sub_80976A8(void);
void sub_80976F8(u8);
bool8 sub_8097710(u8);
void sub_8097790(void);
s32 sub_80977B8(void);
void sub_80977D0(void);
s32 sub_80977F8(void);
s16 sub_8097838(void);
void sub_8097848(void);
s16 sub_8097870(void);
s16 sub_8097880(void);
s16 sub_80978B8(void);

#endif // GUARD_CODE_8097670_H