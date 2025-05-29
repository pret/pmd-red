#include "global.h"
#include "globaldata.h"
#include "constants/bg_music.h"
#include "constants/main_menu.h"
#include "structs/str_dungeon_setup.h"
#include "bg_control.h"
#include "bg_palette_buffer.h"
#include "code_800558C.h"
#include "code_8009804.h"
#include "code_800C9CC.h"
#include "code_800D090_1.h"
#include "code_80118A4.h"
#include "run_dungeon.h"
#include "code_8094F88.h"
#include "code_80958E8.h"
#include "code_8097670.h"
#include "code_8099328.h"
#include "code_8099360.h"
#include "code_80A26CC.h"
#include "cpu.h"
#include "debug.h"
#include "def_filearchives.h"
#include "event_flag.h"
#include "exclusive_pokemon.h"
#include "friend_area.h"
#include "game_options.h"
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
#include "structs/str_dungeon_setup.h"

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

#include "data/main_loops.h"

static void LoadTitleScreen(void);
static void NDS_LoadOverlay_GroundMain();
static u32 sub_80009D0(u32 param_1);
/* static */ // TODO: Uncomment
void sub_80011E8(DungeonSetupSubstruct *info);
static void LoadAndRunDungeon_Async(DungeonSetupStruct *r0);
/* static */ // TODO: Uncomment
u32 xxx_script_related_8001334(u32 r0);
static void MainLoops_RunFrameActions(u32 unused);

extern u32 xxx_script_related_8098468(u32);

// arm9.bin::0200E0A8
void GameLoop(void)
{
    u32 tmp;
    u8 tmp3 = 1;
    u32 nextMenu;
    u32 flag;

    InitHeap();
    NDS_DebugInit();
    sub_801180C();
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
    SetWindowTitle(sPMDBuildVersion);
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
                    tmp3 = sub_80009D0(2);
                }
                else
                    tmp3 = sub_80009D0(1);

                break;
            }
            case 4: {
                tmp3 = sub_80009D0(3);
                break;
            }
            case MENU_NEW_GAME: {
                sub_80122A8();
                nullsub_33();
                tmp3 = sub_80009D0(0);
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
    sub_8011860();
    WaitForNextFrameAndAdvanceRNG();
    LoadBufferedInputs();

    CopySpritesToOam();
    sub_8005304();
    // 2 extra calls here in blue. They seem to be copies of the 2 above funcs, but for 2nd screen sprites

    TransferBGPaletteBuffer();
    xxx_call_update_bg_vram();
    sub_8009908();
    xxx_call_update_bg_sound_input();

    ResetSprites(FALSE);
    // Extra call here in blue. Seems to be for 2nd screen sprites
}

// https://decomp.me/scratch/w6tN1 (82.93%)
// arm9.bin::0200DE18
NAKED
static void LoadTitleScreen(void)
{
    asm_unified(
"	push {r4-r7,lr}\n"
"	mov r7, r9\n"
"	mov r6, r8\n"
"	push {r6,r7}\n"
"	sub sp, 0x18\n"
"	mov r1, sp\n"
"	ldr r0, _08000708\n"
"	ldm r0!, {r2-r4}\n"
"	stm r1!, {r2-r4}\n"
"	add r5, sp, 0xC\n"
"	adds r1, r5, 0\n"
"	ldr r0, _0800070C\n"
"	ldm r0!, {r2-r4}\n"
"	stm r1!, {r2-r4}\n"
"	ldr r0, _08000710\n"
"	movs r1, 0\n"
"	bl MemoryAlloc\n"
"	adds r7, r0, 0\n"
"	movs r0, 0x3\n"
"	bl RandInt\n"
"	adds r4, r0, 0\n"
"	lsls r4, 2\n"
"	adds r5, r4\n"
"	ldr r0, [r5]\n"
"	ldr r5, _08000714\n"
"	adds r1, r5, 0\n"
"	bl OpenFileAndGetFileDataPtr\n"
"	ldr r1, _08000718\n"
"	str r0, [r1]\n"
"	mov r1, sp\n"
"	adds r0, r1, r4\n"
"	ldr r0, [r0]\n"
"	adds r1, r5, 0\n"
"	bl OpenFileAndGetFileDataPtr\n"
"	mov r8, r0\n"
"	adds r0, r7, 0\n"
"	movs r1, 0\n"
"	mov r2, r8\n"
"	bl DecompressATFile\n"
"	movs r2, 0\n"
"	ldr r0, _0800071C\n"
"	movs r3, 0xC0\n"
"	lsls r3, 5\n"
"	adds r3, r0\n"
"	mov r9, r3\n"
"	movs r4, 0x80\n"
"	lsls r4, 5\n"
"	adds r4, r0\n"
"	mov r12, r4\n"
"_080006A0:\n"
"	movs r5, 0\n"
"	lsls r1, r2, 6\n"
"	adds r6, r2, 0x1\n"
"	mov r0, r9\n"
"	adds r4, r1, r0\n"
"	mov r2, r12\n"
"	adds r3, r1, r2\n"
"	movs r2, 0x80\n"
"	lsls r2, 4\n"
"	adds r0, r7, r2\n"
"	adds r2, r1, r0\n"
"	adds r1, r7\n"
"_080006B8:\n"
"	ldrh r0, [r1]\n"
"	strh r0, [r3]\n"
"	ldrh r0, [r2]\n"
"	strh r0, [r4]\n"
"	adds r4, 0x2\n"
"	adds r3, 0x2\n"
"	adds r2, 0x2\n"
"	adds r1, 0x2\n"
"	adds r5, 0x1\n"
"	cmp r5, 0x1F\n"
"	ble _080006B8\n"
"	adds r2, r6, 0\n"
"	cmp r2, 0x1F\n"
"	ble _080006A0\n"
"	movs r0, 0x2\n"
"	bl sub_80098F8\n"
"	movs r0, 0x3\n"
"	bl sub_80098F8\n"
"	ldr r0, _08000720\n"
"	movs r3, 0x80\n"
"	lsls r3, 5\n"
"	adds r1, r7, r3\n"
"	ldr r2, _08000724\n"
"	bl CpuCopy\n"
"	mov r0, r8\n"
"	bl CloseFile\n"
"	adds r0, r7, 0\n"
"	bl MemoryFree\n"
"	add sp, 0x18\n"
"	pop {r3,r4}\n"
"	mov r8, r3\n"
"	mov r9, r4\n"
"	pop {r4-r7}\n"
"	pop {r0}\n"
"	bx r0\n"
"	.align 2, 0\n"
"_08000708: .4byte sLoadScreenBackgroundFileNames\n"
"_0800070C: .4byte sLoadScreenBackgroundPaletteFileNames\n"
"_08000710: .4byte 0x00005b20\n"
"_08000714: .4byte gTitleMenuFileArchive\n"
"_08000718: .4byte sTitlePaletteFile\n"
"_0800071C: .4byte gBgTilemaps\n"
"_08000720: .4byte 0x06008000\n"
"_08000724: .4byte 0x00004b20");
}

// arm9.bin::0200ED08
s32 sub_8000728(void)
{
    return sUnknown_203B03C;
}

// arm9.bin::0200DB58
/* static */ // TODO: uncomment
void QuickSave_Async(u32 mode)
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
/*static*/ // TODO: Uncomment
void sub_80008C0_Async(u32 errorKind)
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

// https://decomp.me/scratch/dlKUt (66.34%)
// arm9.bin::0200D1E0
NAKED
static u32 sub_80009D0(u32 param_1)
{
    asm_unified(
"	push {r4-r7,lr}\n"
"	mov r7, r10\n"
"	mov r6, r9\n"
"	mov r5, r8\n"
"	push {r5-r7}\n"
"	ldr r4, _08000A04\n"
"	add sp, r4\n"
"	adds r4, r0, 0\n"
"	movs r0, 0\n"
"	movs r1, 0x18\n"
"	bl GetScriptVarValue\n"
"	adds r7, r0, 0\n"
"	movs r0, 0\n"
"	mov r10, r0\n"
"	bl sub_801180C\n"
"	movs r0, 0x10\n"
"	bl FadeOutAllMusic\n"
"	cmp r7, 0x7\n"
"	bne _08000A30\n"
"	cmp r4, 0x2\n"
"	bne _08000A08\n"
"	movs r7, 0x8\n"
"	b _08000A3A\n"
"	.align 2, 0\n"
"_08000A04: .4byte 0xfffffdd4\n"
"_08000A08:\n"
"	cmp r4, 0x3\n"
"	bne _08000A3A\n"
"	movs r7, 0xB\n"
"	movs r0, 0\n"
"	movs r1, 0x18\n"
"	movs r2, 0xB\n"
"	bl SetScriptVarValue\n"
"	bl sub_8096BD0\n"
"	movs r0, 0x3\n"
"	bl QuickSave_Async\n"
"	b _08000A3A\n"
"_08000A24:\n"
"	movs r3, 0x1\n"
"	mov r10, r3\n"
"	b _08000EC6\n"
"_08000A2A:\n"
"	movs r0, 0x1\n"
"	mov r10, r0\n"
"	b _08000EC6\n"
"_08000A30:\n"
"	cmp r7, 0\n"
"	beq _08000A3A\n"
"	cmp r7, 0xB\n"
"	beq _08000A3A\n"
"	movs r7, 0x1\n"
"_08000A3A:\n"
"	movs r0, 0\n"
"	movs r1, 0x41\n"
"	bl ClearScriptVarArray\n"
"_08000A42:\n"
"	cmp r7, 0x4\n"
"	bne _08000AB6\n"
"	movs r0, 0\n"
"	movs r1, 0xD\n"
"	bl GetScriptVarValue\n"
"	lsls r0, 16\n"
"	asrs r0, 16\n"
"	bl sub_8002658\n"
"	adds r4, r0, 0\n"
"	lsls r4, 24\n"
"	lsrs r4, 24\n"
"	ldr r0, _08000A9C\n"
"	movs r1, 0x8\n"
"	bl MemoryAlloc\n"
"	str r0, [sp, 0x8]\n"
"	mov r0, sp\n"
"	strb r4, [r0, 0x4]\n"
"	movs r0, 0x9\n"
"	bl sub_80023E4\n"
"	mov r1, sp\n"
"	strb r0, [r1, 0x5]\n"
"	mov r0, sp\n"
"	bl ShowFriendAreasMap_Async\n"
"	ldr r0, [sp, 0x8]\n"
"	bl MemoryFree\n"
"	mov r0, sp\n"
"	ldrb r0, [r0, 0xC]\n"
"	cmp r0, 0x3A\n"
"	beq _08000B70\n"
"	mov r0, sp\n"
"	ldrb r0, [r0, 0xC]\n"
"	cmp r0, 0\n"
"	beq _08000AA0\n"
"	bl sub_8002694\n"
"	lsls r0, 16\n"
"	asrs r2, r0, 16\n"
"	b _08000AA2\n"
"	.align 2, 0\n"
"_08000A9C: .4byte 0x00004e30\n"
"_08000AA0:\n"
"	movs r2, 0x9\n"
"_08000AA2:\n"
"	movs r0, 0\n"
"	movs r1, 0xD\n"
"	bl SetScriptVarValue\n"
"	movs r0, 0\n"
"	movs r1, 0xE\n"
"	movs r2, 0\n"
"	bl SetScriptVarValue\n"
"	b _08000B70\n"
"_08000AB6:\n"
"	cmp r7, 0x5\n"
"	bne _08000B9C\n"
"	movs r0, 0\n"
"	movs r1, 0x12\n"
"	bl GetScriptVarValue\n"
"	lsls r0, 16\n"
"	asrs r0, 16\n"
"	mov r8, r0\n"
"	bl sub_80A2740\n"
"	lsls r0, 24\n"
"	lsrs r6, r0, 24\n"
"	movs r4, 0\n"
"	ldr r5, _08000B18\n"
"	add r5, sp\n"
"_08000AD6:\n"
"	lsls r0, r4, 24\n"
"	lsrs r0, 24\n"
"	bl sub_80A28F0\n"
"	adds r1, r5, r4\n"
"	strb r0, [r1]\n"
"	adds r4, 0x1\n"
"	cmp r4, 0x3E\n"
"	ble _08000AD6\n"
"	cmp r6, 0x63\n"
"	beq _08000B70\n"
"	add r4, sp, 0xB8\n"
"	movs r0, 0x3F\n"
"	strb r0, [r4, 0x4]\n"
"	add r0, sp, 0xC0\n"
"	adds r1, r6, 0\n"
"	bl sub_80011CC\n"
"	ldrb r1, [r4, 0xD]\n"
"	add r0, sp, 0x128\n"
"	strb r1, [r0]\n"
"	mov r0, r8\n"
"	bl sub_80A2750\n"
"	lsls r0, 16\n"
"	asrs r0, 16\n"
"	adds r5, r4, 0\n"
"	cmp r0, 0x1\n"
"	beq _08000B1C\n"
"	cmp r0, 0x2\n"
"	beq _08000B3C\n"
"	b _08000B50\n"
"	.align 2, 0\n"
"_08000B18: .4byte 0x00000129\n"
"_08000B1C:\n"
"	add r4, sp, 0x170\n"
"	add r0, sp, 0x174\n"
"	mov r1, r8\n"
"	bl sub_80990EC\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	beq _08000B50\n"
"	ldrb r0, [r4, 0x10]\n"
"	strb r0, [r5, 0x14]\n"
"	add r0, sp, 0xD0\n"
"	add r1, sp, 0x18C\n"
"	movs r2, 0x58\n"
"	bl memcpy\n"
"	b _08000B50\n"
"_08000B3C:\n"
"	ldrb r0, [r5, 0x8]\n"
"	add r1, sp, 0xD0\n"
"	bl sub_8096A08\n"
"	lsls r0, 24\n"
"	lsrs r0, 24\n"
"	cmp r0, 0\n"
"	beq _08000B4E\n"
"	movs r0, 0x1\n"
"_08000B4E:\n"
"	strb r0, [r5, 0x14]\n"
"_08000B50:\n"
"	ldr r0, _08000B74\n"
"	movs r1, 0x8\n"
"	bl MemoryAlloc\n"
"	add r4, sp, 0x168\n"
"	str r0, [r4]\n"
"	adds r0, r5, 0\n"
"	bl ShowWorldMap_Async\n"
"	ldr r0, [r4]\n"
"	bl MemoryFree\n"
"	add r0, sp, 0x16C\n"
"	ldrb r0, [r0]\n"
"	cmp r0, 0\n"
"	bne _08000B78\n"
"_08000B70:\n"
"	movs r7, 0x2\n"
"	b _08000A42\n"
"	.align 2, 0\n"
"_08000B74: .4byte 0x00006474\n"
"_08000B78:\n"
"	movs r0, 0\n"
"	movs r1, 0x13\n"
"	mov r2, r8\n"
"	bl SetScriptVarValue\n"
"	ldr r1, _08000B98\n"
"	movs r0, 0x2\n"
"	str r0, [r1]\n"
"	movs r0, 0x4\n"
"	bl sub_800A8F8\n"
"	movs r0, 0x5\n"
"	bl xxx_script_related_8001334\n"
"	adds r5, r0, 0\n"
"	b _08000BEC\n"
"	.align 2, 0\n"
"_08000B98: .4byte sUnknown_203B03C\n"
"_08000B9C:\n"
"	cmp r7, 0x8\n"
"	bne _08000BA4\n"
"	movs r5, 0\n"
"	b _08000BEC\n"
"_08000BA4:\n"
"	cmp r7, 0x7\n"
"	bne _08000BAC\n"
"	movs r5, 0x2\n"
"	b _08000BEC\n"
"_08000BAC:\n"
"	cmp r7, 0xB\n"
"	bne _08000BB6\n"
"	bl sub_80012C0\n"
"	b _08000BBE\n"
"_08000BB6:\n"
"	cmp r7, 0xC\n"
"	bne _08000BBE\n"
"	bl sub_8001248\n"
"_08000BBE:\n"
"	ldr r1, _08000BE0\n"
"	movs r0, 0x2\n"
"	str r0, [r1]\n"
"	movs r0, 0x4\n"
"	bl sub_800A8F8\n"
"	adds r0, r7, 0\n"
"	bl xxx_script_related_8001334\n"
"	adds r5, r0, 0\n"
"	cmp r5, 0xE\n"
"	bne _08000BD8\n"
"	b _08000EC6\n"
"_08000BD8:\n"
"	cmp r5, 0x5\n"
"	bne _08000BE4\n"
"	movs r7, 0x4\n"
"	b _08000A42\n"
"	.align 2, 0\n"
"_08000BE0: .4byte sUnknown_203B03C\n"
"_08000BE4:\n"
"	cmp r5, 0x6\n"
"	bne _08000BEC\n"
"	movs r7, 0x5\n"
"	b _08000A42\n"
"_08000BEC:\n"
"	add r6, sp, 0x170\n"
"	movs r4, 0\n"
"	strb r4, [r6, 0x11]\n"
"	strb r4, [r6, 0x10]\n"
"	movs r3, 0xC6\n"
"	lsls r3, 1\n"
"	add r3, sp\n"
"	mov r8, r3\n"
"	mov r0, r8\n"
"	movs r1, 0\n"
"	movs r2, 0x58\n"
"	bl MemoryFill8\n"
"	movs r0, 0\n"
"	mov r9, r0\n"
"	strh r4, [r6, 0x24]\n"
"	cmp r5, 0x7\n"
"	beq _08000C3C\n"
"	cmp r5, 0x8\n"
"	bne _08000C38\n"
"	add r0, sp, 0x174\n"
"	add r1, sp, 0x228\n"
"	bl sub_80991E0\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	beq _08000C4C\n"
"	ldrb r0, [r6, 0x4]\n"
"	mov r1, r8\n"
"	bl sub_8096A08\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	bne _08000C32\n"
"	b _08000D98\n"
"_08000C32:\n"
"	movs r0, 0x1\n"
"	strb r0, [r6, 0x10]\n"
"	b _08000D98\n"
"_08000C38:\n"
"	cmp r5, 0xA\n"
"	bne _08000C52\n"
"_08000C3C:\n"
"	add r0, sp, 0x174\n"
"	add r1, sp, 0x228\n"
"	bl sub_80991E0\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	beq _08000C4C\n"
"	b _08000D98\n"
"_08000C4C:\n"
"	movs r5, 0xD\n"
"	movs r7, 0x9\n"
"	b _08000D98\n"
"_08000C52:\n"
"	cmp r5, 0x9\n"
"	bne _08000C6C\n"
"	add r0, sp, 0x174\n"
"	add r1, sp, 0x228\n"
"	bl sub_80991E0\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	beq _08000C66\n"
"	b _08000D98\n"
"_08000C66:\n"
"	movs r5, 0xB\n"
"	movs r7, 0xC\n"
"	b _08000D98\n"
"_08000C6C:\n"
"	cmp r5, 0\n"
"	bne _08000D04\n"
"	bl sub_8011FA8\n"
"	adds r1, r0, 0\n"
"	ldr r0, _08000CA0\n"
"	cmp r1, r0\n"
"	bne _08000CC8\n"
"	movs r2, 0x1\n"
"	strb r2, [r6, 0x11]\n"
"	strb r2, [r6, 0x8]\n"
"	mov r3, r9\n"
"	strb r3, [r6, 0xF]\n"
"	ldr r0, _08000CA4\n"
"	ldr r1, [r0]\n"
"	movs r3, 0xC\n"
"	ldrsh r0, [r1, r3]\n"
"	cmp r0, 0\n"
"	beq _08000CA8\n"
"	strb r2, [r6, 0x10]\n"
"	adds r1, 0x4\n"
"	mov r0, r8\n"
"	movs r2, 0x58\n"
"	bl memcpy\n"
"	b _08000CAC\n"
"	.align 2, 0\n"
"_08000CA0: .4byte 0x000f1207\n"
"_08000CA4: .4byte gUnknown_203B484\n"
"_08000CA8:\n"
"	mov r0, r9\n"
"	strb r0, [r6, 0x10]\n"
"_08000CAC:\n"
"	ldr r4, _08000CC4\n"
"	ldr r0, [r4]\n"
"	adds r0, 0x4\n"
"	movs r1, 0\n"
"	movs r2, 0x58\n"
"	bl MemoryFill8\n"
"	ldr r1, [r4]\n"
"	movs r0, 0\n"
"	strh r0, [r1, 0xC]\n"
"	b _08000CE4\n"
"	.align 2, 0\n"
"_08000CC4: .4byte gUnknown_203B484\n"
"_08000CC8:\n"
"	ldr r0, _08000CD8\n"
"	cmp r1, r0\n"
"	bne _08000CDC\n"
"	movs r5, 0x1\n"
"	movs r7, 0xB\n"
"	bl sub_8096BD0\n"
"	b _08000CE4\n"
"	.align 2, 0\n"
"_08000CD8: .4byte 0x000f1208\n"
"_08000CDC:\n"
"	movs r5, 0x1\n"
"	movs r7, 0xB\n"
"	bl sub_8096BD0\n"
"_08000CE4:\n"
"	cmp r5, 0x1\n"
"	bne _08000D98\n"
"	ldr r4, _08000D00\n"
"	ldr r0, [r4]\n"
"	adds r0, 0x4\n"
"	movs r1, 0\n"
"	movs r2, 0x58\n"
"	bl MemoryFill8\n"
"	ldr r1, [r4]\n"
"	movs r0, 0\n"
"	strh r0, [r1, 0xC]\n"
"	b _08000D98\n"
"	.align 2, 0\n"
"_08000D00: .4byte gUnknown_203B484\n"
"_08000D04:\n"
"	cmp r5, 0x2\n"
"	bne _08000D98\n"
"	bl sub_8011C1C\n"
"	cmp r0, 0x2\n"
"	bne _08000D34\n"
"	bl sub_8011FA8\n"
"	adds r1, r0, 0\n"
"	movs r0, 0x1\n"
"	strb r0, [r6, 0x8]\n"
"	mov r3, r9\n"
"	strb r3, [r6, 0x11]\n"
"	ldr r0, _08000D30\n"
"	cmp r1, r0\n"
"	beq _08000D36\n"
"	adds r0, 0x1\n"
"	movs r5, 0x1\n"
"	movs r7, 0xB\n"
"	bl sub_8096BD0\n"
"	b _08000D36\n"
"	.align 2, 0\n"
"_08000D30: .4byte 0x000f1207\n"
"_08000D34:\n"
"	movs r5, 0x3\n"
"_08000D36:\n"
"	cmp r5, 0x3\n"
"	bne _08000D7A\n"
"	bl sub_8001170\n"
"	lsls r0, 24\n"
"	lsrs r4, r0, 24\n"
"	movs r5, 0x1\n"
"	movs r7, 0xB\n"
"	bl sub_8096BD0\n"
"	cmp r4, 0x3F\n"
"	beq _08000D70\n"
"	cmp r4, 0x63\n"
"	beq _08000D70\n"
"	adds r0, r4, 0\n"
"	bl IsEnterWithoutGameSave\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	beq _08000D70\n"
"	bl sub_8011C1C\n"
"	cmp r0, 0x2\n"
"	bne _08000D6C\n"
"	movs r5, 0x3\n"
"	movs r7, 0x7\n"
"	b _08000D70\n"
"_08000D6C:\n"
"	movs r5, 0xC\n"
"	movs r7, 0xA\n"
"_08000D70:\n"
"	cmp r5, 0x1\n"
"	bne _08000D98\n"
"	bl sub_8011C1C\n"
"	b _08000D98\n"
"_08000D7A:\n"
"	cmp r5, 0x4\n"
"	bne _08000D8E\n"
"	movs r5, 0x1\n"
"	movs r7, 0xB\n"
"	bl sub_8096BD0\n"
"	movs r0, 0x1\n"
"	bl sub_80008C0_Async\n"
"	b _08000D98\n"
"_08000D8E:\n"
"	cmp r5, 0x1\n"
"	bne _08000D98\n"
"	movs r7, 0xB\n"
"	bl sub_8096BD0\n"
"_08000D98:\n"
"	subs r0, r5, 0x7\n"
"	cmp r0, 0x3\n"
"	bls _08000DAC\n"
"	cmp r5, 0\n"
"	beq _08000E1E\n"
"	cmp r5, 0x2\n"
"	beq _08000DAC\n"
"	cmp r5, 0x3\n"
"	beq _08000DAC\n"
"	b _08000A42\n"
"_08000DAC:\n"
"	cmp r5, 0\n"
"	beq _08000E1E\n"
"	cmp r5, 0x2\n"
"	beq _08000E1E\n"
"	cmp r5, 0x3\n"
"	beq _08000E1E\n"
"	bl sub_8001170\n"
"	lsls r0, 24\n"
"	lsrs r6, r0, 24\n"
"	bl IncrementNumAdventures\n"
"	cmp r5, 0x9\n"
"	bne _08000E00\n"
"	ldr r4, _08000DF4\n"
"	add r4, sp\n"
"	adds r0, r4, 0\n"
"	bl sub_8099394\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	beq _08000E00\n"
"	ldrb r0, [r4]\n"
"	bl GetMailatIndex\n"
"	adds r2, r0, 0\n"
"	adds r0, 0x2C\n"
"	ldrb r1, [r0]\n"
"	ldrb r0, [r0]\n"
"	lsls r0, 24\n"
"	asrs r0, 24\n"
"	cmp r0, 0x1\n"
"	ble _08000DF8\n"
"	subs r1, 0x1\n"
"	b _08000DFA\n"
"	.align 2, 0\n"
"_08000DF4: .4byte 0x0000022a\n"
"_08000DF8:\n"
"	movs r1, 0\n"
"_08000DFA:\n"
"	adds r0, r2, 0\n"
"	adds r0, 0x2C\n"
"	strb r1, [r0]\n"
"_08000E00:\n"
"	cmp r6, 0x3F\n"
"	bne _08000E0C\n"
"	movs r0, 0\n"
"	bl QuickSave_Async\n"
"	b _08000E1E\n"
"_08000E0C:\n"
"	adds r0, r6, 0\n"
"	bl IsEnterWithoutGameSave\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	bne _08000E1E\n"
"	movs r0, 0\n"
"	bl QuickSave_Async\n"
"_08000E1E:\n"
"	ldr r0, _08000E70\n"
"	movs r4, 0x1\n"
"	str r4, [r0]\n"
"	movs r0, 0x3\n"
"	bl sub_800A8F8\n"
"	add r5, sp, 0x170\n"
"	str r4, [r5]\n"
"	add r0, sp, 0x174\n"
"	bl sub_80011E8\n"
"	adds r0, r5, 0\n"
"	bl LoadAndRunQuickSaveDungeon_Async\n"
"	add r4, sp, 0x1EC\n"
"	movs r0, 0\n"
"	ldrsh r1, [r4, r0]\n"
"	cmp r1, 0x3\n"
"	bne _08000E46\n"
"	b _08000A24\n"
"_08000E46:\n"
"	movs r0, 0x2\n"
"	negs r0, r0\n"
"	cmp r1, r0\n"
"	bne _08000E50\n"
"	b _08000A2A\n"
"_08000E50:\n"
"	movs r0, 0\n"
"	movs r1, 0x41\n"
"	bl ClearScriptVarArray\n"
"	ldrh r0, [r4]\n"
"	adds r0, 0x1\n"
"	lsls r0, 16\n"
"	asrs r0, 16\n"
"	cmp r0, 0x6\n"
"	bhi _08000EBE\n"
"	lsls r0, 2\n"
"	ldr r1, _08000E74\n"
"	adds r0, r1\n"
"	ldr r0, [r0]\n"
"	mov pc, r0\n"
"	.align 2, 0\n"
"_08000E70: .4byte sUnknown_203B03C\n"
"_08000E74: .4byte _08000E78\n"
"	.align 2, 0\n"
"_08000E78:\n"
"	.4byte _08000EB6\n"
"	.4byte _08000EBE\n"
"	.4byte _08000E94\n"
"	.4byte _08000EB2\n"
"	.4byte _08000EBE\n"
"	.4byte _08000E94\n"
"	.4byte _08000EBE\n"
"_08000E94:\n"
"	movs r7, 0x9\n"
"	movs r0, 0xF7\n"
"	lsls r0, 1\n"
"	add r0, sp\n"
"	ldrb r0, [r0]\n"
"	movs r3, 0x1\n"
"	cmp r0, 0\n"
"	beq _08000EA6\n"
"	movs r3, 0x2\n"
"_08000EA6:\n"
"	movs r0, 0\n"
"	movs r1, 0x41\n"
"	movs r2, 0\n"
"	bl SetScriptVarArrayValue\n"
"	b _08000A42\n"
"_08000EB2:\n"
"	movs r7, 0xA\n"
"	b _08000A42\n"
"_08000EB6:\n"
"	movs r7, 0xC\n"
"	bl sub_8096BD0\n"
"	b _08000A42\n"
"_08000EBE:\n"
"	movs r7, 0xB\n"
"	bl sub_8096BD0\n"
"	b _08000A42\n"
"_08000EC6:\n"
"	mov r0, r10\n"
"	movs r3, 0x8B\n"
"	lsls r3, 2\n"
"	add sp, r3\n"
"	pop {r3-r5}\n"
"	mov r8, r3\n"
"	mov r9, r4\n"
"	mov r10, r5\n"
"	pop {r4-r7}\n"
"	pop {r1}\n"
"	bx r1");
}

// This func is probably used for running the dungeon in general (and updating RNG mechanics), not just quicksave.
// More documentation needed to be sure
// It'd also be cool to see what happens if a quicksave load fails and the dungeon is skipped entirely
// arm9.bin::0200D01C
/* static */ // TODO: Uncomment
void LoadAndRunQuickSaveDungeon_Async(DungeonSetupStruct *param_1)
{
    u8 quickSaveValid;
    s32 quickSaveStatus;
    s32 local_1c; // 0x4800
    s32 local_18; // sizeof(Dungeon)

    quickSaveValid = TRUE;
    sUnknown_203B03C = 1;

    sub_800A8F8(3);
    sub_8014144();
    sub_8043D50(&local_1c, &local_18);

    param_1->info.unk74 = MemoryAlloc(local_1c, 7); // size: 0x4800
    param_1->info.unk78 = MemoryAlloc(local_18, 7); // size: sizeof(Dungeon)

    if (param_1->info.sub0.unk4) {
        PrepareQuickSaveRead(param_1->info.unk74, local_1c);

        while (TRUE) {
            if (!ReadQuickSave())
                break;
            MainLoops_RunFrameActions(0);
        }

        quickSaveValid = IsQuickSaveValid();
        FinishQuickSaveRead();
        sub_8011830();

        if (quickSaveValid)
            sub_80121E0(0xF1208);
        else
            sub_80121E0(0xF1209);

        xxx_call_start_bg_music();
    }
    else {
        GeneratePelipperJobs();
        sub_80961B4();
        sub_808ED00();
    }

    if (quickSaveValid) {
        LoadAndRunDungeon_Async(param_1);
        sub_8099648();
        SetWindowBGColor();
        sub_8099690(0);
    }
    else
        param_1->info.unk7C = 5;

    if (param_1->info.unk7C == -2)
        sub_809542C(&param_1->info.unk84);

    if (param_1->info.unk7C == 3 || param_1->info.unk7C == -2) {
        SetDungeonLocationInfo(&param_1->info.unk80);
        xxx_call_stop_bgm();

        if (param_1->info.unk7C == -2)
            PrepareQuickSaveWrite(param_1->info.unk74, local_1c, 1);
        else
            PrepareQuickSaveWrite(param_1->info.unk74, local_1c, 0);

        while ((quickSaveStatus = WriteQuickSave(), (quickSaveStatus != 2))) {
            if (quickSaveStatus == 3)
                break;
            if (quickSaveStatus == 1) {
                MemoryFree(param_1->info.unk78);
                MemoryFree(param_1->info.unk74);
            }

            MainLoops_RunFrameActions(0);
        }
        FinishQuickSaveWrite();
    }
    else {
        sub_808ED00();
        MemoryFree(param_1->info.unk78);
        MemoryFree(param_1->info.unk74);
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
/* static */ // TODO: Uncomment
u8 sub_8001170(void)
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
/* static */ // TODO: Uncomment
void sub_80011CC(DungeonSetupSubstruct *info, u8 dungId)
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
/* static */ // TODO: Uncomment
void sub_80011E8(DungeonSetupSubstruct *info)
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
/* static */ // TODO: Uncomment
void sub_8001248(void)
{
    s32 index;

    for (index = 0; index < INVENTORY_SIZE; index++) {
        if (RandInt(100) < 50)
            ZeroOutItem(&gTeamInventoryRef->teamItems[index]);
    }

    FillInventoryGaps();

    for (index = 0; index < NUM_MONSTERS; index++) {
        PokemonStruct1 *mon = &gRecruitedPokemonRef->pokemon[index];
        if (PokemonFlag1(mon) && PokemonFlag2(mon))
            mon->heldItem.id = ITEM_NOTHING;
    }

    gTeamInventoryRef->teamMoney = 0;
}

// arm9.bin::0200CB88
/* static */ // TODO: Uncomment
void sub_80012C0(void)
{
    s32 index;

    for (index = 0; index < INVENTORY_SIZE; index++) {
        ZeroOutItem(&gTeamInventoryRef->teamItems[index]);
    }

    FillInventoryGaps();

    for (index = 0; index < NUM_MONSTERS; index++) {
        PokemonStruct1 *mon = &gRecruitedPokemonRef->pokemon[index];
        if (PokemonFlag1(mon) && PokemonFlag2(mon))
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
/* static */ // TODO: Uncomment
u32 xxx_script_related_8001334(u32 r0)
{
    return xxx_script_related_8098468(r0);
}

// arm9.bin::0200CA1C
static void LoadAndRunDungeon_Async(DungeonSetupStruct *r0)
{
    nullsub_2(r0);
    RunDungeon_Async(r0);
    NDS_LoadOverlay_GroundMain();
}

// TODO: NDS has another func here (arm9.bin::0200C970)

// arm9.bin::0200C96C
void nullsub_3(s32 yPos, s32 a1)
{

}
