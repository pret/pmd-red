#include "global.h"
#include "decompress_sir.h"
#include "structs/str_8009A7C.h"
const struct EfoFileData gUnknown_98452C0;
const SiroArchive gUnknown_9844EDC = { "SIRO", &gUnknown_98452C0 };
const ax_pose gUnknown_9844EEC[] = {
    { -1, { 0, 0 }, 480, 32992, 7168 },
    { -1, { 0, 0 }, 480, 37120, 7168 },
    { -1, { 0, 0 }, 512, 45312, 7168 },
    { -1, { 0, 0 }, 512, 41184, 7168 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9844F1E[] = {
    { -1, { 0, 0 }, 508, 252, 7184 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_9844F34 = 17;
const ax_anim gUnknown_9844F38[] = {
    { 4,   0,   0, { 0, -160 }, { 0, 0 } },
    { 4,   0,   0, { 0, -100 }, { 0, 0 } },
    { 4,   0,   0, { 0, -40 }, { 0, 0 } },
    { 1,   0,   0, { 0, 0 }, { 0, 0 } },
    { 2,   0,   0, { 0, -15 }, { 0, 0 } },
    { 2,   0,   0, { 0, -30 }, { 0, 0 } },
    { 4,   0,   0, { 0, -35 }, { 0, 0 } },
    { 2,   0,   0, { 0, -30 }, { 0, 0 } },
    { 2,   0,   0, { 0, -15 }, { 0, 0 } },
    { 1,   0,   0, { 0, 0 }, { 0, 0 } },
    { 2,   0,   0, { 0, -15 }, { 0, 0 } },
    { 4,   0,   0, { 0, -20 }, { 0, 0 } },
    { 2,   0,   0, { 0, -15 }, { 0, 0 } },
    { 8,   0,   0, { 0, 0 }, { 0, 0 } },
    { 4,   0,   1, { 0, 0 }, { 0, 0 } },
    { 4,   0,   0, { 0, 0 }, { 0, 0 } },
    { 4,   0,   1, { 0, 0 }, { 0, 0 } },
    { 4,   0,   0, { 0, 0 }, { 0, 0 } },
    { 4,   0,   1, { 0, 0 }, { 0, 0 } },
    { 4,   0,   0, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_9845034[] = INCBIN_U32("data/effects/efob123.4bpp");
const RGB gUnknown_9845254[] = INCBIN_U8("data/effects/efob123.pmdpal");
const ax_pose *gUnknown_9845294[] = {
    gUnknown_9844EEC,
    gUnknown_9844F1E,
};
const ax_anim *gUnknown_984529C[] = {
    gUnknown_9844F38,
    gUnknown_9844F38,
    gUnknown_9844F38,
    gUnknown_9844F38,
    gUnknown_9844F38,
    gUnknown_9844F38,
    gUnknown_9844F38,
    gUnknown_9844F38,
};
const ax_anim *const *gUnknown_98452BC[] = {
    gUnknown_984529C,
};
const EfoFileData gUnknown_98452C0 = {
    gUnknown_9845294,
    gUnknown_98452BC,
    ARRAY_COUNT(gUnknown_98452BC), // 1
    NULL,
    NULL,
    gUnknown_9845034,
    gUnknown_9845254,
    ARRAY_COUNT(gUnknown_9845034) / 16, // 17
};
