#include "global.h"
#include "globaldata.h"
#include "naming_screen.h"
#include "code_800D090.h"
#include "music_util.h"
#include "code_803D0D8.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "sprite.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"
#include "text_3.h"
#include "text_util.h"
#include "constants/input.h"
#include "constants/colors.h"

#define MAX_TEXT_SIZE 54

enum
{
    MODE_OVR,
    MODE_INS,
};

struct NamingScreen
{
    // size: 0x198
    u32 type;
    bool8 isPassword;
    // Note: These had to be declared like these, because SpriteOAM is aligned by 4 and these aren't. Makes you think if SpriteOAM is actually a struct, and not just an array of 4 u16s.
    u16 spriteLetterCursor[4];
    u16 spriteInputCursor[4];
    u8 letterCursorFrames;
    u8 inputCursorFrames;
    u8 insOvr;
    u8 inputCursorArrId; // Always 0
    u8 inputCursorPosition;
    u8 maxLetters;
    u8 letterCursorPos;
    u16 letterTotalWidths[MAX_TEXT_SIZE];
    s16 letterWidths[MAX_TEXT_SIZE];
    u8 *textPtr; // Points to the field below. A bit over complicated in my opinion...
    u8 text[MAX_TEXT_SIZE];
    u8 *defaultText;
    WindowTemplates windows;
};

static EWRAM_INIT struct NamingScreen *sNamingScreen = NULL;

static s32 GetEnteredNameLength(void);
static void UpdateInputWindow(bool8);
static void UpdateNameWindow(void);
static void UpdateLetterWidths(void);
static void SetLetterCursorSpritePosition(void);
static void HandleInputCursor(void);
static void UpdatePassword1Window(u8 *text, s32 windowId, s32 _yAdd);
static void UpdatePassword2Window(u8 *text, s32 windowId, s32 _yAdd);
static u32 HandleAPress(void);
static bool8 HandleBPress(void);

enum
{
    NAMING_SELF,
    NAMING_TEAM,
    NAMING_POKEMON,
    NAMING_PARTNER,
    NAMING_PASSWORD1,
    NAMING_PASSWORD2,
};

#define NAMING_WINDOW_INPUT 0
#define NAMING_WINDOW_NAME 1

struct LayoutInfo
{
    u8 upPos;
    u8 downPos;
    u8 leftPos;
    u8 rightPos;
    u8 x;
    u8 y;
    u8 colorType;
    s32 letter;
};

static const DungeonPos sPassword1CursorPositions[] =
{
    {3, 0xD},
    {0xF, 0xD},
    {0x1B, 0xD},
    {0x27, 0xD},
    {0x33, 0xD},
    {0x40, 0xF},
    {0x4C, 0xF},
    {0x58, 0xF},
    {0x64, 0xF},
    {0x70, 0xF},
    {0x7C, 0xF},
    {0x88, 0xF},
    {0x94, 0xF},
    {0xA1, 0xD},
    {0xAD, 0xD},
    {0xB9, 0xD},
    {0xC5, 0xD},
    {0xD1, 0xD},
    {3, 0x1A},
    {0xF, 0x1A},
    {0x1B, 0x1A},
    {0x27, 0x1A},
    {0x33, 0x1A},
    {0x40, 0x1C},
    {0x4C, 0x1C},
    {0x58, 0x1C},
    {0x64, 0x1C},
    {0x70, 0x1C},
    {0x7C, 0x1C},
    {0x88, 0x1C},
    {0x94, 0x1C},
    {0xA1, 0x1A},
    {0xAD, 0x1A},
    {0xB9, 0x1A},
    {0xC5, 0x1A},
    {0xD1, 0x1A},
    {3, 0x28},
    {0xF, 0x28},
    {0x1B, 0x28},
    {0x27, 0x28},
    {0x33, 0x28},
    {0x40, 0x2A},
    {0x4C, 0x2A},
    {0x58, 0x2A},
    {0x64, 0x2A},
    {0x70, 0x2A},
    {0x7C, 0x2A},
    {0x88, 0x2A},
    {0x94, 0x2A},
    {0xA1, 0x28},
    {0xAD, 0x28},
    {0xB9, 0x28},
    {0xC5, 0x28},
    {0xD1, 0x28},
};

static const DungeonPos sPassword2CursorPositions[] =
{
    {0x20, 0x12},
    {0x2E, 0x12},
    {0x3C, 0x12},
    {0x4A, 0x12},
    {0x58, 0x14},
    {0x66, 0x14},
    {0x74, 0x14},
    {0x82, 0x14},
    {0x90, 0x12},
    {0x9E, 0x12},
    {0xAC, 0x12},
    {0xBA, 0x12},
    {0x20, 0x24},
    {0x2E, 0x24},
    {0x3C, 0x24},
    {0x4A, 0x24},
    {0x58, 0x26},
    {0x66, 0x26},
    {0x74, 0x26},
    {0x82, 0x26},
    {0x90, 0x24},
    {0x9E, 0x24},
    {0xAC, 0x24},
    {0xBA, 0x24},
};

#define NAMING_LETTER_DEL 0x105
#define NAMING_LETTER_END 0x106
#define NAMING_LETTER_INS_OVR 0x107
#define NAMING_LETTER_BLANK 0x108
#define NAMING_LETTER_TERMINATOR 0x109

// It was programmed as a 2d array, however it's effectively a 1d array(since there's only one entry for [0][x]). Could be different in Blue?
static const struct LayoutInfo sLayoutInfo[][85] =
{
    [0] = {
        {0, 0, 0, 0, 8, 3, 0, NAMING_LETTER_BLANK},
        {0, 0, 0, 0, 8, 14, 0, NAMING_LETTER_BLANK},
        {0, 0, 0, 0, 8, 25, 0, NAMING_LETTER_BLANK},
        {5, 4, 81, 9, 8, 36, 3, NAMING_LETTER_INS_OVR},
        {3, 5, 82, 10, 8, 47, 3, NAMING_LETTER_DEL},
        {4, 3, 83, 11, 8, 58, 3, NAMING_LETTER_END},
        {11, 7, 78, 12, 36, 3, 0, 'a'},
        {6, 8, 79, 13, 36, 14, 0, 'n'},
        {7, 9, 80, 14, 36, 25, 0, 'A'},
        {8, 10, 3, 15, 36, 36, 0, 'N'},
        {9, 11, 4, 16, 36, 47, 0, 233},
        {10, 6, 5, 17, 36, 58, 0, '+'},
        {17, 13, 6, 18, 50, 3, 0, 'b'},
        {12, 14, 7, 19, 50, 14, 0, 'o'},
        {13, 15, 8, 20, 50, 25, 0, 'B'},
        {14, 16, 9, 21, 50, 36, 0, 'O'},
        {15, 17, 10, 22, 50, 47, 0, '1'},
        {16, 12, 11, 23, 50, 58, 0, '-'},
        {23, 19, 12, 24, 64, 3, 0, 'c'},
        {18, 20, 13, 25, 64, 14, 0, 'p'},
        {19, 21, 14, 26, 64, 25, 0, 'C'},
        {20, 22, 15, 27, 64, 36, 0, 'P'},
        {21, 23, 16, 28, 64, 47, 0, '2'},
        {22, 18, 17, 29, 64, 58, 0, ','},
        {29, 25, 18, 30, 78, 3, 0, 'd'},
        {24, 26, 19, 31, 78, 14, 0, 'q'},
        {25, 27, 20, 32, 78, 25, 0, 'D'},
        {26, 28, 21, 33, 78, 36, 0, 'Q'},
        {27, 29, 22, 34, 78, 47, 0, '3'},
        {28, 24, 23, 35, 78, 58, 0, '.'},
        {35, 31, 24, 36, 92, 3, 0, 'e'},
        {30, 32, 25, 37, 92, 14, 0, 'r'},
        {31, 33, 26, 38, 92, 25, 0, 'E'},
        {32, 34, 27, 39, 92, 36, 0, 'R'},
        {33, 35, 28, 40, 92, 47, 0, '4'},
        {34, 30, 29, 41, 92, 58, 0, '!'},
        {41, 37, 30, 42, 106, 3, 0, 'f'},
        {36, 38, 31, 43, 106, 14, 0, 's'},
        {37, 39, 32, 44, 106, 25, 0, 'F'},
        {38, 40, 33, 45, 106, 36, 0, 'S'},
        {39, 41, 34, 46, 106, 47, 0, '5'},
        {40, 36, 35, 47, 106, 58, 0, '?'},
        {47, 43, 36, 48, 120, 3, 0, 'g'},
        {42, 44, 37, 49, 120, 14, 0, 't'},
        {43, 45, 38, 50, 120, 25, 0, 'G'},
        {44, 46, 39, 51, 120, 36, 0, 'T'},
        {45, 47, 40, 52, 120, 47, 0, '6'},
        {46, 42, 41, 53, 120, 58, 0, 145},
        {53, 49, 42, 54, 134, 3, 0, 'h'},
        {48, 50, 43, 55, 134, 14, 0, 'u'},
        {49, 51, 44, 56, 134, 25, 0, 'H'},
        {50, 52, 45, 57, 134, 36, 0, 'U'},
        {51, 53, 46, 58, 134, 47, 0, '7'},
        {52, 48, 47, 59, 134, 58, 0, 146},
        {59, 55, 48, 60, 148, 3, 0, 'i'},
        {54, 56, 49, 61, 148, 14, 0, 'v'},
        {55, 57, 50, 62, 148, 25, 0, 'I'},
        {56, 58, 51, 63, 148, 36, 0, 'V'},
        {57, 59, 52, 64, 148, 47, 0, '8'},
        {58, 54, 53, 65, 148, 58, 0, 147},
        {65, 61, 54, 66, 162, 3, 0, 'j'},
        {60, 62, 55, 67, 162, 14, 0, 'w'},
        {61, 63, 56, 68, 162, 25, 0, 'J'},
        {62, 64, 57, 69, 162, 36, 0, 'W'},
        {63, 65, 58, 70, 162, 47, 0, '9'},
        {64, 60, 59, 71, 162, 58, 0, 148},
        {71, 67, 60, 72, 176, 3, 0, 'k'},
        {66, 68, 61, 73, 176, 14, 0, 'x'},
        {67, 69, 62, 74, 176, 25, 0, 'K'},
        {68, 70, 63, 75, 176, 36, 0, 'X'},
        {69, 71, 64, 76, 176, 47, 0, '0'},
        {70, 66, 65, 77, 176, 58, 0, 189},
        {77, 73, 66, 78, 190, 3, 0, 'l'},
        {72, 74, 67, 79, 190, 14, 0, 'y'},
        {73, 75, 68, 80, 190, 25, 0, 'L'},
        {74, 76, 69, 81, 190, 36, 0, 'Y'},
        {75, 77, 70, 82, 190, 47, 0, ':'},
        {76, 72, 71, 83, 190, 58, 0, 190},
        {83, 79, 72, 6, 204, 3, 0, 'm'},
        {78, 80, 73, 7, 204, 14, 0, 'z'},
        {79, 81, 74, 8, 204, 25, 0, 'M'},
        {80, 82, 75, 3, 204, 36, 0, 'Z'},
        {81, 83, 76, 4, 204, 47, 0, 133},
        {82, 78, 77, 5, 204, 58, 0, ' '},
        {0, 0, 0, 0, 8, 3, 2, NAMING_LETTER_TERMINATOR},
    }
};

static const u8 *const sSpecialLetters[] =
{
    _("゛"),
    _("゜"),
    _("かな"),
    _("カナ"),
    _("ＡＢＣ"),
    _("DEL"),
    _("END"),
};

static const WindowTemplate sWindowTemplateDummy = WIN_TEMPLATE_DUMMY;

static const WindowTemplate sInputWindowTemplate = {
    .flags = WINTEMPLATE_FLAG_NONE,
    .type = WINDOW_TYPE_WITHOUT_BORDER,
    .pos = { 1, 10 },
    .width = 28,
    .height = 9,
    .totalHeight = 9,
    .unk12 = 0,
    .header = NULL,
};

static const WindowTemplate sNameWindowTemplate = {
    .flags = WINTEMPLATE_FLAG_NONE,
    .type = WINDOW_TYPE_WITHOUT_BORDER,
    .pos = { 4, 3 },
    .width = 22,
    .height = 5,
    .totalHeight = 5,
    .unk12 = 0,
    .header = NULL,
};

static const WindowTemplate sPasswordNameWindowTemplate = {
    .flags = WINTEMPLATE_FLAG_NONE,
    .type = WINDOW_TYPE_WITHOUT_BORDER,
    .pos = { 1, 2 },
    .width = 28,
    .height = 7,
    .totalHeight = 7,
    .unk12 = 0,
    .header = NULL,
};

u32 NamingScreen_Init(u32 type, u8 *defaultText)
{
    SpriteOAM *sprite;
    s32 index;
    s32 i;

    sNamingScreen = MemoryAlloc(sizeof(*sNamingScreen), 8);
    sNamingScreen->type = type;
    sNamingScreen->inputCursorArrId = 0;
    sNamingScreen->insOvr = MODE_OVR;
    sNamingScreen->isPassword = 0;

    switch (sNamingScreen->type) {
        case NAMING_PASSWORD1:
            sNamingScreen->inputCursorPosition = 9;
            sNamingScreen->isPassword = TRUE;
            sNamingScreen->maxLetters = 0x36;
            break;
        case NAMING_PASSWORD2:
            sNamingScreen->inputCursorPosition = 9;
            sNamingScreen->isPassword = TRUE;
            sNamingScreen->maxLetters = 0x18;
            break;
        case NAMING_TEAM:
            sNamingScreen->inputCursorPosition = 6;
            sNamingScreen->maxLetters = TEAM_NAME_LENGTH;
            break;
        case NAMING_SELF:
        case NAMING_PARTNER:
        case NAMING_POKEMON:
        default:
            sNamingScreen->inputCursorPosition = 6;
            sNamingScreen->maxLetters = POKEMON_NAME_LENGTH;
            break;
    }

    sNamingScreen->defaultText = defaultText;
    sNamingScreen->textPtr = sNamingScreen->text;

    for (i = 0; i < MAX_TEXT_SIZE; i++) {
        sNamingScreen->textPtr[i] = '\0';
    }
    MemoryCopy8(sNamingScreen->textPtr, sNamingScreen->defaultText, sNamingScreen->maxLetters);

    for (i = 0; i < sNamingScreen->maxLetters; i++) {
        if (sNamingScreen->textPtr[i] == '\0') {
            break;
        }
    }
    for (; i < sNamingScreen->maxLetters; i++) {
        sNamingScreen->textPtr[i] = '\0';
    }

    sNamingScreen->letterCursorPos = GetEnteredNameLength();
    if (sNamingScreen->letterCursorPos == sNamingScreen->maxLetters) {
        sNamingScreen->letterCursorPos--;
    }

    SpriteSetAffine1((SpriteOAM *) &sNamingScreen->spriteLetterCursor, 0);
    SpriteSetAffine2((SpriteOAM *) &sNamingScreen->spriteLetterCursor, 0);
    SpriteSetObjMode((SpriteOAM *) &sNamingScreen->spriteLetterCursor, 0);
    SpriteSetMosaic((SpriteOAM *) &sNamingScreen->spriteLetterCursor, 0);
    SpriteSetBpp((SpriteOAM *) &sNamingScreen->spriteLetterCursor, 0);
    SpriteSetPriority((SpriteOAM *) &sNamingScreen->spriteLetterCursor, 0);
    SpriteSetPalNum((SpriteOAM *) &sNamingScreen->spriteLetterCursor, 15);
    SpriteSetX((SpriteOAM *) &sNamingScreen->spriteLetterCursor, DISPLAY_WIDTH);
    SpriteSetY((SpriteOAM *) &sNamingScreen->spriteLetterCursor, DISPLAY_WIDTH);

    if (sNamingScreen->isPassword) {
        SpriteSetVFlip((SpriteOAM *) &sNamingScreen->spriteLetterCursor, 0);
        SpriteSetTileNum((SpriteOAM *) &sNamingScreen->spriteLetterCursor, 0x3F6);
        SpriteSetSize((SpriteOAM *) &sNamingScreen->spriteLetterCursor, 0);
        SpriteSetShape((SpriteOAM *) &sNamingScreen->spriteLetterCursor, 1);
    }
    else {
        SpriteSetVFlip((SpriteOAM *) &sNamingScreen->spriteLetterCursor, 1);
        SpriteSetTileNum((SpriteOAM *) &sNamingScreen->spriteLetterCursor, 0x3F0);
        SpriteSetSize((SpriteOAM *) &sNamingScreen->spriteLetterCursor, 0);
        SpriteSetShape((SpriteOAM *) &sNamingScreen->spriteLetterCursor, 1);
    }

    sNamingScreen->letterCursorFrames = 4;

    sprite = (SpriteOAM *) &sNamingScreen->spriteInputCursor;

    SpriteSetAffine1(sprite, 0);
    SpriteSetAffine2(sprite, 0);
    SpriteSetObjMode(sprite, 0);
    SpriteSetMosaic(sprite, 0);
    SpriteSetBpp(sprite, 0);
    SpriteSetShape(sprite, 0);
    SpriteSetTileNum(sprite, 0x3F4);
    SpriteSetPriority(sprite, 0);
    SpriteSetPalNum(sprite, 15);
    SpriteSetMatrixNum(sprite, 0);
    SpriteSetSize(sprite, 0);
    SpriteSetX(sprite, DISPLAY_WIDTH);
    SpriteSetY(sprite, DISPLAY_WIDTH);

    sNamingScreen->inputCursorFrames = 0;

    for (index = 0; index < MAX_WINDOWS; index++) {
        sNamingScreen->windows.id[index] = sWindowTemplateDummy;
    }

    if (sNamingScreen->isPassword) {
        sNamingScreen->windows.id[NAMING_WINDOW_NAME] = sPasswordNameWindowTemplate;
    }
    else {
        sNamingScreen->windows.id[NAMING_WINDOW_NAME] = sNameWindowTemplate;
    }
    sNamingScreen->windows.id[NAMING_WINDOW_INPUT] = sInputWindowTemplate;

    ResetUnusedInputStruct();
    ShowWindows(&sNamingScreen->windows, 1, 1);

    UpdateInputWindow(TRUE);
    UpdateNameWindow();
    UpdateLetterWidths();
    return 1;
}

u32 NamingScreen_HandleInput(void)
{
    sNamingScreen->letterCursorFrames++;
    SetLetterCursorSpritePosition();
    if (sNamingScreen->letterCursorFrames & 8) {
        AddSprite((SpriteOAM *) &sNamingScreen->spriteLetterCursor, 0x100, NULL, NULL);
    }

    sNamingScreen->inputCursorFrames++;
    HandleInputCursor();
    if (sNamingScreen->inputCursorFrames & 8) {
        AddSprite((SpriteOAM *) &sNamingScreen->spriteInputCursor, 0x100, NULL, NULL);
    }

    switch (GetMenuInput()) {
        case INPUT_L_BUTTON:
            if (sNamingScreen->letterCursorPos == 0) {
                PlayMenuSoundEffect(2);
            }
            else {
                sNamingScreen->letterCursorPos--;
                PlayMenuSoundEffect(3);
            }
            break;
        case INPUT_R_BUTTON:
            if (sNamingScreen->letterCursorPos != sNamingScreen->maxLetters - 1 && sNamingScreen->letterCursorPos < GetEnteredNameLength()) {
                sNamingScreen->letterCursorPos++;
                PlayMenuSoundEffect(3);
            }
            else {
                PlayMenuSoundEffect(2);
            }
            break;
        case INPUT_A_BUTTON:
            return HandleAPress();
        case INPUT_B_BUTTON:
            if (HandleBPress()) {
                return 2;
            }
            break;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(3);
            sNamingScreen->inputCursorPosition = 5;
            break;
    }

    return 0;
}

void NamingScreen_Free(void)
{
    if (sNamingScreen != NULL) {
        MemoryFree(sNamingScreen);
        sNamingScreen = NULL;
    }
}

static u32 HandleAPress(void)
{
    s32 letter = sLayoutInfo[sNamingScreen->inputCursorArrId][sNamingScreen->inputCursorPosition].letter;

    switch (letter) {
        case NAMING_LETTER_INS_OVR:
            sNamingScreen->insOvr = (sNamingScreen->insOvr == 0); // Flip
            PlayMenuSoundEffect(4);
            UpdateInputWindow(FALSE);
            break;
        case NAMING_LETTER_DEL:
            if (HandleBPress()) {
                return 2;
            }
            break;
        case NAMING_LETTER_END:
            if (GetEnteredNameLength() == 0 || (sNamingScreen->isPassword && GetEnteredNameLength() != sNamingScreen->maxLetters)) {
                PlayMenuSoundEffect(2);
            }
            else {
                PlayMenuSoundEffect(0);
                MemoryCopy8(sNamingScreen->defaultText, sNamingScreen->textPtr, sNamingScreen->maxLetters);
                return 3;
            }
            break;
        default:
            if (sNamingScreen->isPassword && sub_803D0F0(letter) == 0xFF) {
                PlayMenuSoundEffect(2);
            }
            else {
                if (sNamingScreen->insOvr == MODE_INS) {
                    s32 i;
                    for (i = sNamingScreen->maxLetters - 2; i >= sNamingScreen->letterCursorPos; i--) {
                        u8 *ptr = &sNamingScreen->textPtr[i];
                        ptr[1] = ptr[0];
                    }
                }

                sNamingScreen->textPtr[sNamingScreen->letterCursorPos] = letter;
                if (sNamingScreen->letterCursorPos < sNamingScreen->maxLetters - 1) {
                    sNamingScreen->letterCursorPos++;
                }
                else {
                    sNamingScreen->inputCursorPosition = 5;
                }

                PlayMenuSoundEffect(0);
                UpdateNameWindow();
                UpdateLetterWidths();
            }
            break;
    }

    return 0;
}

static bool8 HandleBPress(void)
{
    if (sNamingScreen->textPtr[sNamingScreen->letterCursorPos] == '\0') {
        if (sNamingScreen->letterCursorPos == 0) {
            PlayMenuSoundEffect(2);
            return TRUE;
        }
        else {
            sNamingScreen->letterCursorPos--;
            sNamingScreen->textPtr[sNamingScreen->letterCursorPos] = '\0';
            PlayMenuSoundEffect(1);
            UpdateNameWindow();
            UpdateLetterWidths();
        }
    }
    else {
        s32 i, n;

        n = GetEnteredNameLength() - 1;
        for (i = sNamingScreen->letterCursorPos; i < n; i++) {
            u8 *ptr = &sNamingScreen->textPtr[i];
            ptr[0] = ptr[1];
        }
        sNamingScreen->textPtr[n] = 0;
        PlayMenuSoundEffect(1);
        UpdateNameWindow();
        UpdateLetterWidths();
    }

    return FALSE;
}

static void SetLetterCursorSpritePosition(void)
{
    Window *window = &gWindows[1];

    // Note: for cases NAMING_PASSWORD1 and NAMING_PASSWORD2, the code is identical except for different position structs.
    if (sNamingScreen->type == NAMING_PASSWORD1) {
        s32 x, y;

        x = sPassword1CursorPositions[sNamingScreen->letterCursorPos].x + (window->x * 8);
        SpriteSetX((SpriteOAM *) &sNamingScreen->spriteLetterCursor, x);

        y = sPassword1CursorPositions[sNamingScreen->letterCursorPos].y + (window->y * 8) + 5;
        SpriteSetY((SpriteOAM *) &sNamingScreen->spriteLetterCursor, y);
    }
    else if (sNamingScreen->type == NAMING_PASSWORD2) {
        s32 x, y;

        x = sPassword2CursorPositions[sNamingScreen->letterCursorPos].x + (window->x * 8);
        SpriteSetX((SpriteOAM *) &sNamingScreen->spriteLetterCursor, x);

        y = sPassword2CursorPositions[sNamingScreen->letterCursorPos].y + (window->y * 8) + 5;
        SpriteSetY((SpriteOAM *) &sNamingScreen->spriteLetterCursor, y);
    }
    else {
        s32 x, y;

        x = sNamingScreen->letterTotalWidths[sNamingScreen->letterCursorPos] + (sNamingScreen->letterWidths[sNamingScreen->letterCursorPos] / 2) + 30 + (window->x * 8);
        SpriteSetX((SpriteOAM *) &sNamingScreen->spriteLetterCursor, (u16) x);

        y = (window->y * 8) + 34;
        SpriteSetY((SpriteOAM *) &sNamingScreen->spriteLetterCursor, y);
    }
}

static void HandleInputCursor(void)
{
    s32 x, y;
    Window *window = &gWindows[0];
    u32 newPosition;

    switch (GetMenuInput()) {
        case INPUT_DPAD_UP:
            newPosition = sLayoutInfo[sNamingScreen->inputCursorArrId][sNamingScreen->inputCursorPosition].upPos;
            break;
        case INPUT_DPAD_DOWN:
            newPosition = sLayoutInfo[sNamingScreen->inputCursorArrId][sNamingScreen->inputCursorPosition].downPos;
            break;
        case INPUT_DPAD_LEFT:
            newPosition = sLayoutInfo[sNamingScreen->inputCursorArrId][sNamingScreen->inputCursorPosition].leftPos;
            break;
        case INPUT_DPAD_RIGHT:
            newPosition = sLayoutInfo[sNamingScreen->inputCursorArrId][sNamingScreen->inputCursorPosition].rightPos;
            break;
        default:
            newPosition = sNamingScreen->inputCursorPosition;
            break;
    }

    if (newPosition != sNamingScreen->inputCursorPosition) {
        sNamingScreen->inputCursorPosition = newPosition;
        PlayMenuSoundEffect(3);
        sNamingScreen->inputCursorFrames = 8;
    }

    x =  sLayoutInfo[sNamingScreen->inputCursorArrId][sNamingScreen->inputCursorPosition].x + (window->x * 8) - 5;
    y =  sLayoutInfo[sNamingScreen->inputCursorArrId][sNamingScreen->inputCursorPosition].y + (window->y * 8) + 1;
    SpriteSetX((SpriteOAM *) &sNamingScreen->spriteInputCursor, x);
    SpriteSetY((SpriteOAM *) &sNamingScreen->spriteInputCursor, y);
}

static void UpdateInputWindow(bool8 unused)
{
    s32 letter;
    s32 i;
    u8 text1[16];
    u8 text2[16];

    CallPrepareTextbox_8008C54(0);
    sub_80073B8(0);

    for (i = 0; (letter = sLayoutInfo[sNamingScreen->inputCursorArrId][i].letter) != NAMING_LETTER_TERMINATOR; i++) {
        s32 color;

        switch (sLayoutInfo[sNamingScreen->inputCursorArrId][i].colorType) {
            case 1:
                color = COLOR_CYAN;
                break;
            case 2:
                color = COLOR_RED;
                break;
            case 3:
                color = COLOR_WHITE_2;
                break;
            default:
                color = COLOR_WHITE_2;
                if (sNamingScreen->isPassword) {
                    if (letter <= 0xFF) {
                        if (sub_803D0F0(letter) == 0xFF) {
                            color = COLOR_RED;
                        }
                    }
                    else if (letter < 0x102) {
                        color = COLOR_RED;
                    }
                }
                break;
        }

        if (letter != NAMING_LETTER_BLANK) {
            if (letter == NAMING_LETTER_INS_OVR) {
                if (sNamingScreen->insOvr == MODE_OVR) {
                    PrintStringOnWindow(sLayoutInfo[sNamingScreen->inputCursorArrId][i].x + 3, sLayoutInfo[sNamingScreen->inputCursorArrId][i].y, _("{COLOR GREEN}OVR{RESET}"), NAMING_WINDOW_INPUT, '\0');
                }
                else {
                    PrintStringOnWindow(sLayoutInfo[sNamingScreen->inputCursorArrId][i].x + 3, sLayoutInfo[sNamingScreen->inputCursorArrId][i].y, _("{COLOR YELLOW}INS{RESET}"), NAMING_WINDOW_INPUT, '\0');
                }
            }
            else if (letter == ' ') {
                sprintfStatic(text1, _("{COLOR}%c{0x81}{0x59}"), color);
                PrintStringOnWindow(sLayoutInfo[sNamingScreen->inputCursorArrId][i].x + 1, sLayoutInfo[sNamingScreen->inputCursorArrId][i].y, text1, NAMING_WINDOW_INPUT, '\0');
            }
            else if (letter > 0xFF) {
                sprintfStatic(text2, _("{COLOR}%c%s"), color, sSpecialLetters[letter & 0xFF]);
                PrintStringOnWindow(sLayoutInfo[sNamingScreen->inputCursorArrId][i].x + 3, sLayoutInfo[sNamingScreen->inputCursorArrId][i].y, text2, NAMING_WINDOW_INPUT, '\0');
            }
            else {
                DrawCharOnWindowWidth12(sLayoutInfo[sNamingScreen->inputCursorArrId][i].x, sLayoutInfo[sNamingScreen->inputCursorArrId][i].y, (u8) letter, color, 0);
            }
        }
    }

    AddUnderScoreHighlight(NAMING_WINDOW_INPUT, 0, 0, 0xE0, 0xE);
    AddUnderScoreHighlight(NAMING_WINDOW_INPUT, 0, 0x47, 0xE0, 0xE);
    sub_8007A78(NAMING_WINDOW_INPUT, 0, 0, 0x48, 0xE);
    sub_8007A78(NAMING_WINDOW_INPUT, 0xDF, 0, 0x48, 0xE);
    sub_80073E0(NAMING_WINDOW_INPUT);
}

static void UpdateNameWindow(void)
{
    u8 text[80];

    CallPrepareTextbox_8008C54(1);
    sub_80073B8(1);
    if (sNamingScreen->isPassword) {
        AddUnderScoreHighlight(NAMING_WINDOW_NAME, 0, 0, 0xE0, 0xE);
        AddUnderScoreHighlight(NAMING_WINDOW_NAME, 0, 0x37, 0xE0, 0xE);
        sub_8007A78(NAMING_WINDOW_NAME, 0, 0, 0x38, 0xE);
        sub_8007A78(NAMING_WINDOW_NAME, 0xDF, 0, 0x38, 0xE);
    }
    else {
        AddUnderScoreHighlight(NAMING_WINDOW_NAME, 0, 0, 0xB0, 0xE);
        AddUnderScoreHighlight(NAMING_WINDOW_NAME, 0, 0x27, 0xB0, 0xE);
        sub_8007A78(NAMING_WINDOW_NAME, 0, 0, 0x28, 0xE);
        sub_8007A78(NAMING_WINDOW_NAME, 0xAF, 0, 0x28, 0xE);
    }

    switch (sNamingScreen->type) {
        case NAMING_SELF:
            PrintStringOnWindow(8, 5, _("What is your name?"), NAMING_WINDOW_NAME, '\0');
            break;
        case NAMING_POKEMON:
            PrintStringOnWindow(8, 5, _("What is this Pokémon's nickname?"), NAMING_WINDOW_NAME, '\0');
            break;
        case NAMING_PARTNER:
            PrintStringOnWindow(8, 5, _("What is your partner's nickname?"), NAMING_WINDOW_NAME, '\0');
            break;
        case NAMING_TEAM:
            PrintStringOnWindow(8, 5, _("What is your team's name?"), NAMING_WINDOW_NAME, '\0');
            break;
        case NAMING_PASSWORD1:
            PrintStringOnWindow(54, 2, _("Please enter the password."), NAMING_WINDOW_NAME, '\0');
            break;
        case NAMING_PASSWORD2:
            PrintStringOnWindow(48, 4, _("Please enter the password."), NAMING_WINDOW_NAME, '\0');
            break;
    }

    switch (sNamingScreen->type) {
        case NAMING_PASSWORD1:
            UpdatePassword1Window(sNamingScreen->textPtr, NAMING_WINDOW_NAME, 0);
            break;
        case NAMING_PASSWORD2:
            UpdatePassword2Window(sNamingScreen->textPtr, NAMING_WINDOW_NAME, 0);
            break;
        case NAMING_SELF:
        case NAMING_TEAM:
        case NAMING_POKEMON:
        case NAMING_PARTNER:
            AddDoubleUnderScoreHighlight(NAMING_WINDOW_NAME, 38, 33, GetMaxPokeNameWidth(), 4);
            if (GetStrWidth(sNamingScreen->textPtr, sNamingScreen->maxLetters) > GetMaxPokeNameWidth()) {
                sprintfStatic(text, _("{COLOR RED}%s{RESET}"), sNamingScreen->textPtr);
            }
            else if (GetEnteredNameLength() == sNamingScreen->maxLetters) {
                sprintfStatic(text, _("{COLOR CYAN}%s{RESET}"), sNamingScreen->textPtr);
            }
            else {
                sprintfStatic(text, _("%s"), sNamingScreen->textPtr);
            }
            PrintStringOnWindow(38, 22, text, NAMING_WINDOW_NAME, '\0');
            break;
    }

    sub_80073E0(NAMING_WINDOW_NAME);
}

static void UpdatePassword1Window(u8 *text, s32 windowId, s32 _yAdd)
{
    s32 i;
    s32 yAdd = (s16) _yAdd;

    for (i = 0; i < ARRAY_COUNT_INT(sPassword1CursorPositions); i++) {
        AddDoubleUnderScoreHighlight(windowId, sPassword1CursorPositions[i].x, sPassword1CursorPositions[i].y + 11 + yAdd, 11, 5);
    }

    for (i = 0; i < ARRAY_COUNT_INT(sPassword1CursorPositions) && text[i] != '\0'; i++) {
        s32 color;

        if (i <= 4) color = COLOR_WHITE_2;
        else if (i <= 12) color = COLOR_YELLOW;
        else if (i <= 17) color = COLOR_WHITE_2;
        else if (i <= 22) color = COLOR_WHITE_2;
        else if (i <= 30) color = COLOR_YELLOW;
        else if (i <= 35) color = COLOR_WHITE_2;
        else if (i <= 40) color = COLOR_WHITE_2;
        else if (i <= 48) color = COLOR_YELLOW;
        else color = 7;

        DrawCharOnWindowWidth12(sPassword1CursorPositions[i].x, sPassword1CursorPositions[i].y + yAdd, text[i], color, windowId);
    }
}

static void UpdatePassword2Window(u8 *text, s32 windowId, s32 _yAdd)
{
    s32 i;
    s32 yAdd = (s16) _yAdd;

    for (i = 0; i < ARRAY_COUNT_INT(sPassword2CursorPositions); i++) {
        AddDoubleUnderScoreHighlight(windowId, sPassword2CursorPositions[i].x, sPassword2CursorPositions[i].y + 11 + yAdd, 12, 5);
    }

    for (i = 0; i < ARRAY_COUNT_INT(sPassword2CursorPositions) && text[i] != '\0'; i++) {
        s32 color;

        if (i <= 3) color = COLOR_WHITE_2;
        else if (i <= 7) color = COLOR_YELLOW;
        else if (i <= 15) color = COLOR_WHITE_2;
        else if (i <= 19) color = COLOR_YELLOW;
        else color = COLOR_WHITE_2;

        DrawCharOnWindowWidth12(sPassword2CursorPositions[i].x, sPassword2CursorPositions[i].y + yAdd, text[i], color, windowId);
    }
}

static s32 GetEnteredNameLength(void)
{
    s32 len = 0;
    s32 i;

    for (i = 0; i < sNamingScreen->maxLetters; i++) {
        if (sNamingScreen->textPtr[i] != '\0') {
            len = i + 1;
        }
        else {
            break;
        }
    }

    return len;
}

static void UpdateLetterWidths(void)
{
    u32 chrId;
    const unkChar *chrInfo;
    s32 i;
    s32 total = 0;

    for (i = 0; i < sNamingScreen->maxLetters; i++) {
        sNamingScreen->letterTotalWidths[i] = total;
        if (sNamingScreen->textPtr[i] == '\0') {
            sNamingScreen->letterWidths[i] = 8;
            return;
        }
        chrId = GetCharId(sNamingScreen->textPtr[i]);
        chrInfo = GetCharacter(chrId);
        sNamingScreen->letterWidths[i] = chrInfo->width;
        total += chrInfo->width;
    }
}

s32 GetStrWidth(const u8 *buffer, s32 size)
{
    s32 i;
    s32 width = 0;

    for (i = 0; i < size && buffer[i] != '\0'; i++) {
        width += GetCharacter(GetCharId(buffer[i]))->width;
    }

    return width;
}

s32 GetMaxPokeNameWidth(void)
{
    return 60;
}
