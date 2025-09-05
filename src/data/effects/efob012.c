#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_97B08E0;
const SiroArchive gUnknown_97AFE54 = { "SIRO", &gUnknown_97B08E0 };
const ax_pose gUnknown_97AFE64[] = {
    { -1, { 0, 0 }, 487, 240, 44032 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97AFE78[] = {
    { -1, { 0, 0 }, 498, 234, 44032 },
    { -1, { 0, 0 }, 487, 33008, 44033 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97AFE96[] = {
    { -1, { 0, 0 }, 498, 33002, 44033 },
    { -1, { 0, 0 }, 487, 33008, 44049 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97AFEB4[] = {
    { -1, { 0, 0 }, 498, 33002, 44049 },
    { -1, { 0, 0 }, 487, 33008, 44065 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97AFED2[] = {
    { -1, { 0, 0 }, 498, 33002, 44065 },
    { -1, { 0, 0 }, 487, 33008, 44081 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97AFEF0[] = {
    { -1, { 0, 0 }, 498, 33002, 44081 },
    { -1, { 0, 0 }, 489, 4358, 44032 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97AFF0E[] = {
    { -1, { 0, 0 }, 498, 4366, 44032 },
    { -1, { 0, 0 }, 489, 37102, 44033 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97AFF2C[] = {
    { -1, { 0, 0 }, 498, 37110, 44033 },
    { -1, { 0, 0 }, 489, 37102, 44049 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97AFF4A[] = {
    { -1, { 0, 0 }, 498, 37110, 44049 },
    { -1, { 0, 0 }, 489, 37102, 44065 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97AFF68[] = {
    { -1, { 0, 0 }, 498, 37110, 44065 },
    { -1, { 0, 0 }, 489, 37102, 44081 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97AFF86[] = {
    { -1, { 0, 0 }, 498, 37110, 44081 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_97AFF9C = 65;
const ax_anim gUnknown_97AFFA0[] = {
    { 1,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 1,   0,   2, { 0, 0 }, { 0, 0 } },
    { 1,   0,   3, { 0, 0 }, { 0, 0 } },
    { 1,   0,   4, { 0, 0 }, { 0, 0 } },
    { 1,   0,   5, { 0, 0 }, { 0, 0 } },
    { 1,   0,   6, { 0, 0 }, { 0, 0 } },
    { 1,   0,   7, { 0, 0 }, { 0, 0 } },
    { 1,   0,   8, { 0, 0 }, { 0, 0 } },
    { 1,   0,   9, { 0, 0 }, { 0, 0 } },
    { 1,   0,   10, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_97B0030[] = INCBIN_U32("data/effects/efob012.4bpp");
const RGB gUnknown_97B0850[] = INCBIN_U8("data/effects/efob012.pmdpal");
const ax_pose *const gUnknown_97B0890[] = {
    gUnknown_97AFE64,
    gUnknown_97AFE78,
    gUnknown_97AFE96,
    gUnknown_97AFEB4,
    gUnknown_97AFED2,
    gUnknown_97AFEF0,
    gUnknown_97AFF0E,
    gUnknown_97AFF2C,
    gUnknown_97AFF4A,
    gUnknown_97AFF68,
    gUnknown_97AFF86,
};
const ax_anim *const gUnknown_97B08BC[] = {
    gUnknown_97AFFA0,
    gUnknown_97AFFA0,
    gUnknown_97AFFA0,
    gUnknown_97AFFA0,
    gUnknown_97AFFA0,
    gUnknown_97AFFA0,
    gUnknown_97AFFA0,
    gUnknown_97AFFA0,
};
const ax_anim *const *const gUnknown_97B08DC[] = {
    gUnknown_97B08BC,
};
const EfoFileData gUnknown_97B08E0 = {
    gUnknown_97B0890,
    gUnknown_97B08DC,
    ARRAY_COUNT(gUnknown_97B08DC), // 1
    NULL,
    NULL,
    gUnknown_97B0030,
    gUnknown_97B0850,
    sizeof(gUnknown_97B0030) / 32, // 65
};
