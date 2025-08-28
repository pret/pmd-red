#include "global.h"
#include "globaldata.h"
#include "dungeon_message_log.h"
#include "dungeon_message.h"
#include "dungeon_info.h"
#include "text_1.h"
#include "text_2.h"
#include "text_3.h"
#include "input.h"
#include "menu_input.h"
#include "dungeon_vram.h"
#include "dungeon_music.h"
#include "sprite.h"
#include "dungeon_tilemap.h"
#include "run_dungeon.h"

#define MESSAGE_LOG_ROW_COUNT 8 // How many log messages are shown

extern void sub_805E804(void);
extern u32 GetTouchScreenArrowPress(s32 a0, const void *a1);


static void PutStringsOnMessageLog(void);
static bool8 TryScrollLogDown(s32 a0);
static bool8 TryScrollLogUp(s32 a0);
static void CreateMessageLogArrow(bool8 upArrow, s32 y);

static EWRAM_DATA s32 sMessageLogCursor = 0;
static EWRAM_DATA u8 sMessageLogFlags = 0;
static EWRAM_DATA SpriteOAM sMessageLogArrowSpriteOAM = {0};

void ResetMessageLog(void)
{
    s32 i;

    gDungeon->unk16 = 0;
    gDungeon->unkB = 1;
    for (i = 0; i < MESSAGE_LOG_STRINGS_COUNT; i++) {
        gDungeon->messageLogStrings[i].str[0] = '\0';
        gDungeon->messageLogStrings[i].unk0 = 0;
        gDungeon->messageLogStrings[i].unk1 = 0;
        gDungeon->messageLogStrings[i].unk2 = 0;
    }
}

// Unused in Red, used in Blue
UNUSED static void sub_8053200(void)
{
    gDungeon->unkB = 1;
}

void CopyStringToMessageLog(const u8 *src, u32 a1, u32 a2)
{
    u8 *dst = &gDungeon->messageLogStrings[gDungeon->unk16].str[0];
    u8 *maxDst = &gDungeon->messageLogStrings[gDungeon->unk16].str[MESSAGE_LOG_BUFFER_SIZE - 1];
    gDungeon->messageLogStrings[gDungeon->unk16].unk0 = 1;
    gDungeon->messageLogStrings[gDungeon->unk16].unk1 = a1;
    gDungeon->messageLogStrings[gDungeon->unk16].unk2 = a2;

    while (*src != '\0') {
        if (*src == '\r') break;
        if (dst < maxDst) {
            *(dst++) = *src;
        }
        src++;
    }

    *dst = '\0';
    if (++gDungeon->unk16 >= MESSAGE_LOG_STRINGS_COUNT) {
        gDungeon->unk16 = 0;
    }

    gDungeon->unkB = 1;
}

// Possibly something menu related?
// Unfortunately, this is passed to GetTouchScreenArrowPress which is a nullsub. It could be used for Blue and Nintendo DS' touch screen.
static const u8 sTouchScreenArrowPressData[] =
{
    0x01, 0x00, 0x54, 0x00, 0xf0, 0xff, 0x18, 0x00, 0x18, 0x00, 0x00, 0x00, 0x02, 0x00, 0x54, 0x00,
    0x6a, 0x00, 0x18, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

bool32 DisplayMessageLog(void)
{
    bool8 unkRet;
    TouchScreenMenuInput touchScreenInput;

    ResetTouchScreenMenuInput(&touchScreenInput);
    sub_803EAF0(9, NULL);
    do {
        DungeonRunFrameActions(13);
        unkRet = sub_8008D8C(0);
    } while (unkRet);

    sMessageLogCursor = 0;
    sMessageLogFlags = 0;
    PutStringsOnMessageLog();

    while (1) {
        s32 touchScreenArrow;
        bool32 scroll = FALSE;

        sMessageLogFlags = 0;
        GetTouchScreenMenuInput(&touchScreenInput, 0);
        touchScreenArrow = GetTouchScreenArrowPress(0, sTouchScreenArrowPressData);

        if (TryScrollLogUp(touchScreenArrow))
            scroll = TRUE;
        if (TryScrollLogDown(touchScreenArrow))
            scroll = TRUE;

        if (!scroll) {
            DungeonRunFrameActions(0xD);
        }

        if (sMessageLogFlags & FLAG_CAN_SCROLL_UP) {
            CreateMessageLogArrow(TRUE, -8);
        }
        if (sMessageLogFlags & FLAG_CAN_SCROLL_DOWN) {
            CreateMessageLogArrow(FALSE, 114);
        }

        if (!sub_80048C8()) {
            if (gRealInputs.pressed & B_BUTTON || touchScreenInput.b_button) {
                PlayDungeonCancelSE();
                break;
            }
            else if (gRealInputs.pressed & A_BUTTON) {
                PlayDungeonConfirmationSE();
                break;
            }
        }
    }

    sub_803EAF0(0, NULL);
    return TRUE;
}

static void PutStringsOnMessageLog(void)
{
    s32 i;
    s32 arrId = gDungeon->unk16;
    s32 y = 16;

    arrId -= 8;
    if (arrId < 0)
        arrId += MESSAGE_LOG_STRINGS_COUNT;

    sub_80073B8(0);
    for (i = 0; i < MESSAGE_LOG_ROW_COUNT; i++) {
        struct MessageLogString *msgLogString = &gDungeon->messageLogStrings[arrId];

        if (msgLogString->unk0) {
            if (msgLogString->unk1) {
                AddDoubleUnderScoreHighlight(0, 0, y, 0xE0, 7);
            }
            PrintStringOnWindow(8, y + 3, msgLogString->str, 0, 0xD);
            y += 14;
        }
        if (++arrId >= MESSAGE_LOG_STRINGS_COUNT)
            arrId = 0;
    }

    sub_80073E0(0);
    sub_8007334(0);
}

static bool8 TryScrollLogUp(s32 touchScreenArrow)
{
    s32 i;
    struct MessageLogString *msgLogString;
    s32 y;
    s32 arrId;

    while (1)
    {
        arrId = gDungeon->unk16 + sMessageLogCursor;
        y = 2;
        arrId -= 9;
        while (arrId < 0) {
            arrId += MESSAGE_LOG_STRINGS_COUNT;
        }
        while (arrId >= MESSAGE_LOG_STRINGS_COUNT) {
            arrId -= MESSAGE_LOG_STRINGS_COUNT;
        }

        if (gDungeon->messageLogStrings[arrId].unk0 && sMessageLogCursor > -12) {
            sMessageLogFlags |= FLAG_CAN_SCROLL_UP;
            if (gRealInputs.repeated & DPAD_UP)
                break;
            if (touchScreenArrow == TOUCH_SCREEN_ARROW_UP_PRESS)
                break;
        }

        return FALSE;
    }
    PlayDungeonCursorSE(0);
    sub_80073B8(0);
    msgLogString = &gDungeon->messageLogStrings[arrId];
    if (msgLogString->unk0) {
        sub_80087EC(0, 0, 0, 0xD0, 0x10);
        if (msgLogString->unk1) {
            AddDoubleUnderScoreHighlight(0, 0, y, 0xE0, 7);
        }
        PrintStringOnWindow(8, y + 3, msgLogString->str, 0, 0xD);
    }
    sub_80073E0(0);
    DungeonRunFrameActions(0xD);

    for (i = 0; i < 7; i++) {
        ScrollUpWindowFunc(0);
        DungeonRunFrameActions(0xD);
    }

    sMessageLogCursor--;
    return TRUE;
}

static bool8 TryScrollLogDown(s32 touchScreenArrow)
{
    s32 i;
    struct MessageLogString *msgLogString;
    s32 y;
    s32 arrId;

    while (1)
    {
        arrId = gDungeon->unk16 + sMessageLogCursor;
        y = 128;
        while (arrId < 0) {
            arrId += MESSAGE_LOG_STRINGS_COUNT;
        }
        while (arrId >= MESSAGE_LOG_STRINGS_COUNT) {
            arrId -= MESSAGE_LOG_STRINGS_COUNT;
        }

        if (sMessageLogCursor < 0) {
            sMessageLogFlags |= FLAG_CAN_SCROLL_DOWN;
            if (gRealInputs.repeated & DPAD_DOWN)
                break;
            if (touchScreenArrow == TOUCH_SCREEN_ARROW_DOWN_PRESS)
                break;
        }

        return FALSE;
    }
    PlayDungeonCursorSE(0);
    sub_80073B8(0);
    msgLogString = &gDungeon->messageLogStrings[arrId];
    if (msgLogString->unk0) {
        sub_80087EC(0, 0, y, 0x68, 0x10);
        if (msgLogString->unk1) {
            AddDoubleUnderScoreHighlight(0, 0, y, 0xE0, 7);
        }
        PrintStringOnWindow(8, y + 3, msgLogString->str, 0, 0xD);
    }
    sub_80073E0(0);
    DungeonRunFrameActions(0xD);

    for (i = 0; i < 7; i++) {
        ScrollDownWindowFunc(0);
        DungeonRunFrameActions(0xD);
    }

    sMessageLogCursor++;
    return TRUE;
}

static void CreateMessageLogArrow(bool8 upArrow, s32 y)
{
    Window *window = &gWindows[0];
    if (!(gDungeonFramesCounter & 8)) {
        SpriteSetAffine1(&sMessageLogArrowSpriteOAM, 0);
        SpriteSetAffine2(&sMessageLogArrowSpriteOAM, 0);
        SpriteSetObjMode(&sMessageLogArrowSpriteOAM, 0);
        SpriteSetMosaic(&sMessageLogArrowSpriteOAM, 0);
        SpriteSetBpp(&sMessageLogArrowSpriteOAM, 0);
        SpriteSetMatrixNum(&sMessageLogArrowSpriteOAM, (upArrow != FALSE) ? (16) : 0);
        SpriteSetPalNum(&sMessageLogArrowSpriteOAM, 15);
        SpriteSetY(&sMessageLogArrowSpriteOAM, (window->y * 8) + y);
        SpriteSetX(&sMessageLogArrowSpriteOAM, (window->x * 8) + 92);
        SpriteSetShape(&sMessageLogArrowSpriteOAM, 1);
        SpriteSetSize(&sMessageLogArrowSpriteOAM, 0);
        SpriteSetPriority(&sMessageLogArrowSpriteOAM, 0);
        SpriteSetPalNum(&sMessageLogArrowSpriteOAM, 15);
        SpriteSetTileNum(&sMessageLogArrowSpriteOAM, 0x3f0);

        AddSprite(&sMessageLogArrowSpriteOAM, 127, NULL, NULL);
    }
}

