#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "bg_palette_buffer.h"
#include "code_800D090.h"
#include "music_util.h"
#include "event_flag.h"
#include "game_options.h"
#include "input.h"
#include "menu_input.h"
#include "pokemon.h"
#include "rescue_team_info.h"
#include "sprite.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"
#include "text_3.h"

static const MenuItem sYesNoMenuItems[] =
{
        {_("*Yes"), 1},
        {_("No"), 0},
        {NULL, -1}
};

static const MenuItem sYesNoMenuItems_DefaultNo[] =
{
        {_("Yes"), 1},
        {_("*No"), 0},
        {NULL, -1}
};

static const u32 gUnknown_80D48A0[] = {0x7, 0x2, 0x2};
static const WindowTemplate gUnknown_80D48AC = {
    0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00, 0x00
};

static const WindowTemplate gUnknown_80D48C4 = {
    0x00,
    0x00,
    0x02, 0x0F,
    0x1A, 0x05,
    0x07, 0x00,
    NULL
};

static const WindowTemplate gUnknown_80D48DC = {
    0x00,
    0x02,
    0x02, 0x08,
    0x1A, 0x05,
    0x07, 0x00,
    NULL
};

extern void DisplayMonPortraitSprite(s32 a0, const u8 *compressedData, s32 a2);
extern void sub_80073E0(s32 a0);

static void sub_8014A88(void);
static bool8 sub_8014B94(void);
static void nullsub_35(void);
static bool8 AppendString(const u8 *, u8 **, u8 *, u16 r3);

// 'd', 'v' and 'V'
EWRAM_DATA s32 gFormatArgs[10] = {0}; // NDS=02134278
// 'i', apparently only i0 and i1 are actually used though it's yet to be verified
EWRAM_DATA u8 gFormatBuffer_Items[4][FORMAT_BUFFER_LEN] = {0}; // NDS=02134450
// 'm' which probably stands for 'monster', available through m0 to m9
EWRAM_DATA u8 gFormatBuffer_Monsters[10][FORMAT_BUFFER_LEN] = {0};
// 'n' which probably stands for 'name', available through n0 to n9
EWRAM_DATA u8 gFormatBuffer_Names[10][FORMAT_BUFFER_LEN] = {0};
// Current textbox's speaker's name
EWRAM_DATA u8 gSpeakerNameBuffer[FORMAT_BUFFER_LEN] = {0}; // NDS=02134400
// 'h' - Friend Area buffer. This buffer seems larger than others. It's possible it actually has the same length, but there were some unused buffers right after it.
EWRAM_DATA u8 gFormatBuffer_FriendArea[FRIEND_AREA_BUFFER_LEN] = {0};

static EWRAM_DATA SpriteOAM sDialogueBoxArrowSprite = {0};

// 't' - team name. This buffer seems wastefully large, given team name can be max 10(or so) characters.
static EWRAM_DATA u8 sFormatBuffer_TeamName[FORMAT_BUFFER_LEN] = {0};

static EWRAM_DATA s32 sAutoPressNewTextboxFrames = 0;
static EWRAM_DATA s32 sAutoPressMidTextboxFrames = 0;
static EWRAM_DATA s32 sAutoPressFramesEndMsg = 0;
static EWRAM_DATA s32 sPrintStringState = 0;
static EWRAM_DATA UnkDrawStringStruct sTextPrintStruct = {0};
static EWRAM_DATA u16 sStringFormatFlags = 0;
static EWRAM_DATA s32 sAutoPressFrames = 0;
static EWRAM_DATA s32 sDialoguePrintFrames = 0;
static EWRAM_DATA s32 sTextPrintSpeed = 0;
static EWRAM_DATA s32 sFramesBetweenCharPrints = 0;
static EWRAM_DATA bool8 sInstantText = FALSE;
static EWRAM_DATA u8 sArrowFrames = 0;
static EWRAM_DATA const u8 *sCurrStr = NULL;

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
    WindowTemplate unk0;
    const u8 *unk18;
};
static EWRAM_DATA struct NeverWrittenToStruct202EC20 *sNeverWrittenToUnknownStructPtr = NULL;
static UNUSED EWRAM_DATA u8 sUnusedEwram1[4] = {0};

static EWRAM_DATA TouchScreenMenuInput sDialogueMenuTouchScreenInput = {0};

static EWRAM_INIT WindowTemplates sUnknown_203B198 = {
    .id = {
        [0] = {
            .unk0 = 0,
            .type = WINDOW_TYPE_0,
            .pos = { .x = 2, .y = 15 },
            .width = 26,
            .height = 5,
            .unk10 = 7,
            .unk12 = 0,
            .header = NULL,
        },
        [1] = {
            .unk0 = 0x40,
            .type = WINDOW_TYPE_7,
            .pos = { .x = 0, .y = 0 },
            .width = 0,
            .height = 0,
            .unk10 = 0,
            .unk12 = 0,
            .header = NULL,
        },
        [2] = WIN_TEMPLATE_DUMMY,
        [3] = WIN_TEMPLATE_DUMMY,
    }
};

enum
{
    STATE_FINISHED,
    STATE_PRINT_CHAR,
    STATE_PRINT_CHAR_SOUND_WAIT,
    STATE_PRINT_FINISHED_MENU,
    STATE_4,
    STATE_5,
    STATE_PRINT_FINISHED,
    // These 3 are the same
    STATE_WAIT_FOR_BUTTON_MID_TEXTBOX,
    STATE_WAIT_FOR_BUTTON_NEW_TEXTBOX,
    STATE_WAIT_FOR_BUTTON_PRESS_END_MSG,
};

void ResetDialogueBox(void)
{
    sPrintStringState = STATE_FINISHED;
    sAutoPressNewTextboxFrames = 60;
    sAutoPressMidTextboxFrames = 60;
    sAutoPressFramesEndMsg = 0;
}

void SetDialogueBoxAutoPressFrames(s32 endMsgFrames, s32 midMsgFrames)
{
    if (endMsgFrames < -1) {
        sAutoPressNewTextboxFrames = midMsgFrames;
        sAutoPressFramesEndMsg = -endMsgFrames;
    }
    else {
        sAutoPressNewTextboxFrames = endMsgFrames;
        sAutoPressFramesEndMsg = 0;
    }
    sAutoPressMidTextboxFrames = (midMsgFrames < 0 ) ? 0 : midMsgFrames;
}

void CreateDialogueBoxAndPortrait(const u8 *text, void *param_2, MonPortraitMsg *monPortraitPtr, u16 flags)
{
    CreateMenuDialogueBoxAndPortrait(text, param_2, -1, NULL, NULL, 3, 0, monPortraitPtr, flags);
}

void CreateYesNoDialogueBoxAndPortrait_DefaultYes(const u8 *text, MonPortraitMsg *monPortraitPtr, u16 flags)
{
    CreateMenuDialogueBoxAndPortrait(text, NULL, -1, sYesNoMenuItems, NULL, 3, 0, monPortraitPtr, flags | 0x300);
}

void CreateYesNoDialogueBoxAndPortrait_DefaultNo(const u8 *text, MonPortraitMsg *monPortraitPtr, u16 flags)
{
    CreateMenuDialogueBoxAndPortrait(text, NULL, -1, sYesNoMenuItems_DefaultNo, NULL, 3, 0, monPortraitPtr, flags | 0x300);
}

#define TEXTBOX_LINE_HEIGHT 11
#define TEXTBOX_HEIGHT ((TEXTBOX_LINE_HEIGHT * 3) + 1)
#define TEXTBOX_OUT_OF_SPACE(y)(y > TEXTBOX_HEIGHT)

// arm9.bin::0201D700
void CreateMenuDialogueBoxAndPortrait(const u8 *text, void *a1, u32 r9, const MenuItem *menuItems, void *arg_0, u32 a5, u32 unknownUnused, MonPortraitMsg *monPortraitPtr, u16 flags)
{
    bool8 portraitOn = FALSE;

    FormatString(text, sDialogueTextBuffer, sDialogueTextBuffer + DIALOGUE_TEXT_BUFFER_SIZE - 1, flags);
    sCurrStr = sDialogueTextBuffer;
    sTextPrintStruct.unk24 = a1;
    gUnknown_202EC10 = a5;
    sDialogueMenuItems = menuItems;
    gUnknown_202EC18 = arg_0;
    gUnknown_202EC1C = r9;
    ResetTouchScreenMenuInput(&sDialogueMenuTouchScreenInput);
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
    sTextPrintStruct.x = 4;
    sTextPrintStruct.y = 4;
    sTextPrintStruct.unk8 = 0x70;
    sTextPrintStruct.unkA = (gWindows[0].y * 8) + TEXTBOX_HEIGHT;
    sTextPrintStruct.unk10 = 7;
    sTextPrintStruct.unk1C = 0;
    sTextPrintStruct.waitButtonPress = 0;
    SetCharacterMask((flags & 0x10) ? 8 : 3);
    sPrintStringState = 1;
    sStringFormatFlags = flags;
    if (flags & STR_FORMAT_FLAG_INSTANT_TEXT) {
        sInstantText = TRUE;
    }
    else {
        sInstantText = FALSE;
    }

    if (flags & 0x400) {
        SetWindowBGColor();
    }
    sTextPrintSpeed = 1;
    sFramesBetweenCharPrints = 1;
    UnpressButtons();
    sArrowFrames = 0;
    sDialoguePrintFrames = 0;
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
    sPrintStringState = STATE_FINISHED;
    gUnknown_202EC1C = 0;
}

s32 sub_80144A4(s32 *a0)
{
    if (a0 != NULL) {
        *a0 = gUnknown_202EC1C;
    }
    return sPrintStringState;
}

// arm9.bin::0201CEB0
void DrawDialogueBoxString(void)
{
    bool8 keepLooping = TRUE;

    sDialoguePrintFrames++;
    while (keepLooping) {
        switch (sPrintStringState) {
            case STATE_FINISHED: {
                keepLooping = FALSE;
            }
            break;
            case STATE_PRINT_CHAR: {
                const u8 *str = sCurrStr;
                s32 txtSpeed;

                if (sInstantText) {
                    txtSpeed = 99999;
                }
                else {
                    txtSpeed = sTextPrintSpeed;
                }
                sTextPrintStruct.framesToWait = 0;
                sub_80073B8(0);
                while (txtSpeed > 0) {
                     str = HandleSpecialCharFormat(str, &sTextPrintStruct);
                     if (sTextPrintStruct.waitFrames) {
                        break;
                     }
                     if (sTextPrintStruct.waitButtonPress) {
                        if (TEXTBOX_OUT_OF_SPACE(sTextPrintStruct.y)) {
                            sPrintStringState = STATE_WAIT_FOR_BUTTON_NEW_TEXTBOX;
                            sAutoPressFrames = sAutoPressNewTextboxFrames;
                        }
                        else {
                            sPrintStringState = STATE_WAIT_FOR_BUTTON_MID_TEXTBOX;
                            sAutoPressFrames = sAutoPressMidTextboxFrames;
                        }
                        sArrowFrames = 0;
                        break;
                     }
                     if (*str == '\0') {
                        break;
                     }

                     if (*str == '\r' || *str == '\n') {
                        sTextPrintStruct.x = 4;
                        sTextPrintStruct.y += TEXTBOX_LINE_HEIGHT;
                        str++;
                     }
                     else {
                        u32 chr;

                        str = GetNextCharFromStr(str, &chr);
                        sTextPrintStruct.x += DrawCharOnWindow(sTextPrintStruct.x, sTextPrintStruct.y, chr, sTextPrintStruct.unk10, 0);
                        sTextPrintStruct.framesToWait = sFramesBetweenCharPrints;
                     }

                     if (TEXTBOX_OUT_OF_SPACE(sTextPrintStruct.y)) {
                        if (!(sStringFormatFlags & 0x10)) {
                            sTextPrintStruct.unk1C = 0;
                            sTextPrintStruct.waitButtonPress = TRUE;
                            sPrintStringState = STATE_WAIT_FOR_BUTTON_NEW_TEXTBOX;
                            sArrowFrames = 0;
                            sAutoPressFrames = sAutoPressNewTextboxFrames;
                            break;
                        }
                        else {
                            sTextPrintStruct.y = 4;
                        }
                     }
                     txtSpeed--;
                }
                sub_80073E0(0);
                sCurrStr = str;
                ResetTouchScreenMenuInput(&sDialogueMenuTouchScreenInput);
                if (*sCurrStr == '\0') {
                    if (sDialogueMenuItems != NULL) {
                        sPrintStringState = STATE_PRINT_FINISHED_MENU;
                    }
                    else {
                        sPrintStringState = STATE_PRINT_FINISHED;
                    }
                    keepLooping = FALSE;
                }
                else {
                    sTextPrintStruct.currFrames = 0;
                    if (sTextPrintStruct.waitButtonPress) {
                        if (sPrintStringState == STATE_PRINT_CHAR) {
                            sPrintStringState = 7;
                            sArrowFrames = 0;
                            sAutoPressFrames = sAutoPressNewTextboxFrames;
                        }
                        keepLooping = FALSE;
                    }
                    else {
                        sPrintStringState = STATE_PRINT_CHAR_SOUND_WAIT;
                    }
                }
            }
            break;
            case STATE_PRINT_CHAR_SOUND_WAIT: {
                if (sStringFormatFlags & STR_FORMAT_FLAG_DIALOGUE_SOUND) {
                    PlayDialogueTextSound();
                }
                if (!(sStringFormatFlags & 2)) {
                    if (sStringFormatFlags & STR_FORMAT_FLAG_INSTANT_TEXT_ON_AB_PRESS && gRealInputs.pressed & AB_BUTTONS) {
                        sInstantText = TRUE;
                        sTextPrintStruct.currFrames = 99999;
                    }
                }

                if (++sTextPrintStruct.currFrames > sTextPrintStruct.framesToWait) {
                    sPrintStringState = STATE_PRINT_CHAR;
                    sTextPrintStruct.waitFrames = FALSE;
                }
                else {
                    keepLooping = FALSE;
                }
            }
            break;
            case STATE_PRINT_FINISHED: {
                if (sStringFormatFlags & STR_FORMAT_FLAG_WAIT_FOR_BUTTON_PRESS) {
                    sPrintStringState = STATE_WAIT_FOR_BUTTON_PRESS_END_MSG;
                    sArrowFrames = 0;
                    if (sAutoPressFramesEndMsg > 0) {
                        sAutoPressFrames = sAutoPressFramesEndMsg - sDialoguePrintFrames;
                        if (sAutoPressFrames < 0) {
                            sPrintStringState = 11;
                            sAutoPressFrames = 0;
                        }
                    }
                    else {
                        sAutoPressFrames = sAutoPressNewTextboxFrames;
                    }
                }
                else {
                    sPrintStringState = 11;
                }
            }
            break;
            case STATE_WAIT_FOR_BUTTON_MID_TEXTBOX:
            case STATE_WAIT_FOR_BUTTON_NEW_TEXTBOX:
            case STATE_WAIT_FOR_BUTTON_PRESS_END_MSG: {
                bool8 buttonPress = FALSE;
                sTextPrintStruct.waitButtonPress = 0;
                GetTouchScreenMenuInput(&sDialogueMenuTouchScreenInput, 0);
                if (!(sStringFormatFlags & STR_FORMAT_FLAG_WAIT_FOR_BUTTON_PRESS_2)) {
                    buttonPress = TRUE;
                }
                else {
                    if (sStringFormatFlags & STR_FORMAT_FLAG_TIMED_AUTO_MSG_CLOSE) {
                        if (sAutoPressFrames > 0) {
                            sAutoPressFrames--;
                        }
                        else {
                            buttonPress = TRUE;
                        }
                    }
                    else if (gRealInputs.pressed & AB_BUTTONS || sDialogueMenuTouchScreenInput.a_button) {
                        buttonPress = TRUE;
                    }
                    else if ((gRealInputs.held & (DPAD_ANY | B_BUTTON)) == B_BUTTON) {
                        buttonPress = TRUE;
                    }
                    else if (sDialogueMenuTouchScreenInput.unk5) {
                        buttonPress = TRUE;
                    }
                }

                if (!buttonPress) {
                    sArrowFrames++;
                    if (!(sStringFormatFlags & STR_FORMAT_FLAG_TIMED_AUTO_MSG_CLOSE) && sArrowFrames & 8) {
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

                        if (sStringFormatFlags & 0x10) {
                            SpriteSetY(&sDialogueBoxArrowSprite, 120);
                            SpriteSetX(&sDialogueBoxArrowSprite, 112);
                        }
                        else {
                            SpriteSetY(&sDialogueBoxArrowSprite, sTextPrintStruct.unkA + 1);
                            SpriteSetX(&sDialogueBoxArrowSprite, sTextPrintStruct.unk8);
                        }

                        AddSprite(&sDialogueBoxArrowSprite, 256, NULL, NULL);
                    }
                }
                else {
                    if (*sCurrStr == '\0') {
                        sPrintStringState = 11;
                    }
                    else if (sPrintStringState == 9) {
                        sPrintStringState = 11;
                    }
                    else if (sPrintStringState == 8) {
                        sTextPrintStruct.x = 4;
                        if (TEXTBOX_OUT_OF_SPACE(sTextPrintStruct.y)) {
                            sTextPrintStruct.y = 4;
                            if (sStringFormatFlags & 0x10) {
                                CallPrepareTextbox_8008C54(0);
                                sPrintStringState = 1;
                            }
                            else if (sTextPrintStruct.unk1C != 0) {
                                CallPrepareTextbox_8008C54(0);
                                sPrintStringState = 1;
                            }
                            else {
                                sPrintStringState = 10;
                                sTextPrintStruct.unk28 = 0;
                            }
                        }
                        else {
                            sPrintStringState = 1;
                        }
                    }
                    else {
                        sPrintStringState = 1;
                    }

                    sTextPrintStruct.unk8 = 0x70;
                    sTextPrintStruct.unkA = (gWindows[0].y * 8) + TEXTBOX_HEIGHT;
                }
                keepLooping = FALSE;
            }
            break;
            case 10: {
                sTextPrintStruct.unk28++;
                gIwramTextFunc3(0);
                if (sTextPrintStruct.unk28 > 17) {
                    sPrintStringState = 1;
                }
                keepLooping = FALSE;
            }
            break;
            case 11: {
                if (sStringFormatFlags & 0x200) {
                    ResetUnusedInputStruct();
                    ShowWindows(NULL, TRUE, TRUE);
                    sPrintStringState = STATE_FINISHED;
                }
                else {
                    sPrintStringState = STATE_FINISHED;
                }
                keepLooping = FALSE;
            }
            break;
            case STATE_PRINT_FINISHED_MENU: {
                sub_8014A88();
                sPrintStringState = 4;
                keepLooping = FALSE;
            }
            break;
            case 4: {
                if (sub_8014B94()) {
                    sPrintStringState = 5;
                }
                keepLooping = FALSE;
            }
            break;
            case 5: {
                nullsub_35();
                sPrintStringState = 11;
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
        val = GetStringLineWidth(text);
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

// arm9.bin::0201C854
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
            if (flags & STR_FORMAT_FLAG_NEW_LINE_TERMINATES)
                break;
            r9 = TRUE;
        }
        else {
            if (r10) {
                r10 = FALSE;
                r9 = FALSE;
                if (flags & STR_FORMAT_FLAG_SPEAKER_NAME) {
                    AppendString(gSpeakerNameBuffer, &dst, dstMax, flags);
                    AppendString(": ", &dst, dstMax, flags);
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
                        Pokemon *monStruct = sub_808D3BC();
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
                        InlineStrcpy(sFormatBuffer_TeamName, "????");
                    }
                    txtPtr = sFormatBuffer_TeamName;
                    break;
                case 'h':
                    str++;
                    txtPtr = gFormatBuffer_FriendArea;
                    break;
                case 'd':
                    str++;
                    sprintfStatic(txtArray, "%d", gFormatArgs[*(str++) - '0']);
                    txtPtr = txtArray;
                    break;
                case 'v': {
                    s32 a;
                    u8 *unkTxtPtr;

                    str++;
                    a = gFormatArgs[*(str++) - '0'];
                    sprintfStatic(txtArray, "%*d", *(str++) - '0', a);
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
                    sprintfStatic(txtArray, "%0*d", *(str++) - '0', a);
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
                    txtPtr = "$";
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
        if (flags & STR_FORMAT_FLAG_NEW_LINE_TERMINATES && *str == '\r') {
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

// arm9.bin::0201C7AC
void PrintFormattedStringOnWindow(s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr)
{
    u8 formattedString[FORMAT_STR_MAX_LEN];

    FormatString(str, formattedString, formattedString + FORMAT_STR_MAX_LEN, 0);
    formattedString[FORMAT_STR_MAX_LEN - 1] = '\0';
    PrintStringOnWindow(x, y, formattedString, windowId, terminatingChr);
}

// arm9.bin::0201C750
void PrintFormattedStringOnWindow2(s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr, s32 lineSpacing)
{
    u8 formattedString[FORMAT_STR_MAX_LEN];

    FormatString(str, formattedString, formattedString + FORMAT_STR_MAX_LEN, 0);
    formattedString[FORMAT_STR_MAX_LEN - 1] = '\0';
    PrintStringOnWindow2(x, y, formattedString, windowId, terminatingChr, lineSpacing);
}
