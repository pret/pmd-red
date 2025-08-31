#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_980E06C;
const SiroArchive gUnknown_980DB3C = { "SIRO", &gUnknown_980E06C };
const ax_pose gUnknown_980DB4C[] = {
    { -1, { 0, 0 }, 502, 16632, 19456 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_980DB60[] = {
    { -1, { 0, 0 }, 496, 16628, 19460 },
    { -1, { 0, 0 }, 16896, 244, 19464 },
    { -1, { 0, 0 }, 33264, 260, 19466 },
    { -1, { 0, 0 }, 512, 260, 19468 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_980DB92[] = {
    { -1, { 0, 0 }, 491, 33008, 19469 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_980DBA6[] = {
    { -1, { 0, 0 }, 508, 252, 19485 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_980DBBC = 30;
const ax_anim gUnknown_980DBC0[] = {
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, -8 }, { 0, 0 } },
    { 2,   0,   2, { 0, -16 }, { 0, 0 } },
    { 1,   0,   3, { 0, -16 }, { 0, 0 } },
    { 1,   0,   2, { 0, -16 }, { 0, 0 } },
    { 1,   0,   3, { 0, -16 }, { 0, 0 } },
    { 1,   0,   2, { 0, -16 }, { 0, 0 } },
    { 1,   0,   3, { 0, -16 }, { 0, 0 } },
    { 6,   0,   2, { 0, -16 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_980DC38[] = INCBIN_U32("data/effects/efob079.4bpp");
const RGB gUnknown_980DFF8[] = INCBIN_U8("data/effects/efob079.pmdpal");
const ax_pose *const gUnknown_980E038[] = {
    gUnknown_980DB4C,
    gUnknown_980DB60,
    gUnknown_980DB92,
    gUnknown_980DBA6,
};
const ax_anim *const gUnknown_980E048[] = {
    gUnknown_980DBC0,
    gUnknown_980DBC0,
    gUnknown_980DBC0,
    gUnknown_980DBC0,
    gUnknown_980DBC0,
    gUnknown_980DBC0,
    gUnknown_980DBC0,
    gUnknown_980DBC0,
};
const ax_anim *const *const gUnknown_980E068[] = {
    gUnknown_980E048,
};
const EfoFileData gUnknown_980E06C = {
    gUnknown_980E038,
    gUnknown_980E068,
    ARRAY_COUNT(gUnknown_980E068), // 1
    NULL,
    NULL,
    gUnknown_980DC38,
    gUnknown_980DFF8,
    sizeof(gUnknown_980DC38) / 32, // 30
};
