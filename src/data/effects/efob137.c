#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_9854CF0;
const SiroArchive gUnknown_98549B8 = { "SIRO", &gUnknown_9854CF0 };
const ax_pose gUnknown_98549C8[] = {
    { -1, { 0, 0 }, 508, 252, 35840 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_98549DC[] = {
    { -1, { 0, 0 }, 508, 252, 35841 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_98549F0[] = {
    { -1, { 0, 0 }, 508, 252, 35842 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9854A04[] = {
    { -1, { 0, 0 }, 508, 252, 35843 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9854A18[] = {
    { -1, { 0, 0 }, 16888, 251, 35844 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9854A2C[] = {
    { -1, { 0, 0 }, 16888, 251, 35846 },
    { -1, { 0, 0 }, 16888, 239, 35844 },
    { -1, { 0, 0 }, 16888, 262, 35844 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9854A54[] = {
    { -1, { 0, 0 }, 16888, 251, 35844 },
    { -1, { 0, 0 }, 16888, 239, 35846 },
    { -1, { 0, 0 }, 16888, 262, 35846 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9854A7C[] = {
    { -1, { 0, 0 }, 16888, 239, 35844 },
    { -1, { 0, 0 }, 16888, 262, 35844 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_9854A9C = 8;
const ax_anim gUnknown_9854AA0[] = {
    { 1,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 1,   0,   2, { 0, 0 }, { 0, 0 } },
    { 1,   0,   3, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_9854ADC[] = {
    { 4,   0,   4, { 0, 0 }, { 0, 0 } },
    { 4,   0,   5, { 0, 0 }, { 0, 0 } },
    { 4,   0,   6, { 0, 0 }, { 0, 0 } },
    { 4,   0,   5, { 0, 0 }, { 0, 0 } },
    { 4,   0,   6, { 0, 0 }, { 0, 0 } },
    { 4,   0,   5, { 0, 0 }, { 0, 0 } },
    { 4,   0,   6, { 0, 0 }, { 0, 0 } },
    { 4,   0,   7, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_9854B48[] = INCBIN_U32("data/effects/efob137.4bpp");
const RGB gUnknown_9854C48[] = INCBIN_U8("data/effects/efob137.pmdpal");
const ax_pose *const gUnknown_9854C88[] = {
    gUnknown_98549C8,
    gUnknown_98549DC,
    gUnknown_98549F0,
    gUnknown_9854A04,
    gUnknown_9854A18,
    gUnknown_9854A2C,
    gUnknown_9854A54,
    gUnknown_9854A7C,
};
const ax_anim *const gUnknown_9854CA8[] = {
    gUnknown_9854AA0,
    gUnknown_9854AA0,
    gUnknown_9854AA0,
    gUnknown_9854AA0,
    gUnknown_9854AA0,
    gUnknown_9854AA0,
    gUnknown_9854AA0,
    gUnknown_9854AA0,
};
const ax_anim *const gUnknown_9854CC8[] = {
    gUnknown_9854ADC,
    gUnknown_9854ADC,
    gUnknown_9854ADC,
    gUnknown_9854ADC,
    gUnknown_9854ADC,
    gUnknown_9854ADC,
    gUnknown_9854ADC,
    gUnknown_9854ADC,
};
const ax_anim *const *const gUnknown_9854CE8[] = {
    gUnknown_9854CA8,
    gUnknown_9854CC8,
};
const EfoFileData gUnknown_9854CF0 = {
    gUnknown_9854C88,
    gUnknown_9854CE8,
    ARRAY_COUNT(gUnknown_9854CE8), // 2
    NULL,
    NULL,
    gUnknown_9854B48,
    gUnknown_9854C48,
    sizeof(gUnknown_9854B48) / 32, // 8
};
