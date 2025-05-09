#include "global.h"
#include "file_system.h"

#define TITLE_MENU_FILES_COUNT 22

extern const File gTitleMenuFiles[TITLE_MENU_FILES_COUNT];

const FileArchive gTitleMenuFileArchive = {
    .magic = "pksdir0",
    .count = TITLE_MENU_FILES_COUNT,
    .entries = gTitleMenuFiles,
};

UNUSED static const char sPksDir2[] = "pksdir0";

extern const u8 gUnknown_83801A0[];
extern const u8 gUnknown_8380AB8[];
extern const u8 gUnknown_8382884[];
extern const u8 gUnknown_8382C04[];
extern const u8 gUnknown_8384914[];
extern const u8 gUnknown_8384C9C[];
extern const u8 gUnknown_8388AD0[];
extern const u8 gUnknown_8388E50[];
extern const u8 gUnknown_838CF98[];
extern const u8 gUnknown_838D318[];
extern const u8 gUnknown_8391C48[];
extern const u8 gUnknown_8391FC8[];
extern const u8 gUnknown_83923A0[];
extern const u8 gUnknown_8392638[];
extern const u8 gUnknown_8392B88[];
extern const u8 gUnknown_8398A9C[];
extern const u8 gUnknown_8399F84[];
extern const u8 gUnknown_839A304[];
extern const u8 gUnknown_839B584[];
extern const u8 gUnknown_839B814[];
extern const u8 gUnknown_83A1574[];
extern const u8 gUnknown_83A2AF4[];


const File gTitleMenuFiles[TITLE_MENU_FILES_COUNT] = {
    [0] = { "clmkpat", gUnknown_83801A0},
    [1] = { "commun0", gUnknown_8380AB8},
    [2] = { "commun0p", gUnknown_8382884},
    [3] = { "subdef", gUnknown_8382C04},
    [4] = { "subdefp", gUnknown_8384914},
    [5] = { "titlen0", gUnknown_8384C9C},
    [6] = { "titlen0p", gUnknown_8388AD0},
    [7] = { "titlen1", gUnknown_8388E50},
    [8] = { "titlen1p", gUnknown_838CF98},
    [9] = { "titlen2", gUnknown_838D318},
    [10] = { "titlen2p", gUnknown_8391C48},
    [11] = { "tmrkpat", gUnknown_8391FC8},
    [12] = { "wlicpat", gUnknown_83923A0},
    [13] = { "wmapcani", gUnknown_8392638},
    [14] = { "wmapfont", gUnknown_8392B88},
    [15] = { "wmapmcc", gUnknown_8398A9C},
    [16] = { "wmappal", gUnknown_8399F84},
    [17] = { "wmapspr", gUnknown_839A304},
    [18] = { "wmp2cani", gUnknown_839B584},
    [19] = { "wmp2font", gUnknown_839B814},
    [20] = { "wmp2mcc", gUnknown_83A1574},
    [21] = { "wmp2pal", gUnknown_83A2AF4},
};

UNUSED ALIGNED(4) static const char sPksDir3[] = "pksdir0";

