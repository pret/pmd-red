#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_97D339C;
const SiroArchive gUnknown_97D2DF8 = { "SIRO", &gUnknown_97D339C };
const ax_pose gUnknown_97D2E08[] = {
    { -1, { 0, 0 }, 502, 16632, 52224 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97D2E1C[] = {
    { -1, { 0, 0 }, 502, 16632, 52228 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97D2E30[] = {
    { -1, { 0, 0 }, 502, 16632, 52232 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97D2E44[] = {
    { -1, { 0, 0 }, 502, 16632, 52236 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97D2E58[] = {
    { -1, { 0, 0 }, 502, 16632, 52240 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97D2E6C[] = {
    { -1, { 0, 0 }, 502, 16632, 52244 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97D2E80[] = {
    { -1, { 0, 0 }, 502, 16632, 52248 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97D2E94[] = {
    { -1, { 0, 0 }, 502, 16632, 52252 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_97D2EA8 = 32;
const ax_anim gUnknown_97D2EAC[] = {
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 2,   0,   2, { 0, 0 }, { 0, 0 } },
    { 2,   0,   3, { 0, 0 }, { 0, 0 } },
    { 2,   0,   4, { 0, 0 }, { 0, 0 } },
    { 2,   0,   5, { 0, 0 }, { 0, 0 } },
    { 2,   0,   6, { 0, 0 }, { 0, 0 } },
    { 2,   0,   7, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_97D2F18[] = INCBIN_U32("data/effects/efob034.4bpp");
const RGB gUnknown_97D3318[] = INCBIN_U8("data/effects/efob034.pmdpal");
const ax_pose *const gUnknown_97D3358[] = {
    gUnknown_97D2E08,
    gUnknown_97D2E1C,
    gUnknown_97D2E30,
    gUnknown_97D2E44,
    gUnknown_97D2E58,
    gUnknown_97D2E6C,
    gUnknown_97D2E80,
    gUnknown_97D2E94,
};
const ax_anim *const gUnknown_97D3378[] = {
    gUnknown_97D2EAC,
    gUnknown_97D2EAC,
    gUnknown_97D2EAC,
    gUnknown_97D2EAC,
    gUnknown_97D2EAC,
    gUnknown_97D2EAC,
    gUnknown_97D2EAC,
    gUnknown_97D2EAC,
};
const ax_anim *const *const gUnknown_97D3398[] = {
    gUnknown_97D3378,
};
const EfoFileData gUnknown_97D339C = {
    gUnknown_97D3358,
    gUnknown_97D3398,
    ARRAY_COUNT(gUnknown_97D3398), // 1
    NULL,
    NULL,
    gUnknown_97D2F18,
    gUnknown_97D3318,
    sizeof(gUnknown_97D2F18) / 32, // 32
};
