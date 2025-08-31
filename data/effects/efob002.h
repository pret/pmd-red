#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_979ECA4;
const SiroArchive gUnknown_979DCF4 = { "SIRO", &gUnknown_979ECA4 };
const ax_pose gUnknown_979DD04[] = {
    { -1, { 0, 0 }, 500, 17648, 19456 },
    { -1, { 0, 0 }, 500, 21760, 19456 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_979DD22[] = {
    { -1, { 0, 0 }, 484, 34032, 19460 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_979DD36[] = {
    { -1, { 0, 0 }, 469, 17660, 19476 },
    { -1, { 0, 0 }, 484, 34032, 19480 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_979DD54[] = {
    { -1, { 0, 0 }, 16853, 34036, 19496 },
    { -1, { 0, 0 }, 484, 34032, 19504 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_979DD72[] = {
    { -1, { 0, 0 }, 16870, 34039, 19520 },
    { -1, { 0, 0 }, 16866, 38121, 19520 },
    { -1, { 0, 0 }, 16881, 34034, 19520 },
    { -1, { 0, 0 }, 16855, 34032, 19520 },
    { -1, { 0, 0 }, 16880, 38121, 19520 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_979DDAE[] = {
    { -1, { 0, 0 }, 16867, 34040, 19528 },
    { -1, { 0, 0 }, 16863, 38119, 19528 },
    { -1, { 0, 0 }, 16876, 34034, 19528 },
    { -1, { 0, 0 }, 16853, 34032, 19528 },
    { -1, { 0, 0 }, 16875, 38121, 19528 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_979DDEA[] = {
    { -1, { 0, 0 }, 16866, 34041, 19536 },
    { -1, { 0, 0 }, 16862, 38118, 19536 },
    { -1, { 0, 0 }, 16874, 34034, 19536 },
    { -1, { 0, 0 }, 16852, 34032, 19536 },
    { -1, { 0, 0 }, 16873, 38121, 19536 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_979DE26[] = {
    { -1, { 0, 0 }, 16865, 34042, 19544 },
    { -1, { 0, 0 }, 16861, 38117, 19544 },
    { -1, { 0, 0 }, 16873, 34034, 19544 },
    { -1, { 0, 0 }, 16851, 34032, 19544 },
    { -1, { 0, 0 }, 16872, 38120, 19544 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_979DE62[] = {
    { -1, { 0, 0 }, 16864, 34043, 19552 },
    { -1, { 0, 0 }, 16860, 38116, 19552 },
    { -1, { 0, 0 }, 16872, 34035, 19552 },
    { -1, { 0, 0 }, 16850, 34032, 19552 },
    { -1, { 0, 0 }, 16871, 38119, 19552 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_979DEA0 = 104;
const ax_anim gUnknown_979DEA4[] = {
    { 4,   0,   0, { 0, 0 }, { 0, 0 } },
    { 4,   0,   1, { 0, 0 }, { 0, 0 } },
    { 4,   0,   2, { 0, 0 }, { 0, 0 } },
    { 4,   0,   3, { 0, 0 }, { 0, 0 } },
    { 4,   0,   4, { 0, 0 }, { 0, 0 } },
    { 4,   0,   5, { 0, 0 }, { 0, 0 } },
    { 4,   0,   6, { 0, 0 }, { 0, 0 } },
    { 4,   0,   7, { 0, 0 }, { 0, 0 } },
    { 4,   0,   8, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_979DF1C[] = INCBIN_U32("data/effects/efob002.4bpp");
const RGB gUnknown_979EC1C[] = INCBIN_U8("data/effects/efob002.pmdpal");
const ax_pose *gUnknown_979EC5C[] = {
    gUnknown_979DD04,
    gUnknown_979DD22,
    gUnknown_979DD36,
    gUnknown_979DD54,
    gUnknown_979DD72,
    gUnknown_979DDAE,
    gUnknown_979DDEA,
    gUnknown_979DE26,
    gUnknown_979DE62,
};
const ax_anim *gUnknown_979EC80[] = {
    gUnknown_979DEA4,
    gUnknown_979DEA4,
    gUnknown_979DEA4,
    gUnknown_979DEA4,
    gUnknown_979DEA4,
    gUnknown_979DEA4,
    gUnknown_979DEA4,
    gUnknown_979DEA4,
};
const ax_anim *const *gUnknown_979ECA0[] = {
    gUnknown_979EC80,
};
const EfoFileData gUnknown_979ECA4 = {
    gUnknown_979EC5C,
    gUnknown_979ECA0,
    ARRAY_COUNT(gUnknown_979ECA0), // 1
    NULL,
    NULL,
    gUnknown_979DF1C,
    gUnknown_979EC1C,
    sizeof(gUnknown_979DF1C) / 32, // 104
};
