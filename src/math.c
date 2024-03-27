#include "global.h"
#include "globaldata.h"
#include "math.h"

extern u24_8 u24_8_div(u24_8 x, u24_8 y); // decomp in progress: https://decomp.me/scratch/pMyGD

#include "data/math.h"

u32 fast_mod_3(s32 x) {
    if (x < 0x100) {
        return gFastMod3Lookup[x];
    }
    return x % 3;
}

s32 sin_abs_4096(s32 x) {
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

s32 cos_4096(s32 x) {
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

bool8 u32_pair_less_than(u32 x_hi, u32 x_lo, u32 y_hi, u32 y_lo) {
    if ((u32)x_hi < (u32)y_hi) {
        return TRUE;
    } else if ((u32)x_hi > (u32)y_hi) {
        return FALSE;
    } else if (x_lo >= y_lo) {
        return FALSE;
    } else {
        return TRUE;
    }
}

s24_8 s24_8_mul(s24_8 x, s24_8 y) {
    s24_8 ret;
    bool8 sgn0 = x < 0;
    bool8 sgn1 = y < 0;

    if (x == 0) {
        return 0;
    }
    if (y == 0) {
        return 0;
    }

    if (sgn0) {
        x = -x;
    }
    if (sgn1) {
        y = -y;
    }
    ret = u24_8_mul(x, y);
    if (sgn0 != sgn1) {
        ret = -ret;
    }
    return ret;
}

s24_8 s24_8_div(s24_8 x, s24_8 y) { // signed division
    s24_8 ret;
    bool8 sgn0 = x < 0;
    bool8 sgn1 = y < 0;

    if (y == 0) {
        return INT32_MAX;
    }
    if (x == 0) {
        return 0;
    }

    if (sgn0) {
        x = -x;
    }
    if (sgn1) {
        y = -y;
    }
    ret = u24_8_div(x, y);
    if (sgn0 != sgn1) {
        ret = -ret;
    }
    return ret;
}

u24_8 u24_8_mul(u24_8 x, u24_8 y) {
    // We need 64 bits for intermediate steps of the multiplication.
    u32 x_h, x_l;
    u32 y_h, y_l;
    u32 out_h, out_l;

    s32 i;
    u32 high_bit_mask;
    u32 round_up;

    if (x == 0 || y == 0) {
        return 0;
    }

    x_h = 0;
    x_l = x;
    y_h = 0;
    y_l = y;
    out_h = 0;
    out_l = 0;
    high_bit_mask = 0x80 << 0x18; // high bit of u32

    for (i = 0; i < 64; ++i) {
        u32 prev_out_l = out_l;
        u32 y_bit = 1;
        y_bit &= y_l;
        if (y_bit) {
            out_l += x_l;
            out_h += x_h;
            if (prev_out_l > out_l) {
                ++out_h;
            }
        }

        y_l >>= 1;
        if (y_h & 1) {
            y_l |= high_bit_mask;
        }
        y_h >>= 1;

        x_h <<= 1;
        if (x_l & high_bit_mask) {
            x_h |= 1;
        }
        do {x_l <<= 1;} while(0); // wtf moment
    }

    round_up = (out_l >> 0x7) & 1;
    out_l = (out_l >> 0x8) | (out_h << 0x18);

    if (round_up) {
        ++out_l;
    }

    return out_l;
}
