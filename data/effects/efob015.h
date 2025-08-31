#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_97B6F0C;
const SiroArchive gUnknown_97B6924 = { "SIRO", &gUnknown_97B6F0C };
const ax_pose gUnknown_97B6934[] = {
    { -1, { 0, 0 }, 496, 16632, 27648 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97B6948[] = {
    { -1, { 0, 0 }, 496, 16632, 27652 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97B695C[] = {
    { -1, { 0, 0 }, 496, 16632, 27656 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97B6970[] = {
    { -1, { 0, 0 }, 496, 16632, 27660 },
    { -1, { 0, 0 }, 496, 16632, 27656 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97B698E[] = {
    { -1, { 0, 0 }, 496, 16633, 27664 },
    { -1, { 0, 0 }, 496, 16632, 27656 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97B69AC[] = {
    { -1, { 0, 0 }, 500, 252, 27668 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97B69C0[] = {
    { -1, { 0, 0 }, 504, 16632, 27669 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97B69D4[] = {
    { -1, { 0, 0 }, 504, 16632, 27673 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_97B69E8 = 29;
const ax_anim gUnknown_97B69EC[] = {
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 2,   0,   2, { 0, 0 }, { 0, 0 } },
    { 5,   0,   3, { 0, 0 }, { 0, 0 } },
    { 5,   0,   4, { 0, 0 }, { 0, 0 } },
    { 5,   0,   3, { 0, 0 }, { 0, 0 } },
    { 8,   0,   4, { 0, 0 }, { 0, 0 } },
    { 2,   0,   2, { 0, 0 }, { 0, 0 } },
    { 2,   0,   1, { 0, 0 }, { 0, 0 } },
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
    { 4,   0,   7, { 14, -16 }, { 0, 0 } },
    { 5,   0,   6, { 14, -16 }, { 0, 0 } },
    { 12,   0,   7, { 14, -16 }, { 0, 0 } },
    { 4,   0,   7, { -14, -16 }, { 0, 0 } },
    { 5,   0,   6, { -14, -16 }, { 0, 0 } },
    { 12,   0,   7, { -14, -16 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_97B6A70[] = {
    { 4,   0,   7, { 14, -16 }, { 0, 0 } },
    { 5,   0,   6, { 14, -16 }, { 0, 0 } },
    { 12,   0,   7, { 14, -16 }, { 0, 0 } },
    { 4,   0,   7, { -14, -16 }, { 0, 0 } },
    { 5,   0,   6, { -14, -16 }, { 0, 0 } },
    { 12,   0,   7, { -14, -16 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_97B6AC4[] = INCBIN_U32("data/effects/efob015.4bpp");
const RGB gUnknown_97B6E64[] = INCBIN_U8("data/effects/efob015.pmdpal");
const ax_pose *gUnknown_97B6EA4[] = {
    gUnknown_97B6934,
    gUnknown_97B6948,
    gUnknown_97B695C,
    gUnknown_97B6970,
    gUnknown_97B698E,
    gUnknown_97B69AC,
    gUnknown_97B69C0,
    gUnknown_97B69D4,
};
const ax_anim *gUnknown_97B6EC4[] = {
    gUnknown_97B69EC,
    gUnknown_97B69EC,
    gUnknown_97B69EC,
    gUnknown_97B69EC,
    gUnknown_97B69EC,
    gUnknown_97B69EC,
    gUnknown_97B69EC,
    gUnknown_97B69EC,
};
const ax_anim *gUnknown_97B6EE4[] = {
    gUnknown_97B6A70,
    gUnknown_97B6A70,
    gUnknown_97B6A70,
    gUnknown_97B6A70,
    gUnknown_97B6A70,
    gUnknown_97B6A70,
    gUnknown_97B6A70,
    gUnknown_97B6A70,
};
const ax_anim *const *gUnknown_97B6F04[] = {
    gUnknown_97B6EC4,
    gUnknown_97B6EE4,
};
const EfoFileData gUnknown_97B6F0C = {
    gUnknown_97B6EA4,
    gUnknown_97B6F04,
    ARRAY_COUNT(gUnknown_97B6F04), // 2
    NULL,
    NULL,
    gUnknown_97B6AC4,
    gUnknown_97B6E64,
    sizeof(gUnknown_97B6AC4) / 32, // 29
};
