#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_98219FC;
const SiroArchive gUnknown_98216EC = { "SIRO", &gUnknown_98219FC };
const ax_pose gUnknown_98216FC[] = {
    { -1, { 0, 0 }, 482, 16632, 11264 },
    { -1, { 0, 0 }, 498, 16632, 11268 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_982171A[] = {
    { -1, { 0, 0 }, 487, 16632, 11264 },
    { -1, { 0, 0 }, 498, 16632, 11268 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9821738[] = {
    { -1, { 0, 0 }, 492, 16632, 11264 },
    { -1, { 0, 0 }, 498, 16632, 11268 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9821756[] = {
    { -1, { 0, 0 }, 498, 16632, 11272 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_982176A[] = {
    { -1, { 0, 0 }, 502, 252, 11276 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_9821780 = 13;
const ax_anim gUnknown_9821784[] = {
    { 2,   0,   3, { 0, 0 }, { 0, 0 } },
    { 1,   0,   2, { 0, 0 }, { 0, 0 } },
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 2,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   4, { 0, 0 }, { 0, 0 } },
    { 1,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   4, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_98217E4[] = INCBIN_U32("data/effects/efob098.4bpp");
const RGB gUnknown_9821984[] = INCBIN_U8("data/effects/efob098.pmdpal");
const ax_pose *const gUnknown_98219C4[] = {
    gUnknown_98216FC,
    gUnknown_982171A,
    gUnknown_9821738,
    gUnknown_9821756,
    gUnknown_982176A,
};
const ax_anim *const gUnknown_98219D8[] = {
    gUnknown_9821784,
    gUnknown_9821784,
    gUnknown_9821784,
    gUnknown_9821784,
    gUnknown_9821784,
    gUnknown_9821784,
    gUnknown_9821784,
    gUnknown_9821784,
};
const ax_anim *const *const gUnknown_98219F8[] = {
    gUnknown_98219D8,
};
const EfoFileData gUnknown_98219FC = {
    gUnknown_98219C4,
    gUnknown_98219F8,
    ARRAY_COUNT(gUnknown_98219F8), // 1
    NULL,
    NULL,
    gUnknown_98217E4,
    gUnknown_9821984,
    sizeof(gUnknown_98217E4) / 32, // 13
};
