#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_9807BBC;
const SiroArchive gUnknown_98078A0 = { "SIRO", &gUnknown_9807BBC };
const ax_pose gUnknown_98078B0[] = {
    { -1, { 0, 0 }, 505, 16634, 27648 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_98078C4[] = {
    { -1, { 0, 0 }, 508, 252, 27652 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_98078D8 = 5;
const ax_anim gUnknown_98078DC[] = {
    { 4,   0,   0, { -7, -12 }, { 0, 0 } },
    { 2,   0,   0, { -4, -8 }, { 0, 0 } },
    { 2,   0,   0, { 1, -1 }, { 0, 0 } },
    { 2,   0,   0, { 6, 6 }, { 0, 0 } },
    { 1,   0,   0, { 10, 12 }, { 0, 0 } },
    { 4,   0,   0, { 12, 15 }, { 0, 0 } },
    { 2,   0,   0, { 13, 10 }, { 0, 0 } },
    { 2,   0,   0, { 15, 3 }, { 0, 0 } },
    { 1,   0,   0, { 17, -3 }, { 0, 0 } },
    { 4,   0,   0, { 19, -9 }, { 0, 0 } },
    { 2,   0,   0, { 13, -3 }, { 0, 0 } },
    { 2,   0,   0, { 6, 4 }, { 0, 0 } },
    { 1,   0,   0, { 3, 7 }, { 0, 0 } },
    { 1,   0,   0, { -5, 14 }, { 0, 0 } },
    { 4,   0,   0, { -10, 19 }, { 0, 0 } },
    { 2,   0,   0, { -12, 10 }, { 0, 0 } },
    { 2,   0,   0, { -13, 2 }, { 0, 0 } },
    { 1,   0,   0, { -14, -6 }, { 0, 0 } },
    { 4,   0,   0, { -15, -15 }, { 0, 0 } },
    { 2,   0,   0, { -11, -10 }, { 0, 0 } },
    { 2,   0,   0, { -5, -3 }, { 0, 0 } },
    { 3,   0,   0, { 0, 3 }, { 0, 0 } },
    { 3,   0,   0, { 4, 8 }, { 0, 0 } },
    { 3,   0,   0, { 8, 13 }, { 0, 0 } },
    { 1,   0,   0, { 6, 10 }, { 0, 0 } },
    { 1,   0,   0, { 2, 4 }, { 0, 0 } },
    { 4,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 1,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_9807AB0[] = INCBIN_U32("data/effects/efob072.4bpp");
const RGB_Struct gUnknown_9807B50[] = INCBIN_U8("data/effects/efob072.pmdpal");
const ax_pose *const gUnknown_9807B90[] = {
    gUnknown_98078B0,
    gUnknown_98078C4,
};
const ax_anim *const gUnknown_9807B98[] = {
    gUnknown_98078DC,
    gUnknown_98078DC,
    gUnknown_98078DC,
    gUnknown_98078DC,
    gUnknown_98078DC,
    gUnknown_98078DC,
    gUnknown_98078DC,
    gUnknown_98078DC,
};
const ax_anim *const *const gUnknown_9807BB8[] = {
    gUnknown_9807B98,
};
const EfoFileData gUnknown_9807BBC = {
    gUnknown_9807B90,
    gUnknown_9807BB8,
    ARRAY_COUNT(gUnknown_9807BB8), // 1
    NULL,
    NULL,
    gUnknown_9807AB0,
    gUnknown_9807B50,
    sizeof(gUnknown_9807AB0) / 32, // 5
};
