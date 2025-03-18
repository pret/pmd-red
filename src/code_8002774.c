#include "global.h"
#include "code_8002774.h"
#include "constants/direction.h"
#include "structs/str_position.h"
#include "other_random.h"

#define UNK_STRUCT_ARR_COUNT 4

struct S
{
    u8 x0[UNK_STRUCT_ARR_COUNT];
};

u16 sub_8002774(struct S s)
{
    return ((s.x0[2] & 0xF8) << 7) | ((s.x0[1] & 0xF8) << 2) | ((s.x0[0] & 0xF8) >> 3);
}

struct S sub_80027A0(u16 a0)
{
    struct S ret;

    ret.x0[0] = (a0 & 0x1F)      << 3 | ((a0 & 1)     ? 7 : 0);
    ret.x0[1] = (a0 & 0x3E0)     >> 2 | ((a0 & 0x20)  ? 7 : 0);
    ret.x0[2] = (a0 & 0x7C00)    >> 7 | ((a0 & 0x400) ? 7 : 0);
    ret.x0[3] = 0;
    return ret;
}

UNUSED static void sub_8002804(struct S *r0, s32 r1, struct S *r2)
{
    s32 i;

    for (i = 0; i < UNK_STRUCT_ARR_COUNT; i++) {
        r0->x0[i] = (r1 * r2->x0[i]) / 256;
    }
}

UNUSED static void sub_800282C(struct S *dst, s32 a1, struct S *a2, struct S *a3)
{
    s32 i, j;
    float spFloats[4];
    float floatsMul[4];
    float f0 = 1.0f / a1;

    for (i = 0; i < 4; i++) {
        s8 asSigned = (s8) a2->x0[i];
        float f = (float)(asSigned);
        if (asSigned < 0) {
            f += 256.0f;
        }
        spFloats[i] = f;
        floatsMul[i] = (float)(a3->x0[i] - a2->x0[i]) * f0;
    }

    *dst++ = *a2;
    for (i = 1; i < a1 - 1; dst++, i++) {
        for (j = 0; j < 4; j++) {
            dst->x0[j] = (unsigned int)((spFloats[j] += floatsMul[j]));
        }
    }

    *dst = *a3;
}

// File split here?

extern PixelPos gVectorDirections[8];

void sub_800290C(PixelPos *param_1, s32 param_2)
{
    if (param_1->x > param_2)
        param_1->x = param_2;
    else if (param_1->x < -param_2)
        param_1->x = -param_2;
    if (param_1->y > param_2)
        param_1->y = param_2;
    else if(param_1->y < -param_2)
        param_1->y = -param_2;
}

void sub_8002934(PixelPos *param_1, PixelPos *param_2, PixelPos *param_3, s32 param_4, s32 param_5)
{
    s32 r9 = (param_4 + param_5);
    param_1->x = (param_4 * param_2->x + param_5 * param_3->x) / r9;
    param_1->y = (param_4 * param_2->y + param_5 * param_3->y) / r9;
}

static inline s8 sub_8002984_sub(s32 direction1, s32 rand, s32 add, s32 multi)
{
    return (s8)(((direction1 + add) + OtherRandInt(rand) * multi) % NUM_DIRECTIONS);
}

s32 sub_8002984(s32 _direction1, u32 caseID)
{
  s32 direction1;

  direction1 = (s8)_direction1;
  switch((u8)caseID) {
      case 1:
        if (direction1 >= 0) {
            direction1 += 7;
            direction1 &= DIRECTION_MASK;
        }
        break;
      case 2:
        if (direction1 >= 0) {
            direction1 += 1;
            direction1 &= DIRECTION_MASK;
        }
        break;
      case 3:
        if (direction1 >= 0) {
            direction1 += 6;
            direction1 &= DIRECTION_MASK;
        }
        break;
      case 4:
        if (direction1 >= 0) {
            direction1 += 2;
            direction1 &= DIRECTION_MASK;
        }
        break;
      case 5:
        if (direction1 >= 0) {
            direction1 += 4;
            direction1 &= DIRECTION_MASK;
        }
        break;
      case 6:
        if ((direction1 & 1) != 0) {
            direction1 = sub_8002984_sub(direction1, 2, 7, 2);
        }
        else
        {
             direction1 = sub_8002984_sub(direction1, 3, 6, 2);
        }
        break;
      case 7:
        direction1 = sub_8002984_sub(direction1, 3, 7, 1);
        break;
      case 8:
        direction1 =  (s8)(OtherRandInt(NUM_DIRECTIONS) & 0xfe);
        break;
      case 9:
        direction1 =  (s8)OtherRandInt(NUM_DIRECTIONS);
        break;
      default:
        break;
  }
  return direction1;
}


s32 sub_8002A70(s32 _direction1, s32 _direction2, s32 _caseId)
{
    s32 direction1 = (s8)(_direction1);
    s32 direction2 = (s8)(_direction2);
    s32 caseId = (u8)(_caseId);

    if (direction1 == direction2)
        return direction1;

    switch (caseId) {
        case 1:
            if (direction1 >= 0) {
                direction1 += 7;
                direction1 &= DIRECTION_MASK;
            }
            break;
        case 2:
            if (direction1 >= 0) {
                direction1 += 1;
                direction1 &= DIRECTION_MASK;
            }
            break;
        case 3:
            if (direction1 >= 0) {
                direction1 += 6;
                direction1 &= DIRECTION_MASK;
            }
            break;
        case 4:
            if (direction1 >= 0) {
                direction1 += 2;
                direction1 &= DIRECTION_MASK;
            }
            break;
        case 11:
            direction1 = sub_8002B04(direction1, direction2);
            // Fallthrough
        case 10:
            direction1 = sub_8002B04(direction1, direction2);
            break;
    }
    return direction1;
}

s32 sub_8002B04(s32 _direction1, s32 _direction2)
{
    s32 direction1 = (s8)(_direction1);
    s32 direction2 = (s8)(_direction2);

    if (direction2 != -1)
    {
        s32 newDirection = ((direction2 + NUM_DIRECTIONS) - direction1) % NUM_DIRECTIONS;

        if (newDirection != 0) {
            if (newDirection < 4)
                newDirection = (direction1 + 1) % NUM_DIRECTIONS;
            else
                newDirection = (direction1 + 7) % NUM_DIRECTIONS;

            direction1 = (s8)newDirection;
        }
    }
    return direction1;
}

UNUSED s32 sub_8002B5C(s32 _direction1, s32 _direction2)
{
    int newDirection;
    int direction1;
    int direction2;

    direction1 = (s8)_direction1;
    direction2 = (s8)_direction2;

    if (direction2 != -1) {
        newDirection = ((direction2 + NUM_DIRECTIONS) - direction1) % NUM_DIRECTIONS;

        if (newDirection != 0) {
            if (newDirection < 4) {
                newDirection = (direction1 + 2) % NUM_DIRECTIONS;
            }
            else {
                newDirection = (direction1 + 6) % NUM_DIRECTIONS;
            }
            direction1 = (s8)(newDirection);
        }
    }
    return direction1 & DIRECTION_MASK_CARDINAL;
}

PixelPos SetVecFromDirectionSpeed(s8 r1, u32 r2)
{
    PixelPos *vec = &gVectorDirections[r1];

    return (PixelPos){ .x = vec->x * r2, .y = vec->y * r2 };
}

s32 VecDirection8Sign(PixelPos *param_1)
{
    if (param_1->x < 0) {
        if (param_1->y < 0) {
            return DIRECTION_NORTHWEST;
        }
        else if (param_1->y > 0) {
            return DIRECTION_SOUTHWEST;
        }
        else {
            return DIRECTION_WEST;
        }
    }
    else if (param_1->x > 0) {
        if (param_1->y < 0) {
            return DIRECTION_NORTHEAST;
        }
        else if (param_1->y > 0) {
            return DIRECTION_SOUTHEAST;
        }
        else {
            return DIRECTION_EAST;
        }
    }
    else if (param_1->y < 0) {
        return DIRECTION_NORTH;
    }
    else if (param_1->y > 0) {
        return DIRECTION_SOUTH;
    }
    else {
        return -1;
    }
}

s32 VecDirection4SignYX(PixelPos *param_1)
{
    if (param_1->y < 0) {
        return DIRECTION_NORTH;
    }
    else if (param_1->y > 0) {
        return DIRECTION_SOUTH;
    }
    else  if (param_1->x < 0) {
        return DIRECTION_WEST;
    }
    else if (param_1->x > 0) {
        return DIRECTION_EAST;
    }
    else {
        return -1;
    }
}

s8 VecDirection8Radial(PixelPos *pixelPos)
{
    PixelPos absPos = {abs(pixelPos->x), abs(pixelPos->y)};

    if (pixelPos->x < 0) {
        if (pixelPos->y < 0) {
            if (absPos.y > absPos.x * 2) {
                return DIRECTION_NORTH;
            }
            if (absPos.x <= absPos.y * 2) {
                return DIRECTION_NORTHWEST;
            }
            return DIRECTION_WEST;
        }
        if (absPos.y <= absPos.x * 2) {
            if (absPos.x > absPos.y * 2) {
                return DIRECTION_WEST;
            }
            return DIRECTION_SOUTHWEST;
        }
    }
    else if (pixelPos->x > 0) {
        if (pixelPos->y < 0) {
            if (absPos.y > absPos.x * 2) {
                return DIRECTION_NORTH;
            }
            if (absPos.x <= absPos.y * 2) {
                return DIRECTION_NORTHEAST;
            }
            return DIRECTION_EAST;
        }
        else {
            if (absPos.y > absPos.x * 2) {
                return DIRECTION_SOUTH;
            }
            if (absPos.x > absPos.y * 2) {
                return DIRECTION_EAST;
            }
            return DIRECTION_SOUTHEAST;
        }
    }
    else {
        if (pixelPos->y < 0) {
            return DIRECTION_NORTH;
        }
        if (pixelPos->y < 1) {
            return -1;
        }
    }
    return DIRECTION_SOUTH;
}

s8 VecDirection4Radial(PixelPos *pixelPos)
{
    PixelPos absPos = {abs(pixelPos->x), abs(pixelPos->y)};

    if (pixelPos->x < 0) {
        if (pixelPos->y < 0) {
            if (absPos.y > absPos.x) {
                return DIRECTION_NORTH;
            }
            return DIRECTION_WEST;
        }
        if (absPos.y <= absPos.x) {
            return DIRECTION_WEST;
        }
    }
    else if (pixelPos->x > 0) {
        if (pixelPos->y < 0) {
            if (absPos.y > absPos.x) {
                return DIRECTION_NORTH;
            }
            return DIRECTION_EAST;
        }
        else {
            if (absPos.y > absPos.x) {
                return DIRECTION_SOUTH;
            }
            return DIRECTION_EAST;
        }
    }
    else {
        if (pixelPos->y < 0) {
            return DIRECTION_NORTH;
        }
        if (pixelPos->y < 1) {
            return -1;
        }
    }
    return DIRECTION_SOUTH;
}

s8 SizedDeltaDirection4(const PixelPos *r0, const PixelPos *r1, const PixelPos *r2, const PixelPos *r3)
{
    PixelPos stack;
    s32 iVar1;
    s32 iVar2;
    s32 iVar3;

    stack.x = r2->x  - r0->x;
    stack.y = r2->y  - r0->y;

    if(stack.x >= 0)
    {
        iVar3 = (stack.x + 1);
        iVar3 -= ((r1->x + r3->x) / 2);
        stack.x = iVar3;
        if(stack.x < 0) stack.x = 0;
    }
    else
    {
        iVar1 = (stack.x - 1);
        iVar1 += ((r1->x + r3->x) / 2);
        stack.x = iVar1;
        if(stack.x > 0) stack.x = 0;
    }

    if(stack.y >= 0)
    {
        iVar2 = (stack.y + 1);
        iVar2 -= ((r1->y + r3->y) / 2);
        stack.y = iVar2;
        if(stack.y < 0) stack.y = 0;
    }
    else
    {
        iVar1 = (stack.y - 1);
        iVar1 += ((r1->y + r3->y) / 2);
        stack.y = iVar1;
        if(stack.y > 0) stack.y = 0;
    }


    return VecDirection4Radial(&stack);
}

s8 SizedDeltaDirection8(const PixelPos *r0, const PixelPos *r1, const PixelPos *r2, const PixelPos *r3)
{
    PixelPos stack;
    s32 iVar1;
    s32 iVar2;
    s32 iVar3;

    stack.x = r2->x  - r0->x;
    stack.y = r2->y  - r0->y;

    if(stack.x >= 0)
    {
        iVar3 = (stack.x + 1);
        iVar3 -= ((r1->x + r3->x) / 2);
        stack.x = iVar3;
        if(stack.x < 0) stack.x = 0;
    }
    else
    {
        iVar1 = (stack.x - 1);
        iVar1 += ((r1->x + r3->x) / 2);
        stack.x = iVar1;
        if(stack.x > 0) stack.x = 0;
    }

    if(stack.y >= 0)
    {
        iVar2 = (stack.y + 1);
        iVar2 -= ((r1->y + r3->y) / 2);
        stack.y = iVar2;
        if(stack.y < 0) stack.y = 0;
    }
    else
    {
        iVar1 = (stack.y - 1);
        iVar1 += ((r1->y + r3->y) / 2);
        stack.y = iVar1;
        if(stack.y > 0) stack.y = 0;
    }


    return VecDirection8Radial(&stack);
}
