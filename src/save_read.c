#include "global.h"
#include "code_80130A8.h"
#include "memory.h"
#include "save.h"
#include "save_read.h"

EWRAM_DATA_2 SavePakRead *gSavePakRead = {0};

#include "data/save_read.h"

void PrepareSavePakRead(void)
{
    gSavePakRead = MemoryAlloc(sizeof(SavePakRead), 5);
    gSavePakRead->state = 1;
}

u8 ReadSavePak(void)
{
    u32 temp;
    u32 temp2;

    switch (gSavePakRead->state) {
        case 0:
            gSavePakRead->state = 1;
            break;
        case 1:
            temp = 0;
            gSavePakRead->readStatus = ReadSaveFromPak(&temp);
            gSavePakRead->state = 2;
            break;
        case 2:
            if (gSavePakRead->readStatus != READ_SAVE_VALID) {
                if (IsSaveCorrupted()) {
                    sub_80141B4(sSaveCorrupted, 0, 0, 0x301);
                    gSavePakRead->state = 3;
                }
                else
                    gSavePakRead->state = 4;
            }
            else
                gSavePakRead->state = 6;
            break;
        case 3:
            if (sub_80144A4(&temp2) == 0)
                gSavePakRead->state = 4;
            break;
        case 4:
            sub_8012298();
            gSavePakRead->state = 6;
        case 5:
            break;
        case 6:
            return 0;
    }
    return 1;
}

void FinishReadSavePak(void)
{
    if (gSavePakRead != NULL) {
        MemoryFree(gSavePakRead);
        gSavePakRead = NULL;
    }
}