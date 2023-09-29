#ifndef GUARD_MATH_H
#define GUARD_MATH_H

#include "global.h"

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
u32 fast_mod_3(s32 x);

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
bool8 u32_pair_less_than(u32 x_hi, u32 x_lo, u32 y_hi, u32 y_lo);

/**
 * This function multiplies two signed 24.8 fixed-point numbers.
 *
 * @param[in] x   The first factor.
 * @param[in] y   The second factor.
 *
 * @return          The product `x*y` as a signed 24.8 fixed-point number.
 */
s24_8 s24_8_mul(s24_8 x, s24_8 y);

/**
 * This function divides two signed 24.8 fixed-point numbers.
 *
 * @param[in] x   The dividend.
 * @param[in] y   The divisor.
 *
 * @returns       The quotient `x/y` as a signed 24.8 fixed-point number.
 */
s32 s24_8_div(s32 r0, s32 r1);

/**
 * This function multiplies two unsigned 24.8 fixed-point numbers.
 *
 * @param[in] x   The first factor.
 * @param[in] y   The second factor.
 *
 * @return        The product `x*y` as an unsigned 24.8 fixed-point number.
 */
u24_8 u24_8_mul(u24_8 x, u24_8 y);

#endif // GUARD_MATH_H
