#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_98489C4;
const SiroArchive gUnknown_98482D0 = { "SIRO", &gUnknown_98489C4 };
const ax_pose gUnknown_98482E0[] = {
    { -1, { 0, 0 }, 504, 16632, 39936 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_98482F4[] = {
    { -1, { 0, 0 }, 504, 16632, 39940 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9848308[] = {
    { -1, { 0, 0 }, 504, 16632, 39944 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_984831C[] = {
    { -1, { 0, 0 }, 504, 16632, 39948 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9848330[] = {
    { -1, { 0, 0 }, 504, 16632, 39952 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9848344[] = {
    { -1, { 0, 0 }, 504, 16632, 39956 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_9848358[] = {
    { -1, { 0, 0 }, 504, 16632, 39960 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_984836C[] = {
    { -1, { 0, 0 }, 504, 16632, 39964 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_9848380 = 32;
const ax_anim gUnknown_9848384[] = {
    { 4,   0,   0, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_984839C[] = {
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_98483B4[] = {
    { 1,   0,   2, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_98483CC[] = {
    { 1,   0,   3, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_98483E4[] = {
    { 1,   0,   4, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_98483FC[] = {
    { 1,   0,   5, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_9848414[] = {
    { 1,   0,   6, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_984842C[] = {
    { 1,   0,   7, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_9848444[] = INCBIN_U32("data/effects/efob127.4bpp");
const RGB_Struct gUnknown_9848844[] = INCBIN_U8("data/effects/efob127.pmdpal");
const ax_pose *const gUnknown_9848884[] = {
    gUnknown_98482E0,
    gUnknown_98482F4,
    gUnknown_9848308,
    gUnknown_984831C,
    gUnknown_9848330,
    gUnknown_9848344,
    gUnknown_9848358,
    gUnknown_984836C,
};
const ax_anim *const gUnknown_98488A4[] = {
    gUnknown_9848384,
    gUnknown_9848384,
    gUnknown_9848384,
    gUnknown_9848384,
    gUnknown_9848384,
    gUnknown_9848384,
    gUnknown_9848384,
    gUnknown_9848384,
};
const ax_anim *const gUnknown_98488C4[] = {
    gUnknown_984839C,
    gUnknown_984839C,
    gUnknown_984839C,
    gUnknown_984839C,
    gUnknown_984839C,
    gUnknown_984839C,
    gUnknown_984839C,
    gUnknown_984839C,
};
const ax_anim *const gUnknown_98488E4[] = {
    gUnknown_98483B4,
    gUnknown_98483B4,
    gUnknown_98483B4,
    gUnknown_98483B4,
    gUnknown_98483B4,
    gUnknown_98483B4,
    gUnknown_98483B4,
    gUnknown_98483B4,
};
const ax_anim *const gUnknown_9848904[] = {
    gUnknown_98483CC,
    gUnknown_98483CC,
    gUnknown_98483CC,
    gUnknown_98483CC,
    gUnknown_98483CC,
    gUnknown_98483CC,
    gUnknown_98483CC,
    gUnknown_98483CC,
};
const ax_anim *const gUnknown_9848924[] = {
    gUnknown_98483E4,
    gUnknown_98483E4,
    gUnknown_98483E4,
    gUnknown_98483E4,
    gUnknown_98483E4,
    gUnknown_98483E4,
    gUnknown_98483E4,
    gUnknown_98483E4,
};
const ax_anim *const gUnknown_9848944[] = {
    gUnknown_98483FC,
    gUnknown_98483FC,
    gUnknown_98483FC,
    gUnknown_98483FC,
    gUnknown_98483FC,
    gUnknown_98483FC,
    gUnknown_98483FC,
    gUnknown_98483FC,
};
const ax_anim *const gUnknown_9848964[] = {
    gUnknown_9848414,
    gUnknown_9848414,
    gUnknown_9848414,
    gUnknown_9848414,
    gUnknown_9848414,
    gUnknown_9848414,
    gUnknown_9848414,
    gUnknown_9848414,
};
const ax_anim *const gUnknown_9848984[] = {
    gUnknown_984842C,
    gUnknown_984842C,
    gUnknown_984842C,
    gUnknown_984842C,
    gUnknown_984842C,
    gUnknown_984842C,
    gUnknown_984842C,
    gUnknown_984842C,
};
const ax_anim *const *const gUnknown_98489A4[] = {
    gUnknown_98488A4,
    gUnknown_98488C4,
    gUnknown_98488E4,
    gUnknown_9848904,
    gUnknown_9848924,
    gUnknown_9848944,
    gUnknown_9848964,
    gUnknown_9848984,
};
const EfoFileData gUnknown_98489C4 = {
    gUnknown_9848884,
    gUnknown_98489A4,
    ARRAY_COUNT(gUnknown_98489A4), // 8
    NULL,
    NULL,
    gUnknown_9848444,
    gUnknown_9848844,
    sizeof(gUnknown_9848444) / 32, // 32
};
