#include "global.h"
#include "decompress_sir.h"
#include "structs/str_8009A7C.h"
const struct EfoFileData gUnknown_97BACA4;
const SiroArchive gUnknown_97BA958 = { "SIRO", &gUnknown_97BACA4 };
const ax_pose gUnknown_97BA968[] = {
    { -1, { 0, 0 }, 504, 17656, 23552 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97BA97C[] = {
    { -1, { 0, 0 }, 504, 17656, 3076 },
    { -1, { 0, 0 }, 504, 17656, 23552 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97BA99A[] = {
    { -1, { 0, 0 }, 504, 17656, 3080 },
    { -1, { 0, 0 }, 504, 17656, 23552 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97BA9B8[] = {
    { -1, { 0, 0 }, 504, 17656, 3084 },
    { -1, { 0, 0 }, 504, 17656, 23552 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_97BA9D8 = 16;
const ax_anim gUnknown_97BA9DC[] = {
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 2,   0,   2, { 0, 0 }, { 0, 0 } },
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 2,   0,   3, { 0, 0 }, { 0, 0 } },
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_97BAA30[] = INCBIN_U32("data/effects/efob019.4bpp");
const RGB gUnknown_97BAC30[] = INCBIN_U8("data/effects/efob019.pmdpal");
const ax_pose *gUnknown_97BAC70[] = {
    gUnknown_97BA968,
    gUnknown_97BA97C,
    gUnknown_97BA99A,
    gUnknown_97BA9B8,
};
const ax_anim *gUnknown_97BAC80[] = {
    gUnknown_97BA9DC,
    gUnknown_97BA9DC,
    gUnknown_97BA9DC,
    gUnknown_97BA9DC,
    gUnknown_97BA9DC,
    gUnknown_97BA9DC,
    gUnknown_97BA9DC,
    gUnknown_97BA9DC,
};
const ax_anim *const *gUnknown_97BACA0[] = {
    gUnknown_97BAC80,
};
const EfoFileData gUnknown_97BACA4 = {
    gUnknown_97BAC70,
    gUnknown_97BACA0,
    ARRAY_COUNT(gUnknown_97BACA0), // 1
    NULL,
    NULL,
    gUnknown_97BAA30,
    gUnknown_97BAC30,
    ARRAY_COUNT(gUnknown_97BAA30) / 16, // 16
};
