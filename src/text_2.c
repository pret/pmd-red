#include "global.h"
#include "code_8009804.h"
#include "cpu.h"
#include "decompress_at.h"
#include "text_1.h"
#include "text_2.h"

static const u32 sUnknown_80B8868[] =
{
    0, 0xF, 0xFF, 0xFFF, 0xFFFF, 0xFFFFF, 0xFFFFFF, 0xFFFFFFF,
    0xFFFFFFFF, 0xFFFFFFF0, 0xFFFFFF00, 0xFFFFF000, 0xFFFF0000,
    0xFFF00000, 0xFF000000, 0xF0000000
};

static void AddUnderScoreHighlightInternal(Window *windows, u32 windowId, s32 x, s32 y, s32 width, u32 color);
static void DisplayMonPortrait(Window *a0, u16 a1[32][32], s32 a2, const u8 *compressedData, u32 a4);
static void DisplayMonPortraitFlipped(Window *windows, s32 windowId, const u8 *compressedData, s32 a3);
static u32 FlipPixelsHorizontally(u32 a0);
static s32 HexDigitValue(u8 chr);
static void nullsub_129(u32 windowId, s32 x, s32 y, s32 width, u32 color);
static void sub_8007AA4(Window *windows, u32 windowId, s32 x, s32 y, s32 a4, u32 color);
static void sub_8007BA8(Window *windows, u32 windowId, s32 x, s32 y, s32 a4, s32 color);
static void sub_8007D00(Window *windows, u32 windowId, s32 x, s32 y, s32 a4, s32 color);
static void sub_8007E64(Window *a0, u16 a1[32][32], u32 a2, s32 a3, s32 a4, s32 a5, s32 a6, u32 *a7, u32 a8);
static void sub_8008030(Window *a0, u16 a1[32][32], u32 a2, s32 a3, s32 a4, s32 a5, s32 a6, u32 *a7, u32 a8);
static void sub_8008334(u32 *r7, u32 *r12);
static void sub_80084A4(Window *a0, u16 a1[32][32], u32 a2, s32 a3, s32 a4, s32 a5, s32 a6, u32 a8);
static void sub_8008818(Window *windows, s32 windowId, s32 a2, s32 a3, s32 a4, s32 a5);
static bool8 xxx_update_bg_vram(Window *windows);

// TODO: Find these funcs in blue. DTCM funcs

// In NDS, this func is copied to 01FF9F34
u32 xxx_call_draw_char(s32 x, s32 y, u32 a2, u32 color, u32 a4)
{
    return xxx_draw_char(gWindows, x, y, a2, color, a4);
}

UNUSED static bool8 sub_8007464(void)
{
    return FALSE;
}

// In NDS, this func is copied to 01FF994C
u32 xxx_draw_char(Window *windows, s32 x, s32 y, u32 a3, u32 color, u32 windowId)
{
    u32 *r3;
    const unkShiftData *shiftData;
    const unkChar *sp0;
    const u16 *local_44;
    const u16 *sp8;
    const u16 *local_3c;
    s32 i;
    s32 xDiv8, yDiv8;
    Window *window = &windows[windowId];
    s32 sp18 = gUnknown_80B853C[color & 0xF];
    u8 var_2C;
    u32 r4;
    u32 r2;

    if (gCurrentCharmap == 1) {
        if (a3 == 0x70 || a3 == 0x6A || a3 == 0x71 || a3 == 0x79 || a3 == 0x67)
            y += 2;
        else if (a3 == 0x8199)
            y -= 2;
    }

    sp0 = GetCharacter(a3);
    local_44 = sp0->unk0;
    ASM_MATCH_TRICK(local_3c); // stack doesn't match without it
    local_3c = sp0->unk0;
    sp8 = sp0->unk0 - 3;

    if (gDrawTextShadow != 0) {
        var_2C = (sp0->unkA >> 1) & 1;
    }
    else {
        var_2C = 0;
    }

    if (sp0->unkA & 1) {
        r3 = window->unk18 + ((((y / 8) * window->width) + (x / 8)) * 8);
        r3 += y - (y / 8 * 8);
        shiftData = &gCharMasksOffsets[x - ((x / 8) * 8)];
        xDiv8 = x / 8;
        yDiv8 = y / 8;

        if (yDiv8 < window->unk8) {
            for (i = 0; i < gCharHeight[gCurrentCharmap]; i++) {
                r2 = (local_44[1] << 0x10) | (local_44[0]);
                if (r2 != 0) {
                    if (xDiv8 < window->width) {
                        *r3 |= (shiftData->bytesA & r2) << shiftData->shift_left;
                        if (window->unk3C > r3)
                            window->unk3C = r3;
                        if (window->unk40 < r3)
                            window->unk40 = r3;
                    }
                    if (xDiv8 < window->width - 1) {
                        r3 += 8;
                        r2 &= shiftData->bytesB;
                        *r3 |= (r2) >> shiftData->shift_right;
                        if (window->unk40 < r3)
                            window->unk40 = r3;
                        r3 -= 8;
                    }
                }

                r2 = local_44[2];
                if (r2 != 0) {
                    if (xDiv8 < window->width - 1) {
                        r3 += 8;
                        *r3 |= (r2 & shiftData->bytesA) << shiftData->shift_left;
                        if (window->unk40 < r3)
                            window->unk40 = r3;
                        r3 -= 8;
                    }
                    if (xDiv8 < window->width - 2) {
                        r3 += 16;
                        *r3 |= (r2 & shiftData->bytesB) >> shiftData->shift_right;
                        if (window->unk40 < r3)
                            window->unk40 = r3;
                        r3 -= 16;
                    }
                }

                local_44 += 3;
                r3++;
                y++;
                if (y % 8 == 0) {
                    r3 += window->unk20;
                    yDiv8++;
                    if (yDiv8 >= window->unk8)
                        break;
                }
            }
        }
    }
    else {
        bool8 notFirstIteration = FALSE;
        u32 r1;

        r3 = window->unk18 + ((((y / 8) * window->width) + (x / 8)) * 8);
        r3 += y - (y / 8 * 8);
        shiftData = &gCharMasksOffsets[x - ((x / 8) * 8)];
        xDiv8 = x / 8;
        yDiv8 = y / 8;

        if (yDiv8 < window->unk8) {
            for (i = 0; i < gCharHeight[gCurrentCharmap]; i++) {
                r4 = (local_44[1] << 0x10) | (local_44[0]);
                r2 = (0x11111111 & r4) + (sp18 & r4);

                if (var_2C != 0) {
                    r1 = ((local_3c[1] << 0x10) | local_3c[0]) << 4;
                    r1 |= r4; // This doesn't really do anything since r4 bits are cleared, but it's needed to match.
                    r1 &= ~(r4);
                    r1 &= gTextShadowMask;
                    r2 |= (r1);
                    if (notFirstIteration) {
                        r1 = (((sp8[1] << 0x10) | sp8[0]) << 4) ^ r4;
                        r1 &= ~(r4);
                        r2 |= (r1 & gTextShadowMask);
                    }
                }

                if (r2 != 0) {
                    if (xDiv8 < window->width) {
                        *r3 |= (r2 & shiftData->bytesA) << shiftData->shift_left;
                        if (window->unk3C > r3)
                            window->unk3C = r3;
                        if (window->unk40 < r3)
                            window->unk40 = r3;
                    }
                    if (xDiv8 < window->width - 1) {
                        r3 += 8;
                        *r3 |= (r2 & shiftData->bytesB) >> shiftData->shift_right;
                        if (window->unk40 < r3)
                            window->unk40 = r3;
                        r3 -= 8;
                    }
                }

                r4 = local_44[2];
                r2 = (0x11111111 & r4) + (sp18 & r4);
                if (var_2C != 0) {
                    r1 = (local_3c[2] << 4) | ((local_3c[1] >> 0xC) & 0xF);
                    r1 |= r4; // This doesn't really do anything since r4 bits are cleared, but it's needed to match.
                    r1 &= ~(r4);
                    r1 &= gTextShadowMask;
                    r2 |= r1;
                    if (notFirstIteration) {
                        r1 = ((sp8[2] << 4) | ((sp8[1] >> 0xC) & 0xF)) ^ r4;
                        r1 &= ~(r4);
                        r1 &= gTextShadowMask;
                        r2 |= (r1);
                    }
                }

                if (r2 != 0) {
                    if (xDiv8 < window->width - 1) {
                        r3 += 8;
                        *r3 |= (r2 & shiftData->bytesA) << shiftData->shift_left;
                        if (window->unk40 < r3)
                            window->unk40 = r3;
                        r3 -= 8;
                    }
                    if (xDiv8 < window->width - 2) {
                        r3 += 16;
                        *r3 |= (r2 & shiftData->bytesB) >> shiftData->shift_right;
                        if (window->unk40 < r3)
                            window->unk40 = r3;
                        r3 -= 16;
                    }
                }

                notFirstIteration = TRUE;
                local_44 += 3;
                sp8 += 3;
                local_3c += 3;
                r3++;
                y++;
                if (y % 8 == 0) {
                    r3 += window->unk20;
                    yDiv8++;
                    if (yDiv8 >= window->unk8)
                        break;
                }
            }
        }
    }

    return sp0->unk6 + gCharacterSpacing;
}

void AddDoubleUnderScoreHighlight(u32 windowId, s32 x, s32 y, s32 width, u32 color)
{
    AddUnderScoreHighlight(windowId, x, y, width, color);
    AddUnderScoreHighlight(windowId, x, y + 1, width, gTextShadowMask & 0xF);
}

UNUSED static void sub_80078E8(u32 a0, s32 x, s32 y, s32 a3, u32 color)
{
    nullsub_129(a0, x, y, a3, color);
    nullsub_129(a0, x, y + 1, a3, gTextShadowMask & 0xF);
}

void AddUnderScoreHighlight(u32 windowId, s32 x, s32 y, s32 width, u32 color)
{
    AddUnderScoreHighlightInternal(gWindows, windowId, x, y, width, color);
}

static void nullsub_129(u32 windowId, s32 x, s32 y, s32 width, u32 color)
{
}

static void AddUnderScoreHighlightInternal(Window *windows, u32 windowId, s32 x, s32 y, s32 width, u32 color)
{
    u32 uVar4;
    u32 *dest;
    s32 r4;
    const unkShiftData *shiftData;
    Window *window;
    s32 r6;
    u32 r9;

    window = &windows[windowId];
    r9 = gUnknown_80B853C[color & 0xF];

    r4 = y / 8;

    dest = window->unk18 + (((window->width * r4) + (x / 8)) * 8);
    dest += (r4 * -8) + y;
    r6 = x / 8;

    if (y / 8 >= window->unk8) {
        return;
    }
    else {
        const u32 unkBits[] = {0, 0xF, 0xFF, 0xFFF, 0xFFFF, 0xFFFFF, 0xFFFFFF, 0xFFFFFFF, 0xFFFFFFFF};

        for (; width > 0; width -= 8) {
            s32 currWidth = width;
            if (currWidth > 7)
                currWidth = 8;

            shiftData = &gCharMasksOffsets[x + (x / 8 * -8)];

            uVar4 = unkBits[currWidth];
            uVar4 = (uVar4 & 0x11111111) + (uVar4 & r9);

            if (uVar4 != 0) {
                if (r6 < window->width) {
                    dest[0] |= (shiftData->bytesA & uVar4) << shiftData->shift_left;

                    if (window->unk3C > dest)
                        window->unk3C = dest;
                    if (window->unk40 < dest)
                        window->unk40 = dest;
                }

                if (r6 < window->width - 1) {
                    dest += 8;
                    dest[0] |= (uVar4 & shiftData->bytesB) >> shiftData->shift_right;

                    if (window->unk40 < dest)
                        window->unk40 = dest;
                    dest -= 8;
                }
            }

            r6++;
            dest += 8;
        }
    }
}

void sub_8007A78(u32 a0, s32 x, s32 y, s32 a3, u32 color)
{
    sub_8007AA4(gWindows, a0, x, y, a3, color);
}

UNUSED static void nullsub_157(void)
{
}

static void sub_8007AA4(Window *windows, u32 windowId, s32 x, s32 y, s32 a4, u32 color)
{
    Window *window = &windows[windowId];
    u32 ip = gUnknown_80B853C[color & 0xF] + 0x11111111;
    const u32 unkBits[] = {0xF, 0xF0, 0xF00, 0xF000, 0xF0000, 0xF00000, 0xF000000, 0xF0000000};
    s32 r3 = y / 8;
    u32 *dest = window->unk18 + ((window->width * r3 + x / 8) * 8);
    s32 r2 = x / 8;

    dest += r3 * -8 + y;
    ip &= unkBits[x & 7];

    if (r2 < window->width) {
        // This goto looks like a fakematch, but I couldn't get it to work otherwise.
        goto LOOP_MIDDLE;
        while (1) {
            y++;
            dest++;
            if ((y % 8) == 0)
                dest += window->unk20;
            a4--;

        LOOP_MIDDLE:
            if (a4 <= 0)
                return;
            if (r3 >= window->unk8)
                return;

            dest[0] |= ip;

            if (window->unk3C > dest)
                window->unk3C = dest;
            if (window->unk40 < dest)
                window->unk40 = dest;
        }
    }
}

void sub_8007B7C(u32 a0, s32 x, s32 y, s32 a3, u32 color)
{
    sub_8007BA8(gWindows, a0, x, y, a3, color);
}

UNUSED static void nullsub_158(void)
{
}

static void sub_8007BA8(Window *windows, u32 windowId, s32 x, s32 y, s32 a4, s32 color)
{
    u32 *dst;
    s32 i;
    s32 xDiv8, yDiv8;
    s32 j, k;

    Window *window = &windows[windowId];
    yDiv8 = y / 8;
    if (yDiv8 >= window->unk8)
        return;

    dst = window->unk18 + (((yDiv8 * window->width) + x / 8) * 8);
    dst += y - (yDiv8 * 8);

    for (i = 0; i < color; i++) {
        u32 *loopDst = dst;
        xDiv8 = x / 8;

        for (j = 0; j < a4; j += 8) {
            if (xDiv8 < window->width) {
                u32 andBits = 0xF0000000;
                u32 orBits = 0xE0000000;
                u32 bits = 0;
                u32 var = *loopDst;

                for (k = 0; k < 8; k++) {
                    if (!(var & andBits))
                        bits |= orBits;

                    andBits >>= 4;
                    orBits >>= 4;
                }

                *loopDst |= bits;
                if (window->unk3C > loopDst)
                    window->unk3C = loopDst;
                if (window->unk40 < loopDst)
                    window->unk40 = loopDst;

                xDiv8++;
                loopDst += 8;
            }
            else {
                break;
            }
        }

        y++;
        dst++;
        if ((y % 8) == 0) {
            dst += window->unk20;
            yDiv8++;
            if (yDiv8 >= window->unk8)
                return;
        }
    }
}

UNUSED static void sub_8007CD4(u32 a0, s32 a1, s32 a2, s32 a3, s32 a4)
{
    sub_8007D00(gWindows, a0, a1, a2, a3, a4);
}

UNUSED static void nullsub_159(void)
{
}

// Very similar to sub_8007BA8. It clears bits instead of setting them.
static void sub_8007D00(Window *windows, u32 windowId, s32 x, s32 y, s32 a4, s32 color)
{
    u32 *dst;
    s32 i;
    s32 xDiv8, yDiv8;
    s32 j, k;

    Window *window = &windows[windowId];
    yDiv8 = y / 8;
    if (yDiv8 >= window->unk8)
        return;

    dst = window->unk18 + (((yDiv8 * window->width) + x / 8) * 8);
    dst += y - (yDiv8 * 8);

    for (i = 0; i < color; i++) {
        u32 *loopDst = dst;
        xDiv8 = x / 8;

        for (j = 0; j < a4; j += 8) {
            if (xDiv8 < window->width) {
                u32 andBits = 0xF0000000;
                u32 equalBits = 0xE0000000;
                u32 bits = 0;
                u32 var = *loopDst;

                for (k = 0; k < 8; k++) {
                    if ((var & andBits) == equalBits)
                        bits |= andBits;

                    andBits >>= 4;
                    equalBits >>= 4;
                }

                *loopDst &= ~(bits);
                if (window->unk3C > loopDst)
                    window->unk3C = loopDst;
                if (window->unk40 < loopDst)
                    window->unk40 = loopDst;

                xDiv8++;
                loopDst += 8;
            }
            else {
                break;
            }
        }

        y++;
        dst++;
        if ((y % 8) == 0) {
            dst += window->unk20;
            yDiv8++;
            if (yDiv8 >= window->unk8)
                return;
        }
    }
}

void sub_8007E20(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 *a5, u32 a6)
{
    sub_8007E64(gWindows, gBgTilemaps[0], a0, a1, a2, a3, a4, a5, a6);
}

UNUSED static void nullsub_160(void)
{
}

static void sub_8007E64(Window *a0, u16 a1[32][32], u32 a2, s32 a3, s32 a4, s32 a5, s32 a6, u32 *a7, u32 a8)
{
    s32 i, j;
    Window *window = &a0[a2];

    a3 /= 8;
    a4 /= 8;
    a5 /= 8;
    a6 /= 8;
    a8 *= 4096;
    if (a4 < window->unk8) {
        s32 id = (window->width * a4) + a3;
        u32 *unk18Ptr = &window->unk18[id * 8];

        for (i = 0; i < a6; i++) {
            s32 xMaybe = a3;
            u32 *loopUnk18Ptr = unk18Ptr;
            for (j = 0; j < a5; j++) {
                if (xMaybe < window->width) {
                    if (window->unk3C > loopUnk18Ptr) {
                        window->unk3C = loopUnk18Ptr;
                    }
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *a7;
                    if (window->unk40 < loopUnk18Ptr) {
                        window->unk40 = loopUnk18Ptr;
                    }
                    a7++;
                    a1[window->y + a4][window->x + xMaybe] &= 0xFFF;
                    a1[window->y + a4][window->x + xMaybe] |= a8;
                }
                else {
                    loopUnk18Ptr += 8;
                    a7 += 8;
                }
                xMaybe++;
            }
            a4++;
            unk18Ptr += window->unk20;
            unk18Ptr += 8;
            if (a4 >= window->unk8)
                break;
        }
    }
}

static u32 FlipPixelsHorizontally(u32 a0)
{
    u32 r0;

    r0 = (a0 >> 28)  & 0xF;
    r0 |= (a0 >> 20) & 0xF0;
    r0 |= (a0 >> 12) & 0xF00;
    r0 |= (a0 >> 4)  & 0xF000;
    r0 |= (a0 << 4)  & 0xF0000;
    r0 |= (a0 << 12) & 0xF00000;
    r0 |= (a0 << 20) & 0xF000000;
    r0 |= (a0 << 28) & 0xF0000000;

    return r0;
}

UNUSED static void sub_8007FEC(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 *a5, u32 a6)
{
    sub_8008030(gWindows, gBgTilemaps[0], a0, a1, a2, a3, a4, a5, a6);
}

UNUSED static void nullsub_161(void)
{
}

// Similar to sub_8007E64
static void sub_8008030(Window *a0, u16 a1[32][32], u32 a2, s32 a3, s32 a4, s32 a5, s32 a6, u32 *a7, u32 a8)
{
    s32 i, j;
    Window *window = &a0[a2];

    a3 /= 8;
    a4 /= 8;
    a5 /= 8;
    a6 /= 8;
    a8 *= 4096;
    if (a4 < window->unk8) {
        u32 *unk18Ptr = &window->unk18[((window->width * a4) + (a3 + a5)) * 8];
        for (i = 0; i < a6; i++) {
            s32 xMaybe = a3 + a5;
            u32 *loopUnk18Ptr = unk18Ptr;
            for (j = 0; j < a5; j++) {
                xMaybe--;
                loopUnk18Ptr -= 8;
                if (xMaybe < window->width) {
                    if (window->unk3C > loopUnk18Ptr) {
                        window->unk3C = loopUnk18Ptr;
                    }
                    loopUnk18Ptr[0] = FlipPixelsHorizontally(*(a7++));
                    loopUnk18Ptr[1] = FlipPixelsHorizontally(*(a7++));
                    loopUnk18Ptr[2] = FlipPixelsHorizontally(*(a7++));
                    loopUnk18Ptr[3] = FlipPixelsHorizontally(*(a7++));
                    loopUnk18Ptr[4] = FlipPixelsHorizontally(*(a7++));
                    loopUnk18Ptr[5] = FlipPixelsHorizontally(*(a7++));
                    loopUnk18Ptr[6] = FlipPixelsHorizontally(*(a7++));
                    loopUnk18Ptr[7] = FlipPixelsHorizontally(*(a7++));
                    if (window->unk40 < loopUnk18Ptr + 8) {
                        window->unk40 = loopUnk18Ptr + 8;
                    }
                    a1[window->y + a4][window->x + xMaybe] &= 0xFFF;
                    a1[window->y + a4][window->x + xMaybe] |= a8;
                }
                else {
                    a7 += 8;
                }
            }
            a4++;
            unk18Ptr += window->unk20;
            unk18Ptr += 8;
            if (a4 >= window->unk8)
                break;
        }
    }
}

// Similar to sub_8007E64
UNUSED static void sub_80081A4(s32 a0, s32 a3, s32 a4, s32 a7Id)
{
    s32 i, j, a5, a6;
    Window *window = &gWindows[a0];
    const u32 *a7 = gUnknown_80B86B4[a7Id];

    a3 /= 8;
    a4 /= 8;
    a5 = 2;
    a6 = 2;
    if (a4 < window->unk8) {
        s32 id = (window->width * a4) + a3;
        u32 *unk18Ptr = &window->unk28[id * 8];

        for (i = 0; i < a6; i++) {
            s32 xMaybe = a3;
            u32 *loopUnk18Ptr = unk18Ptr;
            for (j = 0; j < a5; j++) {
                if (xMaybe < window->width) {
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *a7;
                    a7++;
                }
                else {
                    loopUnk18Ptr += 8;
                    a7 += 8;
                }
                xMaybe++;
            }
            a4++;
            unk18Ptr += window->unk20;
            unk18Ptr += 8;
            if (a4 >= window->unk8)
                break;
        }
    }
}

void DisplayMonPortraitSprite(s32 a0, const u8 *compressedData, s32 a2)
{
    DisplayMonPortrait(gWindows, gBgTilemaps[0], a0, compressedData, a2);
}

UNUSED static void nullsub_162(void)
{
}

static void DisplayMonPortrait(Window *a0, u16 a1[32][32], s32 a2, const u8 *compressedData, u32 a4)
{
    s32 i, j;
    Window *window = &a0[a2];

    a4 *= 4096;
    DecompressAT((u8 *)window->unk18, (window->width * 32) * window->unk8, compressedData);
    for (i = 0; i < window->unk8; i++) {
        for (j = 0; j < window->width; j++) {
            a1[window->y + i][window->x + j] &= 0xFFF;
            a1[window->y + i][window->x + j] |= a4;
        }
    }
    window->unk30 = window->unk28;
    window->unk34 = window->unk1C;
    window->unk38 = window->unk2C;
    window->unk44 = 1;
}

static void sub_8008334(u32 *r7, u32 *r12)
{
    s32 i;
    u32 r2, r3;
    u32 r4, r1;

    r4 = *r7;
    r1 = *r12;

    r3 = 0;
    r2 = 0;

    for (i = 0; i < 32; i += 4) {
        r2 <<= 4;
        r3 <<= 4;
        r2 |= r4 & 0xF;
        r3 |= r1 & 0xF;
        r4 >>= 4;
        r1 >>= 4;
    }
    *r7 = r3;
    *r12 = r2;
}

void DisplayMonPortraitSpriteFlipped(s32 a0, const u8 *compressedData, s32 a1)
{
    DisplayMonPortraitFlipped(gWindows, a0, compressedData, a1);
}

UNUSED static void nullsub_163(void)
{
}

static void DisplayMonPortraitFlipped(Window *windows, s32 windowId, const u8 *compressedData, s32 a3)
{
    s32 i, j;
    Window *window = &windows[windowId];

    DisplayMonPortraitSprite(windowId, compressedData, a3);
    for (i = 0; i < window->unk8; i++) {
        s32 r8 = window->width / 2;
        if (window->width & 1)
            r8++;
        for (j = 0; j < r8; j++) {
            u32 *r4, *r5;
            s32 unk4Mul = window->width * i;

            r4 = &window->unk18[(unk4Mul + j) * 8];
            unk4Mul--;
            r5 = &window->unk18[(unk4Mul + (window->width - j)) * 8];

            sub_8008334(r4++, r5++);
            sub_8008334(r4++, r5++);
            sub_8008334(r4++, r5++);
            sub_8008334(r4++, r5++);
            sub_8008334(r4++, r5++);
            sub_8008334(r4++, r5++);
            sub_8008334(r4++, r5++);
            sub_8008334(r4++, r5++);
        }
    }
}

UNUSED static void sub_8008468(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a6)
{
    sub_80084A4(gWindows, gBgTilemaps[0], a0, a1, a2, a3, a4, a6);
}

UNUSED static void nullsub_164(void)
{
}

// Effectively unused
static void sub_80084A4(Window *a0, u16 a1[32][32], u32 a2, s32 a3, s32 a4, s32 a5, s32 a6, u32 a8)
{
    s32 i, j;
    Window *window = &a0[a2];

    a3 /= 8;
    a4 /= 8;
    a5 /= 8;
    a6 /= 8;
    a8 *= 4096;
    if (a4 < window->unk8) {
        for (i = 0; i < a6; i++) {
            s32 xMaybe = a3;
            for (j = 0; j < a5; j++) {
                if (xMaybe < window->width) {
                    a1[window->y + a4][window->x + xMaybe] &= 0xFFF;
                    a1[window->y + a4][window->x + xMaybe] |= a8;
                }
                xMaybe++;
            }
            a4++;
            if (a4 >= window->unk8)
                break;
        }
    }
}

// Oddly similar to sub_803DEC8
// In NDS, this func is copied to 01FF8E40
const unkChar *GetCharacter(s32 chr)
{
    s32 r2, r4;
    const unkChar *ret;
    const unkChar *strPtr = gCharmaps[gCurrentCharmap]->unk4;
    // TODO: create labels for these
    if (chr > 63487 && chr < 65535)
    {
        s32 r2 = chr & 0xFF;
        s32 r1 = (chr & 0xFF00) >> 8;
        r2 -= 32;
        r1 -= 248;
        ret = &strPtr[r1 * 224 + r2];
    }
    else
    {
        r4 = 0;
        r2 = gCharmaps[gCurrentCharmap]->unk0 - 1;
        while (r4 < r2) {
            s32 r1 = (r4 + r2) / 2;
            if (strPtr[r1].unk4 == chr) {
                r4 = r1;
                break;
            }
            else if (strPtr[r1].unk4 < chr) {
                r4 = r1 + 1;
            }
            else {
                r2 = r1;
            }
        }

        ret = &strPtr[r4];
        if (ret->unk4 != chr)
            ret = &gUnknown_80B86A4;

    }
    return ret;
}

static s32 HexDigitValue(u8 chr)
{
    if (chr >= '0' && chr <= '9')
        return chr - '0';
    else if (chr >= 'a' && chr <= 'f')
        return (chr - 'a') + 10;
    else
        return 1;
}

// In NDS, this func is copied to 01FF8D80
const u8 *xxx_get_next_char_from_string(const u8 *a1, u32 *a0)
{
    s32 currChr = *a1;
    if (currChr == 0x7E) {
        s32 hexDigit;

        a1++;
        hexDigit = (HexDigitValue(a1[0]) << 4) + HexDigitValue(a1[1]);
        if (*a1 != '\0') {
            a1++;
            if (*a1 != '\0') {
                a1++;
            }
        }
        *a0 = hexDigit;
        return a1;
    }
    else if ((currChr >= 0x81 && currChr <= 0x84) || currChr == 0x87) {
        *a0 = a1[1] | (a1[0] << 8);
        return a1 + 2;
    }
    else {
        *a0 = currChr;
        return a1 + 1;
    }
}

UNUSED static void nullsub_165(void)
{
}

UNUSED static void nullsub_166(void)
{
}

UNUSED static void nullsub_167(void)
{
}

UNUSED static void nullsub_168(void)
{
}

UNUSED static void sub_80086C8(Window *windows, s32 windowId, s32 a2, s32 a3, s32 a4, s32 a5)
{
    u32 *r5;
    s32 r2, r0, r1;
    Window *window = &windows[windowId];

    if (a2 < 0) {
        a4 += a2;
        a2 = 0;
    }
    if (a3 < 0) {
        a5 += a3;
        a3 = 0;
    }

    if (a4 + a2 > window->width * 8) {
        a4 = (window->width * 8) - a2;
    }
    if (a3 + a5 > window->unk8 * 8) {
        a5 = (window->unk8 * 8) - a3;
    }

    r2 = window->width * (a3 / 8);
    r0 = 8 * (r2 + (a2 / 8));
    r1 = a3 - ((a3 / 8) * 8);
    r5 = &window->unk18[r0 + r1];
    while (a5 > 0) {
        u32 *loopPtr;
        s32 r4, r6;

        loopPtr = r5;
        r4 = a4;
        r6 = a2;
        if (window->unk3C > r5) {
            window->unk3C = r5;
        }

        while (r4 > 0) {
            s32 r3;
            if (r4 < 8) {
                r3 = r4;
                *loopPtr &= sUnknown_80B8868[(r4 & 7) + 8];
            }
            else if ((r6 & 7) != 0) {
                r3 = 8 - (r6 & 7);
                *loopPtr &= sUnknown_80B8868[r6 & 7];
            }
            else {
                r3 = 8;
                *loopPtr = r6 & 7;
            }

            loopPtr += 8;
            r4 -= r3;
            r6 += r3;
        }
        a5--;
        a3++;
        if (window->unk40 < r5) {
            window->unk40 = r5;
        }
        r5++;
        if (!(a3 & 7)) {
            r5 = &r5[window->unk20];
        }
    }
}

void sub_80087EC(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4)
{
    sub_8008818(gWindows, a0, a1, a2, a3, a4);
}

UNUSED static void nullsub_176(void)
{
}

static void sub_8008818(Window *windows, s32 windowId, s32 a2, s32 a3, s32 a4, s32 a5)
{
    s32 i, j;
    Window *window = &windows[windowId];
    s32 a2Div = a2 / 8;
    s32 a3Div = a3 / 8;

    for (i = 0; i < a5; i += 8) {
        u32 *ptr = &window->unk18[((window->width * a3Div) + a2Div) * 8];
        for (j = 0; j < a4; j += 8) {
            if (window->unk3C > ptr) {
                window->unk3C = ptr;
            }
            *(ptr++) = 0;
            *(ptr++) = 0;
            *(ptr++) = 0;
            *(ptr++) = 0;
            *(ptr++) = 0;
            *(ptr++) = 0;
            *(ptr++) = 0;
            *ptr = 0;
            if (window->unk40 < ptr) {
                window->unk40 = ptr;
            }
            ptr++;
        }
        a3Div++;
    }
}

// Might be copied to 01FF86B8 in NDS
bool8 xxx_call_update_bg_vram(void)
{
    bool8 ret = FALSE;
    if (gUnknown_20274A5 != 0) {
        gUnknown_20274A5 = FALSE;
        sub_80099C0();
    }
    ret = xxx_update_bg_vram(gWindows);
    return ret;
}

static bool8 xxx_update_bg_vram(Window *windows)
{
    s32 i, j;
    u32 r5;
    bool8 ret = FALSE;

    for (i = 0; i < MAX_WINDOWS; i++) {
        Window *window = &windows[i];
        if (window->width == 0)
            continue;
        r5 = window->unk38;
        if (r5 == 0)
            continue;

        if (window->unk45) {
            u32 *r2, *r1;

            CpuCopy(window->unk28, window->unk18, 0xD00);
            // The reason for void casts is because we want to add 0xD00/r5 directly to pointers. Because pointers are u32, without the casts, it would multiply the value by 4.
            r2 = (void *)(window->unk18) + 0xD00;
            r1 = (void *)(window->unk28) + 0xD00;
            for (j = 0; j < window->width; j++) {
                *(r1++) = *(r2++);
                *(r1++) = *(r2++);
                *(r1++) = *(r2++);
                *(r1++) = *(r2++);
                *(r1++) = *(r2++);
                *(r1++) = 0xDDDDDDDD;
                *(r1++) = 0xEEEEEEEE;
                *(r1++) = 0xFFFFFFFF;
                r2 += 3;
            }
            window->unk38 = 0;
        }
        else {
            CpuCopy(window->unk30, window->unk34, r5);
            window->unk34 += (r5 / 4);
            window->unk30 = (void *)(window->unk30) + r5;
            window->unk38 -= r5;
        }

        if (window->unk38 == 0) {
            window->unk44 = 0;
        }
        ret = TRUE;
    }

    return ret;
}

void ResetWindowBgData(void)
{
    s32 i;

    for (i = 0; i < ARRAY_COUNT_INT(gUnknown_3000E94); i++) {
        gUnknown_3000E94[i] = 0xF0F0;
    }
}

void sub_80089AC(const WindowTemplate *r4, DungeonPos *r5_Str)
{
    u8 *r6;

    if (r4->unk0 & 0x40)
        return;

    r6 = (u8*) gUnknown_3000E94;
    if (r4->type == WINDOW_TYPE_WITHOUT_BORDER) {
        s32 r12 = (r4->pos.x + r5_Str->x) * 8;
        s32 r5 = (r4->pos.y + r5_Str->y) * 8;
        s32 r7 = (r4->pos.x + r5_Str->x + r4->width) * 8;
        s32 r2 = (r4->pos.y + r5_Str->y + r4->height) * 8;
        if (r4->height != 0) {
            if (r5 < 0)
                r5 = 0;
            if (r2 < 0)
                r2 = 0;
            if (r5 > 160)
                r5 = 160;
            if (r2 > 160)
                r2 = 160;
            while (r5 < r2) {
                s32 id = r5 * 2;
                if (r6[id] == 240 && r6[id + 1] == 240) {
                    r6[id++] = r7;
                    r6[id] = r12;
                }
                else {
                    if (r6[id] < r7) {
                        r6[id] = r7;
                    }
                    id++;
                    if (r6[id] > r12) {
                        r6[id] = r12;
                    }
                }
                r5++;
            }
        }
    }
    else if (r4->type == WINDOW_TYPE_WITH_HEADER) {
        s32 i;
        s32 r9 = ((r4->pos.x + r5_Str->x) * 8) - 5;
        s32 r5 = ((r4->pos.y + r5_Str->y) * 8) - 4;
        s32 var_24 = ((r4->pos.x + r5_Str->x + r4->width) * 8) + 5;
        s32 r8 = ((r4->pos.y + r5_Str->y + r4->height) * 8) + 5;
        s32 r12 = ((r4->pos.x + r5_Str->x) * 8) + 3;
        const WindowHeader *r2 = r4->header;
        s32 tmp = r2->width - 1;
        s32 r10 = (((tmp + r2->count + 2) * 8) + r12) - 4;
        s32 r4 = r9 + ((r2->currId + 1) * 8);
        s32 r7 = (r4 + ((r2->width + 2) * 8)) - 4;

        if (r5 < 0)
            r5 = 0;
        if (r8 < 0)
            r8 = 0;
        if (r5 > 160)
            r5 = 160;
        if (r8 > 160)
            r8 = 160;

        for (i = 0; i < 4; i++) {
            s32 id = r5 * 2;
            if (r6[id] == 240 && r6[id + 1] == 240) {
                r6[id++] = r7;
                r6[id] = r4;
            }
            else {
                if (r6[id] < r7) {
                    r6[id] = r7;
                }
                id++;
                if (r6[id] > r4) {
                    r6[id] = r4;
                }
            }
            r5++;
        }
        for (i = 0; i < 8; i++) {
            s32 id = r5 * 2;
            if (r6[id] == 240 && r6[id + 1] == 240) {
                r6[id++] = r10;
                r6[id] = r12;
            }
            else {
                if (r6[id] < r10) {
                    r6[id] = r10;
                }
                id++;
                if (r6[id] > r12) {
                    r6[id] = r12;
                }
            }
            r5++;
        }

        while (r5 < r8) {
            s32 id = r5 * 2;
            if (r6[id] == 240 && r6[id + 1] == 240) {
                r6[id++] = var_24;
                r6[id] = r9;
            }
            else {
                if (r6[id] < var_24) {
                    r6[id] = var_24;
                }
                id++;
                if (r6[id] > r9) {
                    r6[id] = r9;
                }
            }
            r5++;
        }
    }
    else {
        s32 r8 = ((r4->pos.x + r5_Str->x) * 8) - 5;
        s32 r3 = ((r4->pos.y + r5_Str->y) * 8) - 5;
        s32 r12 = ((r4->pos.x + r5_Str->x + r4->width) * 8) + 5;
        s32 r5 = ((r4->pos.y + r5_Str->y + r4->height) * 8) + 5;
        if (r4->height != 0) {
            if (r4->type == 0) {
                r3 += 8;
                r5 = ((r4->pos.y + r5_Str->y + r4->height) * 8) - 3;
            }
            if (r3 < 0)
                r3 = 0;
            if (r5 < 0)
                r5 = 0;
            if (r3 > 160)
                r3 = 160;
            if (r5 > 160)
                r5 = 160;
            while (r3 < r5) {
                s32 id = r3 * 2;
                if (r6[id] == 240 && r6[id + 1] == 240) {
                    r6[id++] = r12;
                    r6[id] = r8;
                }
                else {
                    if (r6[id] < r12) {
                        r6[id] = r12;
                    }
                    id++;
                    if (r6[id] > r8) {
                        r6[id] = r8;
                    }
                }
                r3++;
            }
        }
    }
}

void CallPrepareTextbox_8008C54(u32 strId)
{
    PrepareTextbox_8008C6C(gWindows, strId);
}

UNUSED static void nullsub_169(void)
{
}

// Copied to 01ff8000 in NDS
void PrepareTextbox_8008C6C(Window *windows, u32 windowId)
{
    s32 i;
    Window *window = &windows[windowId];

    if (!window->unk45) {
        s32 count = (window->width * window->unk8) * 32;
        for (i = 0; i < count; i += 32) {
            CpuClear(&window->unk18[i / 4u], 32);
        }
    }
    else {
        s32 count = (window->width * (window->unk8 - 1)) * 32;
        u32 *ptr = window->unk18;
        for (i = 0; i < window->width; i++) {
            *(ptr++) = 0xFFFFFFFF;
            *(ptr++) = 0xEEEEEEEE;
            *(ptr++) = 0xDDDDDDDD;
            *(ptr++) = 0;
            *(ptr++) = 0;
            *(ptr++) = 0;
            *(ptr++) = 0;
            *(ptr++) = 0;
        }
        for (i = 0; i < count; i += 32) {
            CpuClear(ptr, 32);
            ptr += 8;
        }
    }

    if (window->type == WINDOW_TYPE_WITH_HEADER) {
        window->unk46 = 1;
        AddUnderScoreHighlightInternal(windows, windowId, 0, 10, window->width * 8, 14);
        AddUnderScoreHighlightInternal(windows, windowId, 0, 11, window->width * 8, 13);
        window->unk46 = 0;
    }

    window->unk30 = window->unk28;
    window->unk34 = window->unk1C;
    window->unk38 = window->unk2C;
    window->unk44 = 1;
}
