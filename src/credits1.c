#include "global.h"
#include "globaldata.h"
#include "code_8099360.h"
#include "credits1.h"
#include "event_flag.h"
#include "input.h"
#include "memory.h"
#include "text_1.h"
#include "text_3.h"

EWRAM_INIT static Credits1Work *sCredits1Work = {NULL};

static const WindowTemplate sDummyWinTemplate = WIN_TEMPLATE_DUMMY;
static const WindowTemplate gUnknown_80E4A28 = {
    .unk0 = 0,
    .type = WINDOW_TYPE_ONLY_TEXT,
    .pos = {2, 2},
    .width = 26,
    .height = 16,
    .unk10 = 16,
    .unk12 = 0,
    .header = NULL,
};

static const unkStruct_3000400 gUnknown_80E4A40 = {{0x18, 0x18, 0x38, 0}};

UNUSED static const u8 sUnknownUnusedData[][2] = {
    {0x21, 0xff},
    {0x22, 0xff},
    {0x23, 0xff},
    {0x24, 0xff},
    {0x25, 0xff},
    {0x26, 0xff},
    {0x27, 0xff},
    {0x28, 0xff},
    {0x29, 0xff},
    {0x2a, 0xff},
    {0x2b, 0xff},
    {0x2c, 0xff},
    {0x2d, 0xff},
    {0x2e, 0xff},
    {0x2f, 0xff},
    {0x30, 0xff},
    {0x31, 0xff},
    {0x32, 0xff},
    {0x33, 0xff},
    {0x34, 0xff},
    {0x35, 0xff},
    {0x36, 0xff},
    {0x37, 0xff},
    {0x38, 0xff},
    {0x39, 0xff},
    {0x3a, 0xff},
    {0x41, 0xff},
    {0x42, 0xff},
    {0x43, 0xff},
    {0x44, 0xff},
    {0x45, 0xff},
    {0x46, 0xff},
    {0x47, 0xff},
    {0x48, 0xff},
    {0x49, 0xff},
    {0x4a, 0xff},
    {0x4b, 0xff},
    {0x4c, 0xff},
    {0x4d, 0xff},
    {0x4e, 0xff},
    {0x4f, 0xff},
    {0x50, 0xff},
    {0x51, 0xff},
    {0x52, 0xff},
    {0x53, 0xff},
    {0x54, 0xff},
    {0x55, 0xff},
    {0x56, 0xff},
    {0x57, 0xff},
    {0x58, 0xff},
    {0x59, 0xff},
    {0x5a, 0xff},
    {0x10, 0xff},
    {0x11, 0xff},
    {0x12, 0xff},
    {0x13, 0xff},
    {0x14, 0xff},
    {0x15, 0xff},
    {0x16, 0xff},
    {0x17, 0xff},
    {0x18, 0xff},
    {0x19, 0xff}
};

extern const CreditsData* gCreditsTable[27];

bool8 DrawCredits(s32 creditsCategoryIndex, s32 param_2)
{
    s32 i;
    s32 x;
    s32 y;
    const CreditsData *cred;
    u8 *destText1;
    u8 *destText2;
    u8 curChar;
    u8 buffer[128];

    sCredits1Work = MemoryAlloc(sizeof(Credits1Work), 8);
    sCredits1Work->unk60 = 0;
    sCredits1Work->unk64 = param_2;
    sCredits1Work->creditsCategoryIndex = creditsCategoryIndex;

    for (i = 0; i < MAX_WINDOWS; i++)
        sCredits1Work->unk0.id[i] = sDummyWinTemplate;
    sCredits1Work->unk0.id[0] = gUnknown_80E4A28;

    ResetUnusedInputStruct();
    ShowWindows(&sCredits1Work->unk0, TRUE, TRUE);
    sub_8099690(2);
    sub_80073B8(0);

    cred = creditsCategoryIndex[gCreditsTable]; // WTF
    y = 0;
    while (cred->text != NULL) {
        const u8 *srcText = cred->text;
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
    sub_8099AFC(9, 0, gUnknown_80E4A40);
    return TRUE;
}

s32 sub_8035574(void)
{
    switch (sCredits1Work->unk60) {
        case 0:
            if (!sub_8099B94()) {
                sCredits1Work->unk60 = 1;
                sub_8099A5C(9, 30, gUnknown_80E4A40);
            }
            break;
        case 1:
            if (!sub_8099B94())
                sCredits1Work->unk60 = 2;
            break;
        case 2:
            if (sCredits1Work->unk64 < 1) {
                sCredits1Work->unk60 = 3;
                sub_8099AFC(9, 30, gUnknown_80E4A40);
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
            sub_8099A5C(1, 0, gUnknown_80E4A40);
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
