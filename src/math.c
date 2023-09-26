#include "global.h"
#include "math.h"

extern u8 gFastMod3Lookup[];
extern s16 gFastSinLookup[];

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

