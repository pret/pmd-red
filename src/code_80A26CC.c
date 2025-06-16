#include "global.h"
#include "globaldata.h"
#include "code_80972F4.h"
#include "code_80A26CC.h"
#include "event_flag.h"

static const DungeonInfo gUnknown_81168A8[] = {
    [0] = {
        .unk0 = 178,
        .unk2 = 178,
        .unk4 = 178,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 359,
        .dungeonIndex = 0,
        .unkD = 0,
        .unkE = 0,
        .unk10 = 1,
        .unk11 = 1,
    },
    [1] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = 127,
        .unk8 = 129,
        .unkA = 360,
        .dungeonIndex = 1,
        .unkD = 0,
        .unkE = 1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [2] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = 136,
        .unk8 = 138,
        .unkA = 361,
        .dungeonIndex = 2,
        .unkD = 0,
        .unkE = 2,
        .unk10 = 1,
        .unk11 = 1,
    },
    [3] = {
        .unk0 = -1,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 361,
        .dungeonIndex = 2,
        .unkD = 0,
        .unkE = 2,
        .unk10 = 1,
        .unk11 = 0,
    },
    [4] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = 148,
        .unk8 = 150,
        .unkA = 362,
        .dungeonIndex = 3,
        .unkD = 0,
        .unkE = 3,
        .unk10 = 1,
        .unk11 = 1,
    },
    [5] = {
        .unk0 = -1,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 362,
        .dungeonIndex = 3,
        .unkD = 0,
        .unkE = 3,
        .unk10 = 1,
        .unk11 = 0,
    },
    [6] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = 155,
        .unk8 = 157,
        .unkA = 363,
        .dungeonIndex = 4,
        .unkD = 0,
        .unkE = 4,
        .unk10 = 1,
        .unk11 = 1,
    },
    [7] = {
        .unk0 = 9,
        .unk2 = 189,
        .unk4 = 12,
        .unk6 = 162,
        .unk8 = 164,
        .unkA = 364,
        .dungeonIndex = 5,
        .unkD = 0,
        .unkE = 5,
        .unk10 = 1,
        .unk11 = 1,
    },
    [8] = {
        .unk0 = -1,
        .unk2 = 12,
        .unk4 = 189,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 364,
        .dungeonIndex = 6,
        .unkD = 0,
        .unkE = 5,
        .unk10 = 1,
        .unk11 = 1,
    },
    [9] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = 170,
        .unk8 = 172,
        .unkA = 365,
        .dungeonIndex = 7,
        .unkD = 0,
        .unkE = 6,
        .unk10 = 1,
        .unk11 = 1,
    },
    [10] = {
        .unk0 = 193,
        .unk2 = 194,
        .unk4 = 193,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 366,
        .dungeonIndex = 8,
        .unkD = 0,
        .unkE = 7,
        .unk10 = 1,
        .unk11 = 1,
    },
    [11] = {
        .unk0 = 195,
        .unk2 = 196,
        .unk4 = 195,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 367,
        .dungeonIndex = 9,
        .unkD = 0,
        .unkE = 8,
        .unk10 = 1,
        .unk11 = 1,
    },
    [12] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = 196,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 367,
        .dungeonIndex = 10,
        .unkD = 0,
        .unkE = 8,
        .unk10 = 1,
        .unk11 = 1,
    },
    [13] = {
        .unk0 = 198,
        .unk2 = 199,
        .unk4 = 198,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 368,
        .dungeonIndex = 11,
        .unkD = 0,
        .unkE = 9,
        .unk10 = 1,
        .unk11 = 1,
    },
    [14] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = 199,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 368,
        .dungeonIndex = 12,
        .unkD = 0,
        .unkE = 9,
        .unk10 = 1,
        .unk11 = 1,
    },
    [15] = {
        .unk0 = 201,
        .unk2 = 202,
        .unk4 = 201,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 369,
        .dungeonIndex = 13,
        .unkD = 0,
        .unkE = 10,
        .unk10 = 1,
        .unk11 = 1,
    },
    [16] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = 202,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 369,
        .dungeonIndex = 14,
        .unkD = 0,
        .unkE = 10,
        .unk10 = 1,
        .unk11 = 1,
    },
    [17] = {
        .unk0 = 9,
        .unk2 = 205,
        .unk4 = 12,
        .unk6 = 222,
        .unk8 = 224,
        .unkA = 370,
        .dungeonIndex = 15,
        .unkD = 0,
        .unkE = 11,
        .unk10 = 1,
        .unk11 = 1,
    },
    [18] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = 205,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 370,
        .dungeonIndex = 16,
        .unkD = 0,
        .unkE = 11,
        .unk10 = 1,
        .unk11 = 1,
    },
    [19] = {
        .unk0 = 9,
        .unk2 = 208,
        .unk4 = 12,
        .unk6 = 230,
        .unk8 = 232,
        .unkA = 371,
        .dungeonIndex = 17,
        .unkD = 0,
        .unkE = 12,
        .unk10 = 1,
        .unk11 = 1,
    },
    [20] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = 208,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 371,
        .dungeonIndex = 18,
        .unkD = 0,
        .unkE = 12,
        .unk10 = 1,
        .unk11 = 1,
    },
    [21] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 372,
        .dungeonIndex = 0,
        .unkD = 0,
        .unkE = 13,
        .unk10 = 1,
        .unk11 = 0,
    },
    [22] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 373,
        .dungeonIndex = 42,
        .unkD = 0,
        .unkE = 14,
        .unk10 = 1,
        .unk11 = 1,
    },
    [23] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 374,
        .dungeonIndex = 53,
        .unkD = 0,
        .unkE = 15,
        .unk10 = 1,
        .unk11 = 1,
    },
    [24] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 375,
        .dungeonIndex = 19,
        .unkD = 0,
        .unkE = 16,
        .unk10 = 1,
        .unk11 = 1,
    },
    [25] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 376,
        .dungeonIndex = 20,
        .unkD = 0,
        .unkE = 17,
        .unk10 = 1,
        .unk11 = 1,
    },
    [26] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 377,
        .dungeonIndex = 21,
        .unkD = 0,
        .unkE = 18,
        .unk10 = 1,
        .unk11 = 1,
    },
    [27] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 378,
        .dungeonIndex = 7,
        .unkD = 0,
        .unkE = 19,
        .unk10 = 1,
        .unk11 = 1,
    },
    [28] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 379,
        .dungeonIndex = 34,
        .unkD = 0,
        .unkE = 20,
        .unk10 = 1,
        .unk11 = 1,
    },
    [29] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 380,
        .dungeonIndex = 37,
        .unkD = 0,
        .unkE = 21,
        .unk10 = 1,
        .unk11 = 1,
    },
    [30] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 381,
        .dungeonIndex = 35,
        .unkD = 0,
        .unkE = 22,
        .unk10 = 1,
        .unk11 = 1,
    },
    [31] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 382,
        .dungeonIndex = 60,
        .unkD = 0,
        .unkE = 23,
        .unk10 = 1,
        .unk11 = 1,
    },
    [32] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 383,
        .dungeonIndex = 23,
        .unkD = 0,
        .unkE = 24,
        .unk10 = 1,
        .unk11 = 1,
    },
    [33] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 384,
        .dungeonIndex = 29,
        .unkD = 0,
        .unkE = 25,
        .unk10 = 1,
        .unk11 = 1,
    },
    [34] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 385,
        .dungeonIndex = 28,
        .unkD = 0,
        .unkE = 26,
        .unk10 = 1,
        .unk11 = 1,
    },
    [35] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 386,
        .dungeonIndex = 27,
        .unkD = 0,
        .unkE = 27,
        .unk10 = 1,
        .unk11 = 1,
    },
    [36] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 387,
        .dungeonIndex = 26,
        .unkD = 0,
        .unkE = 28,
        .unk10 = 1,
        .unk11 = 1,
    },
    [37] = {
        .unk0 = 201,
        .unk2 = 202,
        .unk4 = 201,
        .unk6 = 346,
        .unk8 = 346,
        .unkA = 388,
        .dungeonIndex = 13,
        .unkD = 0,
        .unkE = 29,
        .unk10 = 1,
        .unk11 = 1,
    },
    [38] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = 202,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 388,
        .dungeonIndex = 22,
        .unkD = 0,
        .unkE = 29,
        .unk10 = 1,
        .unk11 = 1,
    },
    [39] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = 350,
        .unk8 = 350,
        .unkA = 389,
        .dungeonIndex = 40,
        .unkD = 0,
        .unkE = 30,
        .unk10 = 1,
        .unk11 = 1,
    },
    [40] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 396,
        .dungeonIndex = 31,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [41] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 396,
        .dungeonIndex = 32,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [42] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 396,
        .dungeonIndex = 33,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [43] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 396,
        .dungeonIndex = 36,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [44] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 396,
        .dungeonIndex = 38,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [45] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 396,
        .dungeonIndex = 41,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [46] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 396,
        .dungeonIndex = 56,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [47] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 396,
        .dungeonIndex = 57,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [48] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 396,
        .dungeonIndex = 58,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [49] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 396,
        .dungeonIndex = 59,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [50] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 390,
        .dungeonIndex = 62,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [51] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 391,
        .dungeonIndex = 43,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [52] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 392,
        .dungeonIndex = 44,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [53] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 393,
        .dungeonIndex = 45,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [54] = {
        .unk0 = 9,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 394,
        .dungeonIndex = 46,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [55] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = 75,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [56] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = 76,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [57] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = 77,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [58] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = 78,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [59] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = 79,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [60] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = 80,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [61] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = 81,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [62] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = 82,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [63] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = 83,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [64] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = 84,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [65] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = 85,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [66] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = 86,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [67] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = 87,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [68] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = 88,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [69] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = 89,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [70] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = 90,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [71] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = 91,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [72] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = 92,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [73] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = 93,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [74] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = 94,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [75] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = 95,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [76] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = 96,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [77] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = 97,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [78] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 398,
        .dungeonIndex = 47,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [79] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 399,
        .dungeonIndex = 48,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 1,
    },
    [80] = {
        .unk0 = -1,
        .unk2 = 5,
        .unk4 = 5,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 395,
        .dungeonIndex = 63,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 0,
    },
    [81] = {
        .unk0 = -1,
        .unk2 = 12,
        .unk4 = 12,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 396,
        .dungeonIndex = 63,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 0,
    },
    [82] = {
        .unk0 = -1,
        .unk2 = -1,
        .unk4 = -1,
        .unk6 = -1,
        .unk8 = -1,
        .unkA = 397,
        .dungeonIndex = 63,
        .unkD = 0,
        .unkE = -1,
        .unk10 = 1,
        .unk11 = 0,
    },
};

static const s16 gUnknown_8116F24[] = {
    -1, -1, 0, 1, 2, 3, 4, 5, 6, -1, -1, 7,
    8, 9, 10, 11, 12, -1, -1, -1, -1, 13, 14,
    -1, 15, -1, 16, 17, -1, 18, -1, 19, 20,
    21, 22, 23, -1, 24, -1, 25, 26, -1, 27, -1,
    28, -1, 29, 30, -1, -1, -1, 0, 0, 0, 0,
    0, 0, 0, 0
};

static const s16 gUnknown_8116F9A[] = {
    0, 1, 2, 4, 6, 7, 9, 10, 11, 13, 15, 17, 19, 21, 22,
    23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,
    36, 37, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    50, 51, 52, 53, 54
};

const DungeonInfo *GetDungeonInfo_80A2608(s32 _index)
{
    s32 index = (s16) _index;
    return &gUnknown_81168A8[index];
}

const DungeonInfo *sub_80A2620(s16 index)
{
    u32 temp;
    temp = sub_80A26B8(index);
    return &gUnknown_81168A8[temp];
}

UNUSED static s16 sub_80A2644(u32 index)
{
    return gUnknown_8116F24[index];
}

s16 sub_80A2654(s16 index)
{
    const DungeonInfo *temp;

    temp = GetDungeonInfo_80A2608(index);
    return temp->unkE;
}

s16 sub_80A2668(s16 a0)
{
    if (a0 >= 55 && a0 <= 79)
        return a0 - 55;

    return -1;
}

s16 sub_80A2688(u8 r0)
{
    if (r0 >= 75 && r0 < 98)
        return r0 - 75;
    if (r0 == 47)
        return 23;
    if (r0 == 48)
        return 24;
    return -1;
}

s16 sub_80A26B8(s16 a0_)
{
    s32 a0 = (s16) a0_;
    return gUnknown_8116F9A[a0];
}

s16 sub_80A26CC(s16 r0)
{
    return 55 + r0;
}

UNUSED static s16 sub_80A26D8(u8 index)
{
    s32 i;
    s16 counter2;
    const DungeonInfo *temp;

    for (i = 0; i < 83; i++) {
        counter2 = i;
        temp = GetDungeonInfo_80A2608(counter2);

        if (temp->unk11 != 0) {
            if (temp->dungeonIndex == index)
                return counter2;
        }
    }
    return -1;
}

u8 sub_80A270C(s16 index)
{
    const DungeonInfo *temp;
    s32 index_s32;

    index_s32 = index; // forcing a shift before addressing
    temp = GetDungeonInfo_80A2608(gUnknown_8116F9A[index_s32]);
    return temp->dungeonIndex;
}

u8 sub_80A2728(s16 index)
{
    const DungeonInfo *temp;

    s16 temp_number = 55 + index;
    temp = GetDungeonInfo_80A2608(temp_number);
    return temp->dungeonIndex;
}

u8 sub_80A2740(s16 index)
{
    const DungeonInfo *temp;
    s32 index_s32;

    index_s32 = index;

    temp = GetDungeonInfo_80A2608(index_s32);
    return temp->dungeonIndex;
}

s16 sub_80A2750(s16 r0)
{
    const DungeonInfo *temp;
    s32 temp_32;
    s32 temp_2;

    // so dumb but it matches
    temp_32 = r0;
    temp_2 = temp_32;

    if (r0 == 80)
        return 3;
    if (r0 == 81)
        return 2;
    if (r0 == 82)
        return 4;
    if ((u16)(r0 - 40) <= 14)
        return 2;
    if ((u16)(r0 - 55) <= 24)
        return 4;

    temp = GetDungeonInfo_80A2608(temp_2);
    if (temp->unkE == -1)
        return 1;
    if (sub_80023E4(5))
        return 1;
    if (!RescueScenarioConquered((s16) temp->unkE))
        return 1;
    if (!sub_80023E4(1))
        return 1;
    return 2;
}

bool8 sub_80A27CC(s16 r0)
{
    s32 temp;
    s32 temp2;
    const DungeonInfo *t;

    // Same dumbness as above to get a match
    temp2 = r0;
    temp = temp2;

    t = sub_80A2620(r0);
    if (t->unk0 == -1)
        return FALSE;
    if (sub_80023E4(5))
        return FALSE;
    if (sub_8097384(r0))
        return TRUE;
    if (!sub_80023E4(1))
        return FALSE;
    if (!RescueScenarioConquered((s16) temp))
        return FALSE;
    return TRUE;
}

bool8 sub_80A2824(u8 index)
{
    s32 i;
    const DungeonInfo *temp;

    if (sub_80023E4(5))
        return FALSE;

    if (sub_80023E4(1)) {
        for (i = 0; i < 46; i++) {
            temp = sub_80A2620(i);

            if (temp->unk11 != 0) {
                if (temp->dungeonIndex == index) {
                    if (sub_8097384((s16) i))
                        return TRUE;
                    if (RescueScenarioConquered((s16) i))
                        return TRUE;
                }
            }
        }
    }
    else {
        for (i = 0; i < 46; i++) {
            temp = sub_80A2620(i);

            if (temp->unk11 != 0)
                if (temp->dungeonIndex == index)
                    if (sub_8097384((s16) i))
                        return TRUE;
        }
    }

    return FALSE;
}

UNUSED static bool8 sub_80A28B4(s16 r0)
{
    const DungeonInfo *temp;

    temp = sub_80A2620(r0);

    if (temp->unk0 != -1) {
        if (!sub_8097384(r0) && !RescueScenarioConquered(r0))
            return FALSE;
        else
            return TRUE;
    }

    return FALSE;
}

bool8 sub_80A28F0(u8 index)
{
    s32 counter;
    const DungeonInfo *temp;

    for (counter = 0; counter < 0x2E; counter++) {
        temp = sub_80A2620(counter);

        if (temp->unk11 != 0) {
            if (temp->dungeonIndex == index) {
                if (sub_8097384((s16) counter))
                    return TRUE;
                if (RescueScenarioConquered((s16) counter))
                    return TRUE;
            }
        }
    }

    return FALSE;
}

UNUSED static s32 sub_80A293C(u8 *param_1)
{
    u8 *pcVar2;
    const DungeonInfo *iVar3;
    s32 index;
    s32 counter;
    u8 local_68[64];
    u8 zero;

    counter = 0;
    zero = 0;

    pcVar2 = &local_68[62];
    do {
        *pcVar2 = zero;
        pcVar2--;
    } while ((int)pcVar2 >= (int)local_68);


    for (index = 0; index < 46; index++) {
        iVar3 = sub_80A2620(index);
        if (iVar3->unk11 != 0 && sub_8097384((s16) index))
            local_68[iVar3->dungeonIndex] = 1;
    }

    for (index = 0; index < 63; index++) {
        if (local_68[index] != 0) {
            param_1[counter] = index;
            counter++;
        }
    }

    return counter;
}

s32 sub_80A29B0(u8 *param_1)
{
    u8 *pcVar2;
    const DungeonInfo *iVar3;
    s32 index;
    s32 counter;
    u8 *local1;
    u8 *local2;
    u8 *local3;
    u8 *local4;
    u8 local_68[0x40];
    u8 zero;

    counter = 0;
    local1 = &local_68[43];
    local2 = &local_68[44];
    local3 = &local_68[45];
    local4 = &local_68[46];
    zero = 0;

    pcVar2 = &local_68[62];
    do {
        *pcVar2 = zero;
        pcVar2 = pcVar2 + -1;
    } while ((int)pcVar2 >= (int)local_68);


    if (sub_80023E4(1)) {
        for (index = 0; index < 46; index++) {
            iVar3 = sub_80A2620(index);

            if (iVar3->unk11 != 0 && RescueScenarioConquered((s16) index))
                local_68[iVar3->dungeonIndex] = 1;
        }
    }

    *local1 = 0;
    *local2 = 0;
    *local3 = 0;
    *local4 = 0;

    for (index = 0; index < 63; index++) {
        if (local_68[index] != 0) {
            param_1[counter] = index;
            counter++;
        }
    }

    return counter;
}

UNUSED static s32 sub_80A2A5C(u8 *param_1)
{
    u8 *pcVar2;
    const DungeonInfo *iVar3;
    s32 index;
    s32 counter;
    u8 local_58[0x40];
    u8 zero;

    counter = 0;
    zero = 0;

    pcVar2 = &local_58[62];
    do {
        *pcVar2 = zero;
        pcVar2--;
    } while ((s32)pcVar2 >= (s32)local_58);

    if (sub_80023E4(1)) {
        for (index = 0; index < 46; index++) {
            iVar3 = sub_80A2620(index);

            if (iVar3->unk11 != 0 && (sub_8097384((s16) index) || RescueScenarioConquered((s16) index)))
                local_58[iVar3->dungeonIndex] = 1;
        }
    }
    else {
        for (index = 0; index < 46; index++) {
            iVar3 = sub_80A2620(index);

            if (iVar3->unk11 != 0 && sub_8097384((s16) index))
                local_58[iVar3->dungeonIndex] = 1;
        }
    }

    for (index = 0; index < 63; index++) {
        if (local_58[index] != 0) {
            param_1[counter] = index;
            counter++;
        }
    }

    return counter;
}
