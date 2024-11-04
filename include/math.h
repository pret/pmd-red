#ifndef GUARD_MATH_H
#define GUARD_MATH_H

#include "gba/types.h"
#include "number_util.h"

/**
 * This type represents a signed 24.8 fixed-point number, where the 24 most
 * significant bits are the integer part and the 8 least significant bits are
 * the fractional part.
 */
typedef s32 s24_8;

/**
 * This type represents an unsigned 24.8 fixed-point number, where the 24 most
 * significant bits are the integer part and the 8 least significant bits are
 * the fractional part.
 */
typedef u32 u24_8;

/**
 * This function computes the sine of the absolute value of `x` using a lookup
 * table. The period of the function is `4096`, and the range is `[-256, 256]`.
 *
 * @param[in] x     The value to get the sine of.
 *
 * @return          `floor(256 * sin(pi * abs(x) / 2048))` as a signed 32-bit integer.
 */
s32 sin_abs_4096(s32 x);

/**
 * This function computes the cosine of of `x` using a lookup table. The period of
 * the function is `4096`, and the range is `[-256, 256]`.
 *
 * @note Mathematically, `cos(abs(t)) = cos(t)`, unlike the case in `sin_abs_4096()` above.
 *
 * @param[in] x     The value to get the cosine of.
 *
 * @return          `floor(256 * cos(pi * x / 2048))` as a signed 32-bit integer.
 */
s32 cos_4096(s32 x);

/**
 * This function multiplies two signed 24.8 fixed-point numbers.
 *
 * @param[in] x   The first factor.
 * @param[in] y   The second factor.
 *
 * @return          The product `x*y` as a signed 24.8 fixed-point number.
 */
s24_8 s24_8_mul(s24_8 x, s24_8 y);

s32 sub_8009FB8(s32 x, s32 y);
void sub_800A020(unkStruct_80943A8 *, u32);
bool8 sub_800A2A0(unkStruct_80943A8 *a);
void sub_800A34C(unkStruct_80943A8 *dst, unkStruct_80943A8 *a, unkStruct_80943A8 *b);

#endif // GUARD_MATH_H
