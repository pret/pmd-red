#include "global.h"
#include "reg_control.h"

extern struct unkStruct_202D648 gUnknown_202D608[8];
extern struct unkStruct_202D648 gUnknown_202D648[8];

// Unused?
s32 sub_800B720(s16 a0, IntrCallback a1)
{
    s32 r2;
    struct unkStruct_202D648 *r3;
    s32 r4;
    bool8 sp4;
    s32 spC;
    bool32 sp10;

    spC = a0;
    sp4 = DisableInterrupts();

    do {
        sp10 = FALSE;
        r4 = 0;
        r3 = gUnknown_202D608;
        if (r4 >= gUnknown_203B0AA)
            continue;
        if (r3->unk0 == gUnknown_203B0A8) {
            gUnknown_203B0A8 = (gUnknown_203B0A8 + 1) & 0x7fff;
            sp10 = TRUE;
            continue;
        }
    label:
        do {
            r4++;
            r3++;
            if (r4 >= gUnknown_203B0AA)
                continue;
            if (r3->unk0 == gUnknown_203B0A8) {
                gUnknown_203B0A8 = (gUnknown_203B0A8 + 1) & 0x7fff;
                sp10 = TRUE;
            }
            else
                goto label;
        } while (0);
    } while (sp10);

    for (r4 = 0, r3 = gUnknown_202D608; r4 < gUnknown_203B0AA; r4++, r3++) {
        if (r3->unk2 > spC)
            break;
    }

    for (r2 = gUnknown_203B0AA - 1, r3 = &gUnknown_202D608[r2]; r2 >= r4; r2--, r3--)
        r3[1] = r3[0];

    gUnknown_203B0AA++;
    gUnknown_202D608[r4].unk0 = gUnknown_203B0A8;
#ifdef NONMATCHING
    gUnknown_202D608[r4].unk2 = spC;
#else
    gUnknown_202D608[r4].unk2 = ((u32)spC << 0x10 >> 0x10); // fake and may overflow. Unspecified behavior
#endif
    gUnknown_202D608[r4].unk4 = a1;

    if (sp4)
        EnableInterrupts();

    return gUnknown_203B0A8;
}

// Unused?
void sub_800B850(s16 a0)
{
    s32 r2;
    struct unkStruct_202D648 *r4;
    bool8 r5;
    s32 r6;

    r6 = a0;
    r5 = DisableInterrupts();

    r2 = 0;
    r4 = &gUnknown_202D608[r2];
    r4++; r4--;
    for (; r2 < gUnknown_203B0AA; r2++, r4++) {
        if (r4->unk0 != r6)
            continue;

        gUnknown_203B0AA--;
        for (; r2 < gUnknown_203B0AA; r2++, r4++)
            r4[0] = r4[1];

        if (!r5)
            return;
        EnableInterrupts();
        return;
    }

    if (r5)
        EnableInterrupts();
}

void UnusedIntrFunc(void)
{
}