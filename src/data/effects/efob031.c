#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_97CE604;
const SiroArchive gUnknown_97CD47C = { "SIRO", &gUnknown_97CE604 };
const ax_pose gUnknown_97CD48C[] = {
    { -1, { 0, 12 }, 33263, 33024, 3072 },
    { -1, { 0, 12 }, 33262, 45296, 3072 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97CD4AA[] = {
    { -1, { 0, 12 }, 480, 32992, 3080 },
    { -1, { 0, 12 }, 512, 32992, 3096 },
    { -1, { 0, 12 }, 512, 45312, 3080 },
    { -1, { 0, 12 }, 480, 45312, 3096 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97CD4DC[] = {
    { -1, { 0, 12 }, 480, 33024, 3112 },
    { -1, { 0, 12 }, 480, 32992, 3128 },
    { -1, { 0, 12 }, 512, 45280, 3112 },
    { -1, { 0, 12 }, 512, 45312, 3128 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97CD50E[] = {
    { -1, { 0, 12 }, 480, 32992, 3144 },
    { -1, { 0, 12 }, 480, 37120, 3144 },
    { -1, { 0, 12 }, 512, 41184, 3144 },
    { -1, { 0, 12 }, 512, 45312, 3144 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97CD540[] = {
    { -1, { 0, 12 }, 480, 32992, 3160 },
    { -1, { 0, 12 }, 480, 37120, 3160 },
    { -1, { 0, 12 }, 512, 41184, 3160 },
    { -1, { 0, 12 }, 512, 45312, 3160 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97CD572[] = {
    { -1, { 0, 12 }, 508, 252, 3176 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97CD586[] = {
    { -1, { 0, 12 }, 480, 32992, 3177 },
    { -1, { 0, 12 }, 480, 37120, 3177 },
    { -1, { 0, 12 }, 512, 41184, 3177 },
    { -1, { 0, 12 }, 512, 45312, 3177 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_97CD5B8 = 121;
const ax_anim gUnknown_97CD5BC[] = {
    { 1,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   5, { 0, 0 }, { 0, 0 } },
    { 1,   0,   4, { 0, 0 }, { 0, 0 } },
    { 1,   0,   5, { 0, 0 }, { 0, 0 } },
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 1,   0,   2, { 0, 0 }, { 0, 0 } },
    { 1,   0,   5, { 0, 0 }, { 0, 0 } },
    { 1,   0,   6, { 0, 0 }, { 0, 0 } },
    { 1,   0,   5, { 0, 0 }, { 0, 0 } },
    { 1,   0,   3, { 0, 0 }, { 0, 0 } },
    { 1,   0,   5, { 0, 0 }, { 0, 0 } },
    { 1,   0,   4, { 0, 0 }, { 0, 0 } },
    { 4,   0,   5, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_97CD664[] = INCBIN_U32("data/effects/efob031.4bpp");
const RGB_Struct gUnknown_97CE584[] = INCBIN_U8("data/effects/efob031.pmdpal");
const ax_pose *const gUnknown_97CE5C4[] = {
    gUnknown_97CD48C,
    gUnknown_97CD4AA,
    gUnknown_97CD4DC,
    gUnknown_97CD50E,
    gUnknown_97CD540,
    gUnknown_97CD572,
    gUnknown_97CD586,
};
const ax_anim *const gUnknown_97CE5E0[] = {
    gUnknown_97CD5BC,
    gUnknown_97CD5BC,
    gUnknown_97CD5BC,
    gUnknown_97CD5BC,
    gUnknown_97CD5BC,
    gUnknown_97CD5BC,
    gUnknown_97CD5BC,
    gUnknown_97CD5BC,
};
const ax_anim *const *const gUnknown_97CE600[] = {
    gUnknown_97CE5E0,
};
const EfoFileData gUnknown_97CE604 = {
    gUnknown_97CE5C4,
    gUnknown_97CE600,
    ARRAY_COUNT(gUnknown_97CE600), // 1
    NULL,
    NULL,
    gUnknown_97CD664,
    gUnknown_97CE584,
    sizeof(gUnknown_97CD664) / 32, // 121
};
