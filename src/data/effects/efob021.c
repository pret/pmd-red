#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_97BE5EC;
const SiroArchive gUnknown_97BD45C = { "SIRO", &gUnknown_97BE5EC };
const ax_pose gUnknown_97BD46C[] = {
    { -1, { 0, 0 }, 500, 17648, 3072 },
    { -1, { 0, 0 }, 500, 21760, 3072 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97BD48A[] = {
    { -1, { 0, 0 }, 485, 34032, 3076 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97BD49E[] = {
    { -1, { 0, 0 }, 476, 1277, 3092 },
    { -1, { 0, 0 }, 506, 1295, 3093 },
    { -1, { 0, 0 }, 505, 1256, 3094 },
    { -1, { 0, 0 }, 484, 34032, 3095 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97BD4D0[] = {
    { -1, { 0, 0 }, 16855, 34032, 3111 },
    { -1, { 0, 0 }, 16864, 34020, 3119 },
    { -1, { 0, 0 }, 16864, 38141, 3119 },
    { -1, { 0, 0 }, 484, 34032, 3127 },
    { -1, { 0, 0 }, 508, 1256, 3143 },
    { -1, { 0, 0 }, 508, 1296, 3144 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97BD516[] = {
    { -1, { 0, 0 }, 16852, 34032, 3119 },
    { -1, { 0, 0 }, 16862, 34018, 3119 },
    { -1, { 0, 0 }, 16862, 38142, 3119 },
    { -1, { 0, 0 }, 484, 34032, 3145 },
    { -1, { 0, 0 }, 508, 1256, 3161 },
    { -1, { 0, 0 }, 508, 1295, 3162 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97BD55C[] = {
    { -1, { 0, 0 }, 16850, 34032, 3119 },
    { -1, { 0, 0 }, 16862, 17632, 3163 },
    { -1, { 0, 0 }, 16862, 21760, 3163 },
    { -1, { 0, 0 }, 16877, 34042, 3111 },
    { -1, { 0, 0 }, 16873, 38123, 3111 },
    { -1, { 0, 0 }, 16885, 34034, 3111 },
    { -1, { 0, 0 }, 16884, 38120, 3111 },
    { -1, { 0, 0 }, 16886, 42208, 3119 },
    { -1, { 0, 0 }, 16884, 42240, 3119 },
    { -1, { 0, 0 }, 500, 17656, 3167 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97BD5CA[] = {
    { -1, { 0, 0 }, 16852, 17648, 3163 },
    { -1, { 0, 0 }, 16880, 34044, 3119 },
    { -1, { 0, 0 }, 16875, 38121, 3119 },
    { -1, { 0, 0 }, 16889, 34037, 3119 },
    { -1, { 0, 0 }, 16887, 38116, 3119 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97BD606[] = {
    { -1, { 0, 0 }, 16854, 17648, 3163 },
    { -1, { 0, 0 }, 16883, 17660, 3163 },
    { -1, { 0, 0 }, 16878, 21737, 3163 },
    { -1, { 0, 0 }, 16892, 17653, 3163 },
    { -1, { 0, 0 }, 16890, 21732, 3163 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97BD642[] = {
    { -1, { 0, 0 }, 496, 33008, 3171 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_97BD658 = 115;
const ax_anim gUnknown_97BD65C[] = {
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 4,   0,   1, { 0, 0 }, { 0, 0 } },
    { 4,   0,   2, { 0, 0 }, { 0, 0 } },
    { 4,   0,   3, { 0, 0 }, { 0, 0 } },
    { 4,   0,   4, { 0, 0 }, { 0, 0 } },
    { 3,   0,   5, { 0, 0 }, { 0, 0 } },
    { 3,   0,   6, { 0, 0 }, { 0, 0 } },
    { 3,   0,   7, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_97BD6C8[] = {
    { 4,   0,   8, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_97BD6E0[] = INCBIN_U32("data/effects/efob021.4bpp");
const RGB_Struct gUnknown_97BE540[] = INCBIN_U8("data/effects/efob021.pmdpal");
const ax_pose *const gUnknown_97BE580[] = {
    gUnknown_97BD46C,
    gUnknown_97BD48A,
    gUnknown_97BD49E,
    gUnknown_97BD4D0,
    gUnknown_97BD516,
    gUnknown_97BD55C,
    gUnknown_97BD5CA,
    gUnknown_97BD606,
    gUnknown_97BD642,
};
const ax_anim *const gUnknown_97BE5A4[] = {
    gUnknown_97BD65C,
    gUnknown_97BD65C,
    gUnknown_97BD65C,
    gUnknown_97BD65C,
    gUnknown_97BD65C,
    gUnknown_97BD65C,
    gUnknown_97BD65C,
    gUnknown_97BD65C,
};
const ax_anim *const gUnknown_97BE5C4[] = {
    gUnknown_97BD6C8,
    gUnknown_97BD6C8,
    gUnknown_97BD6C8,
    gUnknown_97BD6C8,
    gUnknown_97BD6C8,
    gUnknown_97BD6C8,
    gUnknown_97BD6C8,
    gUnknown_97BD6C8,
};
const ax_anim *const *const gUnknown_97BE5E4[] = {
    gUnknown_97BE5A4,
    gUnknown_97BE5C4,
};
const EfoFileData gUnknown_97BE5EC = {
    gUnknown_97BE580,
    gUnknown_97BE5E4,
    ARRAY_COUNT(gUnknown_97BE5E4), // 2
    NULL,
    NULL,
    gUnknown_97BD6E0,
    gUnknown_97BE540,
    sizeof(gUnknown_97BD6E0) / 32, // 115
};
