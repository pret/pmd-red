#include "global.h"
#include "world_map.h"
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
#include "game_options.h"
#include "play_time.h"
#include "pokemon.h"
#include "decompress.h"

extern const DungeonPos gDungeonCoordinates[];
extern const struct FriendAreaLocation gFriendAreaLocations[];
extern const FileArchive gTitleMenuFileArchive;
extern const FileArchive gMonsterFileArchive;
extern const u8 gUnknown_80D40E4[];
extern const u8 gUnknown_80D40EC[];
extern const u8 gUnknown_80D405C[];
extern const u8 gUnknown_80D40FC[];
extern const u8 gUnknown_80D4104[];
extern const u8 gUnknown_80D4120[];
extern const u8 gUnknown_80D3EFC[];
extern const u8 gUnknown_80D40F4[];
extern const u8 gUnknown_80D4064[];
extern const u8 gUnknown_80D406C[];
extern const u8 gUnknown_80D407C[];
extern const u8 gUnknown_80D4080[];
extern const u8 gUnknown_80D4074[];

extern u16 gUnknown_2026E4E;

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

EWRAM_INIT struct UnkStruct_203B0E8 *gUnknown_203B0E8 = NULL;
EWRAM_INIT Windows gUnknown_203B0EC = {
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
        [2] = { .type = WINDOW_TYPE_NORMAL,},
        [3] = { .type = WINDOW_TYPE_NORMAL,},
    }
};

static void ClearWindows(void);
static void AnimateSprites(bool8 a0);
static bool8 FadeScreen(void);
static void nullsub_24(void);
static void RunFrameActions(void);
static void UpdateMonSpritePosition(void);
static void UpdateBg(void);
static void sub_8010494(struct UnkStruct_sub_8010494 *r9);
static void AnimateMonPath(u8 id1, u8 id2);
static void sub_801059C(void);
static bool8 ShowYesNoWindow(u8 *str);
static void PrintDialogueMessage(const u8 *text);
static void FadeFromWorldMap(void);
static void CloseFiles(void);
static void PrintDungeonName(DungeonLocation *dungLocation);

// Code is very similar to the functions in friend_areas_map_util.c

void ShowWorldMap(struct UnkStruct_sub_8010268 *r5)
{
    s32 i, speciesId, var;
    u8 text[1000];

    gUnknown_203B0E8 = r5->unkB0;
    gUnknown_2026E4E = 2566;
    sub_80095CC(0, 0x14);
    UpdateFadeInTile(2);
    sub_801059C();
    sub_8010494(&r5->unk4);
    sub_801178C();
    for (i = 0; i < 60; i++) {
        RunFrameActions();
    }
    AnimateMonPath(r5->unk4.unk0.id, r5->unk4.unk4.id);
    PrintDungeonName(&r5->unk4.unk4);
    for (i = 0; i < 60; i++) {
        RunFrameActions();
    }

    if (r5->unk4.unk10) {
        speciesId = r5->unk4.unk1C;
        ASM_MATCH_TRICK(speciesId);
    }
    else {
        speciesId = 0;
    }

    var = sub_809034C(r5->unk4.unk4.id, speciesId, text, r5->unk4.unk6C, FALSE);
    if (var == 0) {
        r5->unkB4 = 1;
    }
    else if (var == 1) {
        PrintDialogueMessage(text);
        r5->unkB4 = 0;
    }
    else if (var == 2) {
        if (ShowYesNoWindow(text)) {
            r5->unkB4 = 1;
        }
        else {
            r5->unkB4 = 0;
        }
    }

    FadeFromWorldMap();
    CloseFiles();
    nullsub_16();
}

// Heavy math function.
static void AnimateMonPath(u8 id1, u8 id2)
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
    AxResInitFile(&gUnknown_203B0E8->monAxSprite, gUnknown_203B0E8->unk1100[3], 0, r3, 0, 0, TRUE);

    for (i = 0; i < valMax; i++) {
        gUnknown_203B0E8->monSpritePos.x = ((((pos2.x - pos1.x) * (i << 8)) / valMax) / 256) + pos1.x;
        gUnknown_203B0E8->monSpritePos.y = ((((pos2.y - pos1.y) * (i << 8)) / valMax) / 256) + pos1.y;
        UpdateMonSpritePosition();
        UpdateBg();
        RunFrameActions();
        if (gRealInputs.pressed & A_BUTTON)
            break;
        if (gRealInputs.pressed & B_BUTTON)
            break;
    }

    gUnknown_203B0E8->monSpritePos = pos2;
    UpdateMonSpritePosition();
    UpdateBg();
    RunFrameActions();
}

static void sub_8010494(struct UnkStruct_sub_8010494 *r9)
{
    s32 i;
    for (i = 0; i < 64; i++) {
        struct UnkStruct_Sub1 *structPtr = &gUnknown_203B0E8->unk0[i];
        u8 r0;

        if (i < 63) {
            r0 = r9->unk6D[i];
        }
        else {
            r0 = 1;
        }

        if (r0) {
            structPtr->unk0 = 1;
            AxResInitFile(&structPtr->unk8, gUnknown_203B0E8->unk1100[2], (i == 63) ? 12 : 1, 0, 0x40, 0, 1);
            structPtr->unk4 = gDungeonCoordinates[i];
        }
        else {
            structPtr->unk0 = 0;
        }
    }

    AxResInitFile(&gUnknown_203B0E8->monAxSprite, gUnknown_203B0E8->unk1100[3], 0, 0, 0, 0, TRUE);
    gUnknown_203B0E8->monSpritePos = gDungeonCoordinates[r9->unk0.id];
    gUnknown_203B0E8->bgPos.x = gUnknown_203B0E8->monSpritePos.x - 120;
    gUnknown_203B0E8->bgPos.y = gUnknown_203B0E8->monSpritePos.y - 80;
    UpdateMonSpritePosition();
    UpdateBg();
}

static void sub_801059C(void)
{
    u8 filename[0xC];
    s32 i, size;

    PokemonStruct1 *pokeStruct = GetPlayerPokemonStruct();
    OpenedFile *file = OpenFileAndGetFileDataPtr(gUnknown_80D4014[0], &gTitleMenuFileArchive);
    OpenedFile *file2 = OpenFileAndGetFileDataPtr(gUnknown_80D4014[1], &gTitleMenuFileArchive);

    sprintf(filename, "ax%03d", pokeStruct->speciesNum);
    gUnknown_203B0E8->unk1100[3] = OpenFileAndGetFileDataPtr(filename, &gMonsterFileArchive);
    gUnknown_203B0E8->unk1100[2] = OpenFileAndGetFileDataPtr("wmapspr", &gTitleMenuFileArchive);
    gUnknown_203B0E8->unk1100[4] = OpenFileAndGetFileDataPtr(gUnknown_80D4014[2], &gTitleMenuFileArchive);
    gUnknown_203B0E8->unk1100[1] = OpenFileAndGetFileDataPtr("palet", &gMonsterFileArchive);
    gUnknown_203B0E8->unk1100[0] = OpenFileAndGetFileDataPtr(gUnknown_80D4014[3], &gTitleMenuFileArchive);
    gUnknown_203B0E8->unk52D4 = GetPokemonOverworldPalette(pokeStruct->speciesNum, 0);

    sub_8005610(gUnknown_203B0E8->unk1100[2], 0x40, 0x1F, 0);

    DecompressATGlobalFile((u32 *)(VRAM + 0x8000), 0x0, file);
    sub_8004AA4(gUnknown_203B0E8->unk5150, gUnknown_203B0E8->unk1100[4], 0x10);
    size = 0x4000;
    DecompressATFile((u8 *) &gUnknown_203B0E8->unk1114, size, file2);

    gUnknown_203B0E8->brightness = 0;
    gUnknown_203B0E8->bgPos.x = 0;
    gUnknown_203B0E8->bgPos.y = 0;

    for (i = 0; i < 1500; i++) {
        gUnknown_203B0E8->unk52E0[i] |= 0xFFFF;
        gUnknown_203B0E8->unk5E98[i] = 0;
    }

    CloseFile(file);
    CloseFile(file2);
    ShowWindows(NULL, 1, 1);
}

static void CloseFiles(void)
{
    CloseFile(gUnknown_203B0E8->unk1100[4]);
    CloseFile(gUnknown_203B0E8->unk1100[3]);
    CloseFile(gUnknown_203B0E8->unk1100[2]);
    CloseFile(gUnknown_203B0E8->unk1100[0]);
    CloseFile(gUnknown_203B0E8->unk1100[1]);
}

static void UpdateMonSpritePosition(void)
{
    if (gUnknown_203B0E8->monSpritePos.x - gUnknown_203B0E8->bgPos.x < 48) {
        gUnknown_203B0E8->bgPos.x = gUnknown_203B0E8->monSpritePos.x - 48;
    }
    else if (gUnknown_203B0E8->monSpritePos.x - gUnknown_203B0E8->bgPos.x > 192) {
        gUnknown_203B0E8->bgPos.x = gUnknown_203B0E8->monSpritePos.x - 192;
    }

    if (gUnknown_203B0E8->monSpritePos.y - gUnknown_203B0E8->bgPos.y < 48) {
        gUnknown_203B0E8->bgPos.y = gUnknown_203B0E8->monSpritePos.y - 48;
    }
    else if (gUnknown_203B0E8->monSpritePos.y - gUnknown_203B0E8->bgPos.y > 112) {
        gUnknown_203B0E8->bgPos.y = gUnknown_203B0E8->monSpritePos.y - 112;
    }

    if (gUnknown_203B0E8->bgPos.x < 0) {
        gUnknown_203B0E8->bgPos.x = 0;
    }
    if (gUnknown_203B0E8->bgPos.y < 0) {
        gUnknown_203B0E8->bgPos.y = 0;
    }
    if (gUnknown_203B0E8->bgPos.x >= 240) {
        gUnknown_203B0E8->bgPos.x = 240;
    }
    if (gUnknown_203B0E8->bgPos.y >= 160) {
        gUnknown_203B0E8->bgPos.y = 160;
    }
}

static void UpdateBg(void)
{
    s32 i, j;
    s32 y1 = gUnknown_203B0E8->bgPos.y >> 3;
    s32 y2 = y1;

    for (i = 0; i < 21; i++) {
        s32 x1 = gUnknown_203B0E8->bgPos.x >> 3;
        s32 x2 = x1;

        for (j = 0; j < 31; j++) {
            x1 &= 0x1F;
            y1 &= 0x1F;

            gUnknown_202B038[2][y1][x1] = gUnknown_203B0E8->unk3114[y2][x2];
            gUnknown_202B038[3][y1][x1] = gUnknown_203B0E8->unk1114[y2][x2];
            x2++;
            x1++;
        }
        y2++;
        y1++;
    }

    sub_80098F8(2);
    sub_80098F8(3);
}

static void nullsub_24(void)
{

}

static void FadeFromWorldMap(void)
{
    s32 i;

    ClearWindows();
    sub_80117C4();
    for (i = 0; i < 60; i++) {
        gUnknown_203B0E8->brightness -= 2;
        RunFrameActions();
    }
}

static void ClearWindows(void)
{
    ShowWindows(NULL, TRUE, TRUE);
}

static void RunFrameActions(void)
{
    SetBG2RegOffsets(gUnknown_203B0E8->bgPos.x, gUnknown_203B0E8->bgPos.y);
    SetBG3RegOffsets(gUnknown_203B0E8->bgPos.x, gUnknown_203B0E8->bgPos.y);
    AnimateSprites(TRUE);
    FadeScreen();
    sub_8005838(NULL, 0);
    nullsub_8(gGameOptionsRef->unkA);
    sub_8005180();
    sub_80060EC();
    IncrementPlayTime(gPlayTimeRef);
    sub_800CB20();
    LoadBufferedInputs();
    CopySpritesToOam();
    sub_8005304();
    TransferBGPaletteBuffer();
    xxx_call_update_bg_vram();
    nullsub_24();
    sub_8009908();
    xxx_call_update_bg_sound_input();
    sub_8011860();
    ResetSprites(FALSE);
}

static bool8 FadeScreen(void)
{
    bool8 ret = FALSE;

    if (gUnknown_203B0E8->brightness < 31) {
        s32 i;
        RGB *color = (void *) gUnknown_203B0E8->unk1100[0]->data;

        if (++gUnknown_203B0E8->brightness >= 31) {
            gUnknown_203B0E8->brightness = 31;
        }

        for (i = 0; i < 224; color++, i++) {
            SetBGPaletteBufferColorRGB(i, color, gUnknown_203B0E8->brightness, NULL);
        }

        color = (void *) gUnknown_203B0E8->unk1100[1]->data;
        for (i = 0; i < 240; color++, i++) {
            SetBGPaletteBufferColorRGB(i + 256, color, gUnknown_203B0E8->brightness, NULL);
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
    pos = gUnknown_203B0E8->bgPos;
    RunAxAnimationFrame(&gUnknown_203B0E8->monAxSprite);
    if (a0) {
        DoAxFrame_800558C(&gUnknown_203B0E8->monAxSprite, gUnknown_203B0E8->monSpritePos.x - pos.x, gUnknown_203B0E8->monSpritePos.y - pos.y, 3, gUnknown_203B0E8->unk52D4, &var_2C);
    }

    for (i = 0; i < 64; i++) {
        struct UnkStruct_Sub1 *structPtr = &gUnknown_203B0E8->unk0[i];
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
    const s32 x = 12;
    Windows windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_NORMAL,
                .pos = {x, 2},
                .width = 16,
                .height = 2,
                .unk10 = 2,
            },
            [1] = {.type = WINDOW_TYPE_NORMAL},
            [2] = {.type = WINDOW_TYPE_NORMAL},
            [3] = {.type = WINDOW_TYPE_NORMAL},
        }
    };

    if (gUnknown_203B0E8->monSpritePos.y - gUnknown_203B0E8->bgPos.y <= 80) {
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

static void PrintDialogueMessage(const u8 *text)
{
    s32 i, a;
    CreateMenuDialogueBoxAndPortrait(text, NULL, 0, NULL, NULL, 3, 0, NULL, 0x301);
    do {
        DrawDialogueBoxString();
        RunFrameActions();
    } while (sub_80144A4(&a) != 0);

    for (i = 0; i < 10; i++) {
        RunFrameActions();
    }
}

static bool8 ShowYesNoWindow(u8 *str)
{
    s32 r2, i;
    MenuInputStruct menuInput;

    r2 = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            r2 += 12;
        }
    }
    r2 += 11;
    r2 /= 8;

    gUnknown_203B0EC.id[0].pos.y = 19 - r2;
    gUnknown_203B0EC.id[0].unk10 = r2;
    gUnknown_203B0EC.id[0].height = r2;
    gUnknown_203B0EC.id[1].pos.y = 14 - r2;
    ShowWindows(&gUnknown_203B0EC, TRUE, TRUE);
    sub_80073B8(0);
    PrintFormattedStringOnWindow(4, 0, str, 0, '\0');
    sub_80073E0(0);
    sub_80073B8(1);
    PrintFormattedStringOnWindow(10, 0, "Yes", 1, '\0');
    PrintFormattedStringOnWindow(10, 12, "No", 1, '\0');
    sub_80073E0(1);

    menuInput.menuIndex = 1;
    menuInput.unk1A = 2;
    menuInput.unk1C = 2;
    menuInput.unk1E = 0;
    menuInput.unk20 = 0;
    menuInput.unk4 = 0;
    menuInput.unk6 = 0;
    menuInput.unk0 = 1;
    menuInput.unkC = 0;
    menuInput.unkE = 0;
    menuInput.unk14.x = 0;
    menuInput.unk14.y = 0;
    menuInput.unk8.x = 8;
    menuInput.unk8.y = 8;
    sub_80137B0(&menuInput, 24);
    sub_801317C(&menuInput.unk28);
    while (1) {
        AddMenuCursorSprite(&menuInput);
        RunFrameActions();
        if (gRealInputs.repeated & DPAD_DOWN) {
            MoveMenuCursorDown(&menuInput);
            PlayCursorUpDownSoundEffect();
        }
        if (gRealInputs.repeated & DPAD_UP) {
            MoveMenuCursorUp(&menuInput);
            PlayCursorUpDownSoundEffect();
        }
        if ((gRealInputs.pressed & A_BUTTON) || menuInput.unk28.a_button) {
            PlayAcceptSoundEffect();
            break;
        }
    }

    if (menuInput.menuIndex == 0) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

static UNUSED void GetDungeonCoords(u8 id, DungeonPos *pos)
{
    pos->x = gDungeonCoordinates[id].x;
    pos->y = gDungeonCoordinates[id].y;
}

