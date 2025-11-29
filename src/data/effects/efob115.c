#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_983C228;
const SiroArchive gUnknown_983BED4 = { "SIRO", &gUnknown_983C228 };
const ax_pose gUnknown_983BEE4[] = {
    { -1, { 0, 0 }, 33262, 16636, 23552 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_983BEF8[] = {
    { -1, { 0, 0 }, 33262, 252, 23556 },
    { -1, { 0, 0 }, 33278, 252, 23558 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_983BF16[] = {
    { -1, { 0, 0 }, 33262, 253, 23560 },
    { -1, { 0, 0 }, 33278, 252, 23558 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_983BF34[] = {
    { -1, { 0, 0 }, 16886, 244, 23562 },
    { -1, { 0, 0 }, 33278, 252, 23564 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_983BF54 = 14;
const ax_anim gUnknown_983BF58[] = {
    { 3,   0,   0, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 2,   0,   2, { 0, 0 }, { 0, 0 } },
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 4,   0,   2, { 0, 0 }, { 0, 0 } },
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 3,   0,   1, { 0, 0 }, { 0, 0 } },
    { 9,   0,   0, { 0, 0 }, { 0, 0 } },
    { 3,   0,   1, { 0, 0 }, { 0, 0 } },
    { 10,   0,   3, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_983BFF4[] = INCBIN_U32("data/effects/efob115.4bpp");
const RGB_Struct gUnknown_983C1B4[] = INCBIN_U8("data/effects/efob115.pmdpal");
const ax_pose *const gUnknown_983C1F4[] = {
    gUnknown_983BEE4,
    gUnknown_983BEF8,
    gUnknown_983BF16,
    gUnknown_983BF34,
};
const ax_anim *const gUnknown_983C204[] = {
    gUnknown_983BF58,
    gUnknown_983BF58,
    gUnknown_983BF58,
    gUnknown_983BF58,
    gUnknown_983BF58,
    gUnknown_983BF58,
    gUnknown_983BF58,
    gUnknown_983BF58,
};
const ax_anim *const *const gUnknown_983C224[] = {
    gUnknown_983C204,
};
const EfoFileData gUnknown_983C228 = {
    gUnknown_983C1F4,
    gUnknown_983C224,
    ARRAY_COUNT(gUnknown_983C224), // 1
    NULL,
    NULL,
    gUnknown_983BFF4,
    gUnknown_983C1B4,
    sizeof(gUnknown_983BFF4) / 32, // 14
};
