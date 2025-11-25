#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_97B6904;
const SiroArchive gUnknown_97B568C = { "SIRO", &gUnknown_97B6904 };
const ax_pose gUnknown_97B569C[] = {
    { -1, { 0, 0 }, 508, 1276, 15360 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97B56B0[] = {
    { -1, { 0, 0 }, 499, 17656, 15361 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97B56C4[] = {
    { -1, { 0, 0 }, 486, 34032, 15365 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97B56D8[] = {
    { -1, { 0, 0 }, 486, 34032, 15381 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97B56EC[] = {
    { -1, { 0, 0 }, 486, 34032, 15397 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97B5700[] = {
    { -1, { 0, 0 }, 486, 34032, 15413 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97B5714[] = {
    { -1, { 0, 0 }, 486, 34032, 15429 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97B5728[] = {
    { -1, { 0, 0 }, 486, 34032, 15445 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97B573C[] = {
    { -1, { 0, 0 }, 486, 34032, 15461 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97B5750[] = {
    { -1, { 0, 0 }, 499, 17656, 15477 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97B5764[] = {
    { -1, { 0, 0 }, 508, 1276, 15481 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97B5778[] = {
    { -1, { 0, 0 }, 508, 1276, 15482 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_97B578C = 123;
const ax_anim gUnknown_97B5790[] = {
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 2,   0,   2, { 0, 0 }, { 0, 0 } },
    { 2,   0,   3, { 0, 0 }, { 0, 0 } },
    { 1,   0,   2, { 0, 0 }, { 0, 0 } },
    { 2,   0,   3, { 0, 0 }, { 0, 0 } },
    { 1,   0,   11, { 0, 0 }, { 0, 0 } },
    { 2,   0,   3, { 0, 0 }, { 0, 0 } },
    { 1,   0,   11, { 0, 0 }, { 0, 0 } },
    { 2,   0,   3, { 0, 0 }, { 0, 0 } },
    { 1,   0,   11, { 0, 0 }, { 0, 0 } },
    { 2,   0,   3, { 0, 0 }, { 0, 0 } },
    { 1,   0,   11, { 0, 0 }, { 0, 0 } },
    { 2,   0,   4, { 0, 0 }, { 0, 0 } },
    { 1,   0,   11, { 0, 0 }, { 0, 0 } },
    { 2,   0,   5, { 0, 0 }, { 0, 0 } },
    { 1,   0,   11, { 0, 0 }, { 0, 0 } },
    { 2,   0,   6, { 0, 0 }, { 0, 0 } },
    { 1,   0,   11, { 0, 0 }, { 0, 0 } },
    { 2,   0,   7, { 0, 0 }, { 0, 0 } },
    { 1,   0,   11, { 0, 0 }, { 0, 0 } },
    { 2,   0,   7, { 0, 0 }, { 0, 0 } },
    { 1,   0,   11, { 0, 0 }, { 0, 0 } },
    { 2,   0,   7, { 0, 0 }, { 0, 0 } },
    { 1,   0,   11, { 0, 0 }, { 0, 0 } },
    { 2,   0,   7, { 0, 0 }, { 0, 0 } },
    { 1,   0,   8, { 0, 0 }, { 0, 0 } },
    { 2,   0,   7, { 0, 0 }, { 0, 0 } },
    { 2,   0,   8, { 0, 0 }, { 0, 0 } },
    { 2,   0,   9, { 0, 0 }, { 0, 0 } },
    { 2,   0,   10, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_97B5910[] = INCBIN_U32("data/effects/efob014.4bpp");
const RGB_Struct gUnknown_97B6870[] = INCBIN_U8("data/effects/efob014.pmdpal");
const ax_pose *const gUnknown_97B68B0[] = {
    gUnknown_97B569C,
    gUnknown_97B56B0,
    gUnknown_97B56C4,
    gUnknown_97B56D8,
    gUnknown_97B56EC,
    gUnknown_97B5700,
    gUnknown_97B5714,
    gUnknown_97B5728,
    gUnknown_97B573C,
    gUnknown_97B5750,
    gUnknown_97B5764,
    gUnknown_97B5778,
};
const ax_anim *const gUnknown_97B68E0[] = {
    gUnknown_97B5790,
    gUnknown_97B5790,
    gUnknown_97B5790,
    gUnknown_97B5790,
    gUnknown_97B5790,
    gUnknown_97B5790,
    gUnknown_97B5790,
    gUnknown_97B5790,
};
const ax_anim *const *const gUnknown_97B6900[] = {
    gUnknown_97B68E0,
};
const EfoFileData gUnknown_97B6904 = {
    gUnknown_97B68B0,
    gUnknown_97B6900,
    ARRAY_COUNT(gUnknown_97B6900), // 1
    NULL,
    NULL,
    gUnknown_97B5910,
    gUnknown_97B6870,
    sizeof(gUnknown_97B5910) / 32, // 123
};
