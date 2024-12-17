#include "global.h"
#include "globaldata.h"
#include "string_format.h"
#include "memory.h"
#include "quick_save_read.h"
#include "save.h"

static EWRAM_INIT QuickSaveRead *sQuickSaveRead = {NULL};

#include "data/quick_save_read.h"

void PrepareQuickSaveRead(u8 *dest, u32 size)
{
    sQuickSaveRead = MemoryAlloc(sizeof(QuickSaveRead), 5);
    sQuickSaveRead->dest = dest;
    sQuickSaveRead->size = size;
    sQuickSaveRead->saveValid = FALSE;
    sQuickSaveRead->state = 1;
}

bool8 ReadQuickSave(void)
{
    u32 stack_1;
    u32 stack_2;

    switch (sQuickSaveRead->state) {
        case 0:
            sQuickSaveRead->state = 1;
            break;
        case 1:
            stack_1 = 16;

            if (sub_8011F9C(&stack_1, sQuickSaveRead->dest, sQuickSaveRead->size) == READ_SAVE_VALID) {
                sQuickSaveRead->saveValid = TRUE;
                sQuickSaveRead->state = 3;
            }
            else {
                CreateDialogueBoxAndPortrait(sSaveFailedExplanation, 0, 0, 0x301);
                sQuickSaveRead->state = 2;
            }
            break;
        case 2:
            if (sub_80144A4(&stack_2) == 0)
                sQuickSaveRead->state = 3;
            break;
        case 3:
            return FALSE;
        default:
            break;
    }
    return TRUE;
}

bool8 IsQuickSaveValid(void)
{
    return sQuickSaveRead->saveValid;
}

void FinishQuickSaveRead(void)
{
    if (sQuickSaveRead != NULL){
        MemoryFree(sQuickSaveRead);
        sQuickSaveRead = 0;
    }
}
