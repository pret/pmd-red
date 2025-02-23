#include "constants/input.h"
#include "global.h"
#include "globaldata.h"
#include "menu_input.h"
#include "sprite.h"
#include "code_80118A4.h"
#include "string_format.h"
#include "bg_palette_buffer.h"
#include "input.h"
#include "text.h"
#include "game_options.h"
#include "pokemon.h"
#include "code_800D090.h"
#include "rescue_team_info.h"
#include "event_flag.h"

#include "data/code_80140DC.h"

void sub_80140DC(void)
{
    DungeonPos pos;

    pos.x = 200;
    pos.y = 128;
    SetSavingIconCoords(&pos);
    sub_8011830();
}

void sub_80140F8(void)
{
    DungeonPos pos;

    pos.x = 188;
    pos.y = 64;
    SetSavingIconCoords(&pos);
    sub_8011830();
}

void sub_8014114(void) {
    xxx_call_start_bg_music();
    SetSavingIconCoords(NULL);
}

void nullsub_201(void) {}

u32 sub_8014128(void) {
    if(sub_8012AE8() == INPUT_B_BUTTON) return 0;
    else return 1;
}

u32 sub_801413C(void)
{
    return 0;
}

u32 sub_8014140(void)
{
    return 0;
}

// This kinda looks like the 'true' beginning of the file
static const u32 gUnknown_80D48A0[] = {0x7, 0x2, 0x2};
static const struct Window gUnknown_80D48AC = {
    0x00,
    0x00, 0x00,
    0x00, 0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00, 0x00
};

static const Window gUnknown_80D48C4 = {
    0x00, 0x00, 0x00, 0x00,
    0x00,
    0x02, 0x0F,
    0x1A, 0x05,
    0x07, 0x00,
    NULL
};

static const Window gUnknown_80D48DC = {
    0x00, 0x00, 0x00, 0x00,
    0x02,
    0x02, 0x08,
    0x1A, 0x05,
    0x07, 0x00,
    NULL
};


ALIGNED(4) static const u8 sSpeakerNameSeparator[] = ": ";
ALIGNED(4) static const u8 sUnknownTeamName[] = "????";
ALIGNED(4) static const u8 gUnknown_80D4900[] = "%d";
ALIGNED(4) static const u8 gUnknown_80D4904[] = "%*d" ;
extern const u8 gUnknown_80D4908[];
extern const u8 gUnknown_80D4910[];

extern void SetCharacterMask(int a0);
extern void DisplayMonPortraitSprite(s32 a0, const u8 *compressedData, s32 a2);
extern void sub_80073E0(s32 a0);
extern void sub_8011A04(void);

static void sub_8014A88(void);
static bool8 sub_8014B94(void);
static void nullsub_35(void);
static bool8 AppendString(const u8 *, u8 **, u8 *, u16 r3);

// 'd', 'v' and 'V'
EWRAM_DATA s32 gFormatArgs[10] = {0};
// 'i', apparently only i0 and i1 are actually used though it's yet to be verified
EWRAM_DATA u8 gFormatBuffer_Items[4][FORMAT_BUFFER_LEN] = {0};
// 'm' which probably stands for 'monster', available through m0 to m9
EWRAM_DATA u8 gFormatBuffer_Monsters[10][FORMAT_BUFFER_LEN] = {0};
// 'n' which probably stands for 'name', available through n0 to n9
EWRAM_DATA u8 gFormatBuffer_Names[10][FORMAT_BUFFER_LEN] = {0};
// Current textbox's speaker's name
EWRAM_DATA u8 gSpeakerNameBuffer[FORMAT_BUFFER_LEN] = {0};
// 'h' - Friend Area buffer. This buffer seems larger than others. It's possible it actually has the same length, but there were some unused buffers right after it.
EWRAM_DATA u8 gFormatBuffer_FriendArea[FRIEND_AREA_BUFFER_LEN] = {0};

static EWRAM_DATA SpriteOAM sDialogueBoxArrowSprite = {0};

// 't' - team name. This buffer seems wastefully large, given team name can be max 10(or so) characters.
static EWRAM_DATA u8 sFormatBuffer_TeamName[FORMAT_BUFFER_LEN] = {0};

static EWRAM_DATA s32 gUnknown_202E738 = 0;
static EWRAM_DATA s32 gUnknown_202E73C = 0;
static EWRAM_DATA s32 gUnknown_202E740 = 0;
static EWRAM_DATA s32 gUnknown_202E744 = 0;
static EWRAM_DATA struct UnkDrawStringStruct gUnknown_202E748 = {0};
static EWRAM_DATA u16 sUnknownTextFlags = 0;
static EWRAM_DATA s32 gUnknown_202E780 = 0;
static EWRAM_DATA s32 gUnknown_202E784 = 0;
static EWRAM_DATA s32 gUnknown_202E788 = 0;
static EWRAM_DATA s32 gUnknown_202E78C = 0;
static EWRAM_DATA bool8 gUnknown_202E790 = FALSE;
static EWRAM_DATA u8 sArrowFrames = 0;
static EWRAM_DATA const u8 *gUnknown_202E794 = NULL;

#define DIALOGUE_TEXT_BUFFER_SIZE 1000
static EWRAM_DATA u8 sDialogueTextBuffer[DIALOGUE_TEXT_BUFFER_SIZE] = {0};
static EWRAM_DATA u8 sFormatBuffer_UnknownMonster[64] = {0};
static EWRAM_DATA MenuStruct gUnknown_202EBC0 = {0};
static EWRAM_DATA u32 gUnknown_202EC10 = 0;
static EWRAM_DATA const MenuItem *sDialogueMenuItems = NULL;
static EWRAM_DATA void *gUnknown_202EC18 = NULL;
static EWRAM_DATA s32 gUnknown_202EC1C = 0;

// Only read, but never written to. Possibly used in Blue?
struct NeverWrittenToStruct202EC20
{
    struct Window unk0;
    const u8 *unk18;
};
static EWRAM_DATA struct NeverWrittenToStruct202EC20 *sNeverWrittenToUnknownStructPtr = NULL;
static UNUSED EWRAM_DATA u8 sUnusedEwram1[4] = {0};

static EWRAM_DATA MenuInputStructSub gUnknown_202EC28 = {0};

static EWRAM_INIT Windows sUnknown_203B198 = {
    .id = {
        [0] = {
            .pos = {2, 15},
            .width = 26,
            .height = 5,
            .unk10 = 7,
        },
        [1] = {
            .unk0 = 0x40,
            .type = WINDOW_TYPE_7,
        },
        [2] = {
            .type = WINDOW_TYPE_NORMAL,
        },
        [3] = {
            .type = WINDOW_TYPE_NORMAL,
        }
    }
};

void sub_8014144(void)
{
    gUnknown_202E744 = 0;
    gUnknown_202E738 = 60;
    gUnknown_202E73C = 60;
    gUnknown_202E740 = 0;
}

void sub_801416C(s32 param_1,s32 param_2)
{
    if (param_1 < -1) {
        gUnknown_202E738 = param_2;
        gUnknown_202E740 = -param_1;
    }
    else {
        gUnknown_202E738 = param_1;
        gUnknown_202E740 = 0;
    }
    gUnknown_202E73C = (param_2 < 0 ) ? 0 : param_2;
}

void CreateDialogueBoxAndPortrait(const u8 *text, void *param_2, struct MonPortraitMsg *monPortraitPtr, u16 flags)
{
    CreateMenuDialogueBoxAndPortrait(text, param_2, -1, NULL, NULL, 3, 0, monPortraitPtr, flags);
}

void CreateYesNoDialogueBoxAndPortrait_DefaultYes(const u8 *text, struct MonPortraitMsg *monPortraitPtr, u16 flags)
{
    CreateMenuDialogueBoxAndPortrait(text, NULL, -1, gUnknown_80D485C, NULL, 3, 0, monPortraitPtr, flags | 0x300);
}

void CreateYesNoDialogueBoxAndPortrait_DefaultNo(const u8 *text, struct MonPortraitMsg *monPortraitPtr, u16 flags)
{
    CreateMenuDialogueBoxAndPortrait(text, NULL, -1, gUnknown_80D4880, NULL, 3, 0, monPortraitPtr, flags | 0x300);
}

void CreateMenuDialogueBoxAndPortrait(const u8 *text, void *a1, u32 r9, const MenuItem *menuItems, void *arg_0, u32 a5, u32 unknownUnused, struct MonPortraitMsg *monPortraitPtr, u16 flags)
{
    bool8 portraitOn = FALSE;

    FormatString(text, sDialogueTextBuffer, sDialogueTextBuffer + DIALOGUE_TEXT_BUFFER_SIZE - 1, flags);
    gUnknown_202E794 = sDialogueTextBuffer;
    gUnknown_202E748.unk24 = a1;
    gUnknown_202EC10 = a5;
    sDialogueMenuItems = menuItems;
    gUnknown_202EC18 = arg_0;
    gUnknown_202EC1C = r9;
    sub_801317C(&gUnknown_202EC28);
    if (flags & 0x10) {
        sUnknown_203B198.id[0] = gUnknown_80D48DC;
    }
    else {
        sUnknown_203B198.id[0] = gUnknown_80D48C4;
    }

    sUnknown_203B198.id[1].width = 0;
    sUnknown_203B198.id[1].height = 0;
    sUnknown_203B198.id[1].unk10 = 0;
    sUnknown_203B198.id[1].unk0 = 0x40;

    if (monPortraitPtr != NULL && monPortraitPtr->faceData != NULL && monPortraitPtr->faceData->sprites[monPortraitPtr->spriteId].gfx != 0) {
        s32 i;

        sUnknown_203B198.id[1].pos.x = monPortraitPtr->pos.x;
        sUnknown_203B198.id[1].pos.y = monPortraitPtr->pos.y;
        sUnknown_203B198.id[1].width = 5;
        sUnknown_203B198.id[1].height = 5;
        sUnknown_203B198.id[1].unk10 = 5;
        for (i = 0; i < 16; i++) {
            SetBGPaletteBufferColorArray(224 + i, &monPortraitPtr->faceData->sprites[monPortraitPtr->spriteId].pal[i]);
        }
        portraitOn = TRUE;
        if (monPortraitPtr->unkE) {
            sUnknown_203B198.id[1].type = WINDOW_TYPE_7;
        }
        else {
            sUnknown_203B198.id[1].type = WINDOW_TYPE_FILL_TRANSPARENT;
        }
    }

    sUnknown_203B198.id[2] = gUnknown_80D48AC;
    sUnknown_203B198.id[3] = gUnknown_80D48AC;
    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B198, TRUE, TRUE);
    gUnknown_202E748.unk0 = 4;
    gUnknown_202E748.unk2 = 4;
    gUnknown_202E748.unk8 = 0x70;
    gUnknown_202E748.unkA = (gUnknown_2027370[0].unk2 * 8) + 34;
    gUnknown_202E748.unk10 = 7;
    gUnknown_202E748.unk1C = 0;
    gUnknown_202E748.unk20 = 0;
    SetCharacterMask((flags & 0x10) ? 8 : 3);
    gUnknown_202E744 = 1;
    sUnknownTextFlags = flags;
    if (flags & 0x20) {
        gUnknown_202E790 = TRUE;
    }
    else {
        gUnknown_202E790 = FALSE;
    }

    if (flags & 0x400) {
        SetWindowBGColor();
    }
    gUnknown_202E788 = 1;
    gUnknown_202E78C = 1;
    UnpressButtons();
    sArrowFrames = 0;
    gUnknown_202E784 = 0;
    if (portraitOn) {
        const u8 *data = monPortraitPtr->faceData->sprites[monPortraitPtr->spriteId].gfx;

        sub_80073B8(1);
        if (!monPortraitPtr->flip) {
            DisplayMonPortraitSprite(1, data, 0xE);
        }
        else {
            DisplayMonPortraitSpriteFlipped(1, data, 0xE);
        }
        sub_80073E0(1);
    }
}

void sub_8014490(void)
{
    gUnknown_202E744 = 0;
    gUnknown_202EC1C = 0;
}

s32 sub_80144A4(s32 *a0)
{
    if (a0 != NULL) {
        *a0 = gUnknown_202EC1C;
    }
    return gUnknown_202E744;
}

void DrawDialogueBoxString(void)
{
    bool8 keepLooping = TRUE;

    gUnknown_202E784++;
    while (keepLooping) {
        switch (gUnknown_202E744) {
            case 0: {
                keepLooping = FALSE;
            }
            break;
            case 1: {
                const u8 *str = gUnknown_202E794;
                s32 r7;

                if (gUnknown_202E790) {
                    r7 = 99999;
                }
                else {
                    r7 = gUnknown_202E788;
                }
                gUnknown_202E748.unk2C = 0;
                sub_80073B8(0);
                while (r7 > 0) {
                     str = xxx_handle_format_global(str, &gUnknown_202E748);
                     if (gUnknown_202E748.unk21 != 0) {
                        break;
                     }
                     if (gUnknown_202E748.unk20 != 0) {
                        if (gUnknown_202E748.unk2 > 34) {
                            gUnknown_202E744 = 8;
                            gUnknown_202E780 = gUnknown_202E738;
                        }
                        else {
                            gUnknown_202E744 = 7;
                            gUnknown_202E780 = gUnknown_202E73C;
                        }
                        sArrowFrames = 0;
                        break;
                     }
                     if (*str == '\0') {
                        break;
                     }

                     if (*str == '\r' || *str == '\n') {
                        gUnknown_202E748.unk0 = 4;
                        gUnknown_202E748.unk2 += 11;
                        str++;
                     }
                     else {
                        u32 sp;

                        str = xxx_get_next_char_from_string(str, &sp);
                        gUnknown_202E748.unk0 += xxx_call_draw_char(gUnknown_202E748.unk0, gUnknown_202E748.unk2, sp, gUnknown_202E748.unk10, 0);
                        gUnknown_202E748.unk2C = gUnknown_202E78C;
                     }

                     if (gUnknown_202E748.unk2 > 34) {
                        if (!(sUnknownTextFlags & 0x10)) {
                            gUnknown_202E748.unk1C = 0;
                            gUnknown_202E748.unk20 = 1;
                            gUnknown_202E744 = 8;
                            sArrowFrames = 0;
                            gUnknown_202E780 = gUnknown_202E738;
                            break;
                        }
                        else {
                            gUnknown_202E748.unk2 = 4;
                        }
                     }
                     r7--;
                }
                sub_80073E0(0);
                gUnknown_202E794 = str;
                sub_801317C(&gUnknown_202EC28);
                if (gUnknown_202E794[0] == '\0') {
                    if (sDialogueMenuItems != NULL) {
                        gUnknown_202E744 = 3;
                    }
                    else {
                        gUnknown_202E744 = 6;
                    }
                    keepLooping = FALSE;
                }
                else {
                    gUnknown_202E748.unk30 = 0;
                    if (gUnknown_202E748.unk20 != 0) {
                        if (gUnknown_202E744 == 1) {
                            gUnknown_202E744 = 7;
                            sArrowFrames = 0;
                            gUnknown_202E780 = gUnknown_202E738;
                        }
                        keepLooping = FALSE;
                    }
                    else {
                        gUnknown_202E744 = 2;
                    }
                }
            }
            break;
            case 2: {
                if (sUnknownTextFlags & 4) {
                    sub_8011A04();
                }
                if (!(sUnknownTextFlags & 2)) {
                    if (sUnknownTextFlags & 0x40 && gRealInputs.pressed & AB_BUTTONS) {
                        gUnknown_202E790 = TRUE;
                        gUnknown_202E748.unk30 = 99999;
                    }
                }

                if (++gUnknown_202E748.unk30 > gUnknown_202E748.unk2C) {
                    gUnknown_202E744 = 1;
                    gUnknown_202E748.unk21 = 0;
                }
                else {
                    keepLooping = FALSE;
                }
            }
            break;
            case 6: {
                if (sUnknownTextFlags & 0x100) {
                    gUnknown_202E744 = 9;
                    sArrowFrames = 0;
                    if (gUnknown_202E740 > 0) {
                        gUnknown_202E780 = gUnknown_202E740 - gUnknown_202E784;
                        if (gUnknown_202E780 < 0) {
                            gUnknown_202E744 = 11;
                            gUnknown_202E780 = 0;
                        }
                    }
                    else {
                        gUnknown_202E780 = gUnknown_202E738;
                    }
                }
                else {
                    gUnknown_202E744 = 11;
                }
            }
            break;
            case 7:
            case 8:
            case 9: {
                bool8 buttonPress = FALSE;
                gUnknown_202E748.unk20 = 0;
                nullsub_34(&gUnknown_202EC28, 0);
                if (!(sUnknownTextFlags & 1)) {
                    buttonPress = TRUE;
                }
                else
                {
                    if (sUnknownTextFlags & 2)
                    {
                        if (gUnknown_202E780 > 0) {
                            gUnknown_202E780--;
                        }
                        else {
                            buttonPress = TRUE;
                        }
                    }
                    else if (gRealInputs.pressed & AB_BUTTONS || gUnknown_202EC28.a_button) {
                        buttonPress = TRUE;
                    }
                    else if ((gRealInputs.held & (DPAD_ANY | B_BUTTON)) == B_BUTTON) {
                        buttonPress = TRUE;
                    }
                    else if (gUnknown_202EC28.unk5) {
                        buttonPress = TRUE;
                    }
                }

                if (!buttonPress) {
                    sArrowFrames++;
                    if (!(sUnknownTextFlags & 0x2) && sArrowFrames & 8) {
                        SpriteSetAffine1(&sDialogueBoxArrowSprite, 0);
                        SpriteSetAffine2(&sDialogueBoxArrowSprite, 0);
                        SpriteSetObjMode(&sDialogueBoxArrowSprite, 0);
                        SpriteSetMosaic(&sDialogueBoxArrowSprite, 0);
                        SpriteSetBpp(&sDialogueBoxArrowSprite, 0);
                        SpriteSetShape(&sDialogueBoxArrowSprite, 1);
                        SpriteSetMatrixNum(&sDialogueBoxArrowSprite, 0);
                        SpriteSetSize(&sDialogueBoxArrowSprite, 0);
                        SpriteSetTileNum(&sDialogueBoxArrowSprite, 0x3F0);
                        SpriteSetPriority(&sDialogueBoxArrowSprite, 0);
                        SpriteSetPalNum(&sDialogueBoxArrowSprite, 15);

                        if (sUnknownTextFlags & 0x10) {
                            SpriteSetY(&sDialogueBoxArrowSprite, 120);
                            SpriteSetX(&sDialogueBoxArrowSprite, 112);
                        }
                        else {
                            SpriteSetY(&sDialogueBoxArrowSprite, gUnknown_202E748.unkA + 1);
                            SpriteSetX(&sDialogueBoxArrowSprite, gUnknown_202E748.unk8);
                        }

                        AddSprite(&sDialogueBoxArrowSprite, 0x100, NULL, NULL);
                    }
                }
                else {
                    if (*gUnknown_202E794 == '\0') {
                        gUnknown_202E744 = 11;
                    }
                    else if (gUnknown_202E744 == 9) {
                        gUnknown_202E744 = 11;
                    }
                    else if (gUnknown_202E744 == 8) {
                        gUnknown_202E748.unk0 = 4;
                        if (gUnknown_202E748.unk2 > 34) {
                            gUnknown_202E748.unk2 = 4;
                            if (sUnknownTextFlags & 0x10) {
                                CallPrepareTextbox_8008C54(0);
                                gUnknown_202E744 = 1;
                            }
                            else if (gUnknown_202E748.unk1C != 0) {
                                CallPrepareTextbox_8008C54(0);
                                gUnknown_202E744 = 1;
                            }
                            else {
                                gUnknown_202E744 = 10;
                                gUnknown_202E748.unk28 = 0;
                            }
                        }
                        else {
                            gUnknown_202E744 = 1;
                        }
                    }
                    else {
                        gUnknown_202E744 = 1;
                    }

                    gUnknown_202E748.unk8 = 0x70;
                    gUnknown_202E748.unkA = (gUnknown_2027370[0].unk2 * 8) + 34;
                }
                keepLooping = FALSE;
            }
            break;
            case 10: {
                gUnknown_202E748.unk28++;
                gIwramTextFunc3(0);
                if (gUnknown_202E748.unk28 > 17) {
                    gUnknown_202E744 = 1;
                }
                keepLooping = FALSE;
            }
            break;
            case 11: {
                if (sUnknownTextFlags & 0x200) {
                    ResetUnusedInputStruct();
                    ShowWindows(NULL, TRUE, TRUE);
                    gUnknown_202E744 = 0;
                }
                else {
                    gUnknown_202E744 = 0;
                }
                keepLooping = FALSE;
            }
            break;
            case 3: {
                sub_8014A88();
                gUnknown_202E744 = 4;
                keepLooping = FALSE;
            }
            break;
            case 4: {
                if (sub_8014B94()) {
                    gUnknown_202E744 = 5;
                }
                keepLooping = FALSE;
            }
            break;
            case 5: {
                nullsub_35();
                gUnknown_202E744 = 11;
            }
            break;
        }
    }
}

static void sub_8014A88(void)
{
    s32 r2, r1;
    u8 text[128];
    const MenuItem *menuItem = sDialogueMenuItems;
    s32 r5 = 0;
    s32 r7 = 0;
    s32 i;

    for (i = 0; i < 10; menuItem++, i++) {
        s32 val;

        if (menuItem->text == NULL)
            break;

        r5 += 12;
        FormatString(menuItem->text, text, text + sizeof(text), 0);
        val = sub_8008ED0(text);
        if (r7 < val) {
            r7 = val;
        }
    }

    r2 = r5 / 8;
    if (r5 % 8)
        r2++;

    sUnknown_203B198.id[2].type = gUnknown_202EC10;
    r1 = r7 / 8;
    r1 += 2;
    sUnknown_203B198.id[2].width = r1;
    sUnknown_203B198.id[2].unk10 = r2;
    sUnknown_203B198.id[2].height = r2;
    sUnknown_203B198.id[2].pos.x = 28 - r1;
    sUnknown_203B198.id[2].pos.y = 14 - r2;
    sUnknown_203B198.id[0].unk0 = 0x80;
    sUnknown_203B198.id[1].unk0 = 0xC0;
    if (sNeverWrittenToUnknownStructPtr != NULL) {
        sUnknown_203B198.id[3] = sNeverWrittenToUnknownStructPtr->unk0;
    }
    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B198, TRUE, FALSE);
    sub_8012D60(&gUnknown_202EBC0, sDialogueMenuItems, gUnknown_80D48A0, gUnknown_202EC18, gUnknown_202EC1C, 2);
    if (sNeverWrittenToUnknownStructPtr != NULL) {
        sub_80073B8(3);
        PrintStringOnWindow(4, 2, sNeverWrittenToUnknownStructPtr->unk18, 3, 0);
        sub_80073E0(3);
    }
}

static bool8 sub_8014B94(void)
{
    if (!sub_8012FD8(&gUnknown_202EBC0)) {
        sub_8013114(&gUnknown_202EBC0, &gUnknown_202EC1C);
        return TRUE;
    }
    else {
        return FALSE;
    }
}

static void UNUSED nullsub_35(void)
{
}

const u8 *FormatString(const u8 *str, u8 *dst, u8 *dstMax, u16 flags)
{
    u8 txtArray[60];
    bool8 r10 = TRUE;
    bool8 r9 = TRUE;
    dstMax--;

    while (1) {
        u8 currChar = *str;

        if (currChar == '\0')
            break;
        if (currChar == '\r' || currChar == '\n') {
            if (flags & 0x80)
                break;
            r9 = TRUE;
        }
        else {
            if (r10) {
                r10 = FALSE;
                r9 = FALSE;
                if (flags & 8) {
                    AppendString(gSpeakerNameBuffer, &dst, dstMax, flags);
                    AppendString(sSpeakerNameSeparator, &dst, dstMax, flags);
                }
            }
            else if (r9) {
                r9 = FALSE;
            }
        }

        if (currChar == '#') {
            u8 chrPls1 = str[1];
            if (chrPls1 == 'P' || chrPls1 == 'p') {
                r10 = TRUE;
                r9 = TRUE;
            }
            if (dst + 1 < dstMax) {
                *(dst++) = '#';
                *(dst++) = chrPls1;
            }

            str += 2;
        }
        else if (currChar == '$') {
            const u8 *txtPtr = NULL;
            str++;

            switch (*str) {
                case 'i':
                    str++;
                    txtPtr = gFormatBuffer_Items[*str - '0'];
                    str++;
                    break;
                case 'm':
                    str++;
                    if (*str == 'm') {
                        PokemonStruct1 *monStruct = sub_808D3BC();
                        txtPtr = sFormatBuffer_UnknownMonster;
                        PrintColoredPokeNameToBuffer(sFormatBuffer_UnknownMonster, monStruct, 0);
                    }
                    else {
                        txtPtr = gFormatBuffer_Monsters[*str - '0'];
                        str++;
                    }
                    break;
                case 'n':
                    str++;
                    txtPtr = gFormatBuffer_Names[*str - '0'];
                    str++;
                    break;
                case 't':
                    str++;
                    if (sub_80023E4(0)) {
                        sub_80920D8(sFormatBuffer_TeamName);
                    }
                    else {
                        strcpy(sFormatBuffer_TeamName, sUnknownTeamName); // ????
                    }
                    txtPtr = sFormatBuffer_TeamName;
                    break;
                case 'h':
                    str++;
                    txtPtr = gFormatBuffer_FriendArea;
                    break;
                case 'd':
                    str++;
                    sprintfStatic(txtArray, gUnknown_80D4900, gFormatArgs[*(str++) - '0']);
                    txtPtr = txtArray;
                    break;
                case 'v': {
                    s32 a;
                    u8 *unkTxtPtr;

                    str++;
                    a = gFormatArgs[*(str++) - '0'];
                    sprintfStatic(txtArray, gUnknown_80D4904, *(str++) - '0', a);
                    unkTxtPtr = txtArray;
                    while (*unkTxtPtr != '\0') {
                        if (*unkTxtPtr == ' ') {
                            *unkTxtPtr = '`';
                        }
                        unkTxtPtr++;
                    }
                    txtPtr = txtArray;
                    }
                    break;
                // the same as above except "%0*d" instead of "%*d"
                case 'V': {
                    s32 a;
                    u8 *unkTxtPtr;

                    str++;
                    a = gFormatArgs[*(str++) - '0'];
                    sprintfStatic(txtArray, gUnknown_80D4908, *(str++) - '0', a);
                    unkTxtPtr = txtArray;
                    while (*unkTxtPtr != '\0') {
                        if (*unkTxtPtr == ' ') {
                            *unkTxtPtr = '`';
                        }
                        unkTxtPtr++;
                    }
                    txtPtr = txtArray;
                    }
                    break;
                case '$':
                    txtPtr = gUnknown_80D4910;
                    break;
                case '-':
                    str++;
                    break;
            }

            if (txtPtr != NULL) {

                if (AppendString(txtPtr, &dst, dstMax, flags))
                    break;
            }
        }
        else if (currChar == 0x81 || currChar == 0x82 || currChar == 0x83 || currChar == 0x84 || currChar == 0x87) {
            if (dst < dstMax) {
                *(dst++) = currChar;
            }
            str++;
            if (*str == '\0')
                break;
            if (dst < dstMax) {
                *(dst++) = *str;
            }
            str++;
        }
        else {
            if (dst < dstMax) {
                *(dst++) = currChar;
            }
            str++;
        }
    }

    *dst = 0;
    if (*str == '\r') str++;
    if (*str == '\n') str++;

    return str;
}

static bool8 AppendString(const u8 *str, u8 **dstPtr, u8 *dstMax, u16 flags)
{
    u8 *dst = *dstPtr;
    while (*str != '\0') {
        if (flags & 0x80 && *str == '\r') {
            *dstPtr = dst;
            return TRUE;
        }
        if (dst < dstMax) {
            *dst = *str;
            dst++;
        }
        str++;
    }

    *dstPtr = dst;
    return FALSE;
}

#define FORMAT_STR_MAX_LEN 500

void PrintFormattedStringOnWindow(s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr)
{
    u8 formattedString[FORMAT_STR_MAX_LEN];

    FormatString(str, formattedString, formattedString + FORMAT_STR_MAX_LEN, 0);
    formattedString[FORMAT_STR_MAX_LEN - 1] = '\0';
    PrintStringOnWindow(x, y, formattedString, windowId, terminatingChr);
}

void PrintFormattedStringOnWindow2(s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr, s32 lineSpacing)
{
    u8 formattedString[FORMAT_STR_MAX_LEN];

    FormatString(str, formattedString, formattedString + FORMAT_STR_MAX_LEN, 0);
    formattedString[FORMAT_STR_MAX_LEN - 1] = '\0';
    PrintStringOnWindow2(x, y, formattedString, windowId, terminatingChr, lineSpacing);
}

//
