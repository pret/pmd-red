#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfbFileData gUnknown_97547C4;
const SiroArchive gUnknown_974BE54 = { "SIRO", &gUnknown_97547C4 };
const u16 gUnknown_974BE64[] = {
    0, 0, 33, 27, 4, 1, 2, 0, 0, 0,
    INCBIN_U16("data/effects/efbg001_000.bin"),
};
const u16 gUnknown_974C56E[] = {
    33, 0, 33, 27, 4, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg001_001.bin"),
};
const u16 gUnknown_974CC78[] = {
    66, 0, 33, 27, 4, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg001_002.bin"),
};
const u16 gUnknown_974D382[] = {
    99, 0, 33, 27, 4, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg001_003.bin"),
};
const u16 gUnknown_974DA8C[] = {
    132, 0, 33, 27, 4, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg001_004.bin"),
};
const u16 gUnknown_974E196[] = {
    165, 0, 33, 27, 4, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg001_005.bin"),
};
const u16 gUnknown_974E8A0[] = {
    198, 0, 33, 27, 4, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg001_006.bin"),
};
const u16 gUnknown_974EFAA[] = {
    231, 0, 33, 27, 4, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg001_007.bin"),
};
const u16 gUnknown_974F6B4[] = {
    0, 27, 33, 27, 4, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg001_008.bin"),
};
const u16 gUnknown_974FDBE[] = {
    33, 27, 33, 27, 4, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg001_009.bin"),
};
const u16 gUnknown_97504C8[] = {
    66, 27, 33, 27, 4, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg001_010.bin"),
};
const u16 gUnknown_9750BD2[] = {
    99, 27, 33, 27, 4, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg001_011.bin"),
};
const u16 gUnknown_97512DC[] = {
    132, 27, 33, 27, 4, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg001_012.bin"),
};
const u16 gUnknown_97519E6[] = {
    165, 27, 33, 27, 4, 0, 65534, 0, 0, 0,
    INCBIN_U16("data/effects/efbg001_013.bin"),
};
const u16 gUnknown_97520F0[] = {
    198, 27, 33, 27, 4, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg001_014.bin"),
};
const u16 gUnknown_97527FA[] = {
    231, 27, 33, 27, 4, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg001_015.bin"),
};
const u16 *gUnknown_9752F04[] = {
    gUnknown_974BE64,
    gUnknown_974C56E,
    gUnknown_974CC78,
    gUnknown_974D382,
    gUnknown_974DA8C,
    gUnknown_974E196,
    gUnknown_974E8A0,
    gUnknown_974EFAA,
    gUnknown_974F6B4,
    gUnknown_974FDBE,
    gUnknown_97504C8,
    gUnknown_9750BD2,
    gUnknown_97512DC,
    gUnknown_97519E6,
    gUnknown_97520F0,
    gUnknown_97527FA,
};
const RGB gUnknown_9752F44[] = INCBIN_U8("data/effects/efbg001.pmdpal");
const u32 gUnknown_9753344[] = INCBIN_U32("data/effects/efbg001.4bpp");
const struct EfbFileData gUnknown_97547C4 = {
    ARRAY_COUNT(gUnknown_9752F04), // 16
    gUnknown_9752F04,
    sizeof(gUnknown_9753344) / 32 - 1, // 163
    gUnknown_9753344,
    gUnknown_9752F44,
};
