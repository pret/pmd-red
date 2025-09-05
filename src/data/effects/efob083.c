#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_981445C;
const SiroArchive gUnknown_9813710 = { "SIRO", &gUnknown_981445C };
const ax_pose gUnknown_9813720[] = {
    { -1, { 0, 0 }, 16892, 256, 23552 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9813734[] = {
    { -1, { 0, 0 }, 16892, 250, 23554 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9813748[] = {
    { -1, { 0, 0 }, 508, 254, 23556 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_981375C[] = {
    { -1, { 0, 0 }, 496, 16632, 23557 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9813770[] = {
    { -1, { 0, 0 }, 33253, 33016, 23561 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9813784[] = {
    { -1, { 0, 0 }, 479, 33008, 23569 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9813798[] = {
    { -1, { 0, 0 }, 474, 33008, 23585 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_98137AC[] = {
    { -1, { 0, 0 }, 474, 33008, 23601 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_98137C0[] = {
    { -1, { 0, 0 }, 474, 33008, 23617 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_98137D4[] = {
    { -1, { 0, 0 }, 508, 252, 23633 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_98137E8 = 82;
const ax_anim gUnknown_98137EC[] = {
    { 5,   0,   0, { 5, 0 }, { 0, 0 } },
    { 2,   0,   0, { 2, 0 }, { 0, 0 } },
    { 2,   0,   0, { 1, 0 }, { 0, 0 } },
    { 5,   0,   0, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, -1 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, -1 }, { 0, 0 } },
    { 5,   0,   1, { 0, 0 }, { 0, 0 } },
    { 2,   0,   2, { 0, 0 }, { 0, 0 } },
    { 2,   0,   2, { 0, -1 }, { 0, 0 } },
    { 2,   0,   2, { 0, 0 }, { 0, 0 } },
    { 2,   0,   2, { 0, -1 }, { 0, 0 } },
    { 5,   0,   2, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_98138A0[] = {
    { 4,   0,   3, { 0, 0 }, { 0, 0 } },
    { 4,   0,   4, { 0, 0 }, { 0, 0 } },
    { 4,   0,   5, { 0, 0 }, { 0, 0 } },
    { 4,   0,   6, { 0, 0 }, { 0, 0 } },
    { 4,   0,   6, { 0, -4 }, { 0, 0 } },
    { 4,   0,   6, { 0, -6 }, { 0, 0 } },
    { 4,   0,   6, { 0, -8 }, { 0, 0 } },
    { 4,   0,   6, { 0, -11 }, { 0, 0 } },
    { 4,   0,   7, { 0, -14 }, { 0, 0 } },
    { 1,   0,   9, { 0, -8 }, { 0, 0 } },
    { 2,   0,   7, { 0, -18 }, { 0, 0 } },
    { 1,   0,   9, { 0, -8 }, { 0, 0 } },
    { 2,   0,   8, { 0, -20 }, { 0, 0 } },
    { 1,   0,   9, { 0, -8 }, { 0, 0 } },
    { 1,   0,   8, { 0, -22 }, { 0, 0 } },
    { 1,   0,   9, { 0, -8 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_981396C[] = INCBIN_U32("data/effects/efob083.4bpp");
const RGB gUnknown_98143AC[] = INCBIN_U8("data/effects/efob083.pmdpal");
const ax_pose *const gUnknown_98143EC[] = {
    gUnknown_9813720,
    gUnknown_9813734,
    gUnknown_9813748,
    gUnknown_981375C,
    gUnknown_9813770,
    gUnknown_9813784,
    gUnknown_9813798,
    gUnknown_98137AC,
    gUnknown_98137C0,
    gUnknown_98137D4,
};
const ax_anim *const gUnknown_9814414[] = {
    gUnknown_98137EC,
    gUnknown_98137EC,
    gUnknown_98137EC,
    gUnknown_98137EC,
    gUnknown_98137EC,
    gUnknown_98137EC,
    gUnknown_98137EC,
    gUnknown_98137EC,
};
const ax_anim *const gUnknown_9814434[] = {
    gUnknown_98138A0,
    gUnknown_98138A0,
    gUnknown_98138A0,
    gUnknown_98138A0,
    gUnknown_98138A0,
    gUnknown_98138A0,
    gUnknown_98138A0,
    gUnknown_98138A0,
};
const ax_anim *const *const gUnknown_9814454[] = {
    gUnknown_9814414,
    gUnknown_9814434,
};
const EfoFileData gUnknown_981445C = {
    gUnknown_98143EC,
    gUnknown_9814454,
    ARRAY_COUNT(gUnknown_9814454), // 2
    NULL,
    NULL,
    gUnknown_981396C,
    gUnknown_98143AC,
    sizeof(gUnknown_981396C) / 32, // 82
};
