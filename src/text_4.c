#include "global.h"
#include "structs/str_text.h"
#include "text_1.h"
#include "text_4.h"

// These functions run from IWRAM for improved performance.

static void ScrollDownWindowInternal(Window *txtStructs, s32 id);
static void ScrollUpWindowInternal(Window *txtStructs, s32 id);
static void sub_82729B8(Window *txtStructs, s32 id);
static void sub_8272A8C(Window *txtStructs, s32 id);

IWRAM_INIT void ScrollDownWindow(s32 windowId)
{
    ScrollDownWindowInternal(gWindows, windowId);
}

IWRAM_INIT static void ScrollDownWindowInternal(Window *windows, s32 windowId)
{
    Window *window = &windows[windowId];

    if (window->heightInTiles > 0) {
        s32 i, j;
        u32 *dstPtr;
        s32 n;
        s32 id8, id9;

        if (window->type == WINDOW_TYPE_WITH_HEADER) {
            s32 unk4 = window->width;
            s32 dstAdd = ((window->unk24 + 2) * 8);
            dstAdd *= unk4;
            dstPtr = window->unk18 + dstAdd;
            n = window->heightInTiles - 2;
        }
        else {
            dstPtr = window->unk18;
            n = window->heightInTiles;
        }

        id8 = window->unk20 + 8;
        id9 = window->unk20 + 9;
        for (i = 0; i < window->width; i++) {
            s32 to = n - 1;
            u32 *loopPtr = dstPtr;
            for (j = 0; j < to; j++) {
                loopPtr[0] = loopPtr[2];
                loopPtr[1] = loopPtr[3];
                loopPtr[2] = loopPtr[4];
                loopPtr[3] = loopPtr[5];
                loopPtr[4] = loopPtr[6];
                loopPtr[5] = loopPtr[7];
                loopPtr[6] = loopPtr[id8];
                loopPtr[7] = loopPtr[id9];

                loopPtr += id8;
            }

            loopPtr[0] = loopPtr[2];
            loopPtr[1] = loopPtr[3];
            loopPtr[2] = loopPtr[4];
            loopPtr[3] = loopPtr[5];
            loopPtr[4] = loopPtr[6];
            loopPtr[5] = loopPtr[7];
            loopPtr[6] = 0;
            loopPtr[7] = 0;
            dstPtr += 8;
        }

        window->unk30 = window->unk28;
        window->unk34 = window->unk1C;
        window->unk38 = window->unk2C;
        window->unk44 = 1;
    }
}

IWRAM_INIT void ScrollUpWindow(s32 windowId)
{
    ScrollUpWindowInternal(gWindows, windowId);
}

IWRAM_INIT static void ScrollUpWindowInternal(Window *windows, s32 windowId)
{
    Window *window = &windows[windowId];

    if (window->heightInTiles > 0) {
        s32 i;
        s32 j;
        u32 *dstPtr;
        s32 n;
        s32 id8;
        s32 unk4;
        s32 unk8;
        s32 dstAdd;

        if (window->type == WINDOW_TYPE_WITH_HEADER) {
            n = window->heightInTiles - 2;
        }
        else {
            n = window->heightInTiles;
        }

        unk8 = window->heightInTiles - 1;
        unk4 = window->width;
        dstAdd = (unk8 * unk4) * 8;
        dstPtr = window->unk18 + dstAdd;

        id8 = window->unk20 + 8;
        for (i = 0; i < window->width; i++) {
            u32 lastTwo = 0;
            s32 to = n - 1;
            u32 *loopPtr = dstPtr;

            if (n < 2) {
                loopPtr[7] = loopPtr[5];
                loopPtr[6] = loopPtr[4];
                loopPtr[5] = loopPtr[3];
                loopPtr[4] = loopPtr[2];
                loopPtr[3] = loopPtr[1];
                loopPtr[2] = loopPtr[0];
                loopPtr[1] = lastTwo;
                loopPtr[0] = lastTwo;
            }
            else {
                u32 *ptr8 = dstPtr - id8;
                for (j = 0; j < to; j++) {
                    loopPtr[7] = loopPtr[5];
                    loopPtr[6] = loopPtr[4];
                    loopPtr[5] = loopPtr[3];
                    loopPtr[4] = loopPtr[2];
                    loopPtr[3] = loopPtr[1];
                    loopPtr[2] = loopPtr[0];
                    loopPtr[1] = ptr8[7];
                    loopPtr[0] = ptr8[6];

                    loopPtr -= id8;
                    ptr8 -= id8;
                }

                loopPtr[7] = loopPtr[5];
                loopPtr[6] = loopPtr[4];
                loopPtr[5] = loopPtr[3];
                loopPtr[4] = loopPtr[2];
                loopPtr[3] = loopPtr[1];
                loopPtr[2] = loopPtr[0];
                loopPtr[1] = 0;
                loopPtr[0] = 0;
            }
            dstPtr += 8;
        }

        window->unk30 = window->unk28;
        window->unk34 = window->unk1C;
        window->unk38 = window->unk2C;
        window->unk44 = 1;
    }
}

IWRAM_INIT void sub_82729A4(s32 id)
{
    sub_82729B8(gWindows, id);
}

IWRAM_INIT static void sub_82729B8(Window *windows, s32 id)
{
    s32 i, j;
    Window *window = &windows[id];
    u32 *dstPtr = window->unk18;
    s32 id8 = window->unk20 + 8;
    s32 id9 = window->unk20 + 9;

    for (i = 0; i < window->width; i++) {
        u32 *loopPtr;

        dstPtr[3] = dstPtr[5];
        dstPtr[4] = dstPtr[6];
        dstPtr[5] = dstPtr[7];
        dstPtr[6] = dstPtr[id8];
        dstPtr[7] = dstPtr[id9];

        loopPtr = dstPtr + id8;
        for (j = 0; j < 5; j++) {
            loopPtr[0] = loopPtr[2];
            loopPtr[1] = loopPtr[3];
            loopPtr[2] = loopPtr[4];
            loopPtr[3] = loopPtr[5];
            loopPtr[4] = loopPtr[6];
            loopPtr[5] = loopPtr[7];
            loopPtr[6] = loopPtr[id8];
            loopPtr[7] = loopPtr[id9];

            loopPtr += id8;
        }

        loopPtr[0] = loopPtr[2];
        loopPtr[1] = loopPtr[3];
        loopPtr[2] = loopPtr[4];
        loopPtr[3] = loopPtr[5];
        loopPtr[4] = 0;
        loopPtr[5] = 0;
        loopPtr[6] = 0;
        loopPtr[7] = 0;

        dstPtr += 8;
    }

    window->unk30 = window->unk28;
    window->unk34 = window->unk1C;
    window->unk38 = window->unk2C;
    window->unk44 = 1;
}

IWRAM_INIT void sub_8272A78(s32 id)
{
    sub_8272A8C(gWindows, id);
}

IWRAM_INIT static void sub_8272A8C(Window *windows, s32 id)
{
    s32 i, j;
    Window *window = &windows[id];
    u32 *dstPtr = window->unk18;
    s32 id8 = window->unk20 + 8;

    for (i = 0; i < window->width; i++) {
        u32 *loopPtr;

        dstPtr[3] = 0;
        dstPtr[4] = dstPtr[5];
        dstPtr[5] = dstPtr[6];
        dstPtr[6] = dstPtr[7];
        dstPtr[7] = dstPtr[id8];

        loopPtr = dstPtr + id8;
        for (j = 0; j < 5; j++) {
            loopPtr[0] = loopPtr[1];
            loopPtr[1] = loopPtr[2];
            loopPtr[2] = loopPtr[3];
            loopPtr[3] = loopPtr[4];
            loopPtr[4] = loopPtr[5];
            loopPtr[5] = loopPtr[6];
            loopPtr[6] = loopPtr[7];
            loopPtr[7] = loopPtr[id8];

            loopPtr += id8;
        }

        loopPtr[0] = loopPtr[1];
        loopPtr[1] = loopPtr[2];
        loopPtr[2] = loopPtr[3];
        loopPtr[3] = loopPtr[4];
        loopPtr[4] = loopPtr[5];
        loopPtr[5] = loopPtr[6];
        loopPtr[6] = loopPtr[7];
        loopPtr[7] = 0;

        dstPtr += 8;
    }

    window->unk30 = window->unk28;
    window->unk34 = window->unk1C;
    window->unk38 = window->unk2C;
    window->unk44 = 1;
}

#ifndef NONMATCHING
// Needed to match, because without it the alignment is different.
IWRAM_INIT static UNUSED u8 sMatchAlignment = 0;
#endif // NONMATCHING
