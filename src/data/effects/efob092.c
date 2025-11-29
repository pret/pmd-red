#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_981AFA8;
const SiroArchive gUnknown_981AC60 = { "SIRO", &gUnknown_981AFA8 };
const ax_pose gUnknown_981AC70[] = {
    { -1, { 0, 0 }, 500, 16628, 11264 },
    { -1, { 0, 0 }, 33268, 260, 11268 },
    { -1, { 0, 0 }, 16900, 244, 11270 },
    { -1, { 0, 0 }, 516, 260, 11272 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_981ACA2[] = {
    { -1, { 0, 0 }, 500, 16628, 11273 },
    { -1, { 0, 0 }, 33268, 260, 11277 },
    { -1, { 0, 0 }, 16900, 244, 11279 },
    { -1, { 0, 0 }, 516, 260, 11281 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_981ACD4 = 18;
const ax_anim gUnknown_981ACD8[] = {
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_981ACFC[] = INCBIN_U32("data/effects/efob092.4bpp");
const RGB_Struct gUnknown_981AF3C[] = INCBIN_U8("data/effects/efob092.pmdpal");
const ax_pose *const gUnknown_981AF7C[] = {
    gUnknown_981AC70,
    gUnknown_981ACA2,
};
const ax_anim *const gUnknown_981AF84[] = {
    gUnknown_981ACD8,
    gUnknown_981ACD8,
    gUnknown_981ACD8,
    gUnknown_981ACD8,
    gUnknown_981ACD8,
    gUnknown_981ACD8,
    gUnknown_981ACD8,
    gUnknown_981ACD8,
};
const ax_anim *const *const gUnknown_981AFA4[] = {
    gUnknown_981AF84,
};
const EfoFileData gUnknown_981AFA8 = {
    gUnknown_981AF7C,
    gUnknown_981AFA4,
    ARRAY_COUNT(gUnknown_981AFA4), // 1
    NULL,
    NULL,
    gUnknown_981ACFC,
    gUnknown_981AF3C,
    sizeof(gUnknown_981ACFC) / 32, // 18
};
