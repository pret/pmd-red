#include "global.h"
#include "globaldata.h"
#include "constants/bg_music.h"
#include "constants/main_menu.h"
#include "structs/str_dungeon_setup.h"
#include "bg_control.h"
#include "bg_palette_buffer.h"
#include "code_800558C.h"
#include "graphics_memory.h"
#include "code_800C9CC.h"
#include "code_800D090_1.h"
#include "music_util.h"
#include "run_dungeon.h"
#include "code_8094F88.h"
#include "code_80958E8.h"
#include "code_8097670.h"
#include "code_8099360.h"
#include "code_80A26CC.h"
#include "cpu.h"
#include "debug.h"
#include "def_filearchives.h"
#include "event_flag.h"
#include "exclusive_pokemon.h"
#include "friend_area.h"
#include "game_options.h"
#include "ground_main.h"
#include "main_loops.h"
#include "main_menu1.h"
#include "main_menu2.h"
#include "memory.h"
#include "moves.h"
#include "music.h"
#include "play_time.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "quick_save_read.h"
#include "quick_save_write.h"
#include "random.h"
#include "rescue_team_info.h"
#include "save.h"
#include "save_read.h"
#include "sprite.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"
#include "text_3.h"
#include "text_util.h"
#include "decompress_at.h"
#include "world_map.h"
#include "friend_areas_map.h"
#include "structs/str_dungeon_setup.h"
#include "constants/friend_area.h"
#include "constants/ground_map.h"

typedef struct unkTalkTable
{
    u32 unk0;
    s16 species;
} unkTalkTable;

static EWRAM_DATA s32 sTitleBrightness = 0; // NDS=210FAC0
// TODO: I think there's a 2nd s32 here for the bottom screen TitleBrightness.

static EWRAM_INIT OpenedFile *sTitlePaletteFile = NULL;
static EWRAM_INIT u32 sUnknown_203B03C = 0;
static EWRAM_INIT PersonalityRelated sPersonalityRelated_203B040 = {
    .unk0 = 0,
    .StarterID = MONSTER_CHARMANDER,
    .PartnerID = MONSTER_SQUIRTLE,
    .StarterName = {""},
    .PartnerNick = {""},
};

static void LoadTitleScreen(void);
static void NDS_LoadOverlay_GroundMain();
static u32 RunGameMode_Async(u32 param_1);
static void sub_80011CC(DungeonSetupSubstruct *info, u8 dungId);
static void sub_80011E8(DungeonSetupSubstruct *info);
static void LoadAndRunQuickSaveDungeon_Async(DungeonSetupStruct *param_1);
static u8 sub_8001170(void);
static void RemoveMoneyAndRandomItems(void);
static void RemoveAllMoneyAndItems(void);
static void LoadAndRunDungeon_Async(DungeonSetupStruct *r0);
static u32 xxx_script_related_8001334(u32 r0);
static void MainLoops_RunFrameActions(u32 unused);

extern u8 sub_80990EC(DungeonSetupInfo *param_1, s32 param_2);
extern bool8 sub_8096A08(u8 dungeon, Pokemon *pokemon);
extern u8 sub_80991E0(DungeonSetupInfo *param_1,short *param_2);
extern u32 xxx_script_related_8098468(u32);
extern void IncrementNumAdventures(void);
extern void sub_8096BD0(void);
extern bool8 IsEnterWithoutGameSave(u8 dungeon);

static const unkTalkTable sBaseKindTable[17] = {
    [0] = { .unk0 = 0, .species = MONSTER_PIKACHU },
    [1] = { .unk0 = 1, .species = MONSTER_MEOWTH },
    [2] = { .unk0 = 2, .species = MONSTER_EEVEE },
    [3] = { .unk0 = 3, .species = MONSTER_SKITTY },
    [4] = { .unk0 = 4, .species = MONSTER_SQUIRTLE },
    [5] = { .unk0 = 5, .species = MONSTER_TOTODILE },
    [6] = { .unk0 = 6, .species = MONSTER_MUDKIP },
    [7] = { .unk0 = 7, .species = MONSTER_PSYDUCK },
    [8] = { .unk0 = 8, .species = MONSTER_CHARMANDER },
    [9] = { .unk0 = 9, .species = MONSTER_TORCHIC },
    [10] = { .unk0 = 10, .species = MONSTER_CYNDAQUIL },
    [11] = { .unk0 = 11, .species = MONSTER_CUBONE },
    [12] = { .unk0 = 12, .species = MONSTER_MACHOP },
    [13] = { .unk0 = 13, .species = MONSTER_BULBASAUR },
    [14] = { .unk0 = 14, .species = MONSTER_CHIKORITA },
    [15] = { .unk0 = 15, .species = MONSTER_TREECKO },
    [16] = { .unk0 = 0, .species = MONSTER_NONE },
};

static const unkTalkTable sTalkKindTable[5] = {
    [0] = { .unk0 = 1, .species = MONSTER_SQUIRTLE },
    [1] = { .unk0 = 1, .species = MONSTER_TOTODILE },
    [2] = { .unk0 = 3, .species = MONSTER_TORCHIC },
    [3] = { .unk0 = 3, .species = MONSTER_CHIKORITA },
    [4] = { .unk0 = 2, .species = MONSTER_NONE },
};

// arm9.bin::0200E0A8
void GameLoop(void)
{
    u32 tmp;
    u8 tmp3 = 1;
    u32 nextMenu;
    u32 flag;

    InitHeap();
    NDS_DebugInit();
    ResetSoundEffectCounters();
    NDS_LoadOverlay_GroundMain();
    sub_8014144();
    LoadMonsterParameters();
    sub_8097670();
    InitializePlayTime();
    LoadGameOptions();
    SetWindowBGColor();
    LoadExclusivePokemon();
    LoadFriendAreas();
    LoadItemParameters();
    LoadRescueTeamInfo();
    LoadWazaParameters();
    sub_80950BC();
    LoadMailInfo();
    sub_800CD64(0x8000, FALSE);
    sub_8012284();
    InitializeGameOptions(TRUE);
    SetWindowTitle(_("PKDi ver 1.0 [Apr 28 2006] 16:37:54"));
    sub_800DAAC();
    SetSavingIconCoords(NULL);

    tmp = 0;
    if (ReadSaveFromPak(&tmp))
        ThoroughlyResetScriptVars();

    xxx_script_related_8001334(14);
    xxx_script_related_8001334(15);
    ClearScriptVarArray(NULL, EVENT_LOCAL);
    xxx_script_related_8001334(16);

    if (GetScriptVarValue(NULL, EVENT_LOCAL) == 0)
        xxx_script_related_8001334(17);

    while (TRUE) {
        sUnknown_203B03C = 0;
        sub_800A8F8(2);
        ResetSprites(TRUE);
        UpdateFadeInTile(0);
        InitFontPalette();
        sub_800CDA8(2);
        ShowWindows(NULL, TRUE, TRUE);
        gUnknown_2026E4E = 0x1000;
        LoadTitleScreen();
        SetBG2RegOffsets(0, 0);
        SetBG3RegOffsets(0, 0);

        sTitleBrightness = 0;
        while (sTitleBrightness < 32) {
            s32 i;

            sTitleBrightness++;

            for (i = 0; i < 240; i++) {
                SetBGPaletteBufferColorRGB(i, &((RGB*)sTitlePaletteFile->data)[i], sTitleBrightness, NULL);
            }

            MainLoops_RunFrameActions(0);
        }

        if (tmp3) {
            PrepareSavePakRead();
            while ((tmp3 = ReadSavePak()))
                MainLoops_RunFrameActions(0);
            FinishReadSavePak();
        }

        tmp3 = 1;
        StartNewBGM(MUS_FILE_SELECT);
        flag = TRUE;
        sub_80095CC(0, 20);
        InitMainMenu();

        while (TRUE) {
            if (sub_80363E0()) {
                if (gRealInputs.pressed & L_BUTTON) {
                    flag = FALSE;
                    SetBGOBJEnableFlags(19);
                }
                else if (!flag && !(gRealInputs.held & L_BUTTON)) {
                    flag = TRUE;
                    SetBGOBJEnableFlags(0);
                }

                if (!flag) {
                    MainLoops_RunFrameActions(0);
                    continue;
                }
            }

            SetUpMenu();
            MainLoops_RunFrameActions(0);
            nextMenu = UpdateMenu();
            CleanUpMenu();

            if (nextMenu == 2)
                break;
            if (nextMenu == 4)
                break;
            if (nextMenu == MENU_NEW_GAME)
                break;
        }

        DeleteMainMenu();

        while (sTitleBrightness > 0) {
            s32 i;

            sTitleBrightness--;

            for (i = 0; i < 240; i++) {
                SetBGPaletteBufferColorRGB(i, &((RGB*)sTitlePaletteFile->data)[i], sTitleBrightness, NULL);
            }

            MainLoops_RunFrameActions(0);
        }

        CloseFile(sTitlePaletteFile);

        switch (nextMenu) {
            case 2: {
                s32 mailIndex = GetFirstIndexofMailType(7);
                if (mailIndex != -1) {
                    DeleteMailAtIndex(mailIndex);
                    tmp3 = RunGameMode_Async(2);
                }
                else
                    tmp3 = RunGameMode_Async(1);

                break;
            }
            case 4: {
                tmp3 = RunGameMode_Async(3);
                break;
            }
            case MENU_NEW_GAME: {
                sub_80122A8();
                nullsub_33();
                tmp3 = RunGameMode_Async(0);
                break;
            }
        }

    }
}

// arm9.bin::0200E02C
static void MainLoops_RunFrameActions(u32 unused)
{
    DrawDialogueBoxString();
    sub_8005838(NULL, 0);
    nullsub_8(gGameOptionsRef->unkA);

    sub_8005180();
    // Extra call here in blue. Seems to be for 2nd screen sprites

    sub_80060EC();
    UpdateSoundEffectCounters();
    WaitForNextFrameAndAdvanceRNG();
    LoadBufferedInputs();

    CopySpritesToOam();
    sub_8005304();
    // 2 extra calls here in blue. They seem to be copies of the 2 above funcs, but for 2nd screen sprites

    TransferBGPaletteBuffer();
    xxx_call_update_bg_vram();
    DoScheduledMemCopies();
    xxx_call_update_bg_sound_input();

    ResetSprites(FALSE);
    // Extra call here in blue. Seems to be for 2nd screen sprites
}

typedef struct TitleMenuFile
{
    /* 0x0 */ u16 tilemap[2 * 32 * 32];
    /* 0x1000 */ u8 vramStuff[0x4B20];
} TitleMenuFile;

static void LoadTitleScreen(void)
{
    const u8 * renBG[3] = {"titlen0", "titlen1", "titlen2"};
    const u8 * renPal[3] = {"titlen0p", "titlen1p", "titlen2p"};
    OpenedFile *bgFile;
    s32 i, j;
    TitleMenuFile *stru = MemoryAlloc(sizeof(TitleMenuFile), 0);
    s32 rnd = RandInt(3);

    sTitlePaletteFile = OpenFileAndGetFileDataPtr(renPal[rnd], &gTitleMenuFileArchive);
    bgFile = OpenFileAndGetFileDataPtr(renBG[rnd], &gTitleMenuFileArchive);
    DecompressATFile(&stru->tilemap, 0, bgFile);

    for (i = 0; i < 32; i++) {
        for (j = 0; j < 32; j++) {
            u16 *ptr = stru->tilemap;
            gBgTilemaps[2][i][j] = ptr[i * 32 + j];
            gBgTilemaps[3][i][j] = ptr[i * 32 + j + (32 * 32)];
        }
    }

    ScheduleBgTilemapCopy(2);
    ScheduleBgTilemapCopy(3);

    CpuCopy((u32 *)(VRAM + 0x8000), stru->vramStuff, sizeof(stru->vramStuff));
    CloseFile(bgFile);
    MemoryFree(stru);
}

#include "data/main_loops.h"

// arm9.bin::0200ED08
s32 sub_8000728(void)
{
    return sUnknown_203B03C;
}

// arm9.bin::0200DB58
static void QuickSave_Async(u32 mode)
{
    s32 saveStatus;
    s32 counter;

    saveStatus = 0;
    counter = 0;
    UpdateFadeInTile(0);
    sub_8014144();
    InitFontPalette();
    sub_800CDA8(2);
    sub_80095CC(0, 20);
    ShowWindows(NULL, TRUE, TRUE);
    sub_8009408(0, 20);
    gUnknown_2026E4E = 0x1000;
    sub_8099648();
    SetWindowBGColor();
    sub_8099690(0);
    sub_8099744();
    sub_8099750();
    SetCharacterMask(3);
    sub_8005838(NULL, 0);
    sub_80060EC();
    CreateDialogueBoxAndPortrait(sSaveTextQuicksaving, 0, 0, 0x20);

    while (TRUE) {
        MainLoops_RunFrameActions(0);

        if (saveStatus < SAVE_COMPLETED) {
            sub_8014490();
            MainLoops_RunFrameActions(0);
            ShowWindows(NULL, TRUE, TRUE);
            MainLoops_RunFrameActions(0);
            break;
        }

        switch (saveStatus) {
            case SAVE_COMPLETED: {
                s32 local_18 = 0;
                DungeonLocation dl = { .id = DUNGEON_OUT_ON_RESCUE, .floor = 0 };

                SetDungeonLocationInfo(&dl);

                sub_80140DC();
                if (mode < 4)
                    saveStatus = WriteSavetoPak(&local_18, 1);
                else
                    saveStatus = SAVE_FAILED;

                if (saveStatus == SAVE_COMPLETED)
                    saveStatus = sub_80121E0(0xF1206);

                sub_8014114();

                if (saveStatus == SAVE_COMPLETED) {
                    switch (mode) {
                        case 1:
                        case 3: {
                            CreateDialogueBoxAndPortrait(sSaveTextYourAdventureHasBeenSaved, 0, 0, 0x321);
                            counter = 60;
                            saveStatus = SAVE_NOT_WRTTEN;
                            break;
                        }
                        case 0:
                        case 2:
                        default: {
                            CreateDialogueBoxAndPortrait(sSaveTextYourAdventureHasBeenSavedLong, 0, 0, 0x321);
                            counter = 60;
                            saveStatus = SAVE_NOT_WRTTEN;
                            break;
                        }
                    }
                }
                else if (saveStatus == SAVE_NOT_WRTTEN) {
                    CreateDialogueBoxAndPortrait(sSaveTextTheDataCouldNotBeWritten, 0, 0, 0);
                    saveStatus = SAVE_UNK3;
                }
                else {
                    CreateDialogueBoxAndPortrait(sSaveTextFailed, 0, 0, 0x301);
                    saveStatus = SAVE_FAILED;
                }
                break;
            }
            case SAVE_NOT_WRTTEN: {
                if (counter < 1)
                    saveStatus = SAVE_FAILED;
                else {
                    u16 pressed = gRealInputs.pressed;
                    counter--;
                    if (pressed & 3)
                        saveStatus = SAVE_FAILED;
                }
                break;
            }
            case SAVE_FAILED: {
                s32 temp;

                if (sub_80144A4(&temp) == 0)
                    saveStatus = SAVE_NO_STATUS;
                break;
            }
            case SAVE_UNK3: {
                break;
            }
            default: {
                saveStatus = SAVE_NO_STATUS;
                break;
            }
        }
    }
}

// arm9.bin::0200D998
static void sub_80008C0_Async(u32 errorKind)
{
    s32 saveStatus = SAVE_COMPLETED;
    s32 counter = 0;

    UpdateFadeInTile(0);
    sub_8014144();
    InitFontPalette();
    sub_800CDA8(2);
    sub_80095CC(0, 20);
    ShowWindows(NULL, TRUE, TRUE);
    sub_8009408(0, 20);
    gUnknown_2026E4E = 0x1000;
    sub_8099648();
    SetWindowBGColor();
    sub_8099690(0);
    sub_8099744();
    sub_8099750();
    SetCharacterMask(3);

    switch (errorKind) {
        case 0: {
            CreateDialogueBoxAndPortrait(sSaveTextError, 0, 0, 0x20);
            saveStatus = SAVE_FAILED;
            break;
        }
        case 1: {
            CreateDialogueBoxAndPortrait(sSaveTextCantResume, 0, 0, 0x301);
            saveStatus = SAVE_NOT_WRTTEN;
            break;
        }
        case 2: {
            CreateDialogueBoxAndPortrait(sSaveTextMayNotResume, 0, 0, 0x301);
            saveStatus = SAVE_NOT_WRTTEN;
            break;
        }
        case 3: {
            CreateDialogueBoxAndPortrait(sSaveTextMayNotResume, 0, 0, 0x301);
            saveStatus = SAVE_NOT_WRTTEN;
            break;
        }
    }

    while (TRUE) {
        MainLoops_RunFrameActions(0);

        if (saveStatus < 0)
            break;

        switch (saveStatus) {
            case 0: {
                if (counter <= 0)
                    saveStatus = SAVE_NOT_WRTTEN;
                else {
                    u16 pressed = gRealInputs.pressed;
                    counter--;
                    if (pressed & 3)
                        saveStatus = SAVE_NOT_WRTTEN;
                }
                break;
            }
            case 1: {
                s32 temp;
                if (sub_80144A4(&temp) == 0)
                    saveStatus = SAVE_NO_STATUS;
                break;
            }
            case 2: {
                break;
            }
            default: {
                saveStatus = SAVE_NO_STATUS;
                break;
            }
        }
    }

    sub_8014490();
    MainLoops_RunFrameActions(0);
    ShowWindows(NULL ,TRUE, TRUE);
    MainLoops_RunFrameActions(0);
}

enum
{
    MODE_NEW_GAME,
    MODE_CONTINUE_GAME,
    MODE_GROUND, // overworld
    MODE_3,
    MODE_FRIEND_AREAS,
    MODE_DUNGEON_FROM_WORLD_MAP,
    MODE_6,
    MODE_CONTINUE_QUICKSAVE,
    MODE_8,
    MODE_DUNGEON_WON,
    MODE_10,
    MODE_11,
    MODE_DUNGEON_LOST,
};

// arm9.bin::0200D1E0
static u32 RunGameMode_Async(u32 a0)
{
    s32 mode = GetScriptVarValue(NULL, START_MODE);
    bool8 ret = FALSE;

    ResetSoundEffectCounters();
    FadeOutAllMusic(0x10);
    if (mode == MODE_CONTINUE_QUICKSAVE) {
        if (a0 == 2) {
            mode = MODE_8;
        }
        else if (a0 == 3) {
            mode = MODE_11;
            SetScriptVarValue(NULL, START_MODE, 11);
            sub_8096BD0();
            QuickSave_Async(3);
        }
    }
    else if (mode != MODE_NEW_GAME && mode != MODE_11) {
        mode = MODE_CONTINUE_GAME;
    }

    ClearScriptVarArray(NULL, EVENT_S08E01);
    while (1) {
        s32 r5;
        struct FriendAreasMapSetupStruct friendAreasSetup;
        struct WorldMapSetupStruct worldMapSetup;
        DungeonSetupStruct dungeonSetup;
        s16 sp552;

        if (mode == MODE_FRIEND_AREAS) {
            u8 friendAreaId = MapIdToFriendAreaId(GetScriptVarValue(NULL,GROUND_ENTER));

            friendAreasSetup.friendAreasMapPtr = MemoryAlloc(sizeof(*friendAreasSetup.friendAreasMapPtr),8);
            friendAreasSetup.startingFriendAreaId = friendAreaId;
            friendAreasSetup.unk5 = sub_80023E4(9);
            ShowFriendAreasMap_Async(&friendAreasSetup);
            MemoryFree(friendAreasSetup.friendAreasMapPtr);
            if (friendAreasSetup.chosenAreaId != NUM_FRIEND_AREAS) {
                s32 mapId;
                u32 areaId = friendAreasSetup.chosenAreaId;
                if (areaId != FRIEND_AREA_NONE) {
                    mapId = FriendAreaIdToMapId(areaId);
                }
                else {
                    mapId = MAP_TEAM_BASE;
                }
                SetScriptVarValue(NULL,GROUND_ENTER,mapId);
                SetScriptVarValue(NULL,GROUND_ENTER_LINK,0);
            }
            mode = MODE_GROUND;
            continue;
        }
        else if (mode == MODE_DUNGEON_FROM_WORLD_MAP) {
            s32 i;

            s32 dungId = (s16) GetScriptVarValue(NULL, DUNGEON_SELECT);
            u8 r6 = sub_80A2740(dungId);
            for (i = 0; i < WORLD_MAP_UNK_6D_COUNT; i++) {
                worldMapSetup.info.unk6D[i] = sub_80A28F0(i);
            }

            if (r6 == 99) {
                mode = MODE_GROUND;
                continue;
            }

            worldMapSetup.info.startLocation.id = DUNGEON_OUT_ON_RESCUE;
            sub_80011CC(&worldMapSetup.info.unk4, r6);
            worldMapSetup.info.unk6C = worldMapSetup.info.unk4.unk5;
            switch ((s16) sub_80A2750(dungId)) {
                case 1:
                    if (sub_80990EC(&dungeonSetup.info, dungId)) {
                        worldMapSetup.info.unk4.unkC = dungeonSetup.info.sub0.unkC;
                        worldMapSetup.info.mon = dungeonSetup.info.mon;
                    }
                    break;
                case 2:
                    if (sub_8096A08(worldMapSetup.info.unk4.unk0.id, &worldMapSetup.info.mon)) {
                        worldMapSetup.info.unk4.unkC = 1;
                    }
                    else {
                        worldMapSetup.info.unk4.unkC = 0;
                    }
                    break;
            }

            worldMapSetup.worldMap = MemoryAlloc(sizeof(*worldMapSetup.worldMap), 8);
            ShowWorldMap_Async(&worldMapSetup);
            MemoryFree(worldMapSetup.worldMap);
            if (!worldMapSetup.dungeonEntered) {
                mode = MODE_GROUND;
                continue;
            }
            SetScriptVarValue(NULL, DUNGEON_ENTER, dungId);
            sUnknown_203B03C = 2;
            sub_800A8F8(4);
            r5 = xxx_script_related_8001334(5);
        }
        else if (mode == MODE_8) {
            r5 = 0;
        }
        else if (mode == MODE_CONTINUE_QUICKSAVE) {
            r5 = 2;
        }
        else {
            if (mode == MODE_11) {
                RemoveAllMoneyAndItems();
            }
            else if (mode == MODE_DUNGEON_LOST) {
                RemoveMoneyAndRandomItems();
            }
            sUnknown_203B03C = 2;
            sub_800A8F8(4);
            r5 = xxx_script_related_8001334(mode);
            if (r5 == 14) {
                break;
            }
            else if (r5 == 5) {
                mode = MODE_FRIEND_AREAS;
                continue;
            }
            else if (r5 == 6) {
                mode = MODE_DUNGEON_FROM_WORLD_MAP;
                continue;
            }
        }

        dungeonSetup.info.sub0.unkD = 0;
        dungeonSetup.info.sub0.unkC = 0;
        MemoryFill8(&dungeonSetup.info.mon, 0, sizeof(dungeonSetup.info.mon));
        dungeonSetup.info.mon.speciesNum = 0;
        if (r5 == 7) {
            if (!sub_80991E0(&dungeonSetup.info, &sp552)) {
                r5 = 13;
                mode = MODE_DUNGEON_WON;
            }
        }
        else if (r5 == 8) {
            if (!sub_80991E0(&dungeonSetup.info, &sp552)) {
                r5 = 13;
                mode = MODE_DUNGEON_WON;
            }
            else if (sub_8096A08(dungeonSetup.info.sub0.unk0.id, &dungeonSetup.info.mon)) {
                dungeonSetup.info.sub0.unkC = 1;
            }
        }
        else if (r5 == 10) {
            if (!sub_80991E0(&dungeonSetup.info, &sp552)) {
                r5 = 13;
                mode = MODE_DUNGEON_WON;
            }
        }
        else if (r5 == 9) {
            if (!sub_80991E0(&dungeonSetup.info, &sp552)) {
                r5 = 11;
                mode = MODE_DUNGEON_LOST;
            }
        }
        else if (r5 == 0) {
            u32 var = sub_8011FA8();
            if (var == 0xF1207) {
                dungeonSetup.info.sub0.unkD = 1;
                dungeonSetup.info.sub0.unk4 = 1;
                dungeonSetup.info.sub0.unkB = 0;
                if (gUnknown_203B484->unk4.speciesNum != 0) {
                    dungeonSetup.info.sub0.unkC = 1;
                    dungeonSetup.info.mon = gUnknown_203B484->unk4;
                }
                else {
                    dungeonSetup.info.sub0.unkC = 0;
                }
                MemoryFill8(&gUnknown_203B484->unk4, 0, sizeof(gUnknown_203B484->unk4));
                gUnknown_203B484->unk4.speciesNum = 0;
            }
            else if (var == 0xF1208) {
                r5 = 1;
                mode = MODE_11;
                sub_8096BD0();
            }
            else {
                r5 = 1;
                mode = MODE_11;
                sub_8096BD0();
            }

            if (r5 == 1) {
                MemoryFill8(&gUnknown_203B484->unk4, 0, sizeof(gUnknown_203B484->unk4));
                gUnknown_203B484->unk4.speciesNum = 0;
            }
        }
        else if (r5 == 2) {
            if (sub_8011C1C() == 2) {
                u32 var = sub_8011FA8();
                dungeonSetup.info.sub0.unk4 = 1;
                dungeonSetup.info.sub0.unkD = 0;
                if (var == 0xF1207) {
                    ;
                }
                else if (var == 0xF1208) {
                    r5 = 1;
                    mode = MODE_11;
                    sub_8096BD0();
                }
                else {
                    r5 = 1;
                    mode = MODE_11;
                    sub_8096BD0();
                }
            }
            else {
                r5 = 3;
            }

            if (r5 == 3) {
                u8 r4 = sub_8001170();
                r5 = 1;
                mode = MODE_11;
                sub_8096BD0();
                if (r4 != 63 && r4 != 99 && IsEnterWithoutGameSave(r4)) {
                    if (sub_8011C1C() == 2) {
                        r5 = 3;
                        mode = MODE_CONTINUE_QUICKSAVE;
                    }
                    else {
                        r5 = 12;
                        mode = MODE_10;
                    }
                }

                if (r5 == 1) {
                    sub_8011C1C();
                }
            }
            else if (r5 == 4) {
                r5 = 1;
                mode = MODE_11;
                sub_8096BD0();
                sub_80008C0_Async(1);
            }
            else if (r5 == 1) {
                mode = MODE_11;
                sub_8096BD0();
            }
        }

        if (r5 == 7 || r5 == 8 || r5 == 9 || r5 == 10 || r5 == 0 || r5 == 2 || r5 == 3) {
            if (r5 != 0 && r5 != 2 && r5 != 3) {
                u8 r6 = sub_8001170();

                IncrementNumAdventures();
                if (r5 == 9) {
                    u8 sp554;

                    if (sub_8099394(&sp554)) {
                        unkStruct_203B480 *mail = GetMailatIndex(sp554);
                        mail->rescuesAllowed = (mail->rescuesAllowed > 1) ? mail->rescuesAllowed - 1 : 0;
                    }
                }

                if (r6 == 63) {
                    QuickSave_Async(0);
                }
                else if (!IsEnterWithoutGameSave(r6)) {
                    QuickSave_Async(0);
                }
            }

            sUnknown_203B03C = 1;
            sub_800A8F8(3);
            dungeonSetup.unk0 = 1;
            sub_80011E8(&dungeonSetup.info.sub0);
            LoadAndRunQuickSaveDungeon_Async(&dungeonSetup);
            if (dungeonSetup.info.unk7C == 3) {
                ret = TRUE;
                break;
            }
            if (dungeonSetup.info.unk7C == -2) {
                ret = TRUE;
                break;
            }

            ClearScriptVarArray(NULL, EVENT_S08E01);
            switch (dungeonSetup.info.unk7C) {
                case 1:
                case 4:
                    mode = MODE_DUNGEON_WON;
                    SetScriptVarArrayValue(NULL, EVENT_S08E01, 0, (dungeonSetup.info.unk7E != 0) ? 2 : 1);
                    break;
                case 2:
                    mode = MODE_10;
                    break;
                case -1:
                    mode = MODE_DUNGEON_LOST;
                    sub_8096BD0();
                    break;
                case 5:
                    mode = MODE_11;
                    sub_8096BD0();
                    break;
                default:
                    mode = MODE_11;
                    sub_8096BD0();
                    break;
            }
        }
    }

    return ret;
}

// This func is probably used for running the dungeon in general (and updating RNG mechanics), not just quicksave.
// More documentation needed to be sure
// It'd also be cool to see what happens if a quicksave load fails and the dungeon is skipped entirely
// arm9.bin::0200D01C
static void LoadAndRunQuickSaveDungeon_Async(DungeonSetupStruct *setupStr)
{
    u8 quickSaveValid;
    s32 quickSaveStatus;
    s32 local_1c; // 0x4800
    s32 dungeonStructSize; // sizeof(Dungeon)

    quickSaveValid = TRUE;
    sUnknown_203B03C = 1;

    sub_800A8F8(3);
    sub_8014144();
    sub_8043D50(&local_1c, &dungeonStructSize);

    setupStr->info.unk74 = MemoryAlloc(local_1c, 7); // size: 0x4800
    setupStr->info.dungeon = MemoryAlloc(dungeonStructSize, 7); // size: sizeof(Dungeon)

    if (setupStr->info.sub0.unk4) {
        PrepareQuickSaveRead(setupStr->info.unk74, local_1c);

        while (TRUE) {
            if (!ReadQuickSave())
                break;
            MainLoops_RunFrameActions(0);
        }

        quickSaveValid = IsQuickSaveValid();
        FinishQuickSaveRead();
        StopBGMResetSoundEffectCounters();

        if (quickSaveValid)
            sub_80121E0(0xF1208);
        else
            sub_80121E0(0xF1209);

        StartBGMusic();
    }
    else {
        GeneratePelipperJobs();
        sub_80961B4();
        sub_808ED00();
    }

    if (quickSaveValid) {
        LoadAndRunDungeon_Async(setupStr);
        sub_8099648();
        SetWindowBGColor();
        sub_8099690(0);
    }
    else
        setupStr->info.unk7C = 5;

    if (setupStr->info.unk7C == -2)
        sub_809542C(&setupStr->info.unk84);

    if (setupStr->info.unk7C == 3 || setupStr->info.unk7C == -2) {
        SetDungeonLocationInfo(&setupStr->info.unk80);
        StopBGMusic();

        if (setupStr->info.unk7C == -2)
            PrepareQuickSaveWrite(setupStr->info.unk74, local_1c, 1);
        else
            PrepareQuickSaveWrite(setupStr->info.unk74, local_1c, 0);

        while ((quickSaveStatus = WriteQuickSave(), (quickSaveStatus != 2))) {
            if (quickSaveStatus == 3)
                break;
            if (quickSaveStatus == 1) {
                MemoryFree(setupStr->info.dungeon);
                MemoryFree(setupStr->info.unk74);
            }

            MainLoops_RunFrameActions(0);
        }
        FinishQuickSaveWrite();
    }
    else {
        sub_808ED00();
        MemoryFree(setupStr->info.dungeon);
        MemoryFree(setupStr->info.unk74);
    }
}

// arm9.bin::0200CFF4
void sub_8001024(PersonalityRelated *dst)
{
    *dst = sPersonalityRelated_203B040;
}

// arm9.bin::0200CFA4
void sub_8001044(PersonalityRelated *src)
{
    sPersonalityRelated_203B040 = *src;
}

// arm9.bin::0200CE48
void sub_8001064(void)
{
    const unkTalkTable *psVar2;
    u8 buffer2 [20];
    u8 buffer1 [20];

    if (GetPlayerPokemonStruct() == NULL) {
        if (sPersonalityRelated_203B040.StarterName[0] == '\0') {
            CopyMonsterNameToBuffer(buffer1, sPersonalityRelated_203B040.StarterID);
            CopyStringtoBuffer(buffer2, buffer1);
            sub_808CE74(sPersonalityRelated_203B040.StarterID, TRUE, buffer2);
        }
        else
            sub_808CE74(sPersonalityRelated_203B040.StarterID, TRUE, sPersonalityRelated_203B040.StarterName);
    }

    if (sub_808D378() == NULL) {
        if (sPersonalityRelated_203B040.PartnerNick[0] == '\0') {
            CopyMonsterNameToBuffer(buffer1, sPersonalityRelated_203B040.PartnerID);
            CopyStringtoBuffer(buffer2, buffer1);
            sub_808CE74(sPersonalityRelated_203B040.PartnerID, FALSE, buffer2);
        }
        else
            sub_808CE74(sPersonalityRelated_203B040.PartnerID, FALSE, sPersonalityRelated_203B040.PartnerNick);
    }

    if (sPersonalityRelated_203B040.StarterID != MONSTER_NONE) {
        psVar2 = &sBaseKindTable[0];
        while (psVar2->species != MONSTER_NONE && sPersonalityRelated_203B040.StarterID != psVar2->species) {
            psVar2++;
        }
        SetScriptVarValue(NULL, BASE_KIND, psVar2->unk0);
    }

    if (sPersonalityRelated_203B040.PartnerID != MONSTER_NONE) {
        psVar2 = &sTalkKindTable[0];
        while (psVar2->species != MONSTER_NONE && sPersonalityRelated_203B040.PartnerID != psVar2->species) {
            psVar2++;
        }
        SetScriptVarValue(NULL, PARTNER_TALK_KIND, psVar2->unk0);
    }
}

// arm9.bin::0200CDD4
static u8 sub_8001170(void)
{
    s16 local_10;
    s16 auStack_e;
    u8 auStack_b;
    u8 dungeonID = NUM_DUNGEONS + 1;

    if (sub_80992E0(&local_10, &auStack_e))
        dungeonID = sub_80A2740(local_10);
    else if (!sub_8099328(&dungeonID) && !sub_8099360(&dungeonID) && sub_8099394(&auStack_b))
        dungeonID = DUNGEON_OUT_ON_RESCUE;

    return dungeonID;
}

// arm9.bin::0200CDA4
static void sub_80011CC(DungeonSetupSubstruct *info, u8 dungId)
{
    info->unk0.id = dungId;
    info->unk0.floor = 0;

    sub_80011E8(info);

    info->unkB = 0;
    info->unk4 = 0;
    info->unkC = 0;
    info->unkD = 0;
}

// arm9.bin::0200CD1C
static void sub_80011E8(DungeonSetupSubstruct *info)
{
    info->unk5 = sub_80023E4(8);
    info->unk6 = sub_80023E4(3);
    info->unk8 = sub_80023E4(7);
    info->unk9 = sub_80023E4(0);
    info->unkA = sub_80023E4(5);

    if (sub_80023E4(24) && sub_80023E4(25) && sub_80023E4(26))
        info->unk7 = 1;
    else
        info->unk7 = 0;
}

// arm9.bin::0200CC4C
static void RemoveMoneyAndRandomItems(void)
{
    s32 i;

    for (i = 0; i < INVENTORY_SIZE; i++) {
        if (RandInt(100) < 50)
            ZeroOutItem(&gTeamInventoryRef->teamItems[i]);
    }

    FillInventoryGaps();

    for (i = 0; i < NUM_MONSTERS; i++) {
        Pokemon *mon = &gRecruitedPokemonRef->pokemon[i];
        if (PokemonExists(mon) && PokemonFlag2(mon))
            mon->heldItem.id = ITEM_NOTHING;
    }

    gTeamInventoryRef->teamMoney = 0;
}

// arm9.bin::0200CB88
static void RemoveAllMoneyAndItems(void)
{
    s32 i;

    for (i = 0; i < INVENTORY_SIZE; i++) {
        ZeroOutItem(&gTeamInventoryRef->teamItems[i]);
    }

    FillInventoryGaps();

    for (i = 0; i < NUM_MONSTERS; i++) {
        Pokemon *mon = &gRecruitedPokemonRef->pokemon[i];
        if (PokemonExists(mon) && PokemonFlag2(mon))
            mon->heldItem.id = ITEM_NOTHING;
    }

    gTeamInventoryRef->teamMoney = 0;
}

// arm9.bin::0200CB14
static void NDS_LoadOverlay_GroundMain()
{

}

// arm9.bin::0200CADC
static void nullsub_2(DungeonSetupStruct *r0)
{
    // (not a nullsub in the NDS)
    // Probably loads the dungeon overlay?
}

// arm9.bin::0200CAD0
static u32 xxx_script_related_8001334(u32 r0)
{
    return xxx_script_related_8098468(r0);
}

// arm9.bin::0200CA1C
static void LoadAndRunDungeon_Async(DungeonSetupStruct *setupPtr)
{
    nullsub_2(setupPtr);
    RunDungeon_Async(setupPtr);
    NDS_LoadOverlay_GroundMain();
}

// TODO: NDS has another func here (arm9.bin::0200C970)

// arm9.bin::0200C96C
void nullsub_3(s32 yPos, s32 a1)
{

}
