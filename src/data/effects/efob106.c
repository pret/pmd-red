#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_982AEBC;
const SiroArchive gUnknown_982A960 = { "SIRO", &gUnknown_982AEBC };
const ax_pose gUnknown_982A970[] = {
    { -1, { 0, 0 }, 33272, 8440, 23552 },
    { -1, { 0, 0 }, 33272, 12544, 23552 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_982A98E[] = {
    { -1, { 0, 0 }, 508, 252, 23554 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_982A9A2[] = {
    { -1, { 0, 0 }, 503, 28919, 23555 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_982A9B6[] = {
    { -1, { 0, 0 }, 508, 252, 23554 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_982A9CA[] = {
    { -1, { 0, 0 }, 16888, 4344, 23559 },
    { -1, { 0, 0 }, 16896, 12536, 23559 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_982A9E8[] = {
    { -1, { 0, 0 }, 508, 252, 23554 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_982A9FC[] = {
    { -1, { 0, 0 }, 505, 20727, 23555 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_982AA10[] = {
    { -1, { 0, 0 }, 508, 252, 23554 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_982AA24[] = {
    { -1, { 0, 0 }, 33272, 248, 23552 },
    { -1, { 0, 0 }, 33272, 4352, 23552 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_982AA42[] = {
    { -1, { 0, 0 }, 508, 252, 23554 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_982AA56[] = {
    { -1, { 0, 0 }, 505, 16633, 23555 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_982AA6A[] = {
    { -1, { 0, 0 }, 508, 252, 23554 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_982AA7E[] = {
    { -1, { 0, 0 }, 16888, 248, 23559 },
    { -1, { 0, 0 }, 16896, 8440, 23559 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_982AA9C[] = {
    { -1, { 0, 0 }, 508, 252, 23554 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_982AAB0[] = {
    { -1, { 0, 0 }, 503, 24825, 23555 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_982AAC4[] = {
    { -1, { 0, 0 }, 508, 252, 23554 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_982AAD8 = 9;
const ax_anim gUnknown_982AADC[] = {
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 1,   0,   0, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   3, { 0, 0 }, { 0, 0 } },
    { 1,   0,   2, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   5, { 0, 0 }, { 0, 0 } },
    { 1,   0,   4, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   7, { 0, 0 }, { 0, 0 } },
    { 1,   0,   6, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   9, { 0, 0 }, { 0, 0 } },
    { 1,   0,   8, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   11, { 0, 0 }, { 0, 0 } },
    { 1,   0,   10, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   13, { 0, 0 }, { 0, 0 } },
    { 1,   0,   12, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   15, { 0, 0 }, { 0, 0 } },
    { 1,   0,   14, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_982AB00[] = {
    { 1,   0,   3, { 0, 0 }, { 0, 0 } },
    { 1,   0,   2, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   5, { 0, 0 }, { 0, 0 } },
    { 1,   0,   4, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   7, { 0, 0 }, { 0, 0 } },
    { 1,   0,   6, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   9, { 0, 0 }, { 0, 0 } },
    { 1,   0,   8, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   11, { 0, 0 }, { 0, 0 } },
    { 1,   0,   10, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   13, { 0, 0 }, { 0, 0 } },
    { 1,   0,   12, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   15, { 0, 0 }, { 0, 0 } },
    { 1,   0,   14, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_982AB24[] = {
    { 1,   0,   5, { 0, 0 }, { 0, 0 } },
    { 1,   0,   4, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   7, { 0, 0 }, { 0, 0 } },
    { 1,   0,   6, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   9, { 0, 0 }, { 0, 0 } },
    { 1,   0,   8, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   11, { 0, 0 }, { 0, 0 } },
    { 1,   0,   10, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   13, { 0, 0 }, { 0, 0 } },
    { 1,   0,   12, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   15, { 0, 0 }, { 0, 0 } },
    { 1,   0,   14, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_982AB48[] = {
    { 1,   0,   7, { 0, 0 }, { 0, 0 } },
    { 1,   0,   6, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   9, { 0, 0 }, { 0, 0 } },
    { 1,   0,   8, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   11, { 0, 0 }, { 0, 0 } },
    { 1,   0,   10, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   13, { 0, 0 }, { 0, 0 } },
    { 1,   0,   12, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   15, { 0, 0 }, { 0, 0 } },
    { 1,   0,   14, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_982AB6C[] = {
    { 1,   0,   9, { 0, 0 }, { 0, 0 } },
    { 1,   0,   8, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   11, { 0, 0 }, { 0, 0 } },
    { 1,   0,   10, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   13, { 0, 0 }, { 0, 0 } },
    { 1,   0,   12, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   15, { 0, 0 }, { 0, 0 } },
    { 1,   0,   14, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_982AB90[] = {
    { 1,   0,   11, { 0, 0 }, { 0, 0 } },
    { 1,   0,   10, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   13, { 0, 0 }, { 0, 0 } },
    { 1,   0,   12, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   15, { 0, 0 }, { 0, 0 } },
    { 1,   0,   14, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_982ABB4[] = {
    { 1,   0,   13, { 0, 0 }, { 0, 0 } },
    { 1,   0,   12, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   15, { 0, 0 }, { 0, 0 } },
    { 1,   0,   14, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_982ABD8[] = {
    { 1,   0,   15, { 0, 0 }, { 0, 0 } },
    { 1,   0,   14, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_982ABFC[] = INCBIN_U32("data/effects/efob106.4bpp");
const RGB gUnknown_982AD1C[] = INCBIN_U8("data/effects/efob106.pmdpal");
const ax_pose *const gUnknown_982AD5C[] = {
    gUnknown_982A970,
    gUnknown_982A98E,
    gUnknown_982A9A2,
    gUnknown_982A9B6,
    gUnknown_982A9CA,
    gUnknown_982A9E8,
    gUnknown_982A9FC,
    gUnknown_982AA10,
    gUnknown_982AA24,
    gUnknown_982AA42,
    gUnknown_982AA56,
    gUnknown_982AA6A,
    gUnknown_982AA7E,
    gUnknown_982AA9C,
    gUnknown_982AAB0,
    gUnknown_982AAC4,
};
const ax_anim *const gUnknown_982AD9C[] = {
    gUnknown_982AADC,
    gUnknown_982AADC,
    gUnknown_982AADC,
    gUnknown_982AADC,
    gUnknown_982AADC,
    gUnknown_982AADC,
    gUnknown_982AADC,
    gUnknown_982AADC,
};
const ax_anim *const gUnknown_982ADBC[] = {
    gUnknown_982AB00,
    gUnknown_982AB00,
    gUnknown_982AB00,
    gUnknown_982AB00,
    gUnknown_982AB00,
    gUnknown_982AB00,
    gUnknown_982AB00,
    gUnknown_982AB00,
};
const ax_anim *const gUnknown_982ADDC[] = {
    gUnknown_982AB24,
    gUnknown_982AB24,
    gUnknown_982AB24,
    gUnknown_982AB24,
    gUnknown_982AB24,
    gUnknown_982AB24,
    gUnknown_982AB24,
    gUnknown_982AB24,
};
const ax_anim *const gUnknown_982ADFC[] = {
    gUnknown_982AB48,
    gUnknown_982AB48,
    gUnknown_982AB48,
    gUnknown_982AB48,
    gUnknown_982AB48,
    gUnknown_982AB48,
    gUnknown_982AB48,
    gUnknown_982AB48,
};
const ax_anim *const gUnknown_982AE1C[] = {
    gUnknown_982AB6C,
    gUnknown_982AB6C,
    gUnknown_982AB6C,
    gUnknown_982AB6C,
    gUnknown_982AB6C,
    gUnknown_982AB6C,
    gUnknown_982AB6C,
    gUnknown_982AB6C,
};
const ax_anim *const gUnknown_982AE3C[] = {
    gUnknown_982AB90,
    gUnknown_982AB90,
    gUnknown_982AB90,
    gUnknown_982AB90,
    gUnknown_982AB90,
    gUnknown_982AB90,
    gUnknown_982AB90,
    gUnknown_982AB90,
};
const ax_anim *const gUnknown_982AE5C[] = {
    gUnknown_982ABB4,
    gUnknown_982ABB4,
    gUnknown_982ABB4,
    gUnknown_982ABB4,
    gUnknown_982ABB4,
    gUnknown_982ABB4,
    gUnknown_982ABB4,
    gUnknown_982ABB4,
};
const ax_anim *const gUnknown_982AE7C[] = {
    gUnknown_982ABD8,
    gUnknown_982ABD8,
    gUnknown_982ABD8,
    gUnknown_982ABD8,
    gUnknown_982ABD8,
    gUnknown_982ABD8,
    gUnknown_982ABD8,
    gUnknown_982ABD8,
};
const ax_anim *const *const gUnknown_982AE9C[] = {
    gUnknown_982AD9C,
    gUnknown_982ADBC,
    gUnknown_982ADDC,
    gUnknown_982ADFC,
    gUnknown_982AE1C,
    gUnknown_982AE3C,
    gUnknown_982AE5C,
    gUnknown_982AE7C,
};
const EfoFileData gUnknown_982AEBC = {
    gUnknown_982AD5C,
    gUnknown_982AE9C,
    ARRAY_COUNT(gUnknown_982AE9C), // 8
    NULL,
    NULL,
    gUnknown_982ABFC,
    gUnknown_982AD1C,
    sizeof(gUnknown_982ABFC) / 32, // 9
};
