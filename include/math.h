#ifndef GUARD_MATH_H
#define GUARD_MATH_H

#include "gba/types.h"
#include "number_util.h"

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

s24_8 FP24_8_Hypot(s24_8 x, s24_8 y);
void FP48_16_FromS32(s48_16 *dst, s32 src);
u32 FP48_16_ToS32(s48_16 *a);
void FP48_16_FromF248(s48_16 *a, s24_8 b);
bool8 FP48_16_SLessThan(s48_16 *a, s48_16 *b);
void FP48_16_Add(s48_16 *dst, s48_16 *a, s48_16 *b);
void FP48_16_Subtract(s48_16 *dst, s48_16 *a, s48_16 *b);

//static inline bool8 F248Equal(s24_8 x, s24_8 y) {
//    return x.raw == y.raw;
//}

#define F248LessThanInt(x, y) (x.raw < 0x100 * y)
#define F248LessThanFloat(x, y) (x.raw < (int)(y * 0x100))
#define FloatLessThanF248(x, y) ((int)(x * 0x100) < y.raw)
//static inline bool8 F248LessThanOne(s24_8 x) {
//    return x.raw < 0x100;
//}
#define F248LessThan(x, y) (x.raw < y.raw)
#define F248GreaterThan(x, y) (x.raw > y.raw)
#define F248Equal(x, y) (x.raw == y.raw)
#define F248EqualsInt(x, y) (x.raw == 0x100 * y)

//static inline bool8 F248LessThan(s24_8 x, s24_8 y) {
//    return x.raw < y.raw;
//}

#define F248_AddInt(x, y) ((s24_8){x.raw + 0x100 * y})
#define F248_SubInt(x, y) ((s24_8){x.raw - 0x100 * y})

static inline s24_8 F248_Add(s24_8 x, s24_8 y) {
    return (s24_8){x.raw + y.raw};
}

static inline s24_8 F248_Sub(s24_8 x, s24_8 y) {
    return (s24_8){x.raw - y.raw};
}

static inline s24_8 F248_MulInt(s24_8 x, s32 y) {
    return (s24_8){x.raw * y};
}

#endif // GUARD_MATH_H
