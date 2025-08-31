#include "global.h"
#include "decompress_sir.h"
#include "structs/str_8009A7C.h"
const struct EfoFileData gUnknown_9817530;
const SiroArchive gUnknown_98170B4 = { "SIRO", &gUnknown_9817530 };
const ax_pose gUnknown_98170C4[] = {
    { -1, { 0, 0 }, 505, 247, 31744 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_98170D8[] = {
    { -1, { 0, 0 }, 508, 16628, 31745 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_98170EC[] = {
    { -1, { 0, 0 }, 16891, 33012, 31749 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9817100[] = {
    { -1, { 0, 0 }, 33257, 33020, 31757 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9817114[] = {
    { -1, { 0, 0 }, 493, 16630, 31765 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9817128[] = {
    { -1, { 0, 0 }, 494, 245, 31744 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_981713C = 25;
const ax_anim gUnknown_9817140[] = {
    { 1,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 3,   0,   2, { 0, 0 }, { 0, 0 } },
    { 2,   0,   3, { 0, 0 }, { 0, 0 } },
    { 2,   0,   4, { 0, 0 }, { 0, 0 } },
    { 1,   0,   5, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_9817194[] = INCBIN_U32("data/effects/efob088.4bpp");
const RGB gUnknown_98174B4[] = INCBIN_U8("data/effects/efob088.pmdpal");
const ax_pose *gUnknown_98174F4[] = {
    gUnknown_98170C4,
    gUnknown_98170D8,
    gUnknown_98170EC,
    gUnknown_9817100,
    gUnknown_9817114,
    gUnknown_9817128,
};
const ax_anim *gUnknown_981750C[] = {
    gUnknown_9817140,
    gUnknown_9817140,
    gUnknown_9817140,
    gUnknown_9817140,
    gUnknown_9817140,
    gUnknown_9817140,
    gUnknown_9817140,
    gUnknown_9817140,
};
const ax_anim *const *gUnknown_981752C[] = {
    gUnknown_981750C,
};
const EfoFileData gUnknown_9817530 = {
    gUnknown_98174F4,
    gUnknown_981752C,
    ARRAY_COUNT(gUnknown_981752C), // 1
    NULL,
    NULL,
    gUnknown_9817194,
    gUnknown_98174B4,
    ARRAY_COUNT(gUnknown_9817194) / 16, // 25
};
