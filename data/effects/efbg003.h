#include "global.h"
#include "decompress_sir.h"
#include "structs/str_8009A7C.h"
const struct Struct_8009A7C gUnknown_9766A64;
const SiroArchive gUnknown_9756674 = { "SIRO", &gUnknown_9766A64 };
const u16 gUnknown_9756684[] = {
    0, 0, 33, 27, 1, 1, 2, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_000.bin"),
};
const u16 gUnknown_9756D8E[] = {
    33, 0, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_001.bin"),
};
const u16 gUnknown_9757498[] = {
    66, 0, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_002.bin"),
};
const u16 gUnknown_9757BA2[] = {
    99, 0, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_003.bin"),
};
const u16 gUnknown_97582AC[] = {
    132, 0, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_004.bin"),
};
const u16 gUnknown_97589B6[] = {
    165, 0, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_005.bin"),
};
const u16 gUnknown_97590C0[] = {
    198, 0, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_006.bin"),
};
const u16 gUnknown_97597CA[] = {
    231, 0, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_007.bin"),
};
const u16 gUnknown_9759ED4[] = {
    0, 27, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_008.bin"),
};
const u16 gUnknown_975A5DE[] = {
    33, 27, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_009.bin"),
};
const u16 gUnknown_975ACE8[] = {
    66, 27, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_010.bin"),
};
const u16 gUnknown_975B3F2[] = {
    99, 27, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_011.bin"),
};
const u16 gUnknown_975BAFC[] = {
    132, 27, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_012.bin"),
};
const u16 gUnknown_975C206[] = {
    165, 27, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_013.bin"),
};
const u16 gUnknown_975C910[] = {
    198, 27, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_014.bin"),
};
const u16 gUnknown_975D01A[] = {
    231, 27, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_015.bin"),
};
const u16 gUnknown_975D724[] = {
    0, 54, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_016.bin"),
};
const u16 gUnknown_975DE2E[] = {
    33, 54, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_017.bin"),
};
const u16 gUnknown_975E538[] = {
    66, 54, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_018.bin"),
};
const u16 gUnknown_975EC42[] = {
    99, 54, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_019.bin"),
};
const u16 gUnknown_975F34C[] = {
    132, 54, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_020.bin"),
};
const u16 gUnknown_975FA56[] = {
    165, 54, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_021.bin"),
};
const u16 gUnknown_9760160[] = {
    198, 54, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_022.bin"),
};
const u16 gUnknown_976086A[] = {
    231, 54, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_023.bin"),
};
const u16 gUnknown_9760F74[] = {
    0, 81, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_024.bin"),
};
const u16 gUnknown_976167E[] = {
    33, 81, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_025.bin"),
};
const u16 gUnknown_9761D88[] = {
    66, 81, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_026.bin"),
};
const u16 gUnknown_9762492[] = {
    99, 81, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_027.bin"),
};
const u16 gUnknown_9762B9C[] = {
    132, 81, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_028.bin"),
};
const u16 gUnknown_97632A6[] = {
    165, 81, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_029.bin"),
};
const u16 gUnknown_97639B0[] = {
    198, 81, 33, 27, 1, 0, 65534, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_030.bin"),
};
const u16 gUnknown_97640BA[] = {
    231, 81, 33, 27, 1, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg003_031.bin"),
};
const u16 *gUnknown_97647C4[] = {
    gUnknown_9756684,
    gUnknown_9756D8E,
    gUnknown_9757498,
    gUnknown_9757BA2,
    gUnknown_97582AC,
    gUnknown_97589B6,
    gUnknown_97590C0,
    gUnknown_97597CA,
    gUnknown_9759ED4,
    gUnknown_975A5DE,
    gUnknown_975ACE8,
    gUnknown_975B3F2,
    gUnknown_975BAFC,
    gUnknown_975C206,
    gUnknown_975C910,
    gUnknown_975D01A,
    gUnknown_975D724,
    gUnknown_975DE2E,
    gUnknown_975E538,
    gUnknown_975EC42,
    gUnknown_975F34C,
    gUnknown_975FA56,
    gUnknown_9760160,
    gUnknown_976086A,
    gUnknown_9760F74,
    gUnknown_976167E,
    gUnknown_9761D88,
    gUnknown_9762492,
    gUnknown_9762B9C,
    gUnknown_97632A6,
    gUnknown_97639B0,
    gUnknown_97640BA,
};
const u16 gUnknown_9764844[] = INCBIN_U16("data/effects/efbg003_unk10.bin");
const u16 gUnknown_9764C44[] = INCBIN_U16("data/effects/efbg003_unkC.bin");
const struct Struct_8009A7C gUnknown_9766A64 = {
    ARRAY_COUNT(gUnknown_97647C4),
    gUnknown_97647C4,
    ARRAY_COUNT(gUnknown_9764C44),
    gUnknown_9764C44,
    gUnknown_9764844,
};
