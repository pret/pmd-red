#include "global.h"
#include "globaldata.h"
#include "constants/direction.h"
#include "bg_control.h"
#include "bg_palette_buffer.h"
#include "code_8004AA0.h"
#include "code_800558C.h"
#include "graphics_memory.h"
#include "code_800C9CC.h"
#include "code_800D090.h"
#include "music_util.h"
#include "decompress_at.h"
#include "def_filearchives.h"
#include "friend_area.h"
#include "friend_areas_map.h"
#include "friend_areas_map_util.h"
#include "game_options.h"
#include "input.h"
#include "menu_input.h"
#include "play_time.h"
#include "pokemon.h"
#include "sprite.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"
#include "text_3.h"

static inline bool8 ResetFlags(axdata *ptr)
{
    return ptr->flags = 0;
}

static char *const gUnknown_80D408C[] =
{
    "wmapfont",
    "wmapmcc",
    "wmapcani",
    "wmappal",
};

static const DungeonPos gUnknown_80D40C4[] =
{
    {0, 24},
    {24, 24},
    {24, 0},
    {24, -24},
    {0, -24},
    {-24, -24},
    {-24, 0},
    {-24, 24},
};

void FriendAreasMap_InitGfx(void)
{
    u8 filename[12];
    s32 i, size;

    Pokemon *pokeStruct = GetLeaderMon1();
    OpenedFile *file = OpenFileAndGetFileDataPtr(gUnknown_80D408C[0], &gTitleMenuFileArchive);
    OpenedFile *file2 = OpenFileAndGetFileDataPtr(gUnknown_80D408C[1], &gTitleMenuFileArchive);

    sprintf(filename, "ax%03d", pokeStruct->speciesNum);
    gFriendAreasMapPtr->unk0[3] = OpenFileAndGetFileDataPtr(filename, &gMonsterFileArchive);
    gFriendAreasMapPtr->unk0[2] = OpenFileAndGetFileDataPtr("wmapspr", &gTitleMenuFileArchive);
    gFriendAreasMapPtr->unk0[4] = OpenFileAndGetFileDataPtr(gUnknown_80D408C[2], &gTitleMenuFileArchive);
    gFriendAreasMapPtr->unk0[1] = OpenFileAndGetFileDataPtr("palet", &gMonsterFileArchive);
    gFriendAreasMapPtr->unk0[0] = OpenFileAndGetFileDataPtr(gUnknown_80D408C[3], &gTitleMenuFileArchive);
    gFriendAreasMapPtr->unk4DD0 = GetPokemonOverworldPalette(pokeStruct->speciesNum, FALSE);

    sub_8005610(gFriendAreasMapPtr->unk0[2], 0x40, 0x1F, 0);

    DecompressATGlobalFile((u32 *)(VRAM + 0x8000), 0x0, file);
    sub_8004AA4(gFriendAreasMapPtr->unk4C4C, gFriendAreasMapPtr->unk0[4], 0x10);
    size = 0x4000;
    DecompressATFile(&gFriendAreasMapPtr->unk14, size, file2);

    gFriendAreasMapPtr->brightness = 0;
    gFriendAreasMapPtr->bgPos.x = 0;
    gFriendAreasMapPtr->bgPos.y = 0;

    for (i = 0; i < NUM_DIRECTIONS; i++) {
        ResetFlags(&gFriendAreasMapPtr->arrowSprites[i]);
    }

    CloseFile(file);
    CloseFile(file2);
    ShowWindows(NULL, 1, 1);
}

void FriendAreasMap_CloseFiles(void)
{
    CloseFile(gFriendAreasMapPtr->unk0[4]);
    CloseFile(gFriendAreasMapPtr->unk0[2]);
    CloseFile(gFriendAreasMapPtr->unk0[3]);
    CloseFile(gFriendAreasMapPtr->unk0[0]);
    CloseFile(gFriendAreasMapPtr->unk0[1]);
}

static void AnimateSprites(void)
{
    s32 i, dir;
    unkStruct_2039DB0 var_30;
    DungeonPos bgPos;

    sub_8004E8C(&var_30);
    var_30.unk4 = 0xF3FF;
    var_30.unkA = 0x800;
    bgPos = gFriendAreasMapPtr->bgPos;
    RunAxAnimationFrame(&gFriendAreasMapPtr->monAxSprite);
    DoAxFrame_800558C(&gFriendAreasMapPtr->monAxSprite, gFriendAreasMapPtr->monSpritePos.x - bgPos.x, gFriendAreasMapPtr->monSpritePos.y - bgPos.y, 3, gFriendAreasMapPtr->unk4DD0, &var_30);

    for (i = 0; i < NUM_FRIEND_AREA_LOCATIONS; i++) {
        struct MapLocation *mapLocation = &gFriendAreasMapPtr->mapLocations[i];
        const struct FriendAreaLocationInfo *locationInfo = &gFriendAreasMapPtr->locationsInfo[i];
        if (mapLocation->isShown) {
            RunAxAnimationFrame(&mapLocation->sprite);
            DoAxFrame_800558C(&mapLocation->sprite, locationInfo->pos.x - bgPos.x, locationInfo->pos.y- bgPos.y, 1, 0, &var_30);
        }
    }

    for (dir = 0; dir < NUM_DIRECTIONS; dir++) {
        if (AxFlag8000(&gFriendAreasMapPtr->arrowSprites[dir])) {
            RunAxAnimationFrame(&gFriendAreasMapPtr->arrowSprites[dir]);
            // Hide non-diagonal arrows when R button is pressed.
            if ((gRealInputs.held & R_BUTTON) && (dir % 2) == 0)
                continue;

            DoAxFrame_800558C(&gFriendAreasMapPtr->arrowSprites[dir],
                              (gUnknown_80D40C4[dir].x + gFriendAreasMapPtr->monSpritePos.x) - bgPos.x,
                              (gUnknown_80D40C4[dir].y + gFriendAreasMapPtr->monSpritePos.y) - bgPos.y,
                              2, 0, &var_30);
        }
    }
}

void FriendAreasMap_UpdateBg(void)
{
    s32 i, j;
    s32 y1 = gFriendAreasMapPtr->bgPos.y >> 3;
    s32 y2 = y1;

    for (i = 0; i < 21; i++) {
        s32 x1 = gFriendAreasMapPtr->bgPos.x >> 3;
        s32 x2 = x1;

        for (j = 0; j < 31; j++) {
            x1 &= 0x1F;
            y1 &= 0x1F;

            gBgTilemaps[2][y1][x1] = gFriendAreasMapPtr->unk2014[y2][x2];
            gBgTilemaps[3][y1][x1] = gFriendAreasMapPtr->unk14[y2][x2];
            x2++;
            x1++;
        }
        y2++;
        y1++;
    }

    ScheduleBgTilemapCopy(2);
    ScheduleBgTilemapCopy(3);
}

void FriendAreasMap_HideTextWindowAndArrows(void)
{
    s32 i;

    ShowWindows(NULL, TRUE, TRUE);
    gFriendAreasMapPtr->unk4DDC = 0;
    gFriendAreasMapPtr->unk4DE0 = 0;
    gFriendAreasMapPtr->unk4DE4 = 0;
    gFriendAreasMapPtr->unk4DE8 = 0;
    for (i = 0; i < NUM_DIRECTIONS; i++) {
        ResetFlags(&gFriendAreasMapPtr->arrowSprites[i]);
    }
}

static bool8 FadeScreen(void)
{
    bool8 ret = FALSE;

    if (gFriendAreasMapPtr->brightness < 31) {
        s32 i;
        RGB_Struct *color = (void *)gFriendAreasMapPtr->unk0[0]->data;

        if (++gFriendAreasMapPtr->brightness >= 31) {
            gFriendAreasMapPtr->brightness = 31;
        }

        for (i = 0; i < 224; color++, i++) {
            SetBGPaletteBufferColorRGB(i, color, gFriendAreasMapPtr->brightness, NULL);
        }

        color = (void *)gFriendAreasMapPtr->unk0[1]->data;
        for (i = 0; i < 240; color++, i++) {
            SetBGPaletteBufferColorRGB(i + 256, color, gFriendAreasMapPtr->brightness, NULL);
        }

        ret = TRUE;
    }

    return ret;
}

void FriendAreasMap_UpdateMonSpritePosition(void)
{
    if (gFriendAreasMapPtr->monSpritePos.x - gFriendAreasMapPtr->bgPos.x < 48) {
        gFriendAreasMapPtr->bgPos.x = gFriendAreasMapPtr->monSpritePos.x - 48;
    }
    else if (gFriendAreasMapPtr->monSpritePos.x - gFriendAreasMapPtr->bgPos.x > 192) {
        gFriendAreasMapPtr->bgPos.x = gFriendAreasMapPtr->monSpritePos.x - 192;
    }

    if (gFriendAreasMapPtr->monSpritePos.y - gFriendAreasMapPtr->bgPos.y < 48) {
        gFriendAreasMapPtr->bgPos.y = gFriendAreasMapPtr->monSpritePos.y - 48;
    }
    else if (gFriendAreasMapPtr->monSpritePos.y - gFriendAreasMapPtr->bgPos.y > 112) {
        gFriendAreasMapPtr->bgPos.y = gFriendAreasMapPtr->monSpritePos.y - 112;
    }

    if (gFriendAreasMapPtr->bgPos.x < 0) {
        gFriendAreasMapPtr->bgPos.x = 0;
    }
    if (gFriendAreasMapPtr->bgPos.y < 0) {
        gFriendAreasMapPtr->bgPos.y = 0;
    }
    if (gFriendAreasMapPtr->bgPos.x > 239) {
        gFriendAreasMapPtr->bgPos.x = 239;
    }
    if (gFriendAreasMapPtr->bgPos.y > 151) {
        gFriendAreasMapPtr->bgPos.y = 151;
    }
}

void FriendAreasMap_ShowDirectionArrows(void)
{
    s32 i;
    struct MapLocation *currLocation = &gFriendAreasMapPtr->mapLocations[gFriendAreasMapPtr->currLocationId];

    for (i = 0; i < NUM_DIRECTIONS; i++) {
        ResetFlags(&gFriendAreasMapPtr->arrowSprites[i]);
        if (currLocation->locationsByDirection[i] >= 0) {
            struct MapLocation *ptr = &gFriendAreasMapPtr->mapLocations[currLocation->locationsByDirection[i]];
            if (ptr->isShown) {
                AxResInitFile(&gFriendAreasMapPtr->arrowSprites[i], gFriendAreasMapPtr->unk0[2], i + 4, 0, 0x40, 0, TRUE);
            }
        }
    }
}

void FriendAreasMap_PrintCurrAreaName(void)
{
    u8 txt[200];
    s32 id = gFriendAreasMapPtr->currLocationId;
    const struct FriendAreaLocationInfo *locationInfo = &gFriendAreasMapPtr->locationsInfo[id];
    WindowTemplates windows = {0};

    windows.id[0].type = WINDOW_TYPE_NORMAL;
    windows.id[0].pos.x = 7;
    windows.id[0].pos.y = 2;
    windows.id[0].width = 21;
    windows.id[0].height = 2;
    windows.id[0].totalHeight = 2;

    windows.id[1].type = WINDOW_TYPE_NORMAL;

    windows.id[2].type = WINDOW_TYPE_NORMAL;

    windows.id[3].type = WINDOW_TYPE_NORMAL;

    if (gFriendAreasMapPtr->monSpritePos.y - gFriendAreasMapPtr->bgPos.y <= 80)
        windows.id[0].pos.y = 17;
    else
        windows.id[0].pos.y = 1;

    ShowWindows(&windows, TRUE, TRUE);
    sub_80073B8(0);
    sprintfStatic(txt, _("{CENTER_ALIGN}%s"), locationInfo->name);
    PrintFormattedStringOnWindow(12, 2, txt, 0, '\0');
    sub_80073E0(0);
    gFriendAreasMapPtr->unk4DDC = (windows.id[0].pos.x * 8) - 5;
    gFriendAreasMapPtr->unk4DE0 = (windows.id[0].pos.y * 8) + 5;
    gFriendAreasMapPtr->unk4DE4 = (windows.id[0].width * 8) + 10;
    gFriendAreasMapPtr->unk4DE8 = (windows.id[0].height * 8) + 10;
}

void FriendAreasMap_PrintAvailableSubAreas(void)
{
    s32 i, count, var;
    s32 id = gFriendAreasMapPtr->currLocationId;
    const struct FriendAreaLocationInfo *locationInfo = &gFriendAreasMapPtr->locationsInfo[id];
    MenuInputStruct *menuInput = &gFriendAreasMapPtr->menu;
    WindowHeader header;
    WindowTemplates windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {7, 2},
                .width = 21,
                .height = 2,
                .totalHeight = 2,
                .header = &header,
            },
            [1] = WIN_TEMPLATE_DUMMY,
            [2] = WIN_TEMPLATE_DUMMY,
            [3] = WIN_TEMPLATE_DUMMY,
        }
    };

    count = 0;
    for (i = 0; i < MAX_AREAS_PER_LOCATION; i++) {
        if (IsFriendAreaShownOnMap(locationInfo->areasIds[i])) {
            gFriendAreasMapPtr->displayedAreas[count] = locationInfo->areasIds[i];
            count++;
        }
    }

    gFriendAreasMapPtr->displayedAreasCount = count;
    header.count = 1;
    header.currId = 0;
    header.width = 18;
    header.f3 = 0;
    menuInput->menuIndex = 0;
    menuInput->currPageEntries = count;
    menuInput->entriesPerPage = count;
    menuInput->currPage = 0;
    menuInput->pagesCount = 0;
    menuInput->unk4 = 0;
    menuInput->firstEntryY = 16;
    menuInput->windowId = 0;
    menuInput->leftRightArrowsPos.x = 0;
    menuInput->leftRightArrowsPos.y = 0;
    menuInput->unk14.x = 0;
    menuInput->unk14.y = 0;
    menuInput->cursorArrowPos.x = 8;
    menuInput->cursorArrowPos.y = 8;
    ResetTouchScreenMenuInput(&menuInput->touchScreen);
    var = CalcEntriesTotalHeight(menuInput->entriesPerPage, 0);
    windows.id[0].totalHeight = windows.id[0].height = var + 2;
    sub_80137B0(menuInput, var * 8);

    ShowWindows(&windows, TRUE, TRUE);

    gFriendAreasMapPtr->unk4DDC = 0;
    gFriendAreasMapPtr->unk4DE0 = 0;
    gFriendAreasMapPtr->unk4DE4 = 0;
    gFriendAreasMapPtr->unk4DE8 = 0;
    sub_80073B8(0);
    PrintFormattedStringOnWindow(16, 0, _("Where would you like to go?"), 0, '\0');

    for (i = 0; i < count; i++) {
        FriendAreaCapacity friendAreaCapacity;
        s32 y = GetMenuEntryYCoord(menuInput, i);
        u8 areaId = gFriendAreasMapPtr->displayedAreas[i];

        PrintFriendAreaNameInMap(gFormatBuffer_Items[0], areaId);
        if (areaId == 0) {
            PrintFormattedStringOnWindow(12, y, _("{MOVE_ITEM_0}"), 0, '\0');
        }
        else {
            GetFriendAreaCapacity(areaId, &friendAreaCapacity, gFriendAreasMapPtr->unk4A2C);
            gFormatArgs[0] = friendAreaCapacity.currNoPokemon;
            gFormatArgs[1] = friendAreaCapacity.maxPokemon;
            PrintFormattedStringOnWindow(12, y, _("{MOVE_ITEM_0}($v02／$v12)"), 0, '\0');
        }
    }

    sub_80073E0(0);
}

void FriendAreasMap_RunFrameActions(void)
{
    SetBG2RegOffsets(gFriendAreasMapPtr->bgPos.x, gFriendAreasMapPtr->bgPos.y);
    SetBG3RegOffsets(gFriendAreasMapPtr->bgPos.x, gFriendAreasMapPtr->bgPos.y);
    AnimateSprites();
    sub_8004AF0(FadeScreen(), gFriendAreasMapPtr->unk4C4C, 0xB0, 16, gFriendAreasMapPtr->brightness, NULL);
    sub_8005838(NULL, 0);
    nullsub_8(gGameOptionsRef->touchScreen);
    sub_8005180();
    sub_80060EC();
    IncrementPlayTime(gPlayTimeRef);
    WaitForNextFrameAndAdvanceRNG();
    LoadBufferedInputs();
    CopySpritesToOam();
    sub_8005304();
    TransferBGPaletteBuffer();
    xxx_call_update_bg_vram();
    DoScheduledMemCopies();
    xxx_call_update_bg_sound_input();
    UpdateSoundEffectCounters();
    ResetSprites(FALSE);
}
