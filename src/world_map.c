#include "global.h"
#include "globaldata.h"
#include "bg_control.h"
#include "bg_palette_buffer.h"
#include "code_8004AA0.h"
#include "code_800558C.h"
#include "graphics_memory.h"
#include "code_800C9CC.h"
#include "code_800D090.h"
#include "music_util.h"
#include "world_map_sound.h"
#include "decompress_at.h"
#include "decompress_sir.h"
#include "def_filearchives.h"
#include "dungeon_info.h"
#include "friend_area.h"
#include "game_options.h"
#include "input.h"
#include "math.h"
#include "play_time.h"
#include "pokemon.h"
#include "sprite.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"
#include "text_3.h"
#include "world_map.h"

extern void WaitForNextFrameAndAdvanceRNG(void);
extern void CopyDungeonName1toBuffer(u8 *buffer, DungeonLocation *dungeonLocation);

static EWRAM_INIT struct WorldMap *sWorldMapPtr = NULL;
static EWRAM_INIT WindowTemplates sWorldMapWindows = {
    .id = {
        [0] = {
            .type = WINDOW_TYPE_NORMAL,
            .pos = {2, 10},
            .width = 26,
            .height = 9,
            .unk10 = 9,
        },
        [1] = {
            .type = WINDOW_TYPE_NORMAL,
            .pos = {23, 6},
            .width = 5,
            .height = 3,
            .unk10 = 3,
        },
        [2] = WIN_TEMPLATE_DUMMY,
        [3] = WIN_TEMPLATE_DUMMY,
    }
};

static void ClearWindows(void);
static void AnimateSprites(bool8 a0);
static bool8 FadeScreen(void);
static void nullsub_24(void);
static void WorldMap_RunFrameActions(void);
static void UpdateMonSpritePosition(void);
static void UpdateBg(void);
static void sub_8010494(struct WorldMapInfo *r9);
static void AnimateMonPath_Async(u8 id1, u8 id2);
static void sub_801059C(void);
static bool8 PlayerEnterDungeonPrompt_Async(u8 *str);
static void PrintDialogueMessage_Async(const u8 *text);
static void FadeFromWorldMap_Async(void);
static void CloseFiles(void);
static void PrintDungeonName(DungeonLocation *dungLocation);

// Code is very similar to the functions in friend_areas_map_util.c

void ShowWorldMap_Async(struct WorldMapSetupStruct *setupPtr)
{
    s32 i, speciesId, dungeonEnter;
    u8 text[1000];

    sWorldMapPtr = setupPtr->worldMap;
    gUnknown_2026E4E = 2566;
    sub_80095CC(0, 0x14);
    UpdateFadeInTile(2);
    sub_801059C();
    sub_8010494(&setupPtr->info);
    PlayWorldMapBGM();

    // 60 frame delay
    for (i = 0; i < 60; i++)
        WorldMap_RunFrameActions();

    AnimateMonPath_Async(setupPtr->info.startLocation.id, setupPtr->info.unk4.unk0.id);
    PrintDungeonName(&setupPtr->info.unk4.unk0);

    // 60 frame delay
    for (i = 0; i < 60; i++)
        WorldMap_RunFrameActions();

    if (setupPtr->info.unk4.unkC) {
        speciesId = setupPtr->info.mon.speciesNum;
        ASM_MATCH_TRICK(speciesId);
    }
    else {
        speciesId = 0;
    }

    dungeonEnter = sub_809034C(setupPtr->info.unk4.unk0.id, speciesId, text, setupPtr->info.unk6C, FALSE);
    if (dungeonEnter == 0) {
        setupPtr->dungeonEntered = TRUE;
    }
    else if (dungeonEnter == 1) {
        PrintDialogueMessage_Async(text);
        setupPtr->dungeonEntered = FALSE;
    }
    else if (dungeonEnter == 2) {
        if (PlayerEnterDungeonPrompt_Async(text)) {
            setupPtr->dungeonEntered = TRUE;
        }
        else {
            setupPtr->dungeonEntered = FALSE;
        }
    }

    FadeFromWorldMap_Async();
    CloseFiles();
    nullsub_16();
}

static const DungeonPos gDungeonCoordinates[] =
{
    [DUNGEON_TINY_WOODS] = {172, 174},
    [DUNGEON_THUNDERWAVE_CAVE] = {171, 111},
    [DUNGEON_MT_STEEL] = {242, 126},
    [DUNGEON_SINISTER_WOODS] = {232, 181},
    [DUNGEON_SILENT_CHASM] = {263, 155},
    [DUNGEON_MT_THUNDER] = {298, 159},
    [DUNGEON_MT_THUNDER_PEAK] = {299, 142},
    [DUNGEON_GREAT_CANYON] = {203, 255},
    [DUNGEON_LAPIS_CAVE] = {385, 166},
    [DUNGEON_MT_BLAZE] = {388, 126},
    [DUNGEON_MT_BLAZE_PEAK] = {389, 109},
    [DUNGEON_FROSTY_FOREST] = {417, 112},
    [DUNGEON_FROSTY_GROTTO] = {422, 101},
    [DUNGEON_MT_FREEZE] = {432, 85},
    [DUNGEON_MT_FREEZE_PEAK] = {436, 69},
    [DUNGEON_MAGMA_CAVERN] = {442, 150},
    [DUNGEON_MAGMA_CAVERN_PIT] = {446, 163},
    [DUNGEON_SKY_TOWER] = {365, 27},
    [DUNGEON_SKY_TOWER_SUMMIT] = {352, 12},
    [DUNGEON_STORMY_SEA] = {133, 238},
    [DUNGEON_SILVER_TRENCH] = {129, 143},
    [DUNGEON_METEOR_CAVE] = {344, 105},
    [DUNGEON_MT_FREEZE_PEAK_2] = {427, 62},
    [DUNGEON_WESTERN_CAVE] = {27, 211},
    [DUNGEON_BOSS_3] = {246, 315},
    [DUNGEON_BOSS_4] = {443, 6},
    [DUNGEON_WISH_CAVE] = {32, 279},
    [DUNGEON_BURIED_RELIC] = {404, 262},
    [DUNGEON_PITFALL_VALLEY] = {194, 63},
    [DUNGEON_NORTHERN_RANGE] = {159, 46},
    [DUNGEON_BOSS_9] = {441, 310},
    [DUNGEON_DESERT_REGION] = {231, 235},
    [DUNGEON_SOUTHERN_CAVERN] = {169, 287},
    [DUNGEON_WYVERN_HILL] = {441, 273},
    [DUNGEON_FIERY_FIELD] = {64, 87},
    [DUNGEON_NORTHWIND_FIELD] = {80, 54},
    [DUNGEON_SOLAR_CAVE] = {431, 225},
    [DUNGEON_LIGHTNING_FIELD] = {27, 94},
    [DUNGEON_DARKNIGHT_RELIC] = {354, 298},
    [DUNGEON_WONDROUS_SEA] = {336, 253},
    [DUNGEON_MURKY_CAVE] = {287, 222},
    [DUNGEON_GRAND_SEA] = {63, 163},
    [DUNGEON_UPROAR_FOREST] = {275, 111},
    [DUNGEON_ODDITY_CAVE] = {202, 232},
    [DUNGEON_REMAINS_ISLAND] = {268, 302},
    [DUNGEON_MARVELOUS_SEA] = {336, 260},
    [DUNGEON_FANTASY_STRAIT] = {110, 79},
    [DUNGEON_ROCK_PATH] = {225, 314},
    [DUNGEON_SNOW_PATH] = {206, 314},
    [DUNGEON_AUTOPILOT] = {11, 307},
    [DUNGEON_D50] = {472, 25},
    [DUNGEON_D51] = {250, 8},
    [DUNGEON_NORMAL_MAZE] = {187, 190},
    [DUNGEON_HOWLING_FOREST] = {205, 111},
    [DUNGEON_D54] = {474, 6},
    [DUNGEON_POISON_MAZE] = {183, 9},
    [DUNGEON_WATERFALL_POND] = {367, 214},
    [DUNGEON_UNKNOWN_RELIC] = {278, 273},
    [DUNGEON_JOYOUS_TOWER] = {68, 305},
    [DUNGEON_FAR_OFF_SEA] = {270, 33},
    [DUNGEON_MT_FARAWAY] = {33, 39},
    [DUNGEON_D61] = {217, 8},
    [DUNGEON_PURITY_FOREST] = {69, 280},
    [DUNGEON_OUT_ON_RESCUE] = {192, 183},
};

// Heavy math function.
static void AnimateMonPath_Async(u8 id1, u8 id2)
{
    s32 i, valMax, r3;
    PixelPos pixelPos;
    DungeonPos pos1 = gDungeonCoordinates[id1];
    DungeonPos pos2 = gDungeonCoordinates[id2];

    valMax = max(abs(pos2.x - pos1.x), abs(pos2.y - pos1.y));
    valMax /= 2;

    pixelPos.x = pos1.x - pos2.x;
    pixelPos.y = pos2.y - pos1.y;
    r3 = Atan2_4096(&pixelPos) - 1024;
    if (r3 < 0) {
        r3 += 511;
    }
    r3 >>= 9;
    r3 &= 7;
    AxResInitFile(&sWorldMapPtr->monAxSprite, sWorldMapPtr->unk1100[3], 0, r3, 0, 0, TRUE);

    for (i = 0; i < valMax; i++) {
        sWorldMapPtr->monSpritePos.x = ((((pos2.x - pos1.x) * (i << 8)) / valMax) / 256) + pos1.x;
        sWorldMapPtr->monSpritePos.y = ((((pos2.y - pos1.y) * (i << 8)) / valMax) / 256) + pos1.y;
        UpdateMonSpritePosition();
        UpdateBg();
        WorldMap_RunFrameActions();
        if (gRealInputs.pressed & A_BUTTON)
            break;
        if (gRealInputs.pressed & B_BUTTON)
            break;
    }

    sWorldMapPtr->monSpritePos = pos2;
    UpdateMonSpritePosition();
    UpdateBg();
    WorldMap_RunFrameActions();
}

static void sub_8010494(struct WorldMapInfo *info)
{
    s32 i;
    for (i = 0; i < 64; i++) {
        struct UnkStruct_Sub1 *structPtr = &sWorldMapPtr->unk0[i];
        u8 r0;

        if (i < WORLD_MAP_UNK_6D_COUNT) {
            r0 = info->unk6D[i];
        }
        else {
            r0 = 1;
        }

        if (r0) {
            structPtr->unk0 = 1;
            AxResInitFile(&structPtr->unk8, sWorldMapPtr->unk1100[2], (i == WORLD_MAP_UNK_6D_COUNT) ? 12 : 1, 0, 0x40, 0, 1);
            structPtr->unk4 = gDungeonCoordinates[i];
        }
        else {
            structPtr->unk0 = 0;
        }
    }

    AxResInitFile(&sWorldMapPtr->monAxSprite, sWorldMapPtr->unk1100[3], 0, 0, 0, 0, TRUE);
    sWorldMapPtr->monSpritePos = gDungeonCoordinates[info->startLocation.id];
    sWorldMapPtr->bgPos.x = sWorldMapPtr->monSpritePos.x - 120;
    sWorldMapPtr->bgPos.y = sWorldMapPtr->monSpritePos.y - 80;
    UpdateMonSpritePosition();
    UpdateBg();
}

static char *const gUnknown_80D4014[] =
{
    "wmp2font",
    "wmp2mcc",
    "wmp2cani",
    "wmp2pal",
    "wmp2fon1", // Maybe blue uses this?
};

static void sub_801059C(void)
{
    u8 filename[0xC];
    s32 i, size;

    Pokemon *pokeStruct = GetPlayerPokemonStruct();
    OpenedFile *file = OpenFileAndGetFileDataPtr(gUnknown_80D4014[0], &gTitleMenuFileArchive);
    OpenedFile *file2 = OpenFileAndGetFileDataPtr(gUnknown_80D4014[1], &gTitleMenuFileArchive);

    sprintf(filename, "ax%03d", pokeStruct->speciesNum);
    sWorldMapPtr->unk1100[3] = OpenFileAndGetFileDataPtr(filename, &gMonsterFileArchive);
    sWorldMapPtr->unk1100[2] = OpenFileAndGetFileDataPtr("wmapspr", &gTitleMenuFileArchive);
    sWorldMapPtr->unk1100[4] = OpenFileAndGetFileDataPtr(gUnknown_80D4014[2], &gTitleMenuFileArchive);
    sWorldMapPtr->unk1100[1] = OpenFileAndGetFileDataPtr("palet", &gMonsterFileArchive);
    sWorldMapPtr->unk1100[0] = OpenFileAndGetFileDataPtr(gUnknown_80D4014[3], &gTitleMenuFileArchive);
    sWorldMapPtr->unk52D4 = GetPokemonOverworldPalette(pokeStruct->speciesNum, FALSE);

    sub_8005610(sWorldMapPtr->unk1100[2], 0x40, 0x1F, 0);

    DecompressATGlobalFile((u32 *)(VRAM + 0x8000), 0x0, file);
    sub_8004AA4(sWorldMapPtr->unk5150, sWorldMapPtr->unk1100[4], 0x10);
    size = 0x4000;
    DecompressATFile(&sWorldMapPtr->unk1114, size, file2);

    sWorldMapPtr->brightness = 0;
    sWorldMapPtr->bgPos.x = 0;
    sWorldMapPtr->bgPos.y = 0;

    for (i = 0; i < UNK_WORLD_MAP_52E0_COUNT; i++) {
        sWorldMapPtr->unk52E0[i] = 0xFFFF;
        sWorldMapPtr->unk5E98[i] = 0;
    }

    CloseFile(file);
    CloseFile(file2);
    ShowWindows(NULL, 1, 1);
}

static void CloseFiles(void)
{
    CloseFile(sWorldMapPtr->unk1100[4]);
    CloseFile(sWorldMapPtr->unk1100[3]);
    CloseFile(sWorldMapPtr->unk1100[2]);
    CloseFile(sWorldMapPtr->unk1100[0]);
    CloseFile(sWorldMapPtr->unk1100[1]);
}

static void UpdateMonSpritePosition(void)
{
    if (sWorldMapPtr->monSpritePos.x - sWorldMapPtr->bgPos.x < 48) {
        sWorldMapPtr->bgPos.x = sWorldMapPtr->monSpritePos.x - 48;
    }
    else if (sWorldMapPtr->monSpritePos.x - sWorldMapPtr->bgPos.x > 192) {
        sWorldMapPtr->bgPos.x = sWorldMapPtr->monSpritePos.x - 192;
    }

    if (sWorldMapPtr->monSpritePos.y - sWorldMapPtr->bgPos.y < 48) {
        sWorldMapPtr->bgPos.y = sWorldMapPtr->monSpritePos.y - 48;
    }
    else if (sWorldMapPtr->monSpritePos.y - sWorldMapPtr->bgPos.y > 112) {
        sWorldMapPtr->bgPos.y = sWorldMapPtr->monSpritePos.y - 112;
    }

    if (sWorldMapPtr->bgPos.x < 0) {
        sWorldMapPtr->bgPos.x = 0;
    }
    if (sWorldMapPtr->bgPos.y < 0) {
        sWorldMapPtr->bgPos.y = 0;
    }
    if (sWorldMapPtr->bgPos.x >= 240) {
        sWorldMapPtr->bgPos.x = 240;
    }
    if (sWorldMapPtr->bgPos.y >= 160) {
        sWorldMapPtr->bgPos.y = 160;
    }
}

static void UpdateBg(void)
{
    s32 i, j;
    s32 y1 = sWorldMapPtr->bgPos.y >> 3;
    s32 y2 = y1;

    for (i = 0; i < 21; i++) {
        s32 x1 = sWorldMapPtr->bgPos.x >> 3;
        s32 x2 = x1;

        for (j = 0; j < 31; j++) {
            x1 &= 0x1F;
            y1 &= 0x1F;

            gBgTilemaps[2][y1][x1] = sWorldMapPtr->unk3114[y2][x2];
            gBgTilemaps[3][y1][x1] = sWorldMapPtr->unk1114[y2][x2];
            x2++;
            x1++;
        }
        y2++;
        y1++;
    }

    ScheduleBgTilemapCopy(2);
    ScheduleBgTilemapCopy(3);
}

static void nullsub_24(void)
{

}

static void FadeFromWorldMap_Async(void)
{
    s32 i;

    ClearWindows();
    FadeOutWorldMapBGM();
    for (i = 0; i < 60; i++) {
        sWorldMapPtr->brightness -= 2;
        WorldMap_RunFrameActions();
    }
}

static void ClearWindows(void)
{
    ShowWindows(NULL, TRUE, TRUE);
}

static void WorldMap_RunFrameActions(void)
{
    SetBG2RegOffsets(sWorldMapPtr->bgPos.x, sWorldMapPtr->bgPos.y);
    SetBG3RegOffsets(sWorldMapPtr->bgPos.x, sWorldMapPtr->bgPos.y);
    AnimateSprites(TRUE);
    FadeScreen();
    sub_8005838(NULL, 0);
    nullsub_8(gGameOptionsRef->unkA);
    sub_8005180();
    sub_80060EC();
    IncrementPlayTime(gPlayTimeRef);
    WaitForNextFrameAndAdvanceRNG();
    LoadBufferedInputs();
    CopySpritesToOam();
    sub_8005304();
    TransferBGPaletteBuffer();
    xxx_call_update_bg_vram();
    nullsub_24();
    DoScheduledMemCopies();
    xxx_call_update_bg_sound_input();
    UpdateSoundEffectCounters();
    ResetSprites(FALSE);
}

static bool8 FadeScreen(void)
{
    bool8 ret = FALSE;

    if (sWorldMapPtr->brightness < 31) {
        s32 i;
        RGB *color = (void *) sWorldMapPtr->unk1100[0]->data;

        if (++sWorldMapPtr->brightness >= 31) {
            sWorldMapPtr->brightness = 31;
        }

        for (i = 0; i < 224; color++, i++) {
            SetBGPaletteBufferColorRGB(i, color, sWorldMapPtr->brightness, NULL);
        }

        color = (void *) sWorldMapPtr->unk1100[1]->data;
        for (i = 0; i < 240; color++, i++) {
            SetBGPaletteBufferColorRGB(i + 256, color, sWorldMapPtr->brightness, NULL);
        }

        ret = TRUE;
    }

    return ret;
}

static void AnimateSprites(bool8 a0)
{
    s32 i;
    unkStruct_2039DB0 var_2C;
    DungeonPos pos;

    sub_8004E8C(&var_2C);
    var_2C.unk4 = 0xF3FF;
    var_2C.unkA = 0x800;
    pos = sWorldMapPtr->bgPos;
    RunAxAnimationFrame(&sWorldMapPtr->monAxSprite);
    if (a0) {
        DoAxFrame_800558C(&sWorldMapPtr->monAxSprite, sWorldMapPtr->monSpritePos.x - pos.x, sWorldMapPtr->monSpritePos.y - pos.y, 3, sWorldMapPtr->unk52D4, &var_2C);
    }

    for (i = 0; i < 64; i++) {
        struct UnkStruct_Sub1 *structPtr = &sWorldMapPtr->unk0[i];
        if (structPtr->unk0) {
            axdata *axPtr = &structPtr->unk8;

            RunAxAnimationFrame(axPtr);
            if (a0) {
                DoAxFrame_800558C(axPtr, structPtr->unk4.x - pos.x, structPtr->unk4.y - pos.y, 1, 0, &var_2C);
            }
        }
    }
}

static void PrintDungeonName(DungeonLocation *dungLocation)
{
    WindowTemplates windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_NORMAL,
                .pos = {12, 2},
                .width = 16,
                .height = 2,
                .unk10 = 2,
            },
            [1] = WIN_TEMPLATE_DUMMY,
            [2] = WIN_TEMPLATE_DUMMY,
            [3] = WIN_TEMPLATE_DUMMY,
        }
    };

    if (sWorldMapPtr->monSpritePos.y - sWorldMapPtr->bgPos.y <= 80) {
        windows.id[0].pos.y = 17;
    }
    else {
        windows.id[0].pos.y = 1;
    }

    ShowWindows(&windows, TRUE, TRUE);
    sub_80073B8(0);
    CopyDungeonName1toBuffer(gFormatBuffer_Monsters[0], dungLocation);
    PrintFormattedStringOnWindow(12, 2, _("{CENTER_ALIGN}{POKEMON_0}"), 0, '\0');
    sub_80073E0(0);
}

static void PrintDialogueMessage_Async(const u8 *text)
{
    s32 i, a;

    CreateMenuDialogueBoxAndPortrait(text, NULL, 0, NULL, NULL, 3, 0, NULL, 0x301);

    do {
        DrawDialogueBoxString();
        WorldMap_RunFrameActions();
    } while (sub_80144A4(&a) != 0);

    for (i = 0; i < 10; i++)
        WorldMap_RunFrameActions();
}

static bool8 PlayerEnterDungeonPrompt_Async(u8 *str)
{
    s32 height, i;
    MenuInputStruct menuInput;

    height = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            height += 12;
    }
    height += 11;
    height /= 8;

    sWorldMapWindows.id[0].pos.y = 19 - height;
    sWorldMapWindows.id[0].unk10 = height;
    sWorldMapWindows.id[0].height = height;
    sWorldMapWindows.id[1].pos.y = 14 - height;
    ShowWindows(&sWorldMapWindows, TRUE, TRUE);

    sub_80073B8(0);
    PrintFormattedStringOnWindow(4, 0, str, 0, '\0');
    sub_80073E0(0);

    sub_80073B8(1);
    PrintFormattedStringOnWindow(10, 0, "Yes", 1, '\0');
    PrintFormattedStringOnWindow(10, 12, "No", 1, '\0');
    sub_80073E0(1);

    menuInput.menuIndex = 1;
    menuInput.currPageEntries = 2;
    menuInput.entriesPerPage = 2;
    menuInput.currPage = 0;
    menuInput.pagesCount = 0;
    menuInput.unk4 = 0;
    menuInput.firstEntryY = 0;
    menuInput.windowId = 1;
    menuInput.leftRightArrowsPos.x = 0;
    menuInput.leftRightArrowsPos.y = 0;
    menuInput.unk14.x = 0;
    menuInput.unk14.y = 0;
    menuInput.cursorArrowPos.x = 8;
    menuInput.cursorArrowPos.y = 8;
    sub_80137B0(&menuInput, 24);
    ResetTouchScreenMenuInput(&menuInput.touchScreen);

    while (TRUE) {
        AddMenuCursorSprite(&menuInput);
        WorldMap_RunFrameActions();

        if (gRealInputs.repeated & DPAD_DOWN) {
            MoveMenuCursorDown(&menuInput);
            PlayCursorUpDownSoundEffect();
        }
        if (gRealInputs.repeated & DPAD_UP) {
            MoveMenuCursorUp(&menuInput);
            PlayCursorUpDownSoundEffect();
        }
        if ((gRealInputs.pressed & A_BUTTON) || menuInput.touchScreen.a_button) {
            PlayAcceptSoundEffect();
            break;
        }
    }

    if (menuInput.menuIndex == 0)
        return TRUE; // Yes
    return FALSE;
}

static UNUSED void GetDungeonCoords(u8 id, DungeonPos *pos)
{
    pos->x = gDungeonCoordinates[id].x;
    pos->y = gDungeonCoordinates[id].y;
}
