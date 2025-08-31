#include "global.h"
#include "decompress_sir.h"
#include "structs/str_8009A7C.h"
const struct Struct_8009A7C gUnknown_9783EF0;
const SiroArchive gUnknown_9773B00 = { "SIRO", &gUnknown_9783EF0 };
const u16 gUnknown_9773B10[] = {
    0, 0, 33, 27, 2, 1, 2, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_000.bin"),
};
const u16 gUnknown_977421A[] = {
    33, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_001.bin"),
};
const u16 gUnknown_9774924[] = {
    66, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_002.bin"),
};
const u16 gUnknown_977502E[] = {
    99, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_003.bin"),
};
const u16 gUnknown_9775738[] = {
    132, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_004.bin"),
};
const u16 gUnknown_9775E42[] = {
    165, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_005.bin"),
};
const u16 gUnknown_977654C[] = {
    198, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_006.bin"),
};
const u16 gUnknown_9776C56[] = {
    231, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_007.bin"),
};
const u16 gUnknown_9777360[] = {
    0, 27, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_008.bin"),
};
const u16 gUnknown_9777A6A[] = {
    33, 27, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_009.bin"),
};
const u16 gUnknown_9778174[] = {
    66, 27, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_010.bin"),
};
const u16 gUnknown_977887E[] = {
    99, 27, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_011.bin"),
};
const u16 gUnknown_9778F88[] = {
    132, 27, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_012.bin"),
};
const u16 gUnknown_9779692[] = {
    165, 27, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_013.bin"),
};
const u16 gUnknown_9779D9C[] = {
    198, 27, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_014.bin"),
};
const u16 gUnknown_977A4A6[] = {
    231, 27, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_015.bin"),
};
const u16 gUnknown_977ABB0[] = {
    0, 54, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_016.bin"),
};
const u16 gUnknown_977B2BA[] = {
    33, 54, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_017.bin"),
};
const u16 gUnknown_977B9C4[] = {
    66, 54, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_018.bin"),
};
const u16 gUnknown_977C0CE[] = {
    99, 54, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_019.bin"),
};
const u16 gUnknown_977C7D8[] = {
    132, 54, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_020.bin"),
};
const u16 gUnknown_977CEE2[] = {
    165, 54, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_021.bin"),
};
const u16 gUnknown_977D5EC[] = {
    198, 54, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_022.bin"),
};
const u16 gUnknown_977DCF6[] = {
    231, 54, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_023.bin"),
};
const u16 gUnknown_977E400[] = {
    0, 81, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_024.bin"),
};
const u16 gUnknown_977EB0A[] = {
    33, 81, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_025.bin"),
};
const u16 gUnknown_977F214[] = {
    66, 81, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_026.bin"),
};
const u16 gUnknown_977F91E[] = {
    99, 81, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_027.bin"),
};
const u16 gUnknown_9780028[] = {
    132, 81, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_028.bin"),
};
const u16 gUnknown_9780732[] = {
    165, 81, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_029.bin"),
};
const u16 gUnknown_9780E3C[] = {
    198, 81, 33, 27, 2, 0, 65534, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_030.bin"),
};
const u16 gUnknown_9781546[] = {
    231, 81, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg006_031.bin"),
};
const u16 *gUnknown_9781C50[] = {
    gUnknown_9773B10,
    gUnknown_977421A,
    gUnknown_9774924,
    gUnknown_977502E,
    gUnknown_9775738,
    gUnknown_9775E42,
    gUnknown_977654C,
    gUnknown_9776C56,
    gUnknown_9777360,
    gUnknown_9777A6A,
    gUnknown_9778174,
    gUnknown_977887E,
    gUnknown_9778F88,
    gUnknown_9779692,
    gUnknown_9779D9C,
    gUnknown_977A4A6,
    gUnknown_977ABB0,
    gUnknown_977B2BA,
    gUnknown_977B9C4,
    gUnknown_977C0CE,
    gUnknown_977C7D8,
    gUnknown_977CEE2,
    gUnknown_977D5EC,
    gUnknown_977DCF6,
    gUnknown_977E400,
    gUnknown_977EB0A,
    gUnknown_977F214,
    gUnknown_977F91E,
    gUnknown_9780028,
    gUnknown_9780732,
    gUnknown_9780E3C,
    gUnknown_9781546,
};
const Palette256 gUnknown_9781CD0[] = INCBIN_U8("data/effects/efbg006_unk10.pmdpal");
const Palette256 gUnknown_97820D0[] = INCBIN_U8("data/effects/efbg006_unkC.4bpp");
const struct Struct_8009A7C gUnknown_9783EF0 = {
    ARRAY_COUNT(gUnknown_9781C50), // 32
    gUnknown_9781C50,
    ARRAY_COUNT(gUnknown_97820D0) / 16 - 1, // 240
    gUnknown_97820D0,
    gUnknown_9781CD0,
};
