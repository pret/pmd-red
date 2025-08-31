#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_982B0A8;
const SiroArchive gUnknown_982AEDC = { "SIRO", &gUnknown_982B0A8 };
const ax_pose gUnknown_982AEEC[] = {
    { -1, { 0, 0 }, 504, 16632, 19456 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_982AF00[] = {
    { -1, { 0, 0 }, 504, 16632, 19460 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_982AF14 = 8;
const ax_anim gUnknown_982AF18[] = {
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_982AF3C[] = INCBIN_U32("data/effects/efob107.4bpp");
const RGB gUnknown_982B03C[] = INCBIN_U8("data/effects/efob107.pmdpal");
const ax_pose *const gUnknown_982B07C[] = {
    gUnknown_982AEEC,
    gUnknown_982AF00,
};
const ax_anim *const gUnknown_982B084[] = {
    gUnknown_982AF18,
    gUnknown_982AF18,
    gUnknown_982AF18,
    gUnknown_982AF18,
    gUnknown_982AF18,
    gUnknown_982AF18,
    gUnknown_982AF18,
    gUnknown_982AF18,
};
const ax_anim *const *const gUnknown_982B0A4[] = {
    gUnknown_982B084,
};
const EfoFileData gUnknown_982B0A8 = {
    gUnknown_982B07C,
    gUnknown_982B0A4,
    ARRAY_COUNT(gUnknown_982B0A4), // 1
    NULL,
    NULL,
    gUnknown_982AF3C,
    gUnknown_982B03C,
    sizeof(gUnknown_982AF3C) / 32, // 8
};
