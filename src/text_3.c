#include "global.h"
#include "text_1.h"
#include "text_2.h"
#include "text_3.h"

static const u8 *HandleTextFormat(Window *windows, const u8 *str, UnkDrawStringStruct *sp);
static s32 InterpretColorChar(u8 a0);
static const u8 *sub_800915C(s16 *a0, const u8 *str);
static void DrawStringInternal(Window *windows, s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr, s32 characterSpacing, s32 lineSpacing);

// arm9.bin::02003D4C
bool8 sub_8008D8C(s32 windowId)
{
    Window *strPtr = &gWindows[windowId];
    return strPtr->unk38 != 0;
}

#if (GAME_VERSION == VERSION_RED)
UNUSED static bool8 sub_8008DA8(void)
{
    return FALSE;
}

UNUSED static void sub_8008DAC(s32 a0, s32 a1, s32 a2)
{
    gBgTilemaps[0][a1][a0] = a2;
    gUnknown_20274A5 = TRUE;
}
#endif

// Maybe arm9.bin::02003D08
void sub_8008DC8(s32 x, s32 y, u16 bg0Val, u16 bg1Val)
{
    gBgTilemaps[0][y][x] = bg0Val;
    gBgTilemaps[1][y][x] = bg1Val;
    gUnknown_20274A5 = TRUE;
}

// Maybe arm9.bin::02003C88
UNUSED static void sub_8008DF4(s32 x, s32 y, u8 *src)
{
    u8 r1;

    while (TRUE) {
        if (*src == 0)
            break;

        r1 = *src;
        if (r1 >= 97 && r1 <= 122)
            r1 -= 32;

        gBgTilemaps[0][y][x] = TILEMAP_PAL(15) | (r1 + 0x258);
        src++;
        x++;
    }
    gUnknown_20274A5 = TRUE;
}

#if (GAME_VERSION == VERSION_RED)
UNUSED static void sub_8008E58(s32 a0, s32 a1, u8 *a2, s32 a3)
{
    u8 r1;

    while (TRUE) {
        if (*a2 == 0)
            break;

        r1 = *a2;
        if (a3 == 0)
            break;

        if (r1 >= 97 && r1 <= 122)
            r1 -= 32;

        gBgTilemaps[0][a1][a0] = TILEMAP_PAL(15) | (r1 + 0x258);
        a2++;
        a0++;
        a3--;
    }
    gUnknown_20274A5 = TRUE;
}
#endif

// arm9.bin::02003B34
s32 GetStringLineWidth(const u8 *str)
{
    s32 ret = 0;

    while (TRUE) {
        const u8 *strPtr;
        u32 chr;

        strPtr = xxx_get_next_char_from_string(str, &chr);
        str = strPtr;
        if (chr == '\0')
            break;
        if (chr == '\r' || chr == '\n')
            break;
        if (chr == 0x82A0 || chr == 0x82A2)
            continue;
        if (chr == '\e')
            break;

        if (chr == '#') {
            if (*strPtr == 'n' || *strPtr == '[' || *strPtr == 'P')
                break;
            switch (*strPtr) {
                case '=':
                case '~':
                    str = strPtr + 2;
                    break;
                case 'C':
                case 'c':
                    str += 2;
                    break;
                case 'R':
                case 'r':
                    str++;
                    break;
                case '+':
                case 'W':
                    str = strPtr + 1;
                    break;
            }
        }
        else if (chr == '`') {
            ret += 6;
        }
        else {
            const unkChar *ptr = GetCharacter(chr);
            if (ptr != NULL) {
                ret += ptr->width + gCharacterSpacing;
            }
        }
    }

    return ret;
}

// arm9.bin::02003AE8
void PrintStringOnWindow2(s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr, s32 lineSpacing)
{
    DrawStringInternal(gWindows, x, y, str, windowId, terminatingChr, 0, lineSpacing);
}

// arm9.bin::02003A9C
void PrintStringOnWindow(s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr)
{
    DrawStringInternal(gWindows, x, y, str, windowId, terminatingChr, 0, 13);
}

// arm9.bin::02003A50
UNUSED static void nullsub_170(s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr)
{
    // 2nd version of the above func, with gSubWindows
}

#if (GAME_VERSION == VERSION_RED)
// Identical to PrintStringOnWindow
UNUSED static void UnusedPrintStringOnWindow(s32 x, u32 y, const u8 *str, u32 windowId, u32 terminatingChr)
{
    DrawStringInternal(gWindows, x, y, str, windowId, terminatingChr, 0, 13);
}

UNUSED static void nullsub_171(void)
{
}
#endif

// arm9.bin::020038A4
static void DrawStringInternal(Window *windows, s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr, s32 characterSpacing, s32 lineSpacing)
{
    UnkDrawStringStruct sp;
    u32 currChr;

    sp.x = x;
    sp.unk2 = y;
    sp.unkC = x;
    sp.unk10 = 7;
    while (TRUE) {
        str = HandleTextFormat(windows, str, &sp);
        str = xxx_get_next_char_from_string(str, &currChr);
        if (currChr == '\0' || currChr == terminatingChr)
            break;

        if (currChr == 0x82A0) {
            gCurrentCharmap = 0;
        }
        else if (currChr == 0x82A2) {
            gCurrentCharmap = 1;
        }
        else if (currChr == '\e') {
            break;
        }
        else if (currChr == '\r' || currChr == '\n') {
            sp.x = sp.unkC;
            sp.unk2 += lineSpacing;
        }
        else if (currChr == '\x1D') { // ASCII group separator.
            sp.x = sp.unkC;
            sp.unk2 += 5;
        }
        else if (currChr == '`') {
            sp.x += 6;
        }
        else if (characterSpacing == 0) {
            sp.x += DrawCharOnWindowInternal(windows, sp.x, sp.unk2, currChr, sp.unk10, windowId);
        }
        else {
            const unkChar *chrPtr = GetCharacter(currChr);
            if (chrPtr != NULL) {
                s32 x = sp.x;
                s32 x2 = gCharacterSpacing + 10;
                x +=((x2 - chrPtr->width) / 2);
                DrawCharOnWindowInternal(windows, x, sp.unk2, currChr, sp.unk10, windowId);
                sp.x += characterSpacing;
            }
        }
    }
}

// arm9.bin::02003864
static const u8 *sub_800915C(s16 *a0, const u8 *str)
{
    s32 a = 0;

    while (TRUE)
    {
        if (*str == '.') {
            str++;
            break;
        }
        else if (*str >= '0' && *str <= '9') {
            a *= 10;
            a += (*str - '0');
            str++;
        }
        else {
            break;
        }
    }

    *a0 = a;
    return str;
}

// arm9.bin::02003844
const u8 *xxx_handle_format_global(const u8 *str, UnkDrawStringStruct *unkStrPtr)
{
    return HandleTextFormat(gWindows, str, unkStrPtr);
}

#if (GAME_VERSION == VERSION_RED)
UNUSED static s32 sub_80091A8(s32 a0)
{
    return a0 + 1;
}
#endif

// arm9.bin::02003514
static const u8 *HandleTextFormat(Window *windows, const u8 *str, UnkDrawStringStruct *sp)
{
    while (TRUE) {
        if (str[0] == '#') {
            if (str[1] == '[') {
                const u8 *strBefore = str;
                str += 2;
                sp->unk21 = 0;
                while (*str != '\0') {
                    if (*str == ']') {
                        str++;
                        break;
                    }
                    str++;
                }
                if (sp->unk24 != NULL) {
                    const u8 *strNew = sp->unk24(strBefore, str, sp);
                    if (strNew != NULL)
                        str = strNew;
                }

                if (sp->unk21 != 0)
                    break;
            }
            else if (str[1] == '=') {
                sp->x = str[2];
                str += 3;
                if (*str == '.')
                    str++;
            }
            else if (str[1] == 'y') {
                sp->unk2 = str[2];
                str += 3;
                if (*str == '.')
                    str++;
            }
            else if (str[1] == '>') {
                str = sub_800915C(&sp->x, str + 2);
            }
            else if (str[1] == '.') {
                sp->x += str[2];
                str += 3;
            }
            else if (str[1] == 'n') {
                sp->x = sp->unkC;
                sp->unk2 += 11;
                str += 2;
            }
            else if (str[1] == ':') {
                sp->unk4 = sp->x;
                str += 2;
            }
            else if (str[1] == ';') {
                sp->x = sp->unk4 + str[2];
                str += 3;
            }
            else if (str[1] == '+') {
                str += 2;
                sp->x = (windows[0].width * 8) - GetStringLineWidth(str);
                sp->x /= 2;
            }
            else if (str[1] == 'C') {
                sp->unk14 = sp->unk10;
                sp->unk10 = InterpretColorChar(str[2]);
                str += 3;
            }
            else if (str[1] == '_') {
                sp->unk14 = sp->unk10;
                sp->unk10 = gUnknown_202749A[str[2]];
                str += 3;
                if (*str == '.')
                    str++;
            }
            else if (str[1] == 'R') {
                sp->unk10 = sp->unk14;
                str += 2;
            }
            else if (str[1] == 'c') {
                sp->unk18 = sp->unk10;
                sp->unk10 = InterpretColorChar(str[2]);
                str += 3;
            }
            else if (str[1] == 'r') {
                sp->unk10 = sp->unk18;
                str += 2;
            }
            else if (str[1] == 'S') {
                gUnknown_20274A6[str[2] & 0x7F] = str[3] & 0x7F;
                str += 4;
            }
            else if (str[1] == 'W') {
                str += 2;
                sp->unk8 = ((windows[0].x * 8) + sp->x) - 2;
                sp->unkA = ((windows[0].y * 8) + sp->unk2) + 3;
                sp->unk20 = 1;
                break;
            }
            else if (str[1] == 'P') {
                str += 2;
                sp->unk2 = 9999;
                sp->unk1C = 0;
                sp->unk20 = 1;
                break;
            }
            else if (str[1] == 'p') {
                str += 2;
                sp->unk2 = 9999;
                sp->unk1C = 1;
                sp->unk20 = 1;
                break;
            }
            else if (str[1] == '~') {
                sp->unk2C = str[2];
                sp->unk21 = 1;
                str += 3;
            }
            else {
                return str;
            }
        }
        else {
            break;
        }
    }

    return str;
}

// arm9.bin::0200347C
void sub_8009388(void)
{
    s32 i, j;

    gBgTilemaps[0][0][0] = TILEMAP_PAL(15) | TILEMAP_TILE_NUM(0x279);
    gBgTilemaps[1][0][0] = TILEMAP_PAL(15) | TILEMAP_TILE_NUM(0x27A);
    for (i = gUnknown_202B020; i < gUnknown_202B024; i++) {
        gBgTilemaps[0][i][0] = TILEMAP_PAL(15) | TILEMAP_TILE_NUM(0x279);
        gBgTilemaps[1][i][0] = TILEMAP_PAL(15) | TILEMAP_TILE_NUM(0x27A);
        for (j = 1; j < 32; j++) {
            gBgTilemaps[0][i][j] = 0;
            gBgTilemaps[1][i][j] = TILEMAP_PAL(15) | TILEMAP_TILE_NUM(0x27A);
        }
    }
}

#if (GAME_VERSION == VERSION_BLUE)
// Blue has an extra func: arm9.bin::02003410
#endif

// arm9.bin::02003380
void sub_8009408(s32 from, s32 to)
{
    s32 i, j;

    gBgTilemaps[0][0][0] = TILEMAP_PAL(15) | TILEMAP_TILE_NUM(0x279);
    gBgTilemaps[1][0][0] = TILEMAP_PAL(15) | TILEMAP_TILE_NUM(0x27A);
    for (i = from; i < to; i++) {
        gBgTilemaps[0][i][0] = TILEMAP_PAL(15) | TILEMAP_TILE_NUM(0x279);
        gBgTilemaps[1][i][0] = TILEMAP_PAL(15) | TILEMAP_TILE_NUM(0x27A);
        for (j = 1; j < 32; j++) {
            gBgTilemaps[0][i][j] = 0;
            gBgTilemaps[1][i][j] = TILEMAP_PAL(15) | TILEMAP_TILE_NUM(0x27A);
        }
    }
    gUnknown_20274A5 = TRUE;
}

#if (GAME_VERSION == VERSION_RED)
UNUSED static void sub_8009488(s32 windowId)
{
    s32 i, j;
    s32 y, x;
    Window *window = &gWindows[windowId];

    y = window->y;
    for (i = 0; i < window->height; i++) {
        x = window->x;
        for (j = 0; j < window->width; j++) {
            gBgTilemaps[0][y][x] &= TILEMAP_PAL(15) | TILEMAP_FLIP_HORIZONTAL(1) | TILEMAP_FLIP_VERTICAL(1);
            gBgTilemaps[1][y][x] = TILEMAP_PAL(15) | TILEMAP_TILE_NUM(0x27A);
            x++;
        }
        y++;
    }
}

UNUSED static void nullsub_172(void)
{
}
#endif

// arm9.bin::020032DC
void sub_8009524(s32 windowId)
{
    s32 i, j;
    Window *window = &gWindows[windowId];
    s32 y = window->y - 1;

    for (i = 0; i < window->height + 2; i++) {
        s32 x = window->x - 1;
        for (j = 0; j < window->width + 2; j++) {
            gBgTilemaps[0][y][x] &= TILEMAP_PAL(15) | TILEMAP_FLIP_HORIZONTAL(1) | TILEMAP_FLIP_VERTICAL(1);
            gBgTilemaps[1][y][x] = TILEMAP_PAL(15) | TILEMAP_TILE_NUM(0x27A);
            x++;
        }
        y++;
    }
}

#if (GAME_VERSION == VERSION_RED)
UNUSED static void nullsub_173(void)
{
}
#endif

// arm9.bin::020032C0
void sub_80095CC(s32 a0, s32 a1)
{
    gUnknown_202B020 = a0;
    gUnknown_202B024 = a1;
}

#if (GAME_VERSION == VERSION_RED)
UNUSED static void nullsub_174(void)
{
}
#endif

// arm9.bin::02003278
s32 sub_80095E4(s32 a0, s32 a1)
{
    s32 r1;

    if (a1 == 0)
        a1 = 10;
    r1 = a0 * a1;

    if ((r1 % 8) != 0)
        return (r1 / 8) + 1;
    else
        return r1 / 8;
}

// arm9.bin::02003238
// Same as sub_80095E4 except it doesn't check for a1 == 0
s32 sub_8009614(s32 a0, s32 a1)
{
    s32 r1;

    r1 = a0 * a1;

    if ((r1 % 8) != 0)
        return (r1 / 8) + 1;
    else
        return r1 / 8;
}

// arm9.bin::02003158
static s32 InterpretColorChar(u8 a0)
{
    if (a0 < 16)
        return a0;
    if (a0 >= '0' && a0 <= '?')
        return a0 - '0';

    switch (a0) {
        case 'H':
        case 'I':
            return 4;
        case 'E':
        case 'S':
        case 'T':
            return 15;
        case 'G':
        case 'M':
            return 5;
        case 'C':
        case 'D':
        case 'N':
            return 6;
        case 'W':
            return 2;

    }
    return 7;
}
