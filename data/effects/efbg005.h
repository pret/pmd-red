#include "global.h"
#include "decompress_sir.h"
#include "structs/str_8009A7C.h"
const struct Struct_8009A7C gUnknown_9773AEC;
const SiroArchive gUnknown_9769088 = { "SIRO", &gUnknown_9773AEC };
const u16 gUnknown_9769098[] = {
    0, 0, 33, 27, 2, 1, 2, 0, 0, 0,
    INCBIN_U16("data/effects/efbg005_000.bin"),
};
const u16 gUnknown_97697A2[] = {
    33, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg005_001.bin"),
};
const u16 gUnknown_9769EAC[] = {
    66, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg005_002.bin"),
};
const u16 gUnknown_976A5B6[] = {
    99, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg005_003.bin"),
};
const u16 gUnknown_976ACC0[] = {
    132, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg005_004.bin"),
};
const u16 gUnknown_976B3CA[] = {
    165, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg005_005.bin"),
};
const u16 gUnknown_976BAD4[] = {
    198, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg005_006.bin"),
};
const u16 gUnknown_976C1DE[] = {
    231, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg005_007.bin"),
};
const u16 gUnknown_976C8E8[] = {
    264, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg005_008.bin"),
};
const u16 gUnknown_976CFF2[] = {
    297, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg005_009.bin"),
};
const u16 gUnknown_976D6FC[] = {
    330, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg005_010.bin"),
};
const u16 gUnknown_976DE06[] = {
    0, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg005_011.bin"),
};
const u16 gUnknown_976E510[] = {
    33, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg005_012.bin"),
};
const u16 gUnknown_976EC1A[] = {
    66, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg005_013.bin"),
};
const u16 gUnknown_976F324[] = {
    99, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg005_014.bin"),
};
const u16 gUnknown_976FA2E[] = {
    132, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg005_015.bin"),
};
const u16 gUnknown_9770138[] = {
    165, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg005_016.bin"),
};
const u16 gUnknown_9770842[] = {
    198, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg005_017.bin"),
};
const u16 gUnknown_9770F4C[] = {
    231, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg005_018.bin"),
};
const u16 gUnknown_9771656[] = {
    264, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg005_019.bin"),
};
const u16 gUnknown_9771D60[] = {
    297, 0, 33, 27, 2, 0, 65534, 0, 0, 0,
    INCBIN_U16("data/effects/efbg005_020.bin"),
};
const u16 gUnknown_977246A[] = {
    330, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg005_021.bin"),
};
const u16 *gUnknown_9772B74[] = {
    gUnknown_9769098,
    gUnknown_97697A2,
    gUnknown_9769EAC,
    gUnknown_976A5B6,
    gUnknown_976ACC0,
    gUnknown_976B3CA,
    gUnknown_976BAD4,
    gUnknown_976C1DE,
    gUnknown_976C8E8,
    gUnknown_976CFF2,
    gUnknown_976D6FC,
    gUnknown_976DE06,
    gUnknown_976E510,
    gUnknown_976EC1A,
    gUnknown_976F324,
    gUnknown_976FA2E,
    gUnknown_9770138,
    gUnknown_9770842,
    gUnknown_9770F4C,
    gUnknown_9771656,
    gUnknown_9771D60,
    gUnknown_977246A,
};
const u16 gUnknown_9772BCC[] = INCBIN_U16("data/effects/efbg005_unk10.bin");
const u16 gUnknown_9772FCC[] = INCBIN_U16("data/effects/efbg005_unkC.bin");
const struct Struct_8009A7C gUnknown_9773AEC = {
    ARRAY_COUNT(gUnknown_9772B74),
    gUnknown_9772B74,
    ARRAY_COUNT(gUnknown_9772FCC),
    gUnknown_9772FCC,
    gUnknown_9772BCC,
};
