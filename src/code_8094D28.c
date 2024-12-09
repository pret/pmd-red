#include "global.h"
#include "globaldata.h"

IWRAM_DATA u32 gUnknown_3001198[0x270] = {0};
EWRAM_DATA_2 s32 gUnknown_203B470 = {0};
EWRAM_DATA_2 s32 gUnknown_203B474 = {0};

void sub_8094D28(s32 r0) {

    gUnknown_3001198[0] = r0;
    gUnknown_203B470 = 1;

    for(; gUnknown_203B470 < 0x270; gUnknown_203B470++)
    {
        gUnknown_3001198[gUnknown_203B470] =
            (gUnknown_3001198[gUnknown_203B470 - 1] ^
            (gUnknown_3001198[gUnknown_203B470 - 1] >> 0x1e)) * 0x6c078965 + gUnknown_203B470;
    }
}
