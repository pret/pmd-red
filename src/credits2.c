#include "global.h"
#include "globaldata.h"
#include "credits2.h"
#include "event_flag.h"
#include "input.h"
#include "memory.h"

static EWRAM_DATA_2 Credits2Work *sCredits2Work = {0};

#include "data/credits2.h"

bool8 sub_8035678(void)
{
    sCredits2Work = MemoryAlloc(sizeof(Credits2Work), 8);
    sCredits2Work->state = 0;
    sCredits2Work->unk4 = 0;
    ClearScriptVarArray(NULL, 57);
    return TRUE;
}

u32 sub_80356A0(void)
{
    u16 uVar1;
    u16 held_input;

    held_input = gRealInputs.held;
    uVar1 = sUnknown_80E5990[sCredits2Work->unk4];

    switch (sCredits2Work->state) {
        case 0:
            sCredits2Work->state = 3;
            break;
        case 1:
            if (uVar1 == 0)
                sCredits2Work->state = 4;
            else {
                if (held_input == uVar1)
                    sCredits2Work->state = 2;
                else {
                    if ((uVar1 & held_input) != held_input)
                        sCredits2Work->state = 3;
                    else {
                        if (sCredits2Work->unk4 == 0)
                            sCredits2Work->state = 3;
                    }
                }
            }
            break;
        case 2:
            if (held_input == 0) {
                sCredits2Work->state = 1;
                sCredits2Work->unk4++;
            }
            else {
                if ((uVar1 & held_input) != held_input)
                    sCredits2Work->state = 3;
            }
            break;
        case 3:
            return 2;
        case 4:
            return 3; // sub_809C478 clears the flash data when this is returned
    }

    if (GetScriptVarValue(NULL, 57) != 0) {
        sCredits2Work->state = 3;
        return 2;
    }

    return 0;
}

void sub_8035758(void)
{
    if (sCredits2Work != NULL) {
        MemoryFree(sCredits2Work);
        sCredits2Work = NULL;
    }
}