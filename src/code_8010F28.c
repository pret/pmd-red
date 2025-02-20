#include "global.h"
#include "sprite.h"
#include "code_8004AA0.h"
#include "input.h"
#include "text.h"
#include "code_8009804.h"
#include "bg_palette_buffer.h"

static inline bool8 CheckAxFlag8000(axdata *ptr)
{
    return (ptr->flags & 0x8000) != 0;
}

static inline bool8 ResetFlags(axdata *ptr)
{
    return ptr->flags = 0;
}

extern const DungeonPos gUnknown_80D40C4[];

void sub_8010F28(void)
{
    s32 i;
    unkStruct_2039DB0 var_30;
    DungeonPos pos;

    sub_8004E8C(&var_30);
    var_30.unk4 = 0xF3FF;
    var_30.unkA = 0x800;
    pos = gUnknown_203B0E4->unk4DD4;
    RunAxAnimationFrame(&gUnknown_203B0E4->unk4C10);
    DoAxFrame_800558C(&gUnknown_203B0E4->unk4C10, gUnknown_203B0E4->unk4DD8 - pos.x, gUnknown_203B0E4->unk4DDA - pos.y, 3, gUnknown_203B0E4->unk4DD0, &var_30);

    for (i = 0; i < 32; i++) {
        struct UnkStruct_4018 *r0 = &gUnknown_203B0E4->unk4018[i];
        struct UnkStruct_4014Ptr *r5 = &gUnknown_203B0E4->unk4014->array[i];
        if (r0->unk4018 != 0) {
            RunAxAnimationFrame(&r0->unk14);
            DoAxFrame_800558C(&r0->unk14, r5->unk4.x - pos.x, r5->unk4.y- pos.y, 1, 0, &var_30);
        }
    }

{
    s32 i;
    for (i = 0; i < 8; i++) {
        if (CheckAxFlag8000(&gUnknown_203B0E4->unk4A30[i])) {
            RunAxAnimationFrame(&gUnknown_203B0E4->unk4A30[i]);
            if (!(gRealInputs.held & R_BUTTON) || (i % 2) != 0) {
                DoAxFrame_800558C(&gUnknown_203B0E4->unk4A30[i],
                                  (gUnknown_80D40C4[i].x + gUnknown_203B0E4->unk4DD8) - pos.x,
                                  (gUnknown_80D40C4[i].y + gUnknown_203B0E4->unk4DDA) - pos.y,
                                  2, 0, &var_30);
            }
        }
    }
}
}

void sub_80110B0(void)
{
    s32 i, j;
    s32 y1 = gUnknown_203B0E4->unk4DD4.y >> 3;
    s32 y2 = y1;

    for (i = 0; i < 21; i++) {
        s32 x1 = gUnknown_203B0E4->unk4DD4.x >> 3;
        s32 x2 = x1;

        for (j = 0; j < 31; j++) {
            x1 &= 0x1F;
            y1 &= 0x1F;

            gUnknown_202B038[2][y1][x1] = gUnknown_203B0E4->unk2014[y2][x2];
            gUnknown_202B038[3][y1][x1] = gUnknown_203B0E4->unk14[y2][x2];
            x2++;
            x1++;
        }
        y2++;
        y1++;
    }

    sub_80098F8(2);
    sub_80098F8(3);
}

void sub_8011168(void)
{
    s32 i;

    xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
    gUnknown_203B0E4->unk4DDC = 0;
    gUnknown_203B0E4->unk4DE0 = 0;
    gUnknown_203B0E4->unk4DE4 = 0;
    gUnknown_203B0E4->unk4DE8 = 0;
    for (i = 0; i < 8; i++) {
        ResetFlags(&gUnknown_203B0E4->unk4A30[i]);
    }
}

bool8 sub_80111C4(void)
{
    bool8 ret = FALSE;

    if (gUnknown_203B0E4->unk4DCC < 31) {
        s32 i;
        RGB *color = (void *) gUnknown_203B0E4->unk0[0]->data;

        if (++gUnknown_203B0E4->unk4DCC >= 31) {
            gUnknown_203B0E4->unk4DCC = 31;
        }

        for (i = 0; i < 224; color++, i++) {
            SetBGPaletteBufferColorRGB(i, color, gUnknown_203B0E4->unk4DCC, NULL);
        }

        color = (void *) gUnknown_203B0E4->unk0[1]->data;
        for (i = 0; i < 240; color++, i++) {
            SetBGPaletteBufferColorRGB(i + 256, color, gUnknown_203B0E4->unk4DCC, NULL);
        }

        ret = TRUE;
    }

    return ret;
}

void sub_8011240(void)
{
    if (gUnknown_203B0E4->unk4DD8 - gUnknown_203B0E4->unk4DD4.x < 48) {
        gUnknown_203B0E4->unk4DD4.x = gUnknown_203B0E4->unk4DD8 - 48;
    }
    else if (gUnknown_203B0E4->unk4DD8 - gUnknown_203B0E4->unk4DD4.x > 192) {
        gUnknown_203B0E4->unk4DD4.x = gUnknown_203B0E4->unk4DD8 - 192;
    }

    if (gUnknown_203B0E4->unk4DDA - gUnknown_203B0E4->unk4DD4.y < 48) {
        gUnknown_203B0E4->unk4DD4.y = gUnknown_203B0E4->unk4DDA - 48;
    }
    else if (gUnknown_203B0E4->unk4DDA - gUnknown_203B0E4->unk4DD4.y > 112) {
        gUnknown_203B0E4->unk4DD4.y = gUnknown_203B0E4->unk4DDA - 112;
    }

    if (gUnknown_203B0E4->unk4DD4.x < 0) {
        gUnknown_203B0E4->unk4DD4.x = 0;
    }
    if (gUnknown_203B0E4->unk4DD4.y < 0) {
        gUnknown_203B0E4->unk4DD4.y = 0;
    }
    if (gUnknown_203B0E4->unk4DD4.x > 239) {
        gUnknown_203B0E4->unk4DD4.x = 239;
    }
    if (gUnknown_203B0E4->unk4DD4.y > 151) {
        gUnknown_203B0E4->unk4DD4.y = 151;
    }
}

void sub_8011300(void)
{
    s32 i;
    struct UnkStruct_4018 *r9 = &gUnknown_203B0E4->unk4018[gUnknown_203B0E4->unk4A18];

    for (i = 0; i < 8; i++) {
        ResetFlags(&gUnknown_203B0E4->unk4A30[i]);
        if (r9->unk2[i] >= 0) {
            struct UnkStruct_4018 *ptr = &gUnknown_203B0E4->unk4018[r9->unk2[i]];
            if (ptr->unk4018 != 0) {
                AxResInitFile(&gUnknown_203B0E4->unk4A30[i], gUnknown_203B0E4->unk0[2], i + 4, 0, 0x40, 0, TRUE);
            }
        }
    }
}
