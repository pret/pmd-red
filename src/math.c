#include "global.h"
#include "globaldata.h"
#include "math.h"

#include "data/math.h"

static void F48_16_UDiv(s48_16 *, s48_16 *, s48_16 *);
static void F48_16_UMul(s48_16 *, s48_16 *, s48_16 *);
static u24_8 u24_8_div(u24_8, u24_8);
static u24_8 u24_8_mul(u24_8, u24_8);

/**
 * This function computes a value modulo 3, using a lookup table for values less
 * than 0x100.
 *
 * @warning This function performs an invalid memory access if x < 0.
 * Hopefully it's never actually used.
 *
 * @param[in] x     The value to get modulo 3. Must be non-negative.
 *
 * @return          The value of x modulo 3.
 */
UNUSED u32 fast_mod_3(s32 x)
{
    if (x < 0x100)
        return gFastMod3Lookup[x];

    return x % 3;
}

s32 sin_4096(s32 x)
{
    switch (x & 0xc00) {
        case 0x000:
            return gFastSinLookup[x & 0x3ff];
        case 0x400:
            return gFastSinLookup[0x3ff - (x & 0x3ff)];
        case 0x800:
            return -gFastSinLookup[x & 0x3ff];
        case 0xc00:
            return -gFastSinLookup[0x3ff - (x & 0x3ff)];
    }

    return 0;
}

s32 cos_4096(s32 x)
{
    switch (x & 0xc00) {
        case 0x000:
            return gFastSinLookup[0x3ff - (x & 0x3ff)];
        case 0x400:
            return -gFastSinLookup[x & 0x3ff];
        case 0x800:
            return -gFastSinLookup[0x3ff - (x & 0x3ff)];
        case 0xc00:
            return gFastSinLookup[x & 0x3ff];
    }

    return 0;
}

/**
 * This function lexicographically compares two pairs of u32s.
 *
 * @note The call signature of this might change if it makes sense to pack the
 *       inputs into a struct representing, say, a 64-bit unsigned integer. Doing
 *       so does affect the generated assembly; the current approach is the simplest
 *       match.
 *
 * @param[in] x_hi  The high 32 bits of the first pair.
 * @param[in] x_lo  The low 32 bits of the first pair.
 * @param[in] y_hi  The high 32 bits of the second pair.
 * @param[in] y_lo  The low 32 bits of the second pair.
 *
 * @return          `TRUE` if `x < y`, `FALSE` otherwise.
 */
static bool8 u32_pair_less_than(u32 x_hi, u32 x_lo, u32 y_hi, u32 y_lo)
{
    if (x_hi < y_hi)
        return TRUE;
    if (x_hi > y_hi)
        return FALSE;
    if (x_lo >= y_lo)
        return FALSE;
    return TRUE;
}

s24_8 s24_8_mul(s24_8 x, s24_8 y)
{
    s24_8 ret;
    bool8 sgn0;
    bool8 sgn1;

    sgn0 = x < 0;
    sgn1 = y < 0;

    if (x == 0)
        return 0;

    if (y == 0)
        return 0;

    if (sgn0)
        x = -x;

    if (sgn1)
        y = -y;

    ret = u24_8_mul(x, y);

    if (sgn0 != sgn1)
        ret = -ret;

    return ret;
}

/**
 * This function divides two signed 24.8 fixed-point numbers.
 *
 * @param[in] x   The dividend.
 * @param[in] y   The divisor.
 *
 * @returns       The quotient `x/y` as a signed 24.8 fixed-point number.
 */
static s24_8 s24_8_div(s24_8 x, s24_8 y)
{
    s24_8 ret;
    bool8 sgn0;
    bool8 sgn1;

    sgn0 = x < 0;
    sgn1 = y < 0;

    if (y == 0)
        return INT32_MAX;

    if (x == 0)
        return 0;

    if (sgn0)
        x = -x;

    if (sgn1)
        y = -y;

    ret = u24_8_div(x, y);

    if (sgn0 != sgn1)
        ret = -ret;

    return ret;
}

/**
 * This function multiplies two unsigned 24.8 fixed-point numbers.
 *
 * @param[in] x   The first factor.
 * @param[in] y   The second factor.
 *
 * @return        The product `x*y` as an unsigned 24.8 fixed-point number.
 */
static u24_8 u24_8_mul(u24_8 x, u24_8 y)
{
    // We need 64 bits for intermediate steps of the multiplication.
    u32 x_h, x_l;
    u32 y_h, y_l;
    u32 out_h, out_l;

    s32 i;
    u32 high_bit_mask;
    u32 round_up;

    if (x == 0 || y == 0)
        return 0;

    x_h = 0;
    x_l = x;
    y_h = 0;
    y_l = y;
    out_h = 0;
    out_l = 0;
    high_bit_mask = 0x80 << 24; // high bit of u32

    for (i = 0; i < 64; ++i) {
        u32 prev_out_l = out_l;
        u32 y_bit = 1;
        y_bit &= y_l;

        if (y_bit) {
            out_l += x_l;
            out_h += x_h;

            if (prev_out_l > out_l)
                ++out_h;
        }

        y_l >>= 1;
        if (y_h & 1)
            y_l |= high_bit_mask;

        y_h >>= 1;

        x_h <<= 1;
        if (x_l & high_bit_mask)
            x_h |= 1;

        do {x_l <<= 1;} while(0); // Fakematch?
    }

    round_up = (out_l >> 7) & 1;
    out_l = (out_l >> 8) | (out_h << 24);

    if (round_up) {
        ++out_l;
    }

    return out_l;
}

/**
 * This function divides two unsigned 24.8 fixed-point numbers.
 *
 * @param[in] x   The first factor.
 * @param[in] y   The second factor.
 *
 * @return        The quotient `x/y` as an unsigned 24.8 fixed-point number.
 */
static u24_8 u24_8_div(u24_8 x, u24_8 y)
{
    bool8 bVar1;
    u32 r9;
    u32 r2;
    u32 r4;
    u32 r5;
    u32 r6;
    u32 r7;
    u32 r8;
    s32 i;
    s32 sl;
    s32 temp;

    if (y == 0)
        return INT32_MAX;

    if (x == 0)
        return 0;

    r7 = x >> 24;
    r6 = x << 8;
    sl = y;
    r9 = 0;
    r5 = 0;
    r4 = 0;
    r2 = 0;
    r8 = 1;

    for (i = 0; i < 64; i++) {
        r5 <<= 1;
        if (r4 & 0x80000000)
            r5 |= r8;

        r4 = (r4 << 1) & ~0x1;
        if (r7 & 0x80000000)
            r4 |= r8;

        r7 <<= 1;
        if (r6 & 0x80000000)
            r7 |= r8;

        r6 = (r6 << 1) & ~0x1;

        if (!u32_pair_less_than(r5, r4, 0, sl)) {
            temp = r4;
            bVar1 = TRUE;
            r4 -= sl;
            r5 -= r2;
            if (temp < r4)
                r5--;
        }
        else
            bVar1 = FALSE;

        r9 <<= 1;
        if (bVar1)
            r9 |= r8;
    }

    return r9;
}

UNUSED s32 sub_8009F68(s32 x, s32 y)
{
    s32 uVar1;
    s32 sVar1;

    uVar1 = y;
    if (uVar1 < 0)
        uVar1 = -uVar1;

    sVar1 = 0x100;

    for (; uVar1 != 0; uVar1 >>= 1) {
        if (uVar1 & 1)
            sVar1 = s24_8_mul(sVar1, x);

        x = s24_8_mul(x, x);
    }

    if (y >= 0)
        return sVar1;

    return s24_8_div(0x100, sVar1);
}

s32 sub_8009FB8(s32 x, s32 y)
{
    s32 r4;
    s32 i;
    s32 r5;
    s32 r6;

    r5 = x;
    r6 = y;

    if (r5 < 0)
        r5 = -r5;

    if (r6 < 0)
        r6 = -r6;

    if (r5 < r6) {
        r4 = r5;
        r5 = r6;
        r6 = r4;
    }

    if (r6 != 0) {
        for (i = 2; i >= 0; i--) {
            r4 = s24_8_div(r6, r5);
            r4 = s24_8_mul(r4, r4);
            r4 = s24_8_div(r4, r4 + 0x400);
            r5 += s24_8_mul(r5, r4) * 2;
            r6 = s24_8_mul(r6, r4);
        }
    }

    return r5;
}

void sub_800A020(s48_16 *param_1, u32 param_2)
{
#ifndef NONMATCHING
    register u32 temp asm("r4");
#else
    u32 temp;
#endif

    temp = 0xFFFF0000;
    param_1->hi = param_2 >> 16;
    param_1->lo = param_2 << 16;

    if (param_2 & 0x8000)
        param_1->hi |= temp;

}

u32 sub_800A048(s48_16 *a)
{
    u32 uVar1;

    uVar1 = ((u16) a->hi << 16) | (a->lo >> 16);
    if (a->lo & 0x8000)
        uVar1++;

    return uVar1;
}

UNUSED u32 sub_800A068(u32 *a)
{
    u32 uVar1;

    uVar1 = ((u8)a[0] << 24) | a[1] >> 8;
    if (a[1] & 0x8000)
        uVar1++;

    return uVar1;
}

void sub_800A088(s48_16 *a, s32 b)
{
    a->lo = b << 8;
    a->hi = b >> 24;

    if (a->hi & 0x80)
        a->hi |= ~0x7F;
    else
        a->hi &= 0x7f;
}

s32 sub_800A0B0(s48_16 *a)
{
    s32 r2;
    s32 r3;
    s32 idx;
    s32 divi;

    r2 = a->lo;
    r3 = a->hi;
    if (r2 == 0 && r3 == 0)
        return 0;

    if (r2 > 0) {
        if (r3 > 0) {
            if (r2 < r3) {
                divi = r3 / 256;
                if (divi == 0)
                    return 0x200;

                idx = r2 / divi;
                if (idx > 0xFF)
                    idx = 0xFF;
            
                return gFastUnknownFn1Lookup[idx] << 4;
            }
            else { // r2 >= r3
                divi = r2 / 256;
                if (divi == 0)
                    return 0x200;

                idx = r3 / divi;
                if (idx > 0xFF)
                    idx = 0xFF;
            
                return (0x40 - gFastUnknownFn1Lookup[idx]) << 4;
            }
        }
        else { // r3 <= 0
            r3 = -r3;
            if (r2 < r3) {
                divi = r3 / 256;
                if (divi == 0)
                    return 0x600;

                idx = r2 / divi;
                if (idx > 0xFF)
                    idx = 0xFF;
            
                return (0x80 - gFastUnknownFn1Lookup[idx]) << 4;
            }
            else { // r2 >= r3
                divi = r2 / 256;
                if (divi == 0)
                    return 0x600;

                idx = r3 / divi;
                if (idx > 0xFF)
                    idx = 0xFF;
            
                return (gFastUnknownFn1Lookup[idx] + 0x40) << 4;
            }
        }
    }
    else { // r2 <= 0
        r2 = -r2;
        if (r3 > 0) {
            if (r2 < r3) {
                divi = r3 / 256;
                if (divi == 0)
                    return 0xE00;

                idx = r2 / divi;
                if (idx > 0xFF)
                    idx = 0xFF;
            
                return (0x100 - gFastUnknownFn1Lookup[idx]) << 4;
            }
            else { // r2 >= r3
                divi = r2 / 256;
                if (divi == 0)
                    return 0xE00;

                idx = r3 / divi;
                if (idx > 0xFF)
                    idx = 0xFF;
            
                return (gFastUnknownFn1Lookup[idx] + 0xC0) << 4;
            }
        }
        else { // r3 <= 0
            r3 = -r3;
            if (r2 < r3) {
                divi = r3 / 256;
                if (divi == 0)
                    return 0xA00;

                idx = r2 / divi;
                if (idx > 0xFF)
                    idx = 0xFF;
            
                return (gFastUnknownFn1Lookup[idx] + 0x80) << 4;
            }
            else { // r2 >= r3
                divi = r2 / 256;
                if (divi == 0)
                    return 0xA00;

                idx = r3 / divi;
                if (idx > 0xFF)
                    idx = 0xFF;
            
                return (0xC0 - gFastUnknownFn1Lookup[idx]) << 4;
            }
        }
    }
}

static void F48_16_Negate(s48_16 *a)
{
    a->hi = ~a->hi;
    a->lo = ~a->lo + 1;

    if (a->lo == 0)
        a->hi++;
}

static void F48_16_Abs(s48_16 *a)
{
    if (a->hi < 0) {
        a->hi = ~a->hi;
        a->lo = ~a->lo + 1;

        if (a->lo == 0)
            a->hi++;
    }
}

bool8 F48_16_IsZero(s48_16 *a)
{
    if (a->hi == 0 && a->lo == 0)
        return TRUE;
    return FALSE;
}

UNUSED bool8 F48_16_IsEqual(s48_16 *a, s48_16 *b)
{
    if (a->hi == b->hi && a->lo == b->lo)
        return TRUE;
    return FALSE;
}

static bool8 F48_16_IsNegative(s48_16 *a)
{
    if (a->hi < 0)
        return TRUE;
    return FALSE;
}

bool8 sub_800A2F0(s48_16 *a, s48_16 *b)
{
    s32 r1;
    u32 a0;
    s32 b0;

    a0 = a->hi;
    r1 = a0 >> 31;

    b0 = b->hi;
    if (b0 < 0)
        r1 |= 0x2;

    switch (r1) {
        case 0:
        default:
            return u32_pair_less_than(a0, a->lo, b0, b->lo);
        case 1:
            return TRUE;
        case 2:
            return FALSE;
        case 3:
            return !u32_pair_less_than(a0, a->lo, b0, b->lo);
    }
}

void F48_16_SMul(s48_16 *dst, s48_16 *a, s48_16 *b)
{
    bool8 aIsNegative;
    bool8 bIsNegative;
    s48_16 aa;
    s48_16 bb;
    s48_16 res;

    aa.hi = a->hi;
    aa.lo = a->lo;
    bb.hi = b->hi;
    bb.lo = b->lo;
    aIsNegative = F48_16_IsNegative(&aa);
    bIsNegative = F48_16_IsNegative(&bb);

    if (F48_16_IsZero(&aa)) {
        dst->hi = 0;
        dst->lo = 0;
    }
    else if (F48_16_IsZero(&bb)) {
        dst->hi = 0;
        dst->lo = 0;
    }
    else {
        if (aIsNegative)
            F48_16_Negate(&aa);

        if (bIsNegative)
            F48_16_Negate(&bb);

        F48_16_UMul(&res, &aa, &bb);
        if (aIsNegative != bIsNegative)
            F48_16_Negate(&res);

        dst->hi = res.hi;
        dst->lo = res.lo;
    }
}

void F48_16_SDiv(s48_16 *dst, s48_16 *a, s48_16 *b)
{
    bool8 aIsNegative;
    bool8 bIsNegative;
    s48_16 aa;
    s48_16 bb;
    s48_16 res;

    aa.hi = a->hi;
    aa.lo = a->lo;
    bb.hi = b->hi;
    bb.lo = b->lo;
    aIsNegative = F48_16_IsNegative(&aa);
    bIsNegative = F48_16_IsNegative(&bb);

    if (F48_16_IsZero(&bb)) {
        dst->hi = INT32_MAX;
        dst->lo = UINT32_MAX;
    }
    else if (F48_16_IsZero(&aa)) {
        dst->hi = 0;
        dst->lo = 0;
    }
    else {
        if (aIsNegative)
            F48_16_Negate(&aa);

        if (bIsNegative)
            F48_16_Negate(&bb);

        F48_16_UDiv(&res, &aa, &bb);
        if (aIsNegative != bIsNegative)
            F48_16_Negate(&res);

        dst->hi = res.hi;
        dst->lo = res.lo;
    }
}

static void F48_16_Square(s48_16 *a)
{
    s48_16 aa;
    s48_16 res;

    aa.hi = a->hi;
    aa.lo = a->lo;

    if (F48_16_IsZero(&aa)) {
        a->hi = 0;
        a->lo = 0;
    }
    else {
        F48_16_Abs(&aa);
        F48_16_UMul(&res, &aa, &aa);
        a->hi = res.hi;
        a->lo = res.lo;
    }
}

// Regswap https://decomp.me/scratch/HNmlz
static void F48_16_UMul(s48_16 *dst, s48_16 *a, s48_16 *b)
{
    u32 sl;
    u32 r1;
    u32 r2;
    u32 r3;
    u32 r4;
    #ifdef NONMATCHING
    u32 r5;
    #else
    register u32 r5 asm("r5");
    #endif
    u32 r6;
    s32 i;
    
    if (F48_16_IsZero(a)) {
        dst->hi = 0;
        dst->lo = 0;
    }
    else if (F48_16_IsZero(b)) {
        dst->hi = 0;
        dst->lo = 0;
    }
    else {
        r1 = a->hi;
        r4 = a->lo;
        sl = b->hi;
        r2 = b->lo;
        r6 = 0;
        r5 = 0;

        for (i = 0; i < 64; i++) {
            r3 = r5;

            if (r2 & 1) {
                r5 += r4;
                r6 += r1;

                if (r3 > r5)
                    r6++;
            }

            r2 >>= 1;

            if (sl & 1)
                r2 |= 0x80000000;

            sl >>= 1;
            r1 <<= 1;

            if (r4 & 0x80000000)
                r1 |= 1;

            r4 <<= 1;
        }

        r1 = (r5 >> 15) & 1;
        r5 >>= 16;
        r5 |= (r6 << 16);
        r6 >>= 16;

        if (r1 != 0)
            r5++;

        dst->hi = r6;
        dst->lo = r5;
    }
}

// Similar to u24_8_div
static void F48_16_UDiv(s48_16 *dst, s48_16 *a, s48_16 *b)
{
    s32 temp;
    bool8 r1;
    u32 r4;
    u32 r5;
    u32 r6;
    u32 r7;
    u32 r9;
    s32 sp4;
    u32 sp8;
    u32 spC;
    s32 i;

    if (F48_16_IsZero(b)) {
        dst->hi = INT32_MAX;
        dst->lo = UINT32_MAX;
    }
    else if (F48_16_IsZero(a)) {
        dst->hi = 0;
        dst->lo = 0;
    }
    else {
        r7 = (a->hi << 16) | (a->lo >> 16);
        r6 = (a->lo << 16) | 0x8000;
        sp4 = b->hi;
        sp8 = b->lo;
        spC = 0; // Effectively unused
        r9 = 0;
        r5 = 0;
        r4 = 0;

        for (i = 0; i < 64; i++) {
            r5 <<= 1;
            if (r4 & 0x80000000)
                r5 |= 0x1;

            r4 = (r4 << 1) & ~0x1;
            if (r7 & 0x80000000)
                r4 |= 0x1;

            r7 <<= 1;
            if (r6 & 0x80000000)
                r7 |= 0x1;

            r6 = (r6 << 1) & ~0x1;

            if (!u32_pair_less_than(r5, r4, sp4, sp8)) {
                temp = r4;
                r1 = TRUE;
                r4 -= sp8;
                r5 -= sp4;

                if (temp < r4)
                    r5--;
            }
            else
                r1 = FALSE;

            spC <<= 1;
            if (r9 & 0x80000000)
                spC |= 0x1;

            r9 = (r9 << 1) & ~0x1;
            if (r1)
                r9 |= 0x1;
        }

        dst->hi = spC;
        dst->lo = r9;
    }
}

void sub_800A6D0(s48_16 *dst, s48_16 *a, s48_16 *b)
{
    s32 s0;
    u32 s4;

    s0 = a->hi + b->hi;
    s4 = a->lo + b->lo;
    if (s4 < a->lo)
        s0++;

    dst->hi = s0;
    dst->lo = s4;
}

void sub_800A6F0(s48_16 *dst, s48_16 *a, s48_16 *b)
{
    s32 s0;
    u32 s4;

    s0 = a->hi - b->hi;
    s4 = a->lo - b->lo;
    if (s4 > a->lo)
        s0--;

    dst->hi = s0;
    dst->lo = s4;
}

// Similar to sub_8009F68
UNUSED void F48_16_Pow(s48_16 *dst, s48_16 *a, s32 b)
{
    s48_16 aa;
    s32 bb;
    s48_16 res;

    aa.hi = a->hi;
    aa.lo = a->lo;
    bb = b;
    if (bb < 0)
        bb = -bb;

    res.hi = 0;
    res.lo = 0x10000;

    for (; bb != 0; bb >>= 1) {
        if (bb & 1)
            F48_16_SMul(&res, &res, &aa);

        F48_16_Square(&aa);
    }

    if (b < 0) {
        s48_16 idk;
        idk.hi = 0;
        idk.lo = 0x10000;
        F48_16_SDiv(&res, &idk, &res);
    }

    dst->hi = res.hi;
    dst->lo = res.lo;
}

// Similar to sub_8009FB8
UNUSED void sub_800A78C(s48_16 *dst, s48_16 *a, s48_16 *b)
{
    u32 temp;
    s32 i;
    s48_16 sp0;
    s48_16 sp8;
    s48_16 sp10;
    s48_16 sp18;

    sp0 = *a;
    sp8 = *b;
    F48_16_Abs(&sp0);
    F48_16_Abs(&sp8);

    if (sub_800A2F0(&sp0, &sp8)) {
        sp10 = sp0;
        sp0 = sp8;
        sp8 = sp10;
    }

    if (!F48_16_IsZero(&sp8)) {
        i = 0;

        do {
            F48_16_SDiv(&sp10, &sp8, &sp0);
            F48_16_Square(&sp10);
            sp18.hi = sp10.hi;
            sp18.lo = sp10.lo + 0x40000;

            if (sp18.lo < sp10.lo)
                sp18.hi++;

            F48_16_SDiv(&sp10, &sp10, &sp18);
            F48_16_SMul(&sp18, &sp0, &sp10);
            sp18.hi <<= 1;
            if ((s32) sp18.lo < 0)
                sp18.hi |= 0x1;

            sp18.lo <<= 1;
            temp = sp0.lo;
            sp0.hi += sp18.hi;
            sp0.lo = temp + sp18.lo;
            if (temp > sp0.lo)
                sp0.hi++;

            if (i == 2)
                break;

            F48_16_SMul(&sp8, &sp8, &sp10);
            i++;
        } while (TRUE);
    }

    *dst = sp0;
}
