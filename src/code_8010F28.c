#include "global.h"
#include "sprite.h"
#include "code_8004AA0.h"
#include "input.h"

static inline bool8 CheckAxFlag8000(axdata *ptr)
{
    return (ptr->flags & 0x8000) != 0;
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
