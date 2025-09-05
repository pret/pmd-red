#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_9807880;
const SiroArchive gUnknown_98074A4 = { "SIRO", &gUnknown_9807880 };
const ax_pose gUnknown_98074B4[] = {
    { -1, { 0, -5 }, 494, 33008, 23552 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_98074C8[] = {
    { -1, { 0, -5 }, 506, 252, 23568 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_98074DC = 17;
const ax_anim gUnknown_98074E0[] = {
    { 1,   0,   0, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 1,   0,   0, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 1,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 1,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 8,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 1,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 1,   0,   0, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 1,   0,   0, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_98075F4[] = INCBIN_U32("data/effects/efob071.4bpp");
const RGB gUnknown_9807814[] = INCBIN_U8("data/effects/efob071.pmdpal");
const ax_pose *const gUnknown_9807854[] = {
    gUnknown_98074B4,
    gUnknown_98074C8,
};
const ax_anim *const gUnknown_980785C[] = {
    gUnknown_98074E0,
    gUnknown_98074E0,
    gUnknown_98074E0,
    gUnknown_98074E0,
    gUnknown_98074E0,
    gUnknown_98074E0,
    gUnknown_98074E0,
    gUnknown_98074E0,
};
const ax_anim *const *const gUnknown_980787C[] = {
    gUnknown_980785C,
};
const EfoFileData gUnknown_9807880 = {
    gUnknown_9807854,
    gUnknown_980787C,
    ARRAY_COUNT(gUnknown_980787C), // 1
    NULL,
    NULL,
    gUnknown_98075F4,
    gUnknown_9807814,
    sizeof(gUnknown_98075F4) / 32, // 17
};
