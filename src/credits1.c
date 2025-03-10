#include "global.h"
#include "code_8099360.h"
#include "credits1.h"
#include "event_flag.h"
#include "input.h"
#include "memory.h"
#include "text.h"

static EWRAM_INIT Credits1Work *sCredits1Work = {NULL};

extern const WindowTemplate gUnknown_80E4A10;
extern const WindowTemplate gUnknown_80E4A28;
extern const u32 gUnknown_80E4A40[];
extern const CreditsData* gCreditsTable[27];

bool8 DrawCredits(s32 creditsCategoryIndex, s32 param_2)
{
    s32 i;
    s32 x;
    s32 y;
    const CreditsData *cred;
    u8 *srcText;
    u8 *destText1;
    u8 *destText2;
    u8 curChar;
    u8 buffer[128];

    sCredits1Work = MemoryAlloc(sizeof(Credits1Work), 8);
    sCredits1Work->unk60 = 0;
    sCredits1Work->unk64 = param_2;
    sCredits1Work->creditsCategoryIndex = creditsCategoryIndex;

    for (i = 0; i < 4; i++)
        sCredits1Work->unk0.id[i] = gUnknown_80E4A10;
    sCredits1Work->unk0.id[0] = gUnknown_80E4A28;

    ResetUnusedInputStruct();
    ShowWindows(&sCredits1Work->unk0, TRUE, TRUE);
    sub_8099690(2);
    sub_80073B8(0);

    cred = creditsCategoryIndex[gCreditsTable]; // WTF
    y = 0;
    while (cred->text != NULL) {
        srcText = cred->text;
        if (cred->y >= 0)
            y = cred->y;
        else
            y -= cred->y;
        x = cred->x;

        switch (cred->type) {
            case 1:
                destText1 = buffer;
                while ((curChar = *srcText) != 0) {
                    *destText1 = curChar;
                    srcText++;
                    destText1++;
                }
                *destText1 = 0;
                srcText = buffer;
                break;
            case 2:
                destText2 = buffer;
                while ((curChar = *srcText) != 0) {
                    *destText2 = curChar;
                    srcText++;
                    destText2++;
                }
                *destText2 = 0;
                srcText = buffer;
                break;
        }

        PrintStringOnWindow(x, y, srcText, 0, 0);
        cred++;
    }

    sub_80073E0(0);
    SelectCharmap(0);
    do {
        const u32 *a = gUnknown_80E4A40;
        int b = 9;
        unsigned long long c = b;
        sub_8099AFC(c, 0, a[0]);
    } while(0);
    return TRUE;
}

s32 sub_8035574(void)
{
    #ifdef NONMATCHING
    u32 const *p;
    #else
    register u32 const *p asm("r2");
    #endif

    switch (sCredits1Work->unk60) {
        case 0:
            if (!sub_8099B94()) {
                sCredits1Work->unk60 = 1;
                p = gUnknown_80E4A40;
                sub_8099A5C(9, 30, p[0]); // Probably same/similar macro from the above func - Kermalis
            }
            break;
        case 1:
            if (!sub_8099B94())
                sCredits1Work->unk60 = 2;
            break;
        case 2:
            if (sCredits1Work->unk64 < 1) {
                sCredits1Work->unk60 = 3;
                p = gUnknown_80E4A40;
                sub_8099AFC(9, 30, p[0]);
            }
            sCredits1Work->unk64--;
            break;
        case 3:
            if (!sub_8099B94()) {
                ResetUnusedInputStruct();
                ShowWindows(NULL, TRUE, TRUE);
                sCredits1Work->unk60 = 4;
            }
            break;
        case 4:
            sub_8099690(0);
            p = gUnknown_80E4A40;
            sub_8099A5C(1, 0, p[0]);
            return 3;
    }
    return 0;
}

void sub_803565C(void)
{
    if (sCredits1Work != NULL) {
        MemoryFree(sCredits1Work);
        sCredits1Work = NULL;
    }
}
