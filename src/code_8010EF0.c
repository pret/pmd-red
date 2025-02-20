#include "global.h"
#include "code_8004AA0.h"
#include "text.h"

EWRAM_INIT struct UnkBgStruct *gUnknown_203B0E4 = NULL;
EWRAM_INIT void *gUnknown_203B0E8 = NULL; // Pointer to some unknown struct
EWRAM_INIT UnkTextStruct2 gUnknown_203B0EC[4] = { // Exact location of this variable is unknown. Find a better place for it once more code is decompiled.
    [0] = {
        .unk4 = 3,
        .pos = {2, 10},
        .unkC = 26,
        .unkE = 9,
        .unk10 = 9,
    },
    [1] = {
        .unk4 = 3,
        .pos = {23, 6},
        .unkC = 5,
        .unkE = 3,
        .unk10 = 3,
    },
    [2] = {
        .unk4 = 3,
    },
    [3] = {
        .unk4 = 3,
    },
};

void sub_8010EF0(void)
{
    CloseFile(gUnknown_203B0E4->unk0[4]);
    CloseFile(gUnknown_203B0E4->unk0[2]);
    CloseFile(gUnknown_203B0E4->unk0[3]);
    CloseFile(gUnknown_203B0E4->unk0[0]);
    CloseFile(gUnknown_203B0E4->unk0[1]);
}
