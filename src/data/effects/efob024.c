#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_97C2764;
const SiroArchive gUnknown_97C17A8 = { "SIRO", &gUnknown_97C2764 };
const ax_pose gUnknown_97C17B8[] = {
    { -1, { 0, 0 }, 464, 34032, 3072 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97C17CC[] = {
    { -1, { 0, 0 }, 464, 34032, 3088 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97C17E0[] = {
    { -1, { 0, 0 }, 464, 34032, 3104 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97C17F4[] = {
    { -1, { 0, 0 }, 464, 34032, 3120 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97C1808[] = {
    { -1, { 0, 0 }, 464, 34032, 3136 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97C181C[] = {
    { -1, { 0, 0 }, 464, 34032, 3152 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97C1830[] = {
    { -1, { 0, 0 }, 464, 34032, 3168 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_97C1844 = 112;
const ax_anim gUnknown_97C1848[] = {
    { 4,   0,   0, { 0, 0 }, { 0, 0 } },
    { 4,   0,   1, { 1, -1 }, { 0, 0 } },
    { 4,   0,   2, { 2, -2 }, { 0, 0 } },
    { 4,   0,   3, { 2, -3 }, { 0, 0 } },
    { 4,   0,   4, { 2, -4 }, { 0, 0 } },
    { 4,   0,   5, { 1, -5 }, { 0, 0 } },
    { 4,   0,   6, { 0, -5 }, { 0, 0 } },
    { 4,   0,   5, { -1, -5 }, { 0, 0 } },
    { 4,   0,   4, { -2, -4 }, { 0, 0 } },
    { 4,   0,   3, { -2, -3 }, { 0, 0 } },
    { 4,   0,   2, { -2, -2 }, { 0, 0 } },
    { 4,   0,   1, { -1, -1 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_97C18E4[] = INCBIN_U32("data/effects/efob024.4bpp");
const RGB gUnknown_97C26E4[] = INCBIN_U8("data/effects/efob024.pmdpal");
const ax_pose *const gUnknown_97C2724[] = {
    gUnknown_97C17B8,
    gUnknown_97C17CC,
    gUnknown_97C17E0,
    gUnknown_97C17F4,
    gUnknown_97C1808,
    gUnknown_97C181C,
    gUnknown_97C1830,
};
const ax_anim *const gUnknown_97C2740[] = {
    gUnknown_97C1848,
    gUnknown_97C1848,
    gUnknown_97C1848,
    gUnknown_97C1848,
    gUnknown_97C1848,
    gUnknown_97C1848,
    gUnknown_97C1848,
    gUnknown_97C1848,
};
const ax_anim *const *const gUnknown_97C2760[] = {
    gUnknown_97C2740,
};
const EfoFileData gUnknown_97C2764 = {
    gUnknown_97C2724,
    gUnknown_97C2760,
    ARRAY_COUNT(gUnknown_97C2760), // 1
    NULL,
    NULL,
    gUnknown_97C18E4,
    gUnknown_97C26E4,
    sizeof(gUnknown_97C18E4) / 32, // 112
};
