#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_9805FD4;
const SiroArchive gUnknown_980519C = { "SIRO", &gUnknown_9805FD4 };
const ax_pose gUnknown_98051AC[] = {
    { -1, { 0, 0 }, 480, 32992, 35840 },
    { -1, { 0, 0 }, 511, 41184, 35840 },
    { -1, { 0, 0 }, 480, 33024, 35856 },
    { -1, { 0, 0 }, 511, 41216, 35856 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_98051DE[] = {
    { -1, { 0, 0 }, 480, 32992, 35872 },
    { -1, { 0, 0 }, 511, 41184, 35872 },
    { -1, { 0, 0 }, 480, 33024, 35888 },
    { -1, { 0, 0 }, 511, 41216, 35888 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9805210[] = {
    { -1, { 0, 0 }, 480, 32992, 35904 },
    { -1, { 0, 0 }, 511, 41184, 35904 },
    { -1, { 0, 0 }, 480, 33024, 35920 },
    { -1, { 0, 0 }, 511, 41216, 35920 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9805242[] = {
    { -1, { 0, 0 }, 508, 252, 35936 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_9805258 = 97;
const ax_anim gUnknown_980525C[] = {
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   3, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 1,   0,   3, { 0, 0 }, { 0, 0 } },
    { 2,   0,   2, { 0, 0 }, { 0, 0 } },
    { 1,   0,   3, { 0, 0 }, { 0, 0 } },
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   3, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 1,   0,   3, { 0, 0 }, { 0, 0 } },
    { 2,   0,   2, { 0, 0 }, { 0, 0 } },
    { 1,   0,   3, { 0, 0 }, { 0, 0 } },
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   3, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 1,   0,   3, { 0, 0 }, { 0, 0 } },
    { 2,   0,   2, { 0, 0 }, { 0, 0 } },
    { 1,   0,   3, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_9805340[] = INCBIN_U32("data/effects/efob067.4bpp");
const RGB gUnknown_9805F60[] = INCBIN_U8("data/effects/efob067.pmdpal");
const ax_pose *gUnknown_9805FA0[] = {
    gUnknown_98051AC,
    gUnknown_98051DE,
    gUnknown_9805210,
    gUnknown_9805242,
};
const ax_anim *gUnknown_9805FB0[] = {
    gUnknown_980525C,
    gUnknown_980525C,
    gUnknown_980525C,
    gUnknown_980525C,
    gUnknown_980525C,
    gUnknown_980525C,
    gUnknown_980525C,
    gUnknown_980525C,
};
const ax_anim *const *gUnknown_9805FD0[] = {
    gUnknown_9805FB0,
};
const EfoFileData gUnknown_9805FD4 = {
    gUnknown_9805FA0,
    gUnknown_9805FD0,
    ARRAY_COUNT(gUnknown_9805FD0), // 1
    NULL,
    NULL,
    gUnknown_9805340,
    gUnknown_9805F60,
    sizeof(gUnknown_9805340) / 32, // 97
};
