#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_98067BC;
const SiroArchive gUnknown_9805FF4 = { "SIRO", &gUnknown_98067BC };
const ax_pose gUnknown_9806004[] = {
    { -1, { 0, 0 }, 33264, 33009, 15360 },
    { -1, { 0, 0 }, 520, 257, 15368 },
    { -1, { 0, 0 }, 489, 257, 15368 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_980602C[] = {
    { -1, { 0, 0 }, 520, 258, 15369 },
    { -1, { 0, 0 }, 489, 258, 15369 },
    { -1, { 0, 0 }, 33264, 33010, 15370 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9806054[] = {
    { -1, { 0, 0 }, 33264, 33013, 15378 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9806068[] = {
    { -1, { 0, 0 }, 33264, 33016, 15386 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_980607C[] = {
    { -1, { 0, 0 }, 33264, 37116, 15378 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9806090[] = {
    { -1, { 0, 0 }, 520, 4343, 15369 },
    { -1, { 0, 0 }, 489, 4343, 15369 },
    { -1, { 0, 0 }, 33264, 37119, 15370 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_98060B8[] = {
    { -1, { 0, 0 }, 520, 247, 15394 },
    { -1, { 0, 0 }, 489, 247, 15394 },
    { -1, { 0, 0 }, 33264, 33023, 15395 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_98060E0[] = {
    { -1, { 0, 0 }, 508, 252, 15403 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_98060F4 = 44;
const ax_anim gUnknown_98060F8[] = {
    { 3,   0,   0, { 0, 0 }, { 0, 0 } },
    { 3,   0,   1, { 0, 0 }, { 0, 0 } },
    { 2,   0,   2, { 0, 0 }, { 0, 0 } },
    { 2,   0,   3, { 0, 0 }, { 0, 0 } },
    { 2,   0,   4, { 0, 0 }, { 0, 0 } },
    { 3,   0,   5, { 0, 0 }, { 0, 0 } },
    { 3,   0,   6, { 0, 0 }, { 0, 0 } },
    { 2,   0,   7, { 0, 0 }, { 0, 0 } },
    { 3,   0,   0, { 0, 0 }, { 0, 0 } },
    { 3,   0,   1, { 0, 0 }, { 0, 0 } },
    { 2,   0,   2, { 0, 0 }, { 0, 0 } },
    { 2,   0,   3, { 0, 0 }, { 0, 0 } },
    { 2,   0,   4, { 0, 0 }, { 0, 0 } },
    { 3,   0,   5, { 0, 0 }, { 0, 0 } },
    { 3,   0,   6, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_98061B8[] = INCBIN_U32("data/effects/efob068.4bpp");
const RGB gUnknown_9806738[] = INCBIN_U8("data/effects/efob068.pmdpal");
const ax_pose *gUnknown_9806778[] = {
    gUnknown_9806004,
    gUnknown_980602C,
    gUnknown_9806054,
    gUnknown_9806068,
    gUnknown_980607C,
    gUnknown_9806090,
    gUnknown_98060B8,
    gUnknown_98060E0,
};
const ax_anim *gUnknown_9806798[] = {
    gUnknown_98060F8,
    gUnknown_98060F8,
    gUnknown_98060F8,
    gUnknown_98060F8,
    gUnknown_98060F8,
    gUnknown_98060F8,
    gUnknown_98060F8,
    gUnknown_98060F8,
};
const ax_anim *const *gUnknown_98067B8[] = {
    gUnknown_9806798,
};
const EfoFileData gUnknown_98067BC = {
    gUnknown_9806778,
    gUnknown_98067B8,
    ARRAY_COUNT(gUnknown_98067B8), // 1
    NULL,
    NULL,
    gUnknown_98061B8,
    gUnknown_9806738,
    sizeof(gUnknown_98061B8) / 32, // 44
};
