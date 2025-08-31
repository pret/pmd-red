#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfbFileData gUnknown_974BE40;
const SiroArchive gUnknown_9740950 = { "SIRO", &gUnknown_974BE40 };
const u16 gUnknown_9740960[] = {
    0, 0, 33, 27, 4, 1, 2, 0, 0, 0,
};
const u16 gUnknown_9740960_tilemap[] = INCBIN_U16("data/effects/efbg000_000.bin");
const u16 gUnknown_974106A[] = {
    33, 0, 33, 27, 4, 0, 0, 0, 0, 0,
};
const u16 gUnknown_974106A_tilemap[] = INCBIN_U16("data/effects/efbg000_001.bin");
const u16 gUnknown_9741774[] = {
    66, 0, 33, 27, 4, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9741774_tilemap[] = INCBIN_U16("data/effects/efbg000_002.bin");
const u16 gUnknown_9741E7E[] = {
    99, 0, 33, 27, 4, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9741E7E_tilemap[] = INCBIN_U16("data/effects/efbg000_003.bin");
const u16 gUnknown_9742588[] = {
    132, 0, 33, 27, 4, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9742588_tilemap[] = INCBIN_U16("data/effects/efbg000_004.bin");
const u16 gUnknown_9742C92[] = {
    165, 0, 33, 27, 4, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9742C92_tilemap[] = INCBIN_U16("data/effects/efbg000_005.bin");
const u16 gUnknown_974339C[] = {
    198, 0, 33, 27, 4, 0, 0, 0, 0, 0,
};
const u16 gUnknown_974339C_tilemap[] = INCBIN_U16("data/effects/efbg000_006.bin");
const u16 gUnknown_9743AA6[] = {
    231, 0, 33, 27, 4, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9743AA6_tilemap[] = INCBIN_U16("data/effects/efbg000_007.bin");
const u16 gUnknown_97441B0[] = {
    0, 27, 33, 27, 4, 0, 0, 0, 0, 0,
};
const u16 gUnknown_97441B0_tilemap[] = INCBIN_U16("data/effects/efbg000_008.bin");
const u16 gUnknown_97448BA[] = {
    33, 27, 33, 27, 4, 0, 0, 0, 0, 0,
};
const u16 gUnknown_97448BA_tilemap[] = INCBIN_U16("data/effects/efbg000_009.bin");
const u16 gUnknown_9744FC4[] = {
    66, 27, 33, 27, 4, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9744FC4_tilemap[] = INCBIN_U16("data/effects/efbg000_010.bin");
const u16 gUnknown_97456CE[] = {
    99, 27, 33, 27, 4, 0, 0, 0, 0, 0,
};
const u16 gUnknown_97456CE_tilemap[] = INCBIN_U16("data/effects/efbg000_011.bin");
const u16 gUnknown_9745DD8[] = {
    132, 27, 33, 27, 4, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9745DD8_tilemap[] = INCBIN_U16("data/effects/efbg000_012.bin");
const u16 gUnknown_97464E2[] = {
    165, 27, 33, 27, 4, 0, 65534, 0, 0, 0,
};
const u16 gUnknown_97464E2_tilemap[] = INCBIN_U16("data/effects/efbg000_013.bin");
const u16 gUnknown_9746BEC[] = {
    198, 27, 33, 27, 4, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9746BEC_tilemap[] = INCBIN_U16("data/effects/efbg000_014.bin");
const u16 gUnknown_97472F6[] = {
    231, 27, 33, 27, 4, 0, 0, 0, 0, 0,
};
const u16 gUnknown_97472F6_tilemap[] = INCBIN_U16("data/effects/efbg000_015.bin");
const u16 *const gUnknown_9747A00[] = {
    gUnknown_9740960,
    gUnknown_974106A,
    gUnknown_9741774,
    gUnknown_9741E7E,
    gUnknown_9742588,
    gUnknown_9742C92,
    gUnknown_974339C,
    gUnknown_9743AA6,
    gUnknown_97441B0,
    gUnknown_97448BA,
    gUnknown_9744FC4,
    gUnknown_97456CE,
    gUnknown_9745DD8,
    gUnknown_97464E2,
    gUnknown_9746BEC,
    gUnknown_97472F6,
};
const RGB gUnknown_9747A40[] = INCBIN_U8("data/effects/efbg000.pmdpal");
const u32 gUnknown_9747E40[] = INCBIN_U32("data/effects/efbg000.4bpp");
const struct EfbFileData gUnknown_974BE40 = {
    ARRAY_COUNT(gUnknown_9747A00), // 16
    gUnknown_9747A00,
    sizeof(gUnknown_9747E40) / 32 - 1, // 511
    gUnknown_9747E40,
    gUnknown_9747A40,
};
