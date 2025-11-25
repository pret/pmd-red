#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_9838650;
const SiroArchive gUnknown_9837A34 = { "SIRO", &gUnknown_9838650 };
const ax_pose gUnknown_9837A44[] = {
    { -1, { 0, 0 }, 33252, 33016, 15360 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9837A58[] = {
    { -1, { 0, 0 }, 469, 1281, 3080 },
    { -1, { 0, 0 }, 484, 33004, 15369 },
    { -1, { 0, 0 }, 33236, 252, 15385 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9837A80[] = {
    { -1, { 0, 0 }, 465, 1281, 3099 },
    { -1, { 0, 0 }, 469, 1271, 3080 },
    { -1, { 0, 0 }, 484, 33008, 15388 },
    { -1, { 0, 0 }, 33220, 33016, 15404 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9837AB2[] = {
    { -1, { 0, 0 }, 455, 17661, 3124 },
    { -1, { 0, 0 }, 465, 1271, 3099 },
    { -1, { 0, 0 }, 33188, 33016, 15416 },
    { -1, { 0, 0 }, 484, 37104, 15388 },
    { -1, { 0, 0 }, 33220, 37112, 15404 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9837AEE[] = {
    { -1, { 0, 0 }, 447, 17661, 3136 },
    { -1, { 0, 0 }, 455, 17651, 3124 },
    { -1, { 0, 0 }, 484, 33004, 15369 },
    { -1, { 0, 0 }, 33236, 252, 15385 },
    { -1, { 0, 0 }, 33168, 16636, 15428 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9837B2A[] = {
    { -1, { 0, 0 }, 444, 1281, 3080 },
    { -1, { 0, 0 }, 447, 17651, 3136 },
    { -1, { 0, 0 }, 33252, 33016, 15360 },
    { -1, { 0, 0 }, 33160, 16636, 15432 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9837B5C[] = {
    { -1, { 0, 0 }, 436, 1281, 3099 },
    { -1, { 0, 0 }, 444, 1271, 3080 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9837B7A[] = {
    { -1, { 0, 0 }, 428, 1281, 3148 },
    { -1, { 0, 0 }, 436, 1271, 3099 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9837B98[] = {
    { -1, { 0, 0 }, 436, 1271, 3148 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_9837BAC = 77;
const ax_anim gUnknown_9837BB0[] = {
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 2,   0,   2, { 0, 0 }, { 0, 0 } },
    { 2,   0,   3, { 0, 0 }, { 0, 0 } },
    { 2,   0,   4, { 0, 0 }, { 0, 0 } },
    { 2,   0,   5, { 0, 0 }, { 0, 0 } },
    { 2,   0,   6, { 0, 0 }, { 0, 0 } },
    { 2,   0,   7, { 0, 0 }, { 0, 0 } },
    { 2,   0,   8, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_9837C28[] = INCBIN_U32("data/effects/efob111.4bpp");
const RGB_Struct gUnknown_98385C8[] = INCBIN_U8("data/effects/efob111.pmdpal");
const ax_pose *const gUnknown_9838608[] = {
    gUnknown_9837A44,
    gUnknown_9837A58,
    gUnknown_9837A80,
    gUnknown_9837AB2,
    gUnknown_9837AEE,
    gUnknown_9837B2A,
    gUnknown_9837B5C,
    gUnknown_9837B7A,
    gUnknown_9837B98,
};
const ax_anim *const gUnknown_983862C[] = {
    gUnknown_9837BB0,
    gUnknown_9837BB0,
    gUnknown_9837BB0,
    gUnknown_9837BB0,
    gUnknown_9837BB0,
    gUnknown_9837BB0,
    gUnknown_9837BB0,
    gUnknown_9837BB0,
};
const ax_anim *const *const gUnknown_983864C[] = {
    gUnknown_983862C,
};
const EfoFileData gUnknown_9838650 = {
    gUnknown_9838608,
    gUnknown_983864C,
    ARRAY_COUNT(gUnknown_983864C), // 1
    NULL,
    NULL,
    gUnknown_9837C28,
    gUnknown_98385C8,
    sizeof(gUnknown_9837C28) / 32, // 77
};
