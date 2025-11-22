#ifndef GUARD_RUN_DUNGEON_H
#define GUARD_RUN_DUNGEON_H

#include "structs/str_dungeon_setup.h"
#include "structs/str_dungeon.h"

struct UnkStruct_203B414
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC[16];
    s32 unk4C[16];
    struct DungeonPos unk8C[16];
};

extern struct UnkStruct_203B414 *gUnknown_203B414;
extern Dungeon *gDungeon;

void RunDungeon_Async(DungeonSetupStruct *setupPtr);
bool8 sub_8043CE4(s32 dungeonId);
u8 GetFloorType(void);
void sub_8043D50(s32 *a0, s32 *a1);
void sub_8043D60(void);
bool8 TryForcedLoss_Async(bool8 a0);
void EnforceMaxItemsAndMoney(void);
bool8 IsFloorwideFixedRoom(void);
bool8 IsCurrentFixedRoomBossFight(void);
bool8 IsMakuhitaTrainingMaze(void);

#endif
