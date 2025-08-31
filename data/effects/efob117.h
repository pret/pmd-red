#include "global.h"
#include "decompress_sir.h"
#include "structs/str_8009A7C.h"
const struct EfoFileData gUnknown_983D5DC;
const SiroArchive gUnknown_983D410 = { "SIRO", &gUnknown_983D5DC };
const ax_pose gUnknown_983D420[] = {
    { -1, { 0, 0 }, 504, 16632, 19456 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_983D434[] = {
    { -1, { 0, 0 }, 504, 16632, 19460 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_983D448 = 8;
const ax_anim gUnknown_983D44C[] = {
    { 1,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_983D470[] = INCBIN_U32("data/effects/efob117.4bpp");
const RGB gUnknown_983D570[] = INCBIN_U8("data/effects/efob117.pmdpal");
const ax_pose *gUnknown_983D5B0[] = {
    gUnknown_983D420,
    gUnknown_983D434,
};
const ax_anim *gUnknown_983D5B8[] = {
    gUnknown_983D44C,
    gUnknown_983D44C,
    gUnknown_983D44C,
    gUnknown_983D44C,
    gUnknown_983D44C,
    gUnknown_983D44C,
    gUnknown_983D44C,
    gUnknown_983D44C,
};
const ax_anim *const *gUnknown_983D5D8[] = {
    gUnknown_983D5B8,
};
const EfoFileData gUnknown_983D5DC = {
    gUnknown_983D5B0,
    gUnknown_983D5D8,
    ARRAY_COUNT(gUnknown_983D5D8), // 1
    NULL,
    NULL,
    gUnknown_983D470,
    gUnknown_983D570,
    ARRAY_COUNT(gUnknown_983D470) / 16, // 8
};
