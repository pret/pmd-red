#include "global.h"
#include "globaldata.h"
#include "code_8099360.h"
#include "credits1.h"
#include "event_flag.h"
#include "input.h"
#include "memory.h"
#include "palette_util.h"
#include "text_1.h"
#include "text_3.h"

EWRAM_INIT static Credits1Work *sCredits1Work = { NULL };

static const WindowTemplate sDummyWinTemplate = WIN_TEMPLATE_DUMMY;

static const WindowTemplate gUnknown_80E4A28 = {
    .flags = WINTEMPLATE_FLAG_NONE,
    .type = WINDOW_TYPE_ONLY_TEXT,
    .pos = { 2, 2 },
    .width = 26,
    .height = 16,
    .totalHeight = 16,
    .unk12 = 0,
    .header = NULL,
};

static const RGB_Array gUnknown_80E4A40 = {{0x18, 0x18, 0x38, 0}};

UNUSED static const u8 sUnknownUnusedData[][2] = {
    { 0x21, 0xFF },
    { 0x22, 0xFF },
    { 0x23, 0xFF },
    { 0x24, 0xFF },
    { 0x25, 0xFF },
    { 0x26, 0xFF },
    { 0x27, 0xFF },
    { 0x28, 0xFF },
    { 0x29, 0xFF },
    { 0x2A, 0xFF },
    { 0x2B, 0xFF },
    { 0x2C, 0xFF },
    { 0x2D, 0xFF },
    { 0x2E, 0xFF },
    { 0x2F, 0xFF },
    { 0x30, 0xFF },
    { 0x31, 0xFF },
    { 0x32, 0xFF },
    { 0x33, 0xFF },
    { 0x34, 0xFF },
    { 0x35, 0xFF },
    { 0x36, 0xFF },
    { 0x37, 0xFF },
    { 0x38, 0xFF },
    { 0x39, 0xFF },
    { 0x3A, 0xFF },
    { 0x41, 0xFF },
    { 0x42, 0xFF },
    { 0x43, 0xFF },
    { 0x44, 0xFF },
    { 0x45, 0xFF },
    { 0x46, 0xFF },
    { 0x47, 0xFF },
    { 0x48, 0xFF },
    { 0x49, 0xFF },
    { 0x4A, 0xFF },
    { 0x4B, 0xFF },
    { 0x4C, 0xFF },
    { 0x4D, 0xFF },
    { 0x4E, 0xFF },
    { 0x4F, 0xFF },
    { 0x50, 0xFF },
    { 0x51, 0xFF },
    { 0x52, 0xFF },
    { 0x53, 0xFF },
    { 0x54, 0xFF },
    { 0x55, 0xFF },
    { 0x56, 0xFF },
    { 0x57, 0xFF },
    { 0x58, 0xFF },
    { 0x59, 0xFF },
    { 0x5A, 0xFF },
    { 0x10, 0xFF },
    { 0x11, 0xFF },
    { 0x12, 0xFF },
    { 0x13, 0xFF },
    { 0x14, 0xFF },
    { 0x15, 0xFF },
    { 0x16, 0xFF },
    { 0x17, 0xFF },
    { 0x18, 0xFF },
    { 0x19, 0xFF }
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
    sub_8099AFC(PALUTIL_KIND_09, 0, gUnknown_80E4A40);
    return TRUE;
}

s32 sub_8035574(void)
{
    switch (sCredits1Work->unk60) {
        case 0:
            if (!sub_8099B94()) {
                sCredits1Work->unk60 = 1;
                sub_8099A5C(PALUTIL_KIND_09, 30, gUnknown_80E4A40);
            }
            break;
        case 1:
            if (!sub_8099B94())
                sCredits1Work->unk60 = 2;
            break;
        case 2:
            if (sCredits1Work->unk64 < 1) {
                sCredits1Work->unk60 = 3;
                sub_8099AFC(PALUTIL_KIND_09, 30, gUnknown_80E4A40);
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
            sub_8099A5C(PALUTIL_KIND_01, 0, gUnknown_80E4A40);
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
