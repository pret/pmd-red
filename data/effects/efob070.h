#include "global.h"
#include "decompress_sir.h"
#include "structs/str_8009A7C.h"
const struct EfoFileData gUnknown_9807484;
const SiroArchive gUnknown_9806E60 = { "SIRO", &gUnknown_9807484 };
const ax_pose gUnknown_9806E70[] = {
    { -1, { 0, 0 }, 494, 16645, 3072 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9806E84[] = {
    { -1, { 0, 0 }, 492, 33022, 3076 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9806E98[] = {
    { -1, { 0, 0 }, 16890, 33013, 3092 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9806EAC[] = {
    { -1, { 0, 0 }, 16896, 33014, 3100 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9806EC0[] = {
    { -1, { 0, 0 }, 494, 20715, 3072 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9806ED4[] = {
    { -1, { 0, 0 }, 492, 37090, 3076 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9806EE8[] = {
    { -1, { 0, 0 }, 16890, 37099, 3092 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9806EFC[] = {
    { -1, { 0, 0 }, 16896, 37098, 3100 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_9806F10 = 36;
const ax_anim gUnknown_9806F14[] = {
    { 1,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 1,   0,   2, { 0, 0 }, { 0, 0 } },
    { 1,   0,   3, { 0, 0 }, { 0, 0 } },
    { 1,   0,   4, { 0, 0 }, { 0, 0 } },
    { 1,   0,   5, { 0, 0 }, { 0, 0 } },
    { 1,   0,   6, { 0, 0 }, { 0, 0 } },
    { 1,   0,   7, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_9806F80[] = INCBIN_U32("data/effects/efob070.4bpp");
const RGB gUnknown_9807400[] = INCBIN_U8("data/effects/efob070.pmdpal");
const ax_pose *gUnknown_9807440[] = {
    gUnknown_9806E70,
    gUnknown_9806E84,
    gUnknown_9806E98,
    gUnknown_9806EAC,
    gUnknown_9806EC0,
    gUnknown_9806ED4,
    gUnknown_9806EE8,
    gUnknown_9806EFC,
};
const ax_anim *gUnknown_9807460[] = {
    gUnknown_9806F14,
    gUnknown_9806F14,
    gUnknown_9806F14,
    gUnknown_9806F14,
    gUnknown_9806F14,
    gUnknown_9806F14,
    gUnknown_9806F14,
    gUnknown_9806F14,
};
const ax_anim *const *gUnknown_9807480[] = {
    gUnknown_9807460,
};
const EfoFileData gUnknown_9807484 = {
    gUnknown_9807440,
    gUnknown_9807480,
    ARRAY_COUNT(gUnknown_9807480), // 1
    NULL,
    NULL,
    gUnknown_9806F80,
    gUnknown_9807400,
    ARRAY_COUNT(gUnknown_9806F80) / 16, // 36
};
