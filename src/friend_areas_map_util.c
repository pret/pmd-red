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
#include "game_options.h"
#include "play_time.h"
#include "code_80118A4.h"
#include "code_800C9CC.h"
#include "pokemon.h"
#include "decompress.h"
#include "constants/direction.h"

extern void sub_800CB20(void);
extern void xxx_call_update_bg_sound_input(void);
extern s32 sprintf(char *, const char *, ...);

extern const FileArchive gTitleMenuFileArchive;
extern const FileArchive gMonsterFileArchive;

static inline bool8 CheckAxFlag8000(axdata *ptr)
{
    return (ptr->flags & 0x8000) != 0;
}

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

void sub_8010DA4(void)
{
    u8 filename[0xC];
    s32 i, size;

    PokemonStruct1 *pokeStruct = GetPlayerPokemonStruct();
    OpenedFile *file = OpenFileAndGetFileDataPtr(gUnknown_80D408C[0], &gTitleMenuFileArchive);
    OpenedFile *file2 = OpenFileAndGetFileDataPtr(gUnknown_80D408C[1], &gTitleMenuFileArchive);

    sprintf(filename, "ax%03d", pokeStruct->speciesNum);
    gUnknown_203B0E4->unk0[3] = OpenFileAndGetFileDataPtr(filename, &gMonsterFileArchive);
    gUnknown_203B0E4->unk0[2] = OpenFileAndGetFileDataPtr("wmapspr", &gTitleMenuFileArchive);
    gUnknown_203B0E4->unk0[4] = OpenFileAndGetFileDataPtr(gUnknown_80D408C[2], &gTitleMenuFileArchive);
    gUnknown_203B0E4->unk0[1] = OpenFileAndGetFileDataPtr("palet", &gMonsterFileArchive);
    gUnknown_203B0E4->unk0[0] = OpenFileAndGetFileDataPtr(gUnknown_80D408C[3], &gTitleMenuFileArchive);
    gUnknown_203B0E4->unk4DD0 = GetPokemonOverworldPalette(pokeStruct->speciesNum, 0);

    sub_8005610(gUnknown_203B0E4->unk0[2], 0x40, 0x1F, 0);

    DecompressATGlobalFile((u32 *)(VRAM + 0x8000), 0x0, file);
    sub_8004AA4(gUnknown_203B0E4->unk4C4C, gUnknown_203B0E4->unk0[4], 0x10);
    size = 0x4000;
    DecompressATFile((u8 *) &gUnknown_203B0E4->unk14, size, file2);

    gUnknown_203B0E4->brightness = 0;
    gUnknown_203B0E4->bgPos.x = 0;
    gUnknown_203B0E4->bgPos.y = 0;

    for (i = 0; i < NUM_DIRECTIONS; i++) {
        ResetFlags(&gUnknown_203B0E4->arrowSprites[i]);
    }

    CloseFile(file);
    CloseFile(file2);
    ShowWindows(NULL, 1, 1);
}

void sub_8010EF0(void)
{
    CloseFile(gUnknown_203B0E4->unk0[4]);
    CloseFile(gUnknown_203B0E4->unk0[2]);
    CloseFile(gUnknown_203B0E4->unk0[3]);
    CloseFile(gUnknown_203B0E4->unk0[0]);
    CloseFile(gUnknown_203B0E4->unk0[1]);
}

static void AnimateSprites(void)
{
    s32 i, dir;
    unkStruct_2039DB0 var_30;
    DungeonPos bgPos;

    sub_8004E8C(&var_30);
    var_30.unk4 = 0xF3FF;
    var_30.unkA = 0x800;
    bgPos = gUnknown_203B0E4->bgPos;
    RunAxAnimationFrame(&gUnknown_203B0E4->monAxSprite);
    DoAxFrame_800558C(&gUnknown_203B0E4->monAxSprite, gUnknown_203B0E4->monSpritePos.x - bgPos.x, gUnknown_203B0E4->monSpritePos.y - bgPos.y, 3, gUnknown_203B0E4->unk4DD0, &var_30);

    for (i = 0; i < 32; i++) {
        struct UnkStruct_4018 *r0 = &gUnknown_203B0E4->unk4018[i];
        const struct FriendAreaLocation *location = &gUnknown_203B0E4->locations[i];
        if (r0->unk4018 != 0) {
            RunAxAnimationFrame(&r0->unk14);
            DoAxFrame_800558C(&r0->unk14, location->unk4.x - bgPos.x, location->unk4.y- bgPos.y, 1, 0, &var_30);
        }
    }

    for (dir = 0; dir < NUM_DIRECTIONS; dir++) {
        if (CheckAxFlag8000(&gUnknown_203B0E4->arrowSprites[dir])) {
            RunAxAnimationFrame(&gUnknown_203B0E4->arrowSprites[dir]);
            // Hide non-diagonal arrows when R button is pressed.
            if ((gRealInputs.held & R_BUTTON) && (dir % 2) == 0)
                continue;

            DoAxFrame_800558C(&gUnknown_203B0E4->arrowSprites[dir],
                              (gUnknown_80D40C4[dir].x + gUnknown_203B0E4->monSpritePos.x) - bgPos.x,
                              (gUnknown_80D40C4[dir].y + gUnknown_203B0E4->monSpritePos.y) - bgPos.y,
                              2, 0, &var_30);
        }
    }
}

void FriendAreasMap_UpdateBg(void)
{
    s32 i, j;
    s32 y1 = gUnknown_203B0E4->bgPos.y >> 3;
    s32 y2 = y1;

    for (i = 0; i < 21; i++) {
        s32 x1 = gUnknown_203B0E4->bgPos.x >> 3;
        s32 x2 = x1;

        for (j = 0; j < 31; j++) {
            x1 &= 0x1F;
            y1 &= 0x1F;

            gUnknown_202B038[2][y1][x1] = gUnknown_203B0E4->unk2014[y2][x2];
            gUnknown_202B038[3][y1][x1] = gUnknown_203B0E4->unk14[y2][x2];
            x2++;
            x1++;
        }
        y2++;
        y1++;
    }

    sub_80098F8(2);
    sub_80098F8(3);
}

void FriendAreasMap_HideTextWindowAndArrows(void)
{
    s32 i;

    ShowWindows(NULL, TRUE, TRUE);
    gUnknown_203B0E4->unk4DDC = 0;
    gUnknown_203B0E4->unk4DE0 = 0;
    gUnknown_203B0E4->unk4DE4 = 0;
    gUnknown_203B0E4->unk4DE8 = 0;
    for (i = 0; i < NUM_DIRECTIONS; i++) {
        ResetFlags(&gUnknown_203B0E4->arrowSprites[i]);
    }
}

static bool8 FadeScreen(void)
{
    bool8 ret = FALSE;

    if (gUnknown_203B0E4->brightness < 31) {
        s32 i;
        RGB *color = (void *) gUnknown_203B0E4->unk0[0]->data;

        if (++gUnknown_203B0E4->brightness >= 31) {
            gUnknown_203B0E4->brightness = 31;
        }

        for (i = 0; i < 224; color++, i++) {
            SetBGPaletteBufferColorRGB(i, color, gUnknown_203B0E4->brightness, NULL);
        }

        color = (void *) gUnknown_203B0E4->unk0[1]->data;
        for (i = 0; i < 240; color++, i++) {
            SetBGPaletteBufferColorRGB(i + 256, color, gUnknown_203B0E4->brightness, NULL);
        }

        ret = TRUE;
    }

    return ret;
}

void FriendAreasMap_UpdateMonSpritePosition(void)
{
    if (gUnknown_203B0E4->monSpritePos.x - gUnknown_203B0E4->bgPos.x < 48) {
        gUnknown_203B0E4->bgPos.x = gUnknown_203B0E4->monSpritePos.x - 48;
    }
    else if (gUnknown_203B0E4->monSpritePos.x - gUnknown_203B0E4->bgPos.x > 192) {
        gUnknown_203B0E4->bgPos.x = gUnknown_203B0E4->monSpritePos.x - 192;
    }

    if (gUnknown_203B0E4->monSpritePos.y - gUnknown_203B0E4->bgPos.y < 48) {
        gUnknown_203B0E4->bgPos.y = gUnknown_203B0E4->monSpritePos.y - 48;
    }
    else if (gUnknown_203B0E4->monSpritePos.y - gUnknown_203B0E4->bgPos.y > 112) {
        gUnknown_203B0E4->bgPos.y = gUnknown_203B0E4->monSpritePos.y - 112;
    }

    if (gUnknown_203B0E4->bgPos.x < 0) {
        gUnknown_203B0E4->bgPos.x = 0;
    }
    if (gUnknown_203B0E4->bgPos.y < 0) {
        gUnknown_203B0E4->bgPos.y = 0;
    }
    if (gUnknown_203B0E4->bgPos.x > 239) {
        gUnknown_203B0E4->bgPos.x = 239;
    }
    if (gUnknown_203B0E4->bgPos.y > 151) {
        gUnknown_203B0E4->bgPos.y = 151;
    }
}

void FriendAreasMap_ShowDirectionArrows(void)
{
    s32 i;
    struct UnkStruct_4018 *r9 = &gUnknown_203B0E4->unk4018[gUnknown_203B0E4->unk4A18];

    for (i = 0; i < NUM_DIRECTIONS; i++) {
        ResetFlags(&gUnknown_203B0E4->arrowSprites[i]);
        if (r9->unk2[i] >= 0) {
            struct UnkStruct_4018 *ptr = &gUnknown_203B0E4->unk4018[r9->unk2[i]];
            if (ptr->unk4018 != 0) {
                AxResInitFile(&gUnknown_203B0E4->arrowSprites[i], gUnknown_203B0E4->unk0[2], i + 4, 0, 0x40, 0, TRUE);
            }
        }
    }
}

void FriendAreasMap_PrintCurrAreaName(void)
{
    u8 txt[200];
    s32 id = gUnknown_203B0E4->unk4A18;
    const struct FriendAreaLocation *location = &gUnknown_203B0E4->locations[id];
    Windows windows = {0};

    windows.id[0].type = WINDOW_TYPE_NORMAL;
    windows.id[0].pos.x = 7;
    windows.id[0].pos.y = 2;
    windows.id[0].width = 21;
    windows.id[0].height = 2;
    windows.id[0].unk10 = 2;
    windows.id[1].type = WINDOW_TYPE_NORMAL;
    windows.id[2].type = WINDOW_TYPE_NORMAL;
    windows.id[3].type = WINDOW_TYPE_NORMAL;

    if (gUnknown_203B0E4->monSpritePos.y - gUnknown_203B0E4->bgPos.y <= 80) {
        windows.id[0].pos.y = 17;
    }
    else {
        windows.id[0].pos.y = 1;
    }

    ShowWindows(&windows, TRUE, TRUE);
    sub_80073B8(0);
    sprintfStatic(txt, _("{CENTER_ALIGN}%s"), location->name);
    PrintFormattedStringOnWindow(12, 2, txt, 0, '\0');
    sub_80073E0(0);
    gUnknown_203B0E4->unk4DDC = (windows.id[0].pos.x * 8) - 5;
    gUnknown_203B0E4->unk4DE0 = (windows.id[0].pos.y * 8) + 5;
    gUnknown_203B0E4->unk4DE4 = (windows.id[0].width * 8) + 10;
    gUnknown_203B0E4->unk4DE8 = (windows.id[0].height * 8) + 10;
}

void FriendAreasMap_PrintAvailableSubAreas(void)
{
    s32 i, count, var;
    s32 id = gUnknown_203B0E4->unk4A18;
    const struct FriendAreaLocation *location = &gUnknown_203B0E4->locations[id];
    MenuInputStruct *menuInput = &gUnknown_203B0E4->menu;
    WindowHeader header;
    Windows windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {7, 2},
                .width = 21,
                .height = 2,
                .unk10 = 2,
                .unk14 = &header,
            },
            [1] = {
                .type = WINDOW_TYPE_NORMAL,
            },
            [2] = {
                .type = WINDOW_TYPE_NORMAL,
            },
            [3] = {
                .type = WINDOW_TYPE_NORMAL,
            },
        }
    };

    count = 0;
    for (i = 0; i < 8; i++) {
        if (sub_800FFE8(location->unk8[i])) {
            gUnknown_203B0E4->unk4DEC[count] = location->unk8[i];
            count++;
        }
    }

    gUnknown_203B0E4->unk4DF8 = count;
    header.f0 = 1;
    header.f1 = 0;
    header.f2 = 18;
    header.f3 = 0;
    menuInput->menuIndex = 0;
    menuInput->unk1A = count;
    menuInput->unk1C = count;
    menuInput->unk1E = 0;
    menuInput->unk20 = 0;
    menuInput->unk4 = 0;
    menuInput->unk6 = 16;
    menuInput->unk0 = 0;
    menuInput->unkC = 0;
    menuInput->unkE = 0;
    menuInput->unk14.x = 0;
    menuInput->unk14.y = 0;
    menuInput->unk8.x = 8;
    menuInput->unk8.y = 8;
    sub_801317C(&menuInput->unk28);
    var = sub_80095E4(menuInput->unk1C, 0);
    windows.id[0].unk10 = windows.id[0].height = var + 2;
    sub_80137B0(menuInput, var * 8);

    ShowWindows(&windows, TRUE, TRUE);

    gUnknown_203B0E4->unk4DDC = 0;
    gUnknown_203B0E4->unk4DE0 = 0;
    gUnknown_203B0E4->unk4DE4 = 0;
    gUnknown_203B0E4->unk4DE8 = 0;
    sub_80073B8(0);
    PrintFormattedStringOnWindow(16, 0, _("Where would you like to go?"), 0, '\0');

    for (i = 0; i < count; i++) {
        unkStruct_8092638 unkFriendAreaStruct;
        s32 r4 = sub_8013800(menuInput, i);
        u8 r5 = gUnknown_203B0E4->unk4DEC[i];

        sub_80101F8(gFormatBuffer_Items[0], r5);
        if (r5 == 0) {
            PrintFormattedStringOnWindow(12, r4, _("{MOVE_ITEM_0}"), 0, '\0');
        }
        else {
            sub_80926F8(r5, &unkFriendAreaStruct, gUnknown_203B0E4->unk4A2C);
            gFormatArgs[0] = unkFriendAreaStruct.unk2;
            gFormatArgs[1] = unkFriendAreaStruct.numPokemon;
            PrintFormattedStringOnWindow(12, r4, _("{MOVE_ITEM_0}($v02／$v12)"), 0, '\0');
        }
    }

    sub_80073E0(0);
}

void FriendAreasMap_RunFrameActions(void)
{
    SetBG2RegOffsets(gUnknown_203B0E4->bgPos.x, gUnknown_203B0E4->bgPos.y);
    SetBG3RegOffsets(gUnknown_203B0E4->bgPos.x, gUnknown_203B0E4->bgPos.y);
    AnimateSprites();
    sub_8004AF0(FadeScreen(), gUnknown_203B0E4->unk4C4C, 0xB0, 16, gUnknown_203B0E4->brightness, NULL);
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
    sub_8009908();
    xxx_call_update_bg_sound_input();
    sub_8011860();
    ResetSprites(FALSE);
}

