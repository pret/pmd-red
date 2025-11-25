#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_983F384;
const SiroArchive gUnknown_983F060 = { "SIRO", &gUnknown_983F384 };
const ax_pose gUnknown_983F070[] = {
    { -1, { 0, 0 }, 504, 16632, 23552 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_983F084[] = {
    { -1, { 0, 0 }, 504, 16632, 23556 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_983F098[] = {
    { -1, { 0, 0 }, 508, 252, 23560 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_983F0AC = 9;
const ax_anim gUnknown_983F0B0[] = {
    { 1,   0,   2, { 0, 0 }, { 0, 0 } },
    { 1,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   2, { 0, 0 }, { 0, 0 } },
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 1,   0,   1, { 1, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 1,   0,   1, { 1, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_983F128[] = {
    { 1,   0,   0, { 0, -30 }, { 0, 0 } },
    { 1,   0,   2, { 0, -30 }, { 0, 0 } },
    { 1,   0,   1, { 0, -30 }, { 0, 0 } },
    { 1,   0,   2, { 0, -30 }, { 0, 0 } },
    { 8,   0,   1, { 0, -30 }, { 0, 0 } },
    { 1,   0,   1, { 0, -28 }, { 0, 0 } },
    { 1,   0,   1, { 0, -21 }, { 0, 0 } },
    { 1,   0,   1, { 0, -13 }, { 0, 0 } },
    { 1,   0,   1, { 0, -5 }, { 0, 0 } },
    { 1,   0,   1, { 0, -1 }, { 0, 0 } },
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 1,   0,   2, { 0, 0 }, { 0, 0 } },
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_983F1D0[] = INCBIN_U32("data/effects/efob120.4bpp");
const RGB_Struct gUnknown_983F2F0[] = INCBIN_U8("data/effects/efob120.pmdpal");
const ax_pose *const gUnknown_983F330[] = {
    gUnknown_983F070,
    gUnknown_983F084,
    gUnknown_983F098,
};
const ax_anim *const gUnknown_983F33C[] = {
    gUnknown_983F0B0,
    gUnknown_983F0B0,
    gUnknown_983F0B0,
    gUnknown_983F0B0,
    gUnknown_983F0B0,
    gUnknown_983F0B0,
    gUnknown_983F0B0,
    gUnknown_983F0B0,
};
const ax_anim *const gUnknown_983F35C[] = {
    gUnknown_983F128,
    gUnknown_983F128,
    gUnknown_983F128,
    gUnknown_983F128,
    gUnknown_983F128,
    gUnknown_983F128,
    gUnknown_983F128,
    gUnknown_983F128,
};
const ax_anim *const *const gUnknown_983F37C[] = {
    gUnknown_983F33C,
    gUnknown_983F35C,
};
const EfoFileData gUnknown_983F384 = {
    gUnknown_983F330,
    gUnknown_983F37C,
    ARRAY_COUNT(gUnknown_983F37C), // 2
    NULL,
    NULL,
    gUnknown_983F1D0,
    gUnknown_983F2F0,
    sizeof(gUnknown_983F1D0) / 32, // 9
};
