#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_9838A94;
const SiroArchive gUnknown_9838678 = { "SIRO", &gUnknown_9838A94 };
const ax_pose gUnknown_9838688[] = {
    { -1, { 0, 0 }, 504, 244, 35840 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_983869C[] = {
    { -1, { 0, 0 }, 16889, 16624, 35841 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_98386B0[] = {
    { -1, { 0, 0 }, 16888, 33008, 35845 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_98386C4[] = {
    { -1, { 0, 0 }, 16888, 33008, 35853 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_98386D8[] = {
    { -1, { 0, 0 }, 508, 252, 35861 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_98386EC = 22;
const ax_anim gUnknown_98386F0[] = {
    { 3,   0,   0, { 0, 0 }, { 0, 0 } },
    { 3,   0,   1, { 0, 0 }, { 0, 0 } },
    { 3,   0,   2, { 0, 0 }, { 0, 0 } },
    { 6,   0,   3, { 0, 0 }, { 0, 0 } },
    { 1,   0,   4, { 0, 0 }, { 0, 0 } },
    { 1,   0,   3, { 0, 0 }, { 0, 0 } },
    { 1,   0,   4, { 0, 0 }, { 0, 0 } },
    { 1,   0,   3, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_983875C[] = INCBIN_U32("data/effects/efob112.4bpp");
const RGB_Struct gUnknown_9838A1C[] = INCBIN_U8("data/effects/efob112.pmdpal");
const ax_pose *const gUnknown_9838A5C[] = {
    gUnknown_9838688,
    gUnknown_983869C,
    gUnknown_98386B0,
    gUnknown_98386C4,
    gUnknown_98386D8,
};
const ax_anim *const gUnknown_9838A70[] = {
    gUnknown_98386F0,
    gUnknown_98386F0,
    gUnknown_98386F0,
    gUnknown_98386F0,
    gUnknown_98386F0,
    gUnknown_98386F0,
    gUnknown_98386F0,
    gUnknown_98386F0,
};
const ax_anim *const *const gUnknown_9838A90[] = {
    gUnknown_9838A70,
};
const EfoFileData gUnknown_9838A94 = {
    gUnknown_9838A5C,
    gUnknown_9838A90,
    ARRAY_COUNT(gUnknown_9838A90), // 1
    NULL,
    NULL,
    gUnknown_983875C,
    gUnknown_9838A1C,
    sizeof(gUnknown_983875C) / 32, // 22
};
