#ifndef GUARD_MATH_H
#define GUARD_MATH_H

/**
 * This function computes a value modulo 3, using a lookup table for values less
 * than 0x100.
 *
 * @warning This function performs an invalid memory access if x < 0.
 * Hopefully it's never actually used.
 *
 * @param s32 x     The value to get modulo 3. Must be non-negative.
 *
 * @return u32      The value of x modulo 3.
 */
u32 fast_mod_3(s32 x);

/**
 * This function computes the sine of the absolute value of x using a lookup
 * table. The period of the function is 4096, and the range is [-256, 256].
 *
 * @param s32 x     The value to get the sine of.
 *
 * @return s32      `floor(256 * sin(pi * abs(x) / 2048))`
 */
s32 sin_abs_4096(s32 x);

/**
 * This function computes the cosine of the absolute value of x using a lookup
 * table. The period of the function is 4096, and the range is [-256, 256].
 *
 * @note Mathematically, `cos(abs(t)) = cos(t)`, unlike the case in `sin_abs_4096()` above.
 *
 * @param s32 x     The value to get the cosine of.
 *
 * @return s32      `floor(256 * cos(pi * x / 2048))`
 */
s32 cos_4096(s32 x);

#endif // GUARD_MATH_H
