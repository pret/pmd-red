#include "global.h"
#include "globaldata.h"
#include "code_800D090.h"
#include "code_80118A4.h"
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

struct unkStruct_203B1F8
{
    // size: 0x4B4
    u32 menuAction;
    MenuStruct unk4;
    WindowTemplates windows;
    u8 buffer[0x400];
};

EWRAM_INIT struct unkStruct_203B1F8 *gUnknown_203B1F8 = {NULL};

const WindowTemplate gUnknown_80DAF70 = {
   0x00,
   0x03,
   0x00, 0x00,
   0x00, 0x00,
   0x00, 0x00,
   NULL
};

const WindowTemplate gUnknown_80DAF88 = {
   0x00,
   0x03,
   0x02, 0x02,
   0x1A, 0x0c,
   0x0c, 0x00,
   NULL
};

const WindowTemplate gUnknown_80DAFA0 = {
   0x00,
   0x03,
   0x16, 0x0F,
   0x06, 0x03,
   0x03, 0x00,
   NULL
};

struct Struct80DB0F8
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 x;
    u8 y;
    u8 unk6;
    s32 unk8;
};

UNUSED static const char sPksDir[] = "pksdir0";
static const DungeonPos gUnknown_80DAFC0[] =
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

static const DungeonPos gUnknown_80DB098[] =
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

// It was programmed as a 2d array, however it's effectively a 1d array(since there's only one entry for [0][x]). Could be different in Blue?
static const struct Struct80DB0F8 gUnknown_80DB0F8[][85] =
{
    [0] = {
        {0,  0,  0,  0,  8,   3,  0, 264},
        {0,  0,  0,  0,  8,   14, 0, 264},
        {0,  0,  0,  0,  8,   25, 0, 264},
        {5,  4,  81, 9,  8,   36, 3, 263},
        {3,  5,  82, 10, 8,   47, 3, 261},
        {4,  3,  83, 11, 8,   58, 3, 262},
        {11, 7,  78, 12, 36,  3,  0, 97},
        {6,  8,  79, 13, 36,  14, 0, 110},
        {7,  9,  80, 14, 36,  25, 0, 65},
        {8,  10, 3,  15, 36,  36, 0, 78},
        {9,  11, 4,  16, 36,  47, 0, 233},
        {10, 6,  5,  17, 36,  58, 0, 43},
        {17, 13, 6,  18, 50,  3,  0, 98},
        {12, 14, 7,  19, 50,  14, 0, 111},
        {13, 15, 8,  20, 50,  25, 0, 66},
        {14, 16, 9,  21, 50,  36, 0, 79},
        {15, 17, 10, 22, 50,  47, 0, 49},
        {16, 12, 11, 23, 50,  58, 0, 45},
        {23, 19, 12, 24, 64,  3,  0, 99},
        {18, 20, 13, 25, 64,  14, 0, 112},
        {19, 21, 14, 26, 64,  25, 0, 67},
        {20, 22, 15, 27, 64,  36, 0, 80},
        {21, 23, 16, 28, 64,  47, 0, 50},
        {22, 18, 17, 29, 64,  58, 0, 44},
        {29, 25, 18, 30, 78,  3,  0, 100},
        {24, 26, 19, 31, 78,  14, 0, 113},
        {25, 27, 20, 32, 78,  25, 0, 68},
        {26, 28, 21, 33, 78,  36, 0, 81},
        {27, 29, 22, 34, 78,  47, 0, 51},
        {28, 24, 23, 35, 78,  58, 0, 46},
        {35, 31, 24, 36, 92,  3,  0, 101},
        {30, 32, 25, 37, 92,  14, 0, 114},
        {31, 33, 26, 38, 92,  25, 0, 69},
        {32, 34, 27, 39, 92,  36, 0, 82},
        {33, 35, 28, 40, 92,  47, 0, 52},
        {34, 30, 29, 41, 92,  58, 0, 33},
        {41, 37, 30, 42, 106, 3,  0, 102},
        {36, 38, 31, 43, 106, 14, 0, 115},
        {37, 39, 32, 44, 106, 25, 0, 70},
        {38, 40, 33, 45, 106, 36, 0, 83},
        {39, 41, 34, 46, 106, 47, 0, 53},
        {40, 36, 35, 47, 106, 58, 0, 63},
        {47, 43, 36, 48, 120, 3,  0, 103},
        {42, 44, 37, 49, 120, 14, 0, 116},
        {43, 45, 38, 50, 120, 25, 0, 71},
        {44, 46, 39, 51, 120, 36, 0, 84},
        {45, 47, 40, 52, 120, 47, 0, 54},
        {46, 42, 41, 53, 120, 58, 0, 145},
        {53, 49, 42, 54, 134, 3,  0, 104},
        {48, 50, 43, 55, 134, 14, 0, 117},
        {49, 51, 44, 56, 134, 25, 0, 72},
        {50, 52, 45, 57, 134, 36, 0, 85},
        {51, 53, 46, 58, 134, 47, 0, 55},
        {52, 48, 47, 59, 134, 58, 0, 146},
        {59, 55, 48, 60, 148, 3,  0, 105},
        {54, 56, 49, 61, 148, 14, 0, 118},
        {55, 57, 50, 62, 148, 25, 0, 73},
        {56, 58, 51, 63, 148, 36, 0, 86},
        {57, 59, 52, 64, 148, 47, 0, 56},
        {58, 54, 53, 65, 148, 58, 0, 147},
        {65, 61, 54, 66, 162, 3,  0, 106},
        {60, 62, 55, 67, 162, 14, 0, 119},
        {61, 63, 56, 68, 162, 25, 0, 74},
        {62, 64, 57, 69, 162, 36, 0, 87},
        {63, 65, 58, 70, 162, 47, 0, 57},
        {64, 60, 59, 71, 162, 58, 0, 148},
        {71, 67, 60, 72, 176, 3,  0, 107},
        {66, 68, 61, 73, 176, 14, 0, 120},
        {67, 69, 62, 74, 176, 25, 0, 75},
        {68, 70, 63, 75, 176, 36, 0, 88},
        {69, 71, 64, 76, 176, 47, 0, 48},
        {70, 66, 65, 77, 176, 58, 0, 189},
        {77, 73, 66, 78, 190, 3,  0, 108},
        {72, 74, 67, 79, 190, 14, 0, 121},
        {73, 75, 68, 80, 190, 25, 0, 76},
        {74, 76, 69, 81, 190, 36, 0, 89},
        {75, 77, 70, 82, 190, 47, 0, 58},
        {76, 72, 71, 83, 190, 58, 0, 190},
        {83, 79, 72, 6,  204, 3,  0, 109},
        {78, 80, 73, 7,  204, 14, 0, 122},
        {79, 81, 74, 8,  204, 25, 0, 77},
        {80, 82, 75, 3,  204, 36, 0, 90},
        {81, 83, 76, 4,  204, 47, 0, 133},
        {82, 78, 77, 5,  204, 58, 0, 32},
        {0,  0,  0,  0,  8,   3,  2, 265},
    }
};

static const u8 *const gUnknown_80DB4F4[] =
{
    _("゛"),
    _("゜"),
    _("かな"),
    _("カナ"),
    _("ＡＢＣ"),
    _("DEL"),
    _("END"),
};

static const WindowTemplate gUnknown_80DB538 = {
   0x00,
   0x03,
   0x00, 0x00,
   0x00, 0x00,
   0x00, 0x00,
   NULL
};

static const WindowTemplate gUnknown_80DB550 = {
   0x00,
   0x01,
   0x01, 0x0A,
   0x1C, 0x09,
   0x09, 0x00,
   NULL
};

static const WindowTemplate gUnknown_80DB568 = {
   0x00,
   0x01,
   0x04, 0x03,
   0x16, 0x05,
   0x05, 0x00,
   NULL
};

static const WindowTemplate gUnknown_80DB580 = {
   0x00,
   0x01,
   0x01, 0x02,
   0x1C, 0x07,
   0x07, 0x00,
   NULL
};

bool8 sub_8015080(u8 *buffer, const MenuItem *menuItems)
{
    s32 index;

    gUnknown_203B1F8 = MemoryAlloc(sizeof(struct unkStruct_203B1F8), 8);
    gUnknown_203B1F8->menuAction = 0;

    for(index = 0; index < 4; index++)
    {
        gUnknown_203B1F8->windows.id[index] = gUnknown_80DAF70;
    }

    gUnknown_203B1F8->windows.id[0] = gUnknown_80DAF88;
    gUnknown_203B1F8->windows.id[2] = gUnknown_80DAFA0;
    sub_8012CAC(&gUnknown_203B1F8->windows.id[2], menuItems);
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B1F8->windows, 1, 1);
    sub_80073B8(0);
    FormatString(buffer, gUnknown_203B1F8->buffer, gUnknown_203B1F8->buffer + 0x400, 0);
    PrintStringOnWindow(4, 4, gUnknown_203B1F8->buffer, 0, 0);
    sub_80073E0(0);
    sub_8012D60(&gUnknown_203B1F8->unk4, menuItems, 0, 0, -1, 2);
    return TRUE;
}

u32 sub_801516C(void)
{
    if(!sub_8012FD8(&gUnknown_203B1F8->unk4)) {
        sub_8013114(&gUnknown_203B1F8->unk4, &gUnknown_203B1F8->menuAction);
        return 3;
    }
    else {
        return 0;
    }
}

u32 sub_8015198(void)
{
    return gUnknown_203B1F8->menuAction;
}

void sub_80151A4(void)
{
    if(gUnknown_203B1F8) {
        MemoryFree(gUnknown_203B1F8);
        gUnknown_203B1F8 = NULL;
    }
}

#define MAX_TEXT_SIZE 54

struct NamingScreen
{
    // size: 0x198
    u32 type;
    u8 unk4;
    // Note: These had to be declared like these, because SpriteOAM is aligned by 4 and these aren't. Makes you think if SpriteOAM is actually a struct, and not just an array of 4 u16s.
    u16 sprite1Attribs[4];
    u16 sprite2Attribs[4];
    u8 letterCursorFrames;
    u8 inputCursorFrames;
    u8 unk18;
    u8 unk19;
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
void sub_8015A08(u32);
static void UpdateNameWindow(void);
void sub_8015F84();
static void SetLetterCursorSpritePosition(void);
static void HandleInputCursor(void);
static void sub_8015E10(u8 *a0, s32 a1, s32 _a2);
static void sub_8015EB4(u8 *a0, s32 a1, s32 _a2);
s32 GetMaxPokeNameWidth(void);
s32 GetStrWidth(u8 *buffer, s32 size);
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

u32 NamingScreen_Init(u32 type, u8 *defaultText)
{
    SpriteOAM *sprite;
    s32 index;
    s32 i;

    sNamingScreen = MemoryAlloc(sizeof(*sNamingScreen), 8);
    sNamingScreen->type = type;
    sNamingScreen->unk19 = 0;
    sNamingScreen->unk18 = 0;
    sNamingScreen->unk4 = 0;

    switch (sNamingScreen->type) {
        case NAMING_PASSWORD1:
            sNamingScreen->inputCursorPosition = 9;
            sNamingScreen->unk4 = 1;
            sNamingScreen->maxLetters = 0x36;
            break;
        case NAMING_PASSWORD2:
            sNamingScreen->inputCursorPosition = 9;
            sNamingScreen->unk4 = 1;
            sNamingScreen->maxLetters = 0x18;
            break;
        case NAMING_SELF:
        case NAMING_TEAM:
        case NAMING_PARTNER:
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

    SpriteSetAffine1((SpriteOAM *) &sNamingScreen->sprite1Attribs, 0);
    SpriteSetAffine2((SpriteOAM *) &sNamingScreen->sprite1Attribs, 0);
    SpriteSetObjMode((SpriteOAM *) &sNamingScreen->sprite1Attribs, 0);
    SpriteSetMosaic((SpriteOAM *) &sNamingScreen->sprite1Attribs, 0);
    SpriteSetBpp((SpriteOAM *) &sNamingScreen->sprite1Attribs, 0);
    SpriteSetPriority((SpriteOAM *) &sNamingScreen->sprite1Attribs, 0);
    SpriteSetPalNum((SpriteOAM *) &sNamingScreen->sprite1Attribs, 15);
    SpriteSetX((SpriteOAM *) &sNamingScreen->sprite1Attribs, DISPLAY_WIDTH);
    SpriteSetY((SpriteOAM *) &sNamingScreen->sprite1Attribs, DISPLAY_WIDTH);

    if (sNamingScreen->unk4 != 0) {
        SpriteSetMatrixNum((SpriteOAM *) &sNamingScreen->sprite1Attribs, 0);
        SpriteSetTileNum((SpriteOAM *) &sNamingScreen->sprite1Attribs, 0x3F6);
        SpriteSetSize((SpriteOAM *) &sNamingScreen->sprite1Attribs, 0);
        SpriteSetShape((SpriteOAM *) &sNamingScreen->sprite1Attribs, 1);
    }
    else {
        SpriteSetMatrixNum((SpriteOAM *) &sNamingScreen->sprite1Attribs, 16);
        SpriteSetTileNum((SpriteOAM *) &sNamingScreen->sprite1Attribs, 0x3F0);
        SpriteSetSize((SpriteOAM *) &sNamingScreen->sprite1Attribs, 0);
        SpriteSetShape((SpriteOAM *) &sNamingScreen->sprite1Attribs, 1);
    }

    sNamingScreen->letterCursorFrames = 4;

    sprite = (SpriteOAM *) &sNamingScreen->sprite2Attribs;

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

    for (index = 0; index < 4; index++) {
        sNamingScreen->windows.id[index] = gUnknown_80DB538;
    }

    if(sNamingScreen->unk4 != 0) {
        sNamingScreen->windows.id[1] = gUnknown_80DB580;
    }
    else {
        sNamingScreen->windows.id[1] = gUnknown_80DB568;
    }
    sNamingScreen->windows.id[0] = gUnknown_80DB550;

    ResetUnusedInputStruct();
    ShowWindows(&sNamingScreen->windows, 1, 1);

    sub_8015A08(1);
    UpdateNameWindow();
    sub_8015F84();
    return 1;
}

u32 NamingScreen_HandleInput(void)
{
    sNamingScreen->letterCursorFrames++;
    SetLetterCursorSpritePosition();
    if (sNamingScreen->letterCursorFrames & 8) {
        AddSprite((SpriteOAM *) &sNamingScreen->sprite1Attribs, 0x100, NULL, NULL);
    }

    sNamingScreen->inputCursorFrames++;
    HandleInputCursor();
    if (sNamingScreen->inputCursorFrames & 8) {
        AddSprite((SpriteOAM *) &sNamingScreen->sprite2Attribs, 0x100, NULL, NULL);
    }

    switch (sub_8012AE8()) {
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
    s32 var = gUnknown_80DB0F8[sNamingScreen->unk19][sNamingScreen->inputCursorPosition].unk8;

    switch (var) {
        case 0x107:
            sNamingScreen->unk18 = (sNamingScreen->unk18 == 0);
            PlayMenuSoundEffect(4);
            sub_8015A08(0);
            break;
        case 0x105:
            if (HandleBPress()) {
                return 2;
            }
            break;
        case 0x106:
            if (GetEnteredNameLength() == 0 || (sNamingScreen->unk4 != 0 && GetEnteredNameLength() != sNamingScreen->maxLetters)) {
                PlayMenuSoundEffect(2);
            }
            else {
                PlayMenuSoundEffect(0);
                MemoryCopy8(sNamingScreen->defaultText, sNamingScreen->textPtr, sNamingScreen->maxLetters);
                return 3;
            }
            break;
        default:
            if (sNamingScreen->unk4 != 0 && sub_803D0F0(var) == 0xFF) {
                PlayMenuSoundEffect(2);
            }
            else {
                if (sNamingScreen->unk18 == 1) {
                    s32 i;
                    for (i = sNamingScreen->maxLetters - 2; i >= sNamingScreen->letterCursorPos; i--) {
                        u8 *ptr = &sNamingScreen->textPtr[i];
                        ptr[1] = ptr[0];
                    }
                }

                sNamingScreen->textPtr[sNamingScreen->letterCursorPos] = var;
                if (sNamingScreen->letterCursorPos < sNamingScreen->maxLetters - 1) {
                    sNamingScreen->letterCursorPos++;
                }
                else {
                    sNamingScreen->inputCursorPosition = 5;
                }

                PlayMenuSoundEffect(0);
                UpdateNameWindow();
                sub_8015F84();
            }
            break;
    }

    return 0;
}

bool8 HandleBPress(void)
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
            sub_8015F84();
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
        sub_8015F84();
    }

    return FALSE;
}

static void SetLetterCursorSpritePosition(void)
{
    Window *window = &gWindows[1];

    // Note: for cases NAMING_PASSWORD1 and NAMING_PASSWORD2, the code is identical except for different position structs.
    if (sNamingScreen->type == NAMING_PASSWORD1) {
        s32 x, y;

        x = gUnknown_80DAFC0[sNamingScreen->letterCursorPos].x + (window->x * 8);
        SpriteSetX((SpriteOAM *) &sNamingScreen->sprite1Attribs, x);

        y = gUnknown_80DAFC0[sNamingScreen->letterCursorPos].y + (window->y * 8) + 5;
        SpriteSetY((SpriteOAM *) &sNamingScreen->sprite1Attribs, y);
    }
    else if (sNamingScreen->type == NAMING_PASSWORD2) {
        s32 x, y;

        x = gUnknown_80DB098[sNamingScreen->letterCursorPos].x + (window->x * 8);
        SpriteSetX((SpriteOAM *) &sNamingScreen->sprite1Attribs, x);

        y = gUnknown_80DB098[sNamingScreen->letterCursorPos].y + (window->y * 8) + 5;
        SpriteSetY((SpriteOAM *) &sNamingScreen->sprite1Attribs, y);
    }
    else {
        s32 x, y;

        x = sNamingScreen->letterTotalWidths[sNamingScreen->letterCursorPos] + (sNamingScreen->letterWidths[sNamingScreen->letterCursorPos] / 2) + 30 + (window->x * 8);
        SpriteSetX((SpriteOAM *) &sNamingScreen->sprite1Attribs, (u16) x);

        y = (window->y * 8) + 34;
        SpriteSetY((SpriteOAM *) &sNamingScreen->sprite1Attribs, y);
    }
}

static void HandleInputCursor(void)
{
    s32 x, y;
    Window *window = &gWindows[0];
    u32 newPosition;

    switch (sub_8012AE8()) {
        case INPUT_DPAD_UP:
            newPosition = gUnknown_80DB0F8[sNamingScreen->unk19][sNamingScreen->inputCursorPosition].unk0;
            break;
        case INPUT_DPAD_DOWN:
            newPosition = gUnknown_80DB0F8[sNamingScreen->unk19][sNamingScreen->inputCursorPosition].unk1;
            break;
        case INPUT_DPAD_LEFT:
            newPosition = gUnknown_80DB0F8[sNamingScreen->unk19][sNamingScreen->inputCursorPosition].unk2;
            break;
        case INPUT_DPAD_RIGHT:
            newPosition = gUnknown_80DB0F8[sNamingScreen->unk19][sNamingScreen->inputCursorPosition].unk3;
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

    x =  gUnknown_80DB0F8[sNamingScreen->unk19][sNamingScreen->inputCursorPosition].x + (window->x * 8) - 5;
    y =  gUnknown_80DB0F8[sNamingScreen->unk19][sNamingScreen->inputCursorPosition].y + (window->y * 8) + 1;
    SpriteSetX((SpriteOAM *) &sNamingScreen->sprite2Attribs, x);
    SpriteSetY((SpriteOAM *) &sNamingScreen->sprite2Attribs, y);
}

void sub_8015A08(u32 unused)
{
    s32 r4;
    s32 i;
    u8 text1[16];
    u8 text2[16];

    CallPrepareTextbox_8008C54(0);
    sub_80073B8(0);

    for (i = 0; (r4 = gUnknown_80DB0F8[sNamingScreen->unk19][i].unk8) != 0x109; i++) {
        s32 r5;

        switch (gUnknown_80DB0F8[sNamingScreen->unk19][i].unk6) {
            case 1:
                r5 = 5;
                break;
            case 2:
                r5 = 2;
                break;
            case 3:
                r5 = 7;
                break;
            default:
                r5 = 7;
                if (sNamingScreen->unk4 != 0) {
                    if (r4 <= 0xFF) {
                        if (sub_803D0F0(r4) == 0xFF) {
                            r5 = 2;
                        }
                    }
                    else if (r4 < 0x102) {
                        r5 = 2;
                    }
                }
                break;
        }

        if (r4 != 0x108) {
            if (r4 == 0x107) {
                if (sNamingScreen->unk18 == 0) {
                    PrintStringOnWindow(gUnknown_80DB0F8[sNamingScreen->unk19][i].x + 3, gUnknown_80DB0F8[sNamingScreen->unk19][i].y, _("{COLOR GREEN}OVR{RESET}"), 0, '\0');
                }
                else {
                    PrintStringOnWindow(gUnknown_80DB0F8[sNamingScreen->unk19][i].x + 3, gUnknown_80DB0F8[sNamingScreen->unk19][i].y, _("{COLOR YELLOW}INS{RESET}"), 0, '\0');
                }
            }
            else if (r4 == 0x20) {
                sprintfStatic(text1, _("{COLOR}%c{0x81}{0x59}"), r5);
                PrintStringOnWindow(gUnknown_80DB0F8[sNamingScreen->unk19][i].x + 1, gUnknown_80DB0F8[sNamingScreen->unk19][i].y, text1, 0, '\0');
            }
            else if (r4 > 0xFF) {
                sprintfStatic(text2, _("{COLOR}%c%s"), r5, gUnknown_80DB4F4[r4 & 0xFF]);
                PrintStringOnWindow(gUnknown_80DB0F8[sNamingScreen->unk19][i].x + 3, gUnknown_80DB0F8[sNamingScreen->unk19][i].y, text2, 0, '\0');
            }
            else {
                sub_8012C60(gUnknown_80DB0F8[sNamingScreen->unk19][i].x, gUnknown_80DB0F8[sNamingScreen->unk19][i].y, (u8) r4, r5, 0);
            }
        }
    }

    AddUnderScoreHighlight(0, 0, 0, 0xE0, 0xE);
    AddUnderScoreHighlight(0, 0, 0x47, 0xE0, 0xE);
    sub_8007A78(0, 0, 0, 0x48, 0xE);
    sub_8007A78(0, 0xDF, 0, 0x48, 0xE);
    sub_80073E0(0);
}

static void UpdateNameWindow(void)
{
    u8 text[80];

    CallPrepareTextbox_8008C54(1);
    sub_80073B8(1);
    if (sNamingScreen->unk4 != 0) {
        AddUnderScoreHighlight(1, 0, 0, 0xE0, 0xE);
        AddUnderScoreHighlight(1, 0, 0x37, 0xE0, 0xE);
        sub_8007A78(1, 0, 0, 0x38, 0xE);
        sub_8007A78(1, 0xDF, 0, 0x38, 0xE);
    }
    else {
        AddUnderScoreHighlight(1, 0, 0, 0xB0, 0xE);
        AddUnderScoreHighlight(1, 0, 0x27, 0xB0, 0xE);
        sub_8007A78(1, 0, 0, 0x28, 0xE);
        sub_8007A78(1, 0xAF, 0, 0x28, 0xE);
    }

    switch (sNamingScreen->type) {
        case NAMING_SELF:
            PrintStringOnWindow(8, 5, _("What is your name?"), 1, '\0');
            break;
        case NAMING_POKEMON:
            PrintStringOnWindow(8, 5, _("What is this Pokémon's nickname?"), 1, '\0');
            break;
        case NAMING_PARTNER:
            PrintStringOnWindow(8, 5, _("What is your partner's nickname?"), 1, '\0');
            break;
        case NAMING_TEAM:
            PrintStringOnWindow(8, 5, _("What is your team's name?"), 1, '\0');
            break;
        case NAMING_PASSWORD1:
            PrintStringOnWindow(54, 2, _("Please enter the password."), 1, '\0');
            break;
        case NAMING_PASSWORD2:
            PrintStringOnWindow(48, 4, _("Please enter the password."), 1, '\0');
            break;
    }

    switch (sNamingScreen->type) {
        case NAMING_PASSWORD1:
            sub_8015E10(sNamingScreen->textPtr, 1, 0);
            break;
        case NAMING_PASSWORD2:
            sub_8015EB4(sNamingScreen->textPtr, 1, 0);
            break;
        case NAMING_SELF:
        case NAMING_TEAM:
        case NAMING_POKEMON:
        case NAMING_PARTNER:
            AddDoubleUnderScoreHighlight(1, 38, 33, GetMaxPokeNameWidth(), 4);
            if (GetStrWidth(sNamingScreen->textPtr, sNamingScreen->maxLetters) > GetMaxPokeNameWidth()) {
                sprintfStatic(text, _("{COLOR RED}%s{RESET}"), sNamingScreen->textPtr);
            }
            else if (GetEnteredNameLength() == sNamingScreen->maxLetters) {
                sprintfStatic(text, _("{COLOR CYAN}%s{RESET}"), sNamingScreen->textPtr);
            }
            else {
                sprintfStatic(text, _("%s"), sNamingScreen->textPtr);
            }
            PrintStringOnWindow(38, 22, text, 1, '\0');
            break;
    }

    sub_80073E0(1);
}

static void sub_8015E10(u8 *a0, s32 a1, s32 _a2)
{
    s32 i;
    s32 a2 = (s16) _a2;

    for (i = 0; i < ARRAY_COUNT_INT(gUnknown_80DAFC0); i++) {
        AddDoubleUnderScoreHighlight(a1, gUnknown_80DAFC0[i].x, gUnknown_80DAFC0[i].y + 11 + a2, 11, 5);
    }

    for (i = 0; i < ARRAY_COUNT_INT(gUnknown_80DAFC0) && a0[i] != 0; i++) {
        s32 arg3;

        if (i <= 4) arg3 = 7;
        else if (i <= 12) arg3 = 6;
        else if (i <= 17) arg3 = 7;
        else if (i <= 22) arg3 = 7;
        else if (i <= 30) arg3 = 6;
        else if (i <= 35) arg3 = 7;
        else if (i <= 40) arg3 = 7;
        else if (i <= 48) arg3 = 6;
        else arg3 = 7;

        sub_8012C60(gUnknown_80DAFC0[i].x, gUnknown_80DAFC0[i].y + a2, a0[i], arg3, a1);
    }
}

static void sub_8015EB4(u8 *a0, s32 a1, s32 _a2)
{
    s32 i;
    s32 a2 = (s16) _a2;

    for (i = 0; i < ARRAY_COUNT_INT(gUnknown_80DB098); i++) {
        AddDoubleUnderScoreHighlight(a1, gUnknown_80DB098[i].x, gUnknown_80DB098[i].y + 11 + a2, 12, 5);
    }

    for (i = 0; i < ARRAY_COUNT_INT(gUnknown_80DB098) && a0[i] != 0; i++) {
        s32 arg3;

        if (i <= 3) arg3 = 7;
        else if (i <= 7) arg3 = 6;
        else if (i <= 15) arg3 = 7;
        else if (i <= 19) arg3 = 6;
        else arg3 = 7;

        sub_8012C60(gUnknown_80DB098[i].x, gUnknown_80DB098[i].y + a2, a0[i], arg3, a1);
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

void sub_8015F84(void)
{
    u32 uVar2;
    const unkChar *puVar3;
    s32 i;
    s32 total = 0;

    for (i = 0; i < sNamingScreen->maxLetters; i++) {
        sNamingScreen->letterTotalWidths[i] = total;
        if (sNamingScreen->textPtr[i] == '\0') {
            sNamingScreen->letterWidths[i] = 8;
            return;
        }
        uVar2 = ReturnIntFromChar2(sNamingScreen->textPtr[i]);
        puVar3 = GetCharacter(uVar2);
        sNamingScreen->letterWidths[i] = puVar3->width;
        total += puVar3->width;
    }
}

s32 GetStrWidth(u8 *buffer, s32 size)
{
    s32 i;
    s32 width = 0;

    for (i = 0; i < size && buffer[i] != '\0'; i++) {
        width += GetCharacter(ReturnIntFromChar2(buffer[i]))->width;
    }

    return width;
}

s32 GetMaxPokeNameWidth(void)
{
    return 60;
}
