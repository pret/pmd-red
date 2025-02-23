#include "global.h"
#include "globaldata.h"
#include "friend_areas_map.h"
#include "sprite.h"
#include "code_8004AA0.h"
#include "input.h"
#include "text.h"
#include "code_8009804.h"
#include "bg_palette_buffer.h"
#include "string_format.h"
#include "code_800D090.h"
#include "friend_area.h"
#include "bg_control.h"
#include "code_800558C.h"
#include "code_80118A4.h"
#include "code_800C9CC.h"
#include "pokemon.h"
#include "decompress.h"
#include "constants/friend_area.h"

extern u32 sub_809034C(u8 dungeonIndex, s32 speciesId_, u8 *buffer, bool32 param_4_, bool32 param_5_);
extern void sub_801178C(void);
extern void sub_80117C4(void);
extern void PlayCancelSoundEffect(void);
extern void PlayAcceptSoundEffect(void);
extern void PlayCursorUpDownSoundEffect(void);
extern s32 sprintf(char *, const char *, ...);
extern void sub_800CB20(void);
extern void xxx_call_update_bg_sound_input(void);
extern void CopyDungeonName1toBuffer(u8 *buffer, DungeonLocation *dungeonLocation);
extern s32 Atan2_4096(PixelPos *a);
extern void sub_80117AC(void);
extern void sub_8011760(void);

EWRAM_INIT struct FriendAreasMap *gFriendAreasMapPtr = NULL;
EWRAM_DATA static u8 sCurrDirection = 0;
EWRAM_DATA static u8 sHeldDpadCounter = 0;

extern const FileArchive gTitleMenuFileArchive;
extern const FileArchive gMonsterFileArchive;

static void MoveToNewLocation(s32 a0, s32 a1, s32 count);
static u8 GetChosenDirection(void);
static s32 ChooseLocation(s32 *a0, s32 *newDirection);
static bool8 ChooseAreaInLocation(void);
static void FadeFromFriendAreasMap(void);
static void InitMapLocations(u8 startingFriendAreaId);

extern u16 gUnknown_2026E4E;

#define NO_AREA NUM_FRIEND_AREAS + 5

 // ななし means without name
#define DUMMY_LOCATION \
{                       \
     .name = _("ななし"), \
     .pos = {0, 0}, \
     .areasIds = {NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA, NO_AREA}, \
     .adjacentLocations = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF}, \
}

static const struct FriendAreaLocationInfo gFriendAreaLocations[64] =
{
    {
        .name = "Mountain Range",
        .pos = {0x1C5, 0x71},
        .areasIds = {8, 9, 0xA, 0x27, 0x2F, 0xB, 0x3F, 0x3F},
        .adjacentLocations = {5, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xC, 2, 7},
    },
    {
        .name = "Glacier",
        .pos = {0x1CD, 0x1C},
        .areasIds = {0x30, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F},
        .adjacentLocations = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xA, 0xC},
    },
    {
         .name = "Plains",
         .pos = {0x161, 0x78},
         .areasIds = {0xD, 0xE, 0x11, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F},
         .adjacentLocations = {0x1B, 7, 0, 0xC, 0xD, 0xFFFF, 9, 0xFFFF},
    },
    {
         .name = "South Plains",
         .pos = {0x162, 0x12D},
         .areasIds = {0xF, 0xC, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F},
         .adjacentLocations = {0xFFFF, 0xFFFF, 0xFFFF, 4, 0xE, 0x12, 0xFFFF, 0xFFFF},
    },
    {
         .name = "Badlands",
         .pos = {0x194, 0x102},
         .areasIds = {0x34, 0x35, 0x28, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F},
         .adjacentLocations = {0xFFFF, 0x11, 0xFFFF, 0xB, 8, 0xFFFF, 0xE, 3},
    },
    {
         .name = "Eastern Forest",
         .pos = {0x1C7, 0x9D},
         .areasIds = {0x12, 0x13, 0x14, 0x15, 0x3F, 0x3F, 0x3F, 0x3F},
         .adjacentLocations = {0xB, 0xFFFF, 0xFFFF, 0xFFFF, 0, 0xFFFF, 7, 8},
    },
    {
         .name = "Western Forest",
         .pos = {0x108, 0x9D},
         .areasIds = {0x16, 0x17, 0x18, 0x19, 0x3F, 0x3F, 0x3F, 0x3F},
         .adjacentLocations = {0x10, 0xFFFF, 0x1B, 9, 0x14, 0x1A, 0xFFFF, 0xFFFF},
    },
    {
         .name = "River",
         .pos = {0x197, 0xA0},
         .areasIds = {0x1A, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F},
         .adjacentLocations = {8, 0xB, 5, 0, 0xC, 2, 0x1B, 0xFFFF},
    },
    {
         .name = "Eastern Ponds",
         .pos = {0x198, 0xCF},
         .areasIds = {0x1B, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F},
         .adjacentLocations = {4, 0xFFFF, 0xB, 5, 7, 0x1B, 0xFFFF, 0xE},
    },
    {
         .name = "Pond",
         .pos = {0x133, 0x79},
         .areasIds = {0x1C, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F},
         .adjacentLocations = {0xFFFF, 0x1B, 2, 0xD, 0xF, 0x14, 0xFFFF, 6},
    },
    {
         .name = "Northern Lakes",
         .pos = {0x182, 0x1D},
         .areasIds = {0x1D, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F},
         .adjacentLocations = {0xFFFF, 0xC, 1, 0xFFFF, 0xFFFF, 0xFFFF, 0xF, 0xD},
    },
    {
         .name = "Eastern Lakes",
         .pos = {0x1C6, 0xD0},
         .areasIds = {0x1E, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F},
         .adjacentLocations = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 5, 7, 8, 4},
    },
    {
         .name = "Marsh",
         .pos = {0x1A2, 0x46},
         .areasIds = {0x1F, 0x20, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F},
         .adjacentLocations = {7, 0, 0xFFFF, 1, 0xFFFF, 0xA, 0xD, 2},
    },
    {
         .name = "Cave",
         .pos = {0x160, 0x47},
         .areasIds = {0x21, 0x23, 0x24, 0x22, 0x3F, 0x3F, 0x3F, 0x3F},
         .adjacentLocations = {2, 0xFFFF, 0xC, 0xA, 0xFFFF, 0xF, 0x14, 9},
    },
    {
         .name = "Jungle",
         .pos = {0x163, 0x104},
         .areasIds = {0x25, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F},
         .adjacentLocations = {3, 0xFFFF, 4, 8, 0x1B, 0xFFFF, 0x12, 0xFFFF},
    },
    {
         .name = "Ruins",
         .pos = {0x136, 0x1C},
         .areasIds = {0x26, 0x29, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F},
         .adjacentLocations = {9, 0xD, 0xA, 0xFFFF, 0xFFFF, 0xFFFF, 0x18, 0x14},
    },
    {
         .name = "Volcano",
         .pos = {0x107, 0xCB},
         .areasIds = {0x10, 0x2A, 0x32, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F},
         .adjacentLocations = {0xFFFF, 0x12, 0xFFFF, 0x1B, 6, 0xFFFF, 0xFFFF, 0x19},
    },
    {
         .name = "Desert",
         .pos = {0x1C4, 0x12D},
         .areasIds = {0x2B, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F},
         .adjacentLocations = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 4, 0xFFFF, 0xFFFF},
    },
    {
         .name = "Relics",
         .pos = {0x131, 0x105},
         .areasIds = {0x2E, 0x2C, 0x2D, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F},
         .adjacentLocations = {0xFFFF, 3, 0xE, 0xFFFF, 0xFFFF, 0x10, 0x19, 0xFFFF},
    },
    {
        .name = "Sky",
        .pos = {0x2F, 0x15},
        .areasIds = {0x33, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F},
        .adjacentLocations = {0x17, 0x1A, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
    },
    {
     .name = "Northern Isles",
     .pos = {0x107, 0x47},
     .areasIds = {0x36, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F},
     .adjacentLocations = {6, 9, 0xD, 0xF, 0xFFFF, 0x18, 0xFFFF, 0xFFFF},
    },
    {
     .name = "Southern Isles",
     .pos = {0x5D, 0x10C},
     .areasIds = {0x37, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F},
     .adjacentLocations = {0xFFFF, 0xFFFF, 0x19, 0xFFFF, 0xFFFF, 0x16, 0xFFFF, 0xFFFF},
    },
    {
     .name = "Southwest Isles",
     .pos = {0x2D, 0xCB},
     .areasIds = {0x38, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F},
     .adjacentLocations = {0xFFFF, 0x15, 0xFFFF, 0xFFFF, 0x17, 0xFFFF, 0xFFFF, 0xFFFF},
    },
    {
     .name = "Western Isles",
     .pos = {0x2D, 0x70},
     .areasIds = {0x39, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F},
     .adjacentLocations = {0x16, 0xFFFF, 0xFFFF, 0x1A, 0x13, 0xFFFF, 0xFFFF, 0xFFFF},
    },
    {
     .name = "Northern Sea",
     .pos = {0xD0, 0x16},
     .areasIds = {1, 3, 5, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F},
     .adjacentLocations = {0xFFFF, 0x14, 0xF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x1A},
    },
    {
     .name = "Southern Sea",
     .pos = {0xB2, 0x10D},
     .areasIds = {2, 4, 6, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F},
     .adjacentLocations = {0xFFFF, 0xFFFF, 0x12, 0x10, 0xFFFF, 0xFFFF, 0x15, 0xFFFF},
    },
    {
         .name = "Beach",
         .pos = {0x81, 0x42},
         .areasIds = {7, 0x31, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F},
         .adjacentLocations = {0xFFFF, 6, 0xFFFF, 0x18, 0xFFFF, 0x13, 0xFFFF, 0x17},
    },
    {
         .name = _("$t"),
         .pos = {0x163, 0xA1},
         .areasIds = {0, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F},
         .adjacentLocations = {0xE, 8, 7, 0xFFFF, 2, 9, 6, 0x10},
    },
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
    DUMMY_LOCATION,
};

void ShowFriendAreasMap(struct struct_unk800F990 *param_1)
{
    gFriendAreasMapPtr = param_1->unk8;
    gUnknown_2026E4E = 0x1010;
    sub_80095CC(0,0x14);
    UpdateFadeInTile(2);
    gFriendAreasMapPtr->locationsInfo = gFriendAreaLocations;
    gFriendAreasMapPtr->unk4A2C = param_1->unk5;
    FriendAreasMap_InitGfx();
    gFriendAreasMapPtr->unk4A28 = -1;
    gFriendAreasMapPtr->unk4A1C = -1;
    InitMapLocations(param_1->startingFriendAreaId);
    gFriendAreasMapPtr->locationIdOnBPress = gFriendAreasMapPtr->teamBaseLocationId;
    sCurrDirection = 0xff;
    sHeldDpadCounter = 0;
    sub_8011760();
    while (1) {
        s32 newLocationId = 0;
        s32 newDirection = 0;
        s32 iVar2 = ChooseLocation(&newLocationId, &newDirection);

        if (iVar2 == 1) {
            MoveToNewLocation(newLocationId, newDirection, 50);
        }
        else if (iVar2 == 2) {
            if (!ChooseAreaInLocation())
                continue;
            param_1->unkC = gFriendAreasMapPtr->chosenFriendAreaId;
            break;
        }
        else if (iVar2 == 3) {
            if (gFriendAreasMapPtr->currLocationId == gFriendAreasMapPtr->locationIdOnBPress) {
                param_1->unkC = 0;
                break;
            }
            MoveToNewLocation(gFriendAreasMapPtr->locationIdOnBPress,0,10);
        }
    }

    FadeFromFriendAreasMap();
    FriendAreasMap_CloseFiles();
    nullsub_16();
}

static s32 ChooseLocation(s32 *newLocationId, s32 *newDirection)
{
    s32 ret = 0;

    FriendAreasMap_ShowDirectionArrows();
    FriendAreasMap_PrintCurrAreaName();
    while (ret == 0) {
        s32 direction;

        FriendAreasMap_RunFrameActions();
        direction = GetChosenDirection();
        if (direction != 0xFF) {
            s32 currLocationId = gFriendAreasMapPtr->currLocationId;
            struct MapLocation *currLocation = &gFriendAreasMapPtr->mapLocations[currLocationId];

            if (currLocation->locationsByDirection[direction] >= 0) {
                s32 newlocId = currLocation->locationsByDirection[direction];
                struct MapLocation *newLocation = &gFriendAreasMapPtr->mapLocations[newlocId];

                if (newLocation->isShown) {
                    ret = 1;
                    *newLocationId = newlocId;
                    *newDirection = direction;
                    gFriendAreasMapPtr->unk4A28 = direction;
                    gFriendAreasMapPtr->unk4A1C = currLocationId;
                }
            }
        }

        if (gRealInputs.pressed & A_BUTTON) {
            PlayAcceptSoundEffect();
            ret = 2;
        }
        if (gRealInputs.pressed & B_BUTTON) {
            PlayCancelSoundEffect();
            ret = 3;
        }
    }
    return ret;
}

static bool8 ChooseAreaInLocation(void)
{
    bool8 ret = FALSE;

    FriendAreasMap_PrintAvailableSubAreas();
    while (1) {
        MenuInputStruct *menuPtr = &gFriendAreasMapPtr->menu;

        AddMenuCursorSprite(menuPtr);
        FriendAreasMap_RunFrameActions();
        if (gRealInputs.repeated & DPAD_DOWN) {
            MoveMenuCursorDown(menuPtr);
            PlayCursorUpDownSoundEffect();
        }
        if (gRealInputs.repeated & DPAD_UP) {
            MoveMenuCursorUp(menuPtr);
            PlayCursorUpDownSoundEffect();
        }

        if ((gRealInputs.pressed & A_BUTTON) || menuPtr->unk28.a_button) {
            PlayAcceptSoundEffect();
            gFriendAreasMapPtr->chosenFriendAreaId = gFriendAreasMapPtr->displayedAreas[menuPtr->menuIndex];
            ret = TRUE;
            break;
        }
        if ((gRealInputs.pressed & B_BUTTON) || menuPtr->unk28.b_button) {
            PlayCancelSoundEffect();
            break;
        }
    }

    return ret;
}

static void FadeFromFriendAreasMap(void)
{
    s32 i;

    FriendAreasMap_HideTextWindowAndArrows();
    sub_80117AC();
    for (i = 0; i < 60; i++) {
        gFriendAreasMapPtr->brightness -= 2;
        FriendAreasMap_RunFrameActions();
    }
}

struct MaxMin
{
    s16 min;
    s16 max;
};

static const struct MaxMin sDistanceRanges[] =
{
    {0x380, 0x480},
    {0x80, 0x380},
    {0xF80, 0x80},
    {0xC80, 0xF80},
    {0xB80, 0xC80},
    {0x880, 0xB80},
    {0x780, 0x880},
    {0x480, 0x780},
};

static void InitMapLocations(u8 startingFriendAreaId)
{
    s32 startingLocationId = 0;
    s32 i, j, k;

    for (i = 0; i < NUM_FRIEND_AREA_LOCATIONS; i++) {
        bool8 locationShown = FALSE;
        bool8 areaIsBase = FALSE;
        struct MapLocation *mapLocation = &gFriendAreasMapPtr->mapLocations[i];
        const struct FriendAreaLocationInfo *locationInfo = &gFriendAreasMapPtr->locationsInfo[i];

        for (j = 0; j < NUM_DIRECTIONS; j++) {
            mapLocation->locationsByDirection[j] = -1;
        }
        for (j = 0; j < MAX_AREAS_PER_LOCATION; j++) {
            if (IsFriendAreaShownOnMap(locationInfo->areasIds[j])) {
                if (locationInfo->areasIds[j] == startingFriendAreaId) {
                    startingLocationId = i;
                }
                if (locationInfo->areasIds[j] == 0) {
                    gFriendAreasMapPtr->teamBaseLocationId = i;
                    areaIsBase = TRUE;
                }
                locationShown = TRUE;
            }
        }

        if (locationShown) {
            mapLocation->isShown = TRUE;
            AxResInitFile(&mapLocation->sprite, gFriendAreasMapPtr->unk0[2], (areaIsBase) ? 12 : 1, 0, 0x40, 0, 1);
        }
        else {
            mapLocation->isShown = FALSE;
        }
    }

    for (i = 0; i < NUM_FRIEND_AREA_LOCATIONS; i++) {
        s32 var1, var2;
        struct MapLocation *mapLocation = &gFriendAreasMapPtr->mapLocations[i];
        const struct FriendAreaLocationInfo *locationInfo = &gFriendAreasMapPtr->locationsInfo[i];

        if (!mapLocation->isShown) {
            continue;
        }

        // Grab locations which are next to each other.
        for (j = 0; j < NUM_DIRECTIONS; j++) {
            mapLocation->locationsByDirection[j] = -1;
            if (locationInfo->adjacentLocations[j] >= 0) {
                struct MapLocation *ptr = &gFriendAreasMapPtr->mapLocations[locationInfo->adjacentLocations[j]];
                if (ptr->isShown) {
                    mapLocation->locationsByDirection[j] = locationInfo->adjacentLocations[j];
                }
            }
        }

        var1 = gFriendAreasMapPtr->unk4A28;
        var2 = gFriendAreasMapPtr->unk4A1C;
        if (var1 >= 0 && var2 >= 0) {
            struct MapLocation *ptr = &gFriendAreasMapPtr->mapLocations[var2];
            if (ptr->isShown) {
                var1 += 4;
                var1 &= 7;
                mapLocation->locationsByDirection[var1] = var2;
            }
        }

        // Find locations which are the closest from each other.
        for (j = 0; j < NUM_DIRECTIONS; j++) {
            s32 foundLocationId = -1;
            s32 biggestDistance = 999999;

            if (mapLocation->locationsByDirection[j] >= 0)
                continue;

            for (k = 0; k < NUM_FRIEND_AREA_LOCATIONS; k++) {
                bool8 valid;
                PixelPos pixelPos;
                s32 atanVal;
                struct MapLocation *mapLocation2Info = &gFriendAreasMapPtr->mapLocations[k];
                const struct FriendAreaLocationInfo *location2Info = &gFriendAreasMapPtr->locationsInfo[k];

                if (k == i)
                    continue;
                if (!mapLocation2Info->isShown)
                    continue;

                pixelPos.x = (location2Info->pos.x - locationInfo->pos.x) << 8;
                pixelPos.y = (location2Info->pos.y - locationInfo->pos.y) << 8;
                atanVal = Atan2_4096(&pixelPos);
                pixelPos.x /= 4;
                pixelPos.y /= 4;
                pixelPos.x /= 256;
                pixelPos.y /= 256;
                if (pixelPos.x == 0) {
                    pixelPos.x = 1;
                }
                if (pixelPos.y == 0) {
                    pixelPos.y = 1;
                }

                valid = FALSE;
                if (j == DIRECTION_EAST) {
                    while (atanVal >= 0x1000) {
                        atanVal -= 0x1000;
                    }
                    while (atanVal < 0) {
                        atanVal += 0x1000;
                    }
                    if (sDistanceRanges[j].min < atanVal || sDistanceRanges[j].max > atanVal) {
                        valid = TRUE;
                    }
                }
                else {
                    if (sDistanceRanges[j].min <= atanVal && sDistanceRanges[j].max > atanVal) {
                        valid = TRUE;
                    }
                }

                if (valid) {
                    s32 sum = (pixelPos.x * pixelPos.x) + (pixelPos.y * pixelPos.y);
                    if (biggestDistance > sum) {
                        biggestDistance = sum;
                        foundLocationId = k;
                    }
                }
            }

            if (foundLocationId >= 0) {
                mapLocation->locationsByDirection[j] = foundLocationId;
            }
        }
    }

    AxResInitFile(&gFriendAreasMapPtr->monAxSprite, gFriendAreasMapPtr->unk0[3], 0, 0, 0, 0, TRUE);
    gFriendAreasMapPtr->currLocationId = startingLocationId;
    gFriendAreasMapPtr->monSpritePos = gFriendAreasMapPtr->locationsInfo[startingLocationId].pos;
    gFriendAreasMapPtr->bgPos.x = gFriendAreasMapPtr->monSpritePos.x - 120;
    gFriendAreasMapPtr->bgPos.y = gFriendAreasMapPtr->monSpritePos.y - 80;
    FriendAreasMap_UpdateMonSpritePosition();
    FriendAreasMap_UpdateBg();
}

bool8 IsFriendAreaShownOnMap(u8 friendAreaId)
{
    if (friendAreaId >= NUM_FRIEND_AREAS) return FALSE;
    if (friendAreaId == 0) return TRUE;
    if (gFriendAreas[friendAreaId]) return TRUE;

    return FALSE;
}

static u8 GetChosenDirection(void)
{
    u8 dirsAll[] = {0xff, DIRECTION_SOUTH, DIRECTION_EAST, DIRECTION_SOUTHEAST, DIRECTION_NORTH, 0xff, DIRECTION_NORTHEAST, 0xff, DIRECTION_WEST, DIRECTION_SOUTHWEST, 0xff, 0xff, DIRECTION_NORTHWEST, 0xff, 0xff, 0xff};
    u8 dirsDiagonal[] = {0xff, 0xff, 0xff, DIRECTION_SOUTHEAST, 0xff, 0xff, DIRECTION_NORTHEAST, 0xff, 0xff, DIRECTION_SOUTHWEST, 0xff, 0xff, DIRECTION_NORTHWEST, 0xff, 0xff, 0xff};
    u32 id = 0;
    u8 *dirs = (gRealInputs.held & R_BUTTON) ? dirsDiagonal : dirsAll;

    if (gRealInputs.held & DPAD_DOWN) {
        id |= 1;
    }
    if (gRealInputs.held & DPAD_RIGHT) {
        id |= 2;
    }
    if (gRealInputs.held & DPAD_UP) {
        id |= 4;
    }
    if (gRealInputs.held & DPAD_LEFT) {
        id |= 8;
    }

    if (sCurrDirection == dirs[id]) {
        if (++sHeldDpadCounter >= 3) { // It'll only choose a New Area, if the DPAD was held for more than 3 frames.
            return dirs[id];
        }
    }
    else {
        sCurrDirection = dirs[id];
        sHeldDpadCounter = 0;
    }
    return 0xFF;
}

static void MoveToNewLocation(s32 destLocationId, s32 a1, s32 nFrames)
{
    s32 i, currLocationId;
    DungeonPos startingPos, dstPos;

    AxResInitFile(&gFriendAreasMapPtr->monAxSprite, gFriendAreasMapPtr->unk0[3], 0, a1 & 7, 0, 0, TRUE);
    FriendAreasMap_HideTextWindowAndArrows();

    currLocationId = gFriendAreasMapPtr->currLocationId;
    startingPos = gFriendAreasMapPtr->locationsInfo[currLocationId].pos;
    dstPos = gFriendAreasMapPtr->locationsInfo[destLocationId].pos;

    PlayCursorUpDownSoundEffect();
    for (i = 0; i < nFrames; i++) {
        gFriendAreasMapPtr->monSpritePos.x = ((((dstPos.x - startingPos.x) * (i << 8)) / nFrames) / 256) + startingPos.x;
        gFriendAreasMapPtr->monSpritePos.y = ((((dstPos.y - startingPos.y) * (i << 8)) / nFrames) / 256) + startingPos.y;

        FriendAreasMap_UpdateMonSpritePosition();
        FriendAreasMap_UpdateBg();
        FriendAreasMap_RunFrameActions();
    }

    gFriendAreasMapPtr->currLocationId = destLocationId;
    gFriendAreasMapPtr->monSpritePos = gFriendAreasMapPtr->locationsInfo[destLocationId].pos;
    FriendAreasMap_UpdateMonSpritePosition();
    FriendAreasMap_UpdateBg();
    FriendAreasMap_RunFrameActions();
    AxResInitFile(&gFriendAreasMapPtr->monAxSprite, gFriendAreasMapPtr->unk0[3], 0, 0, 0, 0, TRUE);
}

void PrintFriendAreaNameInMap(u8 *strBuffer, u8 index)
{
    if (index == 0) {
        FormatString("$t Team Base", strBuffer, strBuffer + 0x50, 0);
    }
    else {
        WriteFriendAreaName(strBuffer, index, FALSE);
    }
}

static UNUSED void GetAreaMapPosition(u8 areaId, DungeonPos *dst)
{
    s32 i, j;

    for (i = 0; i < NUM_FRIEND_AREA_LOCATIONS; i++) {
        const struct FriendAreaLocationInfo *locationInfo = &gFriendAreaLocations[i];
        for (j = 0; j < MAX_AREAS_PER_LOCATION; j++) {
            if (locationInfo->areasIds[j] == areaId) {
                dst->x = locationInfo->pos.x;
                dst->y = locationInfo->pos.y;
                return;
            }
        }
    }
    dst->x = 0;
    dst->y = 0;
}
