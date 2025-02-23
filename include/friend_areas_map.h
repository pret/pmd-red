#ifndef GUARD_FRIEND_AREAS_MAP_H
#define GUARD_FRIEND_AREAS_MAP_H

#include "file_system.h"
#include "code_8004AA0.h"
#include "menu_input.h"
#include "structs/axdata.h"
#include "structs/str_position.h"
#include "constants/direction.h"

struct FriendAreaLocation
{
    const u8 *name;
    DungeonPos unk4;
    u8 unk8[8];
    s16 unk10[8];
};

struct UnkStruct_4018
{
    u8 unk4018;
    s16 unk2[8];
    axdata unk14;
};

// size: 0x4DD8
struct UnkBgStruct
{
    OpenedFile *unk0[5];
    u16 unk14[64][64];
    u16 unk2014[64][64];
    const struct FriendAreaLocation *locations;
    struct UnkStruct_4018 unk4018[32];
    s32 unk4A18;
    s32 unk4A1C;
    s32 unk4A20;
    s32 unk4A24;
    s32 unk4A28;
    u8 unk4A2C;
    axdata arrowSprites[NUM_DIRECTIONS];
    axdata monAxSprite;
    unkStruct_202EE8C unk4C4C[16];
    s32 brightness;
    u32 unk4DD0;
    DungeonPos bgPos;
    DungeonPos monSpritePos;
    s32 unk4DDC;
    s32 unk4DE0;
    s32 unk4DE4;
    s32 unk4DE8;
    u8 unk4DEC[8];
    u8 unk4DF4;
    s32 unk4DF8;
    MenuInputStruct menu;
};

extern struct UnkBgStruct *gUnknown_203B0E4;

void sub_80101F8(u8 *strBuffer, u8 index);
bool8 sub_800FFE8(u8 friendAreaId);

void FriendAreasMap_UpdateMonSpritePosition(void);
void FriendAreasMap_UpdateBg(void);
void FriendAreasMap_HideTextWindowAndArrows(void);
void FriendAreasMap_RunFrameActions(void);
void FriendAreasMap_ShowDirectionArrows(void);
void FriendAreasMap_PrintCurrAreaName(void);
void FriendAreasMap_PrintAvailableSubAreas(void);
void sub_8010EF0(void);
void sub_8010DA4(void);

#endif
