#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_984CCCC;
const SiroArchive gUnknown_984BDF8 = { "SIRO", &gUnknown_984CCCC };
const ax_pose gUnknown_984BE08[] = {
    { -1, { 0, 0 }, 33246, 33008, 35840 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_984BE1C[] = {
    { -1, { 0, 0 }, 33247, 33010, 35848 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_984BE30[] = {
    { -1, { 0, 0 }, 484, 33010, 35856 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_984BE44[] = {
    { -1, { 0, 0 }, 16887, 33011, 35872 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_984BE58[] = {
    { -1, { 0, 0 }, 16904, 33011, 35880 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_984BE6C[] = {
    { -1, { 0, 0 }, 523, 33013, 35888 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_984BE80[] = {
    { -1, { 0, 0 }, 504, 16632, 35904 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_984BE94[] = {
    { -1, { 0, 0 }, 496, 33008, 35908 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_984BEA8[] = {
    { -1, { 0, 0 }, 496, 33008, 35924 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_984BEBC[] = {
    { -1, { 0, 0 }, 508, 252, 35940 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_984BED0 = 101;
const ax_anim gUnknown_984BED4[] = {
    { 2,   0,   0, { -4, -5 }, { 0, 0 } },
    { 1,   0,   1, { -2, -4 }, { 0, 0 } },
    { 1,   0,   2, { -1, -3 }, { 0, 0 } },
    { 1,   0,   3, { -1, -1 }, { 0, 0 } },
    { 1,   0,   4, { 0, 0 }, { 0, 0 } },
    { 2,   0,   5, { -1, 2 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   6, { 0, 0 }, { 0, 0 } },
    { 1,   0,   9, { 0, 0 }, { 0, 0 } },
    { 1,   0,   7, { 0, 0 }, { 0, 0 } },
    { 1,   0,   9, { 0, 0 }, { 0, 0 } },
    { 1,   0,   8, { 0, 0 }, { 0, 0 } },
    { 1,   0,   9, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_984BF28[] = {
    { 1,   0,   6, { 0, 0 }, { 0, 0 } },
    { 1,   0,   9, { 0, 0 }, { 0, 0 } },
    { 1,   0,   7, { 0, 0 }, { 0, 0 } },
    { 1,   0,   9, { 0, 0 }, { 0, 0 } },
    { 1,   0,   8, { 0, 0 }, { 0, 0 } },
    { 1,   0,   9, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_984BF7C[] = INCBIN_U32("data/effects/efob131.4bpp");
const RGB gUnknown_984CC1C[] = INCBIN_U8("data/effects/efob131.pmdpal");
const ax_pose *const gUnknown_984CC5C[] = {
    gUnknown_984BE08,
    gUnknown_984BE1C,
    gUnknown_984BE30,
    gUnknown_984BE44,
    gUnknown_984BE58,
    gUnknown_984BE6C,
    gUnknown_984BE80,
    gUnknown_984BE94,
    gUnknown_984BEA8,
    gUnknown_984BEBC,
};
const ax_anim *const gUnknown_984CC84[] = {
    gUnknown_984BED4,
    gUnknown_984BED4,
    gUnknown_984BED4,
    gUnknown_984BED4,
    gUnknown_984BED4,
    gUnknown_984BED4,
    gUnknown_984BED4,
    gUnknown_984BED4,
};
const ax_anim *const gUnknown_984CCA4[] = {
    gUnknown_984BF28,
    gUnknown_984BF28,
    gUnknown_984BF28,
    gUnknown_984BF28,
    gUnknown_984BF28,
    gUnknown_984BF28,
    gUnknown_984BF28,
    gUnknown_984BF28,
};
const ax_anim *const *const gUnknown_984CCC4[] = {
    gUnknown_984CC84,
    gUnknown_984CCA4,
};
const EfoFileData gUnknown_984CCCC = {
    gUnknown_984CC5C,
    gUnknown_984CCC4,
    ARRAY_COUNT(gUnknown_984CCC4), // 2
    NULL,
    NULL,
    gUnknown_984BF7C,
    gUnknown_984CC1C,
    sizeof(gUnknown_984BF7C) / 32, // 101
};
