#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_97F80EC;
const SiroArchive gUnknown_97F772C = { "SIRO", &gUnknown_97F80EC };
const ax_pose gUnknown_97F773C[] = {
    { -1, { 0, 0 }, 487, 16633, 3072 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97F7750[] = {
    { -1, { 0, 0 }, 488, 16630, 3076 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97F7764[] = {
    { -1, { 0, 0 }, 488, 33007, 3080 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97F7778[] = {
    { -1, { 0, 0 }, 489, 33008, 3096 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97F778C[] = {
    { -1, { 0, 0 }, 489, 33010, 3112 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97F77A0[] = {
    { -1, { 0, 0 }, 16888, 33012, 3128 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97F77B4[] = {
    { -1, { 0, 0 }, 33272, 265, 3136 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_97F77C8 = 66;
const ax_anim gUnknown_97F77CC[] = {
    { 3,   0,   0, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 1,   0,   2, { 0, 0 }, { 0, 0 } },
    { 1,   0,   3, { 0, 0 }, { 0, 0 } },
    { 1,   0,   4, { 0, 0 }, { 0, 0 } },
    { 2,   0,   5, { 0, 0 }, { 0, 0 } },
    { 3,   0,   6, { 1, -2 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_97F782C[] = INCBIN_U32("data/effects/efob054.4bpp");
const RGB gUnknown_97F806C[] = INCBIN_U8("data/effects/efob054.pmdpal");
const ax_pose *gUnknown_97F80AC[] = {
    gUnknown_97F773C,
    gUnknown_97F7750,
    gUnknown_97F7764,
    gUnknown_97F7778,
    gUnknown_97F778C,
    gUnknown_97F77A0,
    gUnknown_97F77B4,
};
const ax_anim *gUnknown_97F80C8[] = {
    gUnknown_97F77CC,
    gUnknown_97F77CC,
    gUnknown_97F77CC,
    gUnknown_97F77CC,
    gUnknown_97F77CC,
    gUnknown_97F77CC,
    gUnknown_97F77CC,
    gUnknown_97F77CC,
};
const ax_anim *const *gUnknown_97F80E8[] = {
    gUnknown_97F80C8,
};
const EfoFileData gUnknown_97F80EC = {
    gUnknown_97F80AC,
    gUnknown_97F80E8,
    ARRAY_COUNT(gUnknown_97F80E8), // 1
    NULL,
    NULL,
    gUnknown_97F782C,
    gUnknown_97F806C,
    sizeof(gUnknown_97F782C) / 32, // 66
};
