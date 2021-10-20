#include "global.h"
#include "input.h"


extern void nullsub_34(struct UnkInputStruct *r0);
u32 sub_8012AE8(void);

u32 sub_8012A64(struct UnkInputStruct *r0, u32 r1)
{
    if(r0 == NULL)
    {
        return sub_8012AE8();
    }
    if(r1 != -1)
    {
        nullsub_34(r0);
    }
    if(r0->unk1 != 0)
    {
        r0->unk1 = 0;
        return 1;
    }
    if(r0->unk2 == 0)
    {
        return sub_8012AE8();
    }
    r0->unk2 = r0->unk1;
    return 2;
}

u32 GetKeyPress(struct UnkInputStruct *r0)
{
    if(r0 != NULL)
    {
        if(r0->a_button != 0)
        {
            return 1;
        }
        if(r0->b_button != 0)
        {
            return 2;
        }
        if(r0->dpad_left != 0)
        {
            return 9;
        }
        if(r0->dpad_right != 0)
        {
            return 10;
        }
    }
    return sub_8012AE8();
}

u32 sub_8012AE8(void)
{
  if ((gRealInputs.held & R_BUTTON) != 0) {
    if ((gRealInputs.pressed & A_BUTTON) != 0) {
        return 11;
    }
    if ((gRealInputs.repeated & DPAD_UP) != 0) {
        return 12;
    }
    if ((gRealInputs.repeated & DPAD_DOWN) != 0) {
        return 13;
    }
    if ((gRealInputs.repeated & DPAD_LEFT) != 0) {
        return 14;
    }
    if ((gRealInputs.repeated & DPAD_RIGHT) != 0) {
        return 15;
    }
    if ((gRealInputs.repeated & R_BUTTON) != 0) {
        return  6;
    }
  }
  else
  {
    if ((gRealInputs.pressed & A_BUTTON) != 0) {
        return 1;
    }
    if ((gRealInputs.pressed & B_BUTTON) != 0) {
        return 2;
    }
    if ((gRealInputs.pressed & SELECT_BUTTON) != 0) {
        return 3;
    }
    if ((gRealInputs.pressed & START_BUTTON) != 0) {
        return 4;
    }
    if ((gRealInputs.repeated & DPAD_UP) != 0) {
        return 7;
    }
    if ((gRealInputs.repeated & DPAD_DOWN) != 0) {
        return 8;
    }
    if ((gRealInputs.repeated & DPAD_LEFT) != 0) {
        return 9;
    }
    if ((gRealInputs.repeated & DPAD_RIGHT) != 0) {
        return 10;
    }
    if ((gRealInputs.repeated & L_BUTTON) != 0) {
        return 5;
    }
  }
  return 0;
}

