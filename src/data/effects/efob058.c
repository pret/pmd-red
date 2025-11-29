#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_97FCE8C;
const SiroArchive gUnknown_97FBF1C = { "SIRO", &gUnknown_97FCE8C };
const ax_pose gUnknown_97FBF2C[] = {
    { -1, { 0, 0 }, 494, 33008, 44032 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97FBF40[] = {
    { -1, { 0, 0 }, 494, 33008, 44048 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97FBF54[] = {
    { -1, { 0, 0 }, 494, 33008, 44064 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97FBF68[] = {
    { -1, { 0, 0 }, 494, 33008, 44080 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97FBF7C[] = {
    { -1, { 0, 0 }, 494, 33008, 44096 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97FBF90[] = {
    { -1, { 0, 0 }, 16888, 33008, 44112 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97FBFA4[] = {
    { -1, { 0, 0 }, 504, 16633, 44120 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97FBFB8[] = {
    { -1, { 0, 0 }, 504, 16633, 44124 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97FBFCC[] = {
    { -1, { 0, 0 }, 508, 253, 44128 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97FBFE0[] = {
    { -1, { 0, 0 }, 508, 252, 44129 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97FBFF4[] = {
    { -1, { 0, 0 }, 508, 252, 44130 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97FC008[] = {
    { -1, { 0, 0 }, 508, 253, 44131 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97FC01C[] = {
    { -1, { 0, 0 }, 508, 252, 44132 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_97FC030 = 101;
const ax_anim gUnknown_97FC034[] = {
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   12, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 1,   0,   12, { 0, 0 }, { 0, 0 } },
    { 2,   0,   2, { 0, 0 }, { 0, 0 } },
    { 1,   0,   12, { 0, 0 }, { 0, 0 } },
    { 2,   0,   3, { 0, 0 }, { 0, 0 } },
    { 1,   0,   12, { 0, 0 }, { 0, 0 } },
    { 2,   0,   4, { 0, 0 }, { 0, 0 } },
    { 1,   0,   12, { 0, 0 }, { 0, 0 } },
    { 2,   0,   5, { 0, 0 }, { 0, 0 } },
    { 1,   0,   12, { 0, 0 }, { 0, 0 } },
    { 2,   0,   6, { 0, 0 }, { 0, 0 } },
    { 1,   0,   12, { 0, 0 }, { 0, 0 } },
    { 2,   0,   7, { 0, 0 }, { 0, 0 } },
    { 1,   0,   12, { 0, 0 }, { 0, 0 } },
    { 2,   0,   8, { 0, 0 }, { 0, 0 } },
    { 1,   0,   12, { 0, 0 }, { 0, 0 } },
    { 2,   0,   9, { 0, 0 }, { 0, 0 } },
    { 1,   0,   12, { 0, 0 }, { 0, 0 } },
    { 2,   0,   10, { 0, 0 }, { 0, 0 } },
    { 1,   0,   12, { 0, 0 }, { 0, 0 } },
    { 2,   0,   11, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_97FC154[] = INCBIN_U32("data/effects/efob058.4bpp");
const RGB_Struct gUnknown_97FCDF4[] = INCBIN_U8("data/effects/efob058.pmdpal");
const ax_pose *const gUnknown_97FCE34[] = {
    gUnknown_97FBF2C,
    gUnknown_97FBF40,
    gUnknown_97FBF54,
    gUnknown_97FBF68,
    gUnknown_97FBF7C,
    gUnknown_97FBF90,
    gUnknown_97FBFA4,
    gUnknown_97FBFB8,
    gUnknown_97FBFCC,
    gUnknown_97FBFE0,
    gUnknown_97FBFF4,
    gUnknown_97FC008,
    gUnknown_97FC01C,
};
const ax_anim *const gUnknown_97FCE68[] = {
    gUnknown_97FC034,
    gUnknown_97FC034,
    gUnknown_97FC034,
    gUnknown_97FC034,
    gUnknown_97FC034,
    gUnknown_97FC034,
    gUnknown_97FC034,
    gUnknown_97FC034,
};
const ax_anim *const *const gUnknown_97FCE88[] = {
    gUnknown_97FCE68,
};
const EfoFileData gUnknown_97FCE8C = {
    gUnknown_97FCE34,
    gUnknown_97FCE88,
    ARRAY_COUNT(gUnknown_97FCE88), // 1
    NULL,
    NULL,
    gUnknown_97FC154,
    gUnknown_97FCDF4,
    sizeof(gUnknown_97FC154) / 32, // 101
};
