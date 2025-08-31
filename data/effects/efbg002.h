#include "global.h"
#include "decompress_sir.h"
#include "structs/str_8009A7C.h"
const struct Struct_8009A7C gUnknown_9756660;
const SiroArchive gUnknown_97547D8 = { "SIRO", &gUnknown_9756660 };
const u16 gUnknown_97547E8[] = {
    0, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_000.bin"),
};
const u16 gUnknown_9754802[] = {
    33, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_001.bin"),
};
const u16 gUnknown_9754824[] = {
    66, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_002.bin"),
};
const u16 gUnknown_9754840[] = {
    99, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_003.bin"),
};
const u16 gUnknown_9754868[] = {
    132, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_004.bin"),
};
const u16 gUnknown_9754888[] = {
    165, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_005.bin"),
};
const u16 gUnknown_97548B6[] = {
    198, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_006.bin"),
};
const u16 gUnknown_97548D6[] = {
    231, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_007.bin"),
};
const u16 gUnknown_9754906[] = {
    264, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_008.bin"),
};
const u16 gUnknown_975492E[] = {
    297, 0, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_009.bin"),
};
const u16 gUnknown_975496C[] = {
    0, 27, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_010.bin"),
};
const u16 gUnknown_975499E[] = {
    33, 27, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_011.bin"),
};
const u16 gUnknown_97549D6[] = {
    66, 27, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_012.bin"),
};
const u16 gUnknown_9754A14[] = {
    99, 27, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_013.bin"),
};
const u16 gUnknown_9754A52[] = {
    132, 27, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_014.bin"),
};
const u16 gUnknown_9754A9C[] = {
    165, 27, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_015.bin"),
};
const u16 gUnknown_9754AE8[] = {
    198, 27, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_016.bin"),
};
const u16 gUnknown_9754B48[] = {
    231, 27, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_017.bin"),
};
const u16 gUnknown_9754B90[] = {
    264, 27, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_018.bin"),
};
const u16 gUnknown_9754BE6[] = {
    297, 27, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_019.bin"),
};
const u16 gUnknown_9754C34[] = {
    0, 54, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_020.bin"),
};
const u16 gUnknown_9754C88[] = {
    33, 54, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_021.bin"),
};
const u16 gUnknown_9754CD6[] = {
    66, 54, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_022.bin"),
};
const u16 gUnknown_9754D2C[] = {
    99, 54, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_023.bin"),
};
const u16 gUnknown_9754D8E[] = {
    132, 54, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_024.bin"),
};
const u16 gUnknown_9754DE4[] = {
    165, 54, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_025.bin"),
};
const u16 gUnknown_9754E4E[] = {
    198, 54, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_026.bin"),
};
const u16 gUnknown_9754EAE[] = {
    231, 54, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_027.bin"),
};
const u16 gUnknown_9754F2E[] = {
    264, 54, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_028.bin"),
};
const u16 gUnknown_9754F92[] = {
    297, 54, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_029.bin"),
};
const u16 gUnknown_9755014[] = {
    0, 81, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_030.bin"),
};
const u16 gUnknown_975508C[] = {
    33, 81, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_031.bin"),
};
const u16 gUnknown_9755104[] = {
    66, 81, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_032.bin"),
};
const u16 gUnknown_9755176[] = {
    99, 81, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_033.bin"),
};
const u16 gUnknown_97551EC[] = {
    132, 81, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_034.bin"),
};
const u16 gUnknown_9755260[] = {
    165, 81, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_035.bin"),
};
const u16 gUnknown_97552DE[] = {
    198, 81, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_036.bin"),
};
const u16 gUnknown_9755366[] = {
    231, 81, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_037.bin"),
};
const u16 gUnknown_97553F0[] = {
    264, 81, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_038.bin"),
};
const u16 gUnknown_975546A[] = {
    297, 81, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_039.bin"),
};
const u16 gUnknown_97554E8[] = {
    0, 108, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_040.bin"),
};
const u16 gUnknown_9755566[] = {
    33, 108, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_041.bin"),
};
const u16 gUnknown_97555E4[] = {
    66, 108, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_042.bin"),
};
const u16 gUnknown_9755668[] = {
    99, 108, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_043.bin"),
};
const u16 gUnknown_97556DE[] = {
    132, 108, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_044.bin"),
};
const u16 gUnknown_9755762[] = {
    165, 108, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_045.bin"),
};
const u16 gUnknown_97557C4[] = {
    198, 108, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_046.bin"),
};
const u16 gUnknown_9755838[] = {
    231, 108, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_047.bin"),
};
const u16 gUnknown_97558B4[] = {
    264, 108, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_048.bin"),
};
const u16 gUnknown_975592A[] = {
    297, 108, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_049.bin"),
};
const u16 gUnknown_9755984[] = {
    0, 135, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_050.bin"),
};
const u16 gUnknown_97559E8[] = {
    33, 135, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_051.bin"),
};
const u16 gUnknown_9755A52[] = {
    66, 135, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_052.bin"),
};
const u16 gUnknown_9755AB4[] = {
    99, 135, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_053.bin"),
};
const u16 gUnknown_9755AFE[] = {
    132, 135, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_054.bin"),
};
const u16 gUnknown_9755B4A[] = {
    165, 135, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_055.bin"),
};
const u16 gUnknown_9755B9C[] = {
    198, 135, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_056.bin"),
};
const u16 gUnknown_9755BDA[] = {
    231, 135, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_057.bin"),
};
const u16 gUnknown_9755C24[] = {
    264, 135, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_058.bin"),
};
const u16 gUnknown_9755C6A[] = {
    297, 135, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_059.bin"),
};
const u16 gUnknown_9755CA0[] = {
    0, 162, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_060.bin"),
};
const u16 gUnknown_9755CDE[] = {
    33, 162, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_061.bin"),
};
const u16 gUnknown_9755D22[] = {
    66, 162, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_062.bin"),
};
const u16 gUnknown_9755D46[] = {
    99, 162, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_063.bin"),
};
const u16 gUnknown_9755D78[] = {
    132, 162, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_064.bin"),
};
const u16 gUnknown_9755DA4[] = {
    165, 162, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_065.bin"),
};
const u16 gUnknown_9755DC6[] = {
    198, 162, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_066.bin"),
};
const u16 gUnknown_9755DE0[] = {
    231, 162, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_067.bin"),
};
const u16 gUnknown_9755E06[] = {
    264, 162, 33, 27, 2, 0, 0, 0, 0, 0,
    INCBIN_U16("data/effects/efbg002_068.bin"),
};
const u16 *gUnknown_9755E2C[] = {
    gUnknown_97547E8,
    gUnknown_9754802,
    gUnknown_9754824,
    gUnknown_9754840,
    gUnknown_9754868,
    gUnknown_9754888,
    gUnknown_97548B6,
    gUnknown_97548D6,
    gUnknown_9754906,
    gUnknown_975492E,
    gUnknown_975496C,
    gUnknown_975499E,
    gUnknown_97549D6,
    gUnknown_9754A14,
    gUnknown_9754A52,
    gUnknown_9754A9C,
    gUnknown_9754AE8,
    gUnknown_9754B48,
    gUnknown_9754B90,
    gUnknown_9754BE6,
    gUnknown_9754C34,
    gUnknown_9754C88,
    gUnknown_9754CD6,
    gUnknown_9754D2C,
    gUnknown_9754D8E,
    gUnknown_9754DE4,
    gUnknown_9754E4E,
    gUnknown_9754EAE,
    gUnknown_9754F2E,
    gUnknown_9754F92,
    gUnknown_9755014,
    gUnknown_975508C,
    gUnknown_9755104,
    gUnknown_9755176,
    gUnknown_97551EC,
    gUnknown_9755260,
    gUnknown_97552DE,
    gUnknown_9755366,
    gUnknown_97553F0,
    gUnknown_975546A,
    gUnknown_97554E8,
    gUnknown_9755566,
    gUnknown_97555E4,
    gUnknown_9755668,
    gUnknown_97556DE,
    gUnknown_9755762,
    gUnknown_97557C4,
    gUnknown_9755838,
    gUnknown_97558B4,
    gUnknown_975592A,
    gUnknown_9755984,
    gUnknown_97559E8,
    gUnknown_9755A52,
    gUnknown_9755AB4,
    gUnknown_9755AFE,
    gUnknown_9755B4A,
    gUnknown_9755B9C,
    gUnknown_9755BDA,
    gUnknown_9755C24,
    gUnknown_9755C6A,
    gUnknown_9755CA0,
    gUnknown_9755CDE,
    gUnknown_9755D22,
    gUnknown_9755D46,
    gUnknown_9755D78,
    gUnknown_9755DA4,
    gUnknown_9755DC6,
    gUnknown_9755DE0,
    gUnknown_9755E06,
};
const Palette256 gUnknown_9755F40[] = INCBIN_U8("data/effects/efbg002.pmdpal");
const Palette256 gUnknown_9756340[] = INCBIN_U8("data/effects/efbg002.4bpp");
const struct Struct_8009A7C gUnknown_9756660 = {
    ARRAY_COUNT(gUnknown_9755E2C), // 69
    gUnknown_9755E2C,
    ARRAY_COUNT(gUnknown_9756340) / 16 - 1, // 24
    gUnknown_9756340,
    gUnknown_9755F40,
};
