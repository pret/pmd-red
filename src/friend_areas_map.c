#include "global.h"
#include "globaldata.h"
#include "constants/friend_area.h"
#include "bg_control.h"
#include "bg_palette_buffer.h"
#include "code_8004AA0.h"
#include "code_800558C.h"
#include "code_8009804.h"
#include "code_800C9CC.h"
#include "code_800D090.h"
#include "code_80118A4.h"
#include "decompress_sir.h"
#include "friend_area.h"
#include "friend_areas_map.h"
#include "friend_areas_map_util.h"
#include "input.h"
#include "math.h"
#include "menu_input.h"
#include "pokemon.h"
#include "sprite.h"
#include "string_format.h"
#include "text_1.h"
#include "text_3.h"

EWRAM_INIT struct FriendAreasMap *gFriendAreasMapPtr = NULL;
EWRAM_DATA static u8 sCurrDirection = 0;
EWRAM_DATA static u8 sHeldDpadCounter = 0;

#include "data/friend_areas_map.h"

static s32 ChooseLocation_Async(s32 *newLocationId, s32 *newDirection);
static bool8 ChooseAreaInLocation_Async(void);
static void FriendAreasMap_FadeOut_Async(void);
static u8 GetChosenDirection(void);
static void InitMapLocations(u8 startingFriendAreaId);
static void MoveToNewLocation_Async(s32 destLocationId, s32 direction, s32 nFrames);

void ShowFriendAreasMap_Async(struct FriendAreasMapSetupStruct *setupPtr)
{
    gFriendAreasMapPtr = setupPtr->friendAreasMapPtr;
    gUnknown_2026E4E = 0x1010;
    sub_80095CC(0, 20);
    UpdateFadeInTile(2);
    gFriendAreasMapPtr->locationsInfo = sFriendAreaLocations[0];
    gFriendAreasMapPtr->unk4A2C = setupPtr->unk5;
    FriendAreasMap_InitGfx();
    gFriendAreasMapPtr->unk4A28 = -1;
    gFriendAreasMapPtr->unk4A1C = -1;
    InitMapLocations(setupPtr->startingFriendAreaId);
    gFriendAreasMapPtr->locationIdOnBPress = gFriendAreasMapPtr->teamBaseLocationId;
    sCurrDirection = 0xff;
    sHeldDpadCounter = 0;
    sub_8011760();

    while (TRUE) {
        s32 newLocationId = 0;
        s32 newDirection = 0;
        s32 inputRet = ChooseLocation_Async(&newLocationId, &newDirection);

        if (inputRet == 1) {
            MoveToNewLocation_Async(newLocationId, newDirection, 50);
        }
        else if (inputRet == 2) {
            if (!ChooseAreaInLocation_Async())
                continue;
            setupPtr->chosenAreaId = gFriendAreasMapPtr->chosenFriendAreaId;
            break;
        }
        else if (inputRet == 3) {
            if (gFriendAreasMapPtr->currLocationId == gFriendAreasMapPtr->locationIdOnBPress) {
                setupPtr->chosenAreaId = FRIEND_AREA_NONE;
                break;
            }
            MoveToNewLocation_Async(gFriendAreasMapPtr->locationIdOnBPress, DIRECTION_SOUTH, 10);
        }
    }

    FriendAreasMap_FadeOut_Async();
    FriendAreasMap_CloseFiles();
    nullsub_16();
}

static s32 ChooseLocation_Async(s32 *newLocationId, s32 *newDirection)
{
    s32 ret = 0;

    FriendAreasMap_ShowDirectionArrows();
    FriendAreasMap_PrintCurrAreaName();
    while (ret == 0) {
        u8 direction;

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

static bool8 ChooseAreaInLocation_Async(void)
{
    bool8 ret = FALSE;

    FriendAreasMap_PrintAvailableSubAreas();

    while (TRUE) {
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

static void FriendAreasMap_FadeOut_Async(void)
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
                var1 &= DIRECTION_MASK;
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

static void MoveToNewLocation_Async(s32 destLocationId, s32 direction, s32 nFrames)
{
    s32 i, currLocationId;
    DungeonPos startingPos, dstPos;

    AxResInitFile(&gFriendAreasMapPtr->monAxSprite, gFriendAreasMapPtr->unk0[3], 0, direction & DIRECTION_MASK, 0, 0, TRUE);
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
        const struct FriendAreaLocationInfo *locationInfo = &sFriendAreaLocations[0][i];
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
