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

enum FriendAreaLocations
{
    LOCATION_MOUNTAIN_RANGE,
    LOCATION_GLACIER,
    LOCATION_PLAINS,
    LOCATION_SOUTH_PLAINS,
    LOCATION_BADLANDS,
    LOCATION_EASTERN_FOREST,
    LOCATION_WESTERN_FOREST,
    LOCATION_RIVER,
    LOCATION_EASTERN_PONDS,
    LOCATION_POND,
    LOCATION_NORTHERN_LAKES,
    LOCATION_EASTERN_LAKES,
    LOCATION_MARSH,
    LOCATION_CAVE,
    LOCATION_JUNGLE,
    LOCATION_RUINS,
    LOCATION_VOLCANO,
    LOCATION_DESERT,
    LOCATION_RELICS,
    LOCATION_SKY,
    LOCATION_NORTHERN_ISLES,
    LOCATION_SOUTHERN_ISLES,
    LOCATION_SOUTHWEST_ISLES,
    LOCATION_WESTERN_ISLES,
    LOCATION_NORTHERN_SEA,
    LOCATION_SOUTHERN_SEA,
    LOCATION_BEACH,
    LOCATION_TEAM_BASE,
    LOCATION_UNUSED_28,
    LOCATION_UNUSED_29,
    LOCATION_UNUSED_30,
    LOCATION_UNUSED_31,
    NUM_FRIEND_AREA_LOCATIONS
};

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
    struct FriendAreasMap *friendAreasMapPtr;
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
