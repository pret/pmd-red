#include "global.h"
#include "constants/input.h"
#include "input.h"


extern void nullsub_34(struct UnkInputStructSub *r0);
u32 sub_8012AE8(void);

u32 sub_8012A64(struct UnkInputStructSub *r0, u32 r1)
{
    if(r0 == NULL)
    {
        return sub_8012AE8();
    }
    if(r1 != -1)
    {
        nullsub_34(r0);
    }
    if(r0->a_button != 0)
    {
        r0->a_button = 0;
        return INPUT_A_BUTTON;
    }
    else if(r0->b_button == 0)
    {
        return sub_8012AE8();
    }
    else
    {
        r0->b_button = 0;
        return INPUT_B_BUTTON;
    }
}

u32 GetKeyPress(struct UnkInputStruct *r0)
{
    if(r0 != NULL)
    {
        if(r0->unk28.a_button != 0)
        {
            return INPUT_A_BUTTON;
        }
        if(r0->unk28.b_button != 0)
        {
            return INPUT_B_BUTTON;
        }
        if(r0->unk28.dpad_left != 0)
        {
            return INPUT_DPAD_LEFT;
        }
        if(r0->unk28.dpad_right != 0)
        {
            return INPUT_DPAD_RIGHT;
        }
    }
    return sub_8012AE8();
}

u32 sub_8012AE8(void)
{
  if ((gRealInputs.held & R_BUTTON) != 0) {
    if ((gRealInputs.pressed & A_BUTTON) != 0) {
        return INPUT_R_A_BUTTONS;
    }
    if ((gRealInputs.repeated & DPAD_UP) != 0) {
        return INPUT_R_DPAD_UP_BUTTONS;
    }
    if ((gRealInputs.repeated & DPAD_DOWN) != 0) {
        return INPUT_R_DPAD_DOWN_BUTTONS;
    }
    if ((gRealInputs.repeated & DPAD_LEFT) != 0) {
        return INPUT_R_DPAD_LEFT_BUTTONS;
    }
    if ((gRealInputs.repeated & DPAD_RIGHT) != 0) {
        return INPUT_R_DPAD_RIGHT_BUTTONS;
    }
    if ((gRealInputs.repeated & R_BUTTON) != 0) {
        return INPUT_R_BUTTON;
    }
  }
  else
  {
    if ((gRealInputs.pressed & A_BUTTON) != 0) {
        return INPUT_A_BUTTON;
    }
    if ((gRealInputs.pressed & B_BUTTON) != 0) {
        return INPUT_B_BUTTON;
    }
    if ((gRealInputs.pressed & SELECT_BUTTON) != 0) {
        return INPUT_SELECT_BUTTON;
    }
    if ((gRealInputs.pressed & START_BUTTON) != 0) {
        return INPUT_START_BUTTON;
    }
    if ((gRealInputs.repeated & DPAD_UP) != 0) {
        return INPUT_DPAD_UP;
    }
    if ((gRealInputs.repeated & DPAD_DOWN) != 0) {
        return INPUT_DPAD_DOWN;
    }
    if ((gRealInputs.repeated & DPAD_LEFT) != 0) {
        return INPUT_DPAD_LEFT;
    }
    if ((gRealInputs.repeated & DPAD_RIGHT) != 0) {
        return INPUT_DPAD_RIGHT;
    }
    if ((gRealInputs.repeated & L_BUTTON) != 0) {
        return INPUT_L_BUTTON;
    }
  }
  return INPUT_NONE;
}

