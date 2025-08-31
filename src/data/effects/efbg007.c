#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfbFileData gUnknown_978C7AC;
const SiroArchive gUnknown_9783F04 = { "SIRO", &gUnknown_978C7AC };
const u16 gUnknown_9783F14[] = {
    0, 0, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9783F14_tilemap[] = INCBIN_U16("data/effects/efbg007_000.bin");
const u16 gUnknown_97841C4[] = {
    33, 0, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_97841C4_tilemap[] = INCBIN_U16("data/effects/efbg007_001.bin");
const u16 gUnknown_9784544[] = {
    66, 0, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9784544_tilemap[] = INCBIN_U16("data/effects/efbg007_002.bin");
const u16 gUnknown_9784B02[] = {
    99, 0, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9784B02_tilemap[] = INCBIN_U16("data/effects/efbg007_003.bin");
const u16 gUnknown_9784FA0[] = {
    132, 0, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9784FA0_tilemap[] = INCBIN_U16("data/effects/efbg007_004.bin");
const u16 gUnknown_9785352[] = {
    165, 0, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9785352_tilemap[] = INCBIN_U16("data/effects/efbg007_005.bin");
const u16 gUnknown_9785678[] = {
    198, 0, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9785678_tilemap[] = INCBIN_U16("data/effects/efbg007_006.bin");
const u16 gUnknown_9785B3E[] = {
    231, 0, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9785B3E_tilemap[] = INCBIN_U16("data/effects/efbg007_007.bin");
const u16 gUnknown_9785F84[] = {
    0, 27, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9785F84_tilemap[] = INCBIN_U16("data/effects/efbg007_008.bin");
const u16 gUnknown_978621A[] = {
    33, 27, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_978621A_tilemap[] = INCBIN_U16("data/effects/efbg007_009.bin");
const u16 gUnknown_97864B0[] = {
    66, 27, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_97864B0_tilemap[] = INCBIN_U16("data/effects/efbg007_010.bin");
const u16 gUnknown_97869D6[] = {
    99, 27, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_97869D6_tilemap[] = INCBIN_U16("data/effects/efbg007_011.bin");
const u16 gUnknown_9786DAC[] = {
    132, 27, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9786DAC_tilemap[] = INCBIN_U16("data/effects/efbg007_012.bin");
const u16 gUnknown_978712A[] = {
    165, 27, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_978712A_tilemap[] = INCBIN_U16("data/effects/efbg007_013.bin");
const u16 gUnknown_9787438[] = {
    198, 27, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9787438_tilemap[] = INCBIN_U16("data/effects/efbg007_014.bin");
const u16 gUnknown_9787974[] = {
    231, 27, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9787974_tilemap[] = INCBIN_U16("data/effects/efbg007_015.bin");
const u16 gUnknown_9787DD0[] = {
    0, 0, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9787DD0_tilemap[] = INCBIN_U16("data/effects/efbg007_016.bin");
const u16 gUnknown_9788080[] = {
    33, 0, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9788080_tilemap[] = INCBIN_U16("data/effects/efbg007_017.bin");
const u16 gUnknown_9788400[] = {
    66, 0, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9788400_tilemap[] = INCBIN_U16("data/effects/efbg007_018.bin");
const u16 gUnknown_97889BE[] = {
    99, 0, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_97889BE_tilemap[] = INCBIN_U16("data/effects/efbg007_019.bin");
const u16 gUnknown_9788E5C[] = {
    132, 0, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9788E5C_tilemap[] = INCBIN_U16("data/effects/efbg007_020.bin");
const u16 gUnknown_978920E[] = {
    165, 0, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_978920E_tilemap[] = INCBIN_U16("data/effects/efbg007_021.bin");
const u16 gUnknown_9789534[] = {
    198, 0, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9789534_tilemap[] = INCBIN_U16("data/effects/efbg007_022.bin");
const u16 gUnknown_97899FA[] = {
    231, 0, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_97899FA_tilemap[] = INCBIN_U16("data/effects/efbg007_023.bin");
const u16 gUnknown_9789E40[] = {
    0, 27, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_9789E40_tilemap[] = INCBIN_U16("data/effects/efbg007_024.bin");
const u16 gUnknown_978A0D6[] = {
    33, 27, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_978A0D6_tilemap[] = INCBIN_U16("data/effects/efbg007_025.bin");
const u16 gUnknown_978A36C[] = {
    66, 27, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_978A36C_tilemap[] = INCBIN_U16("data/effects/efbg007_026.bin");
const u16 gUnknown_978A892[] = {
    99, 27, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_978A892_tilemap[] = INCBIN_U16("data/effects/efbg007_027.bin");
const u16 gUnknown_978AC68[] = {
    132, 27, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_978AC68_tilemap[] = INCBIN_U16("data/effects/efbg007_028.bin");
const u16 gUnknown_978AFE6[] = {
    165, 27, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_978AFE6_tilemap[] = INCBIN_U16("data/effects/efbg007_029.bin");
const u16 gUnknown_978B2F4[] = {
    198, 27, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_978B2F4_tilemap[] = INCBIN_U16("data/effects/efbg007_030.bin");
const u16 gUnknown_978B830[] = {
    231, 27, 33, 27, 2, 0, 0, 0, 0, 0,
};
const u16 gUnknown_978B830_tilemap[] = INCBIN_U16("data/effects/efbg007_031.bin");
const u16 *const gUnknown_978BC8C[] = {
    gUnknown_9783F14,
    gUnknown_97841C4,
    gUnknown_9784544,
    gUnknown_9784B02,
    gUnknown_9784FA0,
    gUnknown_9785352,
    gUnknown_9785678,
    gUnknown_9785B3E,
    gUnknown_9785F84,
    gUnknown_978621A,
    gUnknown_97864B0,
    gUnknown_97869D6,
    gUnknown_9786DAC,
    gUnknown_978712A,
    gUnknown_9787438,
    gUnknown_9787974,
    gUnknown_9787DD0,
    gUnknown_9788080,
    gUnknown_9788400,
    gUnknown_97889BE,
    gUnknown_9788E5C,
    gUnknown_978920E,
    gUnknown_9789534,
    gUnknown_97899FA,
    gUnknown_9789E40,
    gUnknown_978A0D6,
    gUnknown_978A36C,
    gUnknown_978A892,
    gUnknown_978AC68,
    gUnknown_978AFE6,
    gUnknown_978B2F4,
    gUnknown_978B830,
};
const RGB gUnknown_978BD0C[] = INCBIN_U8("data/effects/efbg007.pmdpal");
const u32 gUnknown_978C10C[] = INCBIN_U32("data/effects/efbg007.4bpp");
const struct EfbFileData gUnknown_978C7AC = {
    ARRAY_COUNT(gUnknown_978BC8C), // 32
    gUnknown_978BC8C,
    sizeof(gUnknown_978C10C) / 32 - 1, // 52
    gUnknown_978C10C,
    gUnknown_978BD0C,
};
