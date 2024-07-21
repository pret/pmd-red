#include "global.h"
#include "globaldata.h"
#include "math.h"

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

u24_8 u24_8_div(u24_8 x, u24_8 y)
{
  bool8 bVar1;
  u32 r9;
  u32 r2;
  u32 r4;
  u32 r5;
  u32 r6;
  u32 r7;
  u32 r8;
  int counter;
  s32 sl;
  s32 flag;
  s32 save;
  
  if (y == 0) {
    return 0x7fffffff;
  }
  else if (x == 0) {
    return 0;
  }
  else {
    r7 = x >> 0x18;
    r6 = x << 8;
    sl = y;
    r9 = 0;
    r5 = 0;
    r4 = 0;
    r2 = 0;
    r8 = 1;

      
    for(counter = 0x3f; counter >= 0; counter--)
    {
      r5 <<= 1;
      if ((r4 & 0x80000000) != 0) {
        r5 |= r8;
      }
      flag = -2;
      r4 <<= 1;
      if ((r7 & 0x80000000) != 0) {
        r4 |= r8;
      }
      r7 <<= 1;
      if ((r6 & 0x80000000) != 0) {
        r7 |= r8;
      }
      r6 <<= 1;
      r6 &= flag;
      if (u32_pair_less_than(r5,r4,0,sl) == 0) {
        save = r4;
        bVar1 = 1;
        r4 = r4 - sl;
        r5 = r5 - r2;  // WHY????
        if (save < r4) {
          r5--;
        }
      }
      else {
        bVar1 = 0;
      }
      r9 <<= 1;
      if (bVar1) {
        r9 |= r8;
      }
    }
  }
  return r9;
}

s32 sub_8009F68(s32 x, s32 y)
{
    s32 uVar1;
    s32 sVar1;

    uVar1 = y;
    if (y < 0) {
        uVar1 = -y;
    }
    sVar1 = 0x100;
    for (; uVar1 != 0; uVar1 >>= 1) {
        if ((uVar1 & 1) != 0) {
            sVar1 = s24_8_mul(sVar1, x);
        }
        x = s24_8_mul(x, x);
    }
    if (y >= 0) {
        return sVar1;
    }
    else
        return s24_8_div(0x100,sVar1);
}

s32 sub_8009FB8(s32 x, s32 y)
{
    s32 r4;
    s32 counter;

    s32 r5;
    s32 r6;

    r5 = x;
    r6 = y;

    if (r5 < 0) {
        r5 = -r5;
    }
    if (r6 < 0) {
        r6 = -r6;
    }
    if (r5 < r6) {
        r4 = r5;
        r5 = r6;
        r6 = r4;
    }
    if (r6 != 0) {
        for(counter = 2; counter >= 0; counter--)
        {
            r4 = s24_8_div(r6,r5);
            r4 = s24_8_mul(r4,r4);
            r4 = s24_8_div(r4,r4 + 0x400);
            r5 = r5 + s24_8_mul(r5,r4) * 2;
            r6 = s24_8_mul(r6,r4);
        }
    }
    return r5;
}

void sub_800A020(s32 *param_1, u32 param_2)
{
#ifndef NONMATCHING
  register u32 temp asm("r4");
#else
  u32 temp;
#endif
    
  temp = 0xffff0000;
  param_1[0] = param_2 >> 0x10;
  param_1[1] = param_2 << 0x10;
  if ((param_2 & 0x8000) != 0) {
    param_1[0] |= temp;
  }
}

u32 sub_800A048(u32 *param_1)
{
  u32 uVar1;
  
  uVar1 = ((u16)param_1[0] << 0x10) | (param_1[1] >> 0x10);
  if ((param_1[1] & 0x8000) != 0) {
    uVar1++;
  }
  return uVar1;
}

UNUSED u32 sub_800A068(u32 *param_1)
{
  u32 uVar1;
  
  uVar1 = ((u8)param_1[0] << 0x18) | param_1[1] >> 8;
  if ((param_1[1] & 0x8000) != 0) {
    uVar1++;
  }
  return uVar1;
}
