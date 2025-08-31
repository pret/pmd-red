#include "global.h"
#include "decompress_sir.h"
#include "structs/str_8009A7C.h"
const struct EfoFileData gUnknown_97EE14C;
const SiroArchive gUnknown_97EDE74 = { "SIRO", &gUnknown_97EE14C };
const ax_pose gUnknown_97EDE84[] = {
    { -1, { 0, 0 }, 502, 252, 3072 },
    { -1, { 0, 0 }, 514, 252, 3072 },
    { -1, { 0, 0 }, 504, 248, 3072 },
    { -1, { 0, 0 }, 512, 248, 3072 },
    { -1, { 0, 0 }, 508, 246, 3072 },
    { -1, { 0, 0 }, 512, 256, 3072 },
    { -1, { 0, 0 }, 504, 256, 3072 },
    { -1, { 0, 0 }, 508, 258, 3072 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97EDEDE[] = {
    { -1, { 0, 0 }, 497, 252, 3072 },
    { -1, { 0, 0 }, 519, 252, 3072 },
    { -1, { 0, 0 }, 501, 245, 3072 },
    { -1, { 0, 0 }, 515, 245, 3072 },
    { -1, { 0, 0 }, 508, 242, 3072 },
    { -1, { 0, 0 }, 515, 259, 3072 },
    { -1, { 0, 0 }, 501, 259, 3072 },
    { -1, { 0, 0 }, 508, 262, 3072 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97EDF38[] = {
    { -1, { 0, 0 }, 490, 252, 3072 },
    { -1, { 0, 0 }, 526, 252, 3072 },
    { -1, { 0, 0 }, 496, 239, 3072 },
    { -1, { 0, 0 }, 520, 239, 3072 },
    { -1, { 0, 0 }, 508, 236, 3072 },
    { -1, { 0, 0 }, 520, 265, 3072 },
    { -1, { 0, 0 }, 496, 265, 3072 },
    { -1, { 0, 0 }, 508, 268, 3072 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97EDF92[] = {
    { -1, { 0, 0 }, 481, 252, 3072 },
    { -1, { 0, 0 }, 535, 252, 3072 },
    { -1, { 0, 0 }, 490, 232, 3072 },
    { -1, { 0, 0 }, 526, 232, 3072 },
    { -1, { 0, 0 }, 508, 226, 3072 },
    { -1, { 0, 0 }, 526, 272, 3072 },
    { -1, { 0, 0 }, 490, 272, 3072 },
    { -1, { 0, 0 }, 508, 278, 3072 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97EDFEC[] = {
    { -1, { 0, 0 }, 470, 252, 3073 },
    { -1, { 0, 0 }, 546, 252, 3073 },
    { -1, { 0, 0 }, 483, 222, 3073 },
    { -1, { 0, 0 }, 533, 222, 3073 },
    { -1, { 0, 0 }, 508, 213, 3073 },
    { -1, { 0, 0 }, 533, 282, 3073 },
    { -1, { 0, 0 }, 483, 282, 3073 },
    { -1, { 0, 0 }, 508, 290, 3073 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_97EE048 = 2;
const ax_anim gUnknown_97EE04C[] = {
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 2,   0,   2, { 0, 0 }, { 0, 0 } },
    { 1,   0,   3, { 0, 0 }, { 0, 0 } },
    { 1,   0,   4, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_97EE094[] = INCBIN_U32("data/effects/efob047.4bpp");
const RGB gUnknown_97EE0D4[] = INCBIN_U8("data/effects/efob047.pmdpal");
const ax_pose *gUnknown_97EE114[] = {
    gUnknown_97EDE84,
    gUnknown_97EDEDE,
    gUnknown_97EDF38,
    gUnknown_97EDF92,
    gUnknown_97EDFEC,
};
const ax_anim *gUnknown_97EE128[] = {
    gUnknown_97EE04C,
    gUnknown_97EE04C,
    gUnknown_97EE04C,
    gUnknown_97EE04C,
    gUnknown_97EE04C,
    gUnknown_97EE04C,
    gUnknown_97EE04C,
    gUnknown_97EE04C,
};
const ax_anim *const *gUnknown_97EE148[] = {
    gUnknown_97EE128,
};
const EfoFileData gUnknown_97EE14C = {
    gUnknown_97EE114,
    gUnknown_97EE148,
    ARRAY_COUNT(gUnknown_97EE148), // 1
    NULL,
    NULL,
    gUnknown_97EE094,
    gUnknown_97EE0D4,
    ARRAY_COUNT(gUnknown_97EE094) / 16, // 2
};
