#ifndef GUARD_FRIEND_AREAS_MAP_H
#define GUARD_FRIEND_AREAS_MAP_H

#include "file_system.h"
#include "code_8004AA0.h"
#include "menu_input.h"
#include "structs/axdata.h"
#include "structs/str_position.h"
#include "constants/direction.h"

#define MAX_AREAS_PER_LOCATION 8

struct FriendAreaLocationInfo
{
    const u8 *name;
    DungeonPos pos;
    u8 areasIds[MAX_AREAS_PER_LOCATION];
    s16 adjacentLocations[NUM_DIRECTIONS];
};

struct MapLocation
{
    bool8 isShown;
    s16 locationsByDirection[NUM_DIRECTIONS];
    axdata sprite;
};

#define NUM_FRIEND_AREA_LOCATIONS 32

// size: 0x4DD8
struct FriendAreasMap
{
    OpenedFile *unk0[5];
    u16 unk14[64][64];
    u16 unk2014[64][64];
    const struct FriendAreaLocationInfo *locationsInfo;
    struct MapLocation mapLocations[NUM_FRIEND_AREA_LOCATIONS];
    s32 currLocationId;
    s32 unk4A1C;
    s32 locationIdOnBPress;
    s32 teamBaseLocationId;
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
    u8 displayedAreas[MAX_AREAS_PER_LOCATION];
    u8 chosenFriendAreaId;
    s32 unk4DF8;
    MenuInputStruct menu;
};

extern struct FriendAreasMap *gFriendAreasMapPtr;

struct struct_unk800F990
{
    u32 unk0;
    u8 startingFriendAreaId;
    u8 unk5;
    struct FriendAreasMap *unk8;
    u8 unkC;
};

void ShowFriendAreasMap(struct struct_unk800F990 *param_1);
void PrintFriendAreaNameInMap(u8 *strBuffer, u8 index);
bool8 IsFriendAreaShownOnMap(u8 friendAreaId);

void FriendAreasMap_UpdateMonSpritePosition(void);
void FriendAreasMap_UpdateBg(void);
void FriendAreasMap_HideTextWindowAndArrows(void);
void FriendAreasMap_RunFrameActions(void);
void FriendAreasMap_ShowDirectionArrows(void);
void FriendAreasMap_PrintCurrAreaName(void);
void FriendAreasMap_PrintAvailableSubAreas(void);
void FriendAreasMap_CloseFiles(void);
void FriendAreasMap_InitGfx(void);

#endif
