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
 * This function computes the cosine of of `x` using a lookup table. The period of
 * the function is `4096`, and the range is `[-256, 256]`.
 *
 * @note Mathematically, `cos(abs(t)) = cos(t)`, unlike the case in `sin_4096()` above.
 *
 * @param[in] x     The value to get the cosine of.
 *
 * @return          `floor(256 * cos(pi * x / 2048))` as a signed 32-bit integer.
 */
s32 cos_4096(s32 x);

/**
 * This function computes the sine of the absolute value of `x` using a lookup
 * table. The period of the function is `4096`, and the range is `[-256, 256]`.
 *
 * @param[in] x     The value to get the sine of.
 *
 * @return          `floor(256 * sin(pi * abs(x) / 2048))` as a signed 32-bit integer.
 */
s32 sin_4096(s32 x);

/**
 * This function multiplies two signed 24.8 fixed-point numbers.
 *
 * @param[in] x   The first factor.
 * @param[in] y   The second factor.
 *
 * @return          The product `x*y` as a signed 24.8 fixed-point number.
 */
s24_8 s24_8_mul(s24_8 x, s24_8 y);

bool8 F48_16_IsZero(s48_16 *a);
void F48_16_SDiv(s48_16 *dst, s48_16 *a, s48_16 *b);
void F48_16_SMul(s48_16 *dst, s48_16 *a, s48_16 *b);

s32 sub_8009FB8(s32 x, s32 y);
void sub_800A020(s48_16 *dst, u32);
u32 sub_800A048(s48_16 *a);
void sub_800A088(s48_16 *a, s32 b);
bool8 sub_800A2F0(s48_16 *a, s48_16 *b);
void sub_800A6D0(s48_16 *dst, s48_16 *a, s48_16 *b);
void sub_800A6F0(s48_16 *dst, s48_16 *a, s48_16 *b);

#endif // GUARD_MATH_H
