#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_9815E7C;
const SiroArchive gUnknown_9815C0C = { "SIRO", &gUnknown_9815E7C };
const ax_pose gUnknown_9815C1C[] = {
    { -1, { 0, 0 }, 502, 16632, 3072 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9815C30[] = {
    { -1, { 0, 0 }, 502, 16632, 3076 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9815C44[] = {
    { -1, { 0, 0 }, 502, 16632, 3080 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_9815C58 = 12;
const ax_anim gUnknown_9815C5C[] = {
    { 3,   0,   0, { 0, -1 }, { 0, 0 } },
    { 4,   0,   1, { 0, 0 }, { 0, 0 } },
    { 4,   0,   2, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_9815C8C[] = INCBIN_U32("data/effects/efob086.4bpp");
const RGB gUnknown_9815E0C[] = INCBIN_U8("data/effects/efob086.pmdpal");
const ax_pose *const gUnknown_9815E4C[] = {
    gUnknown_9815C1C,
    gUnknown_9815C30,
    gUnknown_9815C44,
};
const ax_anim *const gUnknown_9815E58[] = {
    gUnknown_9815C5C,
    gUnknown_9815C5C,
    gUnknown_9815C5C,
    gUnknown_9815C5C,
    gUnknown_9815C5C,
    gUnknown_9815C5C,
    gUnknown_9815C5C,
    gUnknown_9815C5C,
};
const ax_anim *const *const gUnknown_9815E78[] = {
    gUnknown_9815E58,
};
const EfoFileData gUnknown_9815E7C = {
    gUnknown_9815E4C,
    gUnknown_9815E78,
    ARRAY_COUNT(gUnknown_9815E78), // 1
    NULL,
    NULL,
    gUnknown_9815C8C,
    gUnknown_9815E0C,
    sizeof(gUnknown_9815C8C) / 32, // 12
};
