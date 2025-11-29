#include "global.h"
#include "globaldata.h"
#include "ground_lives_helper.h"
#include "constants/direction.h"
#include "input.h"
#include "game_options.h"
#include "ground_main.h"
#include "ground_script.h"
#include "ground_map.h"
#include "textbox.h"

extern void nullsub_104(void);
extern void sub_809C6CC(u16 param_1);

void nullsub_117(void)
{

}

void nullsub_118(void)
{

}

void sub_809CD68(struct GroundLives_Sub120 *dst)
{
    dst->unk0 = 0;
    dst->unk4 = 0;
    dst->unk10 = -1;
    dst->unk14 = 0;
    dst->unk8 = 0;
    dst->unk18 = 0;
}

static void sub_809CD7C(struct GroundLives_Sub120 *dst)
{
    dst->unk0 = 0;
    dst->unk10 = -1;
    dst->unk14 = 0;
    dst->unk8 = 0;
}

void sub_809CD8C(struct GroundLives_Sub120 *dst, s32 a1)
{
    if (a1 == 5) {
        sub_809CD68(dst);
        dst->unk0 = a1;
    }
    else if (dst->unk4 != a1) {
        dst->unk4 = a1;
        dst->unk10 = -1;
        dst->unk14 = 0;
    }
}

s32 sub_809CDB8(struct GroundLives_Sub120 *dst)
{
    s32 ret = dst->unk4;
    if (ret == 0) {
        ret = dst->unk0;
    }
    return ret;
}

u32 sub_809CDC8(struct GroundLives_Sub120 *strPtr, u32 *r6, s8 *direction, s32 *param_4, PixelPos *unused, u32 flags)
{
    u32 sp_4;
    s32 sp;
    s32 r8;

    param_4[0] = -1;

    switch (strPtr->unk0) {
        case 1:
            if (flags & 0x2000) {
                sub_809CD68(strPtr);
                strPtr->unk0 = 2;
            }
            break;
        case 2:
            if (!(flags & 0x2000)) {
                sub_809CD68(strPtr);
                strPtr->unk0 = 1;
            }
            break;
    }

    r8 = strPtr->unk4;
    if (r8 == 0)
        r8 = strPtr->unk0;

    switch (r8) {
        case 1:
        {
            u16 held = gRealInputs.held;
            u16 pressed = gRealInputs.pressed;
            if (held & DPAD_ANY) {
                if (held & B_BUTTON) {
                    strPtr->unk10 = 0;
                }
                else {
                    strPtr->unk10 = -1;
                }
            }
            else if (pressed & B_BUTTON) {
                 strPtr->unk10 = 0x14;
            }
            else if (strPtr->unk10 > 1) {
                 strPtr->unk10--;
                 if (!(held & B_BUTTON)) {
                     *r6 = 0x13;
                     *direction = -1;
                     return 5;
                 }
            }
            else {
                strPtr->unk10 = -1;
            }

            if (pressed & A_BUTTON) {
                *r6 = 10;
            }
            else if (strPtr->unk10 == 0) {
                *r6 = 8;
            }
            else {
                *r6 = 7;
            }

            *direction = DpadToDirection(held);
            return strPtr->unk0;
        }
        case 5:
            if (sub_809B260(&sp)) {
                if (gGameOptionsRef->unkC == 0)
                    sub_809C6CC(4);
                else
                    sub_809C6CC(3);

                nullsub_104();
                sub_809CD7C(strPtr);
                strPtr->unk0 = 1;

                switch (sp) {
                    case 3:
                        strPtr->unk0 = 4;
                        *r6 = 1;
                        *direction = -1;
                        return 4;
                    case 2:
                        strPtr->unk0 = 4;
                        sub_8098D80(0x1E);
                        *r6 = 1;
                        *direction = -1;
                        return strPtr->unk0;
                    case 1:
                        strPtr->unk0 = 4;
                        *r6 = 1;
                        *direction = -1;
                        return 4;
                    case 4:
                        strPtr->unk0 = 4;
                        GroundMap_ExecuteEvent(FORMATION_HERO, FALSE);
                        *r6 = 1;
                        *direction = -1;
                        return strPtr->unk0;
                }
                GroundScriptLockJumpZero(2);
            }
            break;
        case 6:
        case 7:
             if (sub_809B260(&sp_4)) {
                sub_809CD7C(strPtr);
                strPtr->unk0 = 1;
                return strPtr->unk0;
             }
             break;
        case 2:
            {
                if (strPtr->unk8 >= 1) {
                    strPtr->unk8--;
                    *r6 = 9;
                    *direction = strPtr->unkC;
                }
                else {
                    s32 v;
                    u16 held = gRealInputs.held;
                    *r6 = 9;
                    if (held & 0x40) {
                        *direction = 4;
                    }
                    else if (held & 0x80) {
                        *direction = 0;
                    }
                    else {
                        *direction = -1;
                    }

                    // TODO: Fix me, this should be a simple -1 comparision, but agbcc doesn't want to cooperate...
                    v = strPtr->unkC = *direction;
                    if (CMP_S8_NOT_MINUS1(v)) {
                        strPtr->unk8 = 0x20;
                    }
                }
            }
            return r8;
    }

    *r6 = 0;
    *direction = -1;
    return r8;
}

s32 DpadToDirection(u16 dpad)
{
    if (dpad & DPAD_UP) {
        if (dpad & DPAD_RIGHT)
            return DIRECTION_NORTHEAST;
        else if (dpad & DPAD_LEFT)
            return DIRECTION_NORTHWEST;
        else
            return DIRECTION_NORTH;
    }
    else if (dpad & DPAD_DOWN) {
        if (dpad & DPAD_RIGHT)
            return DIRECTION_SOUTHEAST;
        else if (dpad & DPAD_LEFT)
            return DIRECTION_SOUTHWEST;
        else
            return DIRECTION_SOUTH;
    }
    else if (dpad & DPAD_RIGHT)
        return DIRECTION_EAST;
    else if (dpad & DPAD_LEFT)
        return DIRECTION_WEST;

    return -1;
}

UNUSED static s32 sub_809D058(s32 *param_1)
{
  if (param_1[1] < 0x40) {
    if (param_1[0]  < 0x68) {
        return 5;
    }
    else if (param_1[0]  > 0x88) {
        return 3;
    }
    else {
        return 4;
    }
  }
  else if (param_1[1] > 0x60) {
    if (param_1[0]  < 0x68) {
        return 7;
    }
    else if (param_1[0]  > 0x88) {
        return 1;
    }
    else {
        return 0;
    }
  }
  else if (param_1[0]  < 0x68) {
        return 6;
  }
  else if (param_1[0]  > 0x88) {
       return 2;
  }
  else {
       return -1;
  }
}

