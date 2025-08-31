#include "global.h"
#include "decompress_sir.h"
#include "structs/str_8009A7C.h"
const struct EfoFileData gUnknown_97F2BF0;
const SiroArchive gUnknown_97F20B8 = { "SIRO", &gUnknown_97F2BF0 };
const ax_pose gUnknown_97F20C8[] = {
    { -1, { 0, 0 }, 475, 33000, 3072 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97F20DC[] = {
    { -1, { 0, 0 }, 481, 33004, 3088 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97F20F0[] = {
    { -1, { 0, 0 }, 493, 33006, 3104 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97F2104[] = {
    { -1, { 0, 0 }, 502, 33006, 3120 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97F2118[] = {
    { -1, { 0, 0 }, 502, 33005, 3136 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_97F212C = 80;
const ax_anim gUnknown_97F2130[] = {
    { 1,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 1,   0,   2, { 0, 0 }, { 0, 0 } },
    { 1,   0,   3, { 0, 0 }, { 0, 0 } },
    { 1,   0,   4, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_97F2178[] = INCBIN_U32("data/effects/efob050.4bpp");
const RGB gUnknown_97F2B78[] = INCBIN_U8("data/effects/efob050.pmdpal");
const ax_pose *gUnknown_97F2BB8[] = {
    gUnknown_97F20C8,
    gUnknown_97F20DC,
    gUnknown_97F20F0,
    gUnknown_97F2104,
    gUnknown_97F2118,
};
const ax_anim *gUnknown_97F2BCC[] = {
    gUnknown_97F2130,
    gUnknown_97F2130,
    gUnknown_97F2130,
    gUnknown_97F2130,
    gUnknown_97F2130,
    gUnknown_97F2130,
    gUnknown_97F2130,
    gUnknown_97F2130,
};
const ax_anim *const *gUnknown_97F2BEC[] = {
    gUnknown_97F2BCC,
};
const EfoFileData gUnknown_97F2BF0 = {
    gUnknown_97F2BB8,
    gUnknown_97F2BEC,
    ARRAY_COUNT(gUnknown_97F2BEC), // 1
    NULL,
    NULL,
    gUnknown_97F2178,
    gUnknown_97F2B78,
    ARRAY_COUNT(gUnknown_97F2178) / 16, // 80
};
