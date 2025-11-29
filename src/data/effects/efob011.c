#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_97AFE34;
const SiroArchive gUnknown_97AF214 = { "SIRO", &gUnknown_97AFE34 };
const ax_pose gUnknown_97AF224[] = {
    { -1, { 0, 0 }, 504, 16632, 3072 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97AF238[] = {
    { -1, { 0, 0 }, 504, 16632, 3076 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97AF24C[] = {
    { -1, { 0, 0 }, 504, 16632, 3080 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97AF260[] = {
    { -1, { 0, 0 }, 504, 20728, 3076 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97AF274[] = {
    { -1, { 0, 0 }, 504, 20728, 3072 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97AF288[] = {
    { -1, { 0, 0 }, 504, 20728, 3084 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97AF29C[] = {
    { -1, { 0, 0 }, 504, 16632, 3088 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97AF2B0[] = {
    { -1, { 0, 0 }, 504, 16632, 3084 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97AF2C4[] = {
    { -1, { 0, 0 }, 504, 16632, 3092 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97AF2D8[] = {
    { -1, { 0, 0 }, 496, 33008, 3096 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97AF2EC[] = {
    { -1, { 0, 0 }, 494, 251, 3112 },
    { -1, { 0, 0 }, 500, 261, 3112 },
    { -1, { 0, 0 }, 496, 33008, 3113 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97AF314[] = {
    { -1, { 0, 0 }, 496, 33008, 3129 },
    { -1, { 0, 0 }, 487, 252, 3145 },
    { -1, { 0, 0 }, 496, 268, 3145 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97AF33C[] = {
    { -1, { 0, 0 }, 483, 255, 3145 },
    { -1, { 0, 0 }, 495, 273, 3145 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97AF35A[] = {
    { -1, { 0, 0 }, 481, 257, 3145 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_97AF370 = 74;
const ax_anim gUnknown_97AF374[] = {
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 2,   0,   2, { 0, 0 }, { 0, 0 } },
    { 2,   0,   3, { 0, 0 }, { 0, 0 } },
    { 2,   0,   4, { 0, 0 }, { 0, 0 } },
    { 2,   0,   5, { 0, 0 }, { 0, 0 } },
    { 2,   0,   6, { 0, 0 }, { 0, 0 } },
    { 2,   0,   7, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_97AF3E0[] = {
    { 1,   0,   8, { 0, 0 }, { 0, 0 } },
    { 1,   0,   9, { 0, 0 }, { 0, 0 } },
    { 2,   0,   10, { 0, 0 }, { 0, 0 } },
    { 2,   0,   11, { 0, 0 }, { 0, 0 } },
    { 2,   0,   12, { 0, 0 }, { 0, 0 } },
    { 2,   0,   13, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_97AF434[] = INCBIN_U32("data/effects/efob011.4bpp");
const RGB_Struct gUnknown_97AFD74[] = INCBIN_U8("data/effects/efob011.pmdpal");
const ax_pose *const gUnknown_97AFDB4[] = {
    gUnknown_97AF224,
    gUnknown_97AF238,
    gUnknown_97AF24C,
    gUnknown_97AF260,
    gUnknown_97AF274,
    gUnknown_97AF288,
    gUnknown_97AF29C,
    gUnknown_97AF2B0,
    gUnknown_97AF2C4,
    gUnknown_97AF2D8,
    gUnknown_97AF2EC,
    gUnknown_97AF314,
    gUnknown_97AF33C,
    gUnknown_97AF35A,
};
const ax_anim *const gUnknown_97AFDEC[] = {
    gUnknown_97AF374,
    gUnknown_97AF374,
    gUnknown_97AF374,
    gUnknown_97AF374,
    gUnknown_97AF374,
    gUnknown_97AF374,
    gUnknown_97AF374,
    gUnknown_97AF374,
};
const ax_anim *const gUnknown_97AFE0C[] = {
    gUnknown_97AF3E0,
    gUnknown_97AF3E0,
    gUnknown_97AF3E0,
    gUnknown_97AF3E0,
    gUnknown_97AF3E0,
    gUnknown_97AF3E0,
    gUnknown_97AF3E0,
    gUnknown_97AF3E0,
};
const ax_anim *const *const gUnknown_97AFE2C[] = {
    gUnknown_97AFDEC,
    gUnknown_97AFE0C,
};
const EfoFileData gUnknown_97AFE34 = {
    gUnknown_97AFDB4,
    gUnknown_97AFE2C,
    ARRAY_COUNT(gUnknown_97AFE2C), // 2
    NULL,
    NULL,
    gUnknown_97AF434,
    gUnknown_97AFD74,
    sizeof(gUnknown_97AF434) / 32, // 74
};
